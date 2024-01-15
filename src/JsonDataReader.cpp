// JsonDataReader.cpp
#include "JsonDataReader.h"
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QDebug>

JsonDataReader::JsonDataReader(QObject* parent) : QObject(parent) {}

bool JsonDataReader::parseJsonData(const QByteArray& jsonData, QList<QVariantMap>& projectsData) {
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);

    if (jsonDoc.isNull() || !jsonDoc.isArray()) {
        qWarning() << "Failed to parse JSON data";
        return false;
    }

    QJsonArray jsonArray = jsonDoc.array();
    for (const QJsonValue& value : jsonArray) {
        if (value.isObject()) {
            projectsData.append(value.toObject().toVariantMap());
        }
    }

    return true;
}

QList<QVariantMap> JsonDataReader::readJsonFile(const QString& filePath) {
    QList<QVariantMap> projectsData;

    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Failed to open JSON file";
        return projectsData;
    }

    QByteArray jsonData = file.readAll();
    if (!parseJsonData(jsonData, projectsData)) {
        projectsData.clear();
    }

    return projectsData;
}
