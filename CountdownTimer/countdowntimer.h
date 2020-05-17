#ifndef COUNTDOWNTIMER_H
#define COUNTDOWNTIMER_H

#include <QMainWindow>
#include <QTime>
#include <QTimer>
#include <QSound>
#include <QString>
#include "otherwindows.h"
#include "othersclock.h"
#include <QMediaPlayer>
#include <QDir>
#include <QUrl>
#include <QMessageBox>

namespace Ui {
class CountdownTimer;
}

class CountdownTimer : public QMainWindow
{
    Q_OBJECT

public:
    QTime *displayTime = new QTime;
    QTimer *timer = new QTimer;
    QTimer *refresher;              // Таймер обновления времени

    bool isOn;                      // Флаг отслеживания времени

    QTime nextAlarm;                // Время последнего сигнала

    bool buttonStart = true;

public:
    explicit CountdownTimer(QWidget *parent = 0);
    ~CountdownTimer();
  QSound *bell =new QSound (":/new/prefix1/timersound.wav");

protected slots:
    void updateTime();

private slots:
    void on_startButton_clicked();

    void on_pushButton_clicked();

    void refresh();                 // Обновление времени

    void setAlarm();                // Включение/выключение будильника



    void on_pushButton_3_clicked();

private:
    Ui::CountdownTimer *ui;
    Otherwindows *window;
    Othersclock* window2;



};

#endif // COUNTDOWNTIMER_H
