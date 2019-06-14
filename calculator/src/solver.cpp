//
// Created by igor on 24.05.19.
//

#include "solver.h"
#include <vector>
#include <math.h>
#include <iostream>


void reader(const char *file, short *code, char *equation) {
    FILE *DOC;
    DOC = fopen(file, "r");
    if(!DOC){
        throw 1;
    }
    fscanf(DOC, "%hd", code);
    fscanf(DOC, "%s", equation);
    fclose(DOC);
}

std::vector<double> OrdinaryParser::parse(std::string &equation) {
    std::vector<double> num;
    int length = equation.length();
    int i = 0;

    while(i<equation.size()){
    if(isdigit(equation[i]) == false){
        i++;
    }else{
        double number=0;
        bool sign=false;
        if (equation[i-1]=='-'){
            sign=true;
        }
        int c=i;
        while(((isdigit(equation[c]))||equation[c]=='.')&&(i<equation.size())){
            c++;
        }
        if(sign){
            number=-1*std::stod(equation.substr(i,c));
        }else{
            number=std::stod(equation.substr(i,c));
        }
        num.push_back(number);
        i=c;
    }
    }
    if (num.size()!=2){

        throw 2;
    }
    return num;
}

std::vector<double> QuadraticParser::parse(std::string &equation) {
    std::vector<double> num;
    int length=0;

    int i=equation.find("x2");
    if (i==0){
        throw 2;
    }
    num.push_back(std::stod(equation.substr(0,i)));
    i+=2;
    int k=equation.find('x',i);
    num.push_back(std::stod(equation.substr(i,k)));
    i=k+1;
    k=equation.find('=');
    num.push_back(std::stod(equation.substr(i,k)));
    return num;
    }

short Add::get_Type(){
    return 0;
}
short Sub::get_Type(){
    return 1;
}
short Div::get_Type(){
    return 2;
}
short Mul::get_Type(){
    return 3;
}
short Quadratic::get_Type(){
    return 4;
}

double Add::calculate(std::vector<double> elements) {
if (elements[0]==0){
throw 3;}
return elements[0]+elements[1];

}

double Sub::calculate(std::vector<double> elements) {
    if (elements[0]==0){
        throw 3;}
    return elements[0]-elements[1];

}

double Mul::calculate(std::vector<double> elements) {
    if (elements[0]==0){
        throw 3;}
    return elements[0]*elements[1];

}

double Div::calculate(std::vector<double> elements) {
    if (elements[1]==0){
        throw 4;}
    return elements[0]/elements[1];

}

std::vector<double> Quadratic::result(std::string &equation){
    QuadraticParser parser1;
    std::vector<double> elements=parser1.parse(equation);
    std::vector<double>result;
    double derivative=pow(elements[1],2) - 4 * elements[0] * elements[2];
    if (derivative<0){

        throw 5;}
            if (derivative==0){
                result.push_back(-1*elements[1]/(2*elements[0]));
                return result;
            }else{
                result.push_back((-1*elements[1]+sqrt(derivative))/(2*elements[0]));
                result.push_back((-1*elements[1]-sqrt(derivative))/(2*elements[0]));
                return result;
            }
        }


    std::vector<double> ordinary::result(std::string &equation){
    OrdinaryParser parser1;
    std::vector<double> elements=parser1.parse(equation);
    std::vector<double> result;
    result.push_back(calculate(elements));
    return result;
}






void Solver::add(operation *operation1) {
    op.push_back(operation1);
}
void printer(std::vector<double> result){
    for (unsigned int i=0;i<result.size();i++)
        std::cout<<result[i]<<std::endl;
}

std::vector<double> Solver::solve(short type,std::string equation) {
    int n = op.size();
    int i = 0;
    while ((i < n) && op[i]->get_Type() != type){
        i++;
    }
    if (i == n){

        throw 6;
    }
    return op[i]->result(equation);
}

void Error(int x){
    switch (x) {
        case 1:
            std::cout << "file is not opened" << std::endl;
            break;
        case 2:
            std::cout << "incorrect equation" << std::endl;
            break;
        case 3:
            std::cout << "incorrect input values" << std::endl;
            break;
        case 4:
            std::cout << "divider equal to zero!" << std::endl;
            break;
        case 5:
            std::cout << "negative derivative" << std::endl;
            break;
        case 6:
            std::cout << "no operation of such type" << std::endl;
            break;
    }
}


