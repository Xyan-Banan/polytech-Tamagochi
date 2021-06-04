#include <QProgressBar>

#ifndef SCALE_H
#define SCALE_H


class Scale
{
public:
    //default constructor
    Scale(): curValue(100), maxValue(100), progressBar(nullptr){}
    //constructor with pair of "current value label" and "maximum value label"
    Scale(QProgressBar* pB){
        //100 - default values at the beginning of the game for current and maximum value
        Scale(100,100, pB);
    }
    Scale(int maxValue, int curValue, QProgressBar* pB):
        curValue(curValue),
        maxValue(maxValue){
        //setting labels text to its values
        pB->setMaximum(maxValue);
        pB->setMinimum(0);
        pB->setValue(curValue);
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
    void updateProgressBar();
    bool connectProgressBar(QProgressBar*);

private:
    int curValue;
    int maxValue;
    QProgressBar* progressBar;

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
