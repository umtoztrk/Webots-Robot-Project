
#include "NaoRobotInterface.h"

/*!
 * \brief Establishes a connection with the robot.
 */
void NaoRobotInterface::connect()
{
    robotAPI->connect();
}

/*!
 * \brief Disconnects from the robot.
 */
void NaoRobotInterface::disconnect()
{
    robotAPI->disconnect();
}

/*!
 * \brief Turns the robot to the left.
 */
void NaoRobotInterface::turnLeft() {
    robotAPI->turnRobot(LEFT);
}

/*!
 * \brief Turns the robot to the right.
 */
void NaoRobotInterface::turnRight() {
    robotAPI->turnRobot(RIGHT);
}

/*!
 * \brief Moves the robot forward.
 */
void NaoRobotInterface::forward() {
    robotAPI->moveRobot(FORWARD);
}

/*!
 * \brief Prints sensor values such as pose, sonar ranges, and foot force.
 */
void NaoRobotInterface::print() {
    /*! Read sonar range values.*/
    double sonarLeft, sonarRight;
    robotAPI->getSonarRange(sonarLeft, sonarRight);

    /*! Read foot bumper values.*/
    bool leftFoot_left, leftFoot_right, rightFoot_left, rightFoot_right;
    robotAPI->getFootBumpers(leftFoot_left, leftFoot_right, rightFoot_left, rightFoot_right);

    cout << "--------------------SENSOR VALUES-------------------------------------" << endl;
    cout << "POSE         : (X) " << robotAPI->getX() << " meters, "
        << "(Y) " << robotAPI->getY() << " meters, "
        << "(Th) " << robotAPI->getTh() << " degrees" << endl << endl;
    cout << "SONAR RANGES : (LEFT) " << sonarLeft
        << " meters, (RIGHT) " << sonarRight << " meters" << endl << endl;
    cout << "FOOT FORCE   : " << robotAPI->getFootForce() << " kg.f" << endl;
    cout << "----------------------------------------------------------------------" << endl;
}

/*!
 * \brief Moves the robot backward.
 */
void NaoRobotInterface::backward() {
    robotAPI->moveRobot(BACKWARD);
}

/*!
 * \brief Retrieves the current pose of the robot.
 * \return The current pose of the robot.
 */
Pose NaoRobotInterface::getPose() {
    position->setX(robotAPI->getX());
    position->setY(robotAPI->getY());
    position->setTh(robotAPI->getTh());
    return *position;
}

/*!
 * \brief Moves the robot to the left.
 */
void NaoRobotInterface::moveLeft() {
    robotAPI->moveRobot(LEFT);
}

/*!
 * \brief Moves the robot to the right.
 */
void NaoRobotInterface::moveRight() {
    robotAPI->moveRobot(RIGHT);
}

/*!
 * \brief Stops the robot.
 */
void NaoRobotInterface::stop() {
    robotAPI->stopRobot();
}

