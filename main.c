#include <stdio.h>
#include <ctype.h>  // for toupper()
#include <stdlib.h> // for exit()

#include "myBank.h"
#include "myBank.c"

int main(int argc, char const *argv[]) {

        init();
        char choose;

        int flag=1;
        while(scanf(" %c", &choose)!=EOF) {
          printf("\nPlease choose a transaction type:\n O-Open Account\n B-Balance Inquiry\n D-Deposit\n W-Withdrawal\n C-Close Account\n I-Interest\n P-Print\n E-Exit\n");
                switch(choose) {
                case 'O':
                        openAnAccount ();
                        break;
                case 'B':
                        balanceInquriy ();
                        break;
                case 'W':
                        attraction();
                        break;
                case 'D':
                        deposit();
                        break;
                case 'I':
                        interest ();
                        break;
                case 'P':
                        printOpenAccountAndTheBalance();
                        break;
                case 'E':{
                        closes();
                        flag=0;
                        break;
                      }
                case 'C':
                        accountClosing ();
                        break;
                default:
                        printf("Invalid transaction type\n");
                }
                if(flag==0){
                  break;
                }
        }
        return 0;
}
