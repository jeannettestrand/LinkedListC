#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(int ac, char *av[]) {
    
    Queue queue = {NULL, NULL, 0};

    int done = 0;
    while (!done) {
        int choice, nValid;
        do {
            printf("REAR - 0 to remove, 1 to add\nFRONT - 2 to add, 3 to remove\n"
                    "(-1 to quit): ");
            nValid = scanf("%d", &choice);
        } while (nValid != 1 || choice < -1 || choice > 3);

        switch (choice) {
            case 0:
            {
                ItemType *item;
                if ((item = dequeueRear(&queue)) != NULL) {
                    printf("Removed " ITEM_FORMAT "\n", *item);
		    free (item);
                } else {
                    printf("Queue is empty\n");
                }
                

                break;
            }

            case 1:
            {
                ItemType *item = malloc (sizeof(ItemType));
                if (item == NULL) {
                    fprintf(stderr, "%s: Error allocating memory for item.\n", av[0]);
                    return EXIT_FAILURE;
                }

                printf ("Enter " ITEM_PROMPT ": ");
                if (scanf(ITEM_FORMAT, item) != 1) {
                    fprintf(stderr, "Unable to read " ITEM_PROMPT "\n");
                    break;
                }

                if ((item = enqueueRear(&queue, item)) != NULL) {
                    printf("Added " ITEM_FORMAT "\n", *item);
                } else {
                    fprintf(stderr, "%s: Error allocating memory to queue.\n", av[0]);
                    return EXIT_FAILURE;
                }
                

                break;
            }

            case 2:
            {
                ItemType *item = malloc (sizeof(ItemType));
                if (item == NULL) {
                    fprintf(stderr, "%s: Error allocating memory for item.\n", av[0]);
                    return EXIT_FAILURE;
                }

                printf ("Enter " ITEM_PROMPT ": ");
                if (scanf(ITEM_FORMAT, item) != 1) {
                    fprintf(stderr, "Unable to read " ITEM_PROMPT "\n");
                    break;
                }

                if ((item = enqueueFront(&queue, item)) != NULL) {
                    printf("Added " ITEM_FORMAT "\n", *item);
                    printf ("Items remaining in the queue:\n");
                    printQueue (queue, stdout);
                } else {
                    fprintf(stderr, "%s: Error allocating memory to queue.\n", av[0]);
                    return EXIT_FAILURE;
                }
                

                break;
            }
            
            case 3:
            {
                 ItemType *item;
                if ((item = dequeueFront(&queue)) != NULL) {
                    printf("Removed " ITEM_FORMAT "\n", *item);
		    free (item);
                } else {
                    printf("Queue is empty\n");
                }
                break;
                

            }
            
            case -1:
            {
                done = 1;
                break;
            }


            default:
	      fprintf(stderr, "Invalid choice entered");
        }
    }

    printf ("Items remaining in the queue:\n");
    printQueue (queue, stdout);


    return EXIT_SUCCESS;
}

