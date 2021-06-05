#include "firstwindow.h"
#include "mainwindow.h"
#include "ui_firstwindow.h"
//FirstWindow::NO_BORDER_

void FirstWindow::setPersBtnIcon(QPushButton* btn, QString src)
{
    QIcon icon(src);
    btn->setIcon(icon);
    btn->setIconSize(btn->size());
}

FirstWindow::FirstWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FirstWindow)
{
    ui->setupUi(this);

    setPersBtnIcon(ui->Pers1BTN,":/images/Resources/images/Dog10.jpg");
    setPersBtnIcon(ui->Pers2BTN,":/images/Resources/images/Panda10.jpg");
    setPersBtnIcon(ui->Pers3BTN,":/images/Resources/images/Cat10.jpg");

    ui->TextLabel->setText("Привет Герой!");

    ui->TextLabel->setAlignment(Qt::AlignCenter);
}

FirstWindow::~FirstWindow()
{
    delete ui;
}

void FirstWindow::on_Pers1BTN_clicked()
{
    ui->TextLabel->setText("Пес классный!\nНо с ним надо много играть!");
    ui->Pers1BTN->setStyleSheet(BORDERED_STYLE);
    ui->Pers2BTN->setStyleSheet(NO_BORDER_STYLE);
    ui->Pers3BTN->setStyleSheet(NO_BORDER_STYLE);
    ui->SelectBTN->setEnabled(true);
    Settings::character = Character::DOG;

}

void FirstWindow::on_Pers2BTN_clicked()
{
    ui->TextLabel->setText("Панда обаятельная!\nНо она очень много спит!");
    ui->Pers1BTN->setStyleSheet(NO_BORDER_STYLE);
    ui->Pers2BTN->setStyleSheet(BORDERED_STYLE);
    ui->Pers3BTN->setStyleSheet(NO_BORDER_STYLE);
    ui->SelectBTN->setEnabled(true);
    Settings::character = Character::PANDA;
}

void FirstWindow::on_Pers3BTN_clicked()
{
    ui->TextLabel->setText("Кот крутой!\nНо он очень много моется!");
    ui->Pers1BTN->setStyleSheet(NO_BORDER_STYLE);
    ui->Pers2BTN->setStyleSheet(NO_BORDER_STYLE);
    ui->Pers3BTN->setStyleSheet(BORDERED_STYLE);
    ui->SelectBTN->setEnabled(true);
    Settings::character = Character::CAT;



}

void FirstWindow::on_SelectBTN_clicked()
{
    MainWindow *sWindow = new MainWindow();
    sWindow->show();
    this->close();
}

