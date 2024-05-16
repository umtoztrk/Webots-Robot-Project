#include "SonarSensor.h"

/*!
 * \brief Gets the range of the sonar sensor at the specified index.
 * \param index The index of the sonar sensor (0 or 1).
 * \return The range of the sonar sensor at the specified index.
 */
double SonarSensor::getRange(int index) const {
    if ((index != 1) && (index != 0)) {
        cerr << "\nError: Invalid index." << endl;
        exit(1);
    }
    return ranges[index];
}

/*!
 * \brief Gets the maximum range value among the sonar sensors.
 * \param[out] index The index of the sonar sensor with the maximum range.
 * \return The maximum range value.
 */
double SonarSensor::getMax(int& index) {
    if (ranges[0] > ranges[1]) {
        index = 0;
        return ranges[0];
    }
    else {
        index = 1;
        return ranges[1];
    }
}

/*!
 * \brief Gets the minimum range value among the sonar sensors.
 * \param[out] index The index of the sonar sensor with the minimum range.
 * \return The minimum range value.
 */
double SonarSensor::getMin(int& index) {
    if (ranges[0] > ranges[1]) {
        index = 1;
        return ranges[1];
    }
    else {
        index = 0;
        return ranges[0];
    }
}

/*!
 * \brief Updates the sonar sensor values.
 */
void SonarSensor::updateSensor() {
    RobotAPI->getSonarRange(ranges[0], ranges[1]);
}

/*!
 * \brief Gets the range of the sonar sensor at the specified index using the subscript operator.
 * \param i The index of the sonar sensor (0 or 1).
 * \return The range of the sonar sensor at the specified index.
 */
double SonarSensor::operator[](int i) const {
    if ((i != 1) && (i != 0)) {
        cerr << "\nError: Subscript out of range" << endl;
        exit(1);
    }
    return ranges[i];
}

string SonarSensor::getSensorValue() const {
    string value;
    value = "[0] : " + to_string(getRange(0)) + "m , [1] : " + to_string(getRange(1)) + "m\n";
    return value;
}