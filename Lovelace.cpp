#include "Lovelace.h"
#include <iostream>
#include<cstdlib>
using namespace std;



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
	long long int tamanho = GetTamanho();
	A<<=4;
	A+=B;

	if(Posicao>=0 && Posicao/2 < tamanho)
	{
		Algarismos[Posicao/2]=A;
	}
	else
	if(Posicao/2 == tamanho)
	{
		SetTamanho(tamanho+1);
		if(!tamanho)
		{
			Algarismos = (char *)malloc(sizeof(char));

			if(Algarismos)
			{
				Algarismos[Posicao/2]=A;
			}
			else
			{
				cout<<"Erro de alocacao"<<endl;

			}

			return;
		}
		else
		{
			Algarismos = (char *)realloc(Algarismos,tamanho*sizeof(char));
			if(Algarismos)
			{
				Algarismos[Posicao/2]=A;
			}
			else
			{
				cout<<"Erro de alocacao"<<endl;
			}

			return;
		}

	}
	else
	{
		cout<<"Atribuicao erronea"<<endl;
	}
}

void Lovelace::GetBitWise(long long int Posicao,char &A, char &B)
{	
	if(Posicao>=0 && Posicao < GetTamanho())
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
	if(Posicao>=0 && Posicao < GetTamanho())
	{
		char A,B;
		GetBitWise(Posicao/2,A,B);
		
		return Posicao%2?B:A;
	}
	else
	{
		cout<<"Atribuicao erronea"<<endl;
	}
	
	return 0;

}
void Lovelace::SetDigito(long long int Posicao, char Digito)
{	
	if(Posicao>=0 && Posicao < GetTamanho())
	{
		char A,B;
		GetBitWise(Posicao/2,A,B);
		Posicao%2?(B=Digito):(A=Digito);
		SetBitWise(Posicao/2,A,B);
		
		
	}
	else
	{
		cout<<"Atribuicao erronea"<<endl;
	}
}


void Lovelace::SetTamanho(long long int Tamanho)
{
	Lovelace::Tamanho=Tamanho;
}

long long int Lovelace::GetTamanho()
{
	return Lovelace::Tamanho;
}

int Lovelace::GetSinal()
{
	return 0;
}

void Lovelace::SetSinal(int Sinal)
{
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
	for(int c=0;c<GetTamanho;c++)
	{

	}
}

void Lovelace::SetAlgarismosExibicao(long long int Numero)
{
}

long long int Lovelace::GetAlgarismosExibicao()
{
	return 0;
}
Lovelace& Lovelace::Soma(Lovelace A, Lovelace B)
{
	Lovelace *res=(Lovelace*)malloc(sizeof(Lovelace));

	return *res;
}

Lovelace& Lovelace::Subtracao(Lovelace A, Lovelace B)
{
	Lovelace *res=(Lovelace*)malloc(sizeof(Lovelace));

	return *res;
}

Lovelace& Lovelace::Multiplicacao(Lovelace A, Lovelace B)
{
	Lovelace *res=(Lovelace*)malloc(sizeof(Lovelace));

	return *res;
}

Lovelace& Lovelace::Divisao(Lovelace A, Lovelace B)
{
	Lovelace *res=(Lovelace*)malloc(sizeof(Lovelace));

	return *res;
}

Lovelace& Lovelace::InversaoDeSinal(Lovelace A)
{
	Lovelace *res=(Lovelace*)malloc(sizeof(Lovelace));

	return *res;
}

Lovelace& Lovelace::Inversao(Lovelace A)
{
	Lovelace *res=(Lovelace*)malloc(sizeof(Lovelace));

	return *res;
}

Lovelace& Lovelace::Exponenciacao(Lovelace A, Lovelace X)
{
	Lovelace *res=(Lovelace*)malloc(sizeof(Lovelace));

	return *res;
}

Lovelace& Lovelace::Fatorial(Lovelace N)
{
	Lovelace *res=(Lovelace*)malloc(sizeof(Lovelace));

	return *res;
}


