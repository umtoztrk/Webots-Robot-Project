#include "ForceSensor.h"

void ForceSensor::updateSensor() {
    /*!
     * \brief Update the force sensor reading based on the robot's foot force.
     * \details Retrieves the force reading from the RobotAPI and updates the internal force variable.
     */
    force = RobotAPI->getFootForce();
}

double ForceSensor::getForce() const {
    /*!
     * \brief Get the current force reading from the sensor.
     * \return The force reading.
     */
    return force;
}

bool ForceSensor::CheckFall() const {
    /*!
     * \brief Check if the force indicates a potential fall.
     * \return True if the force is below the threshold, indicating a potential fall; otherwise, false.
     */
    if (force < 0.09) return true;
    else return false;
}

string ForceSensor::getSensorValue() const {
    string value;
    value = "Force : " + to_string(getForce()) + "kg.f\n";
    return value;
}
