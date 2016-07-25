#include <iostream>
#include "InteiroLovelace.h"
#include "Lovelace.h"
using namespace std;

void testes_Lovelace();
void teste_1();
void teste_2();
void teste_3();
void teste_4();
void teste_5();

int main()
{
	testes_Lovelace();
	return 0;
}

void testes_Lovelace(){
	cout << "Selecione o teste que deseja fazer:" << endl;
	cout << "[1] Teste 1 - Subtração" << endl;
	cout << "[2] Teste 2 - Comparações" << endl;
	cout << "[3] Teste 3 - Adição" << endl;
	cout << "[4] Teste 4 - Multiplicação" << endl;
	cout << "[4] Teste 5 - Multiplicação melhorada" << endl;
	int c;
	cin >> c;
	switch (c){
		case 1:
			teste_1();
			break;
		case 2:
			teste_2();
			break;
		case 3:
			teste_3();
			break;
		case 4:
			teste_4();
			break;
		case 5:
			teste_5();
			break;

		default:
			teste_1();
			break;
	}

	getchar();
	system("pause");
}

void teste_1(){
	Lovelace Num1, Num2, Num3, resultado;

	cout << "Teste 1 - Subtração de Valores" << endl;
	cout << "Digite os valores de Num1(maior número), Num2 e Num3 abaixo." << endl <<
			"Num1: ";
	cin >> Num1;
	cout << "Num2: ";
	cin >> Num2;
	cout << "Num3: ";
	cin >> Num3;

	cout << Num1 << " - "  << Num2 << " = ";
	resultado = (Num1-Num2);
	resultado.imprimirInfo();
	cout << resultado << endl;
	cout << Num1 << " - "  << Num3 << " = ";
	resultado = (Num1-Num3);
	cout << resultado << endl;

	cout << endl << endl;
	Num1.imprimirInfo();
	Num2.imprimirInfo();
	Num3.imprimirInfo();
	cout << endl;
}

void teste_2(){
	Lovelace A, B, C, D;
	cout << "Teste 2 - Comparação de Valores" << endl;
	cout << "Digite os valores de A, B, C e D abaixo." << endl <<
			"A: ";
	cin >> A;
	cout << "B: ";
	cin >> B;
	cout << "C: ";
	cin >> C;
	cout << "D: ";
	cin >> D;

	cout << "A (" << A << ")" << ((A==B)?"":"nao ") << "eh igual a B (" << B << ")" << endl;
	cout << "A (" << A << ")" << ((A==C)?"":"nao ") << "eh igual a C (" << C << ")" << endl;
	cout << "A (" << A << ")" << ((A==D)?"":"nao ") << "eh igual a D (" << D << ")" << endl;

	cout << endl;

	cout << "A (" << A << ")" << ((A>B)?"":"nao ") << "eh maior que B (" << B << ")" << endl;
	cout << "A (" << A << ")" << ((A>C)?"":"nao ") << "eh maior que C (" << C << ")" << endl;
	cout << "A (" << A << ")" << ((A>D)?"":"nao ") << "eh maior que D (" << D << ")" << endl;

	cout << endl;

	cout << "A (" << A << ")" << ((A<B)?"":"nao ") << "eh menor que B (" << B << ")" << endl;
	cout << "A (" << A << ")" << ((A<C)?"":"nao ") << "eh menor que C (" << C << ")" << endl;
	cout << "A (" << A << ")" << ((A<D)?"":"nao ") << "eh menor que D (" << D << ")" << endl;

	cout << endl;

	cout << "A (" << A << ")" << ((A>=B)?"":"nao ") << "eh maior ou igual a B (" << B << ")" << endl;
	cout << "A (" << A << ")" << ((A>=C)?"":"nao ") << "eh maior ou igual a C (" << C << ")" << endl;
	cout << "A (" << A << ")" << ((A>=D)?"":"nao ") << "eh maior ou igual a D (" << D << ")" << endl;

	cout << endl;

	cout << "A (" << A << ")" << ((A<=B)?"":"nao ") << "eh menor ou igual a B (" << B << ")" << endl;
	cout << "A (" << A << ")" << ((A<=C)?"":"nao ") << "eh menor ou igual a C (" << C << ")" << endl;
	cout << "A (" << A << ")" << ((A<=D)?"":"nao ") << "eh menor ou igual a D (" << D << ")" << endl;

	cout << endl << endl;
	A.imprimirInfo();
	B.imprimirInfo();
	C.imprimirInfo();
	D.imprimirInfo();
	cout << endl;
}

void teste_3(){
	Lovelace Num1, Num2, Num3, Num4, resultado;

	cout << "Teste 3 - Adição de Valores" << endl;
	cout << "Digite os valores de Num1, Num2, Num3 e Num4 abaixo." << endl <<
			"Num1: ";
	cin >> Num1;
	cout << "Num2: ";
	cin >> Num2;
	/*
	cout << "Num3: ";
	cin >> Num3;
	cout << "Num4: ";
	cin >> Num4;
	 //*/
	cout << Num1 << " + "  << Num2 << " = ";
	resultado = (Num1+Num2);
	cout << resultado << endl;

	/*
	cout << Num1 << " + "  << Num3 << " = ";
	resultado = (Num1+Num3);
	cout << resultado << endl;

	cout << Num1 << " + "  << Num4 << " = ";
	resultado = (Num1+Num4);
	cout << resultado << endl;
	//*/
	cout << endl << endl;
	Num1.imprimirInfo();
	Num2.imprimirInfo();
	/*
	Num3.imprimirInfo();
	Num4.imprimirInfo();
	//*/
	cout << endl;
}

void teste_4(){
	Lovelace Num1, Num2, Num3, Num4, resultado;

	cout << "Teste 4 - Multiplicação de Valores" << endl;
	cout << "Digite os valores de Num1, Num2, Num3 e Num4 abaixo." << endl <<
			"Num1: ";
	cin >> Num1;
	cout << "Num2: ";
	cin >> Num2;
	Num1.imprimirInfo();
	Num2.imprimirInfo();
	cout << "Num3: ";
	cin >> Num3;
	cout << "Num4: ";
	cin >> Num4;

	cout << Num1 << " * "  << Num2 << " = ";
	resultado = (Num1*Num2);
	cout << resultado << endl;

	cout << Num1 << " * "  << Num3 << " = ";
	resultado = (Num1*Num3);
	cout << resultado << endl;

	cout << Num1 << " * "  << Num4 << " = ";
	resultado = (Num1*Num4);
	cout << resultado << endl;

	cout << endl << endl;
	Num1.imprimirInfo();
	Num2.imprimirInfo();
	Num3.imprimirInfo();
	Num4.imprimirInfo();
	cout << endl;


}

void teste_5(){
	Lovelace A,B,C,res;

	cout << "Teste 4 - Multiplicação de Valores" << endl;
	cout << "Digite os valores de A, B e C abaixo." << endl <<
			"A: ";
	cin >> A;
	cout << "B: ";
	cin >> B;
	cout << "C: ";
	cin >> C;

	cout << "A = "<< A << endl <<
			"B = " << B << endl <<
			"C = " << C << endl;
	res= A*A;
	cout << "A*A = " << res << endl;
	res = A*B;
	cout << "A*B = " << res << endl;
	res= A*C;
	cout << "A*C = " << res <<endl;
	res= B*B;
	cout << "B*B = " << res <<endl;
	res= C*B;
	cout << "C*B = " << res << endl;
	res= C*C;
	cout << "C*C = " << res << endl;
}
