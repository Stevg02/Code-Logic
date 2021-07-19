# include <iostream>
# include <string>

template <class Type>
class Stack{
    public:
        Stack(static const int def_size = 10);                  // Constructor
        ~Stack();                                               // Destructor
        Type top() const;                                       // Devuelve el primer último elemento ingresado en la pila
        bool empty() const;                                     // verifica si la pila está vacía o no
        int size() const;                                       // Devuelve la capacidad de la pila
        Type push(Type);                                        // Ingresa un elemento en la pila
    private:
        Type * arrayType;
        int size = 10;
        int indexTop;                                           // Indicador de la posicion del último elementop ingresado
};

template <class Type>
Stack<Type>::Stack(int max)
{
    indexTop = -1;
    size = max;
    arrType = new Type[size];    
}

template <class Type>
Stack<Type>::~Stack()
{
    delete [] arrayType;
}

template <class Type>
Type Stack::size() const
{
    
}



