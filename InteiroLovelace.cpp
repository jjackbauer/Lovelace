#include "InteiroLovelace.h"
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

InteiroLovelace::InteiroLovelace(const Lovelace &copiarLovelace)
{
	setTamanho(copiarLovelace.getTamanho());
	setQuantidadeAlgarismos(copiarLovelace.getQuantidadeAlgarismos());
	setZero(copiarLovelace.eZero());
	setSinal(true);
	if (!copiarLovelace.eZero())
		copiarAlgarismos(copiarLovelace, *this);
}

void InteiroLovelace::inicializar(){
	Lovelace::inicializar();
	setSinal(true);
}

void InteiroLovelace::zerar(){
	Lovelace::zerar();
	setSinal(true);
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
	bool sinalMaior;
	toLovelace(auxA);
	B.toLovelace(auxB);

	if(this->getSinal() && B.getSinal())
	{
		InteiroLovelace resultado(auxA.somar(auxB));
		return resultado;
	}
	else {
		InteiroLovelace resultado(auxA.subtrair(auxB));
		sinalMaior = auxA.eMaiorQue(B)?this->getSinal():B.getSinal();
		resultado.setSinal(sinalMaior);
		return resultado;
	}
}

InteiroLovelace 	InteiroLovelace::subtrair(const InteiroLovelace &B) const{
	Lovelace auxA,auxB;
	bool sinalMaior;
	toLovelace(auxA);
	B.toLovelace(auxB);

	if((this->getSinal() && !B.getSinal()) ||(!this->getSinal() && B.getSinal()))// é possível fazer xor com expressões lógicas?
	{
		InteiroLovelace resultado(auxA.somar(auxB));
		resultado.setSinal(this->getSinal());
		return resultado;
	}
	else
	if(this->getSinal() && B.getSinal())
	{
		InteiroLovelace resultado(auxA.subtrair(auxB));
		resultado.setSinal(auxB.eMenorOuIgualA(auxA));
		return resultado;
	}
	else
	if(!this->getSinal() && !B.getSinal())
	{
		InteiroLovelace resultado(auxA.subtrair(auxB));
		resultado.setSinal(auxA.eMenorOuIgualA(auxB));
		return resultado;
	}
}

InteiroLovelace 	InteiroLovelace::multiplicar(const InteiroLovelace &B) const{
	Lovelace auxA,auxB;
	bool sinaisIguais=(this->getSinal()==B.getSinal());
	toLovelace(auxA);
	B.toLovelace(auxB);
	InteiroLovelace resultado(auxA.multiplicar(auxB));
	resultado.setSinal(sinaisIguais);
	return resultado;
}

void     InteiroLovelace::dividir(const InteiroLovelace &B,InteiroLovelace &resultado,InteiroLovelace &resto) const{
	Lovelace auxA,auxB;
	bool sinaisIguais=(this->getSinal()==B.getSinal());
	{
		InteiroLovelace result(auxA.dividir_burro(auxB));
		result.setSinal(sinaisIguais);
		resultado=result;//Mudar para atribuição
	}
	{
		InteiroLovelace rest(auxA.dividir_burro(auxB,false));
		rest.setSinal(sinaisIguais);//Essa lógica tem que ser revista
		resultado=rest;//Mudar para atribuição
	}
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

InteiroLovelace 	InteiroLovelace::incrementar()
{
	InteiroLovelace resultado;

	return resultado;
}
InteiroLovelace 	InteiroLovelace::decrementar(){
	InteiroLovelace resultado;

	return resultado;
}

InteiroLovelace& 	InteiroLovelace::atribuir(const long long int &numero){
	InteiroLovelace resultado;

	return resultado;
}

InteiroLovelace& 	InteiroLovelace::atribuir(const int &numero){
	InteiroLovelace resultado;

	return resultado;
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
	if (this->getSinal() != B.getSinal()){
		if (this->getSinal())
			return true;
		else
			return false;
	}
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


bool InteiroLovelace::eMenorQue(const InteiroLovelace &B) const{
	if (this == &B)
		return false;
	if (this->getSinal() != B.getSinal()){
		if (this->getSinal())
			return false;
		else
			return true;
	}
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

bool InteiroLovelace::eMaiorOuIgualA(const InteiroLovelace &B) const{
	return (this->eIgualA(B) || this->eMaiorQue(B));
}

bool InteiroLovelace::eMenorOuIgualA(const InteiroLovelace &B) const{
	return (this->eIgualA(B) || this->eMenorQue(B));
}


InteiroLovelace& InteiroLovelace::operator=(InteiroLovelace &B){

}

InteiroLovelace& InteiroLovelace::operator=(const InteiroLovelace &B){

}

InteiroLovelace& InteiroLovelace::operator=(const long long int &numero){

}

InteiroLovelace& InteiroLovelace::operator=(const int &numero){

}

InteiroLovelace& InteiroLovelace::operator+=(const InteiroLovelace &B){

}

InteiroLovelace& InteiroLovelace::operator-=(const InteiroLovelace &B){

}

InteiroLovelace& InteiroLovelace::operator*=(const InteiroLovelace &B){

}

InteiroLovelace& InteiroLovelace::operator/=(const InteiroLovelace &B){

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

}

std::istream &operator>>(std::istream &in,InteiroLovelace &A){

}

