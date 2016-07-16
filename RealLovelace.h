#ifndef REALLOVELACE_H
#define REALLOVELACE_H
#include <iostream>
#include<cstdlib>
using namespace std;
#include "Lovelace.h"

class RealLovelace: public Lovelace
{
private:
	char *AlgarismosDecimais;
	long long int TamanhoDecimais;

public:
	static long long int CasasDecimaisExibicao;
	
	RealLovelace();
	~RealLovelace();
	
	void SetAlgarismoDecimal(long long int Posicao, char Algarismo);
	void SetTamanhoDecimais(long long int TamanhoVirgual);
	void SetCasasDecimaisExibicao(long long int Numero);

	char GetAlgarismoDecimal(long long int Posicao);
	long long int GetTamanhoDecimais();
	long long int GetCasasDecimaisExibicao();
	

	RealLovelace & Atribuicao(double A);
	RealLovelace & Atribuicao(RealLovelace &A, RealLovelace B);
	RealLovelace & Soma(RealLovelace A, RealLovelace B);
	RealLovelace & Subtracao(RealLovelace A, RealLovelace B);
	RealLovelace & Multiplicacao(RealLovelace A, RealLovelace B);
	RealLovelace & Divisao(RealLovelace A, RealLovelace B);
	RealLovelace & InversaoDeSinal(RealLovelace A);
	RealLovelace & Inversao(RealLovelace A);
	RealLovelace & Exponenciacao(RealLovelace A, RealLovelace X);

	void Imprime();

	

};

#endif
