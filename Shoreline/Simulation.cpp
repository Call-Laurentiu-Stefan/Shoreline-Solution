#include "Simulation.h"

Simulation::Simulation(int robotNr, int rounds) {
	robotsNr = robotNr;
	maxRound = rounds;
	for (int i = 0; i < robotNr;i++) {
		int activation_round = rand() % 30 + 1;
		int deactivation_round = rand() % 31 + 30;
		serialNumber++;
		serialNumbers.push_back(serialNumber);
		Robot* robot = new Robot(serialNumber, activation_round, deactivation_round);
		robots[serialNumber] = robot;
	}
	for (int i = 1; i <= robotNr / 33; i++) {
		Controller* controller = new Controller(robots);
		controllers.push_back(controller);
	}
	commandCenter = new CommandCenter(serialNumbers, controllers);
}

Simulation::~Simulation() {
	for (auto& pair : robots) {
		delete pair.second;
	}

	robots.clear();

	for (Controller* controller : controllers) {
		delete controller;
	}

	controllers.clear();

	delete commandCenter;
}

int Simulation::playRounds()
{
	while (round <= maxRound) {
		roundPoints = 0;
		for (auto robot : robots) {
			if (robot.second->getActivationRound() == round) {
				robot.second->setActiveStatus(true);
			}
			else if(robot.second->getDeactivationRound() == round) {
				robot.second->setActiveStatus(false);
			}
			roundPoints += robot.second->generatePoints();
		}
		roundPoints -= commandCenter->useControllers();
		commandCenter->newRound();
		cout << "Puncte pentru runda "<<round<<": "<< roundPoints<< endl;
		points += roundPoints;
		round++;
		
	}
	return points;
	
}

Simulation::Simulation(): Simulation(10000,60) {
}