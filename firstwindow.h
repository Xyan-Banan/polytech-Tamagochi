#include <QDialog>
#include "settings.h"
#include "mainwindow.h"

#ifndef FIRSTWINDOW_H
#define FIRSTWINDOW_H


namespace Ui {
class FirstWindow;
}

class FirstWindow : public QDialog
{
    Q_OBJECT

public:
    explicit FirstWindow(QWidget *parent = nullptr);
    ~FirstWindow();

private slots:
    void on_Pers1BTN_clicked();

    void on_Pers2BTN_clicked();

    void on_Pers3BTN_clicked();

    void on_SelectBTN_2_clicked();

private:
    Ui::FirstWindow *ui;
    inline static const QString NO_BORDER_STYLE = "border: 1px solid black; padding: 5px; border-radius: 10%; background-color: white;";
    inline static const QString BORDERED_STYLE ="border: 5px solid #66CDAA;border-radius: 10%; background-color: white;";
};

#endif // FIRSTWINDOW_H
