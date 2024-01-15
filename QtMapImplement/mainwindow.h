#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QQuickWidget>
#include <QPushButton>

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget* parent = nullptr);
    ~MainWidget();

private slots:
    void handleSearchButtonClicked();
    void handleQmlStatusChanged(QQuickWidget::Status statu);

private:
    QVBoxLayout* layout;
    QQuickWidget* qmlWidget;
    QQuickWidget* qmlWidgetMap;
    QPushButton* searchButton;
};

#endif // MAINWIDGET_H
