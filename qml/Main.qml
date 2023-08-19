

/*!
 * Main entry for the QML module used in the L-System Project
 * Copyright (C) 2023 Richard H. Nguyen
 *
 * This file is a part of the L-System Project
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of  MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http: *www.gnu.org/licenses/>.
 * Written by Richard H. Nguyen <richard@richardhnguyen.com>
 */
import QtQuick
import QtQuick.Controls

import LSystem 1.0

ApplicationWindow {
    id: rootWindow

    property int minWidth: 640
    property int minHeight: 480

    width: minWidth
    height: minHeight
    visible: true
    title: getTitle(LSystemDrawer.getStateString())

    LSCanvas {
        anchors.top: parent.top
        anchors.bottom: parent.bottom

        anchors.horizontalCenter: parent.horizontalCenter
    }

    Connections {
        target: LSystemDrawer

        function onStateChanged(newState) {
            title = getTitle(LSystemDrawer.getStateString())
        }
    }

    function getTitle(stateString) {
        return `L-System Rewriting Program (${stateString}) - Richard H. Nguyen`
    }
}
