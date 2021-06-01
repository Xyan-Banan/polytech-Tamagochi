#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    new Settings(getLabelsList()); //passing labels list in settings constructor and managing label text in scales
//    initScales(); //managing labels text initialization and control in settings
}

//creating map of "label_group_name" and labels of scales
std::map<QString,QPair<QLabel*,QLabel*>> MainWindow::getLabelsList(){
    std::map<QString,QPair<QLabel*,QLabel*>> labelsList;
    labelsList.insert({"food",{ui->curFoodLabel,ui->maxFoodLabel}});
    labelsList.insert({"sleep",{ui->curSleepLabel,ui->maxSleepLabel}});
    labelsList.insert({"mood",{ui->curMoodLabel,ui->maxMoodLabel}});
    labelsList.insert({"clear",{ui->curClearLabel,ui->maxClearLabel}});
    labelsList.insert({"health",{ui->curHealthLabel,ui->maxHealthLabel}});
    return labelsList;
}

void MainWindow::initScale(Scale scale, QLabel* curValueLabel, QLabel* maxValueLable){
    curValueLabel->setText(QString::number(scale.getCurValue()));
    maxValueLable->setText(QString::number(scale.getMaxValue()));
}

void MainWindow::initScales(){
    initScale(Settings::food,ui->curFoodLabel,ui->maxFoodLabel);
    initScale(Settings::sleep,ui->curSleepLabel,ui->maxSleepLabel);
    initScale(Settings::mood,ui->curMoodLabel,ui->maxMoodLabel);
    initScale(Settings::clear,ui->curClearLabel,ui->maxClearLabel);
    initScale(Settings::health,ui->curHealthLabel,ui->maxHealthLabel);
}

MainWindow::~MainWindow()
{
    delete ui;
}

