#include <iostream>
#include <cstdio>
#include "InteiroLovelace.h"
#include "Lovelace.h"
using namespace std;

void testes_Lovelace();
void teste_1();
void teste_2();
void teste_3();
void teste_4();
void teste_5();
void teste_6();
void teste_7();
void teste_8();
void teste_9();
void teste_10();

int main(){
	while (char opcao = 1){
		testes_Lovelace();
		cout << "Deseja fazer outro teste? [0] Sair [1] Sim." << endl;
		cin >> opcao;
	}
	return 0;
}

void testes_Lovelace(){
	cout << "Selecione o teste que deseja fazer:" << endl;
	cout << "[1] Teste 1 - 		[-]	Subtração" << endl;
	cout << "[2] Teste 2 - 		[>]	Comparações" << endl;
	cout << "[3] Teste 3 - 		[+]	Adição" << endl;
	cout << "[4] Teste 4 - 		[*]	Multiplicação Burra" << endl;
	cout << "[5] Teste 5 - 		[*]	Multiplicação" << endl;
	cout << "[6] Teste 6 - 		[^]	Exponenciação" << endl;
	cout << "[7] Teste 7 - 		[/]	Divisão Burra" << endl;
	cout << "[8] Teste 8 - 		[/]	Divisão e Resto" << endl;
	cout << "[9] Teste 9 - 		[!]	Fatorial" << endl;
	cout << "[10] Teste 10 - 	[%]	Resto da Divisão Burra" << endl;
	cout << "[11] Teste 11 - 	[%]	Resto da Divisão" << endl;
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
		case 6:
			teste_6();
			break;
		case 7:
			teste_7();
			break;
		case 8:
			teste_8();
			break;
		case 9:
			teste_9();
			break;
		case 10:
			teste_10();
			break;
		default:
			teste_1();
			break;
	}

	getchar();
	system("pause");
}

void teste_1(){
	Lovelace A, B, C, res;

	cout << "Teste 1 - Subtração de Valores" << endl;
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
	res = A-A;
	cout << "A-A = " << res << endl;
	res = A-B;
	cout << "A-B = " << res << endl;
	res = A-C;
	cout << "A-C = " << res <<endl;
	res = B-A;
	cout << "B-A = " << res <<endl;
	res = B-B;
	cout << "B-B = " << res <<endl;
	res = B-C;
	cout << "B-C = " << res <<endl;
	res = C-A;
	cout << "C-A = " << res << endl;
	res = C-B;
	cout << "C-B = " << res << endl;
	res = C-C;
	cout << "C-C = " << res << endl;
	getchar();

	cout << "A (" << A << ") " << ((A.ePar())?"":"nao ") << "eh par" << endl;
	cout << "A (" << A << ") " << ((A.eImpar())?"":"nao ") << "eh impar" << endl;
	cout << "B (" << B << ") " << ((B.ePar())?"":"nao ") << "eh par" << endl;
	cout << "B (" << B << ") " << ((B.eImpar())?"":"nao ") << "eh impar" << endl;
	cout << "C (" << C << ") " << ((C.ePar())?"":"nao ") << "eh par" << endl;
	cout << "C (" << C << ") " << ((C.eImpar())?"":"nao ") << "eh impar" << endl;
	A.imprimirInfo();
	B.imprimirInfo();
	C.imprimirInfo();
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

	cout << "Teste 4 - Multiplicação Burra de Valores" << endl;
	cout << "Digite os valores de Num1, Num2, Num3 e Num4 abaixo." << endl <<
			"Num1: ";
	cin >> Num1;
	cout << endl << "Num2: ";
	cin >> Num2;
	Num1.imprimirInfo();
	Num2.imprimirInfo();
	cout << "Num3: ";
	cin >> Num3;
	cout << "Num4: ";
	cin >> Num4;

	cout << Num1 << " * "  << Num2 << " = ";
	resultado = resultado.multiplicar_burro(Num1,Num2);
	cout << resultado << endl;

	cout << Num1 << " * "  << Num3 << " = ";
	resultado = resultado.multiplicar_burro(Num1,Num3);
	cout << resultado << endl;

	cout << Num1 << " * "  << Num4 << " = ";
	resultado = resultado.multiplicar_burro(Num1,Num4);
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

	cout << "Teste 5 - Multiplicação de Valores" << endl;
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

void teste_6(){
	Lovelace A,B,C,res;

	cout << "Teste 6 - Exponenciação de Valores" << endl;
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
	res = A^A;
	cout << "A^A = " << res << endl;
	res = A^B;
	cout << "A^B = " << res << endl;
	res = A^C;
	cout << "A^C = " << res <<endl;
	res = B^B;
	cout << "B^B = " << res <<endl;
	res = C^B;
	cout << "C^B = " << res << endl;
	res = C^C;
	cout << "C^C = " << res << endl;
}

void teste_7(){
	Lovelace A, B, C, res;

	cout << "Teste 7 - Divisão de Valores" << endl;
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
	res = A/A;
	cout << "A/A = " << res << endl;
	res = A/B;
	cout << "A/B = " << res << endl;
	res = A/C;
	cout << "A/C = " << res <<endl;
	res = B/A;
	cout << "B/A = " << res <<endl;
	res = B/B;
	cout << "B/B = " << res <<endl;
	res = B/C;
	cout << "B/C = " << res <<endl;
	res = C/A;
	cout << "C/A = " << res << endl;
	res = C/B;
	cout << "C/B = " << res << endl;
	res = C/C;
	cout << "C/C = " << res << endl;
	getchar();

	cout << "A (" << A << ") " << ((A.ePar())?"":"nao ") << "eh par" << endl;
	cout << "A (" << A << ") " << ((A.eImpar())?"":"nao ") << "eh impar" << endl;
	cout << "B (" << B << ") " << ((B.ePar())?"":"nao ") << "eh par" << endl;
	cout << "B (" << B << ") " << ((B.eImpar())?"":"nao ") << "eh impar" << endl;
	cout << "C (" << C << ") " << ((C.ePar())?"":"nao ") << "eh par" << endl;
	cout << "C (" << C << ") " << ((C.eImpar())?"":"nao ") << "eh impar" << endl;
	A.imprimirInfo();
	B.imprimirInfo();
	C.imprimirInfo();
}

void teste_8(){
	Lovelace A, B, C, quociente, resto;

	cout << "Teste 8 - Divisão e Resto da Divisão de Valores" << endl;
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
	A.dividir(A,A,quociente,resto);
	cout << "A/A = " << quociente << " A%A = " << resto << endl;
	getchar();
	A.dividir(A,B,quociente,resto);
	cout << "A/B = " << quociente << " A%B = " << resto << endl;
	A.dividir(A,C,quociente,resto);
	cout << "A/C = " << quociente << " A%C = " << resto << endl;
	A.dividir(B,A,quociente,resto);
	cout << "B/A = " << quociente << " B%A = " << resto << endl;
	A.dividir(B,B,quociente,resto);
	cout << "B/B = " << quociente << " B%B = " << resto << endl;
	A.dividir(B,C,quociente,resto);
	cout << "B/C = " << quociente << " B%C = " << resto << endl;
	A.dividir(C,A,quociente,resto);
	cout << "C/A = " << quociente << " C%A = " << resto << endl;
	A.dividir(C,B,quociente,resto);
	cout << "C/B = " << quociente << " C%B = " << resto << endl;
	A.dividir(C,C,quociente,resto);
	cout << "C/C = " << quociente << " C%C = " << resto << endl;
	getchar();

	cout << "A (" << A << ") " << ((A.ePar())?"":"nao ") << "eh par" << endl;
	cout << "A (" << A << ") " << ((A.eImpar())?"":"nao ") << "eh impar" << endl;
	cout << "B (" << B << ") " << ((B.ePar())?"":"nao ") << "eh par" << endl;
	cout << "B (" << B << ") " << ((B.eImpar())?"":"nao ") << "eh impar" << endl;
	cout << "C (" << C << ") " << ((C.ePar())?"":"nao ") << "eh par" << endl;
	cout << "C (" << C << ") " << ((C.eImpar())?"":"nao ") << "eh impar" << endl;
	A.imprimirInfo();
	B.imprimirInfo();
	C.imprimirInfo();
}

void teste_9(){
	Lovelace A,B,C,res;

	cout << "Teste 9 - Fatorial de Valores" << endl;
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
	res = A.fatorial();
	cout << "A! = " << res << endl << endl;
	res = B.fatorial();
	cout << "B! = " << res << endl << endl;
	res = C.fatorial();
	cout << "C! = " << res << endl << endl;
}

void teste_10(){
	Lovelace A, B, C, res;

	cout << "Teste 10 - Resto da Divisão Burra de Valores" << endl;
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
	res = A%A;
	cout << "A%A = " << res << endl;
	res = A%B;
	cout << "A%B = " << res << endl;
	res = A%C;
	cout << "A%C = " << res <<endl;
	res = B%A;
	cout << "B%A = " << res <<endl;
	res = B%B;
	cout << "B%B = " << res <<endl;
	res = B%C;
	cout << "B%C = " << res <<endl;
	res = C%A;
	cout << "C%A = " << res << endl;
	res = C%B;
	cout << "C%B = " << res << endl;
	res = C%C;
	cout << "C%C = " << res << endl;
	getchar();

	cout << "A (" << A << ") " << ((A.ePar())?"":"nao ") << "eh par" << endl;
	cout << "A (" << A << ") " << ((A.eImpar())?"":"nao ") << "eh impar" << endl;
	cout << "B (" << B << ") " << ((B.ePar())?"":"nao ") << "eh par" << endl;
	cout << "B (" << B << ") " << ((B.eImpar())?"":"nao ") << "eh impar" << endl;
	cout << "C (" << C << ") " << ((C.ePar())?"":"nao ") << "eh par" << endl;
	cout << "C (" << C << ") " << ((C.eImpar())?"":"nao ") << "eh impar" << endl;
	A.imprimirInfo();
	B.imprimirInfo();
	C.imprimirInfo();
}


