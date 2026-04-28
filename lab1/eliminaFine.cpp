/**
 * esercizio per eliminare la fine di n elementi di una lista. cancello dalla fine. 
 */
#include <iostream>
using namespace std;




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

//funzione dell'esercizio
/*
    sono in grado di eliminare n-1 
    elementi nella lista di lunghezza qualsiasi
    cerco una soluzione con complessità non troppo 
    alta
    ipotesi induttiva = cosa fa la ricorsione per me

    */

int elimina(cella *&c, int n){
    if(c==nullptr){
        return 0;
    }
    else{
        int k = elimina(c->next,n);
        if(k<n){
            //sono sicuro che la lista ha al massimo 1 cella
            delete c;
            c = nullptr;
            return k+1;
        }
        else{
            return n;
        }
    }    
}

void eliminaFine(cella*& c, int n){

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