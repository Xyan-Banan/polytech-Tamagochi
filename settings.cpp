#include "settings.h"

Settings::Settings(std::map<QString,QPair<QLabel*,QLabel*>> labelsList)
{
    food = Scale(labelsList.at("food"));
    sleep = Scale(labelsList.at("sleep"));
    mood = Scale(labelsList.at("mood"));
    clear = Scale(labelsList.at("clear"));
    health = Scale(labelsList.at("health"));
}

