#include "adjacencyMatrix.h"
#include "valconvert.h"
#include <stdio.h>
#include <stdbool.h>


typedef struct PriorityQueue {
    cell_t* cells; // Kolejka przechowuje instancje struktury komorkiei
    float* priorities; // Priorytety komorek labiryntu, zalezne od wagi w danej komorce
    int size; // Liczba komorek w kolejce 
} PriorityQueue;

// Dodaje komorke wraz z jej waga (jako priorytet) do kolejki
void enqueue(PriorityQueue* queue, cell_t cell, int priority) {
    int i;
    // Znajdowanie odpowiedniej pozycji dla komorki w kolejce wg. jej priorytetu
    // Ustawia priorytety komorek wg. zmiennej totalWeight rosnaco
    for (i = queue->size; i > 0 && queue->priorities[i - 1] > priority; i--) {
        queue->cells[i] = queue->cells[i - 1];
        queue->priorities[i] = queue->priorities[i - 1];
    }

    // Wstawienie komorki do kolejki
    queue->cells[i] = cell;
    queue->priorities[i] = priority;
    queue->size++;
}

// Usuwa komorke o najwiekszej calkowitej wadze z konca kolejki
cell_t dequeue(PriorityQueue* queue) {
    if (queue->size == 0) {
        printf("Zbyt malo elementow w kolejce\n");
        exit(1);
    }
    // Zmniejsza rozmiar kolejki o jedna komorke
    // Zwraca wartosc ostatniej komorki
    return queue->cells[--queue->size];
}

// Sprawdza czy kolejka jest pusta
bool isQueueEmpty(PriorityQueue* queue) {
    return queue->size == 0;
}

// Sprawdza czy dana komorka jest dodana do kolejki
bool isInQueue(PriorityQueue* queue, cell_t cell) {
    for (int i = 0; i < queue->size; i++) {
        if (queue->cells[i].i == cell.i && queue->cells[i].j == cell.j) {
            return true;
        }
    }
    return false;
}

// Zmienia wartosc priorytetu danej komorki
void updatePriority(PriorityQueue* queue, cell_t cell, int newPriority) {
    for (int i = 0; i < queue->size; i++) {
        if (queue->cells[i].i == cell.i && queue->cells[i].j == cell.j) {
            queue->priorities[i] = newPriority;
            break;
        }
    }
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

void removecopies(cell_t **labirynt, int width, int height, int start){
    int startheight=start/width;
    int startwidth=start%width;
    cell_t currentcell=labirynt[startheight][startwidth];
    cell_t *connections=currentcell.next;
    while(connections!=NULL){
        usuwaniewagonika(labirynt, connections->numer/width, connections->numer%width, start);
        removecopies(labirynt, width, height, connections->numer);
        connections=connections->next;
    }
}

void conv2graph(cell_t **labirynt, int width, int height, int start){
    removecopies(labirynt, width, height, start);
}

