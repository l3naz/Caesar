Caesar Cipher
This is a simple Caesar cipher encryption and decryption program written in C.

What is a Caesar Cipher?
A Caesar cipher is one of the simplest forms of encryption. It involves "shifting" letters of the alphabet by a set number of places down the alphabet. For example, with a shift of 3, A would become D, B would become E, C would become F, and so on. The decryption is done by shifting the letters in the opposite direction by the same shift amount.

Usage
The program allows the user to choose between encrypting or decrypting a message.

To encrypt:

Enter the message to encrypt
Enter the shift amount (0-25)
To decrypt:

Choose between entering a specific shift key or brute-forcing all possible shifts
Enter encrypted message
If specific shift, enter the shift amount (0-25)
If brute force, the program will loop through all possible shifts and print the decrypted text for each
The encrypted/decrypted text is printed to the console.

Example
Encrypting "hello" with a shift of 3:

Plaintext: hello
Ciphertext: khoor

Decrypting "khoor" with a shift of 3:

Ciphertext: khoor

Plaintext: hello

Notes
The program only encrypts alphabetical characters, leaves spaces and other characters unchanged
The shift amount wraps around (a shift of 26 would be the same as 0)
Brute force tries all 26 possible shifts (0-25)

Contributors
Nhat Le


