#pragma once
class FrontMiddleBackQueue
{
private:
	struct Node {
		int valor;
		Node* prev;
		Node* next;
	};

	Node* Primero;
	Node* Mitad;
	Node* Ultimo;
	int count;

public:
	FrontMiddleBackQueue();

	void pushFront(int value);

	void pushMiddle(int value);

	void pushBack(int value);

	int popFront();

	int popMiddle();

	int popBack();
};

