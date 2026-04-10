/*
1. Reverse a Vector
Write a function that reverses the elements of a vector of integers
IN PLACE (i.e., without creating a new vector).
Example:
Input: {1, 2, 3, 4, 5}
Output: {5, 4, 3, 2, 1}
Hint: swap elements from the two ends moving towards the centre.


2. Filter Even Numbers
Write a function that, given a vector of integers, returns a NEW vector
containing only the even elements, preserving their order.
Example:
Input: {1, 2, 3, 4, 5, 6, 7, 8}
Output: {2, 4, 6, 8}

3. Remove Duplicates
Write a function that, given a vector of integers, returns a NEW vector
with all duplicate elements removed. The first occurrence of each element
must be preserved, and the relative order of elements must not change.
Example:
Input: {3, 1, 4, 1, 5, 3, 2, 4}
Output: {3, 1, 4, 5, 2}
Hint: for each element, check whether it already appeared earlier in the vector.

4.  Merge Two Sorted Vectors
Write a function that, given two vectors of integers that are each already
sorted in ascending order, returns a NEW vector containing all elements
of both vectors, also sorted in ascending order.
Example:
Input: {1, 3, 5, 7} and {2, 4, 6, 8}
Output: {1, 2, 3, 4, 5, 6, 7, 8}
Hint: use two indices, one for each vector, and at each step pick the
smaller of the two current elements.


5. 5. Matrix Transpose
Write a function that, given a square matrix (represented as a vector of
vectors of integers), returns its transpose.
The transpose swaps rows and columns: element at row i, column j
becomes the element at row j, column i.
Example:
Input:          Output:
1 2 3           1 4 7
4 5 6   --->    2 5 8
7 8 9           3 6 9
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

using namespace std;

//1. REVERSE A VECTOR
void reverse(vector<int> &v){
    int n=v.size();
    for(int i=0;i<n/2;i++){
        swap(v.at(i),v.at(n-1-i));
    }
}

//funzione universale per stampare vettori int
void print(vector<int> v){
    cout<<"[";
    for(int i=0;i<v.size();i++){
        cout<<v.at(i);
        if(i!=v.size()-1){
            cout<<",";
        }
    }
    cout<<"]"<<endl;
}

//2. FILTER EVEN
vector<int> filterEven(vector<int> v){
    vector<int> even;
    for(int i=0;i<v.size();i++){
        if(v.at(i)%2==0)
            even.push_back(v.at(i));
    }
    return even;
}

//3. REMOVE DUPLICATES
//soluzionedi gemini
vector<int> removeDuplicates(vector<int> &v){
    vector<int> fixed;
    for(int x:v){
        //questo serve a dire se non lo trova
        if (find(fixed.begin(), fixed.end(), x) == fixed.end()) {
            fixed.push_back(x);
        }
    }
    return fixed;
}

//4. 
vector<int> mergeSort(const vector<int> &a,const vector<int> &b){
    vector<int> final=a;
    //mi costruisco un vettore con a e b
    for(int x:b){
        final.push_back(x);
    }
    //oppure 
    /*
    final.insert(final.end(),b.begin(),b.end());

    */
    //lo ordino
    sort(final.begin(), final.end());
    return final;
}

void printMatrix(const vector<vector<int>> &m){
    for(int i=0;i<m.size();i++){
        cout<<"[";
        for(int j=0; j<m[i].size();j++){
            cout<<m[i][j];
            if(j!=m.size()-1){
            cout<<",";
        }
        }
        cout<<"]"<<endl;;
    }
}
vector<vector<int>> transponse(const vector<vector<int>> &m){
    int n = m.size();
    vector<vector<int>> trasposta(n,vector<int>(n));

    for(int i=0;i<m.size();i++){
        for(int j=0;j<m[i].size();j++){
            trasposta[i][j]=m[j][i];
        }
    }
    return trasposta;

}

int main(){
    //1.
    cout<<"es1"<<endl;
    
    vector<int> v = {1,2,3,4,5};   
    print(v);
    reverse(v);
    print(v);
    
    cout<<endl;
    
    //2.
    cout<<"es2"<<endl;

    vector<int> v2= {1,2,3,4,5,6,7,8};
    print(v2);
    print(filterEven(v2));
    
    cout<<endl;

    //3.
    cout<<"es3"<<endl;
    vector<int> v3= {3, 1, 4, 1, 5, 3, 2, 4};
    print(v3);
    print(removeDuplicates(v3));
    

    //4.
    cout<<"es4"<<endl;
    vector<int> a= {1, 3, 5, 7}; 
    vector<int> b={2, 4, 6, 8};
    print(a);
    print(b);
    print(mergeSort(a,b));


    cout<<"es5"<<endl;
    //matrice 3x3 ad esempio
    vector<vector<int>> matrice=
    {
    {1,2,3},
    {4,5,6},
    {7,8,9}
    };
    printMatrix(matrice);
    //deve diventare swap righe e colonne
    cout<<endl;
    printMatrix(transponse(matrice));
}