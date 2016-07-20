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
	if(Posicao>=0 && Posicao < GetQuantidadeAlgarismos())//Tinha bug aqui, bug maldito kkkkkkkkk
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
	if(Posicao>=0 && Posicao <= GetQuantidadeAlgarismos())
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
			if(Posicao==0)
				SetZero(false);
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
	return Sinal?1:-1;
}

void Lovelace::SetSinal(int Sinal)
{
	Lovelace::Sinal = Sinal>0?true:false;
}
bool Lovelace::VerificaEzero()
{
	return Ezero;
}

void Lovelace::SetZero(bool Zero)
{
	Ezero=Zero;
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
	//AlgarismosExibicao=Numero;//Why god?
}

long long int Lovelace::GetAlgarismosExibicao()
{
	//return AlgarismosExibicao;//Why god?
}
Lovelace& Lovelace::Lovelace::Soma(Lovelace *A, Lovelace *B)
{
	Lovelace *res = new Lovelace;
	int c,Oflow,sum=((A->GetDigito(0)+B->GetDigito(0))%10),MaxDigi;

	{//I love gambiarra <3 <3
		int NdA=A->GetQuantidadeAlgarismos(),NdB=B->GetQuantidadeAlgarismos();
		MaxDigi=NdA>NdB?NdA:NdB;

	}


	res->SetDigito(0,sum);
	Oflow=((A->GetDigito(0)+B->GetDigito(0))/10);

	for(c=1;c<MaxDigi;c++)
	{
		//cout<<"C = "<<c<<endl;
		//cout<<"Numero Digitos = "<<(res->GetQuantidadeAlgarismos())<<endl;
		sum=((A->GetDigito(c)+B->GetDigito(c))%10);
		res->SetDigito(c,(sum+Oflow)%10);
		Oflow=((A->GetDigito(c-1)+B->GetDigito(c-1))/10);
		//cout<<"SUM = "<<sum<<" Oflow = "<<Oflow<<endl;
		//res->Imprime();
		//getchar();

	}
	Oflow=((A->GetDigito(c-1)+B->GetDigito(c-1))/10);
	if(Oflow)
	res->SetDigito(c,Oflow);
	return *res;
	//res->Imprime();

	/*
	 res->Imprime();
	  cout<<"A= "<<A->GetQuantidadeAlgarismos()<<"B= "<<B->GetQuantidadeAlgarismos()<<endl;
	//*/
}
Lovelace& Lovelace::Lovelace::Subtracao(Lovelace *A, Lovelace *B)
{

}
Lovelace& Lovelace::Lovelace::Multiplicacao(Lovelace *A, Lovelace *B)
{

}
Lovelace& Lovelace::Divisao(Lovelace *A, Lovelace *B)
{

}
Lovelace& Lovelace::InversaoDeSinal(Lovelace *A)
{

}
Lovelace& Lovelace::Inversao(Lovelace *A)
{

}
Lovelace& Lovelace::Exponenciacao(Lovelace *A, Lovelace *X)
{

}
