#ifndef LOVELACE_H
#define LOVELACE_H
#include <iostream>
#include <cstdlib>

using namespace std;

class Lovelace{//Representa numero natural
	private:
		char *algarismos;
		long long int tamanho;
		long long int quantidadeAlgarismos;
		bool zero;	//Alterada para melhor uso;
		void expandirAlgarismos();
		void reduzirAlgarismos();
		void copiarAlgarismos(Lovelace &deA, Lovelace &paraB);

		static long long int algarismosExibicao;
		static long long int Precisao;

	public:
		static char TabelaDeConversao[10];

		static long long int getAlgarismosExibicao();
		static void setAlgarismosExibicao(long long int novoAlgarismosExibicao);

		Lovelace();
		//Lovelace(Lovelace &copiarLovelace);
		~Lovelace();
		void imprimir();
		void imprimir(char separador);
		void imprimirInfo();
		void getBitwise(long long int Posicao,char &A, char &B);//Correção do diagrama: setor desnecessário
		void setBitwise(long long int Posicao,char A, char B);//Faltou parametro posição no UML.
		char getDigito(long long int Posicao);
		void setDigito(long long int Posicao, char Digito);
		long long int getTamanho();
		void setTamanho(long long int novoTamanho);
		long long int getQuantidadeAlgarismos();
		void setQuantidadeAlgarismos(long long int novaQuantidadeAlgarismos);
		bool eZero(); 	// Nome Redefinido de VerificarEZero para eZero
						// Nome redefinido por possuir nome conflitante com atributo no diagrama UML.
		void setZero(bool novoValor);
		Lovelace somar(Lovelace &A, Lovelace &B);
		Lovelace subtrair(Lovelace &A, Lovelace &B);
		Lovelace multiplicar(Lovelace &A, Lovelace &B);
		Lovelace multiplicar_improvment(Lovelace &A, Lovelace &B);
		Lovelace dividir(Lovelace &A, Lovelace &B);
		Lovelace Exponenciacao(Lovelace &A, Lovelace &X);
		Lovelace incrementar();
		Lovelace decrementar();
		Lovelace atribuir(unsigned long long int numero);

		bool eIgualA(Lovelace &B);
		bool eDiferenteDe(Lovelace &B);
		bool eMaiorQue(Lovelace &B);
		bool eMenorQue(Lovelace &B);
		bool eMaiorOuIgualA(Lovelace &B);
		bool eMenorOuIgualA(Lovelace &B);

		/*	Sobrecarga de Operadores	*/

		Lovelace& operator=(Lovelace B);
		Lovelace& operator=(unsigned long long int A);
		Lovelace& operator+=(Lovelace &B);
		Lovelace& operator-=(Lovelace &B);
		Lovelace& operator*=(Lovelace &B);
		Lovelace& operator/=(Lovelace &B);

		/*	Operações Aritméticas 	*/
		Lovelace operator+(Lovelace &B);
		Lovelace operator-(Lovelace &B);
		Lovelace operator*(Lovelace &B);
		Lovelace operator/(Lovelace &B);
		Lovelace operator%(Lovelace &B);

		/*	Operações Inc/Dec 	*/
		Lovelace& operator++();
		Lovelace& operator--();
		Lovelace operator++(int semuso);
		Lovelace operator--(int semuso);

		/* 	Operações de Comparação 	*/
		friend bool operator==(Lovelace &A, Lovelace &B);
		friend bool operator!=(Lovelace &A, Lovelace &B);
		friend bool operator>(Lovelace &A, Lovelace &B);
		friend bool operator<(Lovelace &A, Lovelace &B);
		friend bool operator>=(Lovelace &A, Lovelace &B);
		friend bool operator<=(Lovelace &A, Lovelace &B);

		/*	Operações de Ext/Ins de Fluxo 	*/
		friend std::ostream &operator<<(std::ostream &out,Lovelace &A);
		friend std::istream &operator>>(std::istream &in,Lovelace &A);
};

#endif
