#include <iostream>
#include "InteiroLovelace.h"
using namespace std;

int main()
{

	Lovelace Num1, Num2, Num3;

	Num1 = 487833;
	Num2 = 9689;
	Num3 = 0;

	Num3 = Num1 - Num2;

	Num1.imprimir();
	Num2.imprimir();
	Num3.imprimir();

	getchar();

	//Contador///*
	/*Lovelace A, B, C, D;
	Lovelace Num1, Num2, Num3;
	int c;

	A = 1000;

	B = 999;

	C = 9999;

	D = 374;

	Num1 = 487233;
	Num2 = 9689;
	Num3 = 0;

	Num3 = Num1 - Num2;

	cout << "O valor de Num3 (Num1 - Num2) 3: " << Num3 << endl;

	cout << (A<B) << endl
		<< (A<C) << endl
		<< (D<C) << endl
		<< (B<A) << endl;


	getchar();

	A = 126679823;
	B = 200000;
	A.imprimir();
	B.imprimir();
	getchar();
	C = A*B;

	cout << "Imprimindo C" << endl;
	C.imprimirInfo();
	cout << "Antes do GETCHAR" << endl;
	getchar();

	A.SetDigito(0,0);
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
	A.imprimir();
	cout<<"B"<<endl;
	B.imprimir();
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
	/*A.imprimir();
	B.imprimir();
	A = A.Soma(&A,&B);
	A.imprimir();//*/

	return 0;
}
