#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Simulation.h"

using namespace std;

int main() {
	std::srand(std::time(nullptr));
	Simulation sim = Simulation();
	cout <<"\n*******************************\nTotal points: "<<sim.playRounds()<<"\n*******************************\n";
}