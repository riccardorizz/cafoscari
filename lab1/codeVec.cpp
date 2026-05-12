#include <iostream>
#include <vector>
#include <cassert>
using namespace std;


class Queue{
    public:
        Queue();
        ~Queue();
        void enqueue(int x);
        void dequeue();
        int head() const;
        bool isEmpty() const;

    private:
        vector<int> v[100];
        int next;
        int last;
        int elem;
        //last è l indice dell elemento più vecchio nel vettore
        //next e l indice della prossima posizione libera del vettore
        //questa soluzione consente che last e next possono essere uno piu piccolo dell altro indipendentemente cosi posso riempire l array in tutte le sue caselle
        //se sono entramni ugualki ho la coda vuiota opure piena
        //quindi o facio inserire un valore in meno nella coda quindi 99 anziche 100 oppure 
        //faccio l'implementazionec on un contatore per tenere conto dellecelle occupate e evitare questi problemi
    };

Queue::Queue(){
    next=0;
    last=0;
    elem=0;
}

Queue::~Queue(){

}

void Queue::enqueue(int x){
    if(elem<100){
        v.at(next)=x;
        next=(next+1)%100; //per riempire tutti gli spazi
        elem++;
    }
    else{
        //allungo il vettore

    }
}

void Queue::dequeue(){
    if(elem>0){
        last=(last+1)%100;
        elem--;
    }
}

int Queue::head() const{
    assert(elem>0);
    return v.at(last);
}

bool Queue::isEmpty() const{
    return (elem==0);
}
