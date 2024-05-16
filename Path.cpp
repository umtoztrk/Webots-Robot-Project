#include "Path.h"
#include "Node.h"
#include <string>
#include "RobotControl.h"

using namespace std;

class Path;
class Node;

/*! \class Path
 *  \brief Represents a path consisting of poses in a linked list.
 *
 *  The Path class manages a linked list of Pose objects, where each node in the list
 *  represents a position along the path. It provides methods to add, print, and manipulate
 *  poses in the path, offering basic functionality for path planning and navigation.
 */

 /*! Destructor for the Path class. Deletes all nodes in the linked list. */
Path::~Path() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

/*!
 * \brief Adds a new position to the path.
 *
 * This method creates a new node in the path, setting its pose to the provided
 * Pose object and appending it to the end of the linked list. If the list is
 * empty (tail is nullptr), the new node becomes the head of the list. Otherwise,
 * it is appended after the current tail, and the tail pointer is updated to the
 * new node. The number of nodes in the path is incremented.
 *
 * \param pos Pointer to the Pose object to add to the path.
 */
void Path::addPos(Pose* pos) {
    Node* newnode = new Node;  /*!< Creates a new Node object dynamically. */
    newnode->pose = (*pos);    /*!< Dereferences the pos pointer and assigns the pose to the new node. */
    newnode->next = nullptr;   /*!< Sets the next pointer of the new node to nullptr. */

    if (tail == nullptr) {     /*!< Checks if the list is currently empty. */
        head = newnode;        /*!< If empty, the new node becomes the head of the list. */
    }
    else {
        tail->next = newnode;  /*!< If not empty, appends the new node after the current tail. */
    }

    tail = newnode;            /*!< Updates the tail pointer to the new node. */
    number++;                  /*!< Increments the number of nodes in the path. */
}

/*!
 * \brief Prints the poses in the path to the console.
 *
 * This method traverses the linked list and prints the properties of each Pose object in a Node.
 */
string Path::print() const {
    Node* current = head;
    string poseString;
    string result;
    while (current != nullptr) {
        /*! Manually print the properties of the Pose object in each Node. */
        std::string poseString = "Pose: x=" + std::to_string(current->pose.getX()) +
            ", y=" + std::to_string(current->pose.getY()) +
            ", theta=" + std::to_string(current->pose.getTh());
        /*cout << poseString << endl;*/
        result += poseString + "\n";
        current = current->next;
    }
    return result;
}

/*!
 * \brief Overloaded operator to access the Path as an array.
 *
 * This method returns a vector of Pose objects corresponding to the specified index in the path.
 * If the index is out of bounds, an empty vector is returned.
 *
 * \param i The index to access in the path.
 * \return A vector of Pose objects.
 */
vector<Pose> Path::operator[](int i) const {
    return vector<Pose>(i);
}

int Path::getNumber() {
    return number;
}

/*!
 * \brief Gets the Pose object at the specified index.
 *
 * This method returns a pointer to the Pose object at the specified index in the path.
 * If the index is out of bounds or the list is empty, a pointer to a default Pose is returned.
 *
 * \param index The index to access in the path.
 * \return A pointer to the Pose object.
 */
Pose* Path::getPos(int index) const {
    Node* current = head;
    int count = 0;

    /*! Scroll to the desired index. */
    while (current != nullptr && count < index) {
        current = current->next;
        count++;
    }

    /*! If the index is valid and Node is found, return Pose. */
    if (current != nullptr) {
        return &(current->pose);
    }
    else {
        /*! If the index is not valid or the list is not long enough, return a default Pose. */
        Pose* p = new Pose();
        return p;
    }
}

/*!
 * \brief Removes the Pose object at the specified index.
 *
 * This method removes the Pose object at the specified index in the path.
 * If the index is out of bounds, the list is empty, or the removal fails,
 * it returns false; otherwise, it returns true.
 *
 * \param index The index to remove from the path.
 * \return True if removal is successful, false otherwise.
 */
bool Path::removePos(int index) {
    /*! If the list is empty or the index is negative. */
    if (head == nullptr || index < 0) {
        return false;
    }

    Node* current = head;
    Node* prev = nullptr;

    /*! If we want to delete the first element. */
    if (index == 0) {
        head = current->next;
        delete current;
        // Güncelleme: Eðer listenin tamamýný sildiysek, tail'i de güncelleyelim.
        if (head == nullptr) {
            tail = nullptr;
        }
        number--;
        return true;
    }

    if (current->next == nullptr) {
        tail = prev;
    }

    /*! Scroll down to the Node to delete. */
    for (int i = 0; current != nullptr && i < index; ++i) {
        prev = current;
        current = current->next;
    }

    /*! If current is null, the index exceeds the list size. */
    if (current == nullptr) {
        return false;
    }

    /*! Remove Current from the list. */
    prev->next = current->next;
    delete current; /*!< Delete the node from memory. */

    number--;

    return true;
}

/*!
 * \brief Inserts a new Pose object at the specified index.
 *
 * This method inserts a new Pose object at the specified index in the path.
 * If the index is out of bounds, it returns false; otherwise, it returns true.
 *
 * \param index The index to insert the new Pose object.
 * \param pose The Pose object to insert.
 * \return True if insertion is successful, false otherwise.
 */
bool Path::insertPos(int index, const Pose& pose) {
    if (index < 0) {
        return false; /*!< A negative index is invalid. */
    }

    Node* current = head;
    for (int i = 0; current != nullptr && i < index; ++i) {
        current = current->next;
    }

    if (current == nullptr) {
        return false; /*!< If the index exceeds the list size. */
    }

    Node* newNode = new Node(pose);
    newNode->next = current->next;
    current->next = newNode;

    return true;
}

/*!
 * \brief Overloaded insertion operator for output stream.
 *
 * This operator allows the Path object to be printed to the console using the insertion operator.
 *
 * \param os The output stream object.
 * \param path The Path object to be printed.
 * \return A reference to the output stream.
 */
std::ostream& operator<<(std::ostream& os, const Path& path) {
    Node* current = path.head;
    while (current != nullptr) {
        os << "Pose: x=" << current->pose.getX()
            << ", y=" << current->pose.getY()
            << ", theta=" << current->pose.getTh() << std::endl;
        current = current->next;
    }
    return os;
}

/*!
 * \brief Overloaded extraction operator for input stream.
 *
 * This operator allows the user to input a Pose and add it to the Path using the extraction operator.
 *
 * \param is The input stream object.
 * \param path The Path object to which the Pose is added.
 * \return A reference to the input stream.
 */
std::istream& operator>>(std::istream& is, Path& path) {
    /*! Local variables for the Pose object to be read from the keyboard */
    float x, y, theta;

    /*! Get Pose information from the user. */
    std::cout << "Enter Pose x :";
    is >> x;
    std::cout << "Enter Pose y :";
    is >> y;
    std::cout << "Enter Pose th :";
    is >> theta;
    /*! Create a new Pose object. */
    Pose pose(x, y, theta);

    /*! Add the new Pose object to Path. */
    path.addPos(&pose);

    /*! Return the stream if the operation was successful. */
    return is;
}
