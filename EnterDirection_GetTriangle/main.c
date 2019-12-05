#include <stdio.h>
#include <stdlib.h>

int main()
{
        printf("Enter The Direction Letter See The Direction triangle\n\n");

        printf("By;\n\nHAKKI ULKU \n\nStudent ID: 172010010024\n\n------------------------------------------------------------------------------------------------------------------------\n");

        printf("This Program prints a triangle towards where you have shown to it by some specific letters\n\n\n");//short description of the program

        char x[] = "\\"; // this helps printing "\" sign
        char y[] = "/"; // this helps printing "/" sign
        char z[]= "|"; // this helps printing "|" sign



        printf("Please enter the triangle's direction by using the letters ; u-U, d-D, r-R, l-L  : ");//Usage instruction of the program
        char inputOfUser;
        scanf("%c",&inputOfUser); // takes the answer of user

        switch(inputOfUser){
            case 'u':
            case 'U':
                printf("\n%2s%.1s \n%s%3s \n---- \n\n",y,x,y,x); // prints the upward triangle
                break;

            case 'd':
            case 'D':
                printf("\n____ \n%s%3s \n%2s%.1s \n\n",x,y,x,y); // prints the downward triangle
                break;

            case 'r':
            case 'R':
                printf("\n%s%s \n%s%2s \n%s%2s \n%s%s \n\n",z,x,z,x,z,y,z,y); // prints the rightward triangle
                break;

            case 'l':
            case 'L':
                printf("\n%2s%s \n%s%2s \n%s%2s \n%2s%s \n\n",y,z,y,z,x,z,x,z); // prints the leftward triangle
                break;
            default:
                printf("You should have entered the letters which are given in the order only.\n\n"); // when user enters any other letter than the letters given, it warns the user
                break;
        }


}
