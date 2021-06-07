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

    void on_queue1Button_clicked();

    void on_queue2Button_clicked();

    void on_queue3Button_clicked();

    void on_queue4Button_clicked();

    void on_queue5Button_clicked();

private:
    Ui::MainWindow *ui;

    inline static const int MILLISECONDS_PER_ACTION = 5000;
    inline static const int MILLISECONDS_PER_UPDATE = 50;
    inline static const int MILLISECONDS_PER_SUBTRACTION = 100;

    QTimer* actionTimer;
    QTimer* queueUpdateTimer;
    QTimer* randomSubTimer;
    QList<QPushButton*> actionButtons;
    QList<QPushButton*> queueButtons;

    std::map<QString,QProgressBar*> getLabelsList();

    //for initialization
    void startGameActions();
    void connectProgressBars();
    void chooseCharacterImage();
    void configureActionTimer();
    void configureUpdateTimer();
    void configureRandSubTimer();

    //for timers
    void updateQueue();
    void performQueueAction();
    void subtractRandomStat();
    void subtractStatByInd(int);

    void countHealth();
    bool isGameover();
    void gameoverActions();
    void disableButtons();
    void dropStats();

    QList<QPushButton*> getActionButtons();
    QList<QPushButton*> getQueueButtons();
    void addActionToQueue(Action);
    void removeActionFromQueue(int);
    QIcon getIconByAction(Action);

};
#endif // MAINWINDOW_H
