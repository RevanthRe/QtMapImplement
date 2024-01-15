#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QUrl>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Load the QML file with the map
    ui->quickWidget->setSource(QUrl("maip.qml"));

    // Connect the search button signal to the search slot
    connect(ui->searchButton, &QPushButton::clicked, this, &MainWindow::onSearchClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onSearchClicked()
{
    // Retrieve the map item from the QQuickWidget
    QQuickItem* mapItem = ui->quickWidget->rootObject()->findChild<QQuickItem*>("map");

    if (mapItem) {
        // Perform map-related actions, e.g., set a marker or center the map on a location
        // You can use the mapItem and interact with the map as needed
    }
}
