#include <stdio.h>

int func(int num1, int num2)
{

    return num1 + num2;
};

int main(void)
{
    int num1 = 1, num2 = 1, result;

    int (*function)(int , int );

    function = func;

    result = function(num1, num2);

    printf("O resultado: %d", result);
}