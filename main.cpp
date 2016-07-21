#include <iostream>
#include "InteiroLovelace.h"
using namespace std;

int main()
{
	//Contador///*
	Lovelace A,B;
	int c;

	/*A.SetDigito(0,0);
	A.SetDigito(1,1);//*///10 em 10

	A.SetDigito(0,1);//1 em 1

	///*
	while(1){
		B=A.Soma(&B,&A);

		//cout << "Numero abaixo: " << endl;
		B.Imprime();
		//getchar();
	}//*///FIM CONTADOR


	//*/
	/*
	A.SetDigito(0,9);
	A.SetDigito(1,9);
	A.SetDigito(2,9);

	B.SetDigito(0,9);

	A = A.Soma(&A,&B);
	*/
	/*A.Imprime();
	B.Imprime();
	A = A.Soma(&A,&B);
	A.Imprime();//*/
	return 0;
}
