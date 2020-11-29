#ifndef CUSTOMER_SERVICE_PARAM
#define CUSTOMER_SERVICE_PARAM 1

#include "../model/modelStruct.h"
#include "../tools/stringTools.h"
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

struct Customer* InitializeCustomerNode() {
    return (struct Customer*) malloc(sizeof(struct Customer));
}

struct Customer* CustomerNodeCreate(char *name) {
    struct Customer* inserted = InitializeCustomerNode();

    strcpy(inserted->name, name);
    inserted->headOrder = inserted->tailOrder = NULL;
    inserted->next = inserted->prev = NULL;
    return inserted;
}

void CustomerNodeInsert(struct Customer *inserted){
    int index = DJB2(inserted->name, 26);

    if(CustomerHead[index] != NULL){
        CustomerTail[index]->next = inserted;
        inserted->prev = CustomerTail[index];
        CustomerTail[index] = inserted;
    }
    else{
        CustomerHead[index] = CustomerTail[index] = inserted;
    }
}

void CustomerNodePopHead(int index){
    if(CustomerHead[index] == NULL){
        return;
    }
    if(CustomerHead[index] == CustomerTail[index]){
        CustomerHead[index] = CustomerTail[index] = NULL;
        free(CustomerHead[index]);
    }
    else{
        struct Customer *temp_head = CustomerHead[index];
        temp_head = temp_head->next;
        temp_head->prev = NULL;
        CustomerHead[index] = NULL;
        free(CustomerHead[index]);
        CustomerHead[index] = temp_head;
    }
}

struct Customer* CustomerNodeSearchByName(char *name){
    int index = DJB2(name, 26);

    if(CustomerHead[index] == NULL){
        return NULL;
    }
    
    struct Customer *curr = CustomerHead[index];

    while(curr != NULL){
        if(strcmp(name, curr->name) == 0){
            return curr;
        }
        curr = curr->next;
    }

    return NULL;
}
struct Customer* CustomerHeadNodeSearchByName(char *name){
    int index = DJB2(name, 26);

    if(CustomerHead[index] == NULL){
        return NULL;
    }
    
    struct Customer *curr = CustomerHead[index];

    if(curr != NULL){
        if(strcmp(name, curr->name) == 0){
            return curr;
        }
    }

    return NULL;
}

#endif