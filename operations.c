#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "flight.h"

int getPriority(char *destination) {
    if (strcmp(destination, "Ninoy Aquino International Airport (NAIA)") == 0)
        return 1;
    else if (strcmp(destination, "Clark International Airport") == 0 || 
             strcmp(destination, "Francisco Bangoy International Airport") == 0 || 
             strcmp(destination, "Iloilo International Airport") == 0)
        return 2;
    else if (strcmp(destination, "Panglao International Airport") == 0 || 
             strcmp(destination, "Sibulan Airport") == 0 || 
             strcmp(destination, "Siquijor Airport") == 0)
        return 3;
    else if (strcmp(destination, "Bicol International Airport") == 0 || 
             strcmp(destination, "Daniel Z. Romualdez Airport") == 0 || 
             strcmp(destination, "General Santos International Airport") == 0 || 
             strcmp(destination, "Zamboanga International Airport") == 0)
        return 4;
    else if (strcmp(destination, "Bantayan Airport") == 0 || 
             strcmp(destination, "Bulan Airport") == 0 || 
             strcmp(destination, "Iba Airport") == 0 || 
             strcmp(destination, "Hilongos Airport") == 0)
        return 5;
    else if (strcmp(destination, "Alto Airfield") == 0 || 
             strcmp(destination, "Amoroy Airstrip") == 0)
        return 6;
    return 7;
}

void initQueue(PriorityQueue *pq) {
    pq->size = 0;
}

void swap(Flight *a, Flight *b) {
    Flight temp = *a;
    *a = *b;
    *b = temp;
}

void insertFlight(PriorityQueue *pq, Flight flight) {
    if (pq->size >= MAX_FLIGHTS) {
        printf("Priority Queue is full!\n");
        return;
    }
    pq->heap[pq->size] = flight;
    int current = pq->size;

    while (current > 0 && pq->heap[current].priority < pq->heap[(current - 1) / 2].priority) {
        swap(&pq->heap[current], &pq->heap[(current - 1) / 2]);
        current = (current - 1) / 2;
    }
    pq->size++;
}

Flight removeFlight(PriorityQueue *pq) {
    if (pq->size <= 0) {
        printf("Priority Queue is empty!\n");
        Flight emptyFlight = {"", "", "", "", -1};
        return emptyFlight;
    }
    Flight root = pq->heap[0];
    pq->heap[0] = pq->heap[pq->size - 1];
    pq->size--;

    int current = 0;
    while (1) {
        int left = 2 * current + 1;
        int right = 2 * current + 2;
        int smallest = current;

        if (left < pq->size && pq->heap[left].priority < pq->heap[smallest].priority)
            smallest = left;
        if (right < pq->size && pq->heap[right].priority < pq->heap[smallest].priority)
            smallest = right;
        if (smallest == current)
            break;
        swap(&pq->heap[current], &pq->heap[smallest]);
        current = smallest;
    }

    return root;
}

void displayFlights(PriorityQueue *pq) {
	printf("--------------------------------------------------------\n\n");
    printf("FLIGHTS IN PRIORITY QUEUE\n\n");
    int i;
    for (i = 0; i < pq->size; i++) {
        printf("Flight Code: %s, \nAircraft: %s, \nSchedule: %s, \nDestination: %s, \nPriority: %d\n\n",
               pq->heap[i].flightCode, pq->heap[i].aircraft, pq->heap[i].schedule, pq->heap[i].destination, pq->heap[i].priority);
    }
    printf("--------------------------------------------------------\n");
}

