#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "JsonDataReader.h"
#include "projectmodel.h"

int main(int argc, char* argv[]) {
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    // Instance of JsonDataReader
    JsonDataReader jsonDataReader;

    // JSON file path
    QString jsonFilePath = ":/data.json";  

    // Read JSON file using the JsonDataReader
    QList<QVariantMap> projectsData = jsonDataReader.readJsonFile(jsonFilePath);

    // Expose data to QML
    ProjectModel* projectModel = new ProjectModel();
    projectModel->setProjectsData(projectsData);

    QQmlApplicationEngine engine;

    // Set ownership to QML
    engine.rootContext()->setContextProperty("projectModel", projectModel);
    engine.setObjectOwnership(projectModel, QQmlEngine::JavaScriptOwnership);

    // Load QML content directly
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
