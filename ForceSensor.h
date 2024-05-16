#ifndef FORCESENSOR_H
#define FORCESENSOR_H
#include "NaoRobotAPI.h"
#include <iostream>
#include <string>
#include "NaoRobotSensorInterface.h"



class NaoRobotAPI;

/*!
 * \brief Class representing an Force Sensor.
 * \File ForceSensor.h
 * \Author Atakan Berber
 * \Date 05.01.2024
 */

class ForceSensor :public NaoRobotSensorInterface {
private:
	double force;          //!< Variable to store force sensor readings.
public:
	/*!
	 * @brief Constructor for ForceSensor class.
	 * \param nao A pointer to the NaoRobotAPI instance.
	 */
	ForceSensor() : NaoRobotSensorInterface("Force") {
		force = 0.0;
	}
	/*!
	 * @brief Updates the force sensor readings.
	 */
	void updateSensor();
	/*!
	 * @brief Gets the force sensor reading.
	 * \return The force sensor reading.
	 */
	double getForce() const;
	/*!
	 * @brief Checks if a fall is detected based on the force sensor readings.
	 * \return True if a fall is detected, false otherwise.
	 */
	bool CheckFall() const;

	/*!
	 * @brief Get sensor value.
	 */
	string getSensorValue() const;
};
#endif