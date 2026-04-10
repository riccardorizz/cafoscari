Mara Pistellato, ricercatrice in AI

18-03

esercizio : Scrivi una funzione che dato un vettore controlli che tutti gli elementi siano pari

```cpp
bool allEven(const std::vector<int>&v){
    bool flag = true;
    int i=0;
    while(i<v.size() && flag==true){
        if(v.at(i)%2!=0)
            flag=false;
        i++;
    }
    return flag;
}
```
**std::vector int**-> significa un vettore di interi

**&v** -> significa che sto passando il parametro alla funzione per reference, cioè sto passando un alias dello stesso identico vettore in memoria. Ha il vantaggio di non sprecare memoria

**const** dico che non andrò a modificare il vettore 

---
Esercizio 2: verificare che esiste almeno un elemento negativo 

```cpp

bool existsNegative(const std::vector<int> &v){
    bool flag=false;
    int i=0;
    while(i<v.size() && !flag){
        if(v.at(i)<0)
            flag=true;
        i++;
    }
    return flag;
}
```

Se metto return true o false complica il debug se ci sono problemi avendo un codice lungo quindi il flag è la *best practice*