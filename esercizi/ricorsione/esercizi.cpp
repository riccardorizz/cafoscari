/*
1. Somma dei due elementi più grandi
• Consegna: Dato un vettore di interi, scrivi una funzione che ritorni la somma dei due
elementi più grandi presenti nel vettore.
• Sfida ricorsiva: Prova a risolverlo passando il vettore e riducendone la dimensione a
ogni chiamata, mantenendo traccia dei due massimi trovati finora.

2. Decompressione di una stringa
• Consegna: Data una stringa "compressa" (dove ogni carattere è seguito dal numero di
volte che deve essere ripetuto, ad esempio a3b2), scrivi una funzione che ritorni la
stringa di partenza espansa (es. aaabb).
• Sfida ricorsiva: Pensa al caso base come alla stringa vuota e al passo ricorsivo come
all'espansione della prima coppia carattere-numero unita alla chiamata ricorsiva sul
resto della stringa.


dire se gli elementi di un vettore sono in ordine ricorsivamente

dato un sottoinsieme e somma target, ritorna quanti sottinismemi hanno risultato esattamente
uguale a target. (const vector int arr, int index, int target)
dato n vettore e una somma, dire quanbte volte all interno del vettore è possibile ottenere
quella somma con due numeri. esempio v=1,2,3,4,5 s=5 output -> 5,4+1,3+2,->3

*/

#include <iostream>
#include <vector>
using namespace std;

int contaSottoinsiemi(const vector<int> arr, int index, int target) {
    if (index < 0)
        return 0;

    int combinazioni = 0;

    if (arr[index] == target) {
        combinazioni = 1;
    }
    else {
        for (int i = 0; i < index; i++) {
            if (arr[index] + arr[i] == target) {
                combinazioni = 1;
                break;
            }
        }
    }
    return combinazioni + contaSottoinsiemi(arr, index - 1, target);
}

bool inOrder(const vector<int> v, int index=0){
    if(v.size()==1)
        return true;
    
    if(index>=v.size()-1)
        return true;
    
    if(v.at(index)>v.at(index+1))
        return false;
    
    return inOrder(v,index+1);
}

int main(){
    cout<<inOrder({1,2,3,4,5})<<endl;
    cout<<inOrder({1,3,2,4,5})<<endl;
    cout<<inOrder({1,9,4,5})<<endl;
    cout<<inOrder({1,6,3,4,5})<<endl;
    cout<<contaSottoinsiemi({1,2,3,4},4,5);
}