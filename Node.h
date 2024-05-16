#pragma once
#include "Pose.h"
class Pose;
/*!
 * \brief Class representing an Node.
 * \File Node.h
 * \Author Eren Eroglu
 * \Date 22.12.2023
 */
class Node {
public:
    Node* next;  //!< Pointer to the next Node in the list.
    Pose pose;   //!< Pose object associated with the Node.

    /*!
     * \brief Constructor for Node class with a specified Pose.
     * \param pose The Pose object to associate with the Node.
     */
    Node(const Pose& pose);

    /*!
     * \brief Default constructor for Node class.
     */
    Node();
};
