#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QTimer>
#include "settings.h"
#include "scale.h"
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_eatButton_clicked();

    void on_clearButton_clicked();

    void on_playButton_clicked();

    void on_sleepButton_clicked();

private:
    Ui::MainWindow *ui;

    inline static int MILLISECONDS_PER_ACTION = 5000;
    inline static int MILLISECONDS_PER_UPDATE = 50;
    inline static int MILLISECONDS_PER_SUBTRACTION = 2000;

    QTimer* actionTimer;
    QTimer* queueUpdateTimer;
    QTimer* randomSubTimer;
    QList<QPushButton*> queueButtons;

    std::map<QString,QProgressBar*> getLabelsList();

    //for initialization
    void connectProgressBars();
    void chooseCharacterImage();

    //for timers
    void updateQueue();
    void performQueueAction();
    void subtractRandomStat();
    void configureActionTimer();
    void configureUpdateTimer();
    void configureRandSubTimer();

    QList<QPushButton*> getQueueButtons();
    QIcon getIconByAction(Action);
};
#endif // MAINWINDOW_H
