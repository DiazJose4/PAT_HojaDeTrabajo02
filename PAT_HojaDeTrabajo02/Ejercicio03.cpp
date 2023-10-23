#include "Ejercicio03.h"
#include <stack>


int Ejercicio03::calculate(string s)
{
	int digito = 0;
	int operacion = 0;
	int sign = 1;
	std::stack<int> Datos;

	for (char c : s)
	{
		if (isdigit(c))
		{
			digito = c;
		}
		else if (c == '*')
		{
			digito = Datos.top() * digito;
			Datos.pop();
		}
		else if (c == '/')
		{
			digito = Datos.top() / digito;
			Datos.pop();
		}
		else if (c == '+')
		{
			operacion += sign * digito;
			digito = 0;
			sign = 1;
		}
		else if (c == '-')
		{
			operacion += sign * digito;
			digito = 0;
			sign = -1;
		}
	}
	return operacion += sign * digito;
}
