#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include "InteiroLovelace.h"
#include "Lovelace.h"
#define quantidadeDeNumerosParaTestes 3
using namespace std;

void testes_Lovelace();

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

	map<int, string> cabecalhos;
	map<int, char> operadores;
	map<int, char> letra;
	cabecalhos[1] = "1 - Subtração de Valores";
	cabecalhos[1] = "1 - Comparação de Valores";
	cabecalhos[3] = "3 - Adição de Valores";
	cabecalhos[4] = "4 - Multiplicação Burra de Valores";
	cabecalhos[5] = "5 - Multiplicação de Valores";
	cabecalhos[6] = "6 - Exponenciação de Valores";
	cabecalhos[7] = "7 - Divisão Burra de Valores";
	cabecalhos[8] = "8 - Divisão e Resto da Divisão de Valores";
	cabecalhos[9] = "9 - Fatorial de Valores";
	cabecalhos[10] = "10 - Resto da Divisão Burra de Valores";
	cabecalhos[11] = "11 - Resto da Divisão de Valores";
	operadores[1] = '-';
	operadores[2] = '>';
	operadores[3] = '+';
	operadores[4] = '*';
	operadores[5] = '*';
	operadores[6] = '^';
	operadores[7] = '/';
	operadores[8] = '/';
	operadores[9] = '!';
	operadores[10] = '%';
	operadores[11] = '%';
	letra[0] = 'A';
	letra[1] = 'B';
	letra[2] = 'C';
	letra[3] = 'D';
	letra[4] = 'F';
	letra[5] = 'G';
	letra[6] = 'H';
	letra[7] = 'I';

	int c;
	cin >> c;
	Lovelace numero[quantidadeDeNumerosParaTestes], res,rr;

	cout << "Teste ";
	if (c > 0 && c < 12)
		cout << cabecalhos[c] << endl;
	else
		cout << cabecalhos[(c=1)] << endl;
	cout << "Digite os valores de A, B e C abaixo." << endl;

	for (int cont = 0; cont < quantidadeDeNumerosParaTestes; cont++){
		cout <<	letra[cont] << ": ";
		cin >> numero[cont];
		cout << endl;
		cout <<	letra[cont] << " (" << numero[cont] << ") " << ((numero[cont].ePar())?"":"nao ") << "eh par" << endl;
		cout <<	letra[cont] << " (" << numero[cont] << ") " << ((numero[cont].eImpar())?"":"nao ") << "eh impar" << endl;
	}
	int c1, c2;
	switch (c){
		case 1:	//	Subtração
			for (c1 = 0; c1 < quantidadeDeNumerosParaTestes; c1++){
				for (c2 = 0; c2 < quantidadeDeNumerosParaTestes; c2++){
					res = numero[c1]-numero[c2];
					cout << letra[c1] << '-' << letra[c2] << " = " << res << endl;
				}
			}
			break;
		case 2:	//	Comparação
			for (c1 = 0; c1 < quantidadeDeNumerosParaTestes; c1++){
				for (c2 = 0; c2 < quantidadeDeNumerosParaTestes; c2++){
					cout << letra[c1] << " (" << numero[c1] << ")" <<
							((numero[c1]==numero[c2])?"":"nao ") <<
							"eh igual a" << letra[c2] <<  " (" << numero[c2] << ")" << endl;
				}
			}
			cout << endl;
			for (c1 = 0; c1 < quantidadeDeNumerosParaTestes; c1++){
				for (c2 = 0; c2 < quantidadeDeNumerosParaTestes; c2++){
					cout << letra[c1] << " (" << numero[c1] << ")" <<
							((numero[c1]!=numero[c2])?"":"nao ") <<
							"eh diferente de " << letra[c2] <<  " (" << numero[c2] << ")" << endl;
				}
			}
			cout << endl;
			for (c1 = 0; c1 < quantidadeDeNumerosParaTestes; c1++){
				for (c2 = 0; c2 < quantidadeDeNumerosParaTestes; c2++){
					cout << letra[c1] << " (" << numero[c1] << ")" <<
							((numero[c1]>numero[c2])?"":"nao ") <<
							"eh maior que " << letra[c2] <<  " (" << numero[c2] << ")" << endl;
				}
			}
			cout << endl;
			for (c1 = 0; c1 < quantidadeDeNumerosParaTestes; c1++){
				for (c2 = 0; c2 < quantidadeDeNumerosParaTestes; c2++){
					cout << letra[c1] << " (" << numero[c1] << ")" <<
							((numero[c1]<numero[c2])?"":"nao ") <<
							"eh menor que " << letra[c2] <<  " (" << numero[c2] << ")" << endl;
				}
			}
			cout << endl;
			for (c1 = 0; c1 < quantidadeDeNumerosParaTestes; c1++){
				for (c2 = 0; c2 < quantidadeDeNumerosParaTestes; c2++){
					cout << letra[c1] << " (" << numero[c1] << ")" <<
							((numero[c1]>=numero[c2])?"":"nao ") <<
							"eh maior ou igual a " << letra[c2] <<  " (" << numero[c2] << ")" << endl;
				}
			}
			cout << endl;
			for (c1 = 0; c1 < quantidadeDeNumerosParaTestes; c1++){
				for (c2 = 0; c2 < quantidadeDeNumerosParaTestes; c2++){
					cout << letra[c1] << " (" << numero[c1] << ")" <<
							((numero[c1]<=numero[c2])?"":"nao ") <<
							"eh menor ou igual a " << letra[c2] <<  " (" << numero[c2] << ")" << endl;
				}
			}
			break;
		case 3:		//	Soma
			for (c1 = 0; c1 < quantidadeDeNumerosParaTestes; c1++){
				for (c2 = 0; c2 < quantidadeDeNumerosParaTestes; c2++){
					res = numero[c1]+numero[c2];
					cout << letra[c1] << '+' << letra[c2] << " = " << res << endl;
				}
			}
			break;
		case 4:		//	Multiplicação
			for (c1 = 0; c1 < quantidadeDeNumerosParaTestes; c1++){
				for (c2 = 0; c2 < quantidadeDeNumerosParaTestes; c2++){
					res = numero[c1]*numero[c2];
					cout << letra[c1] << '*' << letra[c2] << " = " << res << endl;
				}
			}
			break;
		case 5:		//	Multiplicação Burra
			for (c1 = 0; c1 < quantidadeDeNumerosParaTestes; c1++){
				for (c2 = 0; c2 < quantidadeDeNumerosParaTestes; c2++){
					res = numero[c1].multiplicar_burro(numero[c2]);
					cout << letra[c1] << '*' << letra[c2] << " = " << res << endl;
				}
			}
			break;
		case 6:		//	Exponenciação
			for (c1 = 0; c1 < quantidadeDeNumerosParaTestes; c1++){
				for (c2 = 0; c2 < quantidadeDeNumerosParaTestes; c2++){
					res = numero[c1]^numero[c2];
					cout << letra[c1] << '^' << letra[c2] << " = " << res << endl;
				}
			}
			break;
		case 7:		//	Divisão Burra
			for (c1 = 0; c1 < quantidadeDeNumerosParaTestes; c1++){
				for (c2 = 0; c2 < quantidadeDeNumerosParaTestes; c2++){
					res = numero[c1]/numero[c2];
					cout << letra[c1] << '/' << letra[c2] << " = " << res << endl;
				}
			}
			break;
		case 8:		//	Divisão e Resto da Divisão
			for (c1 = 0; c1 < quantidadeDeNumerosParaTestes; c1++){
				for (c2 = 0; c2 < quantidadeDeNumerosParaTestes; c2++){
					numero[c1].dividir(numero[c2],res,rr);
					cout << letra[c1] << '/' << letra[c2] << " = " << res <<
							letra[c1] << '%' << letra[c2] << " = " << rr << endl;
				}
			}
			break;
		case 9:		//	Fatorial
			for (c1 = 0; c1 < quantidadeDeNumerosParaTestes; c1++){
					res = numero[c1].fatorial();
					cout << letra[c1] <<  "! = " << res << endl;
			}
			break;
		case 10:	//	Resto da Divisão
			for (c1 = 0; c1 < quantidadeDeNumerosParaTestes; c1++){
				for (c2 = 0; c2 < quantidadeDeNumerosParaTestes; c2++){
					res = numero[c1]%numero[c2];
					cout << letra[c1] << '%' << letra[c2] << " = " << res << endl;
				}
			}
			break;
		default:	//	Padrão
			for (c1 = 0; c1 < quantidadeDeNumerosParaTestes; c1++){
				for (c2 = 0; c2 < quantidadeDeNumerosParaTestes; c2++){
					res = numero[c1]-numero[c2];
					cout << letra[c1] << '-' << letra[c2] << " = " << res << endl;
				}
			}
			break;
	}
	for (int cont = 0; cont < quantidadeDeNumerosParaTestes; cont++)
		numero[cont].imprimirInfo();
}
