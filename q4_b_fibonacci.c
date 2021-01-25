/*
 * ID:u2024013
 * Name:Yijie Geng
 * Preamble: This program aims to find the calculates the solution to the above formula,
 * thus producing the nth Fibonacci number as output.
 */


#include <stdio.h>
//The function can calculate the result of factorial n * (n-1) * (n-2) * ... * 1.
int factorial(int i); //prototype
int factorial(int i){
    int j;
    int product=1;
    //product = n * (n-1) * (n-2) * (n-3) * ... * 1; -------> factorial;
    //Use for loop to iterative and store the result.
    for(j=1;j<=i;j++)
        product=product*j;
    return product;
}
int fibonacci(int n, int k); //prototype
//The function can calculate the formula result. That is n! / (k! * (n-k)!)
int fibonacci(int n, int k){
    int formula_result = factorial(k)/(factorial(n)*factorial(k-n));
    return formula_result;
}
//calculate the final result of this formula.
int main(){
    //Split formula: part1 = (n-1)/2, part2 = (n-k-1)
    int part1,part2,k,n;
    int final_result=0;
    printf("Please enter a number n: ");
    scanf("%d",&n);
    part1= (n-1) / 2;
    //use for loop to calculate the result.
    for(k=0;k<=part1;k++){
        part2=n-k-1;
        //call fibonacci();
        final_result=final_result+fibonacci(k,part2);
    }
    printf("Therefor, the solution to the above formula is %d",final_result); // print the result.
    printf("\n");
    return 0;
}