#include "adjacencyMatrix.h"
#include "valconvert.h"
#include <stdio.h>
#include <stdbool.h>
#include "Errormsg.h"

typedef struct Q {
    cell_t* cells; // Kolejka przechowuje instancje struktury komorki
    int size; // Liczba komorek w kolejce 
    int maxSize;
} Q;

Q initQ(int height, int width){
    Q queue; 
    queue.cells = malloc(height * width *sizeof(cell_t));
    if (queue.cells == NULL) {
        errorcomm(3);
        return;
    }
    queue.size = 0;
    queue.maxSize = height * width;

    return queue;
}

void enqueue(Q* queue, cell_t cell) {
    queue->cells[queue->size++] = cell;
}

// Usuwa komorke o najwiekszej calkowitej wadze z konca kolejki
cell_t dequeue(Q* queue) {
    if (queue->size == 0) {
        errorcomm(4);
        return;
    }
    cell_t cell = queue->cells[0];
    for (int i = 0; i < queue->size - 1; i++) {
        queue->cells[i] = queue->cells[i + 1];
    }
    queue->size--;
    return cell;
}

// Sprawdza czy kolejka jest pusta
bool isQueueEmpty(Q* queue) {
    return queue->size == 0;
}

// Sprawdza czy dana komorka jest dodana do kolejki
bool isInQueue(Q* queue, cell_t cell) {
    for (int i = 0; i < queue->size; i++) {
        if (queue->cells[i].numer == cell.numer) {
            return true;
        }
    }
    return false;
}

void freeQueue(Q* queue) {
    free(queue->cells);
    free(queue);
}

void usuwaniewagonika(cell_t **labirynt, int komorkah, int komorkaw, int numerwagonika){
    cell_t *curwagon=labirynt[komorkah][komorkaw].next;
    cell_t *replacewagon=NULL;
    cell_t *tempwagon=NULL;
    while (curwagon!=NULL)
    {
        if(curwagon->numer!=numerwagonika){
            tempwagon=curwagon;
            tempwagon->next=replacewagon;
            replacewagon=tempwagon;
        }
    }
    labirynt[komorkah][komorkaw].next=replacewagon;
}

bool isInCell_t(cell_t* cells, int numer) {
    cell_t* current = cells;
    while (current != NULL) {
        if (current->numer == numer) 
            return true;
        current = current->next;
    }
    return false;
}

void removecopies(cell_t **labirynt, int width, int height, int start){
    // int startheight=start/width;
    // int startwidth=start%width;
    // cell_t currentcell=labirynt[startheight][startwidth];
    // cell_t *connections=currentcell.next;
    // while(connections!=NULL){
    //     usuwaniewagonika(labirynt, connections->numer/width, connections->numer%width, start);
    //     removecopies(labirynt, width, height, connections->numer);
    //     connections=connections->next;
    // }

    Q queue = initQ(height, width);
    Q queueNext = initQ(height, width);
    cell_t visited;
    visited.numer = -1;
    visited.next = NULL;

    enqueue(&queue, labirynt[start / width][start % width]);

    while(!isQueueEmpty(&queue)){
        cell_t currentCell = dequeue(&queue);
        cell_t *temp = malloc(sizeof(cell_t));
        temp->numer = visited.numer;
        temp->next = visited.next;
        visited = currentCell;
        visited.next = temp;
        if(temp->numer != -1){
            visited.next = temp;
        } else {
            visited.next = NULL;
        }
    }
}

void conv2graph(cell_t **labirynt, int width, int height, int start){
    removecopies(labirynt, width, height, start);
}

