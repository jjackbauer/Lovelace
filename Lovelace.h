#ifndef LOVELACE_H
#define LOVELACE_H
#include <iostream>
#include <cstdlib>

using namespace std;

class Lovelace{//Representa numero natural
	protected:
		char *algarismos;
		void inicializar();
		void zerar();
		void copiarAlgarismos(const Lovelace &deA, Lovelace &paraB);
	private:
		long long int tamanho;
		long long int quantidadeAlgarismos;
		bool zero;	//Alterada para melhor uso;
		void expandirAlgarismos();
		void reduzirAlgarismos();
		bool vefEhZeroBF();
		int	removeZerosNaoSignificativos();
		int getMenorDivisao(Lovelace &maior,Lovelace &menor,Lovelace &saida);
		void concatenaNumeros(const Lovelace &maisSiginificativo,const Lovelace &menosSignificativo,Lovelace &saida);
		void inverteNumero(const Lovelace &entrada, Lovelace &saida);

		static long long int algarismosExibicao;
		static long long int Precisao;

	public:
		static char TabelaDeConversao[10];

		static long long int getAlgarismosExibicao();
		static void setAlgarismosExibicao(long long int novoAlgarismosExibicao);

		Lovelace();
		Lovelace(const Lovelace &copiarLovelace);
		~Lovelace();
		void imprimir()const;
		void imprimir(char separador) const;
		void imprimirInfo(int opcao = 0) const;
		void getBitwise(long long int Posicao,char &A, char &B) const;//Correção do diagrama: setor desnecessário
		void setBitwise(long long int Posicao,char A, char B);//Faltou parametro posição no UML.
		char getDigito(long long int Posicao) const;
		void setDigito(long long int Posicao, char Digito);
		long long int getTamanho() const;
		void setTamanho(long long int novoTamanho);
		long long int getQuantidadeAlgarismos() const;
		void setQuantidadeAlgarismos(long long int novaQuantidadeAlgarismos);
		bool eZero() const; 	// Nome Redefinido de VerificarEZero para eZero
						// Nome redefinido por possuir nome conflitante com atributo no diagrama UML.
		bool naoEZero();
		void setZero(bool novoValor);
		Lovelace somar(Lovelace &A, Lovelace &B);
		Lovelace subtrair(Lovelace &A, Lovelace &B);
		Lovelace multiplicar_burro(Lovelace &A, Lovelace &B);
		Lovelace multiplicar(Lovelace &A, Lovelace &B);
	    void     dividir(Lovelace &A, Lovelace &B,Lovelace &resultado,Lovelace &resto);
		Lovelace dividir_burro(Lovelace &A, Lovelace &B, bool quocienteOuResto = true);
		/*Lovelace resto(Lovelace &A, Lovelace &B);
		Lovelace resto_burro(Lovelace &A, Lovelace &B);*/
		Lovelace exponenciar(Lovelace &A, Lovelace &X); /* Tivemos uma idéia para melhorar a exponenciação*/
		Lovelace fatorial();
		Lovelace incrementar();
		Lovelace decrementar();
		Lovelace& atribuir(unsigned long long int &numero);
		Lovelace& atribuir(const int &numero);


		bool eIgualA(Lovelace &B);
		bool eDiferenteDe(Lovelace &B);
		bool eMaiorQue(Lovelace &B);
		bool eMenorQue(Lovelace &B);
		bool eMaiorOuIgualA(Lovelace &B);
		bool eMenorOuIgualA(Lovelace &B);
		bool ePar();
		bool eImpar();

		/*	Sobrecarga de Operadores	*/

		Lovelace& operator=(Lovelace &B);
		Lovelace& operator=(const Lovelace &B); 	// Tem que ser implementado para
											//	copiar os conteúdos de *algarismos
		Lovelace& operator=(unsigned long long int &numero);
		Lovelace& operator=(const int &numero);
		Lovelace& operator+=(Lovelace &B);
		Lovelace& operator-=(Lovelace &B);
		Lovelace& operator*=(Lovelace &B);
		Lovelace& operator/=(Lovelace &B);
		Lovelace& operator%=(Lovelace &B);
		Lovelace& operator^=(Lovelace &B);

		/*	Operações Aritméticas 	*/
		Lovelace operator+(Lovelace &B);
		Lovelace operator-(Lovelace &B);
		Lovelace operator*(Lovelace &B);
		Lovelace operator/(Lovelace &B);
		Lovelace operator%(Lovelace &B);
		Lovelace operator^(Lovelace &B);

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
