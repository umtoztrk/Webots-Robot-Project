#pragma once
#include <iostream>
#include <string>
#include "Encryption.h"

using namespace std;

/*!
 * \brief Class representing an Robot Operator.
 * \File RobotOperator.h
 * \Author Umut Ozturk
 * \Date 26.12.2023
 */
class RobotOperator {
private:
    string name; /**< Name of the robot operator */
    string surname; /**< Surname of the robot operator */
    unsigned int accessCode; /**< Encrypted access code of the robot operator */
    bool accessState; /**< State indicating whether access is granted or not */
    Encryption* en; /**< Pointer to the Encryption object.*/
public:
    /*!
     * \brief Constructor for RobotOperator class.
     * \param n Name of the robot operator.
     * \param s Surname of the robot operator.
     * \param code Access code of the robot operator.
     * \param encryption Encryption object for code encryption/decryption.
     */
    RobotOperator(string n, string s, int code);
    /*!
     * \brief Checks if the provided access code is correct.
     * \param code Access code to check.
     * \return True if the access code is correct, false otherwise.
     */
    bool checkAccessCode(int);
    /*!
     * \brief Prints the details of the robot operator.
     */
    void print() const;
    /*!
     * \brief Encrypts the given access code using the provided encryption object.
     * \param codeToEncrypt Access code to encrypt.
     * \param encryption Encryption object for code encryption.
     * \return Encrypted access code.
     */
    int encryptCode(int codeToEncrypt);
    /*!
     * \brief Decrypts the given encrypted access code using the provided encryption object.
     * \param encryptedCode Encrypted access code to decrypt.
     * \param encryption Encryption object for code decryption.
     * \return Decrypted access code.
     */
    int decryptCode(int encryptedCode);

    
};
