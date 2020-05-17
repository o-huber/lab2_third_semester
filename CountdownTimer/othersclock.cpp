#include "othersclock.h"
#include "ui_othersclock.h"

Othersclock::Othersclock(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Othersclock)
{
    ui->setupUi(this);
    isOn=false;
    connect(ui->pb_SetAlam,SIGNAL(pressed()),SLOT(setAlarm()));

    refresher=new QTimer(this);
    connect(refresher,SIGNAL(timeout()),this,SLOT(refresh()));
    refresher->start(100);
}

Othersclock::~Othersclock()
{
    delete ui;
}
void Othersclock::setAlarm()
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
        ui->pb_SetAlam->setText("False");
        ui->te_AlarmTime->setEnabled(false);

        ui->pb_SetAlam->setChecked(true);
        isOn=true;
        nextAlarm=ui->te_AlarmTime->time();
    }
}

void Othersclock::refresh()
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
            bell->play();
            mb.setInformativeText("TIME TO WAKE UP");
            mb.setStandardButtons(QMessageBox::Ok|QMessageBox::Retry);
            mb.setDefaultButton(QMessageBox::Ok);
            int result=mb.exec();
            if(result== QMessageBox::Ok)
            {
                // Отключение будильника
                ui->pb_SetAlam->setText("Turn ON");
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
