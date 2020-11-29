#ifndef MODEL_STRUCT_PARAM
#define MODEL_STRUCT_PARAM 1

struct Dish {
    char name[255];
    int price, quantity;
    Dish *prev, *next;
};
//*headDish, *tailDish, *currDish, *newDish, *delDish

struct Order {
    char name[255];
    int quantity, price;
    Order *prev, *next;
};
//*newOrder, *currOrder, *delOrder

struct Customer {
    char name[255];
    Order *headOrder, *tailOrder;
    Customer *prev, *next;    
}*CustomerHead[26], *CustomerTail[26];
//, *currCustomer, *newCustomer, *delCustomer

#endif