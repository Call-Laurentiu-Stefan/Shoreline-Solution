#pragma once
#include <cstdlib>

class Robot
{
private:
	int serialNumber;
	int activationRound;
	int deactivationRound;
	bool isHealthy;
	bool isActive;

public:
	Robot();
	Robot(int serialNumber, int activationRound, int deactivationRound);
	int generatePoints();
	bool getHealthStatus();
	bool getActiveStatus();
	void setActiveStatus(bool activeStatus);
	void setHealthStatus(bool healthStatus);
	int getActivationRound();
	int getDeactivationRound();
};

