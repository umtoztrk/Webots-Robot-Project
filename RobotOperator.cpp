#include "RobotOperator.h"
#include <iostream>

/*!
 * \file RobotOperator.cpp
 * \brief Implementation file for the RobotOperator class.
 */

using namespace std;

RobotOperator::RobotOperator(string n, string s, int code)
    : en(new Encryption()),name(n), surname(s), accessCode(en->encrypt(code)), accessState(false) {}

bool RobotOperator::checkAccessCode(int enteredCode) {
    /*!
     * \brief Checks if the entered access code is correct.
     * \param enteredCode The access code entered by the operator.
     * \return True if the entered code matches the stored access code, false otherwise.
     */
    accessState = (accessCode == enteredCode);
    return accessState;
}

void RobotOperator::print() const {
    /*!
     * \brief Prints the details of the robot operator.
     */
    cout << "Operator: " << name << " " << surname << endl;
    cout << "Access Granted: " << (accessState ? "Yes" : "No") << endl;
}

int RobotOperator::encryptCode(int codeToEncrypt) {
    /*!
     * \brief Encrypts the access code using the provided encryption object.
     * \param codeToEncrypt The access code to be encrypted.
     * \param encryption The encryption object used for encryption.
     * \return The encrypted access code.
     */
    accessCode = en->encrypt(codeToEncrypt);
    return accessCode;
}

int RobotOperator::decryptCode(int encryptedCode) {
    /*!
     * \brief Decrypts the access code using the provided encryption object.
     * \param encryptedCode The encrypted access code to be decrypted.
     * \param encryption The encryption object used for decryption.
     * \return The decrypted access code.
     */
    int decryptedCode = en->decrypt(encryptedCode);
    return decryptedCode;
}
