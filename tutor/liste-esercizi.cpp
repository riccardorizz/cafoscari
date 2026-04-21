#include <iostream>
#include <stdexcept>
using namespace std;

// 1. Devi avere la struttura della cella
struct cell {
    int value;
    cell* next;
};

// 2. Devi avere la definizione della classe
class ll {
public:
    int sum_rec(cell* curr) const; // Dichiari che esiste la funzione
    // ... altre funzioni ...
private:
    cell* head;
};

// 3. ORA puoi scrivere il codice della funzione
int ll::sum_rec(cell* curr) const {
    if(curr == nullptr){
        return 0;
    }
    return curr->value + sum_rec(curr->next);
}