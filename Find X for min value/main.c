#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("MinXGiver\n\n"); // Name of the program
    printf("By Hakki ULKU - 172010010024\n\n"); // Information about the developer
    printf("The programs help getting the minimum value of the x for equations which is in the form of (ax+b)^2\n\n"); // short description
    printf("You just need to supply the values of a and b to the program\n------------------------------------------------------------------------------------------------------------------------\n\n"); // Basic instructions

    printf("Please enter a: "); // asks the value of a from the user
    int a;
    scanf("%d",&a); // takes the value of a from the user

    printf("\nPlease enter b: "); // asks the value of b from the user
    int b;
    scanf("%d",&b); // takes the value of b from the user

    double x = 10; // initial value of x
    double derivative_of_y;
    double x_new;
    double epsilon = 0.0000001;

    while(1<2){

        if(a==0){ // checks whether the value of a is equal to zero, if it is so Program stops and warns the user
            printf("\nYou can't enter 0 for the value of a");
            break;
        }

        derivative_of_y = 2.0*a*(a*x + b); // calculates the derivative of y

        x_new = x - (0.0001)*derivative_of_y; // updates the value of Xt by using Xt-1 and derivative of y


        if(fabs(x_new - x) < epsilon){ // if the difference below a threshold it completes the code

            printf("\nthe minimum value of x is %lf", x_new);
            break;
        }

        x = x_new; // for updating the value of Xt and Xt-1
    }



}
