#pragma once
#include <ostream>
#include <iostream>
#include "Node.h"
#include <vector>
#include "Pose.h"

class Pose;
class Node;

using namespace std;

/*!
 * \brief Class representing an Path.
 * \File Path.h
 * \Author Abdullah Taha Aydin
 * \Date 31.12.2023
 */
class Path {
private:
    Node* tail;    //!< Pointer to the last Node in the linked list.
    Node* head;    //!< Pointer to the first Node in the linked list.
    int number;    //!< Number of nodes in the path.
public:
    /*!
     * \brief Default constructor for the Path class.
     */
    Path() : tail(nullptr), head(nullptr), number(0) {};

    /*!
     * \brief Destructor for the Path class.
     */
    ~Path();

    /*!
     * \brief Adds a new Pose to the path.
     * \param pos Pointer to the Pose object to add.
     */
    void addPos(Pose* pos);

    /*!
     * \brief Prints the information of all Pose objects in the path.
     */
    string print() const;

    /*!
     * \brief Overloaded operator for accessing Pose objects at a specific index.
     * \param i Index of the desired Pose.
     * \return Vector of Pose objects at the specified index.
     */
    vector<Pose> operator[](int i) const;

    /*!
     * \brief Gets the Pose object at a specific index.
     * \param index Index of the desired Pose.
     * \return Pointer to the Pose object at the specified index.
     */
    Pose* getPos(int index) const;

    /*!
     * \brief Removes the Pose object at a specific index.
     * \param index Index of the Pose object to remove.
     * \return True if removal is successful, false otherwise.
     */
    bool removePos(int index);

    /*!
     * \brief Inserts a new Pose object at a specific index.
     * \param index Index at which to insert the new Pose.
     * \param pose Pose object to insert.
     * \return True if insertion is successful, false otherwise.
     */
    bool insertPos(int index, const Pose& pose);

    int getNumber();

    /*!
     * \brief Overloaded stream insertion operator for printing the Path.
     * \param os Output stream.
     * \param path Path object to print.
     * \return Reference to the output stream.
     */
    friend ostream& operator<<(ostream& os, const Path& path);

    /*!
     * \brief Overloaded stream extraction operator for reading from the keyboard.
     * \param is Input stream.
     * \param path Path object to read into.
     * \return Reference to the input stream.
     */
    friend istream& operator>>(istream& is, Path& path);
};
