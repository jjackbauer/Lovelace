#include "Lovelace.h"
#include <iostream>
#include <cstdlib>
using namespace std;

char Lovelace::TabelaDeConversao[] = {'0','1','2','3','4','5','6','7','8','9'};
long long int Lovelace::algarismosExibicao = -1;

void Lovelace::expandirAlgarismos(){
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

void Lovelace::reduzirAlgarismos()
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
			expandirAlgarismos();

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
{	//	Validar também para aceitar somente dígitos entre 0 9?
	if(Posicao>=0 && Posicao <= getQuantidadeAlgarismos())
	{
			char A,B;
			if(Posicao/2 < getTamanho()){
				getBitwise(Posicao/2,A,B);
				Posicao%2?(B=Digito):(A=Digito);
			}
			else {
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
		cout<<"ERRO! Atribuicao erronea de digito."<<endl;
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
void Lovelace::imprimir(){
	imprimir(0);
}
void Lovelace::imprimir(char separador){
	int c;
	char A,B;
	getBitwise(getTamanho()-1,A,B);
	//cout<<aux<<endl;

	if (separador){	//	Exibição com pontos
		if(!(getQuantidadeAlgarismos()%2)) {
			cout<<TabelaDeConversao[(int)B];
			if (getQuantidadeAlgarismos()%3 == 1)
				cout << separador;
			cout <<TabelaDeConversao[(int)A];
			if (getQuantidadeAlgarismos()%3 == 2)
				cout << separador;
		}
		else {
			cout<<TabelaDeConversao[(int)A];
			if (getQuantidadeAlgarismos()%3 == 1)
				cout << separador;
		}

		for(c=getTamanho()-2;c>-1;c--){
			getBitwise(c,A,B);
			cout<<TabelaDeConversao[(int)B];
			if ((((c+1)*2)%3) == 1)
				cout << separador;
			cout<<TabelaDeConversao[(int)A];
			if (c && (((c+1)*2)%3) == 2)
				cout << separador;
		}
	}
	else {
		if(!(getQuantidadeAlgarismos()%2))
			cout<<TabelaDeConversao[(int)B]<<TabelaDeConversao[(int)A];
		else
			cout<<TabelaDeConversao[(int)A];
		for(c=getTamanho()-2;c>-1;c--) {
			getBitwise(c,A,B);
			cout<<TabelaDeConversao[(int)B]<<TabelaDeConversao[(int)A];
		}
	}
	cout<<endl;
}

void Lovelace::imprimirInfo(){
	cout << "tamanho              : " << getTamanho() << endl;
	cout << "quantidadeAlgarismos : " << getQuantidadeAlgarismos() << endl;
	cout << "zero                 : " << eZero() << endl;
	cout << "Vetor de Algarismos  : ";
	imprimir('.');
	cout << endl;
}

Lovelace& Lovelace::incrementar(){
	Lovelace aux;
	aux.setDigito(0,1);//aux=1; Equivalente após sobrecarga //Remover depois de fazer a base pro java!

	return ((*this) = somar(*this,aux));
}

Lovelace& Lovelace::decrementar(){
	Lovelace aux;
	aux.setDigito(0,1);
	return ((*this) = subtrair(*this,aux));
}

Lovelace& Lovelace::somar(Lovelace &A, Lovelace &B){
	Lovelace resultado;
	int c,overflow = 0,sum=((A.getDigito(0)+B.getDigito(0))%10),MaxDigi;

	{//I love gambiarra <3 <3
		int NdA=A.getQuantidadeAlgarismos(),NdB=B.getQuantidadeAlgarismos();
		MaxDigi=NdA>NdB?NdA:NdB;
	}

	resultado.setDigito(0,sum);
	//overflow=((A->GetDigito(0)+B->GetDigito(0))/10);

	for(c=1;c<=MaxDigi;c++){
		sum=((A.getDigito(c)+B.getDigito(c))%10);
		overflow=((A.getDigito(c-1)+B.getDigito(c-1)+overflow)/10);
		//if(sum+overflow)	//	Isso vai ter de voltar apos corrige lovelace....
		resultado.setDigito(c,(sum+overflow)%10);
	}
	overflow=((A.getDigito(c-1)+B.getDigito(c-1))/10);
	if (overflow)
		resultado.setDigito(c,overflow);

	for (c=resultado.getQuantidadeAlgarismos()-1;c > -1 && !resultado.getDigito(c);c--);

	if (int aux = (resultado.getQuantidadeAlgarismos()-1 - c)){
		while(aux--)
			resultado.reduzirAlgarismos();
	}

	return resultado;
}

Lovelace& Lovelace::subtrair(Lovelace &A, Lovelace &B){
	int carry = 0;
	int i;
	int QtdAlgarismosIguais = 0;
	Lovelace resposta;

	if (A.getQuantidadeAlgarismos() == B.getQuantidadeAlgarismos())
	{
		for (i = A.getQuantidadeAlgarismos(); i != 0; i--)
		{
			if (A.getDigito(i) == B.getDigito(i))
			{
				QtdAlgarismosIguais += 1;
			}
			else
				break;
		}
	}

	resposta.setQuantidadeAlgarismos(A.getQuantidadeAlgarismos() - QtdAlgarismosIguais);

	if (A.getQuantidadeAlgarismos() < B.getQuantidadeAlgarismos())
		cout << "Esta operacao nao esta definida no conjunto dos numeros naturais" << endl;
	else if(A.getQuantidadeAlgarismos() == B.getQuantidadeAlgarismos() && (A.getDigito(getQuantidadeAlgarismos() - 1) < B.getDigito(getQuantidadeAlgarismos() - 1)))
			cout << "Esta operacao nao esta definida no conjunto dos numeros naturais" << endl;
	else {
		for (i = 0; i != (A.getQuantidadeAlgarismos() - QtdAlgarismosIguais); i++) {
			if (A.getDigito(i) < B.getDigito(i)) {	
				if (!carry) {
					resposta.setDigito(i, ((A.getDigito(i) + 10) - B.getDigito(i)));
					carry = 1;
				}
				else {
					resposta.setDigito(i, ((A.getDigito(i) + 10) - (B.getDigito(i) + carry)));
					carry = 1;
				}
			}
			else {
				if (!carry){
					resposta.setDigito(i, (A.getDigito(i) - B.getDigito(i)));
					carry = 0;
				}
				else {
					resposta.setDigito(i, (A.getDigito(i) - (B.getDigito(i) + carry)));
					carry = 0;
				}
			}
		}
	}
	return resposta;
}

Lovelace& Lovelace::multiplicar(Lovelace &A, Lovelace &B){
	Lovelace c,aux,resultado;
	bool log = A.eMaiorQue(B);
	c=1;
	aux = log?B:A;
	resultado = log?A:B;

	while(aux.eMaiorQue(c))
	{
		resultado = (resultado+(log?A:B));
		c++;
	}
	cout << "Final da *." << endl;
	return resultado;
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

Lovelace& Lovelace::operator-(Lovelace &B) {
	return subtrair((*this), B);
}

Lovelace& Lovelace::operator*(Lovelace &B){
	return multiplicar((*this), B);
}

Lovelace& Lovelace::operator+=(Lovelace &B){
	return ((*this) = somar((*this), B));
}

Lovelace& Lovelace::operator-=(Lovelace &B){
	return ((*this) = subtrair((*this), B));
}

Lovelace& Lovelace::operator*=(Lovelace &B){
	return ((*this) = multiplicar((*this), B));
}

Lovelace& Lovelace::operator=(unsigned long long int A){
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

Lovelace& Lovelace::operator++(){
	return (this->incrementar());
}

Lovelace& Lovelace::operator++(int semuso){
	Lovelace retorno;

	retorno = (*this);
	this->incrementar();
	return retorno;
}

Lovelace& Lovelace::operator--(){
	return (this->decrementar());
}

Lovelace& Lovelace::operator--(int semuso){
	Lovelace retorno;

	retorno = (*this);
	this->decrementar();
	return retorno;
}
