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
    void updateQueueButtons();
    void sayHello();
    void sayHello2();

private:
    Ui::MainWindow *ui;

    QTimer* timer;
    std::map<QString,QProgressBar*> getLabelsList();
    void initScale(Scale, QLabel*, QLabel*);
    void initScales();
    void connectProgressBars();
    void updateQueue();
    QList<QPushButton*> getQueueButtons();
    QList<QPushButton*> queueButtons;
};
#endif // MAINWINDOW_H
