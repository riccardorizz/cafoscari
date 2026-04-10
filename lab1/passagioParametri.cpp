#include <iostream>
using namespace std;


//10-03-2025
/*
Passaggio dei parametri in c++

il passaggio dei parametri in avviene smepre per copia
se creo una struct non serve che riscrivo struct ogni volta se la richiamo
*/



struct st{
    int a;
    int b[20]; //significa 20 interi no puntatori
    int c;
};

void foo(st par){
    par.a=12;
    par.b=2;
    par.c=3.14;
}

int main(){
    st x;
    foo(x);
    cout<<x.a<<endl;
}
//deep cooy e shellow copy
//passaggio per copia ed indirizzo
//problema puntatori confluenti e orfani
//metodo sicuro per leggere la stringa secondo la guida gnu

/*

per allocare un oggetto dinamico non uso la malloc ma la new
domanda: diferenza malloc e new
    new operatore del linguagio e malloc e' una libreria
    siccome new e un operatore e tipata,
    la new restituisfe un puntatore tipato e non faccio il casting come con la malloc e quindi la
    new e piu sofisticata

nullptr e la keyword per dire null in cpp, meglio usare questa che NULL
new e delete

in cpp se devo fare un puntatore lo meto di fianco al tipio di dato int* a;
    */