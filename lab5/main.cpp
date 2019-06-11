#include <iostream>
#include "src/hash.h"

int main() {


    Hashtable H(10);
    int c = 0;
    element a;
    a.code = 1000;
    a.date = 2000;
    for (int i = 0; i < 5; i++) {
    H.Add(a);
    a.code+=2;
    a.date-=2;
}
    for (int i = 0; i < 5; i++) {
        H.Add(a);
        a.code+=1;
        a.date-=3;
    }
    H.print();
    a.code=1012;
    a.date=1984;
    c=H.Del(a);
    H.print();
    std::cout<<c<<std::endl;


    for (int i = 0; i < 10; i++) {

        int c = H.Add(a);

        a.code += 1;
        a.date -= 1;

    }

    H.print();

    a.code = 1000;
      a.date = 2000;
    a.data = "yyyy";

    for (int i = 0; i < 10; i++) {

        int c = H.Add(a);
        Error(c);
        c = 0;
        a.code += 1;
        a.date -= 5;

    }


    H.print();
a.date=1990;
a.code=1010;
c=H.Search(a);
std::cout<<"POS "<<c<<std::endl;




    return 0;
}