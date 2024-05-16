#ifndef BUMPERSENSOR_H
#define BUMPERSENSOR_H

#include "NaoRobotAPI.h"
#include <iostream>
#include "NaoRobotSensorInterface.h"

/*!
 * @brief Class representing an Bumper Sensor.
 * \File BumperSensor.h
 * \Author Atakan Berber
 * \Date 05.01.2024
 */
class BumperSensor : public NaoRobotSensorInterface {
private:
    bool* states = new bool[4]; //!< Array to store the state of each bumper.

public:
    /*!
     * @brief Constructor for BumperSensor.
     * \param nao Pointer to the NaoRobotAPI instance.
     */
    BumperSensor() : NaoRobotSensorInterface("Bumper") {
        for (int i = 0; i < 4; i++) {
            states[i] = false;
        }
    }

    /*!
     * @brief Gets the state of the bumper at the specified index.
     * \param index The index of the bumper (0 to 3).
     * \return The state of the bumper at the specified index.
     */
    bool getState(int index) const;

    /*!
     * @brief Updates the state of the bumper sensor.
     */
    void updateSensor();

    /*!
     * @brief Checks if any of the bumpers are touched.
     * \return True if any bumper is touched, false otherwise.
     */
    bool checkTouch() const;

    /*!
     * @brief Get sensor value.
     */
    string getSensorValue() const;
};

#endif
