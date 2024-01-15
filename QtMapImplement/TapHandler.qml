// TapHandler.qml
import QtQuick 2.15

Item {
    id: tapHandler

    property variant lastCoordinate
    acceptedButtons: Qt.LeftButton | Qt.RightButton

    onSingleTapped: (eventPoint, button) => {
        lastCoordinate = view.map.toCoordinate(tapHandler.point.position)

        if (button === Qt.RightButton) {
            if (view.unfinishedItem !== undefined) {
                view.finishGeoItem()
            } else {
                mapPopupMenu.show(lastCoordinate)
            }
        } else if (button === Qt.LeftButton) {
            if (view.unfinishedItem !== undefined) {
                if (view.unfinishedItem.addGeometry(view.map.toCoordinate(tapHandler.point.position), false)) {
                    view.finishGeoItem()
                }
            }
        }
    }
}
