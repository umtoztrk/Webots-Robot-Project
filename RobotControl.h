#pragma once
#include "Pose.h"
#include <list>
#include "Path.h"
#include "Record.h"
#include "RobotOperator.h"
#include "NaoRobotAPI.h"
#include "RobotInterface.h"


class NaoRobotAPI;
class RobotInterface;

/*!
 * \brief Class representing an Robot Control.
 * \File RobotControl.h
 * \Author Abdullah Taha Aydin and Umut Ozturk
 * \Date 06.01.2024
 */

/*!
 * \class RobotControl
 * \brief Handles the control and movement of a robot.
 */

class SensorInterface;

class RobotControl {
private:
    Record* rc; ///< Record object for logging and file operations.
    RobotOperator* ro; ///< Robot operator for managing robot operations.
    bool accessStatus; ///< Indicates whether access to the robot is granted.
    RobotInterface* robotInterface; ///< Interface for controlling the robot.
    int state; ///< Internal state variable of the robot.
    Path* path; ///< Path object for storing the robot's movement path.
    list<SensorInterface*> sensorList; ///< List of sensor interfaces attached to the robot
public:

    /*!
     * \brief Default constructor for RobotControl class.
     */
    RobotControl(RobotInterface* rI) : state(0), robotInterface(rI) ,accessStatus(false), path(new Path()), rc(new Record()), ro(new RobotOperator("Cemal","Pasa", 1283)){}

    RobotControl(): state(0), accessStatus(false){}
    /*!
    * \brief Destructor for RobotControl class.
    */
    ~RobotControl() {
        delete rc;
        delete robotInterface;
        delete path;
        delete ro;
    }
    /*!
    * \brief Establishes a connection with the robot.
    */
    void connect();

    /*!
    * \brief Gets the current access status.
    */
    bool getStatus();

    /*!
    * \brief Clears the recorded path.
    */
    void clearPath();

    /*!
    * \brief Adds the current pose of the robot to the path.
    */
    void addToPath();
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
    /*!
    * \brief Returns the current pose of the robot.
    * \return Pointer to the Pose object representing the robot's position.
    */
    Pose* givePose();

    /*!
    * \brief Records the robot's path to a file.
    */
    bool recordPathToFile(Record* rc);
    /*!
    * \brief Open acces for move robot.
    */
    bool openAccess(int i);

    /*!
    * \brief Close acces to move robot.
    */
    bool closeAccess(int i);

    /*!
    * \brief Records the robot's path to a file.
    */
    bool recordSensor(string type,Record* rc);

    /*!
   * \brief Prints sensor values of a specified type.
   */
    bool printSensor(string type);

    /*!
  * \brief Adds a sensor to the robot.
  */
    void addSensor(SensorInterface* sensor);
};