#include "Ejercicio04.h"

FrontMiddleBackQueue::FrontMiddleBackQueue()
{
}

void FrontMiddleBackQueue::pushFront(int value)
{
    Node* newNode = new Node{value};
    if (count == 0) {
        Primero = Mitad = Ultimo = newNode;
    }
    else if (count % 2 == 0) {
        newNode->next = Mitad;
        newNode->prev = Mitad->prev;
        if (Mitad->prev) {
            Mitad->prev->next = newNode;
        }
        Mitad->prev = newNode;
        Mitad = newNode;
    }
    else {
        newNode->next = Mitad;
        Mitad->prev = newNode;
        Mitad = newNode;
    }
    count++;
}

void FrontMiddleBackQueue::pushMiddle(int value)
{
    Node* newNode = new Node{ value };
    if (count == 0) {
        Primero = Mitad = Ultimo = newNode;
    }
    else if (count % 2 == 0) {
        newNode->next = Mitad;
        newNode->prev = Mitad->prev;
        if (Mitad->prev) {
            Mitad->prev->next = newNode;
        }
        Mitad->prev = newNode;
        Mitad = newNode;
    }
    else {
        newNode->next = Mitad;
        Mitad->prev = newNode;
        Mitad = newNode;
    }
    count++;
}

void FrontMiddleBackQueue::pushBack(int value)
{
    Node* newNode = new Node{ value };
    if (count == 0) {
        Primero = Mitad= Ultimo= newNode;
    }
    else {
        newNode->prev = Ultimo;
        Ultimo->next = newNode;
        Ultimo = newNode;
        if (count % 2 != 0) {
            Mitad = Mitad->next;
        }
    }
    count++;
}

int FrontMiddleBackQueue::popFront()
{
    if (count == 0) {
        return 0; 
    }
    int value = Mitad->valor;
    Node* prevNode = Mitad->prev;
    Node* nextNode = Mitad->next;
    delete Mitad;
    if (prevNode) {
        prevNode->next = nextNode;
    }
    if (nextNode) {
        nextNode->prev = prevNode;
    }
    Mitad= count % 2 == 0 ? prevNode : nextNode;
    count--;
    return value;
}

int FrontMiddleBackQueue::popMiddle()
{
    if (count == 0) {
        return 0;
    }
    int value = Mitad->valor;
    Node* prevNode = Mitad->prev;
    Node* nextNode = Mitad->next;
    delete Mitad;
    if (prevNode) {
        prevNode->next = nextNode;
    }
    if (nextNode) {
        nextNode->prev = prevNode;
    }
    Mitad = count % 2 == 0 ? prevNode : nextNode;
    count--;
    return value;
}

int FrontMiddleBackQueue::popBack()
{
    if (count == 0) {
        return 0;
    }
    int value = Ultimo->valor;
    Node* prevNode = Ultimo->prev;
    delete Ultimo;
    if (prevNode) {
        prevNode->next = nullptr;
    }
    Ultimo = prevNode;
    if (count % 2 != 0) {
        Mitad = Mitad->prev;
    }
    count--;
    return value;
}
