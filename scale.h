#include <QProgressBar>

#ifndef SCALE_H
#define SCALE_H



class Scale
{
public:
    //default constructor
    Scale():
        curValue(DEFAULT_CUR_VALUE),
        maxValue(DEFAULT_MAX_VALUE),
        addValue(DEFAULT_ADD_VALUE),
        subValue(DEFAULT_SUB_VALUE),
        progressBar(nullptr){}

    //constructor with pair of "current value label" and "maximum value label"
    Scale(QProgressBar* pB){
        //100 - default values at the beginning of the game for current and maximum value
        Scale(DEFAULT_CUR_VALUE,DEFAULT_MAX_VALUE, pB);
    }

    Scale(int defaultAddValue, int defaultSubValue):
        curValue(DEFAULT_CUR_VALUE),
        maxValue(DEFAULT_MAX_VALUE),
        addValue(defaultAddValue),
        subValue(defaultSubValue),
        progressBar(nullptr) {}

    Scale(int maxValue, int curValue, int defaultAddValue, int defaultSubValue):
        curValue(curValue),
        maxValue(maxValue),
        addValue(defaultAddValue),
        subValue(defaultSubValue),
        progressBar(nullptr) {}

    Scale(int maxValue, int curValue, QProgressBar* pB):
        curValue(curValue),
        maxValue(maxValue),
        addValue(DEFAULT_ADD_VALUE),
        subValue(DEFAULT_SUB_VALUE),
        progressBar(pB){
        progressBar->setMaximum(maxValue);
        progressBar->setMinimum(0);
        progressBar->setValue(curValue);
    }
    int getMaxValue() {return maxValue;}
    int getCurValue() {return curValue;}
    //increment/decrements current value with check and update curValueLabel text
    void incCurValue();
    void decCurValue();

    void addDefaultValue();
    void subDefaultValue();
    //add/subtract current value with check and update curValueLabel text
    void addToCurValue(int arg);
    void subFromCurValue(int arg);
    // update current value label text
    void updateProgressBar();
    bool connectProgressBar(QProgressBar*);

    static const int DEFAULT_CUR_VALUE = 100;
    static const int DEFAULT_MAX_VALUE = 100;
    static const int DEFAULT_ADD_VALUE = 15;
    static const int DEFAULT_SUB_VALUE = 8;

private:
    int curValue;
    int maxValue;
    int addValue;
    int subValue;
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
