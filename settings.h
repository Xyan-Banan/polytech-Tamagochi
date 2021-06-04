#include "scale.h"

#ifndef SETTINGS_H
#define SETTINGS_H


class Settings
{
public:
    Settings();
    Settings(std::map<QString,QProgressBar*>);
    //creature parameters
    inline static Scale food;
    inline static Scale sleep;
    inline static Scale mood;
    inline static Scale clear;
    inline static Scale health;
    static void updateProgressBars();
private:
};

#endif // SETTINGS_H
