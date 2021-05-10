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
    property var samplePosition: -1
    property var sampleRotationY: 0
    property var selectedLense: null


    function clearSelectedLenseGUI (){
        addLensePosition.text = ""
        addLenseVergency.text = ""
        addLenseXDeflection.text = ""
        addLenseZDeflection.text = ""
    }

    Timer {
          id: timer
    }

    function delay(delayTime, cb) {
        timer.interval = delayTime;
        timer.repeat = false;
        timer.triggered.connect(cb);
        timer.triggered.connect(function release () {
            timer.triggered.disconnect(cb);
            timer.triggered.disconnect(release);
        });
        timer.start();
    }


    function createBeam(pos: qint16,xscale: qint16 ) : string {

        delay(70, function(){

        var component = Qt.createComponent("electronbeam.qml")
        var beam = component.createObject(microscopy, {pos:pos,xscale:xscale})
        if(pos >= -146)
          controller.startAnimation()

        controller.catchBeam(beam)
        })
    
        
    }


    function createLense(position, vergency, deflectionX, deflectionZ, GUI): string {
        var lenseType
        var component = Qt.createComponent("lense.qml")
        if (condenserLense == null) {
            lenseType = 0
            if (GUI === true) {
                position = controller.modifyLense(lenseType, position, vergency, deflectionX, deflectionZ, true)
                if (position === -1) {
                    logOutput.text = "Incorrect position given"
                    return -1
                }
            }
            condenserLense = component.createObject(microscopy, {position:position, lenseType: lenseType})
        } else if(objectiveLense == null) {
            lenseType = 1
            if (GUI === true) {
                position = controller.modifyLense(lenseType, position, vergency, deflectionX, deflectionZ, true)
                if (position === -1) {
                    logOutput.text = "Incorrect position given"
                    return -1
                }
            }
            objectiveLense = component.createObject(microscopy, {position:position, lenseType: lenseType})
         } else if (intermediateLense == null) {
             lenseType = 2
             if (GUI === true) {
                position = controller.modifyLense(lenseType, position, vergency, deflectionX, deflectionZ, true)
                if (position === -1) {
                    logOutput.text = "Incorrect position given"
                    return -1
                }
             }
             intermediateLense = component.createObject(microscopy, {position:position, lenseType: lenseType})
          } else if (projectorLense == null) {
              lenseType = 3
              if (GUI === true) {
                position = controller.modifyLense(lenseType, position, vergency, deflectionX, deflectionZ, true)
                if (position === -1) {
                    logOutput.text = "Incorrect position given"
                    return -1
                }
              }
              projectorLense = component.createObject(microscopy, {position:position, lenseType: lenseType})
          } else {
              logOutput.text = "All 4 lenses already placed"
              return -1
          }
          return lenseType
    }


    // free space in microscopy ranges between -145 and 150
    function createLenseFromGUI() {
        var position = addLensePosition.getText(0, addLensePosition.length)
        var vergency = addLenseVergency.getText(0, addLenseVergency.length)
        var deflectionX = addLenseXDeflection.getText(0, addLenseXDeflection.length)
        var deflectionZ = addLenseZDeflection.getText(0, addLenseZDeflection.length)
        logOutput.text = "..."
        clearSelectedLenseGUI()
        createLense(position,vergency,deflectionX,deflectionZ, true)
    }


    function showSelectedLense(type) {
        if (selectedLense == null) {
            return
        }
        addLensePosition.text = controller.getLensePosition(type)
        addLenseVergency.text = controller.getLenseVergency(type)
        addLenseXDeflection.text = controller.getLenseXAxisDeflection(type)
        addLenseZDeflection.text = controller.getLenseZAxisDeflection(type)
    }


    function deleteSelectedLense() {
        if (selectedLense == null) {
            return
        }
        var type = selectedLense.identifier
        controller.deleteLense(type)
        clearSelectedLenseGUI()
        switch(type) {
        case 0:
            condenserLense.destroy()
            condenserLense = null
            break
        case 1:
            objectiveLense.destroy()
            objectiveLense = null
            break
        case 2:
            intermediateLense.destroy()
            intermediateLense = null
            break
        case 3:
            projectorLense.destroy()
            projectorLense = null
            break
        default:
            logOutput.text = "Error while deleting lense"
            break
        }
    }



    function changeSelectedLense() {
        if (selectedLense == null) {
            return
        }
        var component = Qt.createComponent("lense.qml")
        var position = addLensePosition.getText(0, addLensePosition.length)
        var vergency = addLenseVergency.getText(0, addLensePosition.length)
        var deflectionX = addLenseXDeflection.getText(0, addLensePosition.length)
        var deflectionZ = addLenseZDeflection.getText(0, addLensePosition.length)
        var lenseType = selectedLense.identifier
        position = controller.modifyLense(lenseType, position, vergency, deflectionX, deflectionZ, false)
        if (position === -1) {
            logOutput.text = "Incorrect data given"
            return
        }
        selectedLense.y = position
        selectedLense.isPicked = false
        selectedLense = null
        clearSelectedLenseGUI()
    }


    function changeSample() {
        var newSamplePosition = sampleChangePosition.getText(0, sampleChangePosition.length)
        var newSapleRotation = sampleChangeRotation.getText(0, sampleChangeRotation.length)
        newSamplePosition = controller.changeSamplePosition(newSamplePosition)
        if (newSamplePosition !== -1) {
            samplePosition = newSamplePosition
        } else {
            logOutput.text = "Incorrect sample position given"
        }
        newSapleRotation = controller.changeSampleRotation(newSapleRotation)
        sampleRotationY = newSapleRotation
    }


    function saveConfiguration() {
        var path = filePath.getText(0, filePath.length)
        if (controller.saveConfiguration(path) === false) {
            logOutput.text = "Could not save this configuration to the given file"
        } else {
            logOutput.text = "Configuration successfuly saved"
        }
    }

    function loadConfiguration() {
        var path = filePath.getText(0, filePath.length)
        if ( controller.loadConfiguration(path) === false) {
            logOutput.text = "Could not load configuration from the given file"
        } else {
            logOutput.text = "Configuration successfuly loaded"
        }
    }


    function showLoadedSample(position: qint32, rotation: qint32) {
        samplePosition = position
        sampleRotationY = rotation
    }


    function clearMicroscopyToDefault() {
        clearSelectedLenseGUI()
        sampleChangePosition.text = ""
        sampleChangeRotation.text = ""
        sampleRotationY = 0
        samplePosition = -1
        if (condenserLense !== null) {
            condenserLense.destroy()
            condenserLense = null
        }
        if (objectiveLense !== null) {
            objectiveLense.destroy()
            objectiveLense = null
        }
        if (intermediateLense !== null) {
            intermediateLense.destroy()
            intermediateLense = null
        }
        if (projectorLense !== null) {
            projectorLense.destroy()
            projectorLense = null
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
                id: sample
                y: samplePosition
                x: 0
                z: 0

                Node {
                    Model {
                        source: "#Cylinder"
                        scale.y: 0.01
                        scale.x: 0.5
                        scale.z: 0.5
                        opacity: 0.5
                        y:samplePosition
                        eulerRotation.x: 0
                        eulerRotation.y: 30 + sampleRotationY
                        eulerRotation.z: 0
                        materials: PrincipledMaterial {
                            baseColor: "lightcoral"
                            metalness: 0.0
                            roughness: 1.5
                        }

                    }
                }
                Node {
                    Model {
                        source: "#Cube"
                        scale.y: 0.01
                        scale.x: 0.55
                        scale.z: 0.55
                        opacity: 0.5
                        y: samplePosition - 0.01
                        eulerRotation.x: 0
                        eulerRotation.y: 30 + sampleRotationY
                        eulerRotation.z: 0
                        materials: PrincipledMaterial {
                            baseColor: "black"
                            metalness: 0.0
                            roughness: 1.5
                        }

                    }

                }

            }



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


    WasdController {
        x: 0
        y: 0
        width: 921
        height: 800
        xInvert: true
        yInvert: true
        controlledObject: microscopy
    }


    Column {
        id: column3
        x: 921
        y: 0
        width: 329
        height: 108
        anchors.right: parent.right
        Rectangle {
            id: rectangle
            width: 328
            height: 60
            color: "#bfc1e1"
            border.width: 2
            transformOrigin: Item.Center
            anchors.right: parent.right

            Text {
                id: text1
                text: qsTr("Microscopy Controls")
                anchors.fill: parent
                font.pixelSize: 24
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                anchors.bottomMargin: 8
                font.bold: true
                fontSizeMode: Text.VerticalFit
                textFormat: Text.AutoText
                minimumPointSize: 19
                minimumPixelSize: 22
            }
        }

        Rectangle {
            id: rectangle15
            width: 331
            height: 45
            color: "#00000000"
            border.color: "#64bd9d"
            border.width: 0
            Button {
                id: startMicroscopy
                x: 8
                y: 5
                width: 100
                text: qsTr("Start")
                anchors.right: parent.right
                anchors.rightMargin: 223
                onClicked: controller.prepAnimation()
            }

            Button {
                id: resetMicroscopy
                x: 223
                y: 5
                text: qsTr("Restart")
                anchors.right: parent.right
                anchors.rightMargin: 8
                onClicked: controller.restartAnimation()
            }

            Button {
                id: stopMicroscopy
                x: 116
                y: 5
                width: 100
                text: qsTr("Clear")
                anchors.right: parent.right
                anchors.rightMargin: 116
                onClicked: controller.clearAnimation()
            }
        }
    }

    Column {
        id: column
        x: 921
        y: 112
        width: 329
        height: 308
        anchors.right: parent.right


        Rectangle {
            id: rectangle11
            width: 331
            height: 45
            color: "#ffffff"
            border.color: "#64bd9d"
            border.width: 2
            anchors.right: parent.right
            Rectangle {
                id: rectangle12
                x: 3
                y: 4
                width: 328
                height: 38
                color: "#91d4a1"
                border.color: "#968f8f"
            }

            Text {
                id: text7
                x: 7
                y: 6
                width: 324
                height: 33
                text: qsTr("Log")
                font.pixelSize: 18
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
        }

        Rectangle {
            id: rectangle9
            width: 331
            height: 45
            color: "#b4ece0"
            border.color: "#64bd9d"
            border.width: 2
            anchors.right: parent.right

            Text {
                id: logOutput
                x: 13
                y: 0
                width: 302
                height: 45
                text: qsTr("...")
                font.pixelSize: 15
                horizontalAlignment: Text.AlignLeft
                verticalAlignment: Text.AlignVCenter
            }
        }

        Rectangle {
            id: rectangle13
            width: 331
            height: 45
            color: "#ffffff"
            border.color: "#64bd9d"
            border.width: 2
            anchors.right: parent.right
            Rectangle {
                id: rectangle14
                x: 3
                y: 4
                width: 328
                height: 38
                color: "#91d4a1"
                border.color: "#968f8f"
            }

            Text {
                id: text8
                x: 7
                y: 6
                width: 324
                height: 33
                text: qsTr("Lense")
                font.pixelSize: 18
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
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
                placeholderText: qsTr("Range: -146 to 149")
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
                text: ""
                horizontalAlignment: Text.AlignHCenter
                hoverEnabled: false
                placeholderText: qsTr("Default: 0.0")
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
                text: ""
                horizontalAlignment: Text.AlignHCenter
                hoverEnabled: false
                placeholderText: qsTr("Default: 0.0")
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
                text: ""
                horizontalAlignment: Text.AlignHCenter
                hoverEnabled: false
                placeholderText: qsTr("Default: 0.0")
            }
        }

        Rectangle {
            id: rectangle10
            x: -2
            width: 331
            height: 45
            color: "#00000000"
            border.color: "#64bd9d"
            border.width: 0

            Button {
                id: addLenseButton
                x: 8
                y: 5
                width: 100
                text: qsTr("Add")
                anchors.right: parent.right
                anchors.rightMargin: 223
                onClicked: createLenseFromGUI()
            }

            Button {
                id: changeLenseButton
                x: 223
                y: 5
                text: qsTr("Delete")
                anchors.right: parent.right
                anchors.rightMargin: 8
                onClicked: deleteSelectedLense()
            }

            Button {
                id: changeLenseButton1
                x: 116
                y: 5
                width: 100
                text: qsTr("Change")
                anchors.right: parent.right
                anchors.rightMargin: 116
                onClicked: changeSelectedLense()
            }
        }


    }


    MouseArea {
        anchors.fill: view
        onClicked: {
            var pickedCoordinates = view.pick(mouse.x, mouse.y)
            if (pickedCoordinates.objectHit) {
                var pickedObject = pickedCoordinates.objectHit
                // Toggle the isPicked property for the model
                pickedObject.isPicked = !pickedObject.isPicked
                // Get picked model name
                selectedLense = pickedObject
                showSelectedLense(pickedObject.identifier)
            }
        }
        onWheel: {
            main_camera.z = main_camera.z - (wheel.angleDelta.y*0.2)
        }
    }

    Column {
        id: column1
        x: 921
        y: 477
        width: 329
        height: 181
        anchors.right: parent.right
        anchors.rightMargin: 0

        Rectangle {
            id: rectangle17
            width: 331
            height: 45
            color: "#ffffff"
            border.color: "#64bd9d"
            border.width: 2
            anchors.right: parent.right
            Rectangle {
                id: rectangle16
                x: 3
                y: 4
                width: 328
                height: 38
                color: "#91d4a1"
                border.color: "#968f8f"
            }

            Text {
                id: text9
                x: 7
                y: 6
                width: 324
                height: 33
                text: qsTr("Sample")
                font.pixelSize: 18
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
        }

        Rectangle {
            id: rectangle22
            width: 331
            height: 45
            color: "#ffffff"
            border.color: "#64bd9d"
            border.width: 2
            anchors.right: parent.right
            Rectangle {
                id: rectangle21
                x: 3
                y: 4
                width: 158
                height: 38
                color: "#ccddd0"
                border.color: "#968f8f"
            }

            Text {
                id: text11
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
                id: sampleChangePosition
                x: 164
                y: 2
                width: 167
                height: 40
                horizontalAlignment: Text.AlignHCenter
                hoverEnabled: false
                placeholderText: qsTr("Range: -146 to 149")
            }
        }

        Rectangle {
            id: rectangle24
            width: 331
            height: 45
            color: "#ffffff"
            border.color: "#64bd9d"
            border.width: 2
            anchors.right: parent.right
            Rectangle {
                id: rectangle23
                x: 3
                y: 4
                width: 158
                height: 38
                color: "#ccddd0"
                border.color: "#968f8f"
            }

            Text {
                id: text12
                x: 7
                y: 6
                width: 150
                height: 33
                text: qsTr("Rotation")
                font.pixelSize: 18
                horizontalAlignment: Text.AlignLeft
                verticalAlignment: Text.AlignVCenter
            }

            TextField {
                id: sampleChangeRotation
                x: 164
                y: 3
                width: 167
                height: 40
                horizontalAlignment: Text.AlignHCenter
                hoverEnabled: false
                placeholderText: qsTr("Default: 0")
            }
        }

        Rectangle {
            id: rectangle29
            x: -2
            width: 331
            height: 45
            color: "#00000000"
            border.color: "#64bd9d"
            border.width: 0

            Button {
                id: changeSampleButton
                x: 116
                y: 5
                width: 100
                text: qsTr("Change")
                anchors.right: parent.right
                anchors.rightMargin: 116
                onClicked: changeSample()
            }
        }
    }

    Column {
        id: column2
        x: 921
        y: 663
        width: 329
        height: 134
        anchors.right: parent.right
        anchors.rightMargin: 0
        Rectangle {
            id: rectangle19
            width: 331
            height: 45
            color: "#ffffff"
            border.color: "#64bd9d"
            border.width: 2
            anchors.right: parent.right
            Rectangle {
                id: rectangle18
                x: 3
                y: 4
                width: 328
                height: 38
                color: "#91d4a1"
                border.color: "#968f8f"
            }

            Text {
                id: text10
                x: 7
                y: 6
                width: 324
                height: 33
                text: qsTr("Configuration")
                font.pixelSize: 18
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
        }

        Rectangle {
            id: rectangle25
            width: 331
            height: 43
            color: "#ffffff"
            border.color: "#64bd9d"
            border.width: 2
            anchors.right: parent.right
            Rectangle {
                id: rectangle26
                x: 3
                y: 4
                width: 107
                height: 37
                color: "#ccddd0"
                border.color: "#968f8f"
            }

            Text {
                id: text13
                x: 7
                y: 6
                width: 103
                height: 33
                text: qsTr("File name")
                font.pixelSize: 18
                horizontalAlignment: Text.AlignLeft
                verticalAlignment: Text.AlignVCenter
            }

            TextField {
                id: filePath
                x: 113
                y: 3
                width: 216
                height: 38
                horizontalAlignment: Text.AlignHCenter
                hoverEnabled: false
                placeholderText: qsTr("../data/name.in")
            }
        }

        Rectangle {
            id: rectangle30
            x: -2
            width: 331
            height: 45
            color: "#00000000"
            border.color: "#64bd9d"
            border.width: 0
            Button {
                id: saveConfigurationButton
                x: 57
                y: 4
                width: 100
                text: qsTr("Save")
                anchors.right: parent.right
                anchors.rightMargin: 174
                onClicked: saveConfiguration()
            }

            Button {
                id: loadConfigurationButton
                x: 181
                y: 4
                width: 100
                text: qsTr("Load")
                anchors.right: parent.right
                anchors.rightMargin: 50
                onClicked: loadConfiguration()
            }
        }
    }



}
