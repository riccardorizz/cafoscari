Per fare preview del file markdown CMD+K e poi V

# Vettori e Stringhe
12-03

Se accedi ad un array con [] è unsafe mentre at è safe perchè controlla l'indice del vettore

```cpp
N[3]=12;
N.at(3)=12;
cout<<N[3];
cout<<N.at(3);
```
**Push back**: aggiunge un elemento alla fine dell'array, anche se la sua dimensione è finita.

```cpp
N.push_back(23);
```
Esempio in C
```c
void foo(int N[]){
    N[2]=0;
}

int main(){
    int N[]= {1,2,3,4,5};
    foo(N);
    cout<<N[2];
}
```

Esempio in C++
```cpp
void foo(vector<int> N){
    N.at(2)=0;
}

int main(){
    vector<int>N= {1,2,3,4,5};
    foo(N);
    cout<<N.at(2);
}
```

```cpp
vector<double>N(100);
for(int i=0; i<N.size();i++){
    cin>>N.at(i);
}
```

`string s;` e
`cin>>s;`
È una soluzione safe in c++ siccome si arrangia a determinare la lunghezza della stringa.

---

**Confronto di stringhe**

L'operatore == è stato definito in maniera corretta per confrontare le stringhe

[...]

`s1=s2+s2` Concatena due stringhe senza preoccuparsi della dimensione.

---

17-03

```cpp
void stampa(vector<int> v){
    for(int x : v){
        cout<<x<<" ";
    }
}

void leggi(vector<int> &v){
    int n;
    cin>>n;
    v.resize(n);
    
    for(int i=0; i<n: i++){
        cin>>v.at(i);
    }

    //metodo 2
    for(int &x : v){
        cin>>x;
    }
}

int main(){
    vector<int> N;
    leggi(N);
    stampa(N);
}
```
si può usare
```cpp
for(int &x : v){
        cin>>x;
    }
``` 
che è un foreach e ti consente di fare le stesse cose che faresti con un ciclo normale come nell'esempio sopra

**const reference**: passaggio dei parametri per reference ma dentro la funzione non modifico v. Si fa per le prestazioni del codice ma all'interno della funzione non è possibile modificare il parametro formale

```cpp
void stampa(const vector<int> &v){
    for(int x : v){
        cout<<x<<" ";
    }
}
```

Funzione cerca: cerca un elemento nel vector e restituisce 

```cpp
bool cerca(int x, const vector<int> &v){
    bool presente = false;

    for(int g : v){
        if(v == x){
            presente=true;
        }
    }
    return presente;
}
```

Cerco se il vettore ha tutti pari

```cpp
bool tuttiPari(const vector<int> &n){
    bool pari = true;
    pari 
    .....
}

```
Cerco se il vetore ha tutti numeri primi

```cpp
bool isprime(int n){
    if(n>1){
        bool prime=true;

        for(int i=2; i<n;i++){
            if(n%i==0)
                prime=false;
        }
        return prime;
    }
}

```

**Algoritmi di ordinamento**

Bubble sort

---
19-03

```cpp
#include <iostream>
#include <vector>

using namespace std;


void ordina(vector<int> &v){
    for(int soglia=v.size()-1; soglia>0; soglia--){
        for(int j=0; j<soglia; j++){
            swap(v.at(j), v.at(j+1));
        }
    }
}
void stampa(vector<int> &v){
    cout<<"[";
    for(int i=0; i<v.size(); i++){
        cout<<v.at(i)<<",";
    }
    cout<<"]";
}
int main(){
    vector<int> v = {1,2,4,5,7,4,23,1};
    ordina(v);
    stampa(v);
}
```

Esercizi di trasformazione da for a while
per rispettare l'uso preferenziale dei cicli

Esercizio: upcase sulle stringhe

```cpp
void upcase(string &s){
    for(int i=0; i<s.length(); i++){
        if(s.at(i)>='a' && s.at(i)<='z')
        s.at(i)=s.at(i)+('A'-'a');
    }
}

int main(){
    string mys;
    cin>>mys;
    upcase(mys);
    cout<<mys;
    return 0;
}
```
Le stringhe sono trattate come interi quindi posso sommare o togliere quelloche voglio.

È più giusto usare at per controllare che non va fuori dalla dimensione dell'array.

Alternativamente si può usare un foreach
```cpp
for(char&x:s){
    if(x>='a' && x<='z')
        x=x-'a'+'A';
}
```

auto sostituisce in compilazione il compilatore intuendo il tipo di dato dell'array

```cpp
for(auto x:s){
    if(x>='a' && x<='z')
        x=x-'a'+'A';
}

auto b=13; //int
auto a='k'; //char
auto p=3.14; //double
auto x; //da errore
```
---
**La Ricorsione**

Dato un array dire se è possibile formare la somma di 25 usando solo una volta i numeri di questo array ma usandoli solo una volta

[1,5,-3,4,6,9,12,7,2,-10] => 25

numero di combinazioni = 2^n = 1024

Ho un ipotesi induttiva e il caso base

```cpp
bool cercaSomma(const vector<int> &v, int somma;
    int da){
    if(da==v.size())
        return (somma==0);
    else{
        bool resp;
        
        resp1=cercaSomma(v,somma,da+1);
        resp2=cercaSomma(v,somma-v.at(da),da+1);
        
        return(resp1||resp2);
    }
}
```
---
26-03

# Ricorsione

const reference è più veloce di una normale reference, non duplico niente e il vettore non lo modifico.

Da ed a sono due variabili utilizzate per ridimensionare il vettore.

Ipotesi induttiva: so dire se è presente l'elemento e in un vettore più piccolo di v.

Ricerca binaria o bicotomica
dimezzo il vettore ogni volta e così in meno operazioni riesco a trovarci un valore

dato un array restituire la somma degli ultimi elementi dell' array che non superi un valore dato

---
# Le struct e gli Oggetti
31-03

```cpp
struct prova(){
    float x;
    int y;
    string a;
}
```
*x*, *y* ed *a* sono i campi della struct. 


```cpp
struct Punto(){
    private:
        double x;
        double y;
    public:
        void setx(double mx);
        void sety(double my);
        void setm(void mm);
        void stampa();
}
void Punto::setx(double mx){
    x=mx;
}
void Punto::sety(double my){
    y=my;
}
void Punto::setm(double mm){

}

int main(){
    Punto a;
    a.setx(12);
    a.sety(22);
    a.setm(122);
    a.stampa();
}
```
Principio di incapsulamento: soltanto con dei metodi pubblici è concessa l'interazione con la classe.

Normalmente se ci sono solo i campi usiamo struct. Se abbiamo campi e metodi usiamo class. Sono identiche trane per il fatto che per la struct tutto è pubblico e per la class tutto è privato.

costruttore:

```cpp
Punto::Punto(){
    x=0;
    y=0;
}
main(){
    punto a();
    //oppure
    punto a;
}
```
---
2-04

variabile globale nasce prima del esecuzione emuore dopo l ultima riga di codice del programa

maloc allora la memoria, la new utilizza un tipo di dato. la malloc è una funzione di libreria a differenza della new. la new puo chiaare il costrutture in maniera automatica la malloc no

delete[] per i vettori per eliminare tutto


# Le liste
14-04

Push back e pop back hanno complessità costante, siccome vengono solamente modificati i puntatori alla memoria. 

---

21-04
# Liste double linked

```cpp
int &List::at(int pos){
    return at.rec(testa,pos);
}
int &List::at_rec(cella* h, int pos){
    assert(h!=nullptr);
    if(pos==0)
        return h->info;
    else
        return(h->next,pos-1);
        
}
```
provare a fare cancellazione posizione lista, tutti elemti pari, a partire dal primo fino a quando incontra il primo zero

Le liste doppiamente concatenate hanno un puntatore head e tail. Metà dello spazio è overhead per i puntatori quindi occupano più spazio siccome ci sono due puntatori.

```cpp
class listDL{
    public:
        listDL();
        listDL(const ListDL&);
        void prepend(int n);
        void append(int n);
        void print() const;
        int& at(int pos);
        const int& at(int pos) const;
        void remove(int pos);
    
    private:
        struct Cella{
            int info;
            cella* next;
            cella* prev;
        };
        cella* testa;
        cella* coda;
};
ListDL:cella(){
    testa = nullptr;
    coda = nullptr;
}

void listDL::prepend(int n){
    cella* pc = new cella; 
    pc->info = n;
    pc->prev = nullptr;
    pc->next = testa;

    if(testa == nullptr){
        testa = pc;
        coda = pc;
    }
    else{
        testa->prev = pc;
        testa = pc;
    }
}

void ListDL::prepend(int n){
    cell* pc = new cell;
    pc->info = n;
    pc->next = nullptr;
    pc->prev = tail;

    if(tail==nullptr){
        tail = pc;
        head = pc;
    }
    else{
        tail->next = pc;
        tail = pc;
    }
}

void ListDL::remove(int pos){
    cell* pc = head;
    int i=0;
    while(i< pos && pc!=nullptr){
        i++;
        pc=pc->next;
    }
    if(pc!=nullptr){
        if(pc->prev == null){
            //se sto cancellando il primo elemento della lista
            head = pc->next;
        }
        else{
            pc-.prev->next = pc->next;
        }
        if(pc->next ==nullptr){
            tail=pc->prev;
        }
        else{
            pc->next->prev=pc->prev;
        }
        delete pc;
    }
}

void list::swap(){
    swap_rec(head);
}

void List::swap_rec(cell* &l){
    if(l!=nullptr && l->next!=nullptr){
        cell* pc = l;§
    }
}