#include <QSpinBox>
#include <QTableView>
#include <QTableWidget>
#include <QDebug>
#include <QPaintEvent>
#include <QPainter>
#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "QCheaders.h"

using namespace Common;
void SetTableItemData(QTableWidget* table, int row, int col, QString data, int size = 23)
{
    if (!table)
    {
        return;
    }
    QTableWidgetItem* item = table->item(row, col);
    if (!item)
    {
        item = new QTableWidgetItem;
        item->setFlags(Qt::ItemIsEnabled);
        table->setItem(row, col, item);
    }
    item->setText(data);
    item->setTextAlignment(Qt::AlignCenter);
    QFont ft = item->font();
    ft.setPixelSize(size);
    item->setFont(ft);
}


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initUI();
    ui->mainStackWidget->setCurrentIndex( Page::Main );
    ui->stacked_Cali->setCurrentIndex(Page_CaliApply::OverView);
    ui->stacked_CaliRes->setCurrentIndex(Page_CaliRes::ResInitPage);

    ui->popup_CaliQuery->hide();

    ui->popup_NewCaliPro->hide();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initUI()
{
    initNavitationBar();
    connectManager();
    initQCPageConnection();

}

void MainWindow::initNavitationBar()
{
    connect( ui->btnMain, &QPushButton::clicked, [ this ](){
        ui->mainStackWidget->setCurrentIndex( Page::Main );
    } );

    connect( ui->btnApply, &QPushButton::clicked, [ this ](){
        ui->mainStackWidget->setCurrentIndex( Page::Apply );
    } );

    connect( ui->btnReagents, &QPushButton::clicked, [ this ](){
        ui->mainStackWidget->setCurrentIndex( Page::Reagents );
    } );

    connect( ui->btnCalibration, &QPushButton::clicked, [ this ](){
        ui->mainStackWidget->setCurrentIndex( Page::Calibration );
    } );

    connect( ui->btnQC, &QPushButton::clicked, [ this ](){
        ui->mainStackWidget->setCurrentIndex( Page::QC );
    } );

    connect( ui->btnData, &QPushButton::clicked, [ this ](){
        ui->mainStackWidget->setCurrentIndex( Page::Data );
    } );

    connect( ui->btnUse, &QPushButton::clicked, [ this ](){
        ui->mainStackWidget->setCurrentIndex( Page::Use );
    } );
}

void MainWindow::connectManager()
{

    //校准申请
    connect( ui->btn_CaliList, &QPushButton::clicked, [ this ](){
        ui->stacked_Cali->setCurrentIndex(Page_CaliApply::ApplyList);

    } );

    connect( ui->btn_CaliApplyCancle, &QPushButton::clicked, [ this ](){

    } );

    connect( ui->btn_CaliSure, &QPushButton::clicked, [ this ](){

    } );

    connect( ui->btn_CancleCali, &QPushButton::clicked, [ this ](){

    } );

    connect( ui->btn_BackCaliOverView, &QPushButton::clicked, [ this ](){
        ui->stacked_Cali->setCurrentIndex(Page_CaliApply::OverView);
    } );


    //校准结果
    connect( ui->btn_CaliResRefresh, &QPushButton::clicked, [ this ](){

    } );

    //查看曲线
    connect( ui->btn_CaliResCurve, &QPushButton::clicked, [ this ](){
        ui->popup_CheckCaliCurve->setGeometry(700,300,1050,650);
        ui->popup_CheckCaliCurve->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
        ui->popup_CheckCaliCurve->exec();
    } );

    //查看曲线-返回
    connect( ui->popup_CheckCaliCurve, &PopCheckCaliCurve::sigCheckCaliCurve, [ this ](){
        ui->popup_CheckCaliCurve->hide();
    } );

    //查找-确定
    connect( ui->popup_CaliQuery, &PopQueryCaliResult::sigCaliResQueryOk, [ this ](){

    } );

    //查找-返回
    connect( ui->popup_CaliQuery, &PopQueryCaliResult::sigCaliResQueryCancle, [ this ](){
        ui->popup_CaliQuery->hide();
    } );


    //查询
    connect( ui->btn_CaliResQuery, &QPushButton::clicked, [ this ](){
        ui->popup_CaliQuery->setGeometry(800,300,900,550);
        ui->popup_CaliQuery->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
        ui->popup_CaliQuery->exec();
    } );

    connect( ui->btn_CaliResDetails, &QPushButton::clicked, [ this ](){
        ui->stacked_CaliRes->setCurrentIndex(Page_CaliRes::ResDetails);
    } );

    connect( ui->btn_CaliResTrend, &QPushButton::clicked, [ this ](){
        ui->stacked_CaliRes->setCurrentIndex(Page_CaliRes::ResTrend);
    } );

    connect( ui->btn_CaliResExport, &QPushButton::clicked, [ this ](){

    } );

    connect( ui->btn_CaliResPrint, &QPushButton::clicked, [ this ](){

    } );

    connect( ui->btn_CaliResDel, &QPushButton::clicked, [ this ](){

    } );

    connect( ui->btn_CaliResDetailsBack, &QPushButton::clicked, [ this ](){
        ui->stacked_CaliRes->setCurrentIndex(Page_CaliRes::ResInitPage);
    } );

    connect( ui->btn_CaliThreadBack, &QPushButton::clicked, [ this ](){
        ui->stacked_CaliRes->setCurrentIndex(Page_CaliRes::ResInitPage);
    } );



    /********************************校准曲线*****************/

    //主曲线
    connect( ui->btn_CaliMainCurve, &QPushButton::clicked, [ this ](){

    } );

    //激活
    connect( ui->btn_CurveActivate, &QPushButton::clicked, [ this ](){

    } );

    //校准判定
    connect( ui->btn_CaliDecide, &QPushButton::clicked, [ this ](){

    } );

    //重新计算
    connect( ui->btn_CaliRecount, &QPushButton::clicked, [ this ](){

    } );

    //删除
    connect( ui->btn_CurveDelete, &QPushButton::clicked, [ this ](){

    } );

    //打印
    connect( ui->btn_CaliDetailPrint, &QPushButton::clicked, [ this ](){

    } );


    /*********************************校准管理*************************/

    //新增
    connect( ui->btn_CaliProductNew, &QPushButton::clicked, [ this ](){
        ui->popup_NewCaliPro->setGeometry(800,300,900,550);
        ui->popup_NewCaliPro->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
        ui->popup_NewCaliPro->exec();
    } );

    //编辑
    connect( ui->btn_CaliProductEdit, &QPushButton::clicked, [ this ](){

    } );

    //删除
    connect( ui->btn_CaliProductDel, &QPushButton::clicked, [ this ](){

    } );

    //新增-重置
    connect( ui->popup_NewCaliPro, &PopNewCaliProduct::sigNewCaliProductReset, [ this ](){

    } );

    //新增-确定
    connect( ui->popup_NewCaliPro, &PopNewCaliProduct::sigNewCaliProductOk, [ this ](){

    } );

    //新增-返回
    connect( ui->popup_NewCaliPro, &PopNewCaliProduct::sigNewCaliProductCancle, [ this ](){
        ui->popup_NewCaliPro->hide();
    } );



}

void MainWindow::initQCPageConnection()
{
    using namespace Common;
    ui->QCOverViewStackWidget->setCurrentIndex( 0 );

    //点击  质控总览 -> 申请列表按钮
    connect( ui->QCOverviewPage, &QCOverview::sigOPenQCApplyListBtnClicked, [ this ](){
        ui->QCOverViewStackWidget->setCurrentIndex( 1 );
    } );

    //点击  质控总览 -> 申请列表  -> 返回按钮
    connect( ui->QCApplyListPage, &QCApplyList::sigReturnBtnClicked, [ this ](){
        ui->QCOverViewStackWidget->setCurrentIndex( 0 );
    } );

    //点击 质控结果首页 -> 查询按钮
    connect( ui->QCResultPage, &QCResult::sigQueryClicked, [ this ]() {
        ui->QCResultStackWidget->setCurrentIndex( QCResultPageIndex::Query );
    } );

    //点击  质控结果首页 -> 详情
    connect( ui->QCResultPage, &QCResult::sigDetailClicked, [ this ]() {
        ui->QCResultStackWidget->setCurrentIndex( QCResultPageIndex::ResultDetail );
    } );

    //点击  质控查询条件 -> 返回
    connect( ui->QCResultQueryPage, &QCResultQuery::sigReturnBtnClicked, [ this ]() {
        ui->QCResultStackWidget->setCurrentIndex( QCResultPageIndex::Home );
    } );


    //点击  质控查询结果展示页面 -> 返回按钮
    connect( ui->QCResultDisplayPage, &QCResultDisplay::sigReturnBtnClicked, [ this ]() {
        ui->QCResultStackWidget->setCurrentIndex( QCResultPageIndex::Home );
    } );

    //点击  质控查询结果展示页面 -> 导出按钮  待实现接口!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    connect( ui->QCResultDisplayPage, &QCResultDisplay::sigExportBtnClicked, [ this ]() {

    } );

    //点击   质控分析  ->   查询
    connect( ui->QCAnalysisHomePage, &QCAnalysis::sigQueryBtnClicked, [ this ](){
        ui->QCAnalysisStackWidget->setCurrentIndex( QCAnalysisPageIndex::QC_Analysis_Query );
    } );

    //点击   质控分析  ->   趋势
    connect( ui->QCAnalysisHomePage, &QCAnalysis::sigTrendBtnClicked, [ this ](){
        ui->QCAnalysisStackWidget->setCurrentIndex( QCAnalysisPageIndex::QC_Analysis_Trend );
    } );

    //点击  质控趋势  ->  查询
    connect( ui->QCAnalysisTrendPage, &QCAnalysisTrend::sigQueryBtnClicked, [ this ](){
        ui->QCAnalysisStackWidget->setCurrentIndex( QCAnalysisPageIndex::QC_Analysis_Query );
    } );

    //点击  质控趋势  ->  返回
    connect( ui->QCAnalysisTrendPage, &QCAnalysisTrend::sigReturnBtnClicked, [ this ](){
        ui->QCAnalysisStackWidget->setCurrentIndex( QCAnalysisPageIndex::QC_Analysis_Home );
    } );

    //点击  质控分析 -> 查询  -> 返回
    connect( ui->QCAnalysisQueryPage, &QCAnalysisQuery::sigReturnBtnClicked, [ this ]() {
        ui->QCAnalysisStackWidget->setCurrentIndex( QCAnalysisPageIndex::QC_Analysis_Home );
    } );


    //点击  质控分析 -> 查询  -> 确定
    connect( ui->QCAnalysisQueryPage, &QCAnalysisQuery::sigConfirmBtnClicked, [ this ]() {
        // TODO:   按选择的条件筛选结果

        ui->QCAnalysisStackWidget->setCurrentIndex( QCAnalysisPageIndex::QC_Analysis_Home );
    } );

    //点击质控图  ->  TP 图
    connect( ui->QCChartsLJPage, &QCChartLJ::sigTPBtnClicked, [ this ]() {
        ui->QCChartsStackWidget->setCurrentIndex( QCChartPageIndex::QC_Chart_TP );
    } );

    //点击质控图  ->  LJ 图
    connect( ui->QCChartsTPPage, &QCChartTP::sigLJBtnClicked, [ this ]() {
        ui->QCChartsStackWidget->setCurrentIndex( QCChartPageIndex::QC_Chart_LJ );
    } );

    //点击 质控设置 扫码新增
    connect( ui->QCSettingPage, &QCSetting::sigScanfBtnClicked, [ this ]() {
        ui->QCSettingStackWidget->setCurrentIndex( QCSettingPageIndex::QC_Setting_Scanf );
    } );

    //点击 质控设置 手动新增
    connect( ui->QCSettingPage, &QCSetting::sigManualBtnClicked, [ this ]() {
        ui->QCSettingStackWidget->setCurrentIndex( QCSettingPageIndex::QC_Setting_Manual );
    } );

    //点击 质控设置 编辑
    connect( ui->QCSettingPage, &QCSetting::sigEditBtnClicked, [ this ]() {
        ui->QCSettingStackWidget->setCurrentIndex( QCSettingPageIndex::QC_Setting_Edit );
    } );

    //点击 质控设置 规则
    connect( ui->QCSettingPage, &QCSetting::sigRuleBtnClicked, [ this ]() {
        ui->QCSettingStackWidget->setCurrentIndex( QCSettingPageIndex::QC_Setting_Rule );
    } );


    //点击 质控设置 扫码新增 -> 保存
    connect( ui->QCAddByScanfPage, &QCSettingAddByScanf::sigSaveBtnClicked, [ this ]() {
        //TODO:  保存新增的质控品

        ui->QCSettingStackWidget->setCurrentIndex( QCSettingPageIndex::QC_Setting_Home );
    } );

    //点击 质控设置 扫码新增 -> 返回
    connect( ui->QCAddByScanfPage, &QCSettingAddByScanf::sigReturnBtnClicked, [ this ]() {
        ui->QCSettingStackWidget->setCurrentIndex( QCSettingPageIndex::QC_Setting_Home );
    } );

    //点击 质控设置 手动新增 -> 保存
    connect( ui->QCAddByManual, &QCSettingAddByManual::sigSaveBtnClicked, [ this ]() {
        //TODO:  保存新增的质控品

        ui->QCSettingStackWidget->setCurrentIndex( QCSettingPageIndex::QC_Setting_Home );
    } );

    //点击 质控设置 手动新增 -> 返回
    connect( ui->QCAddByManual, &QCSettingAddByManual::sigReturnBtnClicked, [ this ]() {
        ui->QCSettingStackWidget->setCurrentIndex( QCSettingPageIndex::QC_Setting_Home );
    } );

    //点击 质控设置 编辑 -> 保存
    connect( ui->QCEditPage, &QCSettingEdit::sigSaveBtnClicked, [ this ]() {
        //TODO:  保存编辑的质控品

        ui->QCSettingStackWidget->setCurrentIndex( QCSettingPageIndex::QC_Setting_Home );
    } );

    //点击 质控设置 编辑 -> 返回
    connect( ui->QCEditPage, &QCSettingEdit::sigReturnBtnClicked, [ this ]() {
        ui->QCSettingStackWidget->setCurrentIndex( QCSettingPageIndex::QC_Setting_Home );
    } );

    //点击 质控设置 规则 -> 保存
    connect( ui->QCSettingRulePage, &QCSettinRule::sigSaveBtnClicked, [ this ]() {
        //TODO:  保存新修改的规则

        ui->QCSettingStackWidget->setCurrentIndex( QCSettingPageIndex::QC_Setting_Home );
    } );

    //点击 质控设置 规则 -> 返回
    connect( ui->QCSettingRulePage, &QCSettinRule::sigReturnBtnClicked, [ this ]() {
        ui->QCSettingStackWidget->setCurrentIndex( QCSettingPageIndex::QC_Setting_Home );
    } );


    // 质控 -> 保存  -> 质控申请列表
    connect( ui->QCOverviewPage, &QCOverview::sigNewQCApplyAvailable, ui->QCApplyListPage, &QCApplyList::onNewQCApplyAvailable );
}
