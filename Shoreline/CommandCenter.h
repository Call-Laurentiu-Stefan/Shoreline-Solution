#pragma once
#include "Controller.h"
#include <vector>
using namespace std;

class CommandCenter
{
private:
	vector<int>serialNumbers;
	vector<Controller*>controllers;
	int consumedPoints = 0;
	int currentSerialNumber = 0;

public:
	CommandCenter();
	CommandCenter(vector<int>serialNumbers, vector<Controller*>controllers);
	int useControllers();
	void newRound();
};

