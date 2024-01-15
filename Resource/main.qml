import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtLocation 5.15
import QtPositioning
import QtQuick.Window

ApplicationWindow {
    visible: true
    width: 800
    height: 600
    title: "Map Application"

    property double oldLat: 0
    property double oldLng: 0
    property Component comMarker: mapMarker

    Plugin {
        id: mapPlugin
        name: "osm"
    }

    Map {
        id: mapView
        anchors.fill: parent
        plugin: mapPlugin
        center: QtPositioning.coordinate(oldLat, oldLng);
        zoomLevel: 6
        minimumZoomLevel: 2
        maximumZoomLevel: 18
        property MapCircle circle


        MouseArea {
            anchors.fill: parent
            acceptedButtons: Qt.AllButtons

            onClicked: (mouse) => {
                var clickPos = mapView.toCoordinate(Qt.point(mouse.x, mouse.y), true);
                console.log("Clicked at:", clickPos.latitude, clickPos.longitude);

                // Call the C++ function to handle the map click event
                mainwindow.handleMapClick(clickPos.latitude, clickPos.longitude);
            }

            onWheel: {
                var zoomFactor = 1.2; // You can adjust this factor based on your preference

                // Adjust zoom level based on wheel angle delta
                if (wheel.angleDelta.y > 0) {
                    mapView.zoomLevel = Math.min(mapView.zoomLevel * zoomFactor, mapView.maximumZoomLevel);
                } else {
                    mapView.zoomLevel = Math.max(mapView.zoomLevel / zoomFactor, mapView.minimumZoomLevel);
                }

                // Adjust the center based on the cursor position
                var mousePos = Qt.point(wheel.x, wheel.y);
                var mapPos = mapView.toCoordinate(mousePos);
                mapView.center = mapPos;

                wheel.accepted = true;
            }
        }
       
    }

    Rectangle {
        width: parent.width / 5
        height: parent.height
        anchors.right: parent.right

        ListView {
            id: listView
            anchors.fill: parent
            model: ListModel {
                ListElement {
                    name: ""
                    location: ""
                }
                ListElement {
                    name: " Brazil "
                    location: "Lat: 15.793889, Lng: 47.882778"
                }
                ListElement {
                    name: "Maldives"
                    location: "Lat: 3.2028, Lng: 73.2207"
                }
                ListElement {
                    name: "Hyderabad"
                    location: "Lat: 17.4065, Lng: 78.4772"
                }
                ListElement {
                    name: "Pune"
                    location: "Lat: 18.5204, Lng: 73.8567"
                }
                ListElement {
                    name: "Dubai"
                    location: "Lat: 25.2048, Lng: 55.2708"
                }
                ListElement {
                    name: "New York"
                    location: "Lat: 40.7128, Lng: -74.0060"
                }
                ListElement {
                    name: "Gousabad"
                    location: "Lat: 17.5924503, Lng: 77.4644607"
                }
            }
            delegate: contactDelegate
            highlight: Rectangle {
                color: "lightsteelblue"
                radius: 5
            }
            focus: true
        }
    }

    Component {
        id: contactDelegate
        Item {
            width: 250; height: 40
            Column {
                Text {
                    text: ' Project : ' + name
                    font.pointSize: 14
                }
                Text {
                    text: ' Location : ' + location
                }
            }
        }
    }

    Rectangle {
        width: parent.width / 5
        height: 40
        radius: 5
        anchors.top: parent.top
        anchors.right: parent.right

        TextField {
            id: searchField
            width: parent.width - 200
            anchors.verticalCenter: parent.verticalCenter
            // anchors.center: parent.center
            placeholderText: "      Enter <b> Project Name</b> or <b> Location</b>"
            placeholderTextColor: "black"
           // color: "black"
            onEditingFinished: {
                projectModel.search(text);
            }
        }

        Button {
            id: control
            height: 22
            text: qsTr("Enter                                    ")

            background: Rectangle {
                implicitWidth: 200
                implicitHeight: 20
                opacity: enabled ? 1 : 0.3
                border.color: control.down ? "#17a81a" : "#21be2b"
                border.width: 1
                radius: 2
                color: "lightblue"  // I update background color by this
            }
            anchors.verticalCenter: parent.verticalCenter
            anchors.top: myButton
            anchors.right: parent.right

            onClicked: {
                projectModel.search(text);
            }
        }

        Button {
            id: myButton
            width: 100
            height: 22
            text: ("Clear Screen    ")

            background: Rectangle {
                implicitWidth: 40
                implicitHeight: 20
                opacity: enabled ? 1 : 0.3
                border.color: control.down ? "#17a81a" : "#21be2b"
                border.width: 1
                radius: 2
                color: "lightblue"  // I update background color by this
            }
            anchors.verticalCenter: parent.verticalCenter
            anchors.top: control
            //anchors.right: parent.right
            anchors.right: parent.right
            onClicked: {
                projectModel.clearHighlights();
            }
        }

        Item {
            id: highlightItem
            property MapCircle circle: null // Declare the MapCircle property

            Connections {
                target: projectModel

                onRemoveMapCircle:{
                    if (highlightItem.circle !== null) {
                        mapView.removeMapItem(highlightItem.circle);
                        highlightItem.circle.destroy(); // Ensure proper cleanup
                        console.log("Revanth - Previous Circle Removed");
                    }
                    // Clear the array after removing all circles
                    mapView.circles = [];
                }

                onUpdateMap: {
                    mapView.center = QtPositioning.coordinate(latitude, longitude);
                    mapView.zoomLevel = 12;
                    console.log("Revanth - Map Center Updated");

                    // Create a new circle
                    highlightItem.circle = Qt.createQmlObject('import QtLocation 5.15; MapCircle {}', mapView);
                    highlightItem.circle.center = QtPositioning.coordinate(latitude, longitude);
                    highlightItem.circle.radius = 500.0;
                    highlightItem.circle.color = 'black';
                    highlightItem.circle.border.width = 20;
                    highlightItem.circle.border.color = 'blue';

                    // Debug statements
                    console.log("Revanth - New Circle Created:", highlightItem.circle);
                    console.log("Revanth - Circle Center:", highlightItem.circle.center);

                    mapView.addMapItem(highlightItem.circle);
                    console.log("Revanth - New Circle Added to Map");
                }
            }
        }
    }
}
