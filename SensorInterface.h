#pragma once
#include <iostream>
#include <string>
using namespace std;

/*!
 * \brief Class representing an SensorInterface.
 * \File SensorInterface.h
 * \Author Atakan Berber
 * \Date 05.01.2024
 */

 /**
  * @class SensorInterface
  * @brief Abstract class providing an interface for different types of sensors.
  *
  * SensorInterface is an abstract class that defines a common interface for various sensors.
  * It contains methods for updating sensor readings and retrieving sensor values and types.
  */
class SensorInterface {
protected:
	string SensorType; ///< Type of the sensor.
public:
	/**
	 * @brief Default constructor for SensorInterface.
	 * Initializes the sensor type to an empty string.
	 */
	SensorInterface() : SensorType("") {}
	/**
	 * @brief Constructor with sensor type for SensorInterface.
	 * @param s Initial value for the sensor type.
	 */
	SensorInterface(string s) : SensorType(s) {}
	/**
	 * @brief Pure virtual function to update the sensor's reading.
	 */
	virtual void updateSensor() = 0;
	/**
	 * @brief Pure virtual function to get the sensor's current value as a string.
	 * @return A string representing the sensor's current value.
	 */
	virtual string getSensorValue() const = 0;
	/**
	 * @brief Get the type of the sensor.
	 * @return A string representing the sensor type.
	 */
	string getSensorType() const {
		return SensorType;
	}
};
