
/*

05-03-2026


metto using namespace std per dire che tuti gli identificatori del namesace std li uso
basta non metere identificatori che vanno in conflitto fra di loro e mi devo assumere
la responsabilita di non metterli in conflitto

<< = operatore di flusso

endl fa il flush del buffer mentre /n no

c++ cerca di creare un modo di programmare senza puntatori

scanf ha necessario il tipo di dato come parametro quando devo fare delle stampe siccome 
viene passato un puntatore alla memoria che non ha il tipo di dato

hiding di un identificatore: quando metto le graffe e metto stesso nome di una varaibile

definizione vs dichiarazione
    definizione=dichiarazione che riserva per il nome un oggetto es int a
    meccanismo delle reference o riferimenti e' una dichiarazione e non definizione
    e' usato per evitare l uso dei puntatori. nomi alternativi per un oggetto che esiste gia.

passaggio per indirizzo e per reference
    di solito si fa per copia se non metto simboli strani
    se metto & e' per reference. quando scrivo x=10 e' come fare un alias ad a che e il parametro
    passato dalla funzione  

    
*/

#include <iostream>
using namespace std;

void funzione(int& x){
    int y;
    x=10;
}

int main(){
    //std::cout<<"Hello World"<<std::endl;
    int& c=a; //c e' un alias di a, solo un nome non un oggetto fino a quando a non muore
    c=8; //a=8;

    cout<<"Hello world"<<endl;
    int a;
    cin>>a;
    
    funzione(a);
    cout<<a<<endl;
    

    return 0;
}
