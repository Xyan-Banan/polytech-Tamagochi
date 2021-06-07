#include "settings.h"

Settings::Settings(){
    switch (character) {
    case Character::DOG: setDogSettings(); break;
    case Character::CAT: setCatSettings(); break;
    case Character::PANDA: setPandaSettings(); break;
    case Character::NONE:
    default: setDefaultSettings(); break;
    }
}

void Settings::updateProgressBars()
{
    food.updateProgressBar();
    sleep.updateProgressBar();
    mood.updateProgressBar();
    clear.updateProgressBar();
    health.updateProgressBar();
}

void Settings::setDefaultSettings(){
    food = Scale(Scale::DEFAULT_ADD_VALUE, Scale::DEFAULT_SUB_VALUE);
    sleep = Scale(Scale::DEFAULT_ADD_VALUE, Scale::DEFAULT_SUB_VALUE);
    mood = Scale(Scale::DEFAULT_ADD_VALUE, Scale::DEFAULT_SUB_VALUE);
    clear = Scale(Scale::DEFAULT_ADD_VALUE, Scale::DEFAULT_SUB_VALUE);
    health = Scale(Scale::DEFAULT_ADD_VALUE, Scale::DEFAULT_SUB_VALUE);
}

void Settings::setDogSettings()
{
    // TODO: change to actual DOG values
    food = Scale(Scale::DEFAULT_ADD_VALUE, Scale::DEFAULT_SUB_VALUE);
    sleep = Scale(Scale::DEFAULT_ADD_VALUE, Scale::DEFAULT_SUB_VALUE);
    mood = Scale(25, 2);
    clear = Scale(Scale::DEFAULT_ADD_VALUE, Scale::DEFAULT_SUB_VALUE);
    health = Scale(Scale::DEFAULT_ADD_VALUE, Scale::DEFAULT_SUB_VALUE);
}

void Settings::setCatSettings()
{
    // TODO: change to actual CAT values
    food = Scale(Scale::DEFAULT_ADD_VALUE, Scale::DEFAULT_SUB_VALUE);
    sleep = Scale(Scale::DEFAULT_ADD_VALUE, Scale::DEFAULT_SUB_VALUE);
    mood = Scale(Scale::DEFAULT_ADD_VALUE, Scale::DEFAULT_SUB_VALUE);
    clear = Scale(25, 2);
    health = Scale(Scale::DEFAULT_ADD_VALUE, Scale::DEFAULT_SUB_VALUE);
}

void Settings::setPandaSettings()
{
    // TODO: change to actual PANDA values
    food = Scale(Scale::DEFAULT_ADD_VALUE, Scale::DEFAULT_SUB_VALUE);
    sleep = Scale(25,2);
    mood = Scale(Scale::DEFAULT_ADD_VALUE, Scale::DEFAULT_SUB_VALUE);
    clear = Scale(Scale::DEFAULT_ADD_VALUE, Scale::DEFAULT_SUB_VALUE);
    health = Scale(Scale::DEFAULT_ADD_VALUE, Scale::DEFAULT_SUB_VALUE);
}

