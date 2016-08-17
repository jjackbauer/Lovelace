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
void InteiroLovelace::toLovelace(const InteiroLovelace &entrada,Lovelace &saida)
{
	Lovelace aux(entrada.algarismos,entrada.getTamanho(),entrada.getQuantidadeAlgarismos(),entrada.eZero());
	saida.atribuir(aux);
}
InteiroLovelace 	InteiroLovelace::somar( InteiroLovelace &A, InteiroLovelace &B)
{
	Lovelace auxA,auxB;
	bool sinalMaior;
	A.toLovelace(A,auxA);
	B.toLovelace(B,auxB);

	if(A.getSinal() && B.getSinal())
	{
		InteiroLovelace resultado(auxA.somar(auxA,auxB));
		return resultado;
	}
	else
	{	InteiroLovelace resultado(auxA.subtrair(auxA,auxB));
		sinalMaior = auxA.eMaiorQue(B)?A.getSinal():B.getSinal();
		resultado.setSinal(sinalMaior);
		return resultado;
	}
}
InteiroLovelace 	InteiroLovelace::subtrair(InteiroLovelace &A, InteiroLovelace &B)
{
	Lovelace auxA,auxB;
	bool sinalMaior;
	A.toLovelace(A,auxA);
	B.toLovelace(B,auxB);

	if((A.getSinal() && !B.getSinal()) ||(!A.getSinal() && B.getSinal()))// é possível fazer xor com expressões lógicas?
	{
		InteiroLovelace resultado(auxA.somar(auxA,auxB));
		resultado.setSinal(A.getSinal());
		return resultado;
	}
	else
	if(A.getSinal() && B.getSinal())
	{
		InteiroLovelace resultado(auxA.subtrair(auxA,auxB));
		resultado.setSinal(auxB.eMenorOuIgualA(auxA));
		return resultado;
	}
	else
	if(!A.getSinal() && !B.getSinal())
	{
		InteiroLovelace resultado(auxA.subtrair(auxA,auxB));
		resultado.setSinal(auxA.eMenorOuIgualA(auxB));
		return resultado;
	}
}
InteiroLovelace 	InteiroLovelace::multiplicar(InteiroLovelace &A, InteiroLovelace &B)
{
	Lovelace auxA,auxB;
	bool sinaisIguais=(A.getSinal()==B.getSinal());
	A.toLovelace(A,auxA);
	B.toLovelace(B,auxB);
	InteiroLovelace resultado(auxA.multiplicar(auxA,auxB));
	resultado.setSinal(sinaisIguais);
	return resultado;
}
void     			InteiroLovelace::dividir(InteiroLovelace &A, InteiroLovelace &B,InteiroLovelace &resultado,InteiroLovelace &resto)
{	Lovelace auxA,auxB;
	bool sinaisIguais=(A.getSinal()==B.getSinal());
	{
		InteiroLovelace result(auxA.dividir_burro(auxA,auxB));
		result.setSinal(sinaisIguais);
		resultado=result;//Mudar para atribuição
	}
	{
		InteiroLovelace rest(auxA.dividir_burro(auxA,auxB,false));
		rest.setSinal(sinaisIguais);//Essa lógica tem que ser revista
		resultado=rest;//Mudar para atribuição
	}
}
InteiroLovelace		InteiroLovelace::exponenciar(InteiroLovelace &A, InteiroLovelace &X)
{
	if(!A.eZero() && X.eMaiorQue(ZERO))
	{
		Lovelace auxA,auxX;
		A.toLovelace(A,auxA);
		X.toLovelace(X,auxX);

		InteiroLovelace resultado(auxA.exponenciar(auxA,auxX));
		if(!A.getSinal() && X.eImpar())
			resultado.setSinal(false);

		return resultado;
	}
	else
	{
		errorMessage("Operação inválida de exponenciação!");

	}
}

InteiroLovelace 	InteiroLovelace::incrementar()
{
	InteiroLovelace resultado;

	return resultado;
}
InteiroLovelace 	InteiroLovelace::decrementar()
{
	InteiroLovelace resultado;

	return resultado;
}
InteiroLovelace& 	InteiroLovelace::atribuir(unsigned long long int &numero)
{
	InteiroLovelace resultado;

	return resultado;
}
InteiroLovelace& 	InteiroLovelace::atribuir(const int &numero)
{
	InteiroLovelace resultado;

	return resultado;
}



InteiroLovelace	InteiroLovelace::fatorial(){
	if (getSinal())
		return Lovelace::fatorial();
}

InteiroLovelace& InteiroLovelace::inverterSinal(){
	InteiroLovelace resultado(*this);
	if (resultado.naoEZero())
			setSinal(!getSinal());
	return resultado;
}


bool InteiroLovelace::eIgualA(const InteiroLovelace &B){
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

bool InteiroLovelace::eDiferenteDe(const InteiroLovelace &B){
	return !(this->eIgualA(B));
}

bool InteiroLovelace::eMaiorQue(const InteiroLovelace &B){
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

bool InteiroLovelace::eMenorQue(const InteiroLovelace &B){
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

bool InteiroLovelace::eMaiorOuIgualA(const InteiroLovelace &B){
	return (this->eIgualA(B) || this->eMaiorQue(B));
}

bool InteiroLovelace::eMenorOuIgualA(const InteiroLovelace &B){
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

