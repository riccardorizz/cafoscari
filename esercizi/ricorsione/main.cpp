/*
1.  

Scrivere una funzione ricorsiva che calcoli il massimo comun divisore (MCD) tra due interi
positivi sfruttando la seguente proprietà:
P1: se a>b allora MCD(a,b) = MCD(a-b,b).
Per esempio, se a=22 e b=14 allora il MCD(22,14)=MCD(8, 14)
Il primo passo consiste nel capire su quale input sviluppare la ricorsione. Qui la funzione ha
due parametri in ingresso, a e b. Potremmo farlo su a, su b ma anche su a+b o altro.
Supponiamo di voler procedere su a nel calcolo di MCD(a,b).
Di seguito scriviamo l’ipotesi induttiva. Nel nostro caso: siamo in grado di calcolare il MCD
tra due interi positivi MCD(x,y) dove x è più picciolo di a, cioè x<a (non dico nulla su b perché
stiamo procedendo solo su a).
Una volta scritta l’ipotesi, ragioniamo sul come usarla per risolvere il problema. Ci aiuta a
risolvere il problema? Non proprio. Infatti, se abbiamo MCD(14,4) possiamo usare P1 per
calcolare il MCD(10,4) e per ipotesi lo sappiamo fare quindi siamo a posto. Però se dobbiamo
calcolare il MCD(4,14), come facciamo ad usare P1 per ridurre il primo parametro? Facciamo
un altro tentativo.
Supponiamo di voler procedere sul massimo tra a e b nel calcolo di MCD(a,b).
Di seguito scriviamo l’ipotesi induttiva. Nel nostro caso: siamo in grado di calcolare il MCD
tra due interi positivi MCD(x,y) il massimo tra x e y è minore del massimo tra a e b. Proviamo a
sfruttare questa ipotesi.
• Se a>b possiamo calcolare MCD(a-b, b). Siccome a era il massimo e b>0, allora il
massimo di a-b e b è sicuramente minore del massimo tra a e b. Eureka! Possiamo
usare l’ipotesi induttiva.
• Se a<b possiamo calcolare MCD(a, b-a). Stesso ragionamento di prima e usiamo
l’ipotesi induttiva.
Quando non possiamo fare questa operazione? Se a=b, il calcolo a-b dà 0 ma noi ricordiamo
che MCD vuole due parametri positivi, 0 non è ammesso. Questo dà origine al nostro caso
base perché non possiamo fare una chiamata ricorsiva usando P1. Tuttavia, sappiamo che il
MCD tra due numeri uguali è proprio quel numero, per esempio MCD(14,14)=14.


Esercizio 1
Dato un vettore di interi, scrivi una funzione calcoli ricorsivamente la somma degli elementi
positivi del vettore. La funzione può avere come parametro formale solo il vettore.


Esercizio 2
di quel vettore.
Dato un vettore con almeno un elemento, scrivi una funzione ricorsiva che calcoli il massimo


Esercizio 3
Scrivi una funzione ricorsiva che, dato un intero non-negativo calcoli la somma delle sue cifre.
Tip: ricorda che se prendi il numero 452, puoi isolare l’ultima cifra (2) facendo 452%10 e ti
rimane da analizzare il 45 che è 452/10.

Esercizio 4
Data una stringa, scrivi una funzione ricorsiva per contare quante vocali contiene.

Esercizio 5
Data una stringa, scrivi una funzione ricorsiva che restituisca una nuova stringa con i caratteri in ordine inverso.

Esercizio 7
Scrivi una funzione ricorsiva che decide se due vettori sono uguali. Nota che i vettori possono
avere dimensione diversa (e quindi non sono uguali).

Esercizio 8
Scrivi una funzione ricorsiva che ribalta sul posto una stringa (non ne crea una copia).

Esercizio 9
Massimo comun divisore di un vettore. Sia dato un vettore v, vogliamo calcolare
ricorsivamente il MCD di tutti gli elementi di v ricordando che MCD(a,b,c)=MCD(a,MCD(b,c)).
Tutti gli elementi del vettore sono positivi. Puoi usare la funzione MCD precedentemente
implementata

Es 10
Dato un intero positivo, scrivi una funzione ricorsiva che restituisce una stringa che contenga
la rappresentazione binaria del numero in cui il primo carattere è il bit più significativo.

Esercizio 11
Data una stringa che contiene un numero espresso in base 16, scrivi una funzione ricorsiva
con un solo parametro che restituisca il suo valore come intero.

*/
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;


//11 non ho capito come funziona
int hexToDec(string hex){
    //caso base
    if(hex.length()==0)
        return 0;
    
    //converto il valore da esadecimale a intero
    char ultimoCarattere = hex.back();
    int valore;
    if(ultimoCarattere >= '0' || ultimoCarattere <='9')
        valore=ultimoCarattere - '0';
    else
        if(ultimoCarattere>='A' && ultimoCarattere<='F')
            valore = ultimoCarattere - 'A' + 10;
    //tolgo l'ultimo numero che ho appena convertito
    hex.pop_back();
    
    return hexToDec(hex) * 16 + valore;
}

//10
string decToBin(int n, int i=0, string s=""){
    if(n==0)
        return "0";
    if(n==1)
        return "1";

    return decToBin(n/2)+ to_string(n%2);
}

/*9
int mcdVett(vector<int> v){

}*/


//8
void ribaltaStringa(string &s, int inizio, int fine){
    //caso base
    if(inizio>=fine)
        return;
    else{
        swap(s.at(inizio),s.at(fine));
        return ribaltaStringa(s, inizio+1, fine-1);
    }
}

//7
bool uguali(vector<int> &v1, vector<int> &v2){
    //modifico i due vettori e vedo se sono uguali togliendo elemento x elemento. questo tiene conto 
    //anche del fatto che siano di dimensione diversa
    int ultimo1 = v1.back();
    int ultimo2 = v2.back();
    v1.pop_back();
    v2.pop_back();
    
    if(ultimo1!=ultimo2)
        return false;
    else 
        return uguali(v1,v2);
}

//5
string reverse(string s, int i=0){
    if(i==s.size()-1)
        return string(1,s.at(i));
    else
        return reverse(s,i+1) + s.at(i);
}

//4
int contaVocali(string s, int i=0){
    if(i==s.size())
        return 0;
    else 
        if(s.at(i)=='a' || s.at(i)=='e' || s.at(i)=='i' || s.at(i)=='o' || s.at(i)=='u' || s.at(i)=='A' || s.at(i)=='E' || s.at(i)=='I' || s.at(i)=='O' || s.at(i)=='U')
            return 1 + contaVocali(s,i+1);
        else
            return 0 + contaVocali(s,i+1);
}

//3
int sommaCifre(int n){
    if(n<10)
        return n;
    else
        return n%10 + sommaCifre(n/10);
}

//2
int max(vector<int> &v,int index, int massimo){
    if(v.at(index)>massimo)
        massimo=v.at(index);
    //caso base
    if(index==v.size()-1)
        return massimo;

    return max(v,index+1,massimo);
}


//1
int vetPos(vector<int>&v){
    if(v.empty())
        return 0;
    
    int ultimoElemento = v.back();
    v.pop_back();

    int somma=vetPos(v);

    if(ultimoElemento>=0)
        return ultimoElemento+somma;
    else
        return somma;
        
}

/*int mcd(int n1,int n2){
    if(n1==n2)
        return n1;
    else if(n1>n2)
        return mcd(n1-n2,n2);
    else if(n2>n1)
        return mcd(n2-n1,n1);    
}*/

int main(){
    /*{
    cout<<"es0"<<endl;
    cout<<mcd(14,1)<<endl;
    cout<<mcd(12,6)<<endl;
    cout<<mcd(3,18)<<endl;
    }*/

    {
    cout<<"es1"<<endl;
    vector<int> v1={1,2,3,4,5,-3,-6,-9};
    cout<<vetPos(v1)<<endl;
    }
    
    {
        cout<<"es2"<<endl;
        vector<int> v={1,2,3,4,5,7,8,6,54,3,2,4,-2};
        cout<<max(v,0,v.at(0))<<endl;
    }

    {
        cout<<"es3"<<endl;
        int n=256;
        cout<<sommaCifre(256)<<endl;

    }
    {
        cout<<"es4"<<endl;
        string s = "ciao";
        string a = "aaccbbssddaaeeiioouqkwr";
        cout<<contaVocali(a)<<endl;
        cout<<contaVocali(s)<<endl;

    }
    {
        cout<<"es5"<<endl;
        string s="ciao";
        cout<<reverse(s)<<endl;  
    }
    {
        cout<<"es6"<<endl;
        vector<int> v={1,2,3,4,5};
        vector<int> t={1,2,3,4,5};
        vector<int> a ={1,2,5,6,7};
        vector<int> b={1,2,3};
        cout<<uguali(t,v)<<endl;
        cout<<uguali(a,t)<<endl;
        cout<<uguali(a,b)<<endl;
    }
    {
        cout<<"es7"<<endl;
        string s = "ciao";
        ribaltaStringa(s,0,s.size()-1);
        cout<<s<<endl;
    }
    {
        cout<<"es8"<<endl;
        cout<<decToBin(13)<<endl;
        cout<<decToBin(1)<<endl;
    }
    {
        cout<<"hextodec"<<endl;
        cout<<hexToDec("23")<<endl;
    }
    return 0;
}