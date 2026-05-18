#include <iostream>
#include <vector>
using namespace std;


/*
m per reference percje non posso camiarlo e non voglio modificarlo perchee il tabelone. p non voglio nemodificarle ne farle una copia
used e per reference ma forse posso modificarlo quindi non const ed r e c cambia poco eoprche sono tipi privitivi ed occuoan 
poca memoria
*/
bool trova_ric(const vector<vector<char>> &m, const string &p, vector<vector<bool>> &used, int r, int c){
    if(p=="")
        return true;
    else
        if(p.at(0)!=m.at(r).at(c) || used.at(r).at(c))
            return false;
        else{
            bool flag = false;
            used.at(r).at(c)=true;
            for(int i=r-1; i<=r+1; i++)
                for(int j=c-1; j=c+1; j++)
                    if(i>=0 && i<4 && j>=0 && j<4)
                        if(trova_ric(m,p.substr(1,p.length()-1), used, i, j));
                            flag = true;
            used.at(r).at(c) = false;
            return flag;
        }

}

bool trovaParola(const vector<vector<char>> &m, const string &p){
    vector<vector<bool>> used(4);
    
    for(int i=0;i<4;i++){
        used.at(i).resize(4);
    }
    bool resp = false;
    for(int r=0; r<4; r++){
        for(int c=0; c<4; c++){
            if(trova_ric(m,p,used,r,c))
                resp=true;
        }
    }
    return resp;
}

/*

variante 1 : int che conta il numero di parole che possono uscire 

*/
int AtrovaParola(const vector<vector<char>> &m, const string &p){
    vector<vector<bool>> used(4);
    
    for(int i=0;i<4;i++){
        used.at(i).resize(4);
    }
    int resp = 0;
    for(int r=0; r<4; r++){
        for(int c=0; c<4; c++){
            if(Atrova_ric(m,p,used,r,c)){
                resp++;
            }
                
        }
    }
    return resp;
}

int Atrova_ric(const vector<vector<char>> &m, const string &p, vector<vector<bool>> &used, int r, int c,int count=0){
    if(p.length()==1 && p.at(0)==m.at(r).at(c) && !used.at(r).at(c))
        return 1;
    else
        if(p.at(0)!=m.at(r).at(c) || used.at(r).at(c))
            return 0;
        else{
            int resp = 0;
            used.at(r).at(c)=true;
            for(int i=r-1; i<=r+1; i++)
                for(int j=c-1; j=c+1; j++)
                    if(i>=0 && i<4 && j>=0 && j<4)
                        resp = Atrova_ric(m,p.substr(1,p.length()-1), used, i, j) + resp;
                        
                            
            used.at(r).at(c) = false;
            return resp;
        }
}
/**
 * variante 2: la matrice di boleani deve detere il true su le robe usate per le soluzioni e il false su
 *  quelle non usate. se non trovo lascio come pria, se trovo ritorno al chiamante la funzione modificata
 * DA SISTEMARE ANCORA***
 *  */

int BtrovaParola(const vector<vector<char>> &m, const string &p){
    vector<vector<bool>> used(4);
    
    for(int i=0;i<4;i++){
        used.at(i).resize(4);
    }
    int resp = 0;
    for(int r=0; r<4; r++){
        for(int c=0; c<4; c++){
            if(Btrova_ric(m,p,used,r,c)){
                resp++;
            }
                
        }
    }
    return resp;
}

int Btrova_ric(const vector<vector<char>> &m, const string &p, vector<vector<bool>> &used, int r, int c,int count=0){
    if(p.length()==1 && p.at(0)==m.at(r).at(c) && !used.at(r).at(c))
        return 1;
    else
        if(p.at(0)!=m.at(r).at(c) || used.at(r).at(c))
            return 0;
        else{
            int resp = 0;
            used.at(r).at(c)=true;
            for(int i=r-1; i<=r+1; i++)
                for(int j=c-1; j=c+1; j++)
                    if(i>=0 && i<4 && j>=0 && j<4)
                        resp = Btrova_ric(m,p.substr(1,p.length()-1), used, i, j) + resp;
                        
                            
            used.at(r).at(c) = false;
            return resp;
        }
}
/**
 * VARIANTE 3: ANZICHE FALSE  ETRUE VOGLIO L ORDINE DELA PAROLA SULLA TABELLA QUELLA DI DOVE MI SEGNO DOVE SONO 
 * PASSATO, QUINDI 1,2,3,4, E VIA DICENDO PER CASA AD ESEMPIO COSI MI RICORDO L'ORDINE
 * TODO
 * 
 */
int main(){
    return 0;
}
