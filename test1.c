#include <stdio.h>
#include <stdlib.h>

//Define a number() function which recursively calculates the sum of all positive integers that have a digital sum of n.

/*
 * parameter 'current' represents the number being generated.
 * parameter 'n' represents the number n.
 * parameter 'sum' is a pointer which represents the sum of numbers.
 */

void number(int current, int n, int *sum)
{
    if(n==0)
    {
        *sum += current; //when n equals to 0, sum = sum + current.
    }
    int i;
    for (i = 1; i <= n; ++i)
    {
        number(current*10+i,n-i, sum); //Call the number() function recursively.
    }
}

//Define a sum() function which can return the sum of all positive integers that have a digital sum of n with no zero in their digits.

int sum(int n)
{
    int sum = 0; //Declare and initialize the int variable sum.
    number(0,n,&sum); //Call the function number().
    return sum; //Return the sum.
}


int main()
{
    int i; //Declare an int variable i. Then i is used to store the scanf() number n.
    printf( "Enter a value: "); //Prompt the user to enter a number n.
    scanf("%d",&i); //Scan the number n and store it into the int variable i.
    printf("The output f(n) for an input %d is:\n", i);
    printf("%d\n",sum(i)); //Call function sum().
    return 0;
}
