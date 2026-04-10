#include <iostream>
#include <vector>
#include <array>
#include <string>
using namespace std;

/*
1. Count Vowels
Write a function that, given a string, returns the number of vowels
(a, e, i, o, u — both lowercase and uppercase) it contains.
Example:
Input: "Hello World"
Output: 3 (e, o, o)

Convert to Lowercase
Write a function that converts all uppercase letters of a string to
lowercase, modifying the string in place.
Example:
Input: "Hello World"
Output: "hello world"
Hint: look at how the uppercase function is implemented in the lecture examples.

3. Word Count
Write a function that, given a string, returns the number of words it
contains. Words are separated by spaces. You can assume there are no
leading, trailing, or consecutive spaces.
Example:
Input: "the quick brown fox"
Output: 4

4. Palindrome Check
Write a function that, given a string, returns true if the string is a
palindrome and false otherwise. The check must be case-insensitive, so
"Racecar" and "racecar" are both palindromes.
A palindrome is a word that reads the same forwards and backwards.
Examples:
"racecar" -> true
"Racecar" -> true
"hello" -> false

5. Caesar Cipher
Write a function that, given a string and an integer shift, returns a NEW
string where every letter has been shifted forward by that many positions
in the alphabet. Non-letter characters must be left unchanged.
The shift wraps around: shifting 'z' by 1 gives 'a'.
The case of each letter must be preserved.
Examples (shift = 3):
"Hello, World!" -> "Khoor, Zruog!"
"xyz" -> "abc"

*/

int countVowels(const string &a){
    int vowels=0;
    for(int i=0; i<a.size(); i++){
        char lettera=a.at(i);
        if(lettera=='a' || lettera=='A' || lettera=='e' || lettera=='E' || lettera=='i' || lettera=='I' || lettera=='o' || lettera=='O' || lettera=='u' || lettera=='U')
            vowels++;
    }
    return vowels;
}

void tolower(string &s){
    for(int i=0; i<s.size(); i++){
        if(s.at(i)>'A' && s.at(i)<'Z'){
            s.at(i)=s.at(i)+('a'-'A');
        }
    }
}

int word_count(string &c){
    int word=1;
    for(int i=0; i<c.size(); i++){
        char carattere = c.at(i);
        if(c.at(i)==' ' && c.at(i+1)!=' ')
            word++;
    }
    return word;
}

bool palindrome(string &s){
    //trasformo la stringa in to lower
    for(int i=0; i<s.size(); i++){
        if(s.at(i)>'A' && s.at(i)<'Z'){
            s.at(i)=s.at(i)+('a'-'A');
        }
    }
    //controllo se è palindroma
    for(int i=0;i<s.size();i++){
        if(s.at(i)!=s.at(s.size()-1-i)){
            return false;
        }
    }
    return true;
}
string shift(string s, int n){
    for(int i=0;i<s.size();i++){
        s.at(i)+=n;
        
    }
    return s;
}

int main(){

    //1
    cout<<"es1"<<endl;
    string a = "Hello World";
    cout<<a<<endl;
    cout<<countVowels(a)<<endl;

    //2
    cout<<"es2"<<endl;
    tolower(a);
    cout<<a<<endl;

    //3
    string b = "mi piacciono le nere";
    cout<<word_count(b)<<endl;

    //4 
    cout<<palindrome(b)<<endl;
    string c="otto";
    cout<<palindrome(c)<<endl;
    string d = "Racecar";
    cout<<palindrome(d)<<endl;

    //5
    string test="abc";
    cout<<shift(test,3)<<endl;
    string tesst="xyz";
    cout<<shift(tesst,3)<<endl;
}