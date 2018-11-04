//
// Created by christian on 30/10/18.
//

#ifndef LEAGUEOFGEMS_COLA_H
#define LEAGUEOFGEMS_COLA_H
template <class T>
struct Nodo{
    T elemento;
    Nodo *siguiente;
};
/**
 * Estructura de datos tipo cola, metodos push(), pop(), zise(), consultar(), vacia().
 * @tparam T
 */
template <class T>
class Cola{
    int numElementos;
    Nodo<T> *inicio;
    Nodo<T> *final;

public:
    Cola(){
        numElementos = 0;
    }
    ~Cola(){
        while (numElementos != 0) pop();
    }
    /**
     * Insertar un elemento
     * @param elem
     */
    void push(const T& elem){
        Nodo<T>* aux = new Nodo<T>;
        aux->elemento = elem;
        if (numElementos == 0) {
            inicio = aux;
        }
        else {
            final->siguiente = aux;
        }
        final = aux;
        numElementos++;
    }
    /**
     * Tomar datos de la cola
     * @return
     */
    T pop(){
        Nodo<T>* aux = inicio;
        inicio = inicio->siguiente;
        numElementos--;
        return aux->elemento;
    }
    /**
     * Verificar el primer elemento de la cola sin remover
     * @return
     */
    T consultar() const{
        return inicio->elemento;
    }
    /**
     * Consulta si la cola esta vacia
     * @return
     */
    bool vacia() const{
        return numElementos == 0;
    }
    /**
     * Retorna el tamano de la cola
     * @return
     */
    int size() const{
        return numElementos;
    }
};
#endif //LEAGUEOFGEMS_COLA_H
