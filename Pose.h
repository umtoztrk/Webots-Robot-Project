#pragma once
#ifndef POSE_H
#define POSE_H

/*!
 * \brief Class representing an Pose.
 * \File Pose.h
 * \Author Eren Eroglu
 * \Date 22.12.2023
 */
class Pose {
private:
    double x;  //!< X-coordinate.
    double y;  //!< Y-coordinate.
    double th; //!< Angle in radians.

public:
    /*!
     * \brief Default constructor for the Pose class.
     */
    Pose();

    /*!
     * \brief Parameterized constructor for the Pose class.
     * \param _x Initial x-coordinate.
     * \param _y Initial y-coordinate.
     * \param _th Initial angle in radians.
     */
    Pose(double _x, double _y, double _th);

    /*!
     * \brief Getter for the x-coordinate.
     * \return The x-coordinate.
     */
    double getX() const;

    /*!
     * \brief Setter for the x-coordinate.
     * \param _x New x-coordinate.
     */
    void setX(double _x);

    /*!
     * \brief Getter for the y-coordinate.
     * \return The y-coordinate.
     */
    double getY() const;

    /*!
     * \brief Setter for the y-coordinate.
     * \param _y New y-coordinate.
     */
    void setY(double _y);

    /*!
     * \brief Getter for the angle.
     * \return The angle in radians.
     */
    double getTh() const;

    /*!
     * \brief Setter for the angle.
     * \param _th New angle in radians.
     */
    void setTh(double _th);

    /*!
     * \brief Equality operator to check if two Pose objects are equal.
     * \param other Another Pose object for comparison.
     * \return True if the two Pose objects are equal, false otherwise.
     */
    bool operator==(const Pose& other) const;

    /*!
     * \brief Addition operator to add two Pose objects.
     * \param other Another Pose object to add.
     * \return A new Pose object representing the sum.
     */
    Pose operator+(const Pose& other) const;

    /*!
     * \brief Subtraction operator to subtract two Pose objects.
     * \param other Another Pose object to subtract.
     * \return A new Pose object representing the difference.
     */
    Pose operator-(const Pose& other) const;

    /*!
     * \brief In-place addition operator to add another Pose object.
     * \param other Another Pose object to add.
     * \return Reference to the modified current Pose object.
     */
    Pose& operator+=(const Pose& other);

    /*!
     * \brief In-place subtraction operator to subtract another Pose object.
     * \param other Another Pose object to subtract.
     * \return Reference to the modified current Pose object.
     */
    Pose& operator-=(const Pose& other);

    /*!
     * \brief Less than operator to compare two Pose objects.
     * \param other Another Pose object for comparison.
     * \return True if the current Pose is less than the other, false otherwise.
     */
    bool operator<(const Pose& other) const;

    /*!
     * \brief Getter for all Pose components.
     * \param _x Reference to store the x-coordinate.
     * \param _y Reference to store the y-coordinate.
     * \param _th Reference to store the angle.
     */
    void getPose(double& _x, double& _y, double& _th) const;

    /*!
     * \brief Setter for all Pose components.
     * \param _x New x-coordinate.
     * \param _y New y-coordinate.
     * \param _th New angle in radians.
     */
    void setPose(double _x, double _y, double _th);

    /*!
     * \brief Calculates the Euclidean distance to another Pose object.
     * \param pos Another Pose object for distance calculation.
     * \return The Euclidean distance between the two Pose objects.
     */
    double findDistanceTo(const Pose& pos) const;

    /*!
     * \brief Calculates the angle to another Pose object.
     * \param pos Another Pose object for angle calculation.
     * \return The angle in radians to the other Pose object.
     */
    double findAngleTo(const Pose& pos) const;
};

#endif // POSE_H
