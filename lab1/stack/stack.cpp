#include <iostream>
#include <cassert>
using namespace std;

class stack{
    public:
        stack();
        stack(const stack& s);
        void push(int x);
        void pop();
        int top() const;
        bool isEmpty() const;
    private:
        struct cell{
            int info;
            cell* next;
        };
        cell* head;
};

stack::stack(){
    head = nullptr;
}

stack::stack(const stack& s){
    head = nullptr;
    cell* pc = s.head;
    cell* curr = head;

    //distinguo se sto inserendo il primo nodo della lista o meno
    while(pc){
        if(curr){
            curr -> next = new cell;
            curr = curr->next;
            curr -> info = pc ->info;
            curr -> next = nullptr;
        }
        else{
            head = new cell;
            head -> next = nullptr;
            head -> info = pc -> info;
            curr = head;
        }
        pc = pc -> next;
    }
}

void stack::push(int x){
    cell* nuova = new cell();
    nuova->info = x;
    nuova ->next = head;
    head = nuova;
}

void stack::pop(){
    assert(head != nullptr);
    cell* pc = head;
    head = head->next;
    delete pc;
}

int stack::top() const{
    assert(head!=nullptr);
    return head->info;
}

bool stack::isEmpty() const{
    return (head==nullptr);
}

int main(){
    stack s;
    s.push(6);
    s.push(12);
    s.push(46);

    while(!s.isEmpty()){
        cout<<s.top()<<endl;
        s.pop();
    }

    return 0;
}