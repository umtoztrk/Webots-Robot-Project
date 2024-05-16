#pragma once
#include "Pose.h"
#include "SensorInterface.h"
#include "vector"

/*!
 * \brief Class representing an RobotInterface.
 * \File RobotInterface.h
 * \Author Abdullah Taha Aydin and Umut Ozturk
 * \Date 04.01.2024
 */


 /**
  * @class RobotInterface
  * @brief Abstract class providing an interface for robot operations.
  *
  * RobotInterface defines a set of operations that any robot class must implement.
  * It contains a list of sensors, the robot's position, and methods to manipulate
  * the robot's state and sensors.
  */
class NaoRobotInterface;

class RobotInterface {
protected:
	int status; ///< Current status of the robot.
	std::vector<SensorInterface*> sensorList; ///< List of sensors attached to the robot.
	Pose* position; ///< Pointer to the Pose object representing the robot's position.
public:
	/**
	 * @brief Constructor for RobotInterface.
	 * Initializes the robot's status and position.
	 */
	RobotInterface() : status(0), position(new Pose()){}
	// Pure virtual functions defining the robot's possible actions
	virtual void turnLeft() = 0;
	virtual void disconnect() = 0;
	virtual void turnRight() = 0;
	virtual void forward() = 0;
	virtual void backward() = 0;
	virtual void moveLeft() = 0;
	virtual void moveRight() = 0;
	virtual void stop() = 0;
	virtual void print() = 0;
	virtual void connect() = 0;
	/**
	 * @brief Checks if a sensor of a given type is in the sensor list.
	 * @param s Type of the sensor to check for.
	 * @return True if the sensor of the specified type is found, false otherwise.
	 */
	bool checkList(string s) {
		for (int i = 0; i < sensorList.size(); i++) {
			if (sensorList[i]->getSensorType() == s) return true;
		}
		return false;
	}
	/**
	 * @brief Retrieves a pointer to a sensor of a given type if it exists.
	 * @param s Type of the sensor to retrieve.
	 * @return Pointer to the SensorInterface of the sensor if found, otherwise nullptr.
	 */
	SensorInterface* checkSensor(string s) {
		for (int i = 0; i < sensorList.size(); i++) {
			if (sensorList[i]->getSensorType() == s) return sensorList[i];
		}
	}
	/**
	 * @brief Calls the updateSensor method on all sensors in the sensor list.
	 */
	void updateSensors() {
		for (int i = 0; i < sensorList.size(); i++) {
			sensorList[i]->updateSensor();
		}
	}
	/**
	 * @brief Pure virtual method to get the current Pose of the robot.
	 * @return A Pose object representing the current position and orientation of the robot.
	 */
	virtual Pose getPose() = 0;

	/**
	 * @brief Adds a sensor to the robot's sensor list.
	 * @param sensor Pointer to the SensorInterface to be added.
	 */
	void addSensor(SensorInterface* sensor) {
		sensorList.push_back(sensor);
	}
	/**
	 * @brief Gets the current Pose of the robot.
	 * @return Pointer to the Pose object representing the robot's position.
	 */
	Pose* givePose()
	{
		return position;
	}

	/**
	 * @brief Gets the list of sensors attached to the robot.
	 * @return Vector of pointers to SensorInterface objects.
	 */
	vector <SensorInterface*> getSensorList() {
		return sensorList;
	}
};