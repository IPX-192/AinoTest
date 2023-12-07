#ifndef QCRESULTDISPLAY_H
#define QCRESULTDISPLAY_H

#include <QWidget>

namespace Ui {
class QCResultDisplay;
}

class QCResultDisplay : public QWidget
{
    Q_OBJECT

public:
    explicit QCResultDisplay(QWidget *parent = nullptr);
    ~QCResultDisplay();

signals:

    void sigExportBtnClicked();
    void sigReturnBtnClicked();

private:
    Ui::QCResultDisplay *ui;
};

#endif // QCRESULTDISPLAY_H
