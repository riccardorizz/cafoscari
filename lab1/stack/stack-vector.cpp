#include <iostream>
#include <cassert>
#include <vector>
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

///...
int stack(){

}

int stack(const )