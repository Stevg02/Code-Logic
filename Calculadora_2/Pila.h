# include <iostream>
# include <string>

template <class Type>
class Stack{
    public:
        Stack(int def_size = 10);                  // Constructor
        ~Stack();                                               // Destructor
        Type top() const;                                       // Devuelve el primer último elemento ingresado en la pila
        bool empty() const;                                     // verifica si la pila está vacía o no
        int size() const;                                       // Devuelve la capacidad de la pila
        void push(Type);                                        // Ingresa un elemento en la pila
        void pop();
        void reset();                                           // Limpiamos completamente la pila
    private:
        Type * arrayType;
        int def_size;
        int indexTop;                                           // Indicador de la posicion del último elementop ingresado
};

/*------------------------ Método Constructor -------------------------*/

template <class Type>
Stack<Type>::Stack(int max)
{
    indexTop = -1;
    def_size = max;
    arrayType = new Type[def_size];    
}

/*------------------------ Método Destructor -------------------------*/

template <class Type>
Stack<Type>::~Stack()
{
    delete [] arrayType;
}

/*------------------------ Método Size -------------------------*/

template <class Type>
int Stack<Type>::size() const
{
    return indexTop + 1;    
}

/*------------------------ Método empty -------------------------*/

template <class Type>
bool Stack<Type>::empty() const
{
    return (indexTop == -1);
}

/*------------------------ Método Top -------------------------*/

template <class Type>
Type Stack<Type>::top() const
{
    return arrayType[indexTop];
}

/*------------------------ Método Push -------------------------*/

template <class Type>
void Stack<Type>::push(Type data)
{
    if (indexTop + 1 < def_size)
    {
        arrayType[++indexTop] = data;
    }
}

/*------------------------ Método Pop -------------------------*/

template <class Type>
void Stack<Type>::pop()
{
    if(!empty()){
        indexTop--;
    }
    else{
        std::cout << "Empty Stack" << std::endl;
    }
}


/*------------------------ Método Reset -------------------------*/

template <class Type>
void Stack<Type>::reset()
{
    indexTop = -1;
}