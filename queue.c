
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/* Add an item to the rear of the dynamically-allocated queue.
 * Returns:  pointer to the item if successful, NULL if not */
ItemType * enqueue (Queue *queue, ItemType *item){  
   
    // Allocate memory space for the property next of ListNode
    struct listNode *next = malloc (sizeof(struct listNode));
    if (next == NULL){
        // If next is null, allocation failed, return NULL
        return NULL;
    }
    
    // Initialize the new ListNode with next and item property pointers
    ListNode newNode = {next, item};
    printf("new node mem addr: %x\n", &newNode); 
    printf("new node.next mem addr: %x\n", &newNode.next);
    printf("new nodenext value: %x\n", newNode->next);
    printf("new nodeitem mem addr: %x\n", &newNode.item);
    printf("new nodenext value: %x\n", newNode->next);
    
    
    
    // If q not empty, point rear.next at newNode memory Address
    if (queue->rear != NULL){         
        queue->rear->next = &newNode;     
    }   
    // Point the queue.rear at newNode memory Address
    queue->rear = &newNode; 
    // If q is Empty, point front at newNode memory Address
    if (queue->front == NULL){
        queue->front = &newNode;
    }
    // Increment size property
    queue->size++;  
    return newNode.item;                   
}

/* Removes an item from the front of the queue.
 * Returns:  pointer to the item if successful, NULL if empty */
ItemType * dequeue (Queue *queue) {
    // If q is empty, return Null
    if (queue->front == NULL) {
        return NULL;
    }
    // Retrieve and save item to remove and return (main frees space)
    ItemType *oldNode = queue->front->item;   
    
    // Point front at
    queue->front = queue->front->next;       
    queue->size--;                        
    return oldNode;                        
}

/* Returns:  number of items in the queue */
int queueSize (const Queue queue) {
    return queue.size;
}

/* Print the contents of the queue to the specified stream */
void printQueue (const Queue queue, FILE *stream) {
    ListNode *curr = queue.front;
    fprintf(stream, "starting the print");
    fprintf(stream, "%d", queue.front->item);
    while (curr->next != NULL) {
        fprintf(stream, "%d", curr->item);
        struct listNode *curr = curr->next;
    }
}

    

