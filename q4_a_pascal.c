#include <stdio.h>

int factorial(int n); //prototype
//The function can calculate the result of factorial n * (n-1) * (n-2) * ... * 1.
int factorial(int n){
    int product = 1;
    //product = n * (n-1) * (n-2) * (n-3) * ... * 1; -------> factorial;
    //Use for loop to iterative and store the result.
    for(int i = n; i > 1; --i ){
        product = product * i;
    }
    //Finally, return the result.
    return product;
}

int formula(int n, int k); //prototype
//The function can calculate the formula result. That is n! / (k! * (n-k)!)
int formula(int n, int k){
    int formula_result = factorial(n) / (factorial(k) * factorial(n-k));
    //Then return the formula result.
    return formula_result;
}

int main(int argc, char*argv[]){
    // Store the variable
    int formula_result;
    int final_result;
    int n;
    int k;
    printf("Please enter the number of rows and the value of K\n");
    printf("n: \n");
    // scan the number of n.
    scanf("%d",&n);
    printf("k: \n");
    scanf("%d",&k);
    formula_result = formula(n,k);
    printf("Therefore, the formula result is %d. \n", formula_result);
    printf("\n");
    //If n equals to 0 or 1, then print 1 or 1 1
    if(n == 0){
        printf("\n 1 \n");
    }
    else if(n == 1){
        printf("\n 1 1 \n");
    }
    // If n more than 1, the use for loop and call the formula();
    else if(n > 1){
        printf("All the values for a given row of Pascal’s triangle:");
        printf("\n 1 ");
        for(int i = 1; i <= n; i ++){
            final_result = formula(n, i);
            //  print out all the values for a given row of Pascal’s triangle.
            printf(" %d ", final_result);
        }
        printf("\n");
    }
    else{
        printf("Error");     //If n is other number, then hint error.
    }
    return 0;
}
