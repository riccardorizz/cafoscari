#include <iostream>
#include <vector>
using namespace std;



/*
vettore di interi v e un intero target, 

il sottoinsieme vuoto a somma 0 o viene contato solo se target = 0.
vettore v, index e target
*/
int countSubsets(const vector<int>&v, int index, int target){
    if(index>=v.size()){
        return target==0 ? 1:0;
    }
    else{
        countSubsets(v,index+1,target-v.at(index)) + countSubsets(v,index+1,target);
    }
}int main(){

}