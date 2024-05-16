#include "RobotControl.h"

/*!
 * \brief Establishes a connection with the robot.
 */
void RobotControl::connect()
{   
    robotInterface->connect();
}

void RobotControl::addToPath() 
{
    path->addPos(givePose());
    cout << "Path Added." << endl;
}

void RobotControl::clearPath() {
    while (path->getNumber() > 0) {
        path->removePos(0); // Her seferinde listenin baþýndaki elemaný siliyoruz.
    }
    cout << "Path Cleared." << endl;
}


bool RobotControl::recordPathToFile(Record* rc) {
    if (path->getNumber() > 0) {
        rc->writeLine(path->print());
        return true; // Recording path to file successful
    }
    else {
        return false; // Path is empty, nothing to record
    }
}


bool RobotControl::openAccess(int i) {
    if (accessStatus) {
        cout << "Access already opened." << endl;
    }
    else {
        int accessCode = ro->decryptCode(i);
        accessStatus = ro->checkAccessCode(accessCode);
        return accessStatus;
    }
}

bool RobotControl::closeAccess(int i) {
    int accessCode = ro->decryptCode(i);
    accessStatus = ro->checkAccessCode(accessCode);
    if (accessStatus) {
        accessStatus = false;
    }
    else {
        accessStatus = true;
    }
    return accessStatus;
}

bool RobotControl::getStatus() {
    return accessStatus;
}

bool RobotControl::recordSensor(string type,Record* rc) {
    for (int i = 0; i < robotInterface->getSensorList().size(); i++) {
        if (robotInterface->getSensorList()[i]->getSensorType() == type) {
            rc->writeLine(robotInterface->getSensorList()[i]->getSensorValue());
            return true;
        }
    }
    return false;
}

bool RobotControl::printSensor(string type) {
    for (int i = 0; i < robotInterface->getSensorList().size(); i++) {
        if (robotInterface->getSensorList()[i]->getSensorType() == type) {
            cout << robotInterface->getSensorList()[i]->getSensorValue() << endl;
            return true;
        }
    }
    return false;
}

void RobotControl::addSensor(SensorInterface* sensor) {
    robotInterface->addSensor(sensor);
}

/*!
 * \brief Disconnects from the robot.
 */
void RobotControl::disconnect()
{
    robotInterface->disconnect();
}

/*!
 * \brief Turns the robot to the left.
 */
void RobotControl::turnLeft() {
    robotInterface->turnLeft();
    RobotControl::getPose();
}

/*!
 * \brief Turns the robot to the right.
 */
void RobotControl::turnRight() {
    robotInterface->turnRight();
    RobotControl::getPose();
}

/*!
 * \brief Moves the robot forward.
 */
void RobotControl::forward() {
    robotInterface->forward();
    RobotControl::getPose();
}

/*!
 * \brief Prints sensor values such as pose, sonar ranges, and foot force.
 */
void RobotControl::print() {
    robotInterface->print();
}

/*!
 * \brief Moves the robot backward.
 */
void RobotControl::backward() {
    robotInterface->backward();
    RobotControl::getPose();
}

/*!
 * \brief Retrieves the current pose of the robot.
 * \return The current pose of the robot.
 */
Pose RobotControl::getPose() {
    return robotInterface->getPose();
}

/*!
 * \brief Moves the robot to the left.
 */
void RobotControl::moveLeft() {
    robotInterface->moveLeft();
    RobotControl::getPose();
}

/*!
 * \brief Moves the robot to the right.
 */
void RobotControl::moveRight() {
    robotInterface->moveRight();
    RobotControl::getPose();
}

/*!
 * \brief Stops the robot.
 */

void RobotControl::stop() {
    robotInterface->stop();
}

/*!
 * \brief Retrieves the current pose of the robot.
 * \return A pointer to the current pose of the robot.
 */
Pose* RobotControl::givePose()
{
    return robotInterface->givePose();
}
