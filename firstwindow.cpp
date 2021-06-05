#include "firstwindow.h"
#include "mainwindow.h"
#include "ui_firstwindow.h"
//FirstWindow::NO_BORDER_

FirstWindow::FirstWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FirstWindow)
{
    ui->setupUi(this);
    QPixmap pixmapBTN1(":/images/Resources/images/Dog10.jpg");
    QPixmap pixmapBTN2(":/images/Resources/images/Panda10.jpg");
    QPixmap pixmapBTN3(":/images/Resources/images/Cat10.jpg");

    QIcon ButtonIcon1(pixmapBTN1);
    QIcon ButtonIcon2(pixmapBTN2);
    QIcon ButtonIcon3(pixmapBTN3);

    ui->Pers1BTN->setIcon(QIcon(ButtonIcon1));
    ui->Pers1BTN->setIconSize(QSize(100,100));

    ui->Pers2BTN->setIcon(QIcon(ButtonIcon2));
    ui->Pers2BTN->setIconSize(QSize(100,100));

    ui->Pers3BTN->setIcon(QIcon(ButtonIcon3));
    ui->Pers3BTN->setIconSize(QSize(100,100));

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
    Settings::character = Character::DOG;

}

void FirstWindow::on_Pers2BTN_clicked()
{
    ui->TextLabel->setText("Панда обаятельная!\nНо она очень много спит!");
    ui->Pers1BTN->setStyleSheet(NO_BORDER_STYLE);
    ui->Pers2BTN->setStyleSheet(BORDERED_STYLE);
    ui->Pers3BTN->setStyleSheet(NO_BORDER_STYLE);
    Settings::character = Character::CAT;


}

void FirstWindow::on_Pers3BTN_clicked()
{
    ui->TextLabel->setText("Кот крутой!\nНо он очень много моется!");
    ui->Pers1BTN->setStyleSheet(NO_BORDER_STYLE);
    ui->Pers2BTN->setStyleSheet(NO_BORDER_STYLE);
    ui->Pers3BTN->setStyleSheet(BORDERED_STYLE);
    Settings::character = Character::PANDA;



}

void FirstWindow::on_SelectBTN_2_clicked()
{

    MainWindow *sWindow = new MainWindow();
    sWindow->show();
    this->close();

}
