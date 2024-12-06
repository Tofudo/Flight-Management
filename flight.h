#ifndef FLIGHT_H
#define FLIGHT_H

#define MAX_FLIGHTS 100

typedef struct {
    char flightCode[10];
    char aircraft[20];
    char schedule[20];
    char destination[50];
    int priority;
} Flight;

typedef struct {
    Flight heap[MAX_FLIGHTS];
    int size;
} PriorityQueue;

int getPriority(char *destination);
void initQueue(PriorityQueue *pq);
void swap(Flight *a, Flight *b);
void insertFlight(PriorityQueue *pq, Flight flight);
Flight removeFlight(PriorityQueue *pq);
void displayFlights(PriorityQueue *pq);

#endif

