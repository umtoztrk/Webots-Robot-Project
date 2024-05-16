#include "Record.h"

/*!
 * \file Record.cpp
 * \brief Implementation file for the Record class.
 */

Record::Record() {}

Record::~Record() {
    closeFile();
}

bool Record::openFile() {
    /*!
     * \brief Opens the file for reading and writing.
     * \details Opens the file with modes: ios::in | ios::out | ios::app.
     * \return True if the file is successfully opened, false otherwise.
     */
    file.open(fileName, ios::in | ios::out | ios::app);
    if (!file.is_open()) {
        cerr << "Error opening file: " << fileName << endl;
        return false;
    }
    return true;
}

bool Record::closeFile() {
    /*!
     * \brief Closes the file.
     * \return True if the file is successfully closed, false otherwise.
     */
    if (file.is_open()) {
        file.close();
        return true;
    }
    return false;
}

void Record::setFileName(const string& filename) {
    /*!
     * \brief Sets the file name.
     * \details Closes the current file, sets the new file name, and opens the new file.
     * \param filename The name of the new file.
     */
    closeFile();
    fileName = filename;
    openFile();
}

string Record::readLine() {
    /*!
     * \brief Reads all lines from the file and concatenates them into a single string.
     * \return The concatenated string containing all the lines from the file.
     */
    string line;
    string result;
    while (getline(file, line)) {
        result += line + "\n";
    }
    return result;
}


bool Record::writeLine(const string& data) {
    /*!
     * \brief Writes a line to the file.
     * \param data The data to be written to the file.
     * \return True if the data is successfully written, false otherwise.
     */
    if (file.is_open()) {
        file << data << endl;
        return true;
    }
    return false;
}

Record& Record::operator<<(const string& data) {
    /*!
     * \brief Overloaded operator to write a line to the file using <<.
     * \param data The data to be written to the file.
     * \return A reference to the Record object.
     */
    writeLine(data);
    return *this;
}

Record& Record::operator>>(string& data) {
    /*!
     * \brief Overloaded operator to read a line from the file using >>.
     * \param data Reference to store the read data.
     * \return A reference to the Record object.
     */
    data = readLine();
    return *this;
}
