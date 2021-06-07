#include "scale.h"

void Scale::dropCurValue() {
    curValue = 0;
    updateProgressBar();
}

void Scale::incCurValue() {
    if(curValue < maxValue) {
        curValue++;
        updateProgressBar();
    }
}
void Scale::decCurValue() {
    if(curValue > 0) {
        curValue--;
        updateProgressBar();
    }
}

void Scale::addDefaultValue()
{
    addToCurValue(addValue);
}

void Scale::subDefaultValue(){
    subFromCurValue(subValue);
}

void Scale::addToCurValue(int arg) {
    curValue = min(curValue + arg, maxValue);
    updateProgressBar();
}
void Scale::subFromCurValue(int arg) {
    curValue = max(curValue - arg, 0);
    updateProgressBar();
}

void Scale::updateProgressBar() {
    progressBar->setValue(curValue);
}

bool Scale::connectProgressBar(QProgressBar * pB)
{
    if(pB != nullptr){
        progressBar = pB;
        return true;
    }

    return false;
}
