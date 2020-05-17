#ifndef ALARMCLOCK_H
#define ALARMCLOCK_H

#include <QMainWindow>
#include <QDateTime>
#include <QTime>
#include <QTimer>
#include <QMessageBox>
#include <QDebug>
#include <QSound>
#include <QString>
#include <QMediaPlayer>
#include <QDir>
#include <QUrl>


namespace Ui {
class alarmclock;
}

class alarmclock : public QMainWindow
{
    Q_OBJECT;
public:
    alarmclock();
    explicit alarmclock(QWidget *parent = nullptr);
    ~alarmclock();


private:
    Ui::alarmclock *ui;

    QTimer *refresher;              // Таймер обновления времени

    bool isOn;                      // Флаг отслеживания времени

    QTime nextAlarm;                // Время последнего сигнала
private slots:
    void refresh();                 // Обновление времени

    void setAlarm();                // Включение/выключение будильника

};

#endif // ALARMCLOCK_H
