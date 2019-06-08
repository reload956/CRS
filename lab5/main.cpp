#include <iostream>
#include "src/hash.h"

int main() {
    /*  std::string c[] = {"Ruble", "dollar", "euro", "peso", "Tugric", "birma", "hongkong dollar", "frank", "pound",
                         "Uan"};
      unsigned int n;
      std::cout << "Enter table size" << std::endl;
      std::cin >> n;
      try {
          unsigned int z = 0;
          unsigned int x = 0;
          std::string *v = new std::string;
          if (n == 0) {
              throw 1;
          } else {
              Hashtable Hashtable1;
              Hashtable1.Hastable(n);
              for (int i = 0; i < n; i++) {
                  Hashtable1.Statwriter();
                  element a;
                  a.date = 1012 + rand() % n;
                  a.data = c[rand() % 10];
                  a.code = 100 + i;
                  Hashtable1.Add(a);
                  if (i == (n - 1)) {
                      z = a.date;
                      x = a.code;
                      *v = a.data;
                  }

              }

              Hashtable1.print();
              element a;
              a.date = z;
              a.date = x;
              a.data = *v;
              Hashtable1.Del(a);
              Hashtable1.print();

  //            element a;
              a.date = 1014;
              a.data = c[2];
              a.code = 102;
              unsigned int l=Hashtable1.Search(a);
              std::cout << "ELEM POSITION: "<<l<< ' ' << a.data << ' ' << a.code << ' ' << a.date << ' ' << std::endl;


              //element;
              a.date = 1012 + 5;
              a.data = c[4];
              a.code = 100 + 4;
              int z = Hashtable1.Search(a);
              std::cout << z << std::endl;

          }
      }
      catch (int x) {
          switch (x) {
              case 1:
                  std::cout << "Empty length detected" << std::endl;
                  break;
              case 2:
                  std::cout << "Attempt to delete non existing element" << std::endl;
                  break;
              case 3:
                  std::cout << "Hash value bigger then table size" << std::endl;
                  break;
              case 4:
                  std::cout << "repeating data detected" << std::endl;
                  break;
              case 5:
                  std::cout << "no free space to add your data!" << std::endl;
                  break;
              case 6:
                  std::cout << "Procedure of rehashing(quadratic) didn't lead to the result" << std::endl;
                  break;
          }
      }
  */
    // try {

    Hashtable H(0);
    int c = 0;
    element a;
    a.code = 1000;
    a.date = 2000;
    for (int i = 0; i < 3; i++) {
    H.Add(a);
    a.code+=2;
    a.date-=2;
}
    H.print();
    a.code=1004;
    a.date=1996;
    c=H.Del(a);
    H.print();
    std::cout<<c<<std::endl;


  /*  for (int i = 0; i < 10; i++) {

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
int c=H.Search(a);
std::cout<<"POS "<<c<<std::endl;
*/



    return 0;
}