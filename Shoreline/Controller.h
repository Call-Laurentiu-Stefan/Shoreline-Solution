#pragma once
#include "Robot.h"
#include <map>
using namespace std;

class Controller
{
private:
	map<int, Robot*> robots;
	int actions;

public:
	Controller();
	Controller(map<int, Robot*> robots);
	int checkHealth(int serialNr);
	int checkActiveStatus(int serialNr);
	void repairRobot(int serialNr);
	int getActions();
	void resetActions();
};

