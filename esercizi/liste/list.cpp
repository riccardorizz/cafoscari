/*
Svolgere i seguenti esercizi iterativamente e ricorsivemente su liste semplici di interi.
Implementarli come metodi di classe.

Esercizio 1
Scrivi un metodo che calcoli la somma dei numeri pari della lista.

Esercizio 2
Scrivi un metodo che restituisca true se tutti gli elementi della lista sono positivi e pari.

Esercizio 3
Scrivere un metodo che data un intero pos>=0 elimini dalla lista la cella in posizione pos. Se la
rimozione ha successo (la posizione esiste), la funzione ritorna true altrimenti false. Eseguire
lo stesso esercizio (iterativamente) anche per le liste doppiamente concatenate.

Esercizio 4
Scrivere l’overloading dell’operatore == dove due liste sono uguali se e solo se hanno gli
stessi elementi nelle stesse posizioni.

Esercizio 5
Scrivere un metodo che data una somma x, rimuova dalla testa della lista tutti gli elementi
fino ad avvicinarsi il più possibile ad x senza superarlo. Il metodo ritorna il numero di celle
rimosse.

Esercizio 6
Scrivere un metodo che data una somma x, rimuova dalla coda della lista tutti gli elementi
fino ad avvicinarsi il più possibile ad x senza superarlo. Il metodo ritorna la somma delle celle
rimosse.

Esercizio 7
Scrivere un metodo che duplica ogni cella che contiene un elemento dispari. Il metodo
ritorna il numero di celle aggiunte alla lista. Per esempio, la lista 2,7,7,9,8,5 diventa
2,7,7,7,7,9,9,8,5,5.

Esercizio 8
Scrivere un metodo che rimuova dalla lista tutte le celle che contengono numeri uguali
consecuitivi a due a due. Per esempio la lista:
2,7,7,7,7,7,9,9,5 diventa 2,7,5

*/

#include <iostream>
using namespace std;



// Il nodo con doppio puntatore
struct cella {
    int valore;
    cella* next; // Puntatore al nodo successivo
    cella* prev; // Puntatore al nodo precedente
};

class lista_doppia {
private:
    cella* head; // Punta al primo elemento
    cella* tail; // Punta all'ultimo elemento (la "coda")

public:
    // Costruttore
    lista_doppia() {
        head = nullptr;
        tail = nullptr;
    }
    int sommaPari() const;
};
//prepend = inserisci in testa

//append = inserisci in coda
void append(int v){
    cella* nuova = new cella{v,nullptr,tail};
    if(tail!=nullptr){
        tail->next = nuova;
    }
    else{
        head = nuova;
    }
    tail = nuova;
}




// Esercizio 1
// Scrivi un metodo che calcoli la somma dei numeri pari della lista.

int lista_doppia::sommaPari() const{
    int somma=0;
    cella* curr = head;
    
    while(curr){
        if(curr->valore%2==0){
            somma = somma + curr->valore;
        }
        curr = curr->next;
    }
    return somma;
}

int main(){
    lista_doppia l1;
    
}