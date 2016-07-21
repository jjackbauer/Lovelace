#ifndef LOVELACE_H
#define LOVELACE_H
#include <iostream>
#include<cstdlib>

using namespace std;

class Lovelace//Representa numero natural
{	
private:
	char *algarismos;
	long long int tamanho;
	long long int quantidadeAlgarismos;
	bool sinal;//Deve ser removido
	bool zero;	//Alterada para melhor uso;
	void ExpandeAlgarismos();
	void reduzAlgarismos();

	static long long int algarismosExibicao;
	static long long int Precisao;

public:
	static char TabelaDeConversao[10];

	static long long int getAlgarismosExibicao();
	static void setAlgarismosExibicao(long long int novoAlgarismosExibicao);

	Lovelace();
	~Lovelace();
	void Imprime();
	void getBitwise(long long int Posicao,char &A, char &B);//Correção do diagrama: setor desnecessário
	void setBitwise(long long int Posicao,char A, char B);//Faltou parametro posição no UML.
	char getDigito(long long int Posicao);
	void setDigito(long long int Posicao, char Digito);
	long long int getTamanho();
	void setTamanho(long long int novoTamanho);
	long long int getQuantidadeAlgarismos();
	void setQuantidadeAlgarismos(long long int novaQuantidadeAlgarismos);

	int getSinal();
	void setSinal(int novoSinal);
	bool eZero(); 	// Nome Redefinido de VerificarEZero para eZero
					// Nome redefinido por possuir nome conflitante com atributo no diagrama UML.
	void setZero(bool novoValor);
	Lovelace& somar(Lovelace &A, Lovelace &B);
	Lovelace& subtrair(Lovelace *A, Lovelace *B);
	Lovelace& multiplicar(Lovelace *A, Lovelace *B);
	Lovelace& dividir(Lovelace *A, Lovelace *B);
	Lovelace& inverterSinal(Lovelace *A);
	Lovelace& Inversao(Lovelace *A);
	Lovelace& Exponenciacao(Lovelace *A, Lovelace *X);

	Lovelace& incrementar();
	Lovelace& decrementar();

	bool eIgualA(Lovelace &B);
	bool eDiferenteDe(Lovelace &B);
	bool eMaiorQue(Lovelace &B);
	bool eMenorQue(Lovelace &B);
	bool eMaiorOuIgualA(Lovelace &B);
	bool eMenorOuIgualA(Lovelace &B);

	/*	Sobrecarga de Operadores	*/
	/*	Operações Aritméticas */
	//Lovelace& operator=(Lovelace &B);
	Lovelace& operator+(Lovelace &B);
	Lovelace& operator-(Lovelace &B);
	//Lovelace& operator*(Lovelace &B);
	Lovelace& operator/(Lovelace &B);
	Lovelace& operator+=(Lovelace &B);
	Lovelace& operator-=(Lovelace &B);
	Lovelace& operator*=(Lovelace &B);
	Lovelace& operator/=(Lovelace &B);

	/* Operações de Comparação */
	friend bool operator==(Lovelace &A, Lovelace &B);
	friend bool operator!=(Lovelace &A, Lovelace &B);
	friend bool operator>(Lovelace &A, Lovelace &B);
	friend bool operator<(Lovelace &A, Lovelace &B);
	friend bool operator>=(Lovelace &A, Lovelace &B);
	friend bool operator<=(Lovelace &A, Lovelace &B);


};

#endif
