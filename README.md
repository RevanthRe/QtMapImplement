# Map-based project filtering
## Overview
This is a Map Application written in C++ with the Qt framework and QML. The application loads a JSON file containing project data and displays it in a ListView alongside a map. The user can interact with the map, click on items in the ListView, and perform searches. The map highlights selected locations and displays a circle around them.

## Components
JsonDataReader (JsonDataReader.h, JsonDataReader.cpp):

A class responsible for reading and parsing a JSON file containing project data.
Provides a method readJsonFile to read the JSON file and return a list of QVariantMap representing project information.
ProjectModel (projectmodel.h, projectmodel.cpp):

Subclass of QAbstractListModel to manage the data for the ListView in QML.
Handles filtering and highlighting of projects based on user input.
Provides signals for updating the map, removing map circles, and highlighting locations.
Exposes data to QML and manages the interaction between QML and C++.
#main.qml:

The main QML file that defines the user interface.
Contains a map, ListView, and search functionality.
Interacts with C++ backend to handle map events, search, and project highlighting.
Map Interaction
MapView (main.qml):

Displays an interactive map using the QtLocation and QtPositioning modules.
Allows users to click on the map to trigger a C++ function (handleMapClick).
Supports zooming using the mouse wheel.
ListView (main.qml):

Displays project data in a ListView with custom styling.
Allows users to click on items to highlight the corresponding location on the map.
Search (main.qml):

Provides a search field for filtering projects based on project name or location.
Triggered on editing finished or button click.
Highlighting (main.qml):

Highlights selected projects on both the ListView and the map.
Clears highlights when requested.
Map Circle (main.qml):

Adds a circle to the map when a project is selected, with specified radius and styling.
Updates map center and zoom level when a project is selected.
Running the Application
# Dependencies:

Qt 5.15 or later.
## Build:

Open the project file in Qt Creator or use the provided build system.
Ensure the necessary Qt modules are linked.
## Run:

Run the application, and the map interface should appear.

# Video:
https://github.com/RevanthRe/QtMapImplement/assets/149352194/723d7618-73eb-4330-ad92-d48410b0e71d

