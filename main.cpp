#include <iostream>
#include "InteiroLovelace.h"
using namespace std;

int main()
{
	InteiroLovelace A;
	int c;

	for(c=0;c<100;c++)
		A.SetDigito(c,(c+1)%10);

	A.Imprime();
	getchar();
	return 0;
}
