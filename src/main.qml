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

    View3D {
        anchors.fill: parent;

        PerspectiveCamera {

        }

        DirectionalLight {

        }

        Model {

        }

    }

}
