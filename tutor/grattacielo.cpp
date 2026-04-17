#include <iostream>
using namespace std;

int grattacielo(const vector<int>& v, int piano, colore c){
    if(piano==v.size())
        return 0;
    

    if(c==nero)
        return grattacielo(v,piano+1,bianco); 
    else if(c==bianco)
        return grattacielo(v,piano+1,nero);
}

int main(){
    return 0;
}