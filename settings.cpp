#include "settings.h"

Settings::Settings(){
        food = Scale();
        sleep = Scale();
        mood = Scale();
        clear = Scale();
        health = Scale();

}

Settings::Settings(std::map<QString,QProgressBar*> progressBars)
{
//    food = Scale(progressBars.at("food"));
//    sleep = Scale(progressBars.at("sleep"));
//    mood = Scale(progressBars.at("mood"));
//    clear = Scale(progressBars.at("clear"));
    health = Scale(progressBars.at("health"));
}

void Settings::updateProgressBars()
{
    food.updateProgressBar();
    sleep.updateProgressBar();
    mood.updateProgressBar();
    clear.updateProgressBar();
    health.updateProgressBar();
}

