#include "CommandCenter.h"

CommandCenter::CommandCenter()
{
}

CommandCenter::CommandCenter(vector<int>serialNumbers, vector<Controller*> controllers)
{
	this->serialNumbers = serialNumbers;
	this->controllers = controllers;
}

int CommandCenter::useControllers()
{
	for (auto controller : controllers) {
		while(controller->getActions() > 0) {
			if (currentSerialNumber == serialNumbers.size() - 1) {
				consumedPoints += 20;
				return consumedPoints;
			}
			controller->repairRobot(serialNumbers[currentSerialNumber]);
			currentSerialNumber++;
		}
		consumedPoints += 20;
	}
	return consumedPoints;
}

void CommandCenter::newRound()
{
	consumedPoints = 0;
	currentSerialNumber = 0;
	for (auto controller : controllers) {
		controller->resetActions();
	}
}
