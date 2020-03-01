#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void creditPrinter(){   //function to display credits
    printf("Calculator From File\n"); // name of the application
    printf("By HAKKI ULKU 172010010024\n"); // Name of the developer
    printf("With Calculator From File, you can import some data from a file and use those numbers of data to compute mean value\nand standard deviation of the set."); // short description of the program
    printf("\nAs instruction, \nyou need to make a file which is in the same folder with your program and name of the file should be Data.txt,\nthen you will have the result.txt after running the program\n"); //instructions for the program
    printf("------------------------------------------------------------------------------------------------------------------------");
}
float calculateSDEV(float mean, float *arrayForSDEV, int size){
    float SDEV=0;
    if(size ==1){ // if there is only one element in the set, there is no standard deviation
        return 0;
    }
    for(int n=0; n<size; n++){
        SDEV+= pow((arrayForSDEV[n]-mean), 2);
    }
    return sqrt( (SDEV/(size) ) );
}
int main()
{
    creditPrinter();
    float val;
    FILE* fp = fopen("Data.txt", "r");
    if (fp == NULL){
        printf("Could not read file for reading!\n");
        exit(1);
    }
    int count=0; // counts the number of numbers in the Data.txt

    while (!feof(fp)){ // counts how many numbers there are in the file
        fscanf(fp, "%f\n", &val);
        count++;
    }

    float allNum[count];
    rewind(fp);
    count=0;
    while (!feof(fp)){ // takes all numbers in the file to the array called 'allNum'
        fscanf(fp, "%f\n", &val);
        allNum[count]=val;
        count++;
    }

    FILE* fw = fopen("result.txt", "w");

    for(int i=0; i<count; i--){
        float sum=0;
        float arrayForSDEV[(int) allNum[i]]; // array to calculate standard deviation
        int m;
        for(m=0; m<allNum[i]; m++){
            sum+=(allNum[i+m+1]);
            arrayForSDEV[m]=allNum[i+m+1]; // puts the values from the line to the array for calculating standard deviation
        }

        fprintf(fw, "Mean: %f\t", sum/allNum[i]); // calculates the mean value and writes to the result.txt
        fprintf(fw, "Standard Dev: %f\n", calculateSDEV(sum/allNum[i], arrayForSDEV, (int)allNum[i]));
        i+=(allNum[i]+2); // this takes the index to the new line's beginning
    }

    return 0;
}
