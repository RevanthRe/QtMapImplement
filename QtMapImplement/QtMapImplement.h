#ifndef QtMapImplement_H
#define QtMapImplement_H

#include <QQtMapImplement>
#include <QQuickItem>

QT_BEGIN_NAMESPACE
namespace Ui { class QtMapImplement; }
QT_END_NAMESPACE

class QtMapImplement : public QQtMapImplement
{
    Q_OBJECT

public:
    QtMapImplement(QWidget* parent = nullptr);
    ~QtMapImplement();

private slots:
    void onSearchClicked();

private:
    Ui::QtMapImplement* ui;
};

#endif // QtMapImplement_H
