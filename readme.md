# Programmazione e Laboratorio 1

## 1. Vettori e Stringhe

In C++, la gestione degli array dinamici avviene tramite la classe `std::vector`. Esistono due modi principali per accedere agli elementi:

| Metodo | Sicurezza | Descrizione |
| :--- | :--- | :--- |
| `N[i]` | **Unsafe** | Accesso diretto. Se l'indice è fuori limite, il comportamento è indefinito. |
| `N.at(i)` | **Safe** | Esegue il controllo dell'indice. Lancia un'eccezione se l'indice è errato. |

Esempio di utilizzo:

``N[3] = 12``      Unsafe

``N.at(3) = 12``   Safe

**Push back**: Aggiunge un elemento alla fine del vettore, gestendo automaticamente il ridimensionamento della memoria.

`N.push_back(23);`

### Differenza tra C e C++ (Passaggio di Array)
In **C**, gli array vengono passati come puntatori (si perde l'informazione sulla dimensione), mentre in **C++** il `vector` mantiene le sue proprietà e la sua dimensione.

Esempio C:
```c
void foo(int N[]) {
    N[2] = 0;
}

int main() {
    int N[] = {1, 2, 3, 4, 5};
    foo(N);
    cout << N[2];
}
```
Esempio C++:
```cpp
void foo(vector<int> N) {
    // Passaggio per valore: N è una copia locale
    N.at(2) = 0; 
}

int main() {
    vector<int> N = {1, 2, 3, 4, 5};
    foo(N);
    cout << N.at(2); // Stamperà ancora 3
}
```
Iterazione su Vector:
```cpp
vector<double> N(100);
for(int i = 0; i < N.size(); i++){
    cin >> N.at(i);
}
```
### Stringhe
In C++, `std::string` è una soluzione sicura perché gestisce dinamicamente la lunghezza della stringa.
```cpp
string s;
cin >> s; 
```
*   **Confronto**: L'operatore `==` è usato per confrontare il contenuto testuale.
*   **Concatenazione**: `s1 = s2 + s3;` unisce le stringhe senza preoccuparsi dello spazio in memoria.

---

## 2. Passaggio di Parametri e Cicli (17-03)

### Passaggio per Riferimento (Reference)
Usare `&` permette di modificare l'oggetto originale senza copiarlo.
```cpp
void leggi(vector<int> &v) {
    int n;
    cin >> n;
    v.resize(n);
    
    // Metodo standard
    for(int i = 0; i < n; i++) {
        cin >> v.at(i);
    }

    // Foreach con reference per modificare i dati
    for(int &x : v) {
        cin >> x;
    }
}
```

**Const Reference**: Si usa per passare parametri in sola lettura. Velocizza il codice e garantisce che la funzione non modifichi il contenuto.
```cpp
void stampa(const vector<int> &v) {
    for(int x : v) {
        cout << x << " ";
    }
}
```
### Esercizi di Ricerca
Funzione cerca elemento:
```cpp
bool cerca(int x, const vector<int> &v) {
    bool presente = false;
    for(int g : v) {
        if(g == x) presente = true;
    }
    return presente;
}
```
Funzione IsPrime (Verifica numero primo):
```cpp
bool isprime(int n) {
    if(n <= 1) return false;
    bool prime = true;
    for(int i = 2; i < n; i++) {
        if(n % i == 0) prime = false;
    }
    return prime;
}
```
---

## 3. Algoritmi di ordinamento (19-03)

### Bubble Sort
Algoritmo di ordinamento che confronta elementi adiacenti e li scambia se nell'ordine errato.
```cpp
void ordina(vector<int> &v) {
    for(int soglia = v.size() - 1; soglia > 0; soglia--) {
        for(int j = 0; j < soglia; j++) {
            if(v.at(j) > v.at(j+1)) {
                swap(v.at(j), v.at(j+1));
            }
        }
    }
}
```
### Esercizio Upcase (Stringhe)
Trasforma i caratteri minuscoli in maiuscoli usando l'aritmetica dei caratteri.
```cpp
void upcase(string &s) {
    for(char &x : s) {
        if(x >= 'a' && x <= 'z')
            x = x - 'a' + 'A';
    }
}
```
### Keyword auto
Il compilatore deduce il tipo di dato dall'inizializzazione durante la compilazione.

`auto b = 13;` diventa int

`auto p = 3.14;` diventa double

---

## 4. Ricorsione (26-03)

La ricorsione si basa su:
1.  **Caso Base**: Condizione di arresto necessaria per evitare loop infiniti.
2.  **Ipotesi Induttiva**: Risolvere il problema richiamando la funzione su un'istanza più piccola dei dati.

Esempio Subset Sum (Somma di sottoinsieme):
```cpp
bool cercaSomma(const vector<int> &v, int somma, int da) {
    if(da == v.size()) return (somma == 0);
    bool resp1 = cercaSomma(v, somma, da + 1); // Non prendo l'elemento
    bool resp2 = cercaSomma(v, somma - v.at(da), da + 1); // Prendo l'elemento
    return (resp1 || resp2);
}
```
---

## 5. Struct e Classi (31-03)

| Caratteristica | Struct | Class |
| :--- | :--- | :--- |
| **Visibilità Default** | Public | Private |

**Principio di Incapsulamento**: I dati (`private`) sono protetti e accessibili solo tramite metodi pubblici (`public`).

Esempio Classe Punto:
```cpp
struct Punto {
    private:
        double x, y;
    public:
        void setx(double mx) { x = mx; }
        void stampa();
        Punto(); // Costruttore
};
```
---

## 6. Gestione Memoria e Liste (02-04 / 14-04)

*   **new**: Operatore C++ che alloca memoria nello Heap e invoca il costruttore.
*   **malloc**: Funzione C che alloca memoria grezza (non chiama costruttori).
*   **delete[]**: Necessario per deallocare array dinamici creati con `new[]`.

### Liste Doppiamente Concatenate (Double Linked List)
Ogni nodo (Cella) ha un puntatore `next` (successivo) e uno `prev` (precedente). 
*   Vantaggio: Navigazione bidirezionale e cancellazione semplificata.
*   Svantaggio: Overhead di memoria (due puntatori per ogni elemento).


*** esempio di codice da inserire ***
```cpp
struct cella{
    int info;
    cella* next;
};

class list{
    private:
        cella* head; //puntatore al primo elemento 
        void stampa_rec(cella* pc);

    public:
        list(); //costruttore
        //dichiaro gli altri metodi sotto
        void prepend(int x);
        void append(int x);
        void stampa();
};

//costruttore di default
list::list(){
    head = nullptr;
}
//implemento prepend e append. append inserisce in coda, prepend inserisce in testa. 

void list::prepend(int x){
    head = new cella{x,head};
}

void list::append(int x){
    if(head==nullptr){
        //se sono all'ultimo elemento
        head = new cella{x,head};
    }
    else{
        cella* pc = head;
        while(pc->next!=nullptr){
            //cerco l ultimo elemento 
            pc = pc->next;
        }
        pc->next = new cella{x,nullptr}; //attacco infondo
    }
}

//funzione pubblica che fa da ponte
void list::stampa(){
    stampa_rec(head);
    cout<<endl;
}

//funzione privata che fa la ricorsione
void list::stampa_rec(cella* pc){
    if(pc){
        cout<<pc->info<<" ";
        stampa_rec(pc->next);
    }
}

int main(){
    list l1;
    l1.prepend(20);
    l1.append(10);
    l1.append(15);
    l1.prepend(9);
    l1.stampa();
    return 0;
}
```
---

## 7. Stack e Queue (28-04 / 07-05)

### Stack (Pila) - Logica LIFO (Last In, First Out)
L'ultimo elemento inserito è il primo a essere rimosso.
*   `push`: Inserisce in cima.
*   `pop`: Rimuove dalla cima.
*   `top`: Legge l'elemento in cima.

### Queue (Coda) - Logica FIFO (First In, First Out)
Il primo elemento inserito è il primo a essere rimosso.
*   `enqueue`: Inserisce in fondo.
*   `dequeue`: Rimuove dalla testa (primo elemento).
*   `first`: Accede all'elemento in testa.

---

## Domande d'Esame

**Q1: Perché usi il `const` quando dichiari il costruttore di copia?**

R: Per garantire che l'oggetto originale non venga modificato accidentalmente durante l'operazione di copia.

**Q2: Perché metti il `const` sulla firma del metodo `first()` o `stampa()`?**

R: Indica che il metodo è di "sola lettura". Garantisce che lo stato interno dell'oggetto rimarrà invariato dopo la chiamata.