import QtQuick 2.0
import QtQuick3D 1.15
import QtQuick3D.Materials 1.15
import QtQuick3D.Effects 1.15
import QtQuick3D.Helpers 1.15

Node {
        property var position: 0
        property var lenseType: 0


        id: lenseId
         Model {
                x: 0
                y: lenseId.position
                opacity: 0.453
                z: 0

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
                pickable: true
                property bool isPicked: false
                onYChanged: update()
                property int identifier: lenseType
            }
    }
