#include <cassert>
#include "stack.hpp"
#include <iostream>
using namespace std;

struct stack::Impl{
    int info;
    Impl* next;
};

//costruttore
stack::stack(){
    pimpl = nullptr;
    cout<<"Fatto uno stack a liste"<<endl;
}

//distruttore
stack::~stack(){
    while(pimpl!=nullptr){
        Impl* pc = pimpl;
        pimpl = pimpl->next;
        delete pc;
    }
}

bool isEmpty(){
    ///
}