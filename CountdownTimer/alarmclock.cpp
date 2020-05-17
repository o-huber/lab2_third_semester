#include "alarmclock.h"
#include "ui_countdowntimer.h"


alarmclock::alarmclock(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::alarmclock)
{
    ui->setupUi(this);
    isOn=false;
    connect(ui->pb_SetAlam,SIGNAL(pressed()),SLOT(setAlarm()));

    refresher=new QTimer(this);
    connect(refresher,SIGNAL(timeout()),this,SLOT(refresh()));
    refresher->start(100);
}
