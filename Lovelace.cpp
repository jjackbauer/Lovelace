#include "Lovelace.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <utility>

using namespace std;

char Lovelace::TabelaDeConversao[] = {'0','1','2','3','4','5','6','7','8','9'};
long long int Lovelace::algarismosExibicao = -1;

void Lovelace::expandirAlgarismos(){
	char *saida= new char[getTamanho()+1];
	if (!saida) {
		cout << "ERRO! Não foi possível alocar memória para saida" << endl;
		exit(1);
	}

	for (int c=0;c<getTamanho();c++){
		saida[c]=algarismos[c];
	}
	setTamanho(getTamanho()+1);

	if(algarismos)
		free(algarismos);

	algarismos=saida;

	return;
}

void Lovelace::reduzirAlgarismos(){
	if (getQuantidadeAlgarismos()%2){
		char *saida= new char[getTamanho()-1];
		if (!saida){
			cout << "ERRO! Não foi possível alocar memória para saida" << endl;
			exit(1);
		}
		for (int c=0;c<getTamanho()-1;c++){
			saida[c]=algarismos[c];
		}
		setTamanho(getTamanho()-1);

		if (algarismos)
			free(algarismos);

		algarismos=saida;
	}
	else {
		char a,b;
		getBitwise(getTamanho()-1,a,b);
		b=15;
		setBitwise(getTamanho()-1,a,b);
	}
	setQuantidadeAlgarismos(getQuantidadeAlgarismos()-1);
	return;
}

void Lovelace::copiarAlgarismos(const Lovelace &deA, Lovelace &paraB){
	if ((&deA != &paraB) && (!deA.zero)){
		delete (paraB.algarismos);

		paraB.algarismos = new char[deA.getTamanho()];
		if (!paraB.algarismos){
			cout << "ERRO! Não foi possível alocar memória para algarismos." << endl <<
					"Função: operator=(Lovelace &B)" << endl;
			exit(1);
		}
		long long int c;
		for (c = deA.getTamanho()-1;c;c--)
			paraB.algarismos[c] = deA.algarismos[c];
		paraB.algarismos[c] = deA.algarismos[c];
	}
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

Lovelace::Lovelace(){
	algarismos=NULL;
	setTamanho(0);
	setQuantidadeAlgarismos(0);
	setZero(true);
}
//*
Lovelace::Lovelace(const Lovelace &copiarLovelace){
	setTamanho(copiarLovelace.getTamanho());
	setQuantidadeAlgarismos(copiarLovelace.getQuantidadeAlgarismos());
	setZero(copiarLovelace.eZero());
	copiarAlgarismos(copiarLovelace, *this);
}
//*/

Lovelace::~Lovelace(){
	if(!eZero())
		free(algarismos);
}

void Lovelace::setBitwise(long long int Posicao,char A, char B){
	long long int tam = getTamanho();

	if (Posicao>=0 && Posicao <= tam){
		A<<=4;
		A+=B;

		if(Posicao == tam)
			expandirAlgarismos();

		algarismos[Posicao]=A;
	}
	else {
		cout<<"Atribuicao erronea Bitwise"<<endl;
	}
}

void Lovelace::getBitwise(long long int Posicao,char &A, char &B) const{
	if (Posicao>=0 && Posicao < getTamanho()){
		char coded = algarismos[Posicao];

		A=((coded&(240))>>4);
		B=coded&(15);
	}
	else {
		cout<<"Acesso invalido Bitwise"<<endl;
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
void Lovelace::setDigito(long long int Posicao, char Digito){
	//	Validar também para aceitar somente dígitos entre 0 9?
	if (Posicao>=0 && Posicao <= getQuantidadeAlgarismos()){
			char A,B;
			if(Posicao/2 < getTamanho()){
				getBitwise(Posicao/2,A,B);
				Posicao%2?(B=Digito):(A=Digito);
			}
			else {
				B=15;
				A=Digito;
			}

			if (Posicao>=getQuantidadeAlgarismos())
				setQuantidadeAlgarismos(getQuantidadeAlgarismos()+1);
			if (Posicao==0)
				setZero(false);

			setBitwise(Posicao/2,A,B);
	}
	else {
		cout<<"ERRO! Atribuicao erronea de digito."<<endl;
	}
}

void Lovelace::setTamanho(long long int novoTamanho){
	tamanho=novoTamanho;
}

long long int Lovelace::getTamanho() const{
	return tamanho;
}

long long int Lovelace::getQuantidadeAlgarismos() const{
	return quantidadeAlgarismos;
}

void Lovelace::setQuantidadeAlgarismos(long long int novaQuantidadeAlgarismos){
	quantidadeAlgarismos=novaQuantidadeAlgarismos;
}

 bool Lovelace::eZero() const{
	return zero;
}

bool Lovelace::naoEZero(){
	return !zero;
}

void Lovelace::setZero(bool novoValor){
	zero = novoValor;
}

void Lovelace::imprimir() const{
	imprimir(0);
}

void Lovelace::imprimir(char separador) const{
	int c;
	char a,b;
	getBitwise(getTamanho()-1,a,b);
	if (zero) {
		cout << TabelaDeConversao[0];
	}
	else if (separador){	//	Exibição com separador especificado
		if(!(getQuantidadeAlgarismos()%2)) {
			cout<<TabelaDeConversao[(int)b];
			if (getQuantidadeAlgarismos()%3 == 1)
				cout << separador;
			cout <<TabelaDeConversao[(int)a];
			if (getQuantidadeAlgarismos()%3 == 2)
				cout << separador;
		}
		else {
			cout<<TabelaDeConversao[(int)a];
			if (getQuantidadeAlgarismos()%3 == 1)
				cout << separador;
		}

		for(c=getTamanho()-2;c>-1;c--){
			getBitwise(c,a,b);
			cout<<TabelaDeConversao[(int)b];
			if ((((c+1)*2)%3) == 1)
				cout << separador;
			cout<<TabelaDeConversao[(int)a];
			if (c && (((c+1)*2)%3) == 2)
				cout << separador;
		}
	}
	else {
		if(!(getQuantidadeAlgarismos()%2))
			cout<<TabelaDeConversao[(int)b]<<TabelaDeConversao[(int)a];
		else
			cout<<TabelaDeConversao[(int)a];
		for(c=getTamanho()-2;c>-1;c--) {
			getBitwise(c,a,b);
			cout<<TabelaDeConversao[(int)b]<<TabelaDeConversao[(int)a];
		}
	}
	cout<<endl;
}

void Lovelace::imprimirInfo() const{
	cout << "(*)                  : " << this << endl;
	cout << "tamanho              : " << getTamanho() << endl;
	cout << "quantidadeAlgarismos : " << getQuantidadeAlgarismos() << endl;
	cout << "zero                 : " << eZero() << endl;
	cout << "algarismos (*)       : " << &algarismos << endl;
	printf("%d\n", algarismos);
	cout << "Vetor de Algarismos  : ";
	imprimir('.');
	cout << endl;
	for (int c = 0;c < getTamanho();c++){
		cout << "algarismos[" << c << "](2): " << (int)(algarismos[c]&15) << endl;
		cout << "algarismos[" << c << "](1): " << (int)((algarismos[c]&240)>>4) << endl;
	}
	cout << endl;
}

Lovelace Lovelace::incrementar(){
	Lovelace aux;
	aux.setDigito(0,1);//aux=1; Equivalente após sobrecarga //Remover depois de fazer a base pro java!
	return ((*this) = somar(*this,aux));
}

Lovelace Lovelace::decrementar(){
	Lovelace aux;
	aux.setDigito(0,1);
	return ((*this) = subtrair(*this,aux));
}

Lovelace& Lovelace::atribuir(unsigned long long int &numero){
	int c,k;
	unsigned long long int aux=10;
	for(c=0;c<20 && numero ;c++,aux*=10){
		k = numero%aux;
		numero-=k;
		k=(k*10/aux);
		this->setDigito(c,(char)k);
	}
	return (*this);
}
Lovelace& Lovelace::atribuir(const int &numero){
	unsigned long long int aux=numero;
	return atribuir(aux);
}

Lovelace Lovelace::somar(Lovelace &A, Lovelace &B){
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

Lovelace Lovelace::subtrair(Lovelace &A, Lovelace &B){
	int carry = 0;
	int i;
	int QtdAlgarismosIguais = 0;
	Lovelace resposta;

	if (A.getQuantidadeAlgarismos() == B.getQuantidadeAlgarismos()){
		for (i = A.getQuantidadeAlgarismos()-1; i != 0; i--){
			if (A.getDigito(i) == B.getDigito(i)){
				QtdAlgarismosIguais += 1;
			}
			else
				break;
		}
	}



	resposta.setQuantidadeAlgarismos(A.getQuantidadeAlgarismos() - QtdAlgarismosIguais);
	cout << endl <<  "----SUBT" << endl << resposta.getQuantidadeAlgarismos() << endl;
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
	cout << "SUBT" << endl;
	resposta.imprimirInfo();
	cout << endl;
	return resposta;
}

Lovelace Lovelace::multiplicar_burro(Lovelace &A, Lovelace &B){
	Lovelace c,aux,resultado;
	bool log = A.eMaiorQue(B);
	aux = log?B:A;
	resultado = log?A:B;
	c++;

	while(aux.eMaiorQue(c))
	{
		resultado = (resultado+(log?A:B));
		c++;
	}
	return resultado;
}

Lovelace Lovelace::multiplicar(Lovelace &A, Lovelace &B){
	Lovelace aux,aux1,resultado,temp;
	long long int c,c1,c2;
	int multiplicador,multiplicando,produto,overflow;
	bool log = A.eMaiorQue(B);
	aux = log?B:A;
	aux1 = log?A:B;

	for(c=0; c < aux.getQuantidadeAlgarismos();c++){
		multiplicador = aux.getDigito(c);
		if(multiplicador){
			unsigned long long int k =0;
			temp = k;

			for(c1=0;c1<c;c1++)
				temp.setDigito(c1,0);

			overflow=0;
			for(c2=0;c2<aux1.getQuantidadeAlgarismos();c2++){
				multiplicando = aux1.getDigito(c2);
				produto = (multiplicando * multiplicador);
				temp.setDigito((c2+c1),(produto+overflow)%10);
				overflow=(produto+overflow)/10;
			}
			if(overflow)
				temp.setDigito((c2+c1),overflow);//só por isso vey kkkkkkkkkkkkk
			resultado+=temp;
		}
	}

	return resultado;
}

Lovelace Lovelace::dividir(Lovelace &A, Lovelace &B){

}

Lovelace Lovelace::exponenciar(Lovelace &A, Lovelace &X){
	Lovelace c,resultado;
	resultado.setDigito(0,1);

	if(!(X.eZero()))
		for(c=0;c<=X;c++,resultado*=A);

	return resultado;
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

Lovelace& Lovelace::operator=(Lovelace &B){
	if (&B != this){
		if (!zero && B.zero){
			delete this->algarismos;
			this->algarismos = NULL;
		}
		else
			copiarAlgarismos(B,*this);
		this->setQuantidadeAlgarismos(B.getQuantidadeAlgarismos());
		this->setTamanho(B.getTamanho());
		this->setZero(B.eZero());
	}
	return (*this);
}

Lovelace& Lovelace::operator=(const Lovelace &B){
	if (&B != this){
		if (!zero && B.zero){
			delete this->algarismos;
			this->algarismos = NULL;
		}
		else
			copiarAlgarismos(B,*this);
		this->setQuantidadeAlgarismos(B.getQuantidadeAlgarismos());
		this->setTamanho(B.getTamanho());
		this->setZero(B.eZero());
	}
	return (*this);
}

Lovelace& Lovelace::operator=(unsigned long long int &numero){
	return atribuir(numero);
}
Lovelace& Lovelace::operator=(const int &numero){
	return atribuir(numero);
}

Lovelace Lovelace::operator+(Lovelace &B){
	return somar((*this), B);
}

Lovelace Lovelace::operator-(Lovelace &B) {
	return subtrair((*this), B);
}

Lovelace Lovelace::operator*(Lovelace &B){
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



Lovelace& Lovelace::operator++(){
	this->incrementar();
	return (*this);
}

Lovelace Lovelace::operator++(int semuso){
	Lovelace retorno;
	retorno = (*this);
	this->incrementar();
	return retorno;
}

Lovelace& Lovelace::operator--(){
	this->decrementar();
	return (*this);
}

Lovelace Lovelace::operator--(int semuso){
	Lovelace retorno;

	retorno = (*this);
	this->decrementar();
	return retorno;
}

std::ostream &operator<<(std::ostream &out,Lovelace &A){
	long long int c;
	char a, b;
	if (A.zero) {
			out << Lovelace::TabelaDeConversao[0];
	}
	else {
		A.getBitwise(A.getTamanho()-1,a,b);
		if(!(A.getQuantidadeAlgarismos()%2))
			out << Lovelace::TabelaDeConversao[(int)b] << A.TabelaDeConversao[(int)a];
		else
			out << Lovelace::TabelaDeConversao[(int)a];
		for(c=A.getTamanho()-2;c>-1;c--) {
			A.getBitwise(c,a,b);
			out << Lovelace::TabelaDeConversao[(int)b] << Lovelace::TabelaDeConversao[(int)a];
		}
	}

	return out;
}

/*
std::istream &operator>>(std::istream &in,Lovelace &A){
	unsigned long long int numero;
	in >> numero;
	A = numero;
	return in;
}
//*/

/* Inserção de fluxo char a char, problema com números impares de dígitos.
std::istream &operator>>(std::istream &in,Lovelace &A){
	char *algarismos = NULL, *aux;
	long long int tamanho,c;
	char n,alg;
	in >> n;
	for(c = 1;(n >= '0') && (n <= '9');in >> n){
		if (c == 1 && n == '0')
			continue;
		else if (!(c%2)){
			c++;
			alg |= ((n-'0')<<4);
			tamanho = c/2;
			aux = new char[tamanho];
			if (!aux){
				cout << "ERRO! Não foi possível alocar memória para aux." << endl;
				exit(1);
			}
			tamanho--;
			aux[0] = alg;
			for (tamanho--;tamanho+1;tamanho--)
				aux[tamanho+1] = algarismos[tamanho];
			free(algarismos);
			algarismos = aux;
		}
		else {
			alg = (n-'0');
			c++;
		}
	}
	if (!(c%2)){
		//alg <<=4;
		alg |= 240;
		tamanho = c/2;
		aux = new char[tamanho];
		if (!aux){
			cout << "ERRO! Não foi possível alocar memória para aux." << endl;
			exit(1);
		}
		tamanho--;
		aux[0] = alg;
		for (tamanho--;tamanho+1;tamanho--)
			aux[tamanho+1] = algarismos[tamanho];
		free(algarismos);
		algarismos = aux;
	}

	A.algarismos = algarismos;
	A.setTamanho(c/2);
	A.setQuantidadeAlgarismos(c-1);
	A.setZero(false);

	cout << endl <<
			"Tamanho: " << A.getTamanho() << endl;
	cout << "QntAlg: " << A.getQuantidadeAlgarismos() << endl;
	cout << aux[1] << endl;

	for (int c = 0;c < A.getTamanho();c++){
		cout << "algarismos[" << c << "](2): " << (int)(algarismos[c]&15) << endl;
		cout << "algarismos[" << c << "](1): " << (int)((algarismos[c]&240)>>4) << endl;
	}

	return in;
}
//*/
//*	Inserção de fluxo por string
std::istream &operator>>(std::istream &in,Lovelace &A){
	string entrada;
	char *algarismos;
	unsigned long long int tamanho;
	getchar();
	getline(in, entrada);
	string::iterator it=entrada.begin();
	for (tamanho = 0; it!=entrada.end() && entrada[tamanho] >= '0' && entrada[tamanho] <= '9';tamanho++, ++it){
		if (!tamanho && entrada[tamanho] == '0')
			tamanho--;
	}

	if (tamanho == 0){ /* criar função própria para inicializar um Lovelace? */
		delete A.algarismos;
		A.algarismos = NULL;
		A.setTamanho(0);
		A.setQuantidadeAlgarismos(0);
		A.setZero(true);
	}
	else {
		if (tamanho%2)
			A.setTamanho((tamanho/2) +1);
		else
			A.setTamanho(tamanho/2);
		A.setQuantidadeAlgarismos(tamanho);
		A.setZero(false);
		algarismos = new char[A.getTamanho()];
		if (!algarismos){
			cout << "ERRO! Não foi possível alocar memória para aux." << endl;
			exit(1);
		}
		unsigned long long int c;
		for (c= 0;tamanho>1;c++) {
			algarismos[c] = (((entrada[tamanho-1]-'0')<<4)|(entrada[tamanho-2]-'0'));
			tamanho -= 2;
		}
		if (tamanho == 1)
			algarismos[c] = ((entrada[0]-'0')<<4);
		A.algarismos = algarismos;
	}

	return in;
}
//*/

