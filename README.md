# Symmetric Cipher - Simmetric Encryption/Decryption Algorithms

This project implements three symmetric encryption algorithms: Caesar cipher, Vigenère cipher, and Hill cipher. These algorithms are implemented in C++. Code created for Information Security class.

## Getting Started

To compile and run the code, follow these steps:

1. Clone the repository or download the source code.
2. Open the terminal or command prompt and navigate to the project directory.
3. Compile the code using a C++ compiler. For example: g++ -o symmetric_cipher main.cpp


## Menu Options

The program presents a menu with the following options:

1. Caesar cipher
2. Vigenère cipher
3. Hill cipher
4. Exit

### Caesar Cipher

The Caesar cipher is a substitution cipher where each letter in the plaintext is shifted a certain number of positions down the alphabet.

#### Encryption

To encrypt a message using the Caesar cipher:

1. Choose option 1 (Cesar cipher) from the main menu.
2. Select option 1 (Encryption) from the Caesar cipher menu.
3. Enter the message to encrypt.
4. Enter the encryption key (numeric value).
5. The encrypted message will be displayed.

#### Decryption

To decrypt a message using the Caesar cipher:

1. Choose option 1 (Cesar cipher) from the main menu.
2. Select option 2 (Decryption) from the Caesar cipher menu.
3. Enter the message to decrypt.
4. Enter the decryption key (numeric value).
5. The decrypted message will be displayed.

### Vigenère Cipher

The Vigenère cipher is a polyalphabetic substitution cipher that uses a keyword to encrypt and decrypt messages.

#### Encryption

To encrypt a message using the Vigenère cipher:

1. Choose option 2 (Vigenère cipher) from the main menu.
2. Select option 1 (Encryption) from the Vigenère cipher menu.
3. Enter the message to encrypt.
4. Enter the encryption key (keyword).
5. The encrypted message will be displayed.

#### Decryption

To decrypt a message using the Vigenère cipher:

1. Choose option 2 (Vigenère cipher) from the main menu.
2. Select option 2 (Decryption) from the Vigenère cipher menu.
3. Enter the message to decrypt.
4. Enter the decryption key (keyword).
5. The decrypted message will be displayed.

### Hill Cipher

The Hill cipher is a polygraphic substitution cipher that uses matrix multiplication to encrypt and decrypt messages.

#### Encryption

To encrypt a message using the Hill cipher:

1. Choose option 3 (Hill cipher) from the main menu.
2. Select option 1 (Encryption) from the Hill cipher menu.
3. Enter the message to encrypt.
4. Enter the encryption key (4 uppercase letters).
5. The encrypted message will be displayed.

#### Decryption

To decrypt a message using the Hill cipher:

1. Choose option 3 (Hill cipher) from the main menu.
2. Select option 2 (Decryption) from the Hill cipher menu.
3. Enter the message to decrypt.
4. Enter the decryption key (4 uppercase letters).
5. The decrypted message will be displayed.
