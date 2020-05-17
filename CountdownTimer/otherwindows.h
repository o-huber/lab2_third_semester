#ifndef OTHERWINDOWS_H
#define OTHERWINDOWS_H

#include <QMainWindow>
#include <QTime>
#include <QTimer>
#include <QSound>
#include <QString>
#include <QDialog>
#include <QMediaPlayer>
#include <QDir>
#include <QUrl>
namespace Ui {
class Otherwindows;
}

class Otherwindows : public QDialog
{
    Q_OBJECT

public:
    QTime *displayTime = new QTime;
    QTimer *timer = new QTimer;

    bool buttonStart = true;
    QSound *bell =new QSound (":/new/prefix1/timersound.wav");

public:
    explicit Otherwindows(QWidget *parent = nullptr);
    ~Otherwindows();
protected slots:
    void updateTime();

private slots:
    void on_startButton_clicked();


private:
    Ui::Otherwindows *ui;
    Otherwindows *window;
};



#endif // OTHERWINDOWS_H
