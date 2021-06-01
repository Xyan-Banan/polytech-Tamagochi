#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include "settings.h"
#include "scale.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    std::map<QString,QPair<QLabel*,QLabel*>> getLabelsList();
    void initScale(Scale, QLabel*, QLabel*);
    void initScales();
};
#endif // MAINWINDOW_H
