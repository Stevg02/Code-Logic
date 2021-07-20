# include <iostream>

# include <string>
# include <sstream>
# include "Pila.h"

void func_calc(Stack<double> &, Stack<std::string> &);
double calculator(Stack<double> &, Stack<std::string> &, std::string &);
double operation(double &, double &, std::string &);

int main(){
    
    Stack<double> numbers;
    Stack<std::string> symbols;

    bool flag = false;
    std::string c;

    while (flag == false){
        std::cout << "Ingrese 'c' para realizar un calculo, o ingrese 'q' para salir: ";
        getline(std::cin,c);

        if (c == "q"){
            std::cout << "Gracias !" << std::endl;
            flag = true;
        }
        else if (c == "c"){
            func_calc(numbers, symbols);
            flag = true;
        }
    }
    return 0;
}

void func_calc(Stack<double> & numbers, Stack<std::string> & symbols)
{
    std::string phrase;
    double answer;
    bool flag = false;

    while (flag == false){
        
        // std::cout << "\033[2J\033[1;1H" << std::endl;
        std::cout << "Ingrese 'q' para salir, o ingrese una expresión entre paréntesis separando numero y operacion mediante un espacio en blanco: "<< std::endl;

        getline(std::cin, phrase);
        if (phrase == "q"){
            flag = true;
        }
        else{
            answer = calculator(numbers, symbols, phrase);
            std::cout << answer << std::endl;
        }
    }
}

double calculator(Stack<double> & numbers, Stack<std::string> & symbols, std::string & phrase)
{
    double a,b,ans;
    std::string s, token;
    Stack<std::string> parenthesis;

    std::stringstream split(phrase);

    while (getline(split, token, ' ')){
        if (token == "("){
            parenthesis.push(token);
        }
        else if (token == ")"){
            a = numbers.top();
            numbers.pop();
            b = numbers.top();
            numbers.pop();
            s = symbols.top();
            symbols.pop();
            ans = operation(b,a,s);
            numbers.push(ans);
            parenthesis.pop();
        }
        else if (token == "+" || token == "-" || token == "*" || token == "/"){
            symbols.push(token);
        }
        else if ( token == "~"){
            a = numbers.top();
            numbers.pop();
            numbers.push(a*(-1));
        }
        else{
            numbers.push(stod(token));
        }
        
    }
    return numbers.top();
}


double operation(double & a, double & b, std::string & op){
    
    double x = 0;
    if(op == "+"){
        x = a+b;
    }
    else if(op == "-"){
        x = a-b;
    }
    else if(op == "*"){
        x = a*b;
    }
    else if(op == "/"){
        if(b == 0){
            std::cout << "ERROR: Division por cero" <<std::endl;
            exit(EXIT_FAILURE);
        }
        else{
            x = a/b;
        }
    }
    return x;
}

