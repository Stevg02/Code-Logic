# include <iostream>
# include <string>
# include "Pila.h"

bool calculator(std::string &);
bool operations(Stack<bool> &, Stack<char> &);

int main(){

    bool answer,flag = false;
    std::string expression;

    

    while (flag == false){
        std::cout << "Ingrese una operacion booleana o 'q' para salir: ";
        getline(std::cin,expression);
        // (1&0)|1
        // esto debe ser true, o 1
        if (expression != "q"){
            answer = calculator(expression);
            if(answer == true){
                std::cout << "V" << std::endl;
            }
            else{
                std::cout << "F" << std::endl;
            }
        }
        else{
            std::cout << "Gracias !" << std::endl;
            flag = true;
        }
    }

    return 0;
}

bool calculator(std::string & phrase){
    Stack<bool> prop;
    Stack<char> symbols;
    Stack<char> parenthesis;
    bool ans;
    
    for (int i=0; i< phrase.length(); i++){
        if (phrase[i] == '('){
            parenthesis.push(phrase[i]);
        }
        else if (phrase[i] == ')'){
            prop.push(operations(prop,symbols));
        }
        else if (phrase[i] == '0'){
            prop.push(false);
        }
        else if(phrase[i] == '1'){
            prop.push(true);
        }
        else{
            symbols.push(phrase[i]);
        } 
    }

    return operations(prop,symbols);
}

// letras propositionales 
bool operations(Stack<bool> & pl,Stack<char> & symbols){
    bool p = false,q = false,flag = false;
    char op;

    q = pl.top();
    pl.pop();
    p = pl.top();
    pl.pop();
    op = symbols.top();
    symbols.pop();

    if (op == '&'){
        if (p == true && q == true){
            flag = true;
        }
        else{
            flag = false;
        }
    }
    else if(op == '|') {
        if (p == false && q == false){
            flag = false;
        }
        else{
            flag = true;
        }
    }
    else if(op == '~') {
        if (q == true){
            flag = false;
        }
        else{
            flag = true;
        }
    }
    else if(op == '=') {
        if ( (p == true && q == true) || (p == false && q == false)){
            flag = true;
        }
        else{
            flag = false;
        }
    }
    else if(op == '>') {
        if (p == true && q == false){
            flag = false;
        }
        else{
            flag = true;
        }
    }

    return flag;
}