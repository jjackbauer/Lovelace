#ifndef LOVELACEREAL_H
#define LOVELACEREAL_H

#include "Lovelace.h"

class LovelaceReal: Lovelace
{
private:
	char *AlgarismosDecimais;
	long long int TamanhoDecimais;

public:
	static long long int CasasDecimaisExibicao;
	
	LovelaceReal();
	~LovelaceReal();
	
	void SetAlgarismoDecimal(long long int Posicao, char Algarismo);
	void SetTamanhoDecimais(long long int TamanhoVirgual);
	void SetCasasDecimaisExibicao(long long int Numero);

	char GetAlgarismoDecimal(long long int Posicao);
	long long int GetTamanhoDecimais();
	long long int GetCasasDecimaisExibicao();
	

	&LovelaceReal Atribuicao(double A);
	&LovelaceReal Atribuicao(LovelaceReal &A, LovelaceReal B);
	&LovelaceReal Soma(LovelaceReal A, LovelaceReal B);
	&LovelaceReal Subtracao(LovelaceReal A, LovelaceReal B);
	&LovelaceReal Multiplicacao(LovelaceReal A, LovelaceReal B);
	&LovelaceReal Divisao(LovelaceReal A, LovelaceReal B);
	&LovelaceReal InversaoDeSinal(LovelaceReal A);
	&LovelaceReal Inversao(LovelaceReal A);
	&LovelaceReal Exponenciacao(LovelaceReal A, LovelaceReal X);
	&LovelaceReal Fatorial(LovelaceReal N);
	void Imprime();

	

};

#endif