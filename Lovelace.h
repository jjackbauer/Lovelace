#ifndef LOVELACE_H
#define LOVELACE_H
#include <iostream>
#include <cstdlib>

using namespace std;

class Lovelace//Representa numero natural
{	
private:
	char *Algarismos;
	long long int Tamanho;
	long long int QuantidadeAlgarismos;
	bool Sinal;//Deve ser removido
	bool Ezero;
	void ExpandeAlgarismos(int numeroDeCasas = 1);
	void reduzAlgarismos(int numeroDeCasas = 1);

	static long long int algarismosExibicao;
	static long long int Precisao;

public:
	static char TabelaDeConversao[10];

	static long long int getAlgarismosExibicao();
	static void setAlgarismosExibicao(long long int novoAlgarismosExibicao);

	Lovelace();
	~Lovelace();
	void Imprime();
	void GetBitwise(long long int Posicao,char &A, char &B);//Correção do diagrama: setor desnecessário
	void SetBitwise(long long int Posicao,char A, char B);//Faltou parametro posição no UML.
	char GetDigito(long long int Posicao);
	void SetDigito(long long int Posicao, char Digito);
	long long int GetTamanho();
	void SetTamanho(long long int Tamanho);
	long long int GetQuantidadeAlgarismos();
	void SetQuantidadeAlgarismos(long long int Tamanho);

	int GetSinal();
	void SetSinal(int Sinal);
	bool VerificaEzero(); // Nome redefinido por possuir nome conflitante com atributo no diagrama UML.
	void SetZero(bool Zero);
	Lovelace& Soma(Lovelace *A, Lovelace *B);
	Lovelace& Subtracao(Lovelace *A, Lovelace *B);
	Lovelace& Multiplicacao(Lovelace *A, Lovelace *B);
	Lovelace& Divisao(Lovelace *A, Lovelace *B);
	Lovelace& InversaoDeSinal(Lovelace *A);
	Lovelace& Inversao(Lovelace *A);
	Lovelace& Exponenciacao(Lovelace *A, Lovelace *X);


};

#endif
