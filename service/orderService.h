#ifndef ORDER_SERVICE_PARAM
#define ORDER_SERVICE_PARAM 1

#include "../model/modelStruct.h"
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

//Create
struct Order* InitializeOrderNode();
struct Order* OrderNodeCreate(char *name, int price, int quantity);

//To-Do
void OrderNodePushHead(struct Order **head, struct Order **tail, struct Order *inserted);
void OrderNodePushTail(struct Order **head, struct Order **tail, struct Order *inserted);
void OrderNodePushMid(struct Order **head, struct Order **tail, struct Order *inserted);
void OrderNodePopHead(struct Order **head, struct Order **tail);
void OrderNodePopBack(struct Order **head, struct Order **tail);
void OrderNodeViewNode(struct Order **head);
void OrderNodeViewNodeReverse(struct Order **tail);

//InitializeOrderNode Initialize Empty Node
struct Order* InitializeOrderNode() {
    return (struct Order*) malloc(sizeof(struct Order));
}

//OrderNodeCreate Create Node
struct Order* OrderNodeCreate(char *name, int price, int quantity) {
    struct Order *inserted = InitializeOrderNode();
    
    strcpy(inserted->name, name);
    inserted->price = price;
    inserted->quantity = quantity;
    inserted->next = NULL;
    inserted->prev = NULL;

    return inserted;
}

//OrderNodePushHead Push New Node To Head
void OrderNodePushHead(struct Order **head, struct Order **tail, struct Order *inserted) {
    if((*head) == NULL){
        (*head) = (*tail) = inserted;
    }
    else{
        (*head)->prev = inserted;
        inserted->next = (*head);
        (*head) = inserted;
    }
}

//OrderNodePushTail Push New Node To Tail
void OrderNodePushTail(struct Order **head, struct Order **tail, struct Order *inserted) {
    if((*head) == NULL){
        (*head) = (*tail) = inserted;
    }
    else{
        (*tail)->next = inserted;
        inserted->prev = (*tail);
        (*tail) = inserted;
    }
}

//OrderNodePushMid Push Based On Price
void OrderNodePushMid(struct Order **head, struct Order **tail, struct Order *inserted) {
    if((*head) == NULL){
        (*head) = (*tail) = inserted;
    }
    else if((*head)->price >= inserted->price){
        OrderNodePushHead(head, tail, inserted);
    }
    else if((*tail)->price <= inserted->price){
        OrderNodePushTail(head, tail, inserted);
    }
    else{
        struct Order *curr = (*head);
        while(inserted->price > curr->price){
            curr = curr->next;
        }

        inserted->prev = curr->prev;
        inserted->next = curr; 
        curr->prev->next = inserted;
        curr->prev = inserted;
    }   
}

//OrderNodePopHead Pop Head
void OrderNodePopHead(struct Order **head, struct Order **tail){
    if((*head) == NULL){
        return;
    }
    else if((*head) == (*tail)){
        (*head) = (*tail) = NULL;
        free((*head));
    }
    else{
        struct Order *curr = (*head);
        curr = curr->next;
        curr->prev = NULL;
        (*head) = NULL;
        free(*head);
        (*head) = curr;
    }
}

//OrderNodePopBack Pop Back
void OrderNodePopBack(struct Order **head, struct Order **tail){
    if((*head) == NULL){
        return;
    }
    else if((*head) == (*tail)){
        (*head) = (*tail) = NULL;
        free((*tail));
    }
    else{
        struct Order *curr = (*tail);
        curr = curr->prev;
        curr->next = NULL;
        (*tail) = NULL;
        free(*tail);
        (*tail) = curr;
    }
}

//OrderNodeViewNode From Head -> Tail
void OrderNodeViewNode(struct Order **head) {
    struct Order *curr = (*head);

    while(curr != NULL){
        printf("Model {\"name\": \"%s\", \"price\": %d, \"quantity\": %d}\n", curr->name, curr->price, curr->quantity);
        curr = curr->next;
    }
}

//OrderNodeViewNodeReverse From Tail -> Head
void OrderNodeViewNodeReverse(struct Order **tail) {
    struct Order *curr = (*tail);

    while(curr != NULL){
        printf("Model {\"name\": \"%s\", \"price\": %d, \"quantity\": %d}\n", curr->name, curr->price, curr->quantity);
        curr = curr->prev;
    }
}

#endif