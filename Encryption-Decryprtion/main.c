#include <stdio.h>
#include <stdlib.h>

void creditPrinter(){   //function to display credits
    printf("Brand New Cryptographer\n"); // name of the application
    printf("By HAKKI ULKU 172010010024\n"); // Name of the developer
    printf("With Brand New Cryptographer, you can encrypt and decrypt a number that you choose. \n\n"); // short description of the program
    printf("As instruction, \nyou first need to enter a command 'e,E or d,D' showing whether you want to encrypt or decrypt the number.\nThen, enter the number.\n"); //instructions for the program
    printf("------------------------------------------------------------------------------------------------------------------------");
}

int power(int base,int power){ // multiplies result with base for power times
    int result =1;
    if(power ==0){
        return 1;
    } else{
        for(int i =1; i<power+1; i++){
        result*=base;
        }
    return result;
    }
}

int differenceFunction(int a,int b){ //  function to compute (diff + 10)%10
    return ((a-b+10) % 10);
}

int checker(int input){
    if(input>9){ // checks whether the number is positive and have at least two digits because a number is positive and has two digits when it is greater than 9 as an integer number
        return 1;
    } else {
        return 0;
    }
}

int encryption(input){ // function for encrypting

    int newValue = input%10; // Directly takes the least significant digit

    int x, x_1;
    int i =1; // i will be used to have power of 10 to multiply with the generated number so that it can be added to newValue
    while(input>9){ // loop for making the encrypted value from the input number

        x = input%10;
        input/=10;

        x_1 = input%10;

        int theValue = differenceFunction(x_1, x); // function to compute (diff + 10)%10

        newValue += power(10,i)*(theValue); // adding the generated number to newValue

        i++;
    }
    return newValue; // returns new value which is the encrypted value
}



int decryption(input){ // the function for decryption
    int newValue = input%10; // Takes the least significant digit
    int x, x_1,i;
    i =0;
    while(input>9){

        input/=10;
        x = input%10;

        newValue += power(10,i+1)* ((newValue/(power(10,i)) + x ) % 10); // assigns new value as described in the homework
        i++; // increments i for the sake of the having power of ten
    }
    return newValue;
}

int main()
{
    creditPrinter(); //function to display credits

    printf("\ncommand: "); // asking user to enter a command
    char command;
    scanf("%c",&command);

    int input;

    printf("\nnumber: "); // // asking user to enter a number to crypt
    scanf("%d",&input);

    if(checker(input)){ // checking whether input is positive and has two digits or not by using the function checker declared above

        if(command=='d' || command=='D'){  // checks which command is given and executes according to the command
        printf("\nresult of decryption is %d\n", decryption(input));
        }else if (command=='e' || command=='E'){
        printf("\nresult of encryption is %d\n", encryption(input));
        }

    }else{
            printf("\nplease enter a value which is positive and has at least two digits.");
    }

}
