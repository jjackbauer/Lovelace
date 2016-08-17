#ifndef INTEIROLOVELCE_H
#define INTEIROLOVELACE_H
#include "Lovelace.h"


using namespace std;

class InteiroLovelace: public Lovelace
{
	private:
		bool sinal;				//	true = positivo; false = negativo
		void inicializar();
		void zerar();
	public:
		InteiroLovelace();
		InteiroLovelace(const InteiroLovelace &copiarInteiroLovelace);
		InteiroLovelace(const Lovelace &copiarLovelace);
		//	~InteiroLovelace();	// Não é necessário

		bool getSinal() const;
		void setSinal(bool novoSinal);
		void toLovelace(const InteiroLovelace &entrada,Lovelace &saida);

		InteiroLovelace 	somar( InteiroLovelace &A, InteiroLovelace &B);
		InteiroLovelace 	subtrair( InteiroLovelace &A, InteiroLovelace &B);
		//InteiroLovelace 	multiplicar_burro(Lovelace &A, InteiroLovelace &B); //Não se faz burrice duas vezes kkkk
		InteiroLovelace 	multiplicar(InteiroLovelace &A,  InteiroLovelace &B);
		void     			dividir(InteiroLovelace &A,  InteiroLovelace &B,InteiroLovelace &resultado,InteiroLovelace &resto);
		//InteiroLovelace 	dividir_burro(InteiroLovelace &A, InteiroLovelace &B, bool quocienteOuResto = true); //eu espero!
		InteiroLovelace		exponenciar(InteiroLovelace &A,InteiroLovelace &X); /* Tivemos uma idéia para melhorar a exponenciação*/
		InteiroLovelace		fatorial();
		InteiroLovelace& 	inverterSinal();
		InteiroLovelace 	incrementar();
		InteiroLovelace 	decrementar();
		InteiroLovelace& 	atribuir(unsigned long long int &numero);
		InteiroLovelace& 	atribuir(const int &numero);

		bool eIgualA(const InteiroLovelace &B);
		bool eDiferenteDe(const InteiroLovelace &B);
		bool eMaiorQue(const InteiroLovelace &B);
		bool eMenorQue(const InteiroLovelace &B);
		bool eMaiorOuIgualA(const InteiroLovelace &B);
		bool eMenorOuIgualA(const InteiroLovelace &B);

		InteiroLovelace& operator=(InteiroLovelace &B);
		InteiroLovelace& operator=(const InteiroLovelace &B); 	// Tem que ser implementado para
											//	copiar os conteúdos de *algarismos
		InteiroLovelace& operator=(unsigned long long int &numero);
		InteiroLovelace& operator=(const int &numero);
		InteiroLovelace& operator+=(InteiroLovelace &B);
		InteiroLovelace& operator-=(InteiroLovelace &B);
		InteiroLovelace& operator*=(InteiroLovelace &B);
		InteiroLovelace& operator/=(InteiroLovelace &B);
		InteiroLovelace& operator%=(InteiroLovelace &B);
		InteiroLovelace& operator^=(InteiroLovelace &B);
		/*	Operações Aritméticas 	*/
		InteiroLovelace operator+(InteiroLovelace &B);
		InteiroLovelace operator-(InteiroLovelace &B);
		InteiroLovelace operator*(InteiroLovelace &B);
		InteiroLovelace operator/(InteiroLovelace &B);
		InteiroLovelace operator%(InteiroLovelace &B);
		InteiroLovelace operator^(InteiroLovelace &B);

		/*	Operações Inc/Dec 	*/
		InteiroLovelace& operator++();
		InteiroLovelace& operator--();
		InteiroLovelace operator++(int semuso);
		InteiroLovelace operator--(int semuso);

		/* 	Operações de Comparação 	*/
		friend bool operator==(InteiroLovelace &A,InteiroLovelace &B);
		friend bool operator!=(InteiroLovelace &A,InteiroLovelace &B);
		friend bool operator>(InteiroLovelace &A,InteiroLovelace &B);
		friend bool operator<(InteiroLovelace &A,InteiroLovelace &B);
		friend bool operator>=(InteiroLovelace &A,InteiroLovelace &B);
		friend bool operator<=(InteiroLovelace &A,InteiroLovelace &B);

		/*	Operações de Ext/Ins de Fluxo 	*/
		friend std::ostream &operator<<(std::ostream &out,InteiroLovelace &A);
		friend std::istream &operator>>(std::istream &in,InteiroLovelace &A);
};


#endif
