Due date : May 17, 2021
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    /*integer a initalized for the loop*/
    /*for loop for iterating from 1 to 100*/
    for (a = 1; a < 101; a++)
    {
        /*if remainder of a is 0 when dividing to 5 and 3*/
        if (a % 3 == 0 && a % 5 == 0)
        {
            printf("%d  I'm a multiple of 3 && 5!!!\n", a);
            /*output*/
        }
        else if ((a % 5) == 0)
        /*if remainder of a is 0, when divided to 5*/
        {
            printf("%d  I'm a multiple of 5!!!\n", a);
        }
        else if ((a % 3) == 0)
        /*if remainder of a is 0, when divided to 3*/
        {
            printf("%d  I'm a multiple of 3!!!\n", a);
        }
        else
        {
            /*for numbers which are not divided to 3 or 5*/
            printf("%d\n", a);
        }
    }
    return EXIT_SUCCESS;
}
