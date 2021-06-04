#include "scale.h"

#ifndef SETTINGS_H
#define SETTINGS_H

enum Character {
    NONE,
    DOG,
    CAT,
    PANDA,
};

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
    inline static Character character;
    static void updateProgressBars();
private:
    void setDefaultSettings();
    void setDogSettings();
    void setCatSettings();
    void setPandaSettings();
};

#endif // SETTINGS_H
