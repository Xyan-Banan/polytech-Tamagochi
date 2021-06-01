#include "scale.h"

#ifndef SETTINGS_H
#define SETTINGS_H


class Settings
{
public:
    Settings(std::map<QString,QPair<QLabel*,QLabel*>>);
    //creature parameters
    inline static Scale food;
    inline static Scale sleep;
    inline static Scale mood;
    inline static Scale clear;
    inline static Scale health;
private:
};

#endif // SETTINGS_H
