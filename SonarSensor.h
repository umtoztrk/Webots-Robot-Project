#ifndef SONARSENSOR_H
#define SONARSENSOR_H
#include "NaoRobotAPI.h"
#include <iostream>
#include <string>
#include "NaoRobotSensorInterface.h"
#include "SensorInterface.h"



/*!
 * \brief Class representing an Sonar Sensor.
 * \File SonarSensor.h
 * \Author Atakan Berber
 * \Date 05.01.2024
 */

class SonarSensor : public NaoRobotSensorInterface {
private:
	double* ranges = new double[2]; /**< Array to store sonar sensor ranges. */
public:
	/*!
	 * \brief Constructor for SonarSensor class.
	 * \param nao Pointer to the NaoRobotAPI for communication.
	 */
	SonarSensor() : NaoRobotSensorInterface("Sonar") {
		for (int i = 0; i < 2; i++) {
			ranges[i] = 0.0;
		}
	}
	/*!
	 * \brief Gets the range of the specified sonar sensor.
	 * \param index Index of the sonar sensor (0 or 1).
	 * \return Range of the specified sonar sensor.
	 */
	double getRange(int index) const;

	/*!
	 * \brief Gets the maximum range among sonar sensors.
	 * \param index Reference to the index of the sensor with the maximum range.
	 * \return Maximum range among sonar sensors.
	 */
	double getMax(int& index);

	/*!
	 * \brief Gets the minimum range among sonar sensors.
	 * \param index Reference to the index of the sensor with the minimum range.
	 * \return Minimum range among sonar sensors.
	 */
	double getMin(int& index);

	/*!
	 * \brief Updates the sonar sensor readings.
	 */
	void updateSensor();

	/*!
	 * \brief Gets the range of the specified sonar sensor using subscript operator.
	 * \param i Index of the sonar sensor (0 or 1).
	 * \return Range of the specified sonar sensor.
	 */
	double operator[](int i) const;

	/*!
	 * \brief Gets the sensor values.
	 */
	string getSensorValue() const;
};
#endif