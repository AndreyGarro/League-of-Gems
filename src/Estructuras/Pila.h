//
// Created by andrew on 27/10/18.
//

#ifndef A_PILA_H
#define A_PILA_H

template <typename T>
struct nodo{
    T dato;
    nodo *anterior;
};

template <typename T>
class Pila {

private:
    nodo<T> *tope;
    int lenght = 0;

public:
    void push(T dato);
    T pop();
    T peek();
    int getLenght(){ return this->lenght;};

};

template<typename T>
void Pila<T>::push(T dato) {
    if(tope == nullptr){
        tope = new nodo<T>();
        tope->dato = dato;
        tope->anterior = nullptr;
    } else{
        auto *nodoN = new nodo<T>();
        nodoN->dato = dato;
        nodoN->anterior = tope;
        tope = nodoN;
    }
    this->lenght ++;
}

template<typename T>
T Pila<T>::pop() {
    nodo<T> *aux;
    aux = tope;
    tope = tope->anterior;
    this->lenght --;
    return aux->dato;
}

template<typename T>
T Pila<T>::peek() {
    return this->tope->dato;
}


#endif //A_PILA_H
