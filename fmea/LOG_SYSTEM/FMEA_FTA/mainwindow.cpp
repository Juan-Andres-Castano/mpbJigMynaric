#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSerialPortInfo>
#include <QComboBox>


static xLaserLogEventDescriptor_t xLaserLogEventDescriptor[ BUFFER_LOG_SIZE ];

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      ucBufferIndex(0),
      ucBufferRunIndex(0)
    //  m_serialPortLabel(new QLabel(tr("Serial port:"))),
   //   m_serialPortComboBox(new QComboBox)
{
    ui->setupUi(this);
    connect(&m_Timer, &QTimer::timeout, this,  &MainWindow::Timer_triggered);
    connect(&m_Timer2, &QTimer::timeout, this,  &MainWindow::Timer2_triggered);

   // connect(&m_thread, &comunicationThread::response, this, &MainWindow::showResponse);
    connect(&m_thread, &comunicationThread::responseData, this, &MainWindow::showResponseData);
    connect(&m_thread, &comunicationThread::error, this, &MainWindow::processError);
    connect(&m_thread, &comunicationThread::timeout, this, &MainWindow::processTimeout);


    const auto infos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : infos)
        ui->m_serialPortComboBox->addItem(info.portName());

    connect(  this, &MainWindow::triggerLogbuffer, this, &MainWindow::transactionLog);

    ui->sampleNumber->setText( QString::number(0) );
    ui->progressBar->setValue( 0);

    m_Timer.start(500);
    m_Timer2.start(600);

  //  uint16_t mySize = sizeof(xLaserLogEventDescriptor_t);
  //  mySize++;
  //  ui->progressBar->setValue( (mySize - 1) / 10 );
}

void MainWindow::getLogData(xLaserLogEventDescriptor_t *t, uint8_t i)
{
    mpbFtaLowPowerBitAssignment_t mpbFtaLowPowerBitAssignment;
    /* fake info */
 /*   t->eControlGeneralMode = eContinuosMode;
    t->ucSampleNumber = i;
    t->xAlarmRegister.AlarmGlobalValue = 425000 * i ; //0x12345678 * i ;
    t->xAnalogTemperatureInputs.f940MultiModeLaserDiodeTemperature = 23 + i*0.2;
    t->xAnalogTemperatureInputs.f980SingleModeLaserDiodeTemperature = 26 + i*0.3;
    t->xAnalogTemperatureInputs.fQfbCaseRawTemperature = 30 + i*0.4;
    t->xStatusRegister.ucStatusRegistersBytes[0] = 0x12 + i;
    t->xStatusRegister.ucStatusRegistersBytes[1] = 0x02 + i;
    t->xStatusRegister.ucStatusRegistersBytes[2] = 0x03 + i;
    t->xStatusRegister.ucStatusRegistersBytes[3] = 0x04 + i;
    //uint16_t ftaLowC = t->mpbFtaLowTempBitAssignment;
    //mpbFtaLowPowerBitAssignment = 9;
    t->mpbFtaLowTempBitAssignment.b1545ElectricalLowTemperatureFail = 1;
    t->mpbFtaLowTempBitAssignment.b980ElectricalLowTemperatureFail = 1;
    t->mpbFtaLowTempBitAssignment.bLowTemperatureFail = 1;*/
     //= (uint16_t)0x0004;

   /* splitAlarms(t->xAlarmRegister);
    splitStatus(t->xStatusRegister);
    splitFta_1( t->mpbFtaLowTempBitAssignment);
    ui->lcdNumber->display(t->xAnalogTemperatureInputs.f940MultiModeLaserDiodeTemperature );
    ui->lcdNumber_2->display(t->xAnalogTemperatureInputs.f980SingleModeLaserDiodeTemperature );
    ui->lcdNumber_3->display(t->xAnalogTemperatureInputs.fQfbCaseRawTemperature );*/

}

void MainWindow::splitAlarms(xAlarmRegister_t xAlarmRegister)
{
    bool bValue= false;


        bValue = (xAlarmRegister.AlarmsRegisterBitAssignment.b980nmLaserDiodeTemperatureIsWayTooLow == 1 ) ? true : false;
        if(bValue ==true)
        {
            ui->alarm1->setStyleSheet("background-color: red");
        }
        else
        {
            ui->alarm1->setStyleSheet("background-color: green");
        }




        bValue = (xAlarmRegister.AlarmsRegisterBitAssignment.b980nmLaserDiodeTemperatureIsTooLow == 1 ) ? true : false;
        if(bValue ==true)
        {
            ui->alarm2->setStyleSheet("background-color: red");
        }
        else
        {
            ui->alarm2->setStyleSheet("background-color: green");
        }
        bValue = (xAlarmRegister.AlarmsRegisterBitAssignment.b980nmLaserDiodeTemperatureIsToohigh == 1 ) ? true : false;
        if(bValue ==true)
        {
            ui->alarm3->setStyleSheet("background-color: red");
        }
        else
        {
            ui->alarm3->setStyleSheet("background-color: green");
        }
        bValue = (xAlarmRegister.AlarmsRegisterBitAssignment.b980nmLaserDiodeTemperatureIsWayToohigh == 1 ) ? true : false;
        if(bValue ==true)
        {
            ui->alarm4->setStyleSheet("background-color: red");
        }
        else
        {
            ui->alarm4->setStyleSheet("background-color: green");
        }
        bValue = (xAlarmRegister.AlarmsRegisterBitAssignment.b980BeaconOutputPowerIsTooLowWithRtoSetPoint == 1 ) ? true : false;
        if(bValue ==true)
        {
            ui->alarm5->setStyleSheet("background-color: red");
        }
        else
        {
            ui->alarm5->setStyleSheet("background-color: green");
        }
        bValue = (xAlarmRegister.AlarmsRegisterBitAssignment.b980BeaconOutputPowerIsTooHighWithRtoSetPoint == 1 ) ? true : false;
        if(bValue ==true)
        {
            ui->alarm6->setStyleSheet("background-color: red");
        }
        else
        {
            ui->alarm6->setStyleSheet("background-color: green");
        }
        bValue = (xAlarmRegister.AlarmsRegisterBitAssignment.b980BeaconOutputPowerIsWayTooHighWithRtoSetPoint == 1 ) ? true : false;
        if(bValue ==true)
        {
            ui->alarm7->setStyleSheet("background-color: red");
        }
        else
        {
            ui->alarm7->setStyleSheet("background-color: green");
        }
        bValue = (xAlarmRegister.AlarmsRegisterBitAssignment.b980LaserDiodeCurrentIsTooLowWithRespToSetpoint == 1 ) ? true : false;
        if(bValue ==true)
        {
            ui->alarm8->setStyleSheet("background-color: red");
        }
        else
        {
            ui->alarm8->setStyleSheet("background-color: green");
        }
        bValue = (xAlarmRegister.AlarmsRegisterBitAssignment.b980LaserDiodeCurrentIsTooHigh == 1 ) ? true : false;
        if(bValue ==true)
        {
            ui->alarm9->setStyleSheet("background-color: red");
        }
        else
        {
            ui->alarm9->setStyleSheet("background-color: green");
        }
        bValue = (xAlarmRegister.AlarmsRegisterBitAssignment.b980LaserDiodeCurrentIsWayTooHigh == 1 ) ? true : false;
        if(bValue ==true)
        {
            ui->alarm10->setStyleSheet("background-color: red");
        }
        else
        {
            ui->alarm10->setStyleSheet("background-color: green");
        }
        bValue = (xAlarmRegister.AlarmsRegisterBitAssignment.b980LaserDiodeControlValueMismatch == 1 ) ? true : false;
        if(bValue ==true)
        {
            ui->alarm11->setStyleSheet("background-color: red");
        }
        else
        {
            ui->alarm11->setStyleSheet("background-color: green");
        }
        bValue = (xAlarmRegister.AlarmsRegisterBitAssignment.b980LaserDiodeTecCurrentIsTooHigh == 1 ) ? true : false;
        if(bValue ==true)
        {
            ui->alarm12->setStyleSheet("background-color: red");
        }
        else
        {
            ui->alarm12->setStyleSheet("background-color: green");
        }
        bValue = (xAlarmRegister.AlarmsRegisterBitAssignment.b980LaserDiodeTecCurrentIsWayTooHigh == 1 ) ? true : false;
        if(bValue ==true)
        {
            ui->alarm13->setStyleSheet("background-color: red");
        }
        else
        {
            ui->alarm13->setStyleSheet("background-color: green");
        }
        bValue = (xAlarmRegister.AlarmsRegisterBitAssignment.b940LaserDiodeTemperatureIsWayTooLow == 1 ) ? true : false;
        if(bValue ==true)
        {
            ui->alarm14->setStyleSheet("background-color: red");
        }
        else
        {
            ui->alarm14->setStyleSheet("background-color: green");
        }
        bValue = (xAlarmRegister.AlarmsRegisterBitAssignment.b940LaserDiodeTemperatureIsTooLow == 1 ) ? true : false;
        if(bValue ==true)
        {
            ui->alarm15->setStyleSheet("background-color: red");
        }
        else
        {
            ui->alarm15->setStyleSheet("background-color: green");
        }
        bValue = (xAlarmRegister.AlarmsRegisterBitAssignment.b940LaserDiodeTemperatureIsTooHigh == 1 ) ? true : false;
        if(bValue ==true)
        {
            ui->alarm16->setStyleSheet("background-color: red");
        }
        else
        {
            ui->alarm16->setStyleSheet("background-color: green");
        }
        /*-*/
        bValue = (xAlarmRegister.AlarmsRegisterBitAssignment.b940LaserDiodeTemperatureIswayTooHigh == 1 ) ? true : false;
        if(bValue ==true)
        {
            ui->alarm17->setStyleSheet("background-color: red");
        }
        else
        {
            ui->alarm17->setStyleSheet("background-color: green");
        }
        bValue = (xAlarmRegister.AlarmsRegisterBitAssignment.b1545nmBeaconOutputPowerIsTooLowWrToSetpoint == 1 ) ? true : false;
        if(bValue ==true)
        {
            ui->alarm18->setStyleSheet("background-color: red");
        }
        else
        {
            ui->alarm18->setStyleSheet("background-color: green");
        }
        bValue = (xAlarmRegister.AlarmsRegisterBitAssignment.b1545nmBeaconOutputPowerIsTooHighWrToSetpoint == 1 ) ? true : false;
        if(bValue ==true)
        {
            ui->alarm19->setStyleSheet("background-color: red");
        }
        else
        {
            ui->alarm19->setStyleSheet("background-color: green");
        }
        bValue = (xAlarmRegister.AlarmsRegisterBitAssignment.b1545nmBeaconOutputPowerIswayTooHighWrToSetpoint == 1 ) ? true : false;
        if(bValue ==true)
        {
            ui->alarm20->setStyleSheet("background-color: red");
        }
        else
        {
            ui->alarm20->setStyleSheet("background-color: green");
        }
        bValue = (xAlarmRegister.AlarmsRegisterBitAssignment.b940nmLaserDiodeCurrentIsTooLowWrToSetpoint == 1 ) ? true : false;//20
        if(bValue ==true)
        {
            ui->alarm21->setStyleSheet("background-color: red");
        }
        else
        {
            ui->alarm21->setStyleSheet("background-color: green");
        }
        bValue = (xAlarmRegister.AlarmsRegisterBitAssignment.b940nmLaserDiodeCurrentIsTooHigh == 1 ) ? true : false; //21
        if(bValue ==true)
        {
            ui->alarm22->setStyleSheet("background-color: red");
        }
        else
        {
            ui->alarm22->setStyleSheet("background-color: green");
        }
        bValue = (xAlarmRegister.AlarmsRegisterBitAssignment.b940nmLaserDiodeCurrentIsWayTooHigh == 1 ) ? true : false; //22
        if(bValue ==true)
        {
            ui->alarm23->setStyleSheet("background-color: red");
        }
        else
        {
            ui->alarm23->setStyleSheet("background-color: green");
        }
        bValue = (xAlarmRegister.AlarmsRegisterBitAssignment.b940nmLaserDiodeControlValueMismatch == 1 ) ? true : false; //23
        if(bValue ==true)
        {
            ui->alarm24->setStyleSheet("background-color: red");
        }
        else
        {
            ui->alarm24->setStyleSheet("background-color: green");
        }
        bValue = (xAlarmRegister.AlarmsRegisterBitAssignment.bQfbHousingTemperatureIsWayTooLow == 1 ) ? true : false; //24
        if(bValue ==true)
        {
            ui->alarm25->setStyleSheet("background-color: red");
        }
        else
        {
            ui->alarm25->setStyleSheet("background-color: green");
        }
        bValue = (xAlarmRegister.AlarmsRegisterBitAssignment.bQfbHousingTemperatureIsTooLow == 1 ) ? true : false; //25
        if(bValue ==true)
        {
            ui->alarm26->setStyleSheet("background-color: red");
        }
        else
        {
            ui->alarm26->setStyleSheet("background-color: green");
        }
        bValue = (xAlarmRegister.AlarmsRegisterBitAssignment.bQfbHousingTemperatureIsTooHigh == 1 ) ? true : false; //26
        if(bValue ==true)
        {
            ui->alarm27->setStyleSheet("background-color: red");
        }
        else
        {
            ui->alarm27->setStyleSheet("background-color: green");
        }
        bValue = (xAlarmRegister.AlarmsRegisterBitAssignment.bQfbHousingTemperatureIsWayTooHigh == 1 ) ? true : false; //27
        if(bValue ==true)
        {
            ui->alarm28->setStyleSheet("background-color: red");
        }
        else
        {
            ui->alarm28->setStyleSheet("background-color: green");
        }
        bValue = (xAlarmRegister.AlarmsRegisterBitAssignment.bPhotoDiodeOffsetVoltageTooLow == 1 ) ? true : false; //28
        if(bValue ==true)
        {
            ui->alarm29->setStyleSheet("background-color: red");
        }
        else
        {
            ui->alarm29->setStyleSheet("background-color: green");
        }
        bValue = (xAlarmRegister.AlarmsRegisterBitAssignment.bPhotoDiodeOffsetVoltageTooHigh == 1 ) ? true : false; //29
        if(bValue ==true)
        {
            ui->alarm30->setStyleSheet("background-color: red");
        }
        else
        {
            ui->alarm30->setStyleSheet("background-color: green");
        }
        bValue = (xAlarmRegister.AlarmsRegisterBitAssignment.bMcuInternal_2_5_V_ReferenceVoltageTooLow == 1 ) ? true : false; //30
        if(bValue ==true)
        {
            ui->alarm31->setStyleSheet("background-color: red");
        }
        else
        {
            ui->alarm31->setStyleSheet("background-color: green");
        }
        bValue = (xAlarmRegister.AlarmsRegisterBitAssignment.bMcuInternal_2_5_V_ReferenceVoltageTooHigh == 1 ) ? true : false; //31
        if(bValue ==true)
        {
            ui->alarm32->setStyleSheet("background-color: red");
        }
        else
        {
            ui->alarm32->setStyleSheet("background-color: green");
        }
        /* ---*/
        bValue = (xAlarmRegister.AlarmsRegisterBitAssignment.bMcuInternalTemperatureIsWayTooLow == 1 ) ? true : false; //32
        if(bValue ==true)
        {
            ui->alarm33->setStyleSheet("background-color: red");
        }
        else
        {
            ui->alarm33->setStyleSheet("background-color: green");
        }
        bValue = (xAlarmRegister.AlarmsRegisterBitAssignment.bMcuInternalTemperatureIsTooLow == 1 ) ? true : false; //33
        if(bValue ==true)
        {
            ui->alarm34->setStyleSheet("background-color: red");
        }
        else
        {
            ui->alarm34->setStyleSheet("background-color: green");
        }
        bValue = (xAlarmRegister.AlarmsRegisterBitAssignment.bMcuInternalTemperatureIsTooHigh == 1 ) ? true : false; //34
        if(bValue ==true)
        {
            ui->alarm35->setStyleSheet("background-color: red");
        }
        else
        {
            ui->alarm35->setStyleSheet("background-color: green");
        }
        bValue = (xAlarmRegister.AlarmsRegisterBitAssignment.bMcuInternalTemperatureIsWayTooHigh == 1 ) ? true : false; //35
        if(bValue ==true)
        {
            ui->alarm36->setStyleSheet("background-color: red");
        }
        else
        {
            ui->alarm36->setStyleSheet("background-color: green");
        }
        bValue = (xAlarmRegister.AlarmsRegisterBitAssignment.bSerialPort0HasAReceiveError == 1 ) ? true : false;//36
        if(bValue ==true)
        {
            ui->alarm37->setStyleSheet("background-color: red");
        }
        else
        {
            ui->alarm37->setStyleSheet("background-color: green");
        }
        bValue = (xAlarmRegister.AlarmsRegisterBitAssignment.bSerialPort0HasATransmitError == 1 ) ? true : false; //37
        if(bValue ==true)
        {
            ui->alarm38->setStyleSheet("background-color: red");
        }
        else
        {
            ui->alarm38->setStyleSheet("background-color: green");
        }
        bValue = (xAlarmRegister.AlarmsRegisterBitAssignment.bSerialPort1HasAReceiveError == 1 ) ? true : false; //38
        if(bValue ==true)
        {
            ui->alarm39->setStyleSheet("background-color: red");
        }
        else
        {
            ui->alarm39->setStyleSheet("background-color: green");
        }
        bValue = (xAlarmRegister.AlarmsRegisterBitAssignment.bSerialPort1HasATransmitError == 1 ) ? true : false; //39
        if(bValue ==true)
        {
            ui->alarm40->setStyleSheet("background-color: red");
        }
        else
        {
            ui->alarm40->setStyleSheet("background-color: green");
        }
        bValue = (xAlarmRegister.AlarmsRegisterBitAssignment.bBootMemoryCommunicationError == 1 ) ? true : false; // 40
        if(bValue ==true)
        {
            ui->alarm41->setStyleSheet("background-color: red");
        }
        else
        {
            ui->alarm41->setStyleSheet("background-color: green");
        }
        bValue = (xAlarmRegister.AlarmsRegisterBitAssignment.bMemoryACommunicationError == 1 ) ? true : false; // 41
        if(bValue ==true)
        {
            ui->alarm42->setStyleSheet("background-color: red");
        }
        else
        {
            ui->alarm42->setStyleSheet("background-color: green");
        }
        bValue = (xAlarmRegister.AlarmsRegisterBitAssignment.bMemoryBCommunicationError == 1 ) ? true : false; // 42
        if(bValue ==true)
        {
            ui->alarm43->setStyleSheet("background-color: red");
        }
        else
        {
            ui->alarm43->setStyleSheet("background-color: green");
        }
        bValue = (xAlarmRegister.AlarmsRegisterBitAssignment.bBootMemoryCrcErrorDetectedAtPowerUp == 1 ) ? true : false; // 43
        if(bValue ==true)
        {
            ui->alarm44->setStyleSheet("background-color: red");
        }
        else
        {
            ui->alarm44->setStyleSheet("background-color: green");
        }
        bValue = (xAlarmRegister.AlarmsRegisterBitAssignment.bMemoryACrcErrorDetectedAtPowerUp == 1 ) ? true : false; // 44
        if(bValue ==true)
        {
            ui->alarm45->setStyleSheet("background-color: red");
        }
        else
        {
            ui->alarm45->setStyleSheet("background-color: green");
        }
        bValue = (xAlarmRegister.AlarmsRegisterBitAssignment.bMemoryBCrcErrorDetectedAtPowerUp == 1 ) ? true : false; // 45
        if(bValue ==true)
        {
            ui->alarm46->setStyleSheet("background-color: red");
        }
        else
        {
            ui->alarm46->setStyleSheet("background-color: green");
        }
        bValue = (xAlarmRegister.AlarmsRegisterBitAssignment.bSerialPort0HasAReceivedErrorCondition == 1 ) ? true : false; // 46
        if(bValue ==true)
        {
            ui->alarm47->setStyleSheet("background-color: red");
        }
        else
        {
            ui->alarm47->setStyleSheet("background-color: green");
        }
        bValue = (xAlarmRegister.AlarmsRegisterBitAssignment.bSerialPort1HasAReceivedErrorCondition == 1 ) ? true : false; // 47
        if(bValue ==true)
        {
            ui->alarm48->setStyleSheet("background-color: red");
        }
        else
        {
            ui->alarm48->setStyleSheet("background-color: green");
        }
        /*---*/

        bValue = (xAlarmRegister.AlarmsRegisterBitAssignment.bErrorDetectedInProramMemoryA == 1 ) ? true : false; //32
        if(bValue ==true)
        {
            ui->alarm49->setStyleSheet("background-color: red");
        }
        else
        {
            ui->alarm49->setStyleSheet("background-color: green");
        }
        bValue = (xAlarmRegister.AlarmsRegisterBitAssignment.bErrorDetectedInProramMemoryB == 1 ) ? true : false; //33
        if(bValue ==true)
        {
            ui->alarm50->setStyleSheet("background-color: red");
        }
        else
        {
            ui->alarm50->setStyleSheet("background-color: green");
        }
        bValue = (xAlarmRegister.AlarmsRegisterBitAssignment.bErrorDetectedInDataMemoryA == 1 ) ? true : false; //34
        if(bValue ==true)
        {
            ui->alarm51->setStyleSheet("background-color: red");
        }
        else
        {
            ui->alarm51->setStyleSheet("background-color: green");
        }
        bValue = (xAlarmRegister.AlarmsRegisterBitAssignment.bErrorDetectedInDataMemoryB == 1 ) ? true : false; //35
        if(bValue ==true)
        {
            ui->alarm52->setStyleSheet("background-color: red");
        }
        else
        {
            ui->alarm52->setStyleSheet("background-color: green");
        }
        bValue = (xAlarmRegister.AlarmsRegisterBitAssignment.bCalibrationDataIsMissing == 1 ) ? true : false;//36
        if(bValue ==true)
        {
            ui->alarm53->setStyleSheet("background-color: red");
        }
        else
        {
            ui->alarm53->setStyleSheet("background-color: green");
        }
        bValue = (xAlarmRegister.AlarmsRegisterBitAssignment.bAlarmConditionFromOtherMcuSection == 1 ) ? true : false; //37
        if(bValue ==true)
        {
            ui->alarm54->setStyleSheet("background-color: red");
        }
        else
        {
            ui->alarm54->setStyleSheet("background-color: green");
        }
        bValue = (xAlarmRegister.AlarmsRegisterBitAssignment.bSpiAdcTimeoutAlarm == 1 ) ? true : false; //38
        if(bValue ==true)
        {
            ui->alarm55->setStyleSheet("background-color: red");
        }
        else
        {
            ui->alarm55->setStyleSheet("background-color: green");
        }
        bValue = (xAlarmRegister.AlarmsRegisterBitAssignment.b422TransceiversSp0drawExcessiceCurrent == 1 ) ? true : false; //39
        if(bValue ==true)
        {
            ui->alarm56->setStyleSheet("background-color: red");
        }
        else
        {
            ui->alarm56->setStyleSheet("background-color: green");
        }
        bValue = (xAlarmRegister.AlarmsRegisterBitAssignment.b422TransceiversSp1drawExcessiceCurrent == 1 ) ? true : false; // 40
        if(bValue ==true)
        {
            ui->alarm57->setStyleSheet("background-color: red");
        }
        else
        {
            ui->alarm57->setStyleSheet("background-color: green");
        }
        bValue = (xAlarmRegister.AlarmsRegisterBitAssignment.bMemoryADrwasExcessiceCurrent == 1 ) ? true : false; // 41
        if(bValue ==true)
        {
            ui->alarm58->setStyleSheet("background-color: red");
        }
        else
        {
            ui->alarm58->setStyleSheet("background-color: green");
        }
        bValue = (xAlarmRegister.AlarmsRegisterBitAssignment.bMemoryBDrwasExcessiceCurrent == 1 ) ? true : false; // 42
        if(bValue ==true)
        {
            ui->alarm59->setStyleSheet("background-color: red");
        }
        else
        {
            ui->alarm59->setStyleSheet("background-color: green");
        }
        bValue = (xAlarmRegister.AlarmsRegisterBitAssignment.bAlarmsSpare == 1 ) ? true : false; // 43
        if(bValue ==true)
        {
            ui->alarm60->setStyleSheet("background-color: red");
        }
        else
        {
            ui->alarm60->setStyleSheet("background-color: green");
        }
        bValue = (xAlarmRegister.AlarmsRegisterBitAssignment.bMemoryACrcErrorDetectedAtPowerUp == 1 ) ? true : false; // 44
        if(bValue ==true)
        {
            ui->alarm61->setStyleSheet("background-color: red");
        }
        else
        {
            ui->alarm61->setStyleSheet("background-color: green");
        }
        bValue = (xAlarmRegister.AlarmsRegisterBitAssignment.bMemoryBCrcErrorDetectedAtPowerUp == 1 ) ? true : false; // 45
        if(bValue ==true)
        {
            ui->alarm62->setStyleSheet("background-color: red");
        }
        else
        {
            ui->alarm62->setStyleSheet("background-color: green");
        }
        bValue = (xAlarmRegister.AlarmsRegisterBitAssignment.bSerialPort0HasAReceivedErrorCondition == 1 ) ? true : false; // 46
        if(bValue ==true)
        {
            ui->alarm63->setStyleSheet("background-color: red");
        }
        else
        {
            ui->alarm63->setStyleSheet("background-color: green");
        }
        bValue = (xAlarmRegister.AlarmsRegisterBitAssignment.bSerialPort1HasAReceivedErrorCondition == 1 ) ? true : false; // 47
        if(bValue ==true)
        {
            ui->alarm64->setStyleSheet("background-color: red");
        }
        else
        {
            ui->alarm64->setStyleSheet("background-color: green");
        }


}

void MainWindow::splitStatus(xStatusRegister_t xStatusRegister)
{
    bool bValue = false;

    bValue = ( xStatusRegister.StatusRegisterBitAssignment.bDeviceIsAssignedHardwareAddress0 == 1 ) ? 1 : 0;
    if(bValue ==true)
    {
        ui->status_1->setStyleSheet("background-color: white");
    }
    else
    {
        ui->status_1->setStyleSheet("background-color: gray");
    }



    bValue = ( xStatusRegister.StatusRegisterBitAssignment.bSp0IsthePrimarySerialPort == 1 ) ? 1 : 0;
    if(bValue ==true)
    {
        ui->status_2->setStyleSheet("background-color: white");
    }
    else
    {
        ui->status_2->setStyleSheet("background-color: gray");
    }



    bValue = ( xStatusRegister.StatusRegisterBitAssignment.bMeMpryBankAIsUsedAtFirstBootUp == 1 ) ? 1 : 0;
    if(bValue ==true)
    {
        ui->status_3->setStyleSheet("background-color: white");
    }
    else
    {
        ui->status_3->setStyleSheet("background-color: gray");
    }



    bValue = ( xStatusRegister.StatusRegisterBitAssignment.bCodeFromMemoryBankAIsCurrentlyInUse == 1 ) ? 1 : 0;
    if(bValue ==true)
    {
        ui->status_4->setStyleSheet("background-color: white");
    }
    else
    {
        ui->status_4->setStyleSheet("background-color: gray");
    }


    bValue = ( xStatusRegister.StatusRegisterBitAssignment.bQfbIsInOffState == 1 ) ? 1 : 0;
    if(bValue ==true)
    {
        ui->status_5->setStyleSheet("background-color: white");
    }
    else
    {
        ui->status_5->setStyleSheet("background-color: gray");
    }

    bValue = ( xStatusRegister.StatusRegisterBitAssignment.bQfbIsInReadyState == 1 ) ? 1 : 0;
    if(bValue ==true)
    {
        ui->status_6->setStyleSheet("background-color: white");
    }
    else
    {
        ui->status_6->setStyleSheet("background-color: gray");
    }

    bValue = ( xStatusRegister.StatusRegisterBitAssignment.bQfbIsInOnState == 1 ) ? 1 : 0;
    if(bValue ==true)
    {
        ui->status_7->setStyleSheet("background-color: white");
    }
    else
    {
        ui->status_7->setStyleSheet("background-color: gray");
    }

    bValue = ( xStatusRegister.StatusRegisterBitAssignment.bQfbIsInFaultState == 1 ) ? 1 : 0;
    if(bValue ==true)
    {
        ui->status_8->setStyleSheet("background-color: white");
    }
    else
    {
        ui->status_8->setStyleSheet("background-color: gray");
    }



    bValue = ( xStatusRegister.StatusRegisterBitAssignment.bQfbIsIntestState == 1 ) ? 1 : 0;
    if(bValue ==true)
    {
        ui->status_9->setStyleSheet("background-color: white");
    }
    else
    {
        ui->status_9->setStyleSheet("background-color: gray");
    }



    bValue = ( xStatusRegister.StatusRegisterBitAssignment.bUnlockModeIsActive == 1 ) ? 1 : 0;
    if(bValue ==true)
    {
        ui->status_10->setStyleSheet("background-color: white");
    }
    else
    {
        ui->status_10->setStyleSheet("background-color: gray");
    }

    bValue = ( xStatusRegister.StatusRegisterBitAssignment.b980LaserDiodeDriverIsEnabled == 1 ) ? 1 : 0;
    if(bValue ==true)
    {
        ui->status_11->setStyleSheet("background-color: white");
    }
    else
    {
        ui->status_11->setStyleSheet("background-color: gray");
    }


    bValue = ( xStatusRegister.StatusRegisterBitAssignment.b980BeaconIsEmmitingPower == 1 ) ? 1 : 0;
    if(bValue ==true)
    {
        ui->status_12->setStyleSheet("background-color: white");
    }
    else
    {
        ui->status_12->setStyleSheet("background-color: gray");
    }


    bValue = ( xStatusRegister.StatusRegisterBitAssignment.b980LaserDiodeTecIsEnabled == 1 ) ? 1 : 0;
    if(bValue ==true)
    {
        ui->status_13->setStyleSheet("background-color: white");
    }
    else
    {
        ui->status_13->setStyleSheet("background-color: gray");
    }

    bValue = ( xStatusRegister.StatusRegisterBitAssignment.b980LaserDiodeCaseTemperatureIsNormal == 1 ) ? 1 : 0;
    if(bValue ==true)
    {
        ui->status_14->setStyleSheet("background-color: white");
    }
    else
    {
        ui->status_14->setStyleSheet("background-color: gray");
    }



    bValue = ( xStatusRegister.StatusRegisterBitAssignment.b980BeaconIsInAccMode == 1 ) ? 1 : 0;
    if(bValue ==true)
    {
        ui->status_15->setStyleSheet("background-color: white");
    }
    else
    {
        ui->status_15->setStyleSheet("background-color: gray");
    }

    bValue = ( xStatusRegister.StatusRegisterBitAssignment.b980BeaconIsInApcMode == 1 ) ? 1 : 0;
    if(bValue ==true)
    {
        ui->status_16->setStyleSheet("background-color: white");
    }
    else
    {
        ui->status_16->setStyleSheet("background-color: gray");
    }

    bValue = ( xStatusRegister.StatusRegisterBitAssignment.b940LaserDiodeDriverIsEnabled == 1 ) ? 1 : 0;
    if(bValue ==true)
    {
        ui->status_17->setStyleSheet("background-color: white");
    }
    else
    {
        ui->status_17->setStyleSheet("background-color: gray");
    }

    bValue = ( xStatusRegister.StatusRegisterBitAssignment.b1545nmBeaconIsEmittingPower == 1 ) ? 1 : 0;
    if(bValue ==true)
    {
        ui->status_18->setStyleSheet("background-color: white");
    }
    else
    {
        ui->status_18->setStyleSheet("background-color: gray");
    }

    bValue = ( xStatusRegister.StatusRegisterBitAssignment.b940caseTemperatureIsInNormalRange == 1 ) ? 1 : 0;
    if(bValue ==true)
    {
        ui->status_19->setStyleSheet("background-color: white");
    }
    else
    {
        ui->status_19->setStyleSheet("background-color: gray");
    }

    bValue = ( xStatusRegister.StatusRegisterBitAssignment.b1545nmBeaconIsInAccMode == 1 ) ? 1 : 0;
    if(bValue ==true)
    {
        ui->status_20->setStyleSheet("background-color: white");
    }
    else
    {
        ui->status_20->setStyleSheet("background-color: gray");
    }

    bValue = ( xStatusRegister.StatusRegisterBitAssignment.b1545nmBeaconIsInApcMode == 1 ) ? 1 : 0;
    if(bValue ==true)
    {
        ui->status_21->setStyleSheet("background-color: white");
    }
    else
    {
        ui->status_21->setStyleSheet("background-color: gray");
    }

    bValue = ( xStatusRegister.StatusRegisterBitAssignment.bResetLineFromOtherMcuSection == 1 ) ? 1 : 0;
    if(bValue ==true)
    {
        ui->status_22->setStyleSheet("background-color: white");
    }
    else
    {
        ui->status_22->setStyleSheet("background-color: gray");
    }

    bValue = ( xStatusRegister.StatusRegisterBitAssignment.bPowerFailFromOtherMcuSection == 1 ) ? 1 : 0;
    if(bValue ==true)
    {
        ui->status_23->setStyleSheet("background-color: white");
    }
    else
    {
        ui->status_23->setStyleSheet("background-color: gray");
    }
    ui->status_24->setStyleSheet("background-color: black");
    ui->status_25->setStyleSheet("background-color: black");
    ui->status_26->setStyleSheet("background-color: black");
    ui->status_27->setStyleSheet("background-color: black");
    ui->status_28->setStyleSheet("background-color: black");
    ui->status_29->setStyleSheet("background-color: black");
    ui->status_30->setStyleSheet("background-color: black");
    ui->status_31->setStyleSheet("background-color: black");
    ui->status_32->setStyleSheet("background-color: black");


}

void MainWindow::splitFta_1(mpbFtaLowTempBitAssignment_t mpbFtaLowTempBitAssignment)
{

    bool bValue = false;
    bValue = (mpbFtaLowTempBitAssignment.b980nmcomputingError == 1)? 1 : 0;
    if(bValue == 1)
    {
        ui->fta1_1->setStyleSheet("background-color: red");
    }
    else
    {
        ui->fta1_1->setStyleSheet("background-color: white");
    }


    bValue = (mpbFtaLowTempBitAssignment.bLowTemperatureFail == 1)? 1 : 0;
    if(bValue == 1)
    {
        ui->fta1_2->setStyleSheet("background-color: red");
    }
    else
    {
        ui->fta1_2->setStyleSheet("background-color: white");
    }

    bValue = (mpbFtaLowTempBitAssignment.bNormalLowTemperatureFail == 1)? 1 : 0;
    if(bValue == 1)
    {
        ui->fta1_3->setStyleSheet("background-color: red");
    }
    else
    {
        ui->fta1_3->setStyleSheet("background-color: white");
    }





    bValue = (mpbFtaLowTempBitAssignment.bElectricalFailLowTemperature == 1)? 1 : 0;
    if(bValue == 1)
    {
        ui->fta1_4->setStyleSheet("background-color: red");
    }
    else
    {
        ui->fta1_4->setStyleSheet("background-color: white");
    }


    bValue = (mpbFtaLowTempBitAssignment.b980NormalLowTemperatureFail == 1)? 1 : 0;
    if(bValue == 1)
    {
        ui->fta1_5->setStyleSheet("background-color: red");
    }
    else
    {
        ui->fta1_5->setStyleSheet("background-color: white");
    }

    bValue = (mpbFtaLowTempBitAssignment.b1545NormalLowTemperatureFail == 1)? 1 : 0;
    if(bValue == 1)
    {
        ui->fta1_6->setStyleSheet("background-color: red");
    }
    else
    {
        ui->fta1_6->setStyleSheet("background-color: white");
    }

    bValue = (mpbFtaLowTempBitAssignment.b980ElectricalLowTemperatureFail == 1)? 1 : 0;
    if(bValue == 1)
    {
        ui->fta1_7->setStyleSheet("background-color: red");
    }
    else
    {
        ui->fta1_7->setStyleSheet("background-color: white");
    }
    bValue = (mpbFtaLowTempBitAssignment.b1545ElectricalLowTemperatureFail == 1)? 1 : 0;
    if(bValue == 1)
    {
        ui->fta1_8->setStyleSheet("background-color: red");
    }
    else
    {
        ui->fta1_8->setStyleSheet("background-color: white");
    }



}


void MainWindow::splitFmea(mpbFmeaMode_t mpbFmeaMode)
{
    bool bValue = false;
    //mpbFmeaMode
    bValue = ( mpbFmeaMode == mpbFmeaLnaPowerMonitor)? 1 : 0;
    if(bValue == 1)
    {
        ui->mpbFmeaLnaPowerMonitor->setStyleSheet("background-color: red");
        ui->mpbFmeaLowTemp980Fault->setStyleSheet("background-color: red");

    }
    else
    {
        ui->mpbFmeaLnaPowerMonitor->setStyleSheet("background-color: white");
        ui->mpbFmeaLowTemp980Fault->setStyleSheet("background-color: white");
    }

    bValue = ( mpbFmeaMode == mpbFmeaLnaCurrentMonitor)? 1 : 0;
    if(bValue == 1)
    {
        ui->mpbFmeaLnaCurrentMonitor->setStyleSheet("background-color: red");
    }
    else
    {
        ui->mpbFmeaLnaCurrentMonitor->setStyleSheet("background-color: white");
    }

    bValue = ( mpbFmeaMode == mpbFmeaLnaTempMonitor)? 1 : 0;
    if(bValue == 1)
    {
        ui->mpbFmeaLnaTempMonitor->setStyleSheet("background-color: red");
        ui->mpbFmeaLowTemp980Design_C1->setStyleSheet("background-color: red");

    }
    else
    {
        ui->mpbFmeaLnaTempMonitor->setStyleSheet("background-color: white");
        ui->mpbFmeaLowTemp980Design_C1->setStyleSheet("background-color: white");
    }

    bValue = ( mpbFmeaMode == mpbFmeaHpaPowerMonitor)? 1 : 0;
    if(bValue == 1)
    {
        ui->mpbFmeaHpaPowerMonitor->setStyleSheet("background-color: red");
    }
    else
    {
        ui->mpbFmeaHpaPowerMonitor->setStyleSheet("background-color: white");
    }



}
void MainWindow::splitFta_0(mpbFtaLowPowerBitAssignment_t mpbFtaLowPowerBitAssignment)
{
    bool bValue = false;
    bValue = (mpbFtaLowPowerBitAssignment.b980PoweromputingError == 1)? 1 : 0;
    if(bValue == 1)
    {
        ui->b980PowerComputingError->setStyleSheet("background-color: red");
    }
    else
    {
        ui->b980PowerComputingError->setStyleSheet("background-color: white");
    }

    bValue = (mpbFtaLowPowerBitAssignment.b1545PowercomputingError == 1)? 1 : 0;
    if(bValue == 1)
    {
        ui->b1545PowercomputingError->setStyleSheet("background-color: red");
    }
    else
    {
        ui->b1545PowercomputingError->setStyleSheet("background-color: white");
    }
//

    bValue = (mpbFtaLowPowerBitAssignment.bLowPowerFail == 1)? 1 : 0;
    if(bValue == 1)
    {
        ui->bLowPowerFail->setStyleSheet("background-color: red");
    }
    else
    {
        ui->bLowPowerFail->setStyleSheet("background-color: white");
    }
//
    bValue = (mpbFtaLowPowerBitAssignment.bNormalLowPowerFail == 1)? 1 : 0;
    if(bValue == 1)
    {
        ui->bNormalLowPowerFail->setStyleSheet("background-color: red");
    }
    else
    {
        ui->bNormalLowPowerFail->setStyleSheet("background-color: white");
    }

//



    bValue = (mpbFtaLowPowerBitAssignment.bElectricalFailLowPower == 1)? 1 : 0;
    if(bValue == 1)
    {
        ui->bElectricalFailLowPower->setStyleSheet("background-color: red");
    }
    else
    {
        ui->bElectricalFailLowPower->setStyleSheet("background-color: white");
    }

//
    bValue = (mpbFtaLowPowerBitAssignment.b980NormalLowPowerFail == 1)? 1 : 0;
    if(bValue == 1)
    {
        ui->b980NormalLowPowerFail->setStyleSheet("background-color: red");
    }
    else
    {
        ui->b980NormalLowPowerFail->setStyleSheet("background-color: white");
    }
//
    bValue = (mpbFtaLowPowerBitAssignment.b1545NormalLowPowerFail == 1)? 1 : 0;
    if(bValue == 1)
    {
        ui->b1545NormalLowPowerFail->setStyleSheet("background-color: red");
    }
    else
    {
        ui->b1545NormalLowPowerFail->setStyleSheet("background-color: white");
    }
//
    bValue = (mpbFtaLowPowerBitAssignment.b980ElectricalLowPowerFail == 1)? 1 : 0;
    if(bValue == 1)
    {
        ui->b980ElectricalLowPowerFail->setStyleSheet("background-color: red");
    }
    else
    {
        ui->b980ElectricalLowPowerFail->setStyleSheet("background-color: white");
    }
    //
    bValue = (mpbFtaLowPowerBitAssignment.b1545ElectricalLowPowerFail == 1)? 1 : 0;
    if(bValue == 1)
    {
        ui->b1545ElectricalLowPowerFail->setStyleSheet("background-color: red");
    }
    else
    {
        ui->b1545ElectricalLowPowerFail->setStyleSheet("background-color: white");
    }

}

xLaserLogEventDescriptor_t* MainWindow::setBuffer(uint8_t newUcBufferIndex)
{
    return &xLaserLogEventDescriptor[newUcBufferIndex];
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{


}

void MainWindow::Timer2_triggered()
{

    static uint8_t Internalindex = 0;
    xLaserLogEventDescriptor_t *pxLaserLogEventDescriptor;
    static bool color = false;


    uint8_t runEnable = getUcBufferRunIndex();

    if(runEnable == 1)
    {
        if(color == false)
        {
            color = true;
            ui->frame_7->setStyleSheet("background-color: red");

        }
        else
        {
            color = false;
            ui->frame_7->setStyleSheet("background-color: black");
        }
        //setUcBufferIndex(0);

        //ui->forward->QWidget::

        if( Internalindex < 40 )
        {


           emit triggerLogbuffer( Internalindex );
           ui->progressBar->setValue( 100*Internalindex/40);
           ui->sampleNumber->setText( QString::number(Internalindex) );
           Internalindex++;




        }
        else
        {


            ui->sampleNumber->setText( QString::number(0) );
            ui->progressBar->setValue( 0);
            Internalindex = 0;
            setUcBufferRunIndex(0);
            setBuffer(0);
            pxLaserLogEventDescriptor = setBuffer( 0 );
            showResponseDataBuffer( pxLaserLogEventDescriptor );

            ui->frame_7->setStyleSheet("background-color: blue");
            //index = 0;
        }

    }











}
/*
void MainWindow::fill_BufferLog()
{
    xLaserLogEventDescriptor_t xLaserLogEventDescriptorTemp;

    for (int i =0; i< BUFFER_LOG_SIZE;i++)
    {
        //add here transaction
       // getLogData(&xLaserLogEventDescriptorTemp, i);

       // memcpy(&xLaserLogEventDescriptor[i],&xLaserLogEventDescriptorTemp, sizeof(xLaserLogEventDescriptor_t));



    }
}*/

uint8_t MainWindow::getUcBufferIndex() const
{
    return ucBufferIndex;
}
/*
void MainWindow::showResponse(const QString &s)
{

}*/

void MainWindow::showResponseData(const quint8 *buffer)
{

    //xLaserLogEventDescriptor_t xLaserLogEventDescriptor;
    quint8 index;
    uint8_t pData = 4 ;


    typedef union
{
    uint32_t ulmpbLogEventTime;
    uint8_t ucValue[4];
}MyConversionShortData_t;
MyConversionShortData_t MyConversionShortTimeLog;
//MyConversionShortTimeLog.ulmpbLogEventTime = (pxLaserLogEventDescriptor->usmpbLogEventTime);
    MyConversionShortTimeLog.ucValue[0] = buffer[4]      ;
    MyConversionShortTimeLog.ucValue[1] = buffer[5]      ;
    MyConversionShortTimeLog.ucValue[2] = buffer[6]      ;
    MyConversionShortTimeLog.ucValue[3] = buffer[7]      ;

    index = buffer[8];
    (&xLaserLogEventDescriptor[index])->ulmpbLogEventTime =    MyConversionShortTimeLog.ulmpbLogEventTime      ;


   // memset( &xLaserLogEventDescriptor[index], 0, sizeof(xLaserLogEventDescriptor_t) );

    (&xLaserLogEventDescriptor[index])->ucSampleNumber =   index;// buffer[8]      ;


    typedef union
    {
        mpbFmeaMode_t mpbFmeaMode;
        uint8_t ucFmeaValue;
    }MyfmeaConversionData_t;
    MyfmeaConversionData_t MyfmeaConversionData;
    MyfmeaConversionData.ucFmeaValue = buffer[pData++]      ;  //9
    (&xLaserLogEventDescriptor[index])->mpbFmeaMode =  MyfmeaConversionData.mpbFmeaMode;

    typedef union
    {
        mpbFtaLowTempBitAssignment_t mpbFtaLowTempBitAssignment;
        uint8_t ucFtaLowTempValue[2];
    }MyftaLowTempConversionData_t;
    MyftaLowTempConversionData_t MyftaLowTempConversionData;
    MyftaLowTempConversionData.ucFtaLowTempValue[0] = buffer[pData++]      ;
    MyftaLowTempConversionData.ucFtaLowTempValue[1] = buffer[pData++]      ;
    (&xLaserLogEventDescriptor[index])->mpbFtaLowTempBitAssignment = MyftaLowTempConversionData.mpbFtaLowTempBitAssignment;

    typedef union
    {
    mpbFtaLowPowerBitAssignment_t mpbFtaLowPowerBitAssignment;
    uint8_t ucFtaLowPowerValue[2];
    }mpbFtaLowPower_t;
    mpbFtaLowPower_t mpbFtaLowPowerConversion ;
    mpbFtaLowPowerConversion.ucFtaLowPowerValue[0] = buffer[pData++]      ;
    mpbFtaLowPowerConversion.ucFtaLowPowerValue[1] = buffer[pData++]      ;
    (&xLaserLogEventDescriptor[index])->mpbFtaLowPowerBitAssignment = mpbFtaLowPowerConversion.mpbFtaLowPowerBitAssignment;

    typedef union
    {
        eMainLoopState_t eMainLoopState;
        uint8_t ucMainLoopValue;
    }MainLoopConversionData_t;
    MainLoopConversionData_t MainLoopConversionData;
    MainLoopConversionData.ucMainLoopValue = buffer[pData++]      ;
    (&xLaserLogEventDescriptor[index])->eMpbLogMainLoopState =   MainLoopConversionData.eMainLoopState      ;


    typedef union
    {
        eBeaconIdUsedActually_t eBeaconIdUsedActually;
        uint8_t ucBeaconIdValue;
    }MyConversionIdData_t;
    MyConversionIdData_t MyConversionIdData;
    MyConversionIdData.ucBeaconIdValue = buffer[15]      ;
    (&xLaserLogEventDescriptor[index])->xBeaconId = MyConversionIdData.eBeaconIdUsedActually;


    typedef union
    {
        xLaserOperationMode_t xLaserOperationMode[2];
        uint8_t ucLaserOperation[2];
    }MyConversionLaserOpeData_t;
    MyConversionLaserOpeData_t MyConversionLaserOpeData;

    MyConversionLaserOpeData.ucLaserOperation[0] = buffer[16]      ;
    MyConversionLaserOpeData.ucLaserOperation[1] = buffer[17]      ;

    (&xLaserLogEventDescriptor[index])->xLaserOperationMode[0].bLaserIsEnable = (eBool_t) buffer[18]  ;//MyConversionLaserOpeData.xLaserOperationMode[0];
    (&xLaserLogEventDescriptor[index])->xLaserOperationMode[0].bTecIsEnable = (eBool_t) buffer[19] ; //MyConversionLaserOpeData.xLaserOperationMode[1];


    typedef union
    {
        xElectricalVariablesStatus_t xElectricalVariablesStatus;
        uint8_t ucElectricalValuesValues[16];
    }MyConversionelectricalVariablesData_t;
    MyConversionelectricalVariablesData_t MyConversionelectricalVariablesData;

    MyConversionelectricalVariablesData.ucElectricalValuesValues[0] = buffer[18]      ;
    MyConversionelectricalVariablesData.ucElectricalValuesValues[1] = buffer[19]      ;
    MyConversionelectricalVariablesData.ucElectricalValuesValues[2] = buffer[20]      ;
    MyConversionelectricalVariablesData.ucElectricalValuesValues[3] = buffer[21]      ;
    MyConversionelectricalVariablesData.ucElectricalValuesValues[4] = buffer[22]      ;
    MyConversionelectricalVariablesData.ucElectricalValuesValues[5] = buffer[23]      ;
    MyConversionelectricalVariablesData.ucElectricalValuesValues[6] = buffer[24]      ;
    MyConversionelectricalVariablesData.ucElectricalValuesValues[7] = buffer[25]      ;
    MyConversionelectricalVariablesData.ucElectricalValuesValues[8] = buffer[26]      ;
    MyConversionelectricalVariablesData.ucElectricalValuesValues[9] = buffer[27]      ;
    MyConversionelectricalVariablesData.ucElectricalValuesValues[10] = buffer[28]      ;
    MyConversionelectricalVariablesData.ucElectricalValuesValues[11] = buffer[29]      ;
    MyConversionelectricalVariablesData.ucElectricalValuesValues[12] = buffer[30]      ;
    MyConversionelectricalVariablesData.ucElectricalValuesValues[13] = buffer[31]      ;
    MyConversionelectricalVariablesData.ucElectricalValuesValues[14] = buffer[32]      ;
    MyConversionelectricalVariablesData.ucElectricalValuesValues[15] = buffer[33]      ;
    (&xLaserLogEventDescriptor[index])->xElectricalVariablesStatus = MyConversionelectricalVariablesData.xElectricalVariablesStatus;


    typedef union
    {
        eOperationMode_t eOperationMode;
        uint8_t ucOperationModeValues;
    }MyConversioneOperationModeData_t;
    MyConversioneOperationModeData_t MyConversioneOperationModeData;
  //  MyConversioneOperationModeData.ucOperationModeValues = buffer[31]      ;
  //  MyConversioneOperationModeData.ucOperationModeValues[1] = buffer[32]      ;
    (&xLaserLogEventDescriptor[index])->eOperationMode = (eOperationMode_t) buffer[34] ; //(MyConversioneOperationModeData.eOperationMode[0]);
  //  (&xLaserLogEventDescriptor[index])->eOperationMode[1] =(eOperationMode_t) (MyConversioneOperationModeData.eOperationMode[1]);



    typedef union
    {
     eControlGeneralMode_t eControlGeneralMode;
     uint8_t ucControlModeValue;
    }eControlGeneralModeConversionData_t;
    eControlGeneralModeConversionData_t eControlGeneralModeConversionData;
    eControlGeneralModeConversionData.ucControlModeValue = (eControlGeneralMode_t) buffer[36]      ;
    (&xLaserLogEventDescriptor[index])->eControlGeneralMode = (eControlGeneralMode_t) buffer[36]      ; ; //eControlGeneralModeConversionData.eControlGeneralMode;


    typedef union
    {
      xAlarmRegister_t ullmpbAlarms;
      uint8_t ucAlarmsValue[8];
      uint64_t ullAlarmsValue;
    }MyConversionAlarmsData_t;
     MyConversionAlarmsData_t MyConversionAlarmsData;
     MyConversionAlarmsData.ucAlarmsValue[0] = buffer[37]      ;
     MyConversionAlarmsData.ucAlarmsValue[1] = buffer[38]      ;
     MyConversionAlarmsData.ucAlarmsValue[2] = buffer[39]      ;
     MyConversionAlarmsData.ucAlarmsValue[3] = buffer[40]      ;
     MyConversionAlarmsData.ucAlarmsValue[4] = buffer[41]      ;
     MyConversionAlarmsData.ucAlarmsValue[5] = buffer[42]      ;
     MyConversionAlarmsData.ucAlarmsValue[6] = buffer[43]      ;
     MyConversionAlarmsData.ucAlarmsValue[7] = buffer[44]      ;
     (&xLaserLogEventDescriptor[index])->xAlarmRegister.AlarmGlobalValue = MyConversionAlarmsData.ullAlarmsValue;


    typedef union
    {
      xStatusRegister_t xStatusRegister;
      uint8_t ucStatusValue[4];
      uint32_t ulStatusValue;
    }eStatusRegisterData_t;
    eStatusRegisterData_t eStatusRegister_Data;
    eStatusRegister_Data.ucStatusValue[0] = buffer[45]      ;
    eStatusRegister_Data.ucStatusValue[1] = buffer[46]      ;
    eStatusRegister_Data.ucStatusValue[2] = buffer[47]      ;
    eStatusRegister_Data.ucStatusValue[3] = buffer[48]      ;
    (&xLaserLogEventDescriptor[index])->xStatusRegister.ulStatusRegisterValue = eStatusRegister_Data.ulStatusValue;


    typedef union
    {
        float fValue;
        uint8_t ucValue[4];
    }MyConversionData_t;

    MyConversionData_t f940MultiModeLaserDiodeCurrent;
    f940MultiModeLaserDiodeCurrent.ucValue[0] = buffer[49]      ;
    f940MultiModeLaserDiodeCurrent.ucValue[1] = buffer[50]      ;
    f940MultiModeLaserDiodeCurrent.ucValue[2] = buffer[51]      ;
    f940MultiModeLaserDiodeCurrent.ucValue[3] = buffer[52]      ;
    (&xLaserLogEventDescriptor[index])->xCriticalAnalogCurrents.f940MultiModeLaserDiodeCurrent = f940MultiModeLaserDiodeCurrent.fValue;

    MyConversionData_t f980SingleModeLaserDiodeCurrent;
    f980SingleModeLaserDiodeCurrent.ucValue[0] = buffer[53]      ;
    f980SingleModeLaserDiodeCurrent.ucValue[1] = buffer[54]      ;
    f980SingleModeLaserDiodeCurrent.ucValue[2] = buffer[55]      ;
    f980SingleModeLaserDiodeCurrent.ucValue[3] = buffer[56]      ;
    (&xLaserLogEventDescriptor[index])->xCriticalAnalogCurrents.f980SingleModeLaserDiodeCurrent = f980SingleModeLaserDiodeCurrent.fValue;

    MyConversionData_t f980LaserDiodeTecCurrent;
    f980LaserDiodeTecCurrent.ucValue[0] = buffer[57]      ;
    f980LaserDiodeTecCurrent.ucValue[1] = buffer[58]      ;
    f980LaserDiodeTecCurrent.ucValue[2] = buffer[59]      ;
    f980LaserDiodeTecCurrent.ucValue[3] = buffer[60]      ;
    (&xLaserLogEventDescriptor[index])->xCriticalAnalogCurrents.f980LaserDiodeTecCurrent = f980LaserDiodeTecCurrent.fValue;


    MyConversionData_t f1545OutputPower;
    f1545OutputPower.ucValue[0] = buffer[61]      ;
    f1545OutputPower.ucValue[1] = buffer[62]      ;
    f1545OutputPower.ucValue[2] = buffer[63]      ;
    f1545OutputPower.ucValue[3] = buffer[64]      ;
    (&xLaserLogEventDescriptor[index])->xCriticalAnalogPowers.f1545OutputPower = f1545OutputPower.fValue;


    MyConversionData_t f980OutputPower;
    f980OutputPower.ucValue[0] = buffer[65]      ;
    f980OutputPower.ucValue[1] = buffer[66]      ;
    f980OutputPower.ucValue[2] = buffer[67]      ;
    f980OutputPower.ucValue[3] = buffer[68]      ;
    (&xLaserLogEventDescriptor[index])->xCriticalAnalogPowers.f980OutputPower = f980OutputPower.fValue;

    MyConversionData_t fQfbCaseTemperature;
    fQfbCaseTemperature.ucValue[0] = buffer[69]      ;
    fQfbCaseTemperature.ucValue[1] = buffer[70]      ;
    fQfbCaseTemperature.ucValue[2] = buffer[71]      ;
    fQfbCaseTemperature.ucValue[3] = buffer[72]      ;
    (&xLaserLogEventDescriptor[index])->xAnalogTemperatureInputs.fQfbCaseTemperature = fQfbCaseTemperature.fValue;

    MyConversionData_t f940MultiModeLaserDiodeTemperature;
    f940MultiModeLaserDiodeTemperature.ucValue[0] = buffer[73]      ;
    f940MultiModeLaserDiodeTemperature.ucValue[1] = buffer[74]      ;
    f940MultiModeLaserDiodeTemperature.ucValue[2] = buffer[75]      ;
    f940MultiModeLaserDiodeTemperature.ucValue[3] = buffer[76]      ;
    (&xLaserLogEventDescriptor[index])->xAnalogTemperatureInputs.f940MultiModeLaserDiodeTemperature = f940MultiModeLaserDiodeTemperature.fValue;


    MyConversionData_t f980SingleModeLaserDiodeTemperature;
    f980SingleModeLaserDiodeTemperature.ucValue[0] = buffer[77]      ;
    f980SingleModeLaserDiodeTemperature.ucValue[1] = buffer[78]      ;
    f980SingleModeLaserDiodeTemperature.ucValue[2] = buffer[79]      ;
    f980SingleModeLaserDiodeTemperature.ucValue[3] = buffer[80]      ;
    (&xLaserLogEventDescriptor[index])->xAnalogTemperatureInputs.f980SingleModeLaserDiodeTemperature = f980SingleModeLaserDiodeTemperature.fValue;


    typedef union
{
    mpbEventTypeBitsignment_t mpbEventTypeBitsignment;
    uint8_t ucEventType;

}eEventTypeData_t;


eEventTypeData_t eEventTypeData;

    eEventTypeData.ucEventType =  buffer[81]  ;
    (&xLaserLogEventDescriptor[index])->xEventType = eEventTypeData.mpbEventTypeBitsignment;

//    memcpy( &xLaserLogEventDescriptor[index], &buffer[0], sizeof(xLaserLogEventDescriptor_t));

/*    splitAlarms( (&xLaserLogEventDescriptor[index])->xAlarmRegister );
   splitStatus( (&xLaserLogEventDescriptor[index])->xStatusRegister);
    splitFta_1( (&xLaserLogEventDescriptor[index])->mpbFtaLowTempBitAssignment);
    splitFta_0( (&xLaserLogEventDescriptor[index])->mpbFtaLowPowerBitAssignment );
    ui->lcdNumber_4->display( (&xLaserLogEventDescriptor[index])->xAnalogTemperatureInputs.f940MultiModeLaserDiodeTemperature );
    ui->lcdNumber_2->display( (&xLaserLogEventDescriptor[index])->xAnalogTemperatureInputs.f980SingleModeLaserDiodeTemperature );
    ui->lcdNumber_3->display( (&xLaserLogEventDescriptor[index])->xAnalogTemperatureInputs.fQfbCaseRawTemperature );
    ui->lcdNumber->display( (&xLaserLogEventDescriptor[index])->ucSampleNumber );
    ui->lcdNumber_5->display( (&xLaserLogEventDescriptor[index])->usmpbLogEventTime );
    ui->lcdNumber_6->display( (&xLaserLogEventDescriptor[index])->xElectricalVariablesStatus.usActiveSetpoint );
    ui->lcdNumber_7->display( (&xLaserLogEventDescriptor[index])->xElectricalVariablesStatus.usCurrentSetpoint );
    ui->lcdNumber_8->display( (&xLaserLogEventDescriptor[index])->xElectricalVariablesStatus.usFrequency );*/

}

void MainWindow::showResponseDataBuffer(xLaserLogEventDescriptor_t *pxLaserLogEventDescriptor)
{
   splitAlarms( pxLaserLogEventDescriptor->xAlarmRegister );
   splitStatus( pxLaserLogEventDescriptor->xStatusRegister);
   splitFta_1( pxLaserLogEventDescriptor->mpbFtaLowTempBitAssignment);
   splitFta_0( pxLaserLogEventDescriptor->mpbFtaLowPowerBitAssignment );

   splitFmea(pxLaserLogEventDescriptor->mpbFmeaMode);

    ui->lcdNumber->display( pxLaserLogEventDescriptor->ucSampleNumber );

    if( pxLaserLogEventDescriptor->eMpbLogMainLoopState == 0 )
    {
        ui->labelState->setText("eMainLoopStateInit");
    }else if( pxLaserLogEventDescriptor->eMpbLogMainLoopState == 1 )
    {
        ui->labelState->setText( "eMainLoopStateOff" );

    }else if( pxLaserLogEventDescriptor->eMpbLogMainLoopState == 2 )
    {
        ui->labelState->setText( "eMainLoopStateReady" );

    }else if( pxLaserLogEventDescriptor->eMpbLogMainLoopState == 3 )
    {
        ui->labelState->setText( "eMainLoopStateOn" );

    }else if( pxLaserLogEventDescriptor->eMpbLogMainLoopState == 4 )
    {
        ui->labelState->setText( "eMainLoopStateTest" );

    }else if( pxLaserLogEventDescriptor->eMpbLogMainLoopState == 5 )
    {
        ui->labelState->setText( "eMainLoopStateFault" );

    }
    ui->lcdNumber_3->display( (int) pxLaserLogEventDescriptor->ulmpbLogEventTime  );

    uint8_t indexBeaconSelected = 0;

    if( pxLaserLogEventDescriptor->xBeaconId == 0 )
    {
        ui->labelBeaconId->setText( " 980 " );
        indexBeaconSelected = 0;

    }else if( pxLaserLogEventDescriptor->xBeaconId == 1 )
    {
        ui->labelBeaconId->setText( " 1545 " );
        indexBeaconSelected = 1;

    }
    else
    {
        ui->labelBeaconId->setText( " 980 " );
        indexBeaconSelected = 0;
    }


    if( pxLaserLogEventDescriptor->xLaserOperationMode[ indexBeaconSelected ].bLaserIsEnable ==  eTrue )
    {
        ui->labelLaserEnabled->setText( " YES " );
    }
    else
    {
        ui->labelLaserEnabled->setText( " NO " );
    }


    if( pxLaserLogEventDescriptor->xEventType.bIsAlarm == 1 )
    {
        ui->isAlarmEvent->setText( " YES " );
    }
    else
    {
        ui->isAlarmEvent->setText( " NO " );
    }

    if( pxLaserLogEventDescriptor->xEventType.bIsFault == 1 )
    {
        ui->isFaultEvent->setText( " YES " );
        ui->faultPosition->setText( QString::number( pxLaserLogEventDescriptor->ucSampleNumber )  );
    }
    else
    {
        ui->isFaultEvent->setText( " NO " );
    }

    if( pxLaserLogEventDescriptor->xEventType.bNormal == 1 )
    {
        ui->isNoEvent->setText( " YES " );
    }
    else
    {
        ui->isNoEvent->setText( " NO " );
    }

    if( pxLaserLogEventDescriptor->xLaserOperationMode[ indexBeaconSelected ].bLaserIsInTestMode ==  eTrue )
    {
        ui->labelLaserInTest->setText( " YES " );
    }
    else
    {
        ui->labelLaserInTest->setText( " NO " );
    }

    if( pxLaserLogEventDescriptor->xLaserOperationMode[ indexBeaconSelected ].bTecIsEnable ==  eTrue )
    {
        ui->labelTecEnabled->setText( " YES " );
    }
    else
    {
        ui->labelTecEnabled->setText( " NO " );
    }


    ui->lcdNumber_6->display( pxLaserLogEventDescriptor->xElectricalVariablesStatus.usActiveSetpoint  );
    ui->lcdNumber_7->display( pxLaserLogEventDescriptor->xElectricalVariablesStatus.usPowerSetpoint  );
    ui->lcdNumber_8->display( pxLaserLogEventDescriptor->xElectricalVariablesStatus.usCurrentSetpoint  );
    ui->lcdNumber_9->display( pxLaserLogEventDescriptor->xElectricalVariablesStatus.usCurrentThresholdSetpoint  );
    ui->lcdNumber_10->display( pxLaserLogEventDescriptor->xElectricalVariablesStatus.fTemperatureSetpoint  );
    ui->lcdNumber_11->display( pxLaserLogEventDescriptor->xElectricalVariablesStatus.usLedPower  );
    ui->lcdNumber_12->display( pxLaserLogEventDescriptor->xElectricalVariablesStatus.usFrequency  );

    if( pxLaserLogEventDescriptor->eOperationMode == eAlarm  )
    {
        ui->labelMode->setText( " ALARM " );
    }
    else if( pxLaserLogEventDescriptor->eOperationMode == eTest  )
    {
        ui->labelMode->setText( " TEST " );
    }
    else if( pxLaserLogEventDescriptor->eOperationMode == eIdle  )
    {
        ui->labelMode->setText( " IDLE " );
    }
    else if( pxLaserLogEventDescriptor->eOperationMode == eAcc  )
    {
        ui->labelMode->setText( " ACC " );
    }
    else if( pxLaserLogEventDescriptor->eOperationMode == eApc  )
    {
        ui->labelMode->setText( " APC " );
    }
    else
    {
        ui->labelMode->setText( " unknow " );
    }



    if( pxLaserLogEventDescriptor->eControlGeneralMode == 0  )
    {
        ui->labelControlMode->setText( " CONTINUOS " );
    }
    else if( pxLaserLogEventDescriptor->eControlGeneralMode == 1  )
    {
        ui->labelControlMode->setText( " MODULATION " );
    }
    else
    {
        ui->labelControlMode->setText( " unknow " );
    }


   /* ui->lcdNumber_13->display( pxLaserLogEventDescriptor->xCriticalAnalogCurrents.f980SingleModeLaserDiodeCurrent );
    ui->lcdNumber_14->display( pxLaserLogEventDescriptor->xCriticalAnalogCurrents.f940MultiModeLaserDiodeCurrent );
    ui->lcdNumber_15->display( pxLaserLogEventDescriptor->xCriticalAnalogCurrents.f980LaserDiodeTecCurrent );

    ui->lcdNumber_16->display( pxLaserLogEventDescriptor->xCriticalAnalogPowers.f1545OutputPower );
    ui->lcdNumber_17->display( pxLaserLogEventDescriptor->xCriticalAnalogPowers.f980OutputPower );


    ui->lcdNumber_18->display( pxLaserLogEventDescriptor->xAnalogTemperatureInputs.fQfbCaseTemperature );
    ui->lcdNumber_19->display( pxLaserLogEventDescriptor->xAnalogTemperatureInputs.f940MultiModeLaserDiodeTemperature );
    ui->lcdNumber_20->display( pxLaserLogEventDescriptor->xAnalogTemperatureInputs.f980SingleModeLaserDiodeTemperature  );*/


}

void MainWindow::processError()
{

    setUcBufferRunIndex(0);
}

void MainWindow::processTimeout()
{
    setUcBufferRunIndex(0);
}

void MainWindow::transactionLog(quint8 Index)
{
    quint8 datacounter = 0;
    datacounter++;

    ui->m_statusLabel->setText(tr("Status: Running, connected to port %1.")
                           .arg(ui->m_serialPortComboBox->currentText()));

    m_thread.transaction(ui->m_serialPortComboBox->currentText(),
                         100, //m_waitResponseSpinBox->value(),
                    //     m_requestLineEdit->text(),
                         0x81,
                         Index );
                         //2);
}

void MainWindow::setUcBufferIndex(uint8_t newUcBufferIndex)
{
    ucBufferIndex = newUcBufferIndex;
}

void MainWindow::Timer_triggered()
{
    static bool flash = false;
    static int currentValue =0;
    static int sample =0;

    if(flash==false)
    {
        flash = true;
        currentValue++;
        sample++;

        if(sample == 0)
        {
            ui->console2->setText(".\n");
        }


        if(sample > 40)
        {
            sample = 0;
            ui->console2->clear();
            ui->console2->setText(">Console ");
        }


         ui->console2->setText(ui->console2->text() + " . ");

      /*  ui->lcdNumber->display(currentValue);
        ui->lcdNumber_2->display(currentValue*0.3);
        ui->lcdNumber_3->display(currentValue*0.03);
        ui->lcdNumber_4->display(currentValue*1.03);

        ui->lcdNumber_11->display(currentValue);
        ui->lcdNumber_14->display(currentValue*0.2);
        ui->lcdNumber_17->display(currentValue*0.04);
        ui->lcdNumber_8->display(currentValue*1.05);


        ui->label_28->setText("> Displaying Sample Number: " + QString::number(sample) +  ".." +  "\n");
        ui->label_28->setText(ui->label_28->text() + "> Sequencing Log Event system \n " );


    }
    else
    {
        flash = false;
        sample++;

        if(sample == 0)
        {
            ui->console2->setText(".\n");
        }


        if(sample > 40)
        {
            sample = 0;
            ui->console2->clear();
            ui->console2->setText(">Console ");
        }


       ui->label_28->setText("> Displaying Sample Number: " + QString::number(sample) +  "...." +  "\n");
       ui->label_28->setText(ui->label_28->text() + "> Loading FTA and FMEA ---- \n " );


        ui->console2->setText(ui->console2->text() + "  .  ");

       ui->lcdNumber_7->display(currentValue);
        ui->lcdNumber_18->display(currentValue*0.3);
        ui->lcdNumber_19->display(currentValue*0.03);
        ui->lcdNumber_13->display(currentValue*1.03);

        ui->lcdNumber_8->display(currentValue);
        ui->lcdNumber_9->display(currentValue*0.2);
        ui->lcdNumber_10->display(currentValue*0.04);
        ui->lcdNumber_11->display(currentValue*1.05);*/

     }
}


void MainWindow::on_forward_clicked()
{
    uint8_t indexTemp =0;
    xLaserLogEventDescriptor_t *pxLaserLogEventDescriptor;

   indexTemp = getUcBufferIndex();

    if(indexTemp < 40)
    {
        indexTemp++;
    }
    else
    {
        indexTemp = 0;
    }

    ui->sampleNumber->setText( QString::number(indexTemp) );
    ui->progressBar->setValue( 100*indexTemp/40);

     setUcBufferIndex(indexTemp);
     setBuffer(indexTemp);

     pxLaserLogEventDescriptor = setBuffer( indexTemp );
     showResponseDataBuffer( pxLaserLogEventDescriptor );

}






void MainWindow::on_back_clicked()
{
    uint8_t indexTemp =0;
    xLaserLogEventDescriptor_t *pxLaserLogEventDescriptor;

    indexTemp = getUcBufferIndex();

    if(indexTemp > 0)
    {
     indexTemp--;
    }
    else
    {
        indexTemp = 40;
    }

    ui->sampleNumber->setText( QString::number(indexTemp) );
    ui->progressBar->setValue( 100*indexTemp/40);

     setUcBufferIndex(indexTemp);
     pxLaserLogEventDescriptor = setBuffer( indexTemp );

     showResponseDataBuffer( pxLaserLogEventDescriptor );

}


void MainWindow::on_adqData_clicked()
{

    setUcBufferRunIndex( 1);

}

uint8_t MainWindow::getUcBufferRunIndex() const
{
    return ucBufferRunIndex;
}

void MainWindow::setUcBufferRunIndex(uint8_t newUcBufferRunIndex)
{
    ucBufferRunIndex = newUcBufferRunIndex;
}


void MainWindow::on_Decode401_clicked()
{
    CAN_FRAME TestCanMessage;
    eBool_t bInputBoosterChannelSelection = eTrue;
    eBool_t bOutputLnaChannelSelection  = eTrue;
    c401Status1Definition_t c401Status1Definition;

    TestCanMessage.data.byte[0] = ui->textEdit->toPlainText().toInt();
    TestCanMessage.data.byte[1] = ui->textEdit_2->toPlainText().toInt();
    TestCanMessage.data.byte[2] = ui->textEdit_3->toPlainText().toInt();
    TestCanMessage.data.byte[3] = ui->textEdit_4->toPlainText().toInt();
    TestCanMessage.data.byte[4] = ui->textEdit_5->toPlainText().toInt();
    TestCanMessage.data.byte[5] = ui->textEdit_6->toPlainText().toInt();
    TestCanMessage.data.byte[6] = ui->textEdit_7->toPlainText().toInt();
    TestCanMessage.data.byte[7] = ui->textEdit_8->toPlainText().toInt();

    canDictionary.setCan401(&TestCanMessage);

  //  eMpbCan401Decode( &c401Status1Definition, bInputBoosterChannelSelection, bOutputLnaChannelSelection );
    //send signal
    //Q_EMIT
    //Q_EMIT this->trigger401( &c401Status1Definition, bInputBoosterChannelSelection, bOutputLnaChannelSelection );
    canDictionary.eMpbCan401Decode(&c401Status1Definition, bInputBoosterChannelSelection, bOutputLnaChannelSelection );

    ui->fInternalMountingSurfaceTemperature->display(c401Status1Definition.fInternalMountingSurfaceTemperature);
    ui->fLaserPump1CurrentOfBooster->display(c401Status1Definition.fLaserPump1CurrentOfBooster);
    ui->fLaserPump2CurrentOfBooster->display(c401Status1Definition.fLaserPump2CurrentOfBooster);
    ui->fLaserPump3CurrentOfBooster->display(c401Status1Definition.fLaserPump3CurrentOfBooster);
    ui->fLaserPump4CurrentOfLna->display(c401Status1Definition.fLaserPump4CurrentOfLna);
    ui->fBoosterOpticalInputPower->display(c401Status1Definition.fBoosterOpticalInputPower);
    ui->fLnaOpticalOutputPower->display(c401Status1Definition.fLnaOpticalOutputPower);
    ui->fBoosterOutputOpticalPowerIndBmApc->display(c401Status1Definition.fBoosterOutputOpticalPowerIndBmApc);

}

