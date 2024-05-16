#pragma once
#include <iostream>
#include "NaoRobotAPI.h"
#include "SensorInterface.h"

/*!
 * \brief Class representing an NaoRobotSensorInterface.
 * \File NaoRobotSensorInterface.h
 * \Author Atakan Berber
 * \Date 04.01.2024
 */

class NaoRobotSensorInterface :public SensorInterface {
protected:
	NaoRobotAPI* RobotAPI; /**< Pointer to NaoRobotAPI for interacting with the Nao Robot. */
public:

/*!
 * @brief Constructor with no parameter.
 */
	NaoRobotSensorInterface() : RobotAPI(new NaoRobotAPI()) {}

	/*!
	 * @brief Constructor with no a parameter.
	 */
	NaoRobotSensorInterface(string s) : SensorInterface(s), RobotAPI(new NaoRobotAPI()) {}
};
