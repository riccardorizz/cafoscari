#include <iostream>
#include <stdexcept>

using namespace std;

// Un singolo nodo della lista semplicemente concatenata.
struct cell {
    int   value;  // dato / valore
    cell* next;   // collegamento: puntatore al nodo successivo (nullptr se è l'ultimo)
};

class ll {
    public:
        ll();                    // costruttore di default
        ll(const ll& other);     // costruttore di copia
        ~ll();                   // distruttore

        void prepend(int e);            // O(1) – inserimento in testa
        void append(int e);             // O(N) – inserimento in coda
        void print() const;             // stampa in ordine (forward)
        void print_rev() const;         // stampa invertita (ricorsiva)
        bool is_present(int e) const;   // true se e appare almeno una volta

        int&       at(int pos);         // accesso indicizzato in scrittura; lancia out_of_range
        const int& at(int pos) const;   // accesso indicizzato in sola lettura; lancia out_of_range

        void remove     (int e);        // rimuove la prima occorrenza di e
        void remove_last(int e);        // rimuove l'ultima occorrenza di e

        // ── Metodi d'esercizio ─────────────────────────────────────────────────

        int  sum() const;               // somma di tutti gli elementi (ricorsivo)
        void remove_all (int e);        // rimuove tutte le occorrenze di e
        void remove_up_to_sum(int s);   // rimuove i nodi la cui somma dei suffissi è <= s
        void flip();                    // inverte la lista in loco (ricorsivo)
        void double_even();             // inserisce una copia dopo ogni nodo pari (ricorsivo)
        bool equal(const ll& other) const;    // uguaglianza ricorsiva elemento per elemento
        bool countfrom0(int& count) const;    // conta gli elementi dopo l'ultimo 0

        bool operator==(const ll& other) const;  // uguaglianza elemento per elemento
        ll   operator+ (const ll& other) const;  // concatenazione (nuova lista)
        ll&  operator= (const ll& other);         // operatore di assegnazione di copia (copy-and-swap)
    private:
        cell* head;  // puntatore al primo nodo; nullptr quando la lista è vuota

        // ── Aiutanti (helper) privati ──────────────────────────────────────────────────
        void print_rev_rec(cell* curr) const;
        int  sum_rec(cell* curr) const;
        bool remove_last_rec(int e, cell* curr, cell* previous);  // versione 1 (con puntatore prev)
        bool remove_last_rec(int e, cell*& curr);                 // versione 2 (riferimento a puntatore)
        int  remove_up_to_sum_rec(int s, cell*& curr);
        bool equal    (cell* head,  cell* head_other)  const;  // uguaglianza iterativa
        bool equal_rec(cell* curr,  cell* curr_other)  const;  // uguaglianza ricorsiva
        void flip_rec        (cell*& curr);
        void double_even_rec (cell*& curr);
        bool countfrom0_rec  (cell* curr, int& count) const;
};

// Costruttore di default: inizializza una lista vuota.
ll::ll(){
    head = nullptr;  // nessun nodo ancora
}

// Costruttore di copia: crea una copia profonda (deep copy) di l, preservando l'ordine degli elementi.
ll::ll(const ll& other){
    head = nullptr;
    cell* curr = nullptr;   // coda della lista che stiamo costruendo (per un append in O(1))
    cell* curr_other   = other.head;    // iteratore sulla lista sorgente
    while(curr_other != nullptr){
        cell* nc = new cell{curr_other->value, nullptr};  // alloca un nuovo nodo con lo stesso valore
        if(head == nullptr){
            // primo nodo: sia head che curr puntano qui
            head = nc;
            curr = nc;
        }else{
            // collega il nuovo nodo in coda e avanza curr
            curr->next = nc;
            curr = curr->next;
        }
        curr_other = curr_other->next;  // passa al nodo successivo della lista sorgente
    }
}

// Distruttore: dealloca ogni nodo in modo iterativo per evitare lo stack overflow su liste lunghe.
ll::~ll(){
    while(head != nullptr){
        cell* tmp = head;       // salva il puntatore al nodo da eliminare
        head = head->next;      // avanza head prima della deallocazione
        delete tmp;
    }
}

// prepend: inserisce e in testa alla lista – O(1).
void ll::prepend(int e){
    cell* nc = new cell{e, head};  // il nuovo nodo punta alla testa attuale
    head = nc;                     // head ora punta al nuovo nodo
}

// append: inserisce e in coda alla lista – O(N).
void ll::append(int e){
    cell* curr = head;
    cell* nc   = new cell{e, nullptr};  // nuovo nodo senza successore
    if(curr == nullptr){
        head = nc;              // lista vuota: il nuovo nodo diventa la testa
    }else{
        // cammina fino all'ultimo nodo
        while(curr->next != nullptr){
            curr = curr->next;
        }
        curr->next = nc;        // collega il nuovo nodo dopo l'ultimo
    }
}

// print: itera dalla testa e stampa ogni valore, seguito da una nuova riga.
void ll::print() const{
    cell* curr = head;
    while(curr != nullptr){
        cout << curr->value << " ";
        curr = curr->next;
    }
    cout << endl;
}

// is_present: scansione lineare dalla testa; restituisce true alla prima corrispondenza.
bool ll::is_present(int e) const{
    cell* curr = head;
    while(curr != nullptr){
        if(curr->value == e)
            return true;        // trovato: interrompe in anticipo
        curr = curr->next;
    }
    return false;               // fine raggiunta senza alcuna corrispondenza
}

// at (in scrittura): cammina pos passi dalla testa e restituisce un riferimento al valore.
// Lancia std::out_of_range se pos >= lunghezza della lista.
int& ll::at(int pos){
    cell* curr = head;
    for(int i = 0; curr != nullptr && i != pos; i++){
        curr = curr->next;
    }
    if(curr == nullptr){
        throw std::out_of_range("OOR Error");  // pos era oltre l'ultimo nodo
    }
    return curr->value;  // il riferimento permette sia la lettura che la scrittura: lista.at(2) = 5
}

// at (in sola lettura): sovraccarico const utilizzato quando l'oggetto lista è const.
const int& ll::at(int pos) const{
    cell* curr = head;
    for(int i = 0; curr != nullptr && i != pos; i++){
        curr = curr->next;
    }
    if(curr == nullptr){
        throw std::out_of_range("OOR Error");
    }
    return curr->value;
}

// remove: rimuove la PRIMA occorrenza di n.
void ll::remove(int n){
    cell* curr     = head;
    cell* previous = nullptr;
    // cammina finché non troviamo n o raggiungiamo la fine
    while(curr != nullptr && curr->value != n){
        previous = curr;
        curr     = curr->next;
    }
    if (curr != nullptr){           // n è stato trovato
        if(previous == nullptr)
            head = curr->next;      // rimozione della testa: aggiorna head
        else
            previous->next = curr->next; // salta il nodo trovato
        delete curr;
    }
}

// print_rev: wrapper pubblico che avvia la ricorsione e stampa l'andata a capo finale.
void ll::print_rev() const{
    print_rev_rec(head);
    cout << endl;
}

// print_rev_rec: fa ricorsione fino alla fine della lista, poi stampa durante il ritorno.
// Questo inverte l'ordine di stampa senza utilizzare strutture dati extra.
void ll::print_rev_rec(cell* curr) const{
    if (curr != nullptr){
        print_rev_rec(curr->next);  // va prima più in profondità
        cout << curr->value << " "; // stampa dopo il ritorno della chiamata ricorsiva
    }
}

// remove_last: wrapper pubblico – delega a uno dei due helper ricorsivi.
void ll::remove_last(int e){
    // remove_last_rec(e, head, nullptr);  // versione 1 (con puntatore prev esplicito)
    remove_last_rec(e, head);              // versione 2 (riferimento a puntatore)
}


// ─────────────────────────────────────────────────────────────────────────────
// ESERCIZIO – Versione alternativa di remove_last (riferimento a puntatore)
// ─────────────────────────────────────────────────────────────────────────────
// Implementa una versione alternativa di remove_last_rec con la seguente funzione ricorsiva:
// bool ll::remove_last_rec(int e, cell*& curr)

bool ll::remove_last_rec(int e, cell*& curr){
    //caso base
    if(curr==nullptr){
        return false;
    }
    bool rimosso = remove_last_rec(e,curr->next);

    if(!rimosso && curr->value==e){
        cell* temp = curr;
        curr = curr->next;
        delete temp;
        return true;
    }
    return rimosso;
}

// ─────────────────────────────────────────────────────────────────────────────
// ESERCIZIO – operator== (uguaglianza elemento per elemento)
// ─────────────────────────────────────────────────────────────────────────────
// Restituisce true se e solo se le due liste hanno la stessa lunghezza e gli
// stessi valori nello stesso ordine. Implementa sia una versione iterativa (equal)
// sia una versione ricorsiva (equal_rec); operator== delega a equal_rec.
//
// Esempi:
//   [1 2 3] == [1 2 3]  → true
//   [1 2 3] == [1 2]    → false  (lunghezze diverse)
//   [1 2]   == [1 3]    → false  (valori diversi)
//   []      == []       → true
// ─────────────────────────────────────────────────────────────────────────────

bool ll::operator==(const ll& other) const{

}

bool ll::equal(cell* head, cell* head_other) const{
    
}

bool ll::equal_rec(cell* curr, cell* curr_other) const{
  
}

// ─────────────────────────────────────────────────────────────────────────────
// ESERCIZIO – operator+ (concatenazione di liste)
// ─────────────────────────────────────────────────────────────────────────────
// Restituisce una NUOVA lista che è la concatenazione di *this seguito da other.
// Entrambe le liste sorgente devono rimanere invariate.
//
// Esempi:
//   [1 2] + [3 4]  → [1 2 3 4]
//   []    + [1 2]  → [1 2]
//   [1 2] + []     → [1 2]
//   []    + []     → []
// ─────────────────────────────────────────────────────────────────────────────

ll ll::operator+(const ll& other) const{
   
}

// ─────────────────────────────────────────────────────────────────────────────
// ESERCIZIO – operator= (assegnazione di copia)
// ─────────────────────────────────────────────────────────────────────────────
// Implementa l'operatore di assegnazione in modo che *this diventi una copia
// profonda di other, liberando correttamente il contenuto corrente.
// Gestisci l'auto-assegnazione in modo sicuro.
//
// Esempi:
//   ll a = [1 2 3]; ll b; b = a;  → b == [1 2 3], a invariato
//   a = a;                        → nessuna operazione (auto-assegnazione)
// ─────────────────────────────────────────────────────────────────────────────

ll& ll::operator=(const ll& other){

}

// ─────────────────────────────────────────────────────────────────────────────
// ESERCIZIO – sum (somma di tutti gli elementi, ricorsivo)
// ─────────────────────────────────────────────────────────────────────────────
// Calcola la somma di tutti i valori nella lista utilizzando la ricorsione.
//
// Esempi:
//   []              → 0
//   [1]             → 1
//   [1, 2, 3]       → 6
//   [0, 1, 2, 3, 4] → 10
// ─────────────────────────────────────────────────────────────────────────────

int ll::sum() const{

}

int ll::sum_rec(cell* curr) const{

}

// ─────────────────────────────────────────────────────────────────────────────
// ESERCIZIO – remove_all (rimuove ogni occorrenza di un valore)
// ─────────────────────────────────────────────────────────────────────────────
// Rimuove dalla lista TUTTI i nodi il cui valore è uguale a e.
//
// Esempi:
//   [1 2 1 1 3], remove_all(1) → [2 3]
//   [1 1 1],     remove_all(1) → []
//   [1 2 3],     remove_all(9) → [1 2 3]  (non presente – nessun cambiamento)
// ─────────────────────────────────────────────────────────────────────────────

void ll::remove_all(int e){

}

// ─────────────────────────────────────────────────────────────────────────────
// ESERCIZIO – remove_up_to_sum (rimuove i nodi in base alla soglia della somma dei suffissi)
// ─────────────────────────────────────────────────────────────────────────────
// Rimuove ogni nodo la cui somma dei suffissi (il valore del nodo stesso più
// tutti i valori alla sua destra) è <= s.
//
// Esempi:
//   [3 1 2 4 5], remove_up_to_sum(6)  → [3 1 2 4]
//   [1 2 3],     remove_up_to_sum(10) → []
//   [1 2 3],     remove_up_to_sum(0)  → [1 2 3]
// ─────────────────────────────────────────────────────────────────────────────

void ll::remove_up_to_sum(int s){

}

int ll::remove_up_to_sum_rec(int s, cell*& curr){

}

// ─────────────────────────────────────────────────────────────────────────────
// ESERCIZIO – flip (inverte una lista in loco)
// ─────────────────────────────────────────────────────────────────────────────
// Inverte la lista in loco (in-place) utilizzando la ricorsione.
//
// Esempi:
//   []          → []
//   [1]         → [1]
//   [1 2]       → [2 1]
//   [1 2 3]     → [3 2 1]
//   [1 2 3 4 5] → [5 4 3 2 1]
// ─────────────────────────────────────────────────────────────────────────────

void ll::flip(){

}

void ll::flip_rec(cell*& curr){

}

// ─────────────────────────────────────────────────────────────────────────────
// ESERCIZIO – double_even (duplica ogni nodo con valore pari in loco)
// ─────────────────────────────────────────────────────────────────────────────
// Attraversa la lista ricorsivamente e, per ogni nodo che contiene un valore
// pari, inserisce un nuovo nodo con lo stesso valore subito dopo di esso.
//
// Esempi:
//   [2 7 0 5]  → [2 2 7 0 0 5]
//   [1 3 5]    → [1 3 5]         (nessun pari, invariata)
//   [2 4 6]    → [2 2 4 4 6 6]
//   []         → []
//   [0]        → [0 0]
// ─────────────────────────────────────────────────────────────────────────────

void ll::double_even_rec(cell*& curr){

}

void ll::double_even(){

}

// ─────────────────────────────────────────────────────────────────────────────
// ESERCIZIO – equal (uguaglianza ricorsiva elemento per elemento)
// ─────────────────────────────────────────────────────────────────────────────
// Restituisce true se e solo se le due liste contengono gli stessi valori nello
// stesso ordine. Implementalo ricorsivamente.
//
// Esempi:
//   []    vs []         → true
//   [1 2] vs [1 2]      → true
//   [1 2] vs [1 2 3]    → false  (lunghezze diverse)
//   [1 2] vs [1 3]      → false  (valori diversi)
//   [1]   vs []         → false
// ─────────────────────────────────────────────────────────────────────────────

bool ll::equal(const ll& other) const{

}

// ─────────────────────────────────────────────────────────────────────────────
// ESERCIZIO – countfrom0 (conta gli elementi dopo l'ultimo zero)
// ─────────────────────────────────────────────────────────────────────────────
// Scansiona ricorsivamente la lista e conta il numero di elementi che appaiono
// DOPO L'ULTIMO zero. Usa un parametro di output per il conteggio.
//
// Restituisce true  + count = numero di elementi dopo l'ultimo 0
//             false + count = lunghezza totale della lista (nessuno 0 trovato)
//
// Esempi:
//   [3 0 5 2]      → true,  count = 2  (5 e 2 sono dopo l'ultimo 0)
//   [1 0 2 0 7]    → true,  count = 1  (7 è dopo l'ultimo 0)
//   [1 2 3]        → false, count = 3  (nessuno 0, lunghezza intera)
//   [0 0 0]        → true,  count = 0  (l'ultimo 0 è l'ultimo nodo)
//   []             → false, count = 0
// ─────────────────────────────────────────────────────────────────────────────

bool ll::countfrom0(int& count) const{

}

bool ll::countfrom0_rec(cell* curr, int& count) const{

}

///// MAIN /////
int main(){
    return 0;
}