#include "BumperSensor.h"

bool BumperSensor::getState(int index) const {
    /*!
     * \brief Get the state of the specified bumper sensor.
     * \param index The index of the bumper sensor (0 to 3).
     * \return The state of the specified bumper sensor.
     * \note If the index is invalid, an error message is displayed, and the program exits.
     */
    if (index < 0 || index > 3) {
        cerr << "\nError: Invalid index." << endl;
        exit(1);
    }
    return states[index];
}

void BumperSensor::updateSensor() {
    /*!
     * \brief Update the bumper sensor states based on the robot's foot bumpers.
     * \details Retrieves the states of the left and right foot bumpers from the RobotAPI and updates the internal states.
     */
    bool leftFoot_left, leftFoot_right, rightFoot_left, rightFoot_right;
    RobotAPI->getFootBumpers(leftFoot_left, leftFoot_right, rightFoot_left, rightFoot_right);
    states[0] = leftFoot_left;
    states[1] = leftFoot_right;
    states[2] = rightFoot_left;
    states[3] = rightFoot_right;
}

bool BumperSensor::checkTouch() const {
    /*!
     * \brief Check if any of the bumper sensors are touched.
     * \return True if any of the bumper sensors are touched, false otherwise.
     */
    for (int i = 0; i < 4; i++) {
        if (states[i]) return true;
    }
    return false;
}

string BumperSensor::getSensorValue() const {

    string value, tmp;
    value = "LeftFoot_Left : ";
    if (states[0]) tmp = "In touch.\n"; else tmp = "Not in touch.\n";
    value += tmp;
    value += "LeftFoot_Right : ";
    if (states[1]) tmp = "In touch.\n"; else tmp = "Not in touch.\n";
    value += tmp;
    value += "RightFoot_Left : ";
    if (states[2]) tmp = "In touch.\n"; else tmp = "Not in touch.\n";
    value += tmp;
    value += "RightFoot_Right : ";
    if (states[3]) tmp = "In touch.\n"; else tmp = "Not in touch.\n";
    value += tmp;
    return value;
}
