/*
    Autor: Jefferson Brito
    jefferson.brito@epn.edu.ec
*/

# include <iostream>
# include <string>
# include <sstream>
# include "Pila.h"

using namespace std;

/*------------------------------------------------------------------------*/

void funcion_calculadora(Pila &);
string calculadora( Pila &, string &);              //Nos devuelve el resultado de la operación en formato string
void imprimir(string &, string &);                  // Funcion que imprime la expresión y resultado de la operacion
double operacion(double &, double &, string &);     // Funcion que realiza las operaciones indicadas por el string
bool esValido(string &);
/*------------------------------------------------------------------------*/

int main(){

    string c;                                       // Nos indicará la opción del usuario
    bool indicador = false;           
    Pila stack;                                     // creamos una pila de 10 elementos 
    double resultado;                               
    
    /*
        Mientras no se ingrese 'c' o 'q', el programa se ejectará indefinidamente
    */

    while( indicador == false ){                    
        cout << "\033[2J\033[1;1H" << endl; // limpia la pantalla
        cout << "Ingrese 'c' para realizar un calculo, o ingrese 'q' para salir: ";
        getline(cin,c);                             // Receptamos la entrada del usuario

        if (c == "q"){
            cout << "Gracias" << endl;
            indicador = true;
            exit(EXIT_SUCCESS);
        }
        else if (c == "c"){
            funcion_calculadora(stack);             // LLama a la funcion calculadora que realizará todo el proceso
            indicador = true;                       // y saldrá del loop 
        }
    }
    return 0;
}   

/* -------------------------------------------------------------------------------------------------------------------
    Funciones utilizadas en el programa
 -------------------------------------------------------------------------------------------------------------------*/

void funcion_calculadora(Pila & pila){
    
    string answer, frase, aux;
    bool indicador = false;

    cout << "\033[2J\033[1;1H" << endl;
    cout << "Ingrese una expresión en formato RPN separado por un espacio en blanco entre numero y operacion: "<< endl;
    
    while(indicador == false){

        getline(cin,frase);
        
        if (frase == "q"){
            indicador = true;
            imprimir(aux,answer);
        }
        else if(esValido(frase) == false){
            imprimir(aux,answer);
        }
        else{
            aux = aux + " " + frase;
            answer = calculadora(pila,frase);
            imprimir(aux,answer);
        }
        
    }
};

/*------------------------------------------------------------------------*/

string calculadora( Pila & pila, string & expresion ){
    
    double a,b,ans;
    string resultado;
    string token;
    
    stringstream split(expresion);                  // Creamos un objeto split

    while(getline(split, token, ' ')){              // Mientras el string hecho un split no acabe realiza el proceso       
        if (token == "+" || token == "-" || token == "*" || token == "/"){
            a = stod(pila.top());                   // Escojo el primer elemento de la pila (segundo ingresado)
            pila.eliminar();                        // Elimino el primer elemento de la pila (segundo ingresado)
            b = stod(pila.top());                   // Ya que se ha eliminado el anterior, escojo el primero elemento de la pila (primer ingresado)
            pila.eliminar();                        // Elimino el primero elemento de la pila (primer ingresado)
            ans = operacion(b,a,token);             // Realizo la operacion respectiva
            pila.insertar(to_string(ans));          // inserto en la pila el resultado de la operacion anterior como un string 
        }
        else if(token == "~"){                      
            a = stod(pila.top());                   // Escojo el primero elemento de la pila (ultimo ingresado)
            pila.eliminar();                        
            b = a*(-1);                             
            pila.insertar(to_string(b));            
        }
        else{                                       
            pila.insertar(token);                   // Si 'token' no es un 'operador', se ingresa el 'numero' en la pila
        }
    }
    resultado = pila.top();                         // Obtengo el resultado como un string

    return resultado;
}

/*------------------------------------------------------------------------*/


void imprimir(string & phr, string & res){
    
    cout << "\033[2J\033[1;1H" << endl;             // Limpia la pantalla del terminal
    cout << "La expresion ingresada fue:" << endl;
    cout << phr << endl;
    cout << "----------------------------------------------------------- " << endl;
    cout << "El resultado de la expresion es:" <<endl;
    cout << res  << "\n" << endl;
}

/*------------------------------------------------------------------------*/

double operacion(double & a, double & b, string & op){
    
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
            cout << "ERROR: Division por cero" <<endl;
            exit(EXIT_FAILURE);
        }
        else{
            x = a/b;
        }
    }
    return x;
}

/*------------------------------------------------------------------------*/

bool esValido(string & str){

    bool indicador = true;
    string token;
    stringstream split(str);

    while( getline(split, token, ' ') )
    {
        for( int i=0; i<token.length(); i++ ){
            if (isdigit(token[i]) == false){
                indicador = false;
                break;
            }
        }
    }

    return indicador;
}