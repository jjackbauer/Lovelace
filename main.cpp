#include <iostream>
#include "InteiroLovelace.h"
using namespace std;

int main()
{
	//Contador///*
	Lovelace A,B,C;
	int c;

	A=1235;
	B=1035;
	A.Imprime();
	B.Imprime();
	getchar();
	C = C.multiplicar(A,B);

	C.Imprime();
	getchar();
	/*A.SetDigito(0,0);
	A.SetDigito(1,1);//*///10 em 10

	/*A.setDigito(0,1);//1 em 1

	B.setDigito(0,3);

	C.setDigito(0,3);


	cout << "A " << ((A==B)?"":"nao ") << "eh igual a B" << endl;
	cout << "A " << ((A==C)?"":"nao ") << "eh igual a C" << endl;


	cout << "A " << ((A>C)?"":"nao ") << "eh maior a C" << endl;

	cout << "A " << ((A>=C)?"":"nao ") << "eh maior ou igual a C" << endl;

	cout << "C " << ((C>=A)?"":"nao ") << "eh maior ou igual a A" << endl;

	cout << "C " << ((C>=B)?"":"nao ") << "eh maior ou igual a B" << endl;

	getchar();//*/
	//*
	/*while(1){
		B =A++;
		cout<<"A"<<endl;
		A.Imprime();
		cout<<"B"<<endl;
		B.Imprime();
		getchar();

	}
	//*///FIM CONTADOR


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
