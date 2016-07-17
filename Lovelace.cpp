#include "Lovelace.h"
#include <iostream>
#include<cstdlib>
using namespace std;

char Lovelace::TabelaDeConversao[] = {'0','1','2','3','4','5','6','7','8','9'};
void Lovelace::ExpandeAlgarismos()
{
	char *Saida=(char*)malloc(sizeof(char)*(GetTamanho()+1));
	if(!Saida)
	{
		cout<<"Erro ao expandir"<<endl;
		exit(1);
	}

	for(int c=0;c<GetTamanho();c++)
	{
		Saida[c]=Algarismos[c];
	}
	SetTamanho(GetTamanho()+1);

	if(Algarismos)
		free(Algarismos);

	Algarismos=Saida;

	return;



}
Lovelace::Lovelace()
{
	Algarismos=NULL;
	QuantidadeAlgarismos=Tamanho=0;
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

	if(Posicao>=0 && Posicao <= tamanho)
	{
		A<<=4;
		A+=B;

		if(Posicao == tamanho)
			ExpandeAlgarismos();

		Algarismos[Posicao]=A;
	}
	else
	{
		cout<<"Atribuicao erronea BitWise"<<endl;
	}
}

void Lovelace::GetBitWise(long long int Posicao,char &A, char &B)
{	
	if(Posicao>=0 && Posicao < GetTamanho())
	{
			
		char coded = Algarismos[Posicao];
		
		A=((coded&(240))>>4);
		B=coded&(15);
	}
	else
	{
		cout<<"Acesso Invalido BitWise"<<endl;
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
		cout<<"Acesso Invalido Digito"<<endl;
	}
	
	return 0;

}
void Lovelace::SetDigito(long long int Posicao, char Digito)
{	
	if(Posicao>=0 && Posicao/2 <= GetTamanho())
	{
		char A,B;
		if(Posicao/2 < GetTamanho())
		{
			GetBitWise(Posicao/2,A,B);
			Posicao%2?(B=Digito):(A=Digito);
		}
		else
		{
			B=15;
			A=Digito;
		}

		if(Posicao>=GetQuantidadeAlgarismos())
			SetQuantidadeAlgarismos(GetQuantidadeAlgarismos()+1);
		SetBitWise(Posicao/2,A,B);

	}
	else
	{
		cout<<"Atribuicao erronea Digito"<<endl;
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
long long int Lovelace::GetQuantidadeAlgarismos()
{
	return QuantidadeAlgarismos;
}
void Lovelace::SetQuantidadeAlgarismos(long long int Tamanho)
{
	QuantidadeAlgarismos=Tamanho;
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
	int c,aux=QuantidadeAlgarismos;
	char A,B;
	GetBitWise(GetTamanho()-1,A,B);
	//cout<<aux<<endl;

	if(!(aux%2))
		cout<<TabelaDeConversao[(int)B]<<TabelaDeConversao[(int)A];
	else
		cout<<TabelaDeConversao[(int)A];

	for(c=GetTamanho()-2;c>-1;c--)
	{
		GetBitWise(c,A,B);
		cout<<TabelaDeConversao[(int)B]<<TabelaDeConversao[(int)A];
	}
	cout<<endl;
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


