//
// Created by igor on 22.04.19.
//

#include "hash.h"


Hashtable::Hashtable(unsigned int Mysize) {
    if (Mysize < 1) { Mysize = 5; }
    vector = new struct element[Mysize];
    status = new bool[Mysize];
    for (int i = 0; i < Mysize; i++) {
        status[i] = false;
        size = Mysize;
    }

}


unsigned int Hashtable::Hashing1(element element1) {
    unsigned int key = element1.date + element1.code;
    unsigned int result = 0;

    result = key % size;

    return (result);


}

void Hashtable::Statwriter() {
    for (int i = 0; i < size; i++) {
        std::cout << i << ' ' << "Status" << ' ' << status[i] << std::endl;
    }
    std::cout << std::endl;
}

unsigned int Hashtable::Hashing2(unsigned int hash1, unsigned int i) {
    return (hash1 + i * i) % size;
}

Hashtable::~Hashtable() {
    delete[] vector;
    delete[] status;
}

unsigned int Hashtable::Add(element element1) {
    unsigned int hash1 = Hashing1(element1);
    if (status[hash1] == 0) {
        vector[hash1].code = element1.code;
        vector[hash1].data = element1.data;
        vector[hash1].date = element1.date;
        status[hash1] = true;
    } else {
        bool found = false;
        if (status[hash1] != 0) {
            if ((vector[hash1].date == element1.date) && (vector[hash1].code == element1.code)) {
                return 2;
            } else {
                unsigned int i=0;
                unsigned int g = Hashing2(hash1,i);
                while((status[g]==true)&&(i<size)){
                    i++;
                    if ((status[g]) && (vector[g].date == element1.date) && (vector[g].code == element1.code)) {
                        return 2;
                    }
                    g = Hashing2(g, i);
                }
                if (i<size){
                    found=true;
                    vector[g].code = element1.code;
                    vector[g].data = element1.data;
                    vector[g].date = element1.date;
                    status[g] = true;
                }
                if (!found) {
                    return 3;
                }
            }

        }

    }
    return 0;
}


bool Hashtable::Del(element element1) {
    unsigned int hash1 = Hashing1(element1);
    bool found = false;
     if (status[hash1]==false){
        return 1;
    }else {
    if ((status[hash1]) && (vector[hash1].date == element1.date) && (vector[hash1].data == element1.data) &&
        (vector[hash1].code == element1.code)) {
        status[hash1] = false;
        unsigned int i = 1;
        hash1 = Hashing2(hash1, i);
        while ((i < size) && (status[hash1] != false)) {
            if (status[hash1] != false) {
                element a;
                a.date = vector[hash1].date;
                a.code = vector[hash1].code;
                a.data = vector[hash1].data;
                status[hash1] = false;
                Add(a);
            }
            i++;
            hash1 = Hashing2(hash1, i);
        }
        found = true;
        return 0;
    } else {
        int i = 0;
        while ((found == false) && (i < size) && (status[hash1]!=false)) {
            i++;
            if ((status[hash1]) && (vector[hash1].date == element1.date)&&
                (vector[hash1].code == element1.code)) {
                status[hash1] = false;
                found = true;
                std::cout << "del hash " << hash1 << std::endl;
                unsigned int k = i;
                hash1 = Hashing2(hash1, k);
                while ((k < size) && (status[hash1] != false)) {
                    if (status[hash1] != false) {
                        element a;
                        a.date = vector[hash1].date;
                        a.code = vector[hash1].code;
                        a.data = vector[hash1].data;
                        status[hash1] = false;
                        Add(a);
                    }
                    k++;
                    hash1 = Hashing2(hash1, k);
                }

                return 0;
            } else
                hash1 = Hashing2(hash1, i);
        }
    }
    if (!found) {
        return 1;
    }
}
}


unsigned int Hashtable::Search(element element1) {
    unsigned int hash1 = Hashing1(element1);
    if ((status[hash1]) && (vector[hash1].date == element1.date) && (vector[hash1].code == element1.code)) {
        return hash1;
    } else {
        bool found = false;
        unsigned int i=0;
        while((status[hash1]==true)&&(i<size)) {
            hash1 = Hashing2(hash1, i);
            i++;
            if ((status[hash1] == 1) &&
                (vector[hash1].date == element1.date) &&
                (vector[hash1].code == element1.code)) {
                found = true;
                return hash1;

            }
        }
        if (!found) {
            return size;
        }
    }
}


void Hashtable::print() {
    std::cout << "----------------------------------------------------------------" << std::endl;
    for (int i = 0; i < size; i++) {
        if (status[i]) {
            std::cout << i << ' ' << vector[i].code << ' ' << vector[i].date << ' ' << vector[i].data << ' '
                      << "Status: " << status[i] << std::endl;
        } else {
            std::cout << i << "  empty" << ' ' << status[i] << std::endl;
        }
        std::cout << "--------------------------------------------------------------" << std::endl;
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;
}

void Error(int c) {
    if (c != 0) {
        switch (c) {
            case 1:
                std::cout << "Attempt to delete non existing element" << std::endl;
                break;
            case 2:
                std::cout << "repeating data detected" << std::endl;
                break;
            case 3:
                std::cout << "Procedure of rehashing(quadratic) didn't lead to the result" << std::endl;
                break;

        }
    }
}
