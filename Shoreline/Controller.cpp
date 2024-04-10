#include "Controller.h"

Controller::Controller()
{
}

Controller::Controller(map<int, Robot*> robots): actions(100)
{
    this->robots.insert(robots.begin(), robots.end());
}

int Controller::checkHealth(int serialNr)
{
    actions--;
    return robots[serialNr]->getHealthStatus();
}

int Controller::getActions()
{
    return actions;
}

void Controller::resetActions()
{
    actions = 100;
}

int Controller::checkActiveStatus(int serialNr)
{
    actions--;
    return robots[serialNr]->getActiveStatus();
}

void Controller::repairRobot(int serialNr)
{
    if (actions == 0) {
        return ;
    }
    if (checkActiveStatus(serialNr) == 1) {
        if (actions > 0 && checkHealth(serialNr) == 0) {
            if (actions > 0) {
                actions--;
                robots[serialNr]->setHealthStatus(true);
            }
        }
    }
}

