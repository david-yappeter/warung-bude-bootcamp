#ifndef DISH_SERVICE_PARAM
#define DISH_SERVICE_PARAM 1

#include "../model/modelStruct.h"
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

//Create
struct Dish* InitializeDishNode();
struct Dish* DishNodeCreate(char *name, int price, int quantity);

//To-Do
void DishNodePushHead(struct Dish **head, struct Dish **tail, struct Dish *inserted);
void DishNodePushTail(struct Dish **head, struct Dish **tail, struct Dish *inserted);
void DishNodePushMid(struct Dish **head, struct Dish **tail, struct Dish *inserted);
void DishNodePopHead(struct Dish **head, struct Dish **tail);
void DishNodePopBack(struct Dish **head, struct Dish **tail);
void DishNodeViewNode(struct Dish **head);
void DishNodeViewNodeReverse(struct Dish **tail);
bool DishNodeDeleteByName(struct Dish **head, struct Dish **tail, char *remove);

//InitializeDishNode Initialize Empty Node
struct Dish* InitializeDishNode() {
    return (struct Dish*) malloc(sizeof(struct Dish));
}

//DishNodeCreate Create Node
struct Dish* DishNodeCreate(char *name, int price, int quantity) {
    struct Dish *inserted = InitializeDishNode();

    strcpy(inserted->name, name);
    inserted->price = price;
    inserted->quantity = quantity;
    inserted->next = NULL;
    inserted->prev = NULL;

    return inserted;
}

//DishNodePushHead Push New Node To Head
void DishNodePushHead(struct Dish **head, struct Dish **tail, struct Dish *inserted) {
    if((*head) == NULL){
        (*head) = (*tail) = inserted;
    }
    else{
        (*head)->prev = inserted;
        inserted->next = (*head);
        (*head) = inserted;
    }
}

//DishNodePushTail Push New Node To Tail
void DishNodePushTail(struct Dish **head, struct Dish **tail, struct Dish *inserted) {
    if((*head) == NULL){
        (*head) = (*tail) = inserted;
    }
    else{
        (*tail)->next = inserted;
        inserted->prev = (*tail);
        (*tail) = inserted;
    }
}

//DishNodePushMid Push Based On Price
void DishNodePushMid(struct Dish **head, struct Dish **tail, struct Dish *inserted) {
    if((*head) == NULL){
        (*head) = (*tail) = inserted;
    }
    else if((*head)->price >= inserted->price){
        DishNodePushHead(head, tail, inserted);
    }
    else if((*tail)->price <= inserted->price){
        DishNodePushTail(head, tail, inserted);
    }
    else{
        struct Dish *curr = (*head);
        while(inserted->price > curr->price){
            curr = curr->next;
        }

        inserted->prev = curr->prev;
        inserted->next = curr; 
        curr->prev->next = inserted;
        curr->prev = inserted;
    }   
}

//DishNodePopHead Pop Head
void DishNodePopHead(struct Dish **head, struct Dish **tail){
    if((*head) == NULL){
        return;
    }
    else if((*head) == (*tail)){
        (*head) = (*tail) = NULL;
        free((*head));
    }
    else{
        struct Dish *curr = (*head);
        curr = curr->next;
        curr->prev = NULL;
        (*head) = NULL;
        free(*head);
        (*head) = curr;
    }
}

//DishNodePopBack Pop Back
void DishNodePopBack(struct Dish **head, struct Dish **tail){
    if((*head) == NULL){
        return;
    }
    else if((*head) == (*tail)){
        (*head) = (*tail) = NULL;
        free((*tail));
    }
    else{
        struct Dish *curr = (*tail);
        curr = curr->prev;
        curr->next = NULL;
        (*tail) = NULL;
        free(*tail);
        (*tail) = curr;
    }
}

//DishNodePopMid Delete Nodes
void DishNodePopMid(struct Dish **head, struct Dish **tail, struct Dish *deleted){
    (*tail)->prev = deleted->prev;
    (*head)->next = deleted->next;
    deleted = NULL;
    free(deleted);
}

//DishNodeViewNode From Head -> Tail
void DishNodeViewNode(struct Dish **head) {
    struct Dish *curr = (*head);

    while(curr != NULL){
        printf("Model {\"name\": \"%s\", \"price\": %d, \"quantity\": %d}\n", curr->name, curr->price, curr->quantity);
        curr = curr->next;
    }
}

//DishNodeViewNodeReverse From Tail -> Head
void DishNodeViewNodeReverse(struct Dish **tail) {
    struct Dish *curr = (*tail);

    while(curr != NULL){
        printf("Model {\"name\": \"%s\", \"price\": %d, \"quantity\": %d}\n", curr->name, curr->price, curr->quantity);
        curr = curr->prev;
    }
}

//DishNodeDeleteByName Delete By Name
bool DishNodeDeleteByName(struct Dish **head, struct Dish **tail, char *remove) {
    if((*head) == NULL){
        return false;
    }
    else if((*head) == (*tail)){
        if(strcmp((*head)->name, remove) == 0) {
            (*head) = (*tail) = NULL;
            free(*head);
            return true;
        }
    }
    else if(strcmp((*head)->name, remove) == 0){
        DishNodePopHead(head, tail);
    }
    else if(strcmp((*tail)->name, remove) == 0) {
        DishNodePopBack(head, tail);
    }
    else{
        struct Dish *curr = (*head);
        while(curr != NULL){
            if(strcmp(curr->name, remove) == 0){
                DishNodePopMid(head, tail, curr);
                return true;
            }
            curr = curr->next;
        }
        return false;
    }
}


//DishNodeDeleteByName Delete By Name
struct Dish* DishNodeSearchByName(struct Dish **head, struct Dish **tail, char *search) {
    if((*head) == NULL){
        return NULL;
    }
    else if((*head) == (*tail)){
        if(strcmp((*head)->name, search) == 0) {
            return (*head);
        }
    }
    else if(strcmp((*head)->name, search) == 0){
            return (*head);
    }
    else if(strcmp((*tail)->name, search) == 0) {
            return (*tail);
    }
    else{
        struct Dish *curr = (*head);
        while(curr != NULL){
            if(strcmp(curr->name, search) == 0){\
                return curr;
            }
            curr = curr->next;
        }
        return NULL;
    }
}

#endif