#include <stdio.h>
#include <stdlib.h>

int main()
{
    int loopBoolean = 1;
    int phoneNumber;
    long enteredDigits;

    while (loopBoolean == 1)
    { /*while loop for looping program again*/
        int count = 0;
        printf("Enter a phone number:  ");
        scanf("%d", &phoneNumber);
        /*asking user to enter phone number and assigning it to &phoneNumber*/
        enteredDigits = phoneNumber;

        if (phoneNumber == 0)
        {
            /*if 0 entered, program will stop*/
            printf("Program ended\n");
            return EXIT_SUCCESS;
        }
        while (enteredDigits != 0)
        { /*while loop for calculating how many digits entered by dividing 10*/
            enteredDigits /= 10;
            count++;
        }
        if (count > 7)
        { /*if entered digits are more than 7, invalid phone number output*/
            printf("Invalid phone number: too many digits\n");
        }
        else if (count < 7)
        { /*if entered digits are less than 7, invalid phone number output*/
            printf("Invalid phone number: too few digits\n");
        }
        else if (count == 7)
        { /*if entered digits equal to 7*/
            if (phoneNumber / 1000000 == 1)
            { /*if first digit is 1, invalid central office code output*/
                printf("Invalid central office code : 1\n");
            }
            else if (phoneNumber / 1000000 == 0)
            { /*if 1st digit is 0, invalid center office output*/
                printf("Invalid central office code : 0\n");
            }
            else
            { /*outputing phone number as 3 digits first, and 4 digits afterwards*/
                printf("%d-%04d\n", (phoneNumber / 10000), (phoneNumber % 10000));
            }
        }
    }
    return EXIT_SUCCESS;
}
