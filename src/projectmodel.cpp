#include "projectmodel.h"

ProjectModel::ProjectModel(QObject* parent)
    : QAbstractListModel(parent), selectedProjectIndex(-1) {
    highlightedProjects = QList<int>();

    
}

int ProjectModel::rowCount(const QModelIndex& parent) const {
    if (parent.isValid())
        return 0;

    return projectsData.size();
}

QVariant ProjectModel::data(const QModelIndex& index, int role) const {
    if (!index.isValid())
        return QVariant();

    const QVariantMap& project = projectsData[index.row()];

    switch (role) {
    case ProjectNameRole:
        return project.value("name");
    case ProjectStartDateRole:
        return project.value("startDate");
    case ProjectLocationRole:
        return getLocation(index.row());
    default:
        return QVariant();
    }
}

QVariantMap ProjectModel::getLocation(int index) const {
    const QVariantMap& project = projectsData[index];
    QVariantMap location;
    location.insert("latitude", project.value("latitude").toDouble());
    location.insert("longitude", project.value("longitude").toDouble());

    return location;
}

void ProjectModel::highlightProject(int index) {
    if (!highlightedProjects.contains(index)) {
        highlightedProjects.append(index);
        highlightedLocation = getLocation(index);

        // Debug print
        qDebug() << "Highlighted Location set to:" << highlightedLocation;

        // Emit the signal to update the map directly
        emit updateMap(highlightedLocation.value("latitude").toDouble(), highlightedLocation.value("longitude").toDouble());
    }
}


void ProjectModel::clearHighlights() {
    for (int i = 0; i < highlightedProjects.size(); i++) {
        if (!highlightedProjects.isEmpty()) {
            emit removeMapCircle(highlightedLocation.value("latitude").toDouble(), highlightedLocation.value("longitude").toDouble());

           // emit dataChanged(createIndex(0, 0), createIndex(rowCount() - 1, 0), { ProjectNameRole, ProjectStartDateRole, ProjectLocationRole });
            highlightedProjects.clear();
        }
    }
}

void ProjectModel::search(const QString& searchText) {
    //clearHighlights();

    for (int i = 0; i < projectsData.size(); ++i) {
        const QVariantMap& project = projectsData[i];

        QString projectName = project.value("name").toString();
        QString projectLocation = QString("%1, %2")
            .arg(project.value("latitude").toDouble())
            .arg(project.value("longitude").toDouble());

        if (projectName.contains(searchText, Qt::CaseInsensitive) || projectLocation.contains(searchText, Qt::CaseInsensitive)) {
            highlightProject(i);
        }
    }
}
void ProjectModel::setProjectsData(const QList<QVariantMap>& data) {
    beginResetModel();  // Notify views to reset
    projectsData = data;
    endResetModel();    // Notify views that the reset is complete
}

