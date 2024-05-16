#include "Encryption.h"
#include <iostream>

/*!
 * \file Encryption.cpp
 * \brief Implementation file for the Encryption class.
 */

int Encryption::encrypt(int num) {
    /*!
     * \brief Encrypts a 4-digit number using a simple algorithm.
     * \details Adds 7 to each digit and takes the modulo 10.
     * \param num The 4-digit number to be encrypted.
     * \return The encrypted 4-digit number.
     * \throws std::runtime_error if the input is not a 4-digit number.
     */
    if (num < 1000 || num > 9999) {
        std::cout << "Error: Input must be a 4-digit number." << std::endl;
        exit(1);
    }

    int d1 = (num % 10 + 7) % 10;
    int d2 = ((num / 10) % 10 + 7) % 10;
    int d3 = ((num / 100) % 10 + 7) % 10;
    int d4 = (num / 1000 + 7) % 10;

    int encryptedNum = d2 * 1000 + d1 * 100 + d4 * 10 + d3;
    return encryptedNum;
}

int Encryption::decrypt(int encryptedNum) {
    /*!
     * \brief Decrypts an encrypted 4-digit number.
     * \details Subtracts 3 from each digit and takes the modulo 10.
     * \param encryptedNum The encrypted 4-digit number to be decrypted.
     * \return The decrypted 4-digit number.
     * \throws std::runtime_error if the input is not a 4-digit number.
     */
    if (encryptedNum < 1000 || encryptedNum > 9999) {
        std::cout << "Error: Input must be a 4-digit number." << std::endl;
        exit(1);
    }

    int d1 = (encryptedNum % 10 + 3) % 10;
    int d2 = ((encryptedNum / 10) % 10 + 3) % 10;
    int d3 = ((encryptedNum / 100) % 10 + 3) % 10;
    int d4 = (encryptedNum / 1000 + 3) % 10;

    int decryptedNum = d2 * 1000 + d1 * 100 + d4 * 10 + d3;
    return decryptedNum;
}
