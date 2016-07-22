#include "Lovelace.h"
#include <iostream>
#include <cstdlib>
using namespace std;

char Lovelace::TabelaDeConversao[] = {'0','1','2','3','4','5','6','7','8','9'};
long long int Lovelace::algarismosExibicao = -1;

void Lovelace::ExpandeAlgarismos()
{
	char *Saida=(char*)malloc(sizeof(char)*(getTamanho()+1));
	if(!Saida)
	{
		cout<<"Erro ao expandir"<<endl;
		exit(1);
	}

	for(int c=0;c<getTamanho();c++)
	{
		Saida[c]=algarismos[c];
	}
	setTamanho(getTamanho()+1);

	if(algarismos)
		free(algarismos);

	algarismos=Saida;

	return;
}

void Lovelace::reduzAlgarismos()
{
	if(getQuantidadeAlgarismos()%2)
	{
		//cout<<"Entrou REDUX IF true"<<endl;
		char *Saida=(char*)malloc(sizeof(char)*(getTamanho()-1));
		if(!Saida)
		{
			cout<<"Erro ao expandir"<<endl;
			exit(1);
		}
		//cout<<"Tamanho -1 = "<<GetTamanho()-1<<endl;
		for(int c=0;c<getTamanho()-1;c++)
		{	/*char A,B;
			getBitwise(c,A,B);
			cout<<"A = "<<(int)A<<"B = "<<(int)B<<endl;//*/
			Saida[c]=algarismos[c];

		}
		setTamanho(getTamanho()-1);

		if(algarismos)
			free(algarismos);

		algarismos=Saida;

	}
	else
	{
		char A,B;

		getBitwise(getTamanho()-1,A,B);
		B=15;
		setBitwise(getTamanho()-1,A,B);
	}
	setQuantidadeAlgarismos(getQuantidadeAlgarismos()-1);
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
	algarismos=NULL;
	setQuantidadeAlgarismos(tamanho=0);
	setZero(true);
}


Lovelace::~Lovelace(){
	if(!eZero())
		free(algarismos);
}

void Lovelace::setBitwise(long long int Posicao,char A, char B)
{
	long long int tamanho = getTamanho();

	if(Posicao>=0 && Posicao <= tamanho)
	{
		A<<=4;
		A+=B;

		if(Posicao == tamanho)
			ExpandeAlgarismos();

		algarismos[Posicao]=A;
	}
	else
	{
		cout<<"Atribuicao erronea BitWise"<<endl;
	}
}

void Lovelace::getBitwise(long long int Posicao,char &A, char &B)
{	
	if(Posicao>=0 && Posicao < getTamanho())
	{
		char coded = algarismos[Posicao];

		A=((coded&(240))>>4);
		B=coded&(15);
	}
	else
	{
		cout<<"Acesso Invalido BitWise"<<endl;
	}
}

char Lovelace::getDigito(long long int Posicao)
{
	if(Posicao>=0 && Posicao < getQuantidadeAlgarismos())//Tinha bug aqui, bug maldito kkkkkkkkk
	{
		char A,B;
		getBitwise(Posicao/2,A,B);

		return Posicao%2?B:A;
	}
	else
	{
		//cout<<"Acesso Invalido Digito"<<endl;
		return 0;
	}

	return 0;

}
void Lovelace::setDigito(long long int Posicao, char Digito)
{	
	if(Posicao>=0 && Posicao <= getQuantidadeAlgarismos())
	{
			char A,B;
			if(Posicao/2 < getTamanho())
			{
				getBitwise(Posicao/2,A,B);
				Posicao%2?(B=Digito):(A=Digito);
			}
			else
			{
				B=15;
				A=Digito;
			}

			if(Posicao>=getQuantidadeAlgarismos())
				setQuantidadeAlgarismos(getQuantidadeAlgarismos()+1);
			if(Posicao==0)
				setZero(false);

			setBitwise(Posicao/2,A,B);
	}
	else
	{
		cout<<"Atribuicao erronea Digito"<<endl;
	}
}


void Lovelace::setTamanho(long long int novoTamanho)
{
	tamanho=novoTamanho;
}

long long int Lovelace::getTamanho()
{
	return tamanho;
}

long long int Lovelace::getQuantidadeAlgarismos()
{
	return quantidadeAlgarismos;
}

void Lovelace::setQuantidadeAlgarismos(long long int novaQuantidadeAlgarismos)
{
	quantidadeAlgarismos=novaQuantidadeAlgarismos;
}

bool Lovelace::eZero()
{
	return zero;
}

void Lovelace::setZero(bool novoValor)
{
	zero=novoValor;
}
void Lovelace::imprimir()
{
	int c,aux=getQuantidadeAlgarismos();
	char A,B;
	getBitwise(getTamanho()-1,A,B);
	//cout<<aux<<endl;

	if(!(aux%2))
		cout<<TabelaDeConversao[(int)B]<<TabelaDeConversao[(int)A];
	else
		cout<<TabelaDeConversao[(int)A];

	for(c=getTamanho()-2;c>-1;c--)
	{
		getBitwise(c,A,B);
		cout<<TabelaDeConversao[(int)B]<<TabelaDeConversao[(int)A];
	}
	cout<<endl;
}

void Lovelace::imprimirInfo(){
	cout << "tamanho              : " << getTamanho() << endl;
	cout << "quantidadeAlgarismos : " << getQuantidadeAlgarismos() << endl;
	cout << "zero                 : " << eZero() << endl;
	cout << "Vetor de Algarismos  : ";
	imprimir();
	cout << endl;
}

Lovelace& Lovelace::incrementar()
{
	Lovelace aux;
	aux.setDigito(0,1);//aux=1; Equivalente após sobrecarga //Remover depois de fazer a base pro java!

	return ((*this) = somar(*this,aux));
}

Lovelace& Lovelace::operator=(unsigned long long int A)
{
	int c,k;
	unsigned long long int aux=10;

	for(c=0;c<20 && A ;c++,aux*=10)
	{
		k = A%aux;
		A-=k;
		k=(k*10/aux);
		this->setDigito(c,(int)k);
	}
	return *this;
}

Lovelace& Lovelace::operator++()
{
	return (this->incrementar());
}

Lovelace& Lovelace::operator++(int semuso)
{
	Lovelace *aux = new Lovelace;

	*aux = *this;
	this->incrementar();
	return *aux;
}
Lovelace& Lovelace::somar(Lovelace &A, Lovelace &B)
{
	Lovelace *res = new Lovelace;
	int c,overflow = 0,sum=((A.getDigito(0)+B.getDigito(0))%10),MaxDigi;

	{//I love gambiarra <3 <3
		int NdA=A.getQuantidadeAlgarismos(),NdB=B.getQuantidadeAlgarismos();
		MaxDigi=NdA>NdB?NdA:NdB;

	}


	res->setDigito(0,sum);
	//Oflow=((A->GetDigito(0)+B->GetDigito(0))/10);

	for(c=1;c<=MaxDigi;c++)
	{
		//cout<<"C = "<<c<<endl;
		//cout<<"Numero Digitos = "<<(res->getQuantidadeAlgarismos())<<endl;
		sum=((A.getDigito(c)+B.getDigito(c))%10);
		overflow=((A.getDigito(c-1)+B.getDigito(c-1)+overflow)/10);
		//if(sum+Oflow)//Isso vai ter de voltar apos corrige lovelace....
		res->setDigito(c,(sum+overflow)%10);
		//cout<<"SUM = "<<sum<<" Oflow = "<<Oflow<<endl;
		//res->imprimir();
		//getchar();

	}
	overflow=((A.getDigito(c-1)+B.getDigito(c-1))/10);
	if (overflow)
		res->setDigito(c,overflow);

	for (c=res->getQuantidadeAlgarismos()-1;c > -1 && !res->getDigito(c);c--);
	if (int aux = (res->getQuantidadeAlgarismos()-1 - c))
	{	//cout<<"Entrou com aux = "<<aux<<endl;
		//res->imprimir();
		while(aux--)
		res->reduzAlgarismos();
		//res->imprimir();
		//getchar();
	}
	//cout << "teste" << endl;
	//getchar();
	//*/

	return *res;
	//res->imprimir();

	/*
	 res->imprimir();
	  cout<<"A= "<<A->getQuantidadeAlgarismos()<<"B= "<<B->getQuantidadeAlgarismos()<<endl;
	//*/
}
Lovelace& Lovelace::subtrair(Lovelace &A, Lovelace &B)
{

}
Lovelace& Lovelace::multiplicar(Lovelace &A, Lovelace &B)
{
	Lovelace c,aux,*aux2 = new Lovelace;
	bool log = A.eMaiorQue(B);
	c=1;
	aux = log?B:A;
	*aux2= log?A:B;

	while(aux.eMaiorQue(c))
	{
		(*aux2)=((*aux2)+(log?A:B));
		//aux2->imprimir();
		c++;
	}
	cout << "Final da *." << endl;
	return *aux2;
}

Lovelace& Lovelace::dividir(Lovelace &A, Lovelace &B)
{

}
Lovelace& Lovelace::Exponenciacao(Lovelace &A, Lovelace &X)
{

}

bool Lovelace::eIgualA(Lovelace &B){
	if (this->getQuantidadeAlgarismos() != B.getQuantidadeAlgarismos())
		return false;
	else {
		if (this->eZero() && B.eZero())
			return true;
		for (long long int c = 0;c < this->getTamanho();c++)
			if (this->algarismos[c] != B.algarismos[c])
				return false;
	}
	return true;
}

bool Lovelace::eDiferenteDe(Lovelace &B){
	return !(this->eIgualA(B));
}

bool Lovelace::eMaiorQue(Lovelace &B) {
	if (this->getQuantidadeAlgarismos() > B.getQuantidadeAlgarismos()){
		return true;
	}
	else if (this->getQuantidadeAlgarismos() == B.getQuantidadeAlgarismos()){
		if (this->eZero() && B.eZero())
			return false;
		long long int c;
		for (c = this->getQuantidadeAlgarismos();c && this->getDigito(c) == B.getDigito(c);c--);

		if (this->getDigito(c) > B.getDigito(c))
			return true;
		else
			return false;
	}
	else
		return false;
	return true;
}

bool Lovelace::eMenorQue(Lovelace &B){
	if (this->getQuantidadeAlgarismos() < B.getQuantidadeAlgarismos()){
		return true;
	}
	else if (this->getQuantidadeAlgarismos() == B.getQuantidadeAlgarismos()){
		if (this->eZero() && B.eZero())
			return false;
		long long int c;
		for (c = this->getQuantidadeAlgarismos();c && this->getDigito(c) == B.getDigito(c);c--);

		if (this->getDigito(c) < B.getDigito(c))
			return true;
		else
			return false;
	}
	else
		return false;
	return true;
}

bool Lovelace::eMaiorOuIgualA(Lovelace &B){
	return (this->eIgualA(B) || this->eMaiorQue(B));
}

bool Lovelace::eMenorOuIgualA(Lovelace &B){
	return (this->eIgualA(B) || this->eMenorQue(B));
}

bool operator==(Lovelace &A, Lovelace &B){
	return (A.eIgualA(B));
}

bool operator!=(Lovelace &A, Lovelace &B){
	return A.eDiferenteDe(B);
}

bool operator>(Lovelace &A, Lovelace &B){
	return A.eMaiorQue(B);
}

bool operator>=(Lovelace &A, Lovelace &B){
	return A.eMaiorOuIgualA(B);
}

bool operator<(Lovelace &A, Lovelace &B){
	return A.eMenorQue(B);
}

bool operator<=(Lovelace &A, Lovelace &B){
	return A.eMenorOuIgualA(B);
}

Lovelace& Lovelace::operator+(Lovelace &B){
	return somar((*this), B);
}

Lovelace& Lovelace::operator*(Lovelace &B){
	return multiplicar((*this), B);
}
