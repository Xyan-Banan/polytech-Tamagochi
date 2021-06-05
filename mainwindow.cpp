#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::sayHello(){
    qDebug() << "hello1" << timer->timerId();
}

void MainWindow::sayHello2(){
    qDebug() << "hello2" << timer->timerId();
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    new Settings(); //passing labels list in settings constructor and managing label text in scales
    connectProgressBars();
    queueButtons = getQueueButtons();

//    timer = new QTimer(this);
//    connect(timer, &QTimer::timeout,this,&MainWindow::sayHello);
//    timer->start(1000);
//    connect(timer, &QTimer::timeout,this,&MainWindow::sayHello2);
//    timer->start(400);
}

void MainWindow::connectProgressBars()
{
    Settings::food.connectProgressBar(ui->foodProgressBar);
    Settings::clear.connectProgressBar(ui->clearProgressBar);
    Settings::mood.connectProgressBar(ui->moodProgressBar);
    Settings::sleep.connectProgressBar(ui->sleepProgressBar);
    Settings::health.connectProgressBar(ui->healthProgressBar);
    Settings::updateProgressBars();
}

void MainWindow::updateQueue()
{
    // TODO
}

QList<QPushButton *> MainWindow::getQueueButtons()
{
    QList<QPushButton*> list = {
        ui->queue1Button,
        ui->queue2Button,
        ui->queue3Button,
        ui->queue4Button,
        ui->queue5Button,
    };
    return list;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_eatButton_clicked()
{
    if(Settings::actionQueue.count() < queueButtons.count()){
        Settings::actionQueue.enqueue(Action::EAT);
        updateQueue();
    }
}

void MainWindow::updateQueueButtons()
{

}

