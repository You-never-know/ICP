import QtQuick 2.0
import QtQuick3D 1.15
import QtQuick3D.Materials 1.15
import QtQuick3D.Effects 1.15
import QtQuick3D.Helpers 1.15

Node {
        property var pos: 0
        property var xscale: 0

        visible : true
        id: beamId

            Model {
                x: 0
                y: beamId.pos
                z: 0
                opacity : 0.2
                id: cylinder
                source: "#Cylinder"
                scale.y: 0.01
                scale.z: beamId.xscale
                scale.x: beamId.xscale
                eulerRotation.y: 30
                materials: PrincipledMaterial {
                    baseColor: "red"
                    metalness: 0.0
                    roughness: 0.0
                }
            }
    }
