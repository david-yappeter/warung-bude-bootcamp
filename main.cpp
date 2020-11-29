#include <stdio.h>
#include <time.h>
#include<stdlib.h>

#include "import/importLib.h"

int main(){

    struct Dish *dishHead = NULL;
    struct Dish *dishTail = NULL;

    for(int i = 0; i < 26; i++){
        CustomerHead[i] = NULL;
        CustomerTail[i] = NULL;
    }

    while(1){
        Clrscr();
        printf("System: %s\n", DetectOS());
        printf("%s\n", GetTimeNow());
        MainMenuView();

        int choice;
        scanf("%d", &choice);
        getchar();

        if (choice == 1) {
            AddDishView(&dishHead, &dishTail);
        }
        else if (choice == 2) {
            RemoveDishView(&dishHead, &dishTail);
        }
        else if (choice == 3) {
            AddCustomerView();
        }   
        else if (choice == 4) {
            SearchCustomerView();
        }
        else if (choice == 5) {
            WartegCustomerListView();
        }
        else if (choice == 6) {
            OrderingView(&dishHead, &dishTail);
        }
        else if (choice == 7) {
            PaymentView();
        }
        else if (choice == 8) {
            break;
        }
        else{
            NotValid();
        }
    
    }

    
    PrintButkemp();
    system("pause");
    return 0;
}