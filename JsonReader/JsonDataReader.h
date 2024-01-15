// JsonDataReader.h
#pragma once
#include <QObject>
#include <QList>
#include <QVariantMap>

class JsonDataReader : public QObject {
    Q_OBJECT

public:
    JsonDataReader(QObject* parent = nullptr);

    QList<QVariantMap> readJsonFile(const QString& filePath);

private:
    bool parseJsonData(const QByteArray& jsonData, QList<QVariantMap>& projectsData);
};


