#include <iostream>
using namespace std;


class List{
    public:
        List();
        List(const List& s);
        
        void prepend(int x);
        void append(int x);

        void print();

    private:
        struct Cella{
           int info;
            Cella* next;
            };
    Cella* head;
};

List::List(){
    head = nullptr;
}

List::List(const List& s){
    Cella* pc = s.head;
    Cella* nc;
    head = nullptr;

    while(pc!=nullptr){
        if(head == nullptr){
            head = new Cella;
            head->info = pc->info;
            nc = head;
        }
        else{
            nc->next = new Cella;
            nc = nc->next;
            nc->info = pc->info;
        }
        pc = pc->next;
    }
    if(nc != nullptr){
        nc->next = nullptr;
    }
}