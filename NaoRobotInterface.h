#pragma once
#include "RobotInterface.h"
#include "NaoRobotAPI.h"


class NaoRobotAPI;
class RobotInterface;

/*!
 * \brief Class representing an NaoRobotInterface.
 * \File NaoRobotInterface.h
 * \Author Umut Ozturk and Eren Eroglu
 * \Date 05.01.2024
 */

class NaoRobotInterface: public RobotInterface {
protected:
   
    NaoRobotAPI* robotAPI; /**< Pointer to the NaoRobotAPI for robot communication. */
   
public:
    /*!
     * \brief Default constructor for RobotControl class.
     */
    NaoRobotInterface() : robotAPI(new NaoRobotAPI()) {}
    /*!
    * \brief Destructor for RobotControl class.
    */
    ~NaoRobotInterface() {}
    /*!
    * \brief Establishes a connection with the robot.
    */
    void connect();
    /*!
    * \brief Disconnects from the robot.
    */
    void disconnect();
    /*!
    * \brief Turns the robot to the left.
    */
    void turnLeft();
    /*!
    * \brief Turns the robot to the right.
    */
    void turnRight();
    /*!
    * \brief Moves the robot forward.
    */
    void forward();
    /*!
    * \brief Prints information about the robot's pose and sensor values.
    */
    void print();
    /*!
    * \brief Moves the robot backward.
    */
    void backward();
    /*!
    * \brief Gets the current pose of the robot.
    * \return Pose object representing the robot's position.
    */
    Pose getPose();
    /*!
    * \brief Moves the robot to the left.
    */
    void moveLeft();
    /*!
    * \brief Moves the robot to the right.
    */
    void moveRight();
    /*!
    * \brief Stops the robot.
    */
    void stop();
    
};