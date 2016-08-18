#ifndef LOVELACE_HPP_
#define LOVELACE_HPP_
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <utility>
#include <string>

#define pause cout<<"Aperte enter para continuar..."<<endl; getchar();
#define pauseclear pause system(clear || cls);

using namespace std;

class Lovelace{//Representa numero natural
	protected:
		char *algarismos;
		void inicializar();
		void zerar();
		void copiarAlgarismos(const Lovelace &deA, Lovelace &paraB);
		void errorMessage(string message) const;
	private:
		long long int tamanho;
		long long int quantidadeAlgarismos;
		bool zero;	//Alterada para melhor uso;
		void expandirAlgarismos();
		void reduzirAlgarismos();
		bool vefEhZeroBF();
		int	removeZerosNaoSignificativos();


		int getMenorDivisao(const Lovelace &maior,const Lovelace &menor,Lovelace &saida) const;
		void concatenaNumeros(const Lovelace &maisSiginificativo,const Lovelace &menosSignificativo,Lovelace &saida) const;
		void inverteNumero(Lovelace &saida) const;

		static long long int algarismosExibicao;
		static long long int Precisao;

	public:
		//Ex membros privados que devem ser publicos para serem reutilizados nas subclasses

		static char TabelaDeConversao[10];

		static long long int getAlgarismosExibicao();
		static void setAlgarismosExibicao(long long int novoAlgarismosExibicao);

		Lovelace();
		Lovelace(const Lovelace &copiarLovelace);
		Lovelace(const char*,int tamanho,int quantidadeAlgarismos,bool zero);

		~Lovelace();
		void imprimir() const;
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
		bool naoEZero() const;
		void setZero(bool novoValor);
		Lovelace somar(const Lovelace &B) const;
		Lovelace subtrair(const Lovelace &B) const;
		Lovelace multiplicar_burro(const Lovelace &B) const;
		Lovelace multiplicar(const Lovelace &B) const;
	    void     dividir(const Lovelace &B,Lovelace &resultado,Lovelace &resto) const;
		Lovelace dividir_burro(const Lovelace &B, bool quocienteOuResto = true) const;
		/*Lovelace resto(Lovelace &A, Lovelace &B);
		Lovelace resto_burro(Lovelace &A, Lovelace &B);*/
		Lovelace exponenciar(const Lovelace &X) const; /* Tivemos uma idéia para melhorar a exponenciação*/
		Lovelace fatorial() const;
		Lovelace incrementar();
		Lovelace decrementar();
		Lovelace& atribuir(unsigned long long int numero);
		Lovelace& atribuir(const int &numero);
		Lovelace& atribuir(const Lovelace& numero);

		bool eIgualA(const Lovelace &B) const;
		bool eDiferenteDe(const Lovelace &B) const;
		bool eMaiorQue(const Lovelace &B) const;
		bool eMenorQue(const Lovelace &B) const;
		bool eMaiorOuIgualA(const Lovelace &B) const;
		bool eMenorOuIgualA(const Lovelace &B) const;
		bool ePar() const;
		bool eImpar() const;

		/*	Sobrecarga de Operadores	*/

		Lovelace& operator=(Lovelace &B);//Porque tem essas duas implementações?
		Lovelace& operator=(const Lovelace &B); 	// Tem que ser implementado para
											//	copiar os conteúdos de *algarismos
		Lovelace& operator=(const unsigned long long int &numero);
		Lovelace& operator=(const int &numero);
		Lovelace& operator+=(const Lovelace &B);
		Lovelace& operator-=(const Lovelace &B);
		Lovelace& operator*=(const Lovelace &B);
		Lovelace& operator/=(const Lovelace &B);
		Lovelace& operator%=(const Lovelace &B);
		Lovelace& operator^=(const Lovelace &B);

		/*	Operações Aritméticas 	*/
		Lovelace operator+(const Lovelace &B) const;
		Lovelace operator-(const Lovelace &B) const;
		Lovelace operator*(const Lovelace &B) const;
		Lovelace operator/(const Lovelace &B) const;
		Lovelace operator%(const Lovelace &B) const;
		Lovelace operator^(const Lovelace &B) const;

		/*	Operações Inc/Dec 	*/
		Lovelace& operator++();
		Lovelace& operator--();
		Lovelace operator++(int semuso);
		Lovelace operator--(int semuso);

		/* 	Operações de Comparação 	*/
		friend bool operator==(const Lovelace &A,const Lovelace &B);
		friend bool operator!=(const Lovelace &A,const Lovelace &B);
		friend bool operator>(const Lovelace &A,const Lovelace &B);
		friend bool operator<(const Lovelace &A,const Lovelace &B);
		friend bool operator>=(const Lovelace &A,const Lovelace &B);
		friend bool operator<=(const Lovelace &A,const Lovelace &B);

		/*	Operações de Ext/Ins de Fluxo 	*/
		friend std::ostream &operator<<(std::ostream &out,const Lovelace &A);
		friend std::istream &operator>>(std::istream &in,Lovelace &A);
};

#endif /* LOVELACE_HPP_ */
