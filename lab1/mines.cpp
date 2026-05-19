/**
 * esercizio campo minato
 */
#include<vector>
#include <iostream>
using namespace std;

class campoFiorito{
    public:
        campoFiorito(int r,int c);
        ~campoFiorito();
        void aggiungiFiori(int n);
        void play(int r, int c);
    private:
        vector<vector<int>> tabella;
        int fiori;
};

campoFiorito::campoFiorito(int r, int c){
    tabella.resize(r);
    for(auto& riga:tabella){
        riga.resize(c);
        fiori = 0;
    }
}



void campoFiorito::aggiungiFiori(int n){
    for(auto& riga : tabella){
        for(auto& cella : riga){
            cella = 100;
        }
    }
    int x = 0;
    do{
        int row = rand(tabella.size());
        int column = rand(tabella.at(0).size());
    }
    while(tabella.at(row).at(column)==99);

    tabella.at(row).at(column)=99;

    for(int r = row-1; r<=row++;r++){
        for(int c=column-1;c<=column+1;c++){
            if(r>=0 && r<tabella.size() && c>=0 && tabella.at(0).size() && tabella.at(r).at(c)!=99){
                tabella.at(r).at(c)++;
            }
        }
    }
}

void campoFiorito::play(int r, int c){
    if(r>=0 && r<tabella.size() && c>=0 && c<tabella.size() && tabella.at(r).at(c)>=99){
        tabella.at(r).at(c)-=100;
        if(tabella.at(r).at(c)==0)
            for(int i=r-1; i<=r; i++)
                for(int j=c-1;j<=c+1;j++)
                    play(i,j);
    }
}

int campoFiorito::controlloPartita() const{
    bool scoperto = false;
    int conta = 0;
    
}