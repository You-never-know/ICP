import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick3D 1.15
import QtQuick3D.Materials 1.15
import QtQuick3D.Effects 1.15
import QtQuick3D.Helpers 1.15

Window {
    width: 1200
    height: 800
    visible: true
    title: qsTr("Microscopy")

    // Lense
    Node {

    }


    // Specimen





    View3D {
        anchors.fill: parent;        
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
            id: source

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
                z: -50
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
                z: -50
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

    // move the camera freely
    WasdController {
        controlledObject: main_camera
    }

}
