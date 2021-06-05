#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    queueButtons = getQueueButtons();
    new Settings();
    connectProgressBars();
    chooseCharacterImage();
    configureActionTimer();
    configureUpdateTimer();
    configureRandSubTimer();
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
    connect(queueUpdateTimer, &QTimer::timeout, this, &MainWindow::updateQueue);
    queueUpdateTimer->start(MILLISECONDS_PER_UPDATE);
}

void MainWindow::configureRandSubTimer()
{
    randomSubTimer = new QTimer(this);
    connect(randomSubTimer, &QTimer::timeout, this, &MainWindow::subtractRandomStat);
    randomSubTimer->start(MILLISECONDS_PER_SUBTRACTION);
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
        pM = QPixmap(":/images/Resources/images/Cat10.jpg");
        break;
    case Character::PANDA:
        pM = QPixmap(":/images/Resources/images/Panda10.jpg");
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
    case Action::EAT: icon = QIcon(":icons/icon_food"); break;
    case Action::CLEAR: icon = QIcon(":icons/icon_clear"); break;
    case Action::PLAY: icon = QIcon(":icons/icon_mood"); break;
    case Action::SLEEP: icon = QIcon(":icons/icon_sleep"); break;
    }
    return icon;
}

void MainWindow::updateQueue()
{
    int actionsCount = Settings::actionQueue.count();

    if(actionsCount == 0 && actionTimer->isActive()){
        actionTimer->stop();
        qDebug() << "timer stopped";
        qDebug() << "is active "<< actionTimer->isActive();
        qDebug() << "remaining Time "<< actionTimer->remainingTime();
    }
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
            qb->setVisible(true);
        }
        else{
            qb->setVisible(false);
        }
    }
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

void MainWindow::subtractRandomStat()
{
    qDebug()<< "performing random subtraction " << time(NULL);
    int actionInd = rand() % 4;
    qDebug()<< "choosed action " << actionInd;
    switch (actionInd) {
    case Action::EAT: Settings::food.subDefaultValue(); break;
    case Action::CLEAR: Settings::clear.subDefaultValue(); break;
    case Action::PLAY: Settings::mood.subDefaultValue(); break;
    case Action::SLEEP: Settings::sleep.subDefaultValue(); break;
    }
    updateQueue();
}

void MainWindow::on_eatButton_clicked()
{
    if(Settings::actionQueue.count() < queueButtons.count()){
        Settings::actionQueue.enqueue(Action::EAT);
        updateQueue();
    }
}

void MainWindow::on_clearButton_clicked()
{
    if(Settings::actionQueue.count() < queueButtons.count()){
        Settings::actionQueue.enqueue(Action::CLEAR);
        updateQueue();
    }
}

void MainWindow::on_playButton_clicked()
{
    if(Settings::actionQueue.count() < queueButtons.count()){
        Settings::actionQueue.enqueue(Action::PLAY);
        updateQueue();
    }
}

void MainWindow::on_sleepButton_clicked()
{
    if(Settings::actionQueue.count() < queueButtons.count()){
        Settings::actionQueue.enqueue(Action::SLEEP);
        updateQueue();
    }
}
