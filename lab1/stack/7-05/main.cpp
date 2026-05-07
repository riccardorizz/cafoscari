/**
 * È blind all implementazione dela struttura dati
 */
#include <iostream>
#include "stack.hpp"

int main(){
    stack s;
    for(int i=0; i<10000; i++){
        s.push(6);
        s.push(12);
        s.push(56);

        while(s.isEmpty()){
            s.pop();
        }
    }

    return 0;
}