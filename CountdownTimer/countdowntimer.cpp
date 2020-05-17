#include "countdowntimer.h"
#include "ui_countdowntimer.h"


CountdownTimer::CountdownTimer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CountdownTimer)
{
    ui->setupUi(this);
    connect(timer,SIGNAL(timeout()), this, SLOT(updateTime()));
    timer->setSingleShot(true);
    isOn=false;
    connect(ui->pb_SetAlam,SIGNAL(pressed()),SLOT(setAlarm()));
    refresher=new QTimer(this);
    connect(refresher,SIGNAL(timeout()),this,SLOT(refresh()));
    refresher->start(100);
}

CountdownTimer::~CountdownTimer()
{
    delete ui;
}

void CountdownTimer::on_startButton_clicked()
{
    if(buttonStart == true)
    {
        buttonStart = false;
        ui->startButton->setText("Stop");
        ui->timeEdit->setEnabled(false);
        *displayTime = ui->timeEdit->time();
        ui->timerLabel->setText(displayTime->toString("hh:mm:ss"));
        timer->start(1000);
    }
    else
    {
        buttonStart = true;
        ui->startButton->setText("Start");
        ui->timeEdit->setEnabled(true);
        ui->timeEdit->setTime(*displayTime);
        timer->stop();
    }
}

void CountdownTimer::updateTime()
{
    QTime newTime = displayTime->addSecs(-1);
    displayTime->setHMS(newTime.hour(),newTime.minute(),newTime.second());
    ui->timerLabel->setText(displayTime->toString("hh:mm:ss"));
    if(displayTime->hour() != 0 ||
            displayTime->minute() != 0 ||
            displayTime->second() != 0)
    {
        timer->start(1000);
    }
    else
    {
        bell->play();
        buttonStart = true;
        ui->startButton->setText("Start");
        timer->stop();
    }

}

void CountdownTimer::on_pushButton_clicked()
{
window = new Otherwindows(this);
window->show();

}
void CountdownTimer::setAlarm()
{
    if(isOn)
    {
        ui->pb_SetAlam->setText("Start");
        ui->pb_SetAlam->setChecked(false);
        ui->te_AlarmTime->setEnabled(true);

        isOn=false;
    }
    else
    {
        ui->pb_SetAlam->setText("Stop");
        ui->te_AlarmTime->setEnabled(false);

        ui->pb_SetAlam->setChecked(true);
        isOn=true;
        nextAlarm=ui->te_AlarmTime->time();
    }
}

void CountdownTimer::refresh()
{
    QDateTime dt=QDateTime::currentDateTime();
    ui->lb_Time->setText(dt.toString("dd  MMMM  yyyy\nHH:mm:ss"));
    if(isOn)
    {
        // Если будильник включен
        if((nextAlarm.hour()==dt.time().hour())&&(nextAlarm.minute()==dt.time().minute()))
        {
            // Срабатывание
            QMessageBox mb;
            mb.setText("Alarm");
            mb.setInformativeText("TIME TO WAKE UP");
            bell->play();
            mb.setStandardButtons(QMessageBox::Ok|QMessageBox::Retry);
            mb.setDefaultButton(QMessageBox::Ok);
            int result=mb.exec();
            if(result== QMessageBox::Ok)
            {
                // Отключение будильника
                ui->pb_SetAlam->setText("Start");
                ui->pb_SetAlam->setChecked(false);
                isOn=false;
                ui->lb_Reuse->clear();
            }
            if(result== QMessageBox::Retry)
            {
                // повтор будильника через 5 минут
                nextAlarm=QTime::currentTime();
                nextAlarm=nextAlarm.addSecs(5*60);
                ui->lb_Reuse->setText("-= Reuse Alarm: "+nextAlarm.toString("HH:mm =-"));
            }
        }
    }

}



void CountdownTimer::on_pushButton_3_clicked()
{
    window2 = new Othersclock(this);
    window2->show();

}
