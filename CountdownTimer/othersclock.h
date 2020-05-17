#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTime>
#include <QTimer>
#include <QSound>
#include <QString>
#include <QDialog>
#include <QMediaPlayer>
#include <QDir>
#include <QUrl>
#include <QMessageBox>
namespace Ui {
class Othersclock;
}

class Othersclock : public QDialog
{
    Q_OBJECT

public:
    explicit Othersclock(QWidget *parent = nullptr);
    ~Othersclock();
    QSound *bell =new QSound (":/new/prefix1/timersound.wav");

private:
    Ui::Othersclock *ui;

    QTimer *refresher;              // Таймер обновления времени

    bool isOn;                      // Флаг отслеживания времени

    QTime nextAlarm;                // Время последнего сигнала

private slots:
    void refresh();                 // Обновление времени

    void setAlarm();                // Включение/выключение будильника
};

#endif
