#pragma once

/*!
 * @brief Class representing an Encryption.
 * \File Encryption.h
 * \Author Umut Ozturk
 * \Date 22.12.2023
 */
class Encryption {
public:
    /*!
     * @brief Encrypts a 4-digit number using a specific algorithm.
     * \param num The 4-digit number to be encrypted.
     * \return The encrypted number.
     */
    int encrypt(int num);

    /*!
     * @brief Decrypts an encrypted 4-digit number.
     * \param encryptedNum The encrypted 4-digit number to be decrypted.
     * \return The decrypted number.
     */
    int decrypt(int encryptedNum);
};

