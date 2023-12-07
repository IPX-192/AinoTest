#ifndef LISMESSAGES_H
#define LISMESSAGES_H

#include <QObject>
#include "Message.h"
#include <QString>
#include <QList>
#include <string>
#include <QDateTime>

struct SampleInfo
{
    bool isEmergency;
    QList<QString> listMdid;
    QString sampleBarcode;
    QString sampleId;
};

struct AssayInfo
{
    QString con;
    QString result;  //pos or neg
    QString sampleId;
    QString sampleType;
    QString mdId;
    QString mdCode;
    QString unit;
};

struct QCResult
{
    QString mdID;
    QString mdName;
    QString QCID;
    QString QCName;
    QString Lot;
    QString ExpireDate;
    QString AvgValue;
    QString Std;
    QDateTime StartTime;
    QDateTime FinishTime;
    QString Result;
    QString Unit;
    QString ModuleID;
};

class LisMessages : public QObject
{
    Q_OBJECT
public:
    explicit LisMessages(QObject *parent = nullptr);

    //sample request message
    Message SampleRequestMessage(QString sampleId, int MessageCtrlID);
    //sample response message
    SampleInfo SampleResponseMessage(QString strMessage);
    //result send message
    Message ResultSendMessage(AssayInfo asy,int result_type, int MessageCtrlID);
    Message QCResultSendMessage(QCResult qcResult, int MessageCtrlID);

    void SetMessageHeadInfo(std::string app, std::string faclity);
private:
    std::string m_Application = "AINO";
    std::string m_Facility = "AINO-6000";
};


#endif // LISMESSAGES_H
