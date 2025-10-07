#include <cs50.h>   // For get_string
#include <ctype.h>  // For isalpha, toupper, tolower
#include <stdio.h>  // For printf
#include <string.h> // For strlen

bool is_valid_key(string key);

int main(int argc, string argv[])
{
    // Check for correct number of arguments
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];

    // Validate key
    if (!is_valid_key(key))
    {
        printf("Key must contain 26 unique alphabetic characters.\n");
        return 1;
    }

    // Get plaintext input
    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");

    // Loop through each character of plaintext
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        char c = plaintext[i];

        if (isupper(c))
        {
            // Find alphabetical index (0-25)
            int index = c - 'A';
            // Substitute using uppercase version of key
            printf("%c", toupper(key[index]));
        }
        else if (islower(c))
        {
            int index = c - 'a';
            // Substitute using lowercase version of key
            printf("%c", tolower(key[index]));
        }
        else
        {
            // Leave non-alphabetical characters unchanged
            printf("%c", c);
        }
    }

    printf("\n");
    return 0;
}

// Function to check if key is valid
bool is_valid_key(string key)
{
    // Key must be exactly 26 characters
    if (strlen(key) != 26)
    {
        return false;
    }

    // Track used letters (case-insensitive)
    bool used[26] = {false};

    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(key[i]))
        {
            return false;
        }

        int index = toupper(key[i]) - 'A';
        if (used[index])
        {
            // Duplicate letter found
            return false;
        }
        used[index] = true;
    }

    return true;
}
