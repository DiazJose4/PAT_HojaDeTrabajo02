#include "Ejercicio02.h"

Node<int>* Ejercicio02::addTwoNumbers(Node<int>* l1, Node<int>* l2)
{
    int resto = 0;
    Node<int>* LS = nullptr;
    Node<int>* LR = nullptr;
    
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

        //LS->next = new Node<int>(suma % 10);
        resto = suma / 10;
        int dato = suma % 10;
        Node<int>* newNode = new Node<int>{ dato };
        if (LR == nullptr)
        {
            LR =  newNode;
            LS = LR;
        }
        else
        {
            LS->next = newNode;
            LS = LS->next;
        }
    }

    return LR;
}
