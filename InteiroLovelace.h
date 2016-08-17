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
		void toLovelace(Lovelace &saida) const;

		InteiroLovelace 	somar(const InteiroLovelace &B) const;
		InteiroLovelace 	subtrair(const InteiroLovelace &B) const;
		//InteiroLovelace 	multiplicar_burro(const InteiroLovelace &B) const; //Não se faz burrice duas vezes kkkk
		InteiroLovelace 	multiplicar(const InteiroLovelace &B) const;
		void     			dividir(const InteiroLovelace &B,InteiroLovelace &resultado,InteiroLovelace &resto) const;
		//InteiroLovelace 	dividir_burro(const InteiroLovelace &B, bool quocienteOuResto = true) const; //eu espero!
		InteiroLovelace		exponenciar(const InteiroLovelace &X) const; /* Tivemos uma idéia para melhorar a exponenciação*/
		InteiroLovelace		fatorial() const;
		InteiroLovelace 	inverterSinal() const;

		InteiroLovelace 	incrementar();
		InteiroLovelace 	decrementar();
		InteiroLovelace& 	atribuir(const long long int &numero);
		InteiroLovelace& 	atribuir(const int &numero);


		bool eIgualA(const InteiroLovelace &B) const;
		bool eDiferenteDe(const InteiroLovelace &B) const;
		bool eMaiorQue(const InteiroLovelace &B) const;
		bool eMenorQue(const InteiroLovelace &B) const;
		bool eMaiorOuIgualA(const InteiroLovelace &B) const;
		bool eMenorOuIgualA(const InteiroLovelace &B) const;

		InteiroLovelace& operator=(InteiroLovelace &B);
		InteiroLovelace& operator=(const InteiroLovelace &B); 	// Tem que ser implementado para
											//	copiar os conteúdos de *algarismos
		InteiroLovelace& operator=(const long long int &numero);
		InteiroLovelace& operator=(const int &numero);

		InteiroLovelace& operator+=(const InteiroLovelace &B);
		InteiroLovelace& operator-=(const InteiroLovelace &B);
		InteiroLovelace& operator*=(const InteiroLovelace &B);
		InteiroLovelace& operator/=(const InteiroLovelace &B);
		InteiroLovelace& operator%=(const InteiroLovelace &B);
		InteiroLovelace& operator^=(const InteiroLovelace &B);

		/*	Operações Aritméticas 	*/
		InteiroLovelace operator+(const InteiroLovelace &B) const;
		InteiroLovelace operator-(const InteiroLovelace &B) const;
		InteiroLovelace operator*(const InteiroLovelace &B) const;
		InteiroLovelace operator/(const InteiroLovelace &B) const;
		InteiroLovelace operator%(const InteiroLovelace &B) const;
		InteiroLovelace operator^(const InteiroLovelace &B) const;

		/*	Operações Inc/Dec 	*/
		InteiroLovelace& operator++();
		InteiroLovelace& operator--();
		InteiroLovelace operator++(int semuso);
		InteiroLovelace operator--(int semuso);

		/* 	Operações de Comparação 	*/
		friend bool operator==(const InteiroLovelace &A, const InteiroLovelace &B);
		friend bool operator!=(const InteiroLovelace &A, const InteiroLovelace &B);
		friend bool operator>(const InteiroLovelace &A, const InteiroLovelace &B);
		friend bool operator<(const InteiroLovelace &A, const InteiroLovelace &B);
		friend bool operator>=(const InteiroLovelace &A, const InteiroLovelace &B);
		friend bool operator<=(const InteiroLovelace &A, const InteiroLovelace &B);

		/*	Operações de Ext/Ins de Fluxo 	*/
		friend std::ostream &operator<<(std::ostream &out,const InteiroLovelace &A);
		friend std::istream &operator>>(std::istream &in,InteiroLovelace &A);
};


#endif
