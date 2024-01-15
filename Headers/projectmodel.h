#pragma once

#include <QObject>
#include <QAbstractListModel>
#include <QVariantMap>

class ProjectModel : public QAbstractListModel {
    Q_OBJECT

public:
    explicit ProjectModel(QObject* parent = nullptr);

    enum {
        ProjectNameRole = Qt::UserRole + 1,
        ProjectStartDateRole,
        ProjectLocationRole,
    };

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    void setProjectsData(const QList<QVariantMap>& data);
    Q_INVOKABLE void search(const QString& searchText);
    Q_INVOKABLE void clearHighlights();

    Q_PROPERTY(QVariantMap highlightedLocation READ getHighlightedLocation NOTIFY highlightLocationChanged)

signals:
    void highlightLocationChanged(const QVariantMap& location);
    void updateMap(double latitude, double longitude);
    void removeMapCircle(double latitude, double longitude);


private:
    QVariantMap highlightedLocation;
    QVariantMap getLocation(int index) const;

    Q_INVOKABLE QVariantMap getHighlightedLocation() const {
        return highlightedLocation;
    }

private:
    void highlightProject(int index);

    QList<QVariantMap> projectsData;
    QList<int> highlightedProjects;
    int selectedProjectIndex;
};
