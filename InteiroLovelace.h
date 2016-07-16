#ifndef INTEIROLOVELCE_H
#define INTEIROLOVELACE_H
#include <iostream>
#include<cstdlib>
#include "Lovelace.h"
using namespace std;

class InteiroLovelace: public Lovelace
{

		InteiroLovelace();
		~InteiroLovelace();

		InteiroLovelace& Atribuicao(int A);
		InteiroLovelace& Atribuicao(InteiroLovelace &A, InteiroLovelace B);
		InteiroLovelace& Soma(InteiroLovelace A, InteiroLovelace B);
		InteiroLovelace& Subtracao(InteiroLovelace A, InteiroLovelace B);
		InteiroLovelace& Multiplicacao(InteiroLovelace A, InteiroLovelace B);
		InteiroLovelace& Divisao(InteiroLovelace A, InteiroLovelace B);
		InteiroLovelace& InversaoDeSinal(InteiroLovelace A);
		InteiroLovelace& Inversao(InteiroLovelace A);
		InteiroLovelace& Exponenciacao(InteiroLovelace A, InteiroLovelace X);
		InteiroLovelace& Fatorial(InteiroLovelace N);

};


#endif /* INTEIROInteiroLovelace_H_ */
