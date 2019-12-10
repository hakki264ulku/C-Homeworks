#include <stdio.h>
#include <stdlib.h>

void creditPrinter(){   //function to display credits
    printf("Fault Fixer\n"); // name of the application
    printf("By HAKKI ULKU 172010010024\n"); // Name of the developer
    printf("With Fault Fixer, you can fix the mistakes (?*! is written from the keyboard instead of 'the') in your sentences.\nAlso, you can learn the ratio of faulty words and see what they are. \n\n"); // short description of the program
    printf("As instruction, \nyou need to enter the sentence which has the faulty form.\n"); //instructions for the program
    printf("------------------------------------------------------------------------------------------------------------------------");
}

int main()
{

    creditPrinter(); //prints the info about the developer and the application
    printf("please enter the text: ");
    char sentence[250];
    fgets(sentence,sizeof(sentence),stdin); // takes the sentence from the console as a characters array

    for(int u =0; sentence[u]!='\0';u++){
        if(sentence[u] == ' ' && sentence[u+1]==' '){
            printf("Please do not press on space two times successively!"); // if the sentence has two blanks after one another the program stops and warns the user
            return 0;
        }
    }
    char newArray[50][50]; // the words will be stored into this multidimensional array
    int i, k=0, wordCount=0;
    for(i=0; sentence[i]!='\0'; i++){ // splitting the words from the sentence into a new array
        if(sentence[i]==' '){ // if there is a blank it saves the word before blank and changes wordCount to store a new word from the sentence
            newArray[wordCount][k]='\0';
            k=0;
            wordCount++;
            continue; //  for turning back to the beginning of the loop
        }
        newArray[wordCount][k]=sentence[i];
        k++;
    }
    newArray[wordCount][k]='\0'; // new array includes the words separately

    int w, c, count=0;
    for(w=0; w<wordCount+1;w++){ // w hels us to separate the words into different locations for multi dimensional arrays
        for(c=0; newArray[w][c]!='\0'; c++){
            if(newArray[w][c]=='?' && newArray[w][c+1]=='*' && newArray[w][c+2]=='!'){ //the words which include "the"
                printf("\n");
                count++; // counts the number for faulty words
                printf("%s",newArray[w]); // prints the faulty words
                newArray[w][c]='t';
                newArray[w][c+1]='h';
                newArray[w][c+2]='e';
            }
        }
    }

    printf("\nrange:%d/%d\nCorrected: ",count,wordCount+1); //counting the ratio for mistaken words
    for(w=0; w<wordCount+1;w++){//prints the corrected sentence
        printf("%s ",newArray[w]);
    }
    return 0;
}
