#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Get input text from user
    string text = get_string("Text: ");

    int letters = 0;
    int words = 1; // Start at 1 since last word won't have a trailing space
    int sentences = 0;

    // Loop through each character in the string
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // Count letters
        if (isalpha(text[i]))
        {
            letters++;
        }
        // Count words (spaces separate words)
        else if (text[i] == ' ')
        {
            words++;
        }
        // Count sentences (., !, ?)
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }

    // Calculate L and S values
    float L = (float) letters / words * 100;
    float S = (float) sentences / words * 100;

    // Coleman-Liau index formula
    float index = 0.0588 * L - 0.296 * S - 15.8;

    // Round index to nearest integer
    int grade = round(index);

    // Print grade level according to rules
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}
