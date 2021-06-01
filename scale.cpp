#include "scale.h"

void Scale::incCurValue() {
    if(curValue < maxValue) {
        curValue++;
        updateCurValueLabel();
    }
}
void Scale::decCurValue() {
    if(curValue > 0) {
        curValue--;
        updateCurValueLabel();
    }
}
void Scale::addToCurValue(int arg) {
    curValue = min(curValue + arg, maxValue);
    updateCurValueLabel()
}
void Scale::subFromCurValue(int arg) {
    curValue = max(curValue - arg, 0);
    updateCurValueLabel();
}

void Scale::updateCurValueLabel() {
    curValueLabel->setText(QString::number(curValue));
}
