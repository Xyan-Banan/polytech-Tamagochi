#include <QLabel>

#ifndef SCALE_H
#define SCALE_H


class Scale
{
public:
    //default constructor
    Scale(): curValue(0), maxValue(0), curValueLabel(nullptr), maxValueLabel(nullptr){}
    //constructor with pair of "current value label" and "maximum value label"
    Scale(QPair<QLabel*, QLabel*> labelsPair){
        Scale(labelsPair.first,labelsPair.second);
    }

    Scale(QLabel* curValueLabel, QLabel* maxValueLabel){
        //100 - default values at the beginning of the game for current and maximum value
        Scale(100,100, curValueLabel, maxValueLabel);
    }
    Scale(int maxValue, int curValue, QLabel* curValueLabel, QLabel* maxValueLabel):
        curValue(curValue),
        maxValue(maxValue){
        //setting labels text to its values
        curValueLabel->setText(QString::number(curValue));
        maxValueLabel->setText(QString::number(maxValue));
    }
    int getMaxValue() {return maxValue;}
    int getCurValue() {return curValue;}
    //increment/decrements current value with check and update curValueLabel text
    void incCurValue();
    void decCurValue();
    //add/subtract current value with check and update curValueLabel text
    void addToCurValue(int arg);
    void subFromCurValue(int arg);
    // update current value label text
    void updateCurValueLabel();

private:
    int curValue;
    int maxValue;
    QLabel* curValueLabel;
    QLabel* maxValueLabel;

    int min(int a, int b){
        if(a < b) return a;
        return b;
    }
    int max(int a, int b){
        if(a > b) return a;
        return b;
    }
};

#endif // SCALE_H
