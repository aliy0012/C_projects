#include <stdio.h>

int main()
{

    int age;
    printf("Please enter year you were born: ");
    scanf("%d", &age);
    if (age >= 2021)
    {
        printf("Hello future person, still using C in %d\n", age);
        return 0;
    }
    else if (age < 0)
    {
        printf("ok,ok, we done here..\n");
    }
    else
    {
        age = 2021 - age;

        printf("\nyou are %d years old\n", age);
    }
    return 0;
}