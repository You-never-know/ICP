import QtQuick 2.0
import QtQuick3D 1.15
import QtQuick3D.Materials 1.15
import QtQuick3D.Effects 1.15
import QtQuick3D.Helpers 1.15

Node {
        property var pos: 50
        visible : true
        id: beamId

            Model {
                x: 0
                y: 50
                z: 0
                opacity : 0.7
                id: cylinder
                source: "#Cylinder"
                scale.y: 0.001
                scale.z: 0.1
                scale.x: 0.1
                eulerRotation.y: 30
                materials: PrincipledMaterial {
                    baseColor: "red"
                    metalness: 0.0
                    roughness: 0.0
                }
            }
    }
