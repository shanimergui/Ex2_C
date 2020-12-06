#include "myBank.h"
# include <stdio.h>


// we defined matrix
double numberAccount [50][3];


//   i                1               2
// {accountNumber, openOrNotOpen , sumInTheCount}

// initialization
void init(){
        int count = 901;
        for ( int i=0; i<50; i++) {
                numberAccount[i][0] = count;
                count++;
                numberAccount[i][1] = 0;
                numberAccount [i][2] =0; // how much money do i have in mind
        }
}

// 0 - not in use
void openAnAccount (){ // to check if the account is open
        double amount;
        printf("Please enter amount for deposit: ");
        if(scanf("%lf", &amount)!=1) {
                printf("Failed to read the amount\n");
        }else{
                if(amount<0) {
                        printf("Failed to read the amount\n");
                }else{
                        for( int i = 0; i<50; i++) {
                                if(numberAccount[i][1] == 0) {
                                        numberAccount[i][1]=1;
                                        numberAccount[i][2]=amount;
                                        printf ("New account number is: %.0f \n",numberAccount[i][0]);
                                        break;
                                }
                        }
                }
        }
}

void balanceInquriy (){
        int accountNumber;
        printf("Please enter account number: ");
        if(scanf("%d", &accountNumber)!=1) {
                printf("Failed to read the account number\n");
        }else{
                for(int i = 0; i < 50; i++) {
                        if(numberAccount[i][0]==accountNumber) {
                                if(numberAccount[i][1]==0) {
                                        printf("This account is closed\n");
                                }else{
                                        printf ( "The balance of account number %.0f is: %.2f\n",numberAccount[i][0],numberAccount[i][2]);
                                        break;
                                }
                        }
                }
        }
}

void deposit (){
        double sumDeposit;
        int accountNumber;
        printf("Please enter account number: ");
        if(scanf("%d", &accountNumber)!=1) {
                printf("Failed to read the account number\n");
        }else {
                printf("Please enter the amount to deposit: ");
                if(scanf("%lf", &sumDeposit)!=1) {
                        printf("Failed to read the amount\n");
                }else{
                        for(int i = 0; i < 50; i++) {
                                if(numberAccount[i][0]==accountNumber) {
                                        if(numberAccount[i][1]==1) {
                                                numberAccount[i][2]+= sumDeposit;
                                                printf ( "The new balance is: %.2f\n",numberAccount[i][2]);
                                        }else{
                                                printf("This account is closed\n");
                                        }
                                        break;
                                }
                        }
                }
        }
}


void attraction (){
        double sumAttraction;
        int accountNumber;
        printf("Please enter account number: ");
        if(scanf("%d", &accountNumber)!=1) {
                printf("Failed to read the account number\n");
        }else {
                printf("Please enter the amount to withdraw: ");
                if(scanf("%lf", &sumAttraction)!=1) {
                        printf("Failed to read the amount\n");
                }else{
                        for(int i = 0; i < 50; i++) {
                                if(numberAccount[i][0]==accountNumber ) {
                                        if(numberAccount[i][1]==1) {
                                                if((numberAccount[i][2]- sumAttraction)>0) {
                                                        numberAccount[i][2]-= sumAttraction;
                                                        printf ( "The new balance is: %.2f\n",numberAccount[i][2]);
                                                }else {
                                                        printf ( "Cannot withdraw more than the balance\n");
                                                }
                                        }else{
                                                printf("This account is closed\n");
                                        }
                                        break;
                                }
                        }
                }
        }
}

void accountClosing (){
        int accountNumber;
        printf("Please enter account number: ");
        if(scanf("%d", &accountNumber)!=1) {
                printf("Failed to read the account number\n");
        }else{
                for(int i = 0; i < 50; i++) {
                        if(numberAccount[i][0]==accountNumber) {
                                numberAccount[i][1]=0;
                                numberAccount[i][2]=0;
                                break;
                        }
                }
        }
}

void interest (){
        double rest;
        printf("Please enter interest rate: ");
        if(scanf("%lf", &rest)!=1) {
                printf("Failed to read the amount\n");
        }else{
                for(int i = 0; i < 50; i++) {
                        if(numberAccount[i][1] == 1) {
                                numberAccount[i][2]*= ((rest/100)+1);
                        }
                }
        }
}

void printOpenAccountAndTheBalance (){

        for(int i = 0; i < 50; i++) {
                if(numberAccount[i][1] == 1) {
                        printf ( "The balance of account number %.0f is: %.2f\n",numberAccount[i][0],numberAccount[i][2]);
                }
        }
}

void closes(){
        for(int i = 0; i < 50; i++) {
                if((numberAccount [i][1]==1)) {
                        numberAccount[i][1]=0;
                        numberAccount[i][2]=0;
                }
        }
}
