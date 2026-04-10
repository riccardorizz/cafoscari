/*
dato un vettore di interi ed un interi e un tagert trovare la coppia 
di elementi la cui somma è più vicina al target

*/
#include <iostream>
using namespace std;
#include <vector>

int closestToSum(const vector<int>&v, int target){
    int best_sum = v.at(0)+ v.at(1);
    int best_dist = abs(best_sum - target);
    for(int i=0;i<v.size();i++){
        for(int j=i+1; j<v.size(); j++){
            int curr_sum = v.at(i) + v.at(j);
            int curr_dist = abs(curr_sum-target);
            if(curr_dist<best_dist){
                best_dist = curr_dist;
                best_sum = curr_sum;
            }
        }
    }
    return best_sum;
}

/*
stampa tutte le possibili stringhe di lunghezza k che possono essere formate da 
un dato set di caratteri (con ripeizione ) {a,b,c} k=2 aa ba ca 
                                                       ab bb cb
                                                       ac bc cc
*/

void generate_strings(const vector<char> &set, string prefix, int k){
    if(k==0){
        cout<<prefix<<endl;
        return;
    }
    for(int i=0; i<set.size(); i++){
        
    }
}