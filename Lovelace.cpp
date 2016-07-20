#include "Lovelace.h"
#include <iostream>
#include <cstdlib>
using namespace std;

char Lovelace::TabelaDeConversao[] = {'0','1','2','3','4','5','6','7','8','9'};
long long int Lovelace::algarismosExibicao = 0;

void Lovelace::ExpandeAlgarismos(int numeroDeCasas)
{
	char *Saida=(char*)malloc(sizeof(char)*(GetTamanho()+numeroDeCasas));
	if(!Saida)
	{
		cout<<"Erro ao expandir"<<endl;
		exit(1);
	}

	for(int c=0;c<GetTamanho();c++)
	{
		Saida[c]=Algarismos[c];
	}
	SetTamanho(GetTamanho()+numeroDeCasas);

	if(Algarismos)
		free(Algarismos);

	Algarismos=Saida;

	return;
}

void Lovelace::reduzAlgarismos(int numeroDeCasas)
{
	char *Saida=(char*)malloc(sizeof(char)*(GetTamanho()-numeroDeCasas));
	if(!Saida)
	{
		cout<<"Erro ao expandir"<<endl;
		exit(1);
	}
	SetTamanho(GetTamanho()-numeroDeCasas);
	for(int c=0;c<GetTamanho();c++)
	{
		Saida[c]=Algarismos[c];
	}

	if(Algarismos)
		free(Algarismos);

	Algarismos=Saida;

	return;
}


void Lovelace::setAlgarismosExibicao(long long int novoAlgarismosExibicao)
{
	algarismosExibicao=novoAlgarismosExibicao;
}

long long int Lovelace::getAlgarismosExibicao()
{
	return algarismosExibicao;
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

void Lovelace::SetBitwise(long long int Posicao,char A, char B)
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
		cout<<"Atribuicao erronea Bitwise"<<endl;
	}
}

void Lovelace::GetBitwise(long long int Posicao,char &A, char &B)
{	
	if(Posicao>=0 && Posicao < GetTamanho())
	{

		char coded = Algarismos[Posicao];

		A=((coded&(240))>>4);
		B=coded&(15);
	}
	else
	{
		cout<<"Acesso invalido Bitwise"<<endl;
	}
}

char Lovelace::GetDigito(long long int Posicao)
{
	if(Posicao>=0 && Posicao < GetQuantidadeAlgarismos())//Tinha bug aqui, bug maldito kkkkkkkkk
	{
		char A,B;
		GetBitwise(Posicao/2,A,B);

		return Posicao%2?B:A;
	}
	else
	{
		//cout<<"Acesso Invalido Digito"<<endl;
		return 0;
	}

	return 0;

}
void Lovelace::SetDigito(long long int Posicao, char Digito)
{	
	if(Posicao>=0 && Posicao <= GetQuantidadeAlgarismos())
	{
			char A,B;
			if(Posicao < GetQuantidadeAlgarismos())
			{
				GetBitwise(Posicao/2,A,B);
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
			SetBitwise(Posicao/2,A,B);
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
	GetBitwise(GetTamanho()-1,A,B);
	//cout<<aux<<endl;

	if(!(aux%2))
		cout<<TabelaDeConversao[(int)B]<<TabelaDeConversao[(int)A];
	else
		cout<<TabelaDeConversao[(int)A];

	for(c=GetTamanho()-2;c>-1;c--)
	{
		GetBitwise(c,A,B);
		cout<<TabelaDeConversao[(int)B]<<TabelaDeConversao[(int)A];
	}
	cout<<endl;
}


Lovelace& Lovelace::Lovelace::Soma(Lovelace *A, Lovelace *B)
{
	Lovelace *res = new Lovelace;
	int c,Oflow=0,sum=((A->GetDigito(0)+B->GetDigito(0))%10),MaxDigi;

	{//I love gambiarra <3 <3
		int NdA=A->GetQuantidadeAlgarismos(),NdB=B->GetQuantidadeAlgarismos();
		MaxDigi=NdA>NdB?NdA:NdB;
	}

	res->SetDigito(0,sum);

	for(c=1;c<=MaxDigi;c++)
	{
		//cout <<endl;
		//cout<<"C = "<<c<<endl;
		//cout<<"Numero Digitos = "<<(res->GetQuantidadeAlgarismos())<<endl;
		sum=((A->GetDigito(c)+B->GetDigito(c))%10);
		Oflow=((A->GetDigito(c-1)+B->GetDigito(c-1)+Oflow)/10);
		//if(sum+Oflow)//Isso vai ter de voltar apos corrige lovelace....
		res->SetDigito(c,(sum+Oflow)%10);
		//cout<<"SUM = "<<sum<<" Oflow = "<<Oflow<<endl;
		//res->Imprime();
		//getchar();
	}
	system("clear || cls");
	Oflow=((A->GetDigito(c-1)+B->GetDigito(c-1))/10);
	if (Oflow)
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
