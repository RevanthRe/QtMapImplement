#include "mainwindow.h"
#include <QDebug>

MainWidget::MainWidget(QWidget* parent)
    : QWidget(parent)
{
    layout = new QVBoxLayout(this);

    // Create a QQuickWidget to display the QML content
    qmlWidget = new QQuickWidget(this);
    qmlWidgetMap = new QQuickWidget(qmlWidget);
    //qmlWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);
    qmlWidgetMap->setSource(QUrl::fromLocalFile("main.qml")); // Assuming main.qml is in the resource file

    // Create a QPushButton for searching
    searchButton = new QPushButton("filter", this);

    // Connect the button click signal to handleSearchButtonClicked slot
    connect(searchButton, &QPushButton::clicked, this, &MainWidget::handleSearchButtonClicked);

    connect(qmlWidgetMap, &QQuickWidget::statusChanged, this, &MainWidget::handleQmlStatusChanged);


    // Add QML widget and search button to the layout
    layout->addWidget(qmlWidgetMap);
    layout->addWidget(searchButton);
    
}

MainWidget::~MainWidget()
{
    // Destructor
}

void MainWidget::handleSearchButtonClicked()
{
    qDebug() << "Search button clicked!";
    // Add your search logic here
}

void MainWidget::handleQmlStatusChanged(QQuickWidget::Status status)
{
    qDebug() << "QML Status Changed:" << status;
}
