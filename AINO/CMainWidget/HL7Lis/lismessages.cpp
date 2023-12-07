#include "lismessages.h"

LisMessages::LisMessages(QObject *parent) : QObject(parent)
{

}

Message LisMessages::SampleRequestMessage(QString sampleId, int MessageCtrlID)
{
    Message msg;
    msg.addSegmentMSH(m_Application, m_Facility, "", "", "", "QRY^Q02", std::to_string(MessageCtrlID), "P", "2.3.1");
    auto obr = Segment("OBR", msg.encoding);
    obr.addNewField("");
    obr.addEmptyField();//2
    obr.addEmptyField();//3
    obr.addNewField("1");//4
    obr.addEmptyField();//5
    obr.addEmptyField();//6
    obr.addEmptyField();//7
    obr.addNewField(sampleId.toStdString());//8
    msg.addNewSegment(obr);
    return msg;
}

SampleInfo LisMessages::SampleResponseMessage(QString strMessage)
{
    auto msg=Message(strMessage.toStdString());
    auto dsps=msg.segments("DSP");
    QList<QString> listMdid;
    for(int i=0;i<dsps.size();i++)
    {
        listMdid.push_back(QString::fromStdString(dsps[i].fields(2).getValue()));
    }

    SampleInfo info;
    info.isEmergency=dsps[3].fields(2).getValue()=="N"?false:true;
    info.listMdid=listMdid;
    info.sampleBarcode=QString::fromStdString(dsps[0].fields(2).getValue());
    info.sampleId=QString::fromStdString(dsps[1].fields(2).getValue());
    return info;
}

Message LisMessages::ResultSendMessage(AssayInfo assay,int result_type, int MessageCtrlID)
{
    Message message=Message();
    message.addSegmentMSH(m_Application, m_Facility, "", "", "", "ORU^R01", std::to_string(MessageCtrlID), "P", "2.3.1", rtSample);
    auto pid = Segment("PID",message.encoding);
    pid.addNewField("1");
    for (int i = 0; i < 29; i++)
    {
        pid.addEmptyField();
    }
    message.addNewSegment(pid);


    auto obr = Segment("OBR", message.encoding);
    obr.addNewField("1");
    obr.addEmptyField();
    obr.addNewField(assay.sampleId.toStdString());
    for (int i = 0; i < 47 - 3; i++)
    {
        obr.addEmptyField();
    }
    message.addNewSegment(obr);

    QString strResult;
    if (result_type)
        strResult = assay.con;
    else
    {
        strResult = assay.result;
    }
    auto obx = Segment("OBX", message.encoding);
    obx.addNewField("1");//1
    obx.addNewField(assay.sampleType.toStdString());//2
    obx.addNewField(assay.mdId.toStdString());//3
    obx.addNewField(assay.mdCode.toStdString());//4
    obx.addNewField(strResult.toStdString());//5
    obx.addNewField(assay.unit.toStdString());//6
    obx.addNewField("-");//7
    obx.addNewField("N");//8
    obx.addEmptyField();//9
    obx.addEmptyField();//10
    obx.addNewField("F");//11
    obx.addEmptyField();//12
    obx.addNewField(assay.con.toStdString());//13
    obx.addNewField("");//14

    message.addNewSegment(obx);
    return message;
}

Message LisMessages::QCResultSendMessage(QCResult qcResult, int MessageCtrlID)
{
    Message message;

    message.addSegmentMSH(m_Application, m_Facility, "", "", "", "ORU^R01", std::to_string(MessageCtrlID), "P", "2.3.1", rtQC);

    auto obr = Segment("OBR", message.encoding);
    obr.addNewField("1");
    obr.addNewField(qcResult.mdID.toStdString());
    obr.addNewField(qcResult.mdName.toStdString());
    obr.addNewField("^");
    obr.addNewField("0");

    QString startTimeStr = qcResult.StartTime.toString("yyyyMMddHHmmss");
    obr.addNewField(startTimeStr.toStdString());
    obr.addEmptyField();
    QString endTimestr = qcResult.FinishTime.toString("yyyyMMddHHmmss");
    obr.addNewField(endTimestr.toStdString());
    obr.addEmptyField();
    obr.addEmptyField();
    obr.addNewField("1");
    obr.addNewField(qcResult.QCID.toStdString());
    obr.addNewField(qcResult.QCName.toStdString());
    obr.addNewField(qcResult.Lot.toStdString());
    obr.addNewField(qcResult.ExpireDate.toStdString());
    obr.addNewField("0");
    obr.addNewField("M");
    obr.addNewField(qcResult.AvgValue.toStdString());
    obr.addNewField(qcResult.Std.toStdString());
    obr.addNewField(qcResult.Result.toStdString());
    obr.addNewField(qcResult.Unit.toStdString());

    for (int var = 0; var < 8; ++var) {
        obr.addEmptyField();
    }

    obr.addNewField(qcResult.ModuleID.toStdString());
    for (int var = 0; var < 17; ++var) {
        obr.addEmptyField();
    }

    message.addNewSegment(obr);
    return message;
}

void LisMessages::SetMessageHeadInfo(std::string app, std::string faclity)
{
    m_Application = app;
    m_Facility = faclity;
}


