#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/* Add an item to the rear of the dynamically-allocated queue.
 * Returns:  pointer to the item if successful, NULL if not */
ItemType * enqueueRear (Queue *queue, ItemType *item){  
   
    // Allocate memory space for the newNode, initialize properties
    ListNode *newNode = malloc (sizeof(ListNode));
    if (newNode == NULL){
        return NULL;
    }
    newNode->item = item;
    newNode->next = NULL;
    newNode->previous = NULL;
    
    // Attach node to queue structure
    if (queue->front == NULL){
        queue->front = newNode;
    } else {
        newNode->previous = queue->rear;
        queue->rear->next = newNode;
    }
    queue->rear = newNode; 

    queue->size++;  
    return item;                   
}
ItemType * enqueueFront (Queue *queue, ItemType *item){  
   
    // Allocate memory space for the newNode, initialize properties
    ListNode *newNode = malloc (sizeof(ListNode));
    if (newNode == NULL){
        return NULL;
    }
    newNode->item = item;
    newNode->next = NULL;
    newNode->previous = NULL;
    
    // Attach node to queue structure
    if (queue->front == NULL){
        queue->rear = newNode;
    } else {
        newNode->next = queue->front;
        queue->front->previous = newNode;
    }
    queue->front = newNode; 
    
    queue->size++;  
    return item;                   
}


/* Removes an item from the front of the queue.
 * Returns:  pointer to the item if successful, NULL if empty */
ItemType * dequeueFront (Queue *queue) {

    if (queue->front == NULL) {
        return NULL;
    }
    // Remember item and node for memory release
    ItemType *item = queue->front->item;   
    ListNode *removeNode = queue->front;
    
    // Detach Node from Queue Structure
    if (queue->size == 1){
        queue->front = NULL;
        queue->rear = NULL;
    }else {
        queue->front = queue->front->next;
        queue->front->previous = NULL;
    }    
    
    //Release from memory, and complete queue mgmt
    free(removeNode);
    queue->size--;                        
    return item;                        
}
ItemType * dequeueRear (Queue *queue) {
    // If q is empty, return Null
    if (queue->front == NULL) {
        return NULL;
    }
    // Remember item and node for memory release
    ItemType *item = queue->rear->item;   
    ListNode *removeNode = queue->rear;
    
    // Detach node from Queue structure
    printf("%d", queue->size);
    if (queue->size == 1) {
        queue->rear = NULL;
        queue->front = NULL;
    } else {
        queue->rear = queue->rear->previous;
        queue->rear->next = NULL;
    }
    
    //Release from memory, and complete queue mgmt
    free(removeNode);
    queue->size--;                        
    return item;                        
}

/* Returns:  number of items in the queue */
int queueSize (const Queue queue) {
    return queue.size;
}

/* Print the contents of the queue to the specified stream */
void printQueue (const Queue queue, FILE *stream) {
    struct listNode *next = queue.front;
    while (next != NULL) {
        fprintf(stream, "%d\n", *next->item);   
        next = next->next;
    }
}