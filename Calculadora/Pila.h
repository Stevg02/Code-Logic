/**
    Clase Pila.h
    Integrantes: - Jefferson Brito (Master)
                 - Ivan Proaño
                 - David Guevara
**/

# include <iostream>
# include <string>
# include <stdlib.h>

class Pila
{
public:
    Pila(int maximo = 10); // nos crea una pila que sin pasar argumentos será de 10 elementos máximo
    ~Pila(); // destructor
    int tam() const; // tamaño de la pila
    bool vacio() const; //nos indicará si la pila está vacía o no
    std::string top() const; // nos devolverá el elemento que esté en el nivel más alto de la pila
    void insertar(std::string dato); // Ingresa un elemento a la pila
    void eliminar(); // elimina el último elemento ingresado a la pila
private:
    std::string *arr;   
    int indexTop; // Indicador para el último elemento ingresado en la pila
    int maximo; // numero máximo de elementos de la pila
};

Pila::Pila(int max)
{
    indexTop = -1; // indica que la Pila está vacía
    maximo = max;
    arr = new std::string[max];
}

Pila::~Pila()
{
    delete[]arr;
}

int Pila::tam() const
{
    return indexTop + 1;
}

bool Pila::vacio() const
{
    return (indexTop == -1); // Si el indextop es igual a -1, devolverá true, caso contrario false
}

std::string Pila::top() const
{
    //Nos devolverá el último elemento que está en la pila
    return arr[indexTop];
}

void Pila::insertar(std::string dato)
{
    // Añade un elemento a la pila
    // verificamos si ya está llena la pila
    if (indexTop +1 < maximo )
    {
        arr[++indexTop] = dato;
    }
}

void Pila::eliminar()
{
    //Elimina el elemento top de la pila
    // Verificamos que la lista no esté vacía, y si lo está, el programa termina automaticamente, por tanto en casos de testo donde tenemos ') (', el programa terminará antes de llegar al segundo parentesis
    if (vacio() == false)
    {
        indexTop--;
    }
    else
    {
        std::cout << "La lista está vacía." << std::endl;
        exit(EXIT_FAILURE);
    }    
}
