#include <iostream>
#include <vector>

using namespace std;

bool presente(const vector<int> &v, int e, int da, int a){
    if(da>a){
        return false;
    }
    else
        if(v.at(da)==e)
            return true;

    else 
        return(presente(v,e,da+1,a));

}
bool presente2(const vector<int> &v, int e, int da, int a){
    return (da<=a)&&(v.at(da)==e || presente(v,e,da++,a));
}
/*
bool binaria(vector<int> &v, int n, int inizio, int fine){
    if(fine>inizio)
        return false;
    else{
        int meta=(inizio+fine)/2;
        if()
        ...

    }
}
*/

int somma_max(const vector<int> &v, int s, int inizio, int fine){
    if(inizio>fine)
        return 0;
    else    
        if(v.at(inizio)<=s)
            return(v.at(fine)+somma_max(v,s-v.at(inizio),fine,fine-1));
        else
            return 0;
        }

bool palindroma(const string &s, int inizio, int fine){
    if(inizio>=fine)
        return true;
    else{
        if(s.at(inizio)!=s.at(fine))
            return false;
            
        else    
            return palindroma(s,inizio+1,fine-1);
    }
    return true;
}

int main(){
    vector<int> v={1,2,3,4,5,6};
    cout<<presente(v,3,0,5)<<endl;
    cout<<presente2(v,3,0,5)<<endl;
    cout<<somma_max(v,19,0,5)<<endl;

    string s="anna";
    string p="lana";
    cout<<palindroma(s,0,3)<<endl;
    cout<<palindroma(p,0,3)<<endl;
    return 0;
}