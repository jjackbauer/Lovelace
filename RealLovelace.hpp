#ifndef REALLOVELACE_HPP_
#define REALLOVELACE_HPP_
#include <iostream>
#include<cstdlib>
using namespace std;
#include "InteiroLovelace.hpp"

class RealLovelace: public InteiroLovelace{
	private:
		long long int expoente;
		static long long int casasDecimaisExibicao;
		InteiroLovelace& toInteiroLovelace(long long int zeros=0);
		void digitosToBitwise(long long int tamanho,char * entrada,char* saida);
	public:
		//Construtores
		RealLovelace();
		RealLovelace(const double A);
		RealLovelace(string A);
		RealLovelace(const RealLovelace &A);
		//Sets e Gets
		void setExpoente(long long int X);
		long long int getExpoente() const;
		static void setCasasDecimaisExibicao(long long int Numero);
		static long long int getCasasDecimaisExibicao();
		//Operações Aritiméticas
		RealLovelace& atribuir(const double A);
		RealLovelace& atribuir(const string A);
		RealLovelace& atribuir(const RealLovelace &A);
		RealLovelace somar(const RealLovelace B) const;
		RealLovelace subtrair(RealLovelace B) const;
		RealLovelace multiplicar(RealLovelace B) const;
		RealLovelace dividir(RealLovelace B) const;
		RealLovelace inverter() const;
		RealLovelace exponenciar(RealLovelace X) const;
		//Entrada e Saída
		void imprimir() const;
		void ler();
};

#endif /* REALLOVELACE_HPP_ */
