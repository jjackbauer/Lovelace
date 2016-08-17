#include "InteiroLovelace.h"

InteiroLovelace::InteiroLovelace(){
	inicializar();
}

InteiroLovelace::InteiroLovelace(const InteiroLovelace &copiarInteiroLovelace){
	setTamanho(copiarInteiroLovelace.getTamanho());
	setQuantidadeAlgarismos(copiarInteiroLovelace.getQuantidadeAlgarismos());
	setZero(copiarInteiroLovelace.eZero());
	setSinal(copiarInteiroLovelace.getSinal());
	if (!copiarInteiroLovelace.eZero())
		copiarAlgarismos(copiarInteiroLovelace, *this);
}
InteiroLovelace::InteiroLovelace(const Lovelace &copiarLovelace)
{
	setTamanho(copiarLovelace.getTamanho());
	setQuantidadeAlgarismos(copiarLovelace.getQuantidadeAlgarismos());
	setZero(copiarLovelace.eZero());
	setSinal(true);
	if (!copiarLovelace.eZero())
		copiarAlgarismos(copiarLovelace, *this);
}

void InteiroLovelace::inicializar(){
	Lovelace::inicializar();
	setSinal(false);
}

void InteiroLovelace::zerar(){
	Lovelace::zerar();
	setSinal(false);
}

bool InteiroLovelace::getSinal() const{
	return sinal;
}

void InteiroLovelace::setSinal(bool novoSinal){
	sinal = novoSinal;
}
void toLovelace(const InteiroLovelace &entrada,Lovelace &saida)
{
	Lovelace aux(entrada.algarismos,entrada.getTamanho(),entrada.getQuantidadeAlgarismos(),entrada.eZero());
	saida.atribuir(aux);
}
InteiroLovelace 	InteiroLovelace::somar(InteiroLovelace &A, InteiroLovelace &B)
{
	Lovelace auxA,auxB;
	bool sinalMaior;
	A.toLovelace(A,auxA);
	B.toLovelace(B,auxB);

	if(A.getSinal() && B.getSinal())
	{
		InteiroLovelace resultado(auxA.somar(auxA,auxB));
		return resultado;
	}
	else
	{	InteiroLovelace resultado(auxA.subtrair(auxA,auxB));
		sinalMaior = auxA.eMaiorQue(B)?A.getSinal():B.getSinal();
		resultado.setSinal(sinalMaior);
		return resultado;
	}
}
InteiroLovelace 	InteiroLovelace::subtrair(InteiroLovelace &A, InteiroLovelace &B)
{
	Lovelace auxA,auxB;
	bool sinalMaior;
	A.toLovelace(A,auxA);
	B.toLovelace(B,auxB);

	if((A.getSinal() && !B.getSinal()) ||(!A.getSinal() && B.getSinal()))// é possível fazer xor com expressões lógicas?
	{
		InteiroLovelace resultado(auxA.somar(auxA,auxB));
		resultado.setSinal(A.getSinal());
		return resultado;
	}
	else
	if(A.getSinal() && B.getSinal())
	{
		InteiroLovelace resultado(auxA.subtrair(auxA,auxB));
		resultado.setSinal(auxB.eMenorOuIgualA(auxA));
		return resultado;
	}
	else
	if(!A.getSinal() && !B.getSinal())
	{
		InteiroLovelace resultado(auxA.subtrair(auxA,auxB));
		resultado.setSinal(auxA.eMenorOuIgualA(auxB));
		return resultado;
	}
}
InteiroLovelace 	InteiroLovelace::multiplicar(InteiroLovelace &A, InteiroLovelace &B)
{
	Lovelace auxA,auxB;
	bool sinaisIguais=(A.getSinal()==B.getSinal());
	A.toLovelace(A,auxA);
	B.toLovelace(B,auxB);
	InteiroLovelace resultado(auxA.multiplicar(auxA,auxB));
	resultado.setSinal(sinaisIguais);
	return resultado;
}
void     			InteiroLovelace::dividir(InteiroLovelace &A, InteiroLovelace &B,InteiroLovelace &resultado,InteiroLovelace &resto)
{

}
InteiroLovelace		InteiroLovelace::exponenciar(InteiroLovelace &A, Lovelace &X)
{
	InteiroLovelace resultado;

	return resultado;
}
InteiroLovelace& 	InteiroLovelace::inversaoDeSinal(InteiroLovelace A)
{
	InteiroLovelace resultado;

	return resultado;
}
InteiroLovelace 	InteiroLovelace::incrementar()
{
	InteiroLovelace resultado;

	return resultado;
}
InteiroLovelace 	InteiroLovelace::decrementar()
{
	InteiroLovelace resultado;

	return resultado;
}
InteiroLovelace& 	InteiroLovelace::atribuir(unsigned long long int &numero)
{
	InteiroLovelace resultado;

	return resultado;
}
InteiroLovelace& 	InteiroLovelace::atribuir(const int &numero)
{
	InteiroLovelace resultado;

	return resultado;
}



