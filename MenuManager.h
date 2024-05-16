#pragma once
#include <iostream>
#include <string>
#include "RobotOperator.h"
#include "RobotControl.h"
#include "Record.h"
#include "SensorInterface.h"
#include "RobotInterface.h"
#include "NaoRobotInterface.h"
#include "ForceSensor.h"
#include "SonarSensor.h"
#include "BumperSensor.h"
#include "NaoRobotAPI.h"

/*!
 * \brief Class representing an MenuManager.
 * \File MenuManager.h
 * \Author Umut Ozturk and Atakan Berber and Abdullah Taha Aydin
 * \Date 08.01.2024
 */

 /**
  * @class MenuManager
  * @brief Manages the interactive menus for controlling and monitoring the robot.
  *
  * MenuManager handles user interactions and orchestrates control and monitoring
  * of a robot system. It creates and manages the necessary components such as
  * RobotControl, Record, RobotOperator, and various sensors.
  */

class MenuManager {
private:
    RobotOperator* ro; //< Robot operator for managing robot operations.
    RobotControl* nao1; ///< Control interface for a Nao robot.
    Record* rc; ///< Record object for logging and file operations.
    SensorInterface* sr; ///< Generic sensor interface for sonar sensors.
    SensorInterface* bs; ///< Generic sensor interface for bumper sensors.
    SensorInterface* fs; ///< Generic sensor interface for force sensors.
    RobotInterface* rif; ///< Interface for generic robot operations.
    NaoRobotAPI* api; ///< API for interacting with Nao Robot.
public:

    /**
     * @brief Constructor for MenuManager.
     * Initializes all necessary components for robot control and sensor management.
     */
    MenuManager() {
    rif = new NaoRobotInterface();
    nao1 = new RobotControl(rif);
    rc = new Record();
    ro = new RobotOperator("Cemal", "Pasa", 1283);
    }


    /**
     * @brief Destructor for MenuManager.
     * Frees up all dynamically allocated resources.
     */
    ~MenuManager() {
        delete rif;
        delete nao1;
        delete rc;
        delete ro;
        delete sr;
        delete bs;
        delete fs;
        delete api;
    }

    /**
 * @brief Displays the motion menu and handles motion-related commands.
 *
 * This function presents a menu with various motion commands like moving right, left,
 * turning, moving forward, and backward. The user's choice is executed via the
 * RobotControl interface. The function continues to display the menu until the user
 * chooses to return to the main menu.
 */
    void showMotionMenu();

    /**
 * @brief Displays the main menu and routes to the appropriate sub-menu.
 *
 * The main menu offers various options including connecting to the robot, motion control,
 * sensor management, file operations, and more. The function handles user input to navigate
 * to the respective sub-menu or perform the selected action.
 */
    void showMainMenu();

    /**
 * @brief Displays the connection menu and handles robot connection commands.
 *
 * This function presents a menu to either connect or disconnect the robot. It utilizes
 * the RobotControl interface to execute the corresponding actions.
 */
    void showConnectionMenu();

    /**
 * @brief Displays the sensor menu and handles sensor-related commands.
 *
 * The sensor menu allows the user to interact with various sensors like sonar, bumper,
 * and force sensors. It includes options to get sensor readings, update sensors, and more.
 */
    void showSensorMenu();

    /**
 * @brief Handles file operations related to the robot.
 *
 * This function provides options to write and read robot position to/from a file,
 * record path and sensor data. It manages the input/output operations through the Record class.
 */
    void fileOperation();

    /**
 * @brief Validates the user's password for accessing the main menu.
 *
 * The function prompts the user to enter a password. It then checks the validity of
 * the password using RobotOperator. The user is granted access to the main menu upon
 * entering the correct password.
 */
    void checkPassword();
};
