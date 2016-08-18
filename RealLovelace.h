#ifndef REALLOVELACE_H
#define REALLOVELACE_H
#include <iostream>
#include<cstdlib>
using namespace std;
#include "InteiroLovelace.h"

class RealLovelace: public InteiroLovelace
{
private:

	long long int expoente;
	static long long int casasDecimaisExibicao;
public:
	
	//Construtores
	RealLovelace();
	RealLovelace(const double A);
	RealLovelace(string A);
	RealLovelace(const RealLovelace A);
	//Sets e Gets
	void setExpoente(long long int X);
	long long int getExpoente();
	static void setCasasDecimaisExibicao(long long int Numero);
	static long long int getCasasDecimaisExibicao();
	//Operações Aritiméticas
	RealLovelace & atribuir(const double A);
	RealLovelace & atribuir(const string A);
	RealLovelace & atribuir(const RealLovelace &A);
	RealLovelace & somar(const RealLovelace B);
	RealLovelace & subtrair(RealLovelace B);
	RealLovelace & multiplicar(RealLovelace B);
	RealLovelace & dividir(RealLovelace B);
	RealLovelace & Inversao();
	RealLovelace & Exponenciacao(RealLovelace X);
	//Entrada e Saída
	void imprimir();
	void ler();


	

};

#endif
