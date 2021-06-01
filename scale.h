#ifndef SCALE_H
#define SCALE_H


class Scale
{
public:
    Scale(int maxValue, int curValue):
        _maxValue(maxValue),
        _curValue(curValue){}
    int getMaxValue() {return _maxValue;}
    int getCurValue() {return _curValue;}
    void incCurValue() { if(_curValue < _maxValue) _curValue++;}
    void decCurValue() { if(_curValue > 0) _curValue--; }
    void addToCurValue(int arg) { _curValue = min(_curValue + arg, _maxValue); }
    void subFromCurValue(int arg) { _curValue = max(_curValue - arg, 0); }

private:
    int _maxValue;
    int _curValue;

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
