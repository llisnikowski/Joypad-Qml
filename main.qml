import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

import Joypad 1.0

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Joypad{
        x:50
        y:50
        width: 100
        height: 100
    }

    Joypad{
        x:160
        y:50
        width: 100
        height: 100
    }
}
