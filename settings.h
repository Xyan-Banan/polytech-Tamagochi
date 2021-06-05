#include "scale.h"
#include <QQueue>

#ifndef SETTINGS_H
#define SETTINGS_H

enum Character {
    NONE,
    DOG,
    CAT,
    PANDA,
};

enum Action {
    EAT,
    SLEEP,
    CLEAR,
    PLAY
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
    inline static QQueue<Action> actionQueue;
    static void updateProgressBars();
private:
    void setDefaultSettings();
    void setDogSettings();
    void setCatSettings();
    void setPandaSettings();
};

#endif // SETTINGS_H
