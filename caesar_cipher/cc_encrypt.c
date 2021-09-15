#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/*defining macros*/
#define MAX 26
#define MIN 0
#define MAX_MESSAGE 80
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
/*function used in the main*/
int encrypter(char a[], char b[], int k, int s);
int flushing();

int main()
{

    char enteredMessage[80];
    int key, read, rc;
    char abc[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    /*abc charachters entered as abc[]*/
    int sizeA;
    sizeA = strlen(enteredMessage);

    /*do while loop for user to enter correct input*/
    do
    {
        printf("Enter message to encrypt: ");

        rc = scanf("%80[^\n]s", enteredMessage);
        /* scanf limiting to 80 chars */
        sizeA = strlen(enteredMessage);
        while (getchar() != '\n')
        /* scanf stops when new line pressed */
        {
        }
        if (rc == '\0' || enteredMessage[0] == ' ' || enteredMessage[0] == '\t')
        {
            printf("Please enter a message\n");
            rc = 0;
        }

    } while (rc != 1);

    while (13) /*while loop to get the correct rotation key*/
    {
        printf("Enter rotation key: ");
        read = scanf("%d", &key);

        if (read == 1)
        {
            if (key >= MIN && key <= MAX)
            /*setting boundaries for rotation key*/
            {
                printf("Encrypting message (key = %d): %s\n", key, enteredMessage);
                encrypter(enteredMessage, abc, key, sizeA);
                printf("\n");
                break;
                /*if rotation key is in boundaries, encrypter function called, and output*/
            }
            else
            {
                printf("Error - key must be in range 0 and 26.Try again.\n");
                flushing();
            }
        }
        else
        {
            printf("Error - key must be in range 0 and 26.Try again.\n");
            flushing();
        }
    }
    return EXIT_SUCCESS;
}

int encrypter(char enteredMessage[], char abc[], int key, int sizeA)
{
    /*encrypt function to find the entered char's location in alphabet and adding rotation key to that location, then output the rotated char*/
    int y, i, rotated;
    for (i = 0; i < sizeA; i++)
    {
        if (enteredMessage[i] == '\n')
        {
            break;
        }
        else if (isdigit(enteredMessage[i]))
        {
            /*if thec char is digit. print as it is*/
            printf("%c", enteredMessage[i]);
        }
        for (y = 0; y < MAX; y++)
        {

            if (ispunct(enteredMessage[i]))
            {
                /*if input includes puctiation, it outputs as it is*/
                printf("%c", enteredMessage[i]);
                break;
            }
            else if (tolower(enteredMessage[i]) == abc[y])
            {
                /*if charachter in input is lower*/
                rotated = y + key;
                if (rotated >= MAX)
                {
                    rotated -= MAX;
                    /*if new rotation is bigger than number of charachters in alphabet, 26 subtracted so rotation starts from the begining of alphabet*/
                }
                if (isupper(enteredMessage[i]))
                {
                    /*if charachter is upper, print rotated charachter as upper case*/
                    printf("%c", toupper(abc[rotated]));
                }
                else
                {
                    printf("%c", abc[rotated]);
                }
            }
            else if (enteredMessage[i] == ' ')
            {
                /*if there is a space in the mesage, print space at is*/
                printf(" ");
                break;
            }
        }
    }
    return EXIT_SUCCESS;
}

/*flush function to get rid of char stuck in scanf method*/
int flushing()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    return EXIT_SUCCESS;
}
