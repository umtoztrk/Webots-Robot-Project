#include "Node.h"

    /*!
     * \brief Constructor to create a node with a specified pose.
     * \param pose The pose associated with the node.
     */
Node::Node(const Pose& pose) : next(nullptr), pose(pose) {}
    /*!
     * \brief Default constructor to create a node with a null pose.
     */
Node::Node() : next(nullptr) {}
