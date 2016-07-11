#include "Lovelace.h"



Lovelace::Lovelace()
{
	Algarismos=NULL;
	Tamanho=0;
	Sinal=true;
	Ezero=true;
}


Lovelace::~Lovelace()
{
	if(!VerificaEzero())
	{
		free(Algarismos);
	}
}

void Lovelace::SetBitWise(long long int Posicao,char A, char B)
{
	if(posicao>=0 && posicao < GetTamanho())
	{
		A<<=4;
		A+=B;
		Algarismos[Posicao/2]=A;
	}
	else
	{
		cout<<"Atribuicao erronea"<<endl;
	}
}

void Lovelace::GetBitWise(long long int Posicao,char &A, char &B)
{	
	if(posicao>=0 && posicao < GetTamanho())
	{
			
		char coded = Algarismos[Posicao/2];
		
		A=((coded&(240))>>4);
		B=coded&(15);
	}
	else
	{
		cout<<"Atribuicao erronea"<<endl;
	}
}

char Lovelace::GetDigito(long long int Posicao)
{
	if(posicao>=0 && posicao < GetTamanho())
	{
		char A,B;
		GetBitWise(Posicao/2,A,B);
		
		return Posicao%2?B:A;
	}
	else
	{
		cout<<"Atribuicao erronea"<<endl;
	}
	
}
void Lovelace::SetDigito(long long int Posicao, char Digito)
{	
	if(posicao>=0 && posicao < GetTamanho())
	{
		char A,B,aux;
		GetBitWise(Posicao/2,A,B);
		Posicao%2?(B=Digito):(A=Digito);
		SetBitWise(Posicao/2,A,B);
		
		
	}
	else
	{
		cout<<"Atribuicao erronea"<<endl;
	}
}

&Lovelace Lovelace::Atribuicao(int A)
{
	return Lovelace();
}

&Lovelace Lovelace::Atribuicao(Lovelace &A, Lovelace B)
{
	return Lovelace();
}

&Lovelace Lovelace::Soma(Lovelace A, Lovelace B)
{
	return Lovelace();
}

&Lovelace Lovelace::Subtracao(Lovelace A, Lovelace B)
{
	return Lovelace();
}

&Lovelace Lovelace::Multiplicacao(Lovelace A, Lovelace B)
{
	return Lovelace();
}

&Lovelace Lovelace::Divisao(Lovelace A, Lovelace B)
{
	return Lovelace();
}

&Lovelace Lovelace::InversaoDeSinal(Lovelace A)
{
	return Lovelace();
}

&Lovelace Lovelace::Inversao(Lovelace A)
{
	return Lovelace();
}

void Lovelace::SetTamanho(long long int Tamanho)
{
}

long long int Lovelace::GetTamanho()
{
	return 0;
}

int Lovelace::GetSinal()
{
	return 0;
}

void Lovelace::SetSinal(int Sinal)
{
}

&Lovelace Lovelace::Exponenciacao(Lovelace A, Lovelace X)
{
	return Lovelace();
}

&Lovelace Lovelace::Fatorial(Lovelace N)
{
	return Lovelace();
}

bool Lovelace::VerificaEzero()
{
	return false;
}

void Lovelace::SetZero(bool Zero)
{
}
void Lovelace::Imprime()
{
}

void Lovelace::SetAlgarismosExibicao(long long int Numero)
{
}

long long int Lovelace::GetAlgarismosExibicao()
{
	return 0;
}
