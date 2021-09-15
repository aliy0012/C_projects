#include <stdio.h>
#include <math.h>
int binaryCalculator(int entry);
/*function to convert binary to decimal*/

int main()
{
        int entry;
        /*initalizing variable for user input*/

        while (entry != 0)
        { /*while loop, till user enters 0 to stop*/
                printf("Enter a binary number: ");
                scanf("%d", &entry);
                /*asking user to enter number and assigning it to &entry variable*/

                if (entry == 0)
                { /*if input 0, progrm will stop*/
                        printf("Program ended\n");
                        return 0;
                }
                printf("The decimal equivalent of %d is %d\n", entry, binaryCalculator(entry));
                /*output is the decimal value processed by binaryCalculation function*/
        }
        return 0;
}

int binaryCalculator(int entry)
{ /*function to called in main*/

        int dec_value = 0;
        int base = 1;
        int remainder;

        while (entry != 0)
        {
                /*while loop will assign remainder value of entry remainder of 10*/
                remainder = entry % 10;
                entry /= 10;
                /*entry is divided with 10 to extract 1 digit from input*/
                dec_value += remainder * base;
                /*decimal value is remainder multiplied with base*/
                base *= 2;
                /*base starts with 2 and multiplied with 2 in each loop*/
        }

        return dec_value;
}
