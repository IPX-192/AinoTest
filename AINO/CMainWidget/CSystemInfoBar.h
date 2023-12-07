#ifndef CSYSTEMINFOBAR_H
#define CSYSTEMINFOBAR_H

#include <QWidget>
#include <QDebug>
#include <QTimer>
#include <QDateTime>


namespace Ui {
class CSystemInfoBar;
}

class CSystemInfoBar : public QWidget
{
    Q_OBJECT

public:
    explicit CSystemInfoBar(QWidget *parent = 0);
    ~CSystemInfoBar();

public slots:
    void onSetUserLoginName( const QString &loginName );


private:
    void init();



private:
    Ui::CSystemInfoBar *ui;

    QTimer m_timer;
};

#endif // CSYSTEMINFOBAR_H
