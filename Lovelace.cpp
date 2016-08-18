#include "Lovelace.hpp"

using namespace std;

char Lovelace::TabelaDeConversao[] = {'0','1','2','3','4','5','6','7','8','9'};
long long int Lovelace::algarismosExibicao = -1;

void Lovelace::errorMessage(string message) const{
	cout << message << endl;
	pause;
	exit(1);
}

void Lovelace::expandirAlgarismos(){
	char *saida= new char[getTamanho()+1];
	if (!saida) {
		cout << "ERRO! NÃ£o foi possÃ­vel alocar memÃ³ria para saida" << endl;
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
			cout << "ERRO! NÃ£o foi possÃ­vel alocar memÃ³ria para saida" << endl;
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
		paraB.algarismos = new char[deA.getTamanho()];
		if (!paraB.algarismos){
			cout << "ERRO! NÃ£o foi possÃ­vel alocar memÃ³ria para algarismos." << endl <<
					"FunÃ§Ã£o: operator=(Lovelace &B)" << endl;
			exit(1);
		}
		long long int c;
		for (c = deA.getTamanho()-1;c;c--)
			paraB.algarismos[c] = deA.algarismos[c];
		paraB.algarismos[c] = deA.algarismos[c];
	}
	return;
}

void Lovelace::inicializar(){
	this->algarismos = NULL;
	this->setTamanho(0);
	this->setQuantidadeAlgarismos(0);
	this->setZero(true);
}

void Lovelace::zerar(){
	if (naoEZero()){
		delete this->algarismos;
		this->inicializar();
	}
}

void Lovelace::setAlgarismosExibicao(long long int novoAlgarismosExibicao){
	algarismosExibicao=novoAlgarismosExibicao;
}

long long int Lovelace::getAlgarismosExibicao(){
	return algarismosExibicao;
}
bool Lovelace::vefEhZeroBF()
{
	for(int c=0;c<getQuantidadeAlgarismos();c++)
		if(getDigito(c))
			return false;
	return true;
}
Lovelace::Lovelace(){
	inicializar();
}
//*
Lovelace::Lovelace(const Lovelace &copiarLovelace){
	setTamanho(copiarLovelace.getTamanho());
	setQuantidadeAlgarismos(copiarLovelace.getQuantidadeAlgarismos());
	setZero(copiarLovelace.eZero());
	if (!copiarLovelace.eZero())
		copiarAlgarismos(copiarLovelace, *this);
}
//*/
Lovelace::Lovelace(const char *algarismos,int tamanho,int quantidadeAlgarismos,bool zero)
{
	if(tamanho>0)
	{
		this->algarismos = new char[tamanho];

		if(!this->algarismos)
			errorMessage("Não foi possível alocar esta instância Lovelace");
		else
		{
			setTamanho(tamanho);
			setQuantidadeAlgarismos(quantidadeAlgarismos);
			setZero(zero);
			for(int c=0;c<tamanho;c++)
				this->algarismos[c]=algarismos[c];
		}

	}
	else
	{
		setZero(zero);
	}
}
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

char Lovelace::getDigito(long long int Posicao) const{
	if (Posicao>=0 && Posicao < getQuantidadeAlgarismos()){//Tinha bug aqui, bug maldito kkkkkkkkk
		char A,B;
		getBitwise(Posicao/2,A,B);

		return (Posicao%2)?B:A;
	}
	else {
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
				(Posicao%2)?(B=Digito):(A=Digito);
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

bool Lovelace::naoEZero() const{
	return !eZero();
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
	else if (separador){	//	ExibiÃ§Ã£o com separador especificado
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

void Lovelace::imprimirInfo(int opcao) const{
	cout << "(*)                  : " << this << endl;
	cout << "tamanho              : " << getTamanho() << endl;
	cout << "quantidadeAlgarismos : " << getQuantidadeAlgarismos() << endl;
	cout << "zero                 : " << eZero() << endl;
	cout << "algarismos (*)       : " << &algarismos << endl;
	printf("%p\n", algarismos);
	cout << "Vetor de Algarismos  : ";
	imprimir('.');
	cout << endl;
	if (opcao){
		for (int c = 0;c < getTamanho();c++){
			cout << "algarismos[" << c << "](2): " << (int)(algarismos[c]&15) << endl;
			cout << "algarismos[" << c << "](1): " << (int)((algarismos[c]&240)>>4) << endl;
		}
	}
	cout << endl;
}

Lovelace Lovelace::incrementar(){
	Lovelace aux;
	aux.setDigito(0,1);//aux=1; Equivalente apÃ³s sobrecarga //Remover depois de fazer a base pro java!
	return ((*this) = somar(aux));
}

Lovelace Lovelace::decrementar(){
	Lovelace aux;
	aux.setDigito(0,1);
	return ((*this) = subtrair(aux));
}

Lovelace& Lovelace::atribuir(unsigned long long int numero){
	int c,k;
	unsigned long long int aux=10;
	if (numero == 0) {
		this->inicializar();
	}
	else {
		for(c=0;c<20 && numero ;c++,aux*=10){
			k = numero%aux;
			numero-=k;
			k=(k*10/aux);
			this->setDigito(c,(char)k);
		}
	}
	return (*this);
}
Lovelace& Lovelace::atribuir(const int &numero){
	unsigned long long int aux=numero;
	return atribuir(aux);
}
Lovelace& Lovelace::atribuir(const Lovelace& B)
{
	if (&B != this){
		if (!zero)
			delete this->algarismos;
		if (B.zero)
			this->algarismos = NULL;
		else
			copiarAlgarismos(B,*this);
		this->setQuantidadeAlgarismos(B.getQuantidadeAlgarismos());
		this->setTamanho(B.getTamanho());
		this->setZero(B.eZero());
	}
	return (*this);
}
Lovelace Lovelace::somar(const Lovelace &B) const{
	Lovelace resultado;
	if (this->eZero()){
		resultado = B;
	}
	else if (B.eZero()){
		resultado = *this;
	}
	else {
		int c,overflow = 0,sum=((this->getDigito(0)+B.getDigito(0))%10),MaxDigi;
		{//I love gambiarra <3 <3
			int NdA=this->getQuantidadeAlgarismos(),NdB=B.getQuantidadeAlgarismos();
			MaxDigi=NdA>NdB?NdA:NdB;
		}

		resultado.setDigito(0,sum);
		//overflow=((A->GetDigito(0)+B->GetDigito(0))/10);

		for(c=1;c<=MaxDigi;c++){
			sum=((this->getDigito(c)+B.getDigito(c))%10);
			overflow=((this->getDigito(c-1)+B.getDigito(c-1)+overflow)/10);
			//if(sum+overflow)	//	Isso vai ter de voltar apos corrige lovelace....
			resultado.setDigito(c,(sum+overflow)%10);
		}
		overflow=((this->getDigito(c-1)+B.getDigito(c-1))/10);
		if (overflow)
			resultado.setDigito(c,overflow);

		for (c=resultado.getQuantidadeAlgarismos()-1;c > -1 && !resultado.getDigito(c);c--);

		if (int aux = (resultado.getQuantidadeAlgarismos()-1 - c)){
			while(aux--)
				resultado.reduzirAlgarismos();
		}
	}
	return resultado;
}

Lovelace Lovelace::subtrair(const Lovelace &B) const{
	Lovelace resultado;
	if (this->eZero()){
		resultado = B;
	}
	else if (B.eZero()){
		resultado = (*this);
	}
	else if (!this->eIgualA(B)){
		Lovelace Aaux,Baux;
		long long int c,diferenca;
		if (this->eMaiorQue(B)){
			Aaux = (*this);
			Baux = B;
		}
		else  {
			Aaux = B;
			Baux = (*this);
		}

		for(c=0;c<Aaux.getQuantidadeAlgarismos();c++)
		{
			diferenca=Aaux.getDigito(c)-Baux.getDigito(c);
			if(diferenca<0)//Caso haja divida na subtracao
			{
				long long int diferencaAux,cAux;

				for(diferencaAux=-1,cAux=c+1; diferencaAux<0;cAux++){
					if (Aaux.getDigito(cAux) > 0)
						Aaux.setDigito(cAux,diferencaAux=(Aaux.getDigito(cAux)-1));
					else
						Aaux.setDigito(cAux,9);
				}

				diferenca+=10;
			}
			resultado.setDigito(c,diferenca);
		}
		for (c=resultado.getQuantidadeAlgarismos()-1;c > -1 && !resultado.getDigito(c);c--);

		if (long long int aux = (resultado.getQuantidadeAlgarismos()-1 - c))
			while(aux--)
				resultado.reduzirAlgarismos();
	}
	return resultado;
}

Lovelace Lovelace::multiplicar_burro(const Lovelace &B) const{
	Lovelace resultado;
	if (this->naoEZero() && B.naoEZero()){
		Lovelace c,aux;
		bool log = this->eMaiorQue(B);
		aux = log?B:(*this);
		resultado = log?(*this):B;
		++c;

		while(aux.eMaiorQue(c)){
			resultado = (resultado+(log?(*this):B));
			++c;
		}
	}
	return resultado;
}

Lovelace Lovelace::multiplicar(const Lovelace &B) const{
	Lovelace resultado;
	if (this->naoEZero() && B.naoEZero()){
		Lovelace aux,aux1,temp;
		long long int c,c1,c2;
		int multiplicador,multiplicando,produto,overflow;
		bool log = this->eMaiorQue(B);
		aux = log?B:(*this);
		aux1 = log?(*this):B;

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
					temp.setDigito((c2+c1),overflow);//Só por isso vey kkkkkkkkkkkkk
				resultado+=temp;
			}
		}
	}
	return resultado;
}
int	Lovelace::removeZerosNaoSignificativos()
{	int numero,qtdAlg=getQuantidadeAlgarismos();

	for(numero=0; getDigito(qtdAlg)==0 ;qtdAlg--,numero++)
		reduzirAlgarismos();

	return numero;
}
int Lovelace::getMenorDivisao(const Lovelace &maior,const Lovelace &menor,Lovelace &saida) const{
	int c,k,d,qtdMaior=maior.getQuantidadeAlgarismos(),qtdMenor=menor.getQuantidadeAlgarismos(),inicio=(qtdMaior-qtdMenor);
	bool val=saida.eMenorQue(menor);
	saida.zerar();
	d=inicio;/*A abordagem já desloca algumas casas diretamente para poupar trabalho braçal mas isso era um tanto nebulo nesse algoritmo.Mas agora faz sentido*/

	while(val)
	{
		for(c=inicio,k=0;c<qtdMaior && c>-1;c++,k++)
			saida.setDigito(k,maior.getDigito(c));
		val=saida.eMenorQue(menor);
		if(val)
		{
			inicio--;
			d++;
		}
		else
			break;
	}

	return d;

}
void Lovelace::concatenaNumeros(const Lovelace &maisSignificativo,const Lovelace &menosSignificativo,Lovelace &saida) const{
	long long int c,qtdMais=maisSignificativo.getQuantidadeAlgarismos(),qtdMenos=menosSignificativo.getQuantidadeAlgarismos();
	saida.zerar();

	for(c=0; c<qtdMenos ; c++)
		saida.setDigito(c,menosSignificativo.getDigito(c));
	for(;(c-qtdMenos) < qtdMais; c++)
		saida.setDigito(c,maisSignificativo.getDigito(c-qtdMenos));
}
void Lovelace::inverteNumero(Lovelace &saida) const{
	long long int c,k,qtdAlg=this->getQuantidadeAlgarismos();
	saida.zerar();

	for(c=qtdAlg-1,k=0;c>-1;c--,k++)
		saida.setDigito(k,this->getDigito(c));
}
void Lovelace::dividir(const Lovelace &B,Lovelace &quociente,Lovelace &resto) const{
	quociente.zerar();
	resto = *this;
	if (B.eZero())
	{
		cout << "ERRO! OPERAÇÃO INVÁLIDA! Não é possível dividir por zero." << endl;
	}
	else if(this->eIgualA(B))
	{
		quociente.setDigito(0,1);
		resto.zerar();
	}
	else if (this->eMaiorQue(B))
	{
		Lovelace aux,aux2(*this);
		int	q,d,k=0;
		while(this->eMaiorQue(B))
		{

			q=d=this->getMenorDivisao(aux2,B,aux);

			while(d--)
				aux2.reduzirAlgarismos();
			if(k)
				while(q--)
					quociente.setDigito(k++,0);//Caso do deslocamento após a primeira





			for(q=0; aux.eMaiorOuIgualA(B); q++)
				aux-=B;

			quociente.setDigito(k++,q);
			aux.removeZerosNaoSignificativos();

			if(!aux.eZero())//Caso com resto
				this->concatenaNumeros(aux,aux2,aux2);
			else//caso sem
			{
				d=aux2.removeZerosNaoSignificativos();

				while(d--)//Sobra de zeros não significativos
					quociente.setDigito(k++,0);
			}

		}

		quociente.inverteNumero(quociente);
		resto=aux2;

	}
}


Lovelace Lovelace::dividir_burro(const Lovelace &B, bool quocienteOuResto) const{
	Lovelace resto, quociente;
	if (B.eZero()){
		cout << "ERRO! NÃ£o Ã© possÃ­vel dividir por zero." << endl;
	}
	else if (this->eIgualA(B)){
		quociente.setDigito(0,1);
	}
	else if (this->eMenorQue(B)){
		resto = (*this);
	}
	else if (this->naoEZero()){
		for (resto = (*this);resto.eMaiorOuIgualA(B);quociente.incrementar())
			resto -= B;
	}
	if (quocienteOuResto == true)
		return quociente;
	else
		return resto;
}
/*
Lovelace Lovelace::modulo(Lovelace &A, Lovelace &B){
	Lovelace resultado;

	return resultado;
}

Lovelace Lovelace::resto(Lovelace &A, Lovelace &B){
	Lovelace resultado;

	return resultado;
}

Lovelace Lovelace::resto_burro(Lovelace &A, Lovelace &B){
	Lovelace resultado;
	if (B.eZero()){
		cout << "ERRO! NÃ£o Ã© possÃ­vel dividir por zero." << endl;
	}
	else if (A.naoEZero()){
		if (A.eMenorQue(B)){
			resultado = A;
		}
		else if (A.eDiferenteDe(B)){
			resultado = A;
			while(resultado.eMaiorOuIgualA(B)){
				resultado -= B;
			}
		}
	}
	return resultado;
}
*/
Lovelace Lovelace::exponenciar(const Lovelace &X) const{
	Lovelace c,resultado;
	resultado.setDigito(0,1);
	if (!(X.eZero())) {
		for(c.atribuir(0);c.eMenorQue(X);++c,resultado*=(*this));
		/*
		c.imprimirInfo();
		getchar();
		X.imprimirInfo();
		getchar();
		resultado.imprimirInfo();
		getchar();
		//*/
	}
	return resultado;
}

Lovelace Lovelace::fatorial() const{
	Lovelace resultado,aux;
	resultado.setDigito(0,1);
	if (this->naoEZero()) {
		aux = 2;
		for (; aux.eMenorOuIgualA(*this);aux.incrementar())
			resultado *= aux;
	}
	return resultado;
}

bool Lovelace::eIgualA(const Lovelace &B) const{
	if (this == &B)
		return true;
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

bool Lovelace::eDiferenteDe(const Lovelace &B) const{
	return !(this->eIgualA(B));
}

bool Lovelace::eMaiorQue(const Lovelace &B) const{
	if (this == &B)
		return false;
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

bool Lovelace::eMenorQue(const Lovelace &B) const{
	if (this == &B)
		return false;
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

bool Lovelace::eMaiorOuIgualA(const Lovelace &B) const{
	return (this->eIgualA(B) || this->eMaiorQue(B));
}

bool Lovelace::eMenorOuIgualA(const Lovelace &B) const{
	return (this->eIgualA(B) || this->eMenorQue(B));
}
bool Lovelace::eImpar() const{	//Fazendo essa treta sem precisar de divisÃ£o
	if (eZero())
		return false;
	else
		return ((this->algarismos[0]>>4)&1);
}
bool Lovelace::ePar() const{
	return (!eImpar());
}

bool operator==(const Lovelace &A, const Lovelace &B){
	return (A.eIgualA(B));
}

bool operator!=(const Lovelace &A, const Lovelace &B){
	return A.eDiferenteDe(B);
}

bool operator>(const Lovelace &A, const Lovelace &B){
	return A.eMaiorQue(B);
}

bool operator>=(const Lovelace &A, const Lovelace &B){
	return A.eMaiorOuIgualA(B);
}

bool operator<(const Lovelace &A, const Lovelace &B){
	return A.eMenorQue(B);
}

bool operator<=(const Lovelace &A, const Lovelace &B){
	return A.eMenorOuIgualA(B);
}

Lovelace& Lovelace::operator=(Lovelace &B){
	if (&B != this){
		if (!zero)
			delete this->algarismos;
		if (B.zero)
			this->algarismos = NULL;
		else
			copiarAlgarismos(B,*this);
		this->setQuantidadeAlgarismos(B.getQuantidadeAlgarismos());
		this->setTamanho(B.getTamanho());
		this->setZero(B.eZero());
	}
	return (*this);
}

Lovelace& Lovelace::operator=(const Lovelace &B){
	this->atribuir(B);
	return (*this);
}

Lovelace& Lovelace::operator=(const unsigned long long int &numero){
	return atribuir(numero);
}
Lovelace& Lovelace::operator=(const int &numero){
	return atribuir(numero);
}

Lovelace Lovelace::operator+(const Lovelace &B) const{
	return somar(B);
}

Lovelace Lovelace::operator-(const Lovelace &B) const{
	return subtrair(B);
}

Lovelace Lovelace::operator*(const Lovelace &B) const{
	return multiplicar(B);
}

Lovelace Lovelace::operator/(const Lovelace &B) const{
	return dividir_burro(B);
}

Lovelace Lovelace::operator%(const Lovelace &B) const{
	return dividir_burro(B,false);
}

Lovelace Lovelace::operator^(const Lovelace &B) const{
	return exponenciar(B);
}

Lovelace& Lovelace::operator+=(const Lovelace &B){
	return ((*this) = somar(B));
}

Lovelace& Lovelace::operator-=(const Lovelace &B){
	return ((*this) = subtrair(B));
}

Lovelace& Lovelace::operator*=(const Lovelace &B){
	return ((*this) = multiplicar(B));
}

Lovelace& Lovelace::operator/=(const Lovelace &B){
	return ((*this) = dividir_burro(B));
}

Lovelace& Lovelace::operator%=(const Lovelace &B){
	return ((*this) = dividir_burro(B,false));
}

Lovelace& Lovelace::operator^=(const Lovelace &B){
	return ((*this) = exponenciar(B));
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

std::ostream &operator<<(std::ostream &out,const Lovelace &A){
	long long int c;
	char a, b;

	if (A.eZero()) {
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

/* InserÃ§Ã£o de fluxo char a char, problema com nÃºmeros impares de dÃ­gitos.
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
				cout << "ERRO! NÃ£o foi possÃ­vel alocar memÃ³ria para aux." << endl;
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
			cout << "ERRO! NÃ£o foi possÃ­vel alocar memÃ³ria para aux." << endl;
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
//*	InserÃ§Ã£o de fluxo por string
std::istream &operator>>(std::istream &in,Lovelace &A){
	string entrada;
	unsigned long long int tamanho;
	while(!entrada[0])
		getline(in, entrada);
	string::iterator it=entrada.begin();

	for (tamanho = 0; it!=entrada.end() && entrada[tamanho] >= '0' && entrada[tamanho] <= '9';tamanho++, ++it){
		if (!tamanho && entrada[tamanho] == '0')
			tamanho--;
	}

	if (tamanho == 0){
		A.zerar();
	}
	else {
		long long int c;
		tamanho--;

		for(c=tamanho;c>-1;c--)
			A.setDigito(tamanho-c,entrada[c]-'0');
	}

	return in;
}
//*/

