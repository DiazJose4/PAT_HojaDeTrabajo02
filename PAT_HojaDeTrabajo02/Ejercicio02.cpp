#include "Ejercicio02.h"

Node<int>* Ejercicio02::addTwoNumbers(Node<int>* l1, Node<int>* l2)
{
    int resto = 0;
    Node<int>* LS;
    
    while (l1 || l2 || resto)
    {
        int suma = resto;
        if (l1)
        {
            suma += l1->value;
            l1 = l1->next;
        }
        if (l2)
        {
            suma += l2->value;
            l2 = l2->next;
        }

        resto = suma / 10;
        //LS->next = new Node<int>(suma % 10);


    }

    return nullptr;
}
