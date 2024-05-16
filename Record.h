#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*!
 * \brief Class representing an Record.
 * \File Record.h
 * \Author Umut Ozturk
 * \Date 24.12.2023
 */
class Record {
private:
    string fileName; /**< Name of the file to read or write */
    fstream file; /**< File stream for reading/writing */
public:
    /*!
     * \brief Default constructor for Record class.
     */
    Record();
    /*!
     * \brief Destructor for Record class.
     */
    ~Record();
    /*!
     * \brief Opens the file specified by fileName.
     * \return True if the file is opened successfully, false otherwise.
     */
    bool openFile();
    /*!
     * \brief Closes the currently opened file.
     * \return True if the file is closed successfully, false otherwise.
     */
    bool closeFile();
    /*!
     * \brief Sets the name of the file to read or write.
     * \param filename Name of the file.
     */
    void setFileName(const string& filename);
    /*!
     * \brief Reads a line from the currently opened file.
     * \return A string representing the read line.
     */
    string readLine();
    /*!
     * \brief Writes a line to the currently opened file.
     * \param data Data to be written.
     * \return True if writing is successful, false otherwise.
     */
    bool writeLine(const string& data);
    /*!
     * \brief Overloaded operator for writing a string to the file.
     * \param data Data to be written.
     * \return Reference to the Record object.
     */
    Record& operator<<(const std::string& data);
    /*!
     * \brief Overloaded operator for reading a string from the file.
     * \param data Data to be read.
     * \return Reference to the Record object.
     */
    Record& operator>>(std::string& data);
};