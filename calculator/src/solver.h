//
// Created by igor on 24.05.19.
//

#ifndef CALCULATOR_SOLVER_H
#define CALCULATOR_SOLVER_H
#include<string>
#include<fstream>
#include<vector>


void reader(const char *file,short *code, char *expression);
void printer(std::vector<double>);
void Error(int x);

class Parser{
        public:
        std::vector<double> parse(std::string &equation);
};

class OrdinaryParser: public Parser{
public:
    std::vector<double> parse(std::string &equation);
};

class QuadraticParser: public Parser{
public:
    std::vector<double> parse(std::string &equation);
};


class operation{
public:
    virtual short get_Type() = 0;
    virtual std::vector<double> result(std::string &equation) = 0;
};

class ordinary : public operation {
public:
    std::vector<double> result(std::string &s);
    virtual double calculate(std::vector<double> elements) = 0;
};

class Add :public ordinary{
public:
    short get_Type();
    double calculate(std::vector<double > elements);
};

class Sub :public ordinary{
public:
    short get_Type();
    double calculate(std::vector<double> elements);
};

class Mul :public ordinary{
public:
    short get_Type();
    double calculate(std::vector<double> elements);
};

class Div :public ordinary{
public:
    short get_Type();
    double calculate(std::vector<double> elements);
};

class Quadratic :public operation{

    short get_Type();
    std::vector<double> result(std::string &equation);



};



class Solver{
    std::vector<operation*>op ;
public:
    void add(operation* operation1);
    std::vector<double> solve(short type,std::string error);
};








#endif //CALCULATOR_SOLVER_H
