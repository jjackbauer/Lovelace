#include <iostream>
#include "InteiroLovelace.h"
using namespace std;

int main()
{
	Lovelace A,B;
	int c;

	for(c=0;c<100;c++)
		A.SetDigito(c,9);
	for(c=0;c<100;c++)
			B.SetDigito(c,9);

	A.Imprime();
	B.Imprime();
	A = A.Soma(&A,&B);
	A.Imprime();
	getchar();
	return 0;
}
