import QtQuick 2.0
import QtQuick3D 1.15
import QtQuick3D.Materials 1.15
import QtQuick3D.Effects 1.15
import QtQuick3D.Helpers 1.15

Node {
        property var positionY: 0
        property var positionZ: 0
        property var scaleX: 1
        property var scaleZ: 1
        property var color: "black"

        id: pixel
        Model {
                x: 190
                y: 50+ pixel.positionY
                z: -100 + pixel.positionZ
                source: "#Cube"
                scale.y: 0.01
                scale.z: pixel.scaleZ
                scale.x: pixel.scaleX
                eulerRotation.z: 90
                eulerRotation.y: 25
                materials: PrincipledMaterial {
                    baseColor: pixel.color
                    metalness: 0.0
                    roughness: 0.0
                }
            }
    }
