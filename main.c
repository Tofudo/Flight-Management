#include <stdio.h>
#include "flight.h"


int main() {
    PriorityQueue pq;
    initQueue(&pq);

    Flight f1 = {"PR101", "Airbus A320", "10:00 AM", "Ninoy Aquino International Airport (NAIA)", getPriority("Ninoy Aquino International Airport (NAIA)")};
    Flight f2 = {"DG702", "ATR 72", "12:30 PM", "Panglao International Airport", getPriority("Panglao International Airport")};
    Flight f3 = {"5J110", "Boeing 737", "2:00 PM", "Clark International Airport", getPriority("Clark International Airport")};
    
    insertFlight(&pq, f1);
    insertFlight(&pq, f2);
    insertFlight(&pq, f3);

    displayFlights(&pq);

    printf("\nRemoving highest-priority flight...\n\n");
    Flight removed = removeFlight(&pq);
    printf("Removed Flight: \nFlight Code: %s, \nDestination: %s\n\n\n", removed.flightCode, removed.destination);

    displayFlights(&pq);
    
    printf("\nRemoving highest-priority flight...\n\n");
    removed = removeFlight(&pq);
    printf("Removed Flight: \nFlight Code: %s, \nDestination: %s\n\n\n", removed.flightCode, removed.destination);

    displayFlights(&pq);

    return 0;
}

