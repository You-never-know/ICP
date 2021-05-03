import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick3D 1.15
import QtQuick3D.Helpers 1.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.11

Window {

    width: 1250
    height: 800
    visible: true
    color: "#6f6a6a"
    title: qsTr("Microscopy")

    function create_lense(y, id) {

    }

    View3D {
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
    }

    // move the camera freely


    WasdController {
        x: 0
        y: 0
        width: 921
        height: 800
        controlledObject: microscopy
    }


    Button {
        id: button
        x: 1036
        y: 460
        text: qsTr("Add Lense")
    }

    Rectangle {
        id: rectangle
        x: 921
        y: 0
        width: 329
        height: 63
        color: "#bfc1e1"

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
        x: 920
        y: 63
        width: 331
        height: 45
        color: "#ffffff"
        border.color: "#64bd9d"
        border.width: 3

        TextInput {
            id: textInput
            x: 172
            y: 0
            width: 151
            height: 45
            text: qsTr("100")
            font.pixelSize: 12
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }
    }

    Text {
        id: text2
        x: 927
        y: 69
        width: 150
        height: 33
        text: qsTr("Position")
        font.pixelSize: 18
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
    }

    Rectangle {
        id: rectangle2
        x: 1066
        y: 183
        width: 200
        height: 200
        color: "#ffffff"
    }












}





/*##^##
Designer {
    D{i:0;formeditorZoom:0.9}D{i:31}
}
##^##*/
