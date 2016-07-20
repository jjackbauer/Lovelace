#include <iostream>
#include "InteiroLovelace.h"
using namespace std;

int main()
{
	Lovelace A,B;
	int c;
	A.SetDigito(0,1);

	while(1){
		B=A.Soma(&B,&A);
		B.Imprime();
		getchar();
	}

	/*A.Imprime();
	B.Imprime();
	A = A.Soma(&A,&B);
	A.Imprime();//*/
	return 0;
}
