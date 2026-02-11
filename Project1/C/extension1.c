/**
 * Extension 1: Make task 5 more robust
 * Mickey Zhang
 * 2/8/26
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 
 /**
  * This creates a definition for the struct Account.
  *
  * Note that balance (an int) is saved after name in memory.
  */
 typedef struct Account {
     char name[10];
     int balance;
 } Account;
 
 int main(int arg, char *argv[]) {
     Account newAccount = {"", 0};

     /**
      * Very simply cuts off any character after the maximum allowed chars for name
      */
     printf("Please input your name for a new bank account: ");
    
     // here add's a 9 following the % assignation
     scanf("%9[^\n]s", newAccount.name);
     printf("Thank you %s, your new account has been initialized with balance %d. \n",
            newAccount.name, newAccount.balance);
                      
     return 0;
 }