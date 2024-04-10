#include "Robot.h"

Robot::Robot(int serialNumber, int activationRound, int deactivationRound): serialNumber(serialNumber), activationRound(activationRound), deactivationRound(deactivationRound), isHealthy(true), isActive(false)
{
}

Robot::Robot()
{
}

int Robot::generatePoints()
{
	int workload = rand() % 100 + 1;
	if (isActive) {
		if (!isHealthy) {
			return -10;
		}
		if (workload > 90) {
			isHealthy = false;
			return 0;
		}
		return 1;
	}
	return 0;
}

bool Robot::getHealthStatus()
{
	return isHealthy;
}

bool Robot::getActiveStatus() 
{
	return isActive;
}

void Robot::setActiveStatus(bool activeStatus)
{
	isActive = activeStatus;
}


int Robot::getActivationRound()
{
	return activationRound;
}

void Robot::setHealthStatus(bool healthStatus)
{
	isHealthy = healthStatus;
}

int Robot::getDeactivationRound()
{
	return deactivationRound;
}



