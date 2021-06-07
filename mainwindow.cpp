#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    startGameActions();
}

void MainWindow::startGameActions()
{
    queueButtons = getQueueButtons();
    new Settings();
    connectProgressBars();
    chooseCharacterImage();
    configureActionTimer();
    configureUpdateTimer();
    configureRandSubTimer();
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

void MainWindow::configureActionTimer()
{
    actionTimer = new QTimer(this);
    connect(actionTimer, &QTimer::timeout,this,&MainWindow::performQueueAction);
    actionTimer->start(MILLISECONDS_PER_ACTION);
}

void MainWindow::configureUpdateTimer()
{
    queueUpdateTimer = new QTimer(this);
    connect(queueUpdateTimer, &QTimer::timeout, this, &MainWindow::updateQueue);
    queueUpdateTimer->start(MILLISECONDS_PER_UPDATE);
}

void MainWindow::configureRandSubTimer()
{
    randomSubTimer = new QTimer(this);
    connect(randomSubTimer, &QTimer::timeout, this, &MainWindow::subtractRandomStat);
    randomSubTimer->start(MILLISECONDS_PER_SUBTRACTION);
}

void MainWindow::countHealth()
{
    int countEmpty = Settings::food.isCurValEmpty()
            + Settings::clear.isCurValEmpty()
            + Settings::mood.isCurValEmpty()
            + Settings::sleep.isCurValEmpty();
//    qDebug() << "count empty " << countEmpty <<" subtracting " << Settings::health.getSubValue()*countEmpty;
    if(countEmpty > 0){
        Settings::health.subFromCurValue(Settings::health.getSubValue() * countEmpty);
    }
}

bool MainWindow::isGameover()
{
    return Settings::health.isCurValEmpty();
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

void MainWindow::chooseCharacterImage()
{
    QPixmap pM;
    switch (Settings::character) {

    case Character::CAT:
        pM = QPixmap(":/images/character_cat");
        break;
    case Character::PANDA:
        pM = QPixmap(":/images/character_panda");
        break;
    case Character::DOG:
    case Character::NONE:
    default:
        pM = QPixmap(":images/character_dog");
        break;
    }
    ui->characterImage->setPixmap(pM);
}

QIcon MainWindow::getIconByAction(Action action)
{
    QIcon icon;
    switch (action) {
    case Action::EAT: icon = QIcon(":icons/btn_icon_food"); break;
    case Action::CLEAR: icon = QIcon(":icons/btn_icon_clean"); break;
    case Action::PLAY: icon = QIcon(":icons/btn_icon_play"); break;
    case Action::SLEEP: icon = QIcon(":icons/btn_icon_sleep"); break;
    }
    return icon;
}

void MainWindow::updateQueue()
{
    int actionsCount = Settings::actionQueue.count();

    //no actions in queue and timer is active -> need to stop timer
    if(actionsCount == 0 && actionTimer->isActive()){
        actionTimer->stop();
        qDebug() << "timer stopped";
        qDebug() << "is active "<< actionTimer->isActive();
        qDebug() << "remaining Time "<< actionTimer->remainingTime();
    }

    //there IS actions in queue and timer is NOT active -> need to restart timer
    if(actionsCount > 0 && !actionTimer->isActive()) {
        actionTimer->start(MILLISECONDS_PER_ACTION);
        qDebug() << "timer started";
        qDebug() << "is active "<< actionTimer->isActive();
        qDebug() << "remaining Time "<< actionTimer->remainingTime();
    }

    for(int i = 0; i < queueButtons.count(); i++){
        QPushButton* qb = queueButtons[i];
        if(i < actionsCount){
            Action action = Settings::actionQueue[i];
            qb->setIcon(getIconByAction(action));
            qb->setIconSize(QSize(qb->size()));
            qb->setEnabled(true);
        }
        else{
            qb->setEnabled(false);
            qb->setIcon(QIcon());
        }
    }
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::performQueueAction()
{
    if(!Settings::actionQueue.isEmpty()){
        Action action = Settings::actionQueue.dequeue();
        switch (action) {
        case Action::EAT: Settings::food.addDefaultValue(); break;
        case Action::CLEAR: Settings::clear.addDefaultValue(); break;
        case Action::PLAY: Settings::mood.addDefaultValue(); break;
        case Action::SLEEP: Settings::sleep.addDefaultValue(); break;
        }

        updateQueue();
    }
}

void MainWindow::disableButtons()
{
    ui->eatButton->setEnabled(false);
    ui->sleepButton->setEnabled(false);
    ui->clearButton->setEnabled(false);
    ui->playButton->setEnabled(false);
}

void MainWindow::gameoverActions()
{
    actionTimer->stop();
    queueUpdateTimer->stop();
    randomSubTimer->stop();
    disableButtons();
    ui->characterImage->setPixmap(QPixmap(":/images/grave"));
    ui->statusbar->showMessage("you, bastard, you killed him!");
    //show message
}

void MainWindow::subtractStatByInd(int actionInd)
{
//    qDebug()<< "choosed action " << actionInd;
    switch (actionInd) {
    case Action::EAT: Settings::food.subDefaultValue(); break;
    case Action::CLEAR: Settings::clear.subDefaultValue(); break;
    case Action::PLAY: Settings::mood.subDefaultValue(); break;
    case Action::SLEEP: Settings::sleep.subDefaultValue(); break;
    default: break;
    }
}

void MainWindow::subtractRandomStat()
{
//    qDebug()<< "performing random subtraction " << time(NULL) % 60;
    subtractStatByInd(rand() % 4);
    subtractStatByInd(rand() % 4);

    countHealth();
    if(isGameover()){
        gameoverActions();
    }
}

void MainWindow::addActionToQueue(Action action)
{
    if(Settings::actionQueue.count() < queueButtons.count()){
        Settings::actionQueue.enqueue(action);
        updateQueue();
    }
}

void MainWindow::on_eatButton_clicked()
{
    addActionToQueue(Action::EAT);
}

void MainWindow::on_clearButton_clicked()
{
    addActionToQueue(Action::CLEAR);
}

void MainWindow::on_playButton_clicked()
{
    addActionToQueue(Action::PLAY);
}

void MainWindow::on_sleepButton_clicked()
{
    addActionToQueue(Action::SLEEP);
}


void MainWindow::removeActionFromQueue(int index)
{
    Settings::actionQueue.removeAt(index);
    updateQueue();
}

void MainWindow::on_queue1Button_clicked()
{
    removeActionFromQueue(0);
}


void MainWindow::on_queue2Button_clicked()
{
    removeActionFromQueue(1);
}


void MainWindow::on_queue3Button_clicked()
{
    removeActionFromQueue(2);
}


void MainWindow::on_queue4Button_clicked()
{
    removeActionFromQueue(3);
}


void MainWindow::on_queue5Button_clicked()
{
    removeActionFromQueue(4);
}

