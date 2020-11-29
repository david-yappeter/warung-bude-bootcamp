#ifndef UI_VIEW_TOOLS_PARAM
#define UI_VIEW_TOOLS_PARAM 1

#include "../tools/stringTools.h"
#include "../service/dishService.h"
#include "../service/customerService.h"
#include "../tools/clearScreen.h"

//MainMenuView View Of Main Menu
void MainMenuView() {
   printf("%s",
R"(1. Add Dish
2. Remove Dish
3. Add Customer
4. Search Customer
5. View Warteg
6. Order
7. Payment
8. Exit Warteg
>> )");
}

//AddDishView Menu 2
void AddDishView(struct Dish **head, struct Dish **tail) {

   char text[3][100] = {
      "Insert the name of the dish [Lowercase Letters]: ",
      "Insert the price of the dish[1000..50000]: ",
      "Insert the quantity of the dish[1..999]: ",
   };

   char name[150];
   int price, quantity;

   do {
      printf("%s", text[0]);
      scanf("%[^\n]%*c", &name);
   }while(RestrictUpperCase((char *) name) == false);

   while(1){
      printf("%s", text[1]);
      scanf("%d", &price);
      getchar();
      if(price >= 1000 && price <= 50000){
         break;
      }
   }

   do {
      printf("%s", text[2]);
      scanf("%d", &quantity);
      getchar();
   }while(quantity < 1 || quantity > 999);

   struct Dish *NewDishNode = DishNodeCreate((char *)name, price, quantity);

   DishNodePushTail(head, tail, NewDishNode);

   printf("The Dish has been added!\n");
   Valid();
}

//RemoveDishView Remove Dish View
void RemoveDishView(struct Dish **head, struct Dish **tail) {
   int counter = 0;
   struct Dish *curr = (*head);

   printf("\t\tBude's Menu\n");
   printf("===================================================\n");
   printf("No.\tName\t\tQuantity\tPrice\n");
   while(curr != NULL){
      printf("%-7d %-11s %03d Rp%-8d\n", (counter + 1), curr->name, curr->quantity, curr->price);
      curr = curr->next;
      counter++;
   }
   printf("===================================================\n");

   char name[150];

   if(counter == 0){
      printf("No Dish!!!\n");
      Valid();
      return;
   }

   do {
      printf("Insert dish's name to be deleted: ");
      scanf("%[^\n]%*c", &name);
   }while(RestrictUpperCase((char *) name) == false);

   if(DishNodeDeleteByName(head, tail, (char *) name)){
      printf("The dish has been removed!\n");
      Valid();
   }
   else{
      NotValid();
   }
}

void AddCustomerView(){
   
   char customer_name[100];
   while(1){
      printf("Insert the customer's name [Without Space]: ");
      scanf("%[^\n]%*c", &customer_name);

      char *name_duplicate = strdup(customer_name);

      if(RestrictSpace((char *) name_duplicate)){
         break;
      }
   }

   CustomerNodeInsert(CustomerNodeCreate((char *) customer_name));

   printf("Customer has been added!");
   Valid();
}

void SearchCustomerView() {
   char customer_name[150];

   while(1){
      printf("Insert the customer's name to be searched: ");
      scanf("%[^\n]%*c", &customer_name);

      if(RestrictSpace((char *) customer_name)){
         break;
      }
   }
   if(CustomerNodeSearchByName((char *) customer_name) != NULL){
      printf("%s Found\n", customer_name);
      Valid();
   }
   else{
      printf("%s is not present.\n", customer_name);
      Valid();
   }
}

void WartegCustomerListView() {
   printf("Customer's List\n\n");

   int counter = 0;
   
   for(int i = 0; i < 26; i++){
      struct Customer *curr = CustomerHead[i];
      
      // while(curr != NULL){
      //    printf("%d. %s\n", counter + 1, curr->name);
      //    curr = curr->next;
      //    counter++;
      // }
      if(curr != NULL){
         printf("%d. %s\n", i, curr->name);
         counter++;
      }
   }

   if(counter == 0){
      printf("No Customer Available\n");
   }
   Valid();
}

void OrderingView(struct Dish **DishHead, struct Dish **DishTail){
   char customer_name[150];
   int amount;

   struct Customer *curr_customer = NULL;

   while(1){
      printf("Insert the customer's name: ");
      scanf("%[^\n]%*c", &customer_name);

      curr_customer = CustomerHeadNodeSearchByName((char *) customer_name);
      if(curr_customer != NULL){
         break;
      }
      printf("Customer Not Found!\n");
   }

   while(1){
      printf("Insert the amount of dish: ");
      scanf("%d", &amount);
      getchar();
      if(amount >= 0){
         break;
      }
      printf("Not Valid!!\n");
   }

   if(amount == 0){
      printf("No Order Will Be Insert!!!\n");
      Valid();
      return;
   }

   for(int i = 0; i < amount; i++){
      char input[200];
      char *dish_name;
      int many = 0;
      printf("[%d] Insert the dish's name and quantity: ", i + 1);
      scanf("%[^\n]%*c", &input);

      OrderingGetValue((char *)input, &dish_name, &many);


      struct Dish *SearchingDish = DishNodeSearchByName(DishHead, DishTail, dish_name);
      if(SearchingDish != NULL){
         if(SearchingDish->quantity - many < 0){
            printf("%d Dish Stock Available, Not Enough!!\n", SearchingDish->quantity);
            i--;
            continue;
         }
         SearchingDish->quantity -= many;
         struct Order *created_order = OrderNodeCreate((char *) SearchingDish->name, SearchingDish->price , many);
         OrderNodePushTail(&curr_customer->headOrder, &curr_customer->tailOrder, created_order);
      }
      else{
         printf("Dish Name Not Valid!!!\n");
         i--;
      }
   }
   printf("Order success!\n");
   Valid();
}

void PaymentView() {
   int customer_index;
   struct Customer *curr_customer = NULL;
   
   while(1){
      printf("Insert the customer's index: ");
      scanf("%d", &customer_index);
      getchar();

      if(CustomerHead[customer_index] != NULL){
         curr_customer = CustomerHead[customer_index];
         break;
      }

      printf("Customer Index Not Found!!!\n");
   }

   printf("%s\n", curr_customer->name);
   struct Order *curr_customer_order = curr_customer->headOrder;

   int numbering = 1;
   int total = 0;
   while(curr_customer_order != NULL){
      printf("[%d] %s x%d\n", numbering, curr_customer_order->name, curr_customer_order->quantity);
      total += curr_customer_order->price * curr_customer_order->quantity;
      numbering++;
      curr_customer_order = curr_customer_order->next;
   }

   CustomerNodePopHead(customer_index);

   printf("Total: Rp%d", total);
   Valid();
}


#endif