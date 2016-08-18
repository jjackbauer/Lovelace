#include "InteiroLovelace.hpp"

const InteiroLovelace ZERO;

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

InteiroLovelace::InteiroLovelace(const Lovelace &copiarLovelace){
	setTamanho(copiarLovelace.getTamanho());
	setQuantidadeAlgarismos(copiarLovelace.getQuantidadeAlgarismos());
	setZero(copiarLovelace.eZero());
	setSinal(true);
	if (!copiarLovelace.eZero())
		copiarAlgarismos(copiarLovelace, *this);
}
InteiroLovelace::InteiroLovelace(const char *algarismos,int tamanho,int quantidadeAlgarismos,bool zero,bool sinal)
: Lovelace(algarismos,tamanho,quantidadeAlgarismos,zero)
{
	setSinal(sinal);

}
void InteiroLovelace::inicializar(){
	Lovelace::inicializar();
	setSinal(true);
}

void InteiroLovelace::zerar(){
	Lovelace::zerar();
	setSinal(true);
}
void InteiroLovelace::imprimir() const{
	imprimir(0);
}

void InteiroLovelace::imprimir(char separador) const{
	if (eNegativo())
		cout << '-';
	Lovelace::imprimir(separador);
}

void InteiroLovelace::imprimirInfo(int opcao) const{
	cout << "sinal              : " << getSinal() << endl;
	Lovelace::imprimirInfo(opcao);
}

bool InteiroLovelace::getSinal() const{
	return sinal;
}

void InteiroLovelace::setSinal(bool novoSinal){
	sinal = novoSinal;
}

void InteiroLovelace::toLovelace(Lovelace &saida) const{
	Lovelace aux(this->algarismos,this->getTamanho(),this->getQuantidadeAlgarismos(),this->eZero());
	saida.atribuir(aux);
}

InteiroLovelace 	InteiroLovelace::somar(const InteiroLovelace &B) const{
	Lovelace auxA,auxB;
	toLovelace(auxA);
	B.toLovelace(auxB);

	if (this->getSinal() == B.getSinal()){
		InteiroLovelace resultado(auxA.somar(auxB));
		resultado.setSinal(this->getSinal());
		return resultado;
	}
	else {
		InteiroLovelace resultado(auxA.subtrair(auxB));
		bool sinalMaior = auxA.eMaiorQue(B)?this->getSinal():B.getSinal();
		resultado.setSinal(sinalMaior);
		return resultado;
	}
}

InteiroLovelace 	InteiroLovelace::subtrair(const InteiroLovelace &B) const{
	Lovelace auxA,auxB;
	toLovelace(auxA);
	B.toLovelace(auxB);

	if(this->getSinal() != B.getSinal()){
		InteiroLovelace resultado(auxA.somar(auxB));
		resultado.setSinal(this->getSinal());
		return resultado;
	}
	else if(this->ePositivo() && B.ePositivo()){
		InteiroLovelace resultado(auxA.subtrair(auxB));
		resultado.setSinal(auxB.eMenorOuIgualA(auxA));
		return resultado;
	}
	else if(this->eNegativo() && B.eNegativo()){
		InteiroLovelace resultado(auxA.subtrair(auxB));
		resultado.setSinal(auxA.eMenorOuIgualA(auxB));
		return resultado;
	}
}

InteiroLovelace 	InteiroLovelace::multiplicar(const InteiroLovelace &B) const{
	Lovelace auxA,auxB;
	toLovelace(auxA);
	B.toLovelace(auxB);
	InteiroLovelace resultado(auxA.multiplicar(auxB));
	resultado.setSinal(this->getSinal()==B.getSinal());
	return resultado;
}

void     InteiroLovelace::dividir(const InteiroLovelace &B,InteiroLovelace &quociente,InteiroLovelace &resto) const{
	Lovelace auxA,auxB;
	toLovelace(auxA);
	B.toLovelace(auxB);
	bool sinaisIguais=(this->getSinal()==B.getSinal());
	{
		InteiroLovelace result(auxA.dividir_burro(auxB));
		result.setSinal(sinaisIguais);
		quociente.atribuir(result);
	}
	{
		InteiroLovelace rest(auxA.dividir_burro(auxB,false));
		rest.setSinal(sinaisIguais);//Essa lógica tem que ser revista
		resto.atribuir(rest);
	}
}
InteiroLovelace 	InteiroLovelace::dividir(const InteiroLovelace &B, bool quocienteOuResto) const{
	Lovelace auxA,auxB;
	toLovelace(auxA);
	B.toLovelace(auxB);

	InteiroLovelace resultado(auxA.dividir_burro(auxB,quocienteOuResto));
	resultado.setSinal(this->getSinal()==B.getSinal());

	return resultado;
}

InteiroLovelace		InteiroLovelace::exponenciar(const InteiroLovelace &X) const{
	if(!this->eZero() && X.eMaiorQue(ZERO)){
		Lovelace auxA,auxX;
		toLovelace(auxA);
		X.toLovelace(auxX);

		InteiroLovelace resultado(auxA.exponenciar(auxX));
		if(!this->getSinal() && X.eImpar())
			resultado.setSinal(false);

		return resultado;
	}
	else
		errorMessage("Operação inválida de exponenciação!");
}

InteiroLovelace 	InteiroLovelace::incrementar(){
	InteiroLovelace aux;
	aux.setDigito(0,1);//aux=1; Equivalente após sobrecarga //Remover depois de fazer a base pro java!
	return ((*this) = somar(aux));
}
InteiroLovelace 	InteiroLovelace::decrementar(){
	InteiroLovelace aux;
	aux.setDigito(0,1);
	return ((*this) = subtrair(aux));
}

InteiroLovelace& 	InteiroLovelace::atribuir(long long int numero){
	unsigned long long int n = numero;
	Lovelace::atribuir(n);
	if (numero >= 0)
		setSinal(true);
	else
		setSinal(false);
	return (*this);
}

InteiroLovelace& 	InteiroLovelace::atribuir(const int &numero){
	long long int aux = numero;
	return atribuir(aux);
}

InteiroLovelace& 	InteiroLovelace::atribuir(const InteiroLovelace &B){
	if (&B != this){
		if (naoEZero())
			delete this->algarismos;
		if (B.eZero())
			this->algarismos = NULL;
		else
			copiarAlgarismos(B,*this);
		this->setQuantidadeAlgarismos(B.getQuantidadeAlgarismos());
		this->setTamanho(B.getTamanho());
		this->setZero(B.eZero());
		this->setSinal(B.getSinal());
	}
	return (*this);
}

InteiroLovelace&    InteiroLovelace::atribuir(string numeroEmString){
	long long int inicio, tamanho;
	string::iterator it=numeroEmString.begin();

	for (tamanho = 0, inicio = 0; it!=numeroEmString.end() && ((numeroEmString[tamanho] >= '0' && numeroEmString[tamanho] <= '9') || numeroEmString[tamanho] == '-');++tamanho, ++it){
		if (!tamanho) {
			if (numeroEmString[tamanho] == '0')
				inicio++;
			else if (numeroEmString[tamanho] == '-'){
				setSinal(false);
				inicio++;
			}
		}
	}

	if (tamanho-inicio == 0){
		this->zerar();
	}
	else {
		long long int c;
		tamanho--;

		for(c=tamanho;c>=inicio;c--)
			this->setDigito(tamanho-c,numeroEmString[c]-'0');
	}

	return (*this);
}

InteiroLovelace	InteiroLovelace::fatorial() const{
	InteiroLovelace resultado;
	if (!getSinal())
		resultado = Lovelace::fatorial();
	return resultado;
}

InteiroLovelace InteiroLovelace::inverterSinal() const{
	InteiroLovelace resultado(*this);
	if (this->naoEZero())
		resultado.setSinal(!getSinal());
	return resultado;
}

bool InteiroLovelace::eIgualA(const InteiroLovelace &B) const{
	if (this == &B)
		return true;
	if (this->getSinal() != B.getSinal())
		return false;
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


bool InteiroLovelace::eDiferenteDe(const InteiroLovelace &B) const{
	return !(this->eIgualA(B));
}

bool InteiroLovelace::eMaiorQue(const InteiroLovelace &B) const{
	if (this == &B)
		return false;
	if (this->getSinal() != B.getSinal())
		return ePositivo();
	else if (this->getQuantidadeAlgarismos() == B.getQuantidadeAlgarismos()){
		if (this->eZero() && B.eZero())
			return false;
		long long int c;
		for (c = this->getQuantidadeAlgarismos();c && this->getDigito(c) == B.getDigito(c);c--);

		if (this->getDigito(c) > B.getDigito(c))
			return ePositivo();
		else
			return eNegativo();
	}
	else if (this->getQuantidadeAlgarismos() > B.getQuantidadeAlgarismos())
		return this->ePositivo();
	else
		return this->eNegativo();
	return true;
}


bool InteiroLovelace::eMenorQue(const InteiroLovelace &B) const{
	if (this == &B)
		return false;
	if (this->getSinal() != B.getSinal())
		return eNegativo();
	else if (this->getQuantidadeAlgarismos() == B.getQuantidadeAlgarismos()){
		if (this->eZero() && B.eZero())
			return false;
		long long int c;
		for (c = this->getQuantidadeAlgarismos();c && this->getDigito(c) == B.getDigito(c);c--);

		if (this->getDigito(c) < B.getDigito(c))
			return ePositivo();
		else
			return eNegativo();
	}
	else if (this->getQuantidadeAlgarismos() < B.getQuantidadeAlgarismos())
		return this->ePositivo();
	else
		return this->eNegativo();
	return true;
}

bool InteiroLovelace::eMaiorOuIgualA(const InteiroLovelace &B) const{
	return (this->eIgualA(B) || this->eMaiorQue(B));
}

bool InteiroLovelace::eMenorOuIgualA(const InteiroLovelace &B) const{
	return (this->eIgualA(B) || this->eMenorQue(B));
}

bool InteiroLovelace::ePositivo() const{
	return getSinal();
}

bool InteiroLovelace::eNegativo() const{
	return !getSinal();
}

InteiroLovelace& InteiroLovelace::operator=(InteiroLovelace &B){
	if (&B != this){
		if (naoEZero())
			delete this->algarismos;
		if (B.eZero())
			this->algarismos = NULL;
		else
			copiarAlgarismos(B,*this);
		this->setQuantidadeAlgarismos(B.getQuantidadeAlgarismos());
		this->setTamanho(B.getTamanho());
		this->setZero(B.eZero());
		this->setSinal(B.getSinal());
	}
	return (*this);
}

InteiroLovelace& InteiroLovelace::operator=(const InteiroLovelace &B){
	this->atribuir(B);
	return (*this);
}

InteiroLovelace& InteiroLovelace::operator=(const long long int &numero){
	return atribuir(numero);
}

InteiroLovelace& InteiroLovelace::operator=(const int &numero){
	return atribuir(numero);
}

InteiroLovelace& InteiroLovelace::operator+=(const InteiroLovelace &B){
	return ((*this) = somar(B));
}

InteiroLovelace& InteiroLovelace::operator-=(const InteiroLovelace &B){
	return ((*this) = subtrair(B));
}

InteiroLovelace& InteiroLovelace::operator*=(const InteiroLovelace &B){
	return ((*this) = multiplicar(B));
}

InteiroLovelace& InteiroLovelace::operator/=(const InteiroLovelace &B){
	return ((*this) = dividir(B));
}

InteiroLovelace& InteiroLovelace::operator%=(const InteiroLovelace &B){

}

InteiroLovelace& InteiroLovelace::operator^=(const InteiroLovelace &B){

}

/*	Operações Aritméticas 	*/
InteiroLovelace InteiroLovelace::operator+(const InteiroLovelace &B) const{
	return somar(B);
}

InteiroLovelace InteiroLovelace::operator-(const InteiroLovelace &B) const{
	return subtrair(B);
}

InteiroLovelace InteiroLovelace::operator*(const InteiroLovelace &B) const{
	return multiplicar(B);
}

InteiroLovelace InteiroLovelace::operator/(const InteiroLovelace &B) const{
	InteiroLovelace resultado;
	//return dividir(B);
	return resultado;
}

InteiroLovelace InteiroLovelace::operator%(const InteiroLovelace &B) const{
	return multiplicar(B);
}

InteiroLovelace InteiroLovelace::operator^(const InteiroLovelace &B) const{
	return exponenciar(B);
}

/*	Operações Inc/Dec 	*/
InteiroLovelace& InteiroLovelace::operator++(){
	this->incrementar();
	return (*this);
}

InteiroLovelace& InteiroLovelace::operator--(){
	this->decrementar();
	return (*this);
}

InteiroLovelace InteiroLovelace::operator++(int semuso){
	InteiroLovelace retorno;
	retorno = (*this);
	this->incrementar();
	return retorno;
}

InteiroLovelace InteiroLovelace::operator--(int semuso){
	InteiroLovelace retorno;
	retorno = (*this);
	this->decrementar();
	return retorno;
}


/* 	Operações de Comparação 	*/
bool operator==(const InteiroLovelace &A, const InteiroLovelace &B){
	return (A.eIgualA(B));
}

bool operator!=(const InteiroLovelace &A, const InteiroLovelace &B){
	return (A.eDiferenteDe(B));
}

bool operator>(const InteiroLovelace &A, const InteiroLovelace &B){
	return A.eMaiorQue(B);
}

bool operator<(const InteiroLovelace &A, const InteiroLovelace &B){
	return A.eMenorQue(B);
}

bool operator>=(const InteiroLovelace &A, const InteiroLovelace &B){
	return A.eMaiorOuIgualA(B);
}

bool operator<=(const InteiroLovelace &A, const InteiroLovelace &B){
	return A.eMenorOuIgualA(B);
}


/*	Operações de Ext/Ins de Fluxo 	*/
std::ostream &operator<<(std::ostream &out,const InteiroLovelace &A){
	long long int c;
	char a, b;

	if (A.eNegativo())
		cout << '-';
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

std::istream &operator>>(std::istream &in,InteiroLovelace &A){
	string entrada;
	while(!entrada[0])
		getline(in, entrada);
	A.atribuir(entrada);

	return in;
}

