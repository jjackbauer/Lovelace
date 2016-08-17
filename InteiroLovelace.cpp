#include "InteiroLovelace.h"

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

void InteiroLovelace::inicializar(){
	Lovelace::inicializar();
	setSinal(false);
}

void InteiroLovelace::zerar(){
	Lovelace::zerar();
	setSinal(false);
}

bool InteiroLovelace::getSinal() const{
	return sinal;
}

void InteiroLovelace::setSinal(bool novoSinal){
	sinal = novoSinal;
}

InteiroLovelace InteiroLovelace::somar(InteiroLovelace &A, InteiroLovelace &B){

}

InteiroLovelace InteiroLovelace::subtrair(InteiroLovelace &A, InteiroLovelace &B){

}

InteiroLovelace InteiroLovelace::multiplicar_burro(Lovelace &A, InteiroLovelace &B){

}

InteiroLovelace InteiroLovelace::multiplicar(InteiroLovelace &A, InteiroLovelace &B){

}

void  InteiroLovelace::dividir(InteiroLovelace &A, InteiroLovelace &B,InteiroLovelace &resultado,InteiroLovelace &resto){

}

InteiroLovelace InteiroLovelace::dividir_burro(InteiroLovelace &A, InteiroLovelace &B, bool quocienteOuResto){

}

InteiroLovelace	InteiroLovelace::exponenciar(Lovelace &A, Lovelace &X){ /* Tivemos uma idéia para melhorar a exponenciação*/

}


InteiroLovelace	InteiroLovelace::fatorial(){
	if (!getSinal())
		return Lovelace::fatorial();
}

InteiroLovelace& InteiroLovelace::inverterSinal(){
	InteiroLovelace resultado(*this);
	if (resultado.naoEZero())
			setSinal(!getSinal());
	return resultado;
}


InteiroLovelace InteiroLovelace::incrementar(){

}

InteiroLovelace InteiroLovelace::decrementar(){

}

InteiroLovelace& InteiroLovelace::atribuir(unsigned long long int &numero){

}

InteiroLovelace& InteiroLovelace::atribuir(const int &numero){

}

bool InteiroLovelace::eIgualA(InteiroLovelace &B){
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

bool InteiroLovelace::eDiferenteDe(InteiroLovelace &B){
	return !(this->eIgualA(B));
}

bool InteiroLovelace::eMaiorQue(InteiroLovelace &B){
	if (this == &B)
		return false;
	if (this->getSinal() != B.getSinal()){
		if (this->getSinal())
			return false;
		else
			return true;
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

bool InteiroLovelace::eMenorQue(InteiroLovelace &B){
	if (this == &B)
		return false;
	if (this->getSinal() != B.getSinal()){
		if (this->getSinal())
			return true;
		else
			return false;
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

bool InteiroLovelace::eMaiorOuIgualA(InteiroLovelace &B){
	return (this->eIgualA(B) || this->eMaiorQue(B));
}

bool InteiroLovelace::eMenorOuIgualA(InteiroLovelace &B){
	return (this->eIgualA(B) || this->eMenorQue(B));
}


InteiroLovelace& InteiroLovelace::operator=(InteiroLovelace &B){

}

InteiroLovelace& InteiroLovelace::operator=(const InteiroLovelace &B){

}

InteiroLovelace& InteiroLovelace::operator=(unsigned long long int &numero){

}

InteiroLovelace& InteiroLovelace::operator=(const int &numero){

}

InteiroLovelace& InteiroLovelace::operator+=(InteiroLovelace &B){

}

InteiroLovelace& InteiroLovelace::operator-=(InteiroLovelace &B){

}

InteiroLovelace& InteiroLovelace::operator*=(InteiroLovelace &B){

}

InteiroLovelace& InteiroLovelace::operator/=(InteiroLovelace &B){

}

InteiroLovelace& InteiroLovelace::operator%=(InteiroLovelace &B){

}

InteiroLovelace& InteiroLovelace::operator^=(InteiroLovelace &B){

}

/*	Operações Aritméticas 	*/
InteiroLovelace InteiroLovelace::operator+(InteiroLovelace &B){

}

InteiroLovelace InteiroLovelace::operator-(InteiroLovelace &B){

}

InteiroLovelace InteiroLovelace::operator*(InteiroLovelace &B){

}

InteiroLovelace InteiroLovelace::operator/(InteiroLovelace &B){

}

InteiroLovelace InteiroLovelace::operator%(InteiroLovelace &B){

}

InteiroLovelace InteiroLovelace::operator^(InteiroLovelace &B){

}

/*	Operações Inc/Dec 	*/
InteiroLovelace& InteiroLovelace::operator++(){

}

InteiroLovelace& InteiroLovelace::operator--(){

}

InteiroLovelace InteiroLovelace::operator++(int semuso){

}

InteiroLovelace InteiroLovelace::operator--(int semuso){

}


/* 	Operações de Comparação 	*/
bool operator==(InteiroLovelace &A, InteiroLovelace &B){

}

bool operator!=(InteiroLovelace &A, InteiroLovelace &B){

}

bool operator>(InteiroLovelace &A, InteiroLovelace &B){

}

bool operator<(InteiroLovelace &A, InteiroLovelace &B){

}

bool operator>=(InteiroLovelace &A, InteiroLovelace &B){

}

bool operator<=(InteiroLovelace &A, InteiroLovelace &B){

}


/*	Operações de Ext/Ins de Fluxo 	*/
std::ostream &operator<<(std::ostream &out,InteiroLovelace &A){

}

std::istream &operator>>(std::istream &in,InteiroLovelace &A){

}



