import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick3D 1.15
import QtQuick3D.Helpers 1.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.11

Window {
    id: window
    width: 1250
    height: 800
    visible: true
    color: "#6f6a6a"
    title: qsTr("Microscopy")

    property var condenserLense: null
    property var objectiveLense: null
    property var intermediateLense: null
    property var projectorLense: null

    function createLense(y, id) {
        var component = Qt.createComponent("lense.qml")
        var position = addLensePosition.getText(0, addLensePosition.length)
        var vergency = addLenseVergency.getText(0, addLensePosition.length)
        var deflectionX = addLenseXDeflection.getText(0, addLensePosition.length)
        var deflectionZ = addLenseZDeflection.getText(0, addLensePosition.length)
        var lenseType = 0

        if (condenserLense == null) {
            lenseType = 0
            position = controller.addLense(lenseType, position, vergency, deflectionX, deflectionZ)
            if (position === -1 || position <= -145 || position >= 150) {
                return
            }
            condenserLense = component.createObject(microscopy, {position:position, id: "condenserLense"})
        } else if(objectiveLense == null) {
            lenseType = 1
            position = controller.addLense(lenseType, position, vergency, deflectionX, deflectionZ)
            if (position === -1 || position <= -145 || position >= 150) {
                return
            }
            objectiveLense = component.createObject(microscopy, {position:position, id: "objectiveLense"})
        } else if (intermediateLense == null) {
            lenseType = 2
            position = controller.addLense(lenseType, position, vergency, deflectionX, deflectionZ)
            if (position === -1 || position <= -145 || position >= 150) {
                return
            }
            intermediateLense = component.createObject(microscopy, {position:position, id: "intermediateLense"})
        } else if (projectorLense == null) {
            lenseType = 3
            position = controller.addLense(lenseType, position, vergency, deflectionX, deflectionZ)
            if (position === -1 || position <= -145 || position >= 150) {
                return
            }
            projectorLense = component.createObject(microscopy, {position:position, id: "projectorLense"})
        } else {
            return
        }
    }


    View3D {
        id: view
        anchors.fill: parent;
        anchors.rightMargin: 329
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        environment: SceneEnvironment {
            clearColor: "silver"
            backgroundMode: SceneEnvironment.Color
            antialiasingMode: SceneEnvironment.MSAA
            antialiasingQuality: SceneEnvironment.High
        }

        PerspectiveCamera {
            id: main_camera
            z: 500
            x: -10
            y: 10
        }


        DirectionalLight {
            visible: true
            eulerRotation.x: -45
        }

        Node {
            id: microscopy

            Node {
                id: base_platform


                // Platform
                Node {
                    id: platform
                    x: 0
                    z: 0
                    y: -150

                    Model {
                        source: "#Cube"
                        scale.z: 3
                        scale.x: 3
                        scale.y: 0.1
                        eulerRotation.y: 30
                        materials: PrincipledMaterial {
                            baseColor: "grey"
                            metalness: 0.0
                            roughness: 0.0
                        }
                    }
                }


                // Detector
                Node {
                    id: detector
                    x: 0
                    z: 0
                    y: -145

                    Model {
                        source: "#Cube"
                        scale.z: 0.5
                        scale.x: 0.5
                        scale.y: 0.05
                        eulerRotation.y: 30
                        materials: PrincipledMaterial {
                            baseColor: "white"
                            metalness: 0.0
                            roughness: 0.0
                        }
                    }
                }

            }


            // Source
            Node {
                id: source_screen

                // Source top
                Node {
                    x: 0
                    z: 0
                    y: 175

                    Model {
                        source: "#Cube"
                        scale.z: 0.5
                        scale.x: 0.5
                        scale.y: 0.1
                        eulerRotation.y: 30
                        materials: PrincipledMaterial {
                            baseColor: "grey"
                            metalness: 0.0
                            roughness: 0.0
                        }
                    }
                }


                // Source bottom
                Node {
                    x: 0
                    z: 0
                    y: 150

                    Model {
                        source: "#Cone"
                        scale.z: 0.5
                        scale.x: 0.5
                        scale.y: 0.3
                        eulerRotation.y: 30
                        materials: PrincipledMaterial {
                            baseColor: "grey"
                            metalness: 0.0
                            roughness: 0.0
                        }
                    }
                }

            }


            // Display
            Node {
                id: display

                DirectionalLight {
                    visible: true
                    eulerRotation.z: -1
                }



                Node {
                    x: 200
                    z: -100
                    y: 50

                    Model {
                        source: "#Cube"
                        scale.z: 1.6
                        scale.x: 1.6
                        scale.y: 0.1
                        eulerRotation.z: 90
                        eulerRotation.y: 25
                        materials: PrincipledMaterial {
                            baseColor: "grey"
                            metalness: 0.0
                            roughness: 0.0
                        }
                    }

                }


                Node {
                    x: 195
                    z: -100
                    y: 50

                    Model {
                        source: "#Cube"
                        scale.z: 1.5
                        scale.x: 1.5
                        scale.y: 0.1
                        eulerRotation.z: 90
                        eulerRotation.y: 25
                        materials: PrincipledMaterial {
                            baseColor: "white"
                            metalness: 0.0
                            roughness: 0.0
                        }
                    }
                }

            }
        }

        DirectionalLight {
            id: lightDirectional
            x: 0
            y: 0
            visible: true
            scale.x: 1
            eulerRotation.x: 90
            eulerRotation.z: 0
            eulerRotation.y: -44
            pivot.y: 0
        }
    }

    // move the camera freely


    WasdController {
        x: 0
        y: 0
        width: 921
        height: 800
        controlledObject: microscopy
    }


    Column {
        id: column
        x: 921
        y: 0
        width: 329
        height: 793
        anchors.right: parent.right


        Rectangle {
            id: rectangle
            width: 329
            height: 63
            color: "#bfc1e1"
            transformOrigin: Item.Center
            anchors.right: parent.right

            Text {
                id: text1
                text: qsTr("Microscopy Controls")
                anchors.fill: parent
                font.pixelSize: 24
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.bold: true
                fontSizeMode: Text.VerticalFit
                textFormat: Text.AutoText
                minimumPointSize: 19
                minimumPixelSize: 22
            }
        }

        Rectangle {
            id: rectangle1
            width: 331
            height: 45
            color: "#ffffff"
            border.color: "#64bd9d"
            border.width: 2
            anchors.right: parent.right

            Rectangle {
                id: rectangle2
                x: 3
                y: 4
                width: 158
                height: 38
                color: "#ccddd0"
                border.color: "#968f8f"
            }

            Text {
                id: text2
                x: 7
                y: 6
                width: 150
                height: 33
                text: qsTr("Position")
                font.pixelSize: 18
                horizontalAlignment: Text.AlignLeft
                verticalAlignment: Text.AlignVCenter
            }

            TextField {
                id: addLensePosition
                x: 164
                y: 2
                width: 167
                height: 40
                horizontalAlignment: Text.AlignHCenter
                hoverEnabled: false
                placeholderText: qsTr("100")
            }
        }

        Rectangle {
            id: rectangle3
            width: 331
            height: 45
            color: "#ffffff"
            border.color: "#64bd9d"
            border.width: 2
            anchors.right: parent.right
            Rectangle {
                id: rectangle4
                x: 3
                y: 4
                width: 158
                height: 38
                color: "#ccddd0"
                border.color: "#968f8f"
            }

            Text {
                id: text3
                x: 7
                y: 6
                width: 150
                height: 33
                text: qsTr("Vergency")
                font.pixelSize: 18
                horizontalAlignment: Text.AlignLeft
                verticalAlignment: Text.AlignVCenter
            }

            TextField {
                id: addLenseVergency
                x: 164
                y: 3
                width: 167
                height: 40
                horizontalAlignment: Text.AlignHCenter
                hoverEnabled: false
                placeholderText: qsTr("1.5")
            }
        }

        Rectangle {
            id: rectangle5
            width: 331
            height: 45
            color: "#ffffff"
            border.color: "#64bd9d"
            border.width: 2
            anchors.right: parent.right
            Rectangle {
                id: rectangle6
                x: 3
                y: 4
                width: 158
                height: 38
                color: "#ccddd0"
                border.color: "#968f8f"
            }

            Text {
                id: text4
                x: 7
                y: 6
                width: 150
                height: 33
                text: qsTr("Deflection (x)")
                font.pixelSize: 18
                horizontalAlignment: Text.AlignLeft
                verticalAlignment: Text.AlignVCenter
            }

            TextField {
                id: addLenseXDeflection
                x: 164
                y: 3
                width: 167
                height: 40
                text: "-0.5"
                horizontalAlignment: Text.AlignHCenter
                hoverEnabled: false
                placeholderText: qsTr("1.5")
            }
        }

        Rectangle {
            id: rectangle7
            x: -2
            width: 331
            height: 45
            color: "#ffffff"
            border.color: "#64bd9d"
            border.width: 2
            Rectangle {
                id: rectangle8
                x: 3
                y: 4
                width: 158
                height: 38
                color: "#ccddd0"
                border.color: "#968f8f"
            }

            Text {
                id: text5
                x: 7
                y: 6
                width: 150
                height: 33
                text: "Deflection (z)"
                font.pixelSize: 18
                horizontalAlignment: Text.AlignLeft
                verticalAlignment: Text.AlignVCenter
                textFormat: Text.AutoText
            }

            TextField {
                id: addLenseZDeflection
                x: 164
                y: 3
                width: 167
                height: 40
                text: "0.5"
                horizontalAlignment: Text.AlignHCenter
                hoverEnabled: false
                placeholderText: qsTr("1.5")
            }
        }

        Button {
            id: button
            text: qsTr("Add Lense")
            anchors.right: parent.right
            anchors.rightMargin: 120
            onClicked: createLense(0, "sa")

        }
    }















}






