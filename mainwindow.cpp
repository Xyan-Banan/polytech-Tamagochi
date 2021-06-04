#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    new Settings(); //passing labels list in settings constructor and managing label text in scales
    connectProgressBars();
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

MainWindow::~MainWindow()
{
    delete ui;
}

