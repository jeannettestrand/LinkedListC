#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/* Add an item to the rear of the dynamically-allocated queue.
 * Returns:  pointer to the item if successful, NULL if not */
ItemType * enqueue (Queue *queue, ItemType *item){  
   
    // Allocate memory space for the newNode
    ListNode *newNode = malloc (sizeof(ListNode));
    if (newNode == NULL){
        // If next is null, allocation failed, return NULL
        return NULL;
    }
    newNode->item = item;
    newNode->next = NULL;
    
    // If q is Empty, point front at newNode memory Address
    // otherwise, it is attached to the end of the queue
    if (queue->front == NULL){
      queue->front = newNode;
    } else {
      queue->rear->next = newNode;
    }

    // Always point the queue.rear at newNode memory Address
    queue->rear = newNode; 

    // Increment size property
    queue->size++;  

    // Return item
    return item;                   
}

/* Removes an item from the front of the queue.
 * Returns:  pointer to the item if successful, NULL if empty */
ItemType * dequeue (Queue *queue) {
    // If q is empty, return Null
    if (queue->front == NULL) {
        return NULL;
    }
    // Retrieve and save item forreturn from function
    ItemType *oldNode = queue->front->item;   
    
    // Set up a pointer to the ListNode to be returned to the heap - release from memory
    ListNode *removeNode = queue->front;
    
    // Point front at
    queue->front = queue->front->next; 
    
    free(removeNode);
    
    queue->size--;                        
    return oldNode;                        
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