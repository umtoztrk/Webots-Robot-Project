#include "Pose.h"
#include <iostream>
#include <cmath>

using namespace std;

/*!
 * \brief Default constructor for Pose class.
 * Initializes the pose with default values (x=0, y=0, th=0).
 */
Pose::Pose() : x(0), y(0), th(0) {}

/*!
 * \brief Parameterized constructor for Pose class.
 * \param _x Initial x-coordinate.
 * \param _y Initial y-coordinate.
 * \param _th Initial orientation (theta).
 */
Pose::Pose(double _x, double _y, double _th) : x(_x), y(_y), th(_th) {}

/*!
 * \brief Getter function for x-coordinate.
 * \return Current x-coordinate.
 */
double Pose::getX() const {
    return x;
}

/*!
 * \brief Setter function for x-coordinate.
 * \param _x New x-coordinate value.
 */
void Pose::setX(double _x) {
    x = _x;
}

/*!
 * \brief Getter function for y-coordinate.
 * \return Current y-coordinate.
 */
double Pose::getY() const {
    return y;
}

/*!
 * \brief Setter function for y-coordinate.
 * \param _y New y-coordinate value.
 */
void Pose::setY(double _y) {
    y = _y;
}

/*!
 * \brief Getter function for orientation (theta).
 * \return Current orientation value.
 */
double Pose::getTh() const {
    return th;
}

/*!
 * \brief Setter function for orientation (theta).
 * \param _th New orientation value.
 */
void Pose::setTh(double _th) {
    th = _th;
}

/*!
 * \brief Equality comparison operator for Pose objects.
 * \param other The Pose object to compare with.
 * \return True if the two Pose objects are equal, false otherwise.
 */
bool Pose::operator==(const Pose& other) const {
    return x == other.x && y == other.y && th == other.th;
}

/*!
 * \brief Addition operator for Pose objects.
 * \param other The Pose object to add.
 * \return A new Pose object representing the sum of the two Poses.
 */
Pose Pose::operator+(const Pose& other) const {
    return Pose(x + other.x, y + other.y, th + other.th);
}

/*!
 * \brief Subtraction operator for Pose objects.
 * \param other The Pose object to subtract.
 * \return A new Pose object representing the difference between the two Poses.
 */
Pose Pose::operator-(const Pose& other) const {
    return Pose(x - other.x, y - other.y, th - other.th);
}

/*!
 * \brief Compound addition assignment operator for Pose objects.
 * \param other The Pose object to add.
 * \return A reference to the modified original Pose object.
 */
Pose& Pose::operator+=(const Pose& other) {
    x += other.x;
    y += other.y;
    th += other.th;
    return *this;
}

/*!
 * \brief Compound subtraction assignment operator for Pose objects.
 * \param other The Pose object to subtract.
 * \return A reference to the modified original Pose object.
 */
Pose& Pose::operator-=(const Pose& other) {
    x -= other.x;
    y -= other.y;
    th -= other.th;
    return *this;
}

/*!
 * \brief Less-than comparison operator for Pose objects.
 * \param other The Pose object to compare with.
 * \return True if the current Pose is less than the other Pose, false otherwise.
 */
bool Pose::operator<(const Pose& other) const {
    return x < other.x || (x == other.x && (y < other.y || (y == other.y && th < other.th)));
}

/*!
 * \brief Getter function for retrieving the Pose values.
 * \param _x Reference to store the x-coordinate.
 * \param _y Reference to store the y-coordinate.
 * \param _th Reference to store the orientation (theta).
 */
void Pose::getPose(double& _x, double& _y, double& _th) const {
    _x = x;
    _y = y;
    _th = th;
}

/*!
 * \brief Setter function for updating the Pose values.
 * \param _x New x-coordinate value.
 * \param _y New y-coordinate value.
 * \param _th New orientation (theta) value.
 */
void Pose::setPose(double _x, double _y, double _th) {
    x = _x;
    y = _y;
    th = _th;
}

/*!
 * \brief Calculate the distance between the current Pose and another Pose.
 * \param pos The target Pose.
 * \return The Euclidean distance between the two Poses.
 */
double Pose::findDistanceTo(const Pose& pos) const {
    return sqrt(pow(x - pos.x, 2) + pow(y - pos.y, 2));
}

/*!
 * \brief Calculate the angle between the current Pose and another Pose.
 * \param pos The target Pose.
 * \return The angle (in radians) between the two Poses.
 */
double Pose::findAngleTo(const Pose& pos) const {
    return atan2(pos.y - y, pos.x - x) - th;
}

