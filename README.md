# Robot simulation
## _Shoreline solution_

This solution contains 4 classes used for solving the problem requirements:
 - Robot - it has all the proprieties from the requirement (activation round, deactivation round, active status, health, getters, setters and a method for generating points)

 - Controller - it has a robot map used for pairing each serial number to its corresponding robot (using a map optimizes the search for each robot). This class has also an action parameter used to count the available actions for each controller in every round. The methods implemented are used for checking the robot health, active status, repairing a robot.
 
 - CommandCenter - it has a vector containing the serial number of each robot, a vector containing all created controllers. It has a method called "useControllers" - it iterates through the controllers giving serial numbers to perform actions on the corresponding robot until the current controller actions are exhausted.
 
 - Simulation - it creates the robots, controllers and command center, giving each the necessary parameters. The method "playRounds" activates and deactivates each robot based on the current round and the proprieties for each robot. It gives each robot a task to generate points and uses command center to repair robots using the controllers.
 
The strategy used was optimizing the number of actions of each controller by repairing only the unhealthy and active robots. By doing this, each controller can check on more robots and repair the unhealthy ones.