#pragma once
#include "Robot.h"
#include "Controller.h"
#include "CommandCenter.h"
#include <iostream>

using namespace std;

class Simulation
{
private:
	map<int,Robot*> robots;
	vector<int> serialNumbers;
	CommandCenter* commandCenter;
	vector<Controller*> controllers;
	int robotsNr;
	int serialNumber = 0;
	int round = 1;
	int points = 0;
	int roundPoints;
	int maxRound;

public:
	Simulation();
	Simulation(int robotsNr, int rounds);
	~Simulation();
	int playRounds();
};

