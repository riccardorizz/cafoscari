#include <iostream>
using namespace std;


class Foo{
    public:
        void print();
        void set(int a);

    private:
        int a;
};

Foo:Foo(){
    x = 0;
    
}
void Foo::print(){
    cout<<x<<endl;
}

void Foo::set(int a){
    x = a;
}

int main(){
    Foo myv1, myv2;
    myv1.set(12);
    myv2.set(23);
    myv1.print();
    myv2.print();


    
    return 0;
}
