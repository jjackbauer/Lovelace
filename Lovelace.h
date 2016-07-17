#ifndef LOVELACE_H
#define LOVELACE_H
#include <iostream>
#include<cstdlib>

using namespace std;

class Lovelace
{	
	private:
		char *Algarismos;
		long long int Tamanho;
		long long int QuantidadeAlgarismos;
		bool Sinal;
		bool Ezero;
		void ExpandeAlgarismos();
		
	public:
		static long long int Precisao;
		static char TabelaDeConversao[10];
		static long long int AlgarismosExibicao;
		
		Lovelace();
		~Lovelace();
		void Imprime();
		void GetBitWise(long long int Posicao,char &A, char &B);//Correção do diagrama: setor desnecessário
		void SetBitWise(long long int Posicao,char A, char B);//Faltou parametro posição no UML.
		char GetDigito(long long int Posicao);
		void SetDigito(long long int Posicao, char Digito);
		long long int GetTamanho();
		void SetTamanho(long long int Tamanho);
		long long int GetQuantidadeAlgarismos();
		void SetQuantidadeAlgarismos(long long int Tamanho);
		long long int GetAlgarismosExibicao();
		void SetAlgarismosExibicao(long long int Numero);
		int GetSinal();
		void SetSinal(int Sinal);
		bool VerificaEzero(); // Nome redefinido por possuir nome conflitante com atributo no diagrama UML.
		void SetZero(bool Zero);
		virtual Lovelace& Soma(Lovelace A, Lovelace B);
		virtual Lovelace& Subtracao(Lovelace A, Lovelace B);
		virtual Lovelace& Multiplicacao(Lovelace A, Lovelace B);
		virtual Lovelace& Divisao(Lovelace A, Lovelace B);
		virtual Lovelace& InversaoDeSinal(Lovelace A);
		virtual Lovelace& Inversao(Lovelace A);
		virtual Lovelace& Exponenciacao(Lovelace A, Lovelace X);
		virtual Lovelace& Fatorial(Lovelace N);



};

#endif
