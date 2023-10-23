#include "Ejercicio01.h"

Node<char>* Ejercicio01::rotateRight(Node<char>* head, int k)
{
	if (!head || k == 0)
	{
		return head;
	}

	Node<char>* tail = head;
	int count = 1;
	//mientras tail encuentre un siguiente nodo
	while (tail->next)
	{
		count++;
		tail = tail->next;
	}
	tail->next = head;
	//Longitud de lista = count

	k = count - (k % count);//cantidad real en lista

	//rotacion
	for (int i = 0; i < k; i++)
	{
		head = head->next;
	}
	return head;
}
