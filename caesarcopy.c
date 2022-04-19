//Libraries required for the program to run.
#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

//Define the ASCII values of A-Z for upper case and lowercase. These are "magic numbers".
#define BASECAP 65
#define BASELOW 97

//Declare the function so the computer knows to look for it. (Prototype).
char encrypt(char letter, int key);

//Main function, taking in 2 arguments as a string datatype.
int main(int argc, string argv[])
{

// An if statement that returns an error message if the user inputs more or less than 2 arguments.
    if (argc != 2 || argc == 1)
    {
        printf("ERROR: Invalid amount of arguments! Proper usage: ./caesar (key). \n");
        return 1;
    }
//An else statement that will first chek if the key is an integer, then prompt the user for a string value. Each character of the string is then iterated through using a for loop.
    else
    {
        //Stores the argument value of the second argument in a variable called key.
        string key = argv[1];
        //A for loop that iterates through every character of key (as it is stored as a string).
        for (int i = 0; i < strlen(key); i++)
        {
            //An if statement that checks if the inputted key is an alphabet character or not. f it is, it will result in an error, ending the program.
            if (isalpha(key[i]))
            {
                printf("ERROR: Key must be an integer!\n");
                return 1;
            }
        }
//The for loop will take each and every character in the string and pass it through the encrypt function, along with the key.
//The key will be passed through the function "atoi" in order to change it from a string datatype to an integer.
//It will then assign the return value from the encrypt function to variable "e". Then, the program will print each and every encrypted character.
        int e = 0;
        string plaintext = get_string("Enter text: ");
        printf("ciphertext: ");
        for (int i = 0; i < strlen(plaintext); i++)
        {
            e = encrypt(plaintext[i], atoi(argv[1]));
            printf("%c", e);
        }
        printf("\n");
    }
}
//Ecrypt function defined.
char encrypt(char letter, int key)
{
    int encrypted = 0;

//Checks if the character is an uppercase or lowercase letter and uses the appropiate base for each one.
    if (islower(letter))
    {
        encrypted = ((((letter + key) - BASELOW) % 26) + BASELOW);
    }
    else if (isupper(letter))
    {
        encrypted = ((((letter + key) - BASECAP) % 26) + BASECAP);
    }
    else
    {
        //If it's not a lowercase or uppercase letter, it will return the original value, perserving non-alphabetical characters.
        encrypted = letter;
    }
    return encrypted;
}