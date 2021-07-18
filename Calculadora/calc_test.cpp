# include <iostream>
# include "Pila.h"
# include <string>
# include <stdlib.h>

using namespace std;

double operacion(double & a, double & b, char & op){
    double x;
    switch(op){
        case '+':   x = a+b;
                    break;
        case '-':   x = a-b;
                    break;
        case '*':   x = a*b;
                    break;
        case '/':   if(b == 0){
                        cerr << "Error: Division por cero" <<endl;
                        exit(EXIT_FAILURE);
                    }
                    else{
                        x = a/b;
                    }
    }
    if(op == '+'){
        x = a+b;
    }
    else if(op == '-'){
        x = a-b;
    }
    else if(op == '*'){
        x = a*b;
    }
    else if(op == '/'){
        if(b == 0){
            cout << "No" <<endl;
            exit(EXIT_FAILURE);
        }
        x = a/b;
    }
    return x;
}

int main(){
    // 53 + 62 / * 35 * +
    
    Pila numeros;
    string expresion;
    char aux;
    cout << "Ingresar una expresion en notacion polaca: ";
    getline(cin, expresion);
    
    double a=0, b=0, res;

    for(int i=0; i<expresion.length(); i++){
        aux = expresion[i];
        if (aux == ' '){
            continue;
        }
        else{
            if (aux == '+' || aux == '-' || aux == '*' || aux == '/'){
                a = stod(numeros.top());
                numeros.eliminar();
                b = stod(numeros.top());
                numeros.eliminar();
                res = operacion(b,a,aux);
                numeros.insertar(to_string(res));            
            }
            else{
                numeros.insertar(to_string(aux));
            }
        }
    }
    cout << numeros.top() << endl;

    return 0;
}
