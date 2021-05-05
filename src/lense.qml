import QtQuick3D 1.15
import QtQuick3D.Materials 1.15
import QtQuick3D.Effects 1.15
import QtQuick3D.Helpers 1.15
import QtQuick 2.15

Node {
        property var position: 0;
        property var id: lense1

        x: 0
        y: position
        opacity: 0.453
        z: 0
        id: id
            Model {
                id: cylinder
                source: "#Cylinder"
                scale.y: 0.02
                scale.z: 0.5
                scale.x: 0.5
                eulerRotation.y: 30
                materials: PrincipledMaterial {
                    baseColor: "cyan"
                    metalness: 0.0
                    roughness: 0.0
                }
            }
    }
