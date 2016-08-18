#include "RealLovelace.hpp"
long long int RealLovelace::casasDecimaisExibicao=100;
void RealLovelace::digitosToBitwise(long long int tamanho,char * entrada,char* saida)
{
	int c;
	if(saida)
		delete []saida;

	saida = new char[tamanho/2];

	for(c=0;((2*c)+1)<tamanho;c++)
		saida[c]=((entrada[2*c]<<4)+(entrada[2*c+1]));

	if(tamanho&1)//Se for impar seta um digito inválido na ultima posição
		saida[c]=((entrada[2*c]<<4)+15);



}
InteiroLovelace& RealLovelace::toInteiroLovelace(long long int zeros)
{	int qtdAlgs = zeros+getQuantidadeAlgarismos() ;
	char *digitos = new char[qtdAlgs];
	char *algs;

	for(int c=0;c<zeros;c++)
		digitos[c]=0;
	for(int c=zeros;c<getQuantidadeAlgarismos();c++)
		digitos[c]= getDigito(c-zeros);

	digitosToBitwise(qtdAlgs,digitos,algs);
	InteiroLovelace *resultado = new InteiroLovelace(algs,qtdAlgs/2,qtdAlgs,eZero(),getSinal());
	//Mozila Warming
	return *resultado;
}
RealLovelace::RealLovelace()
:InteiroLovelace()//Talvez isso já fosse feito de forma automática.... mas...
{
	setExpoente(0);
}
RealLovelace::RealLovelace(const double A)
{
	//Utilizar atribuir como base
}
RealLovelace::RealLovelace(string A)
{
	//Utilizar atribuir como base
}
RealLovelace::RealLovelace(const RealLovelace &A)
{
	atribuir(A);
}
void RealLovelace::setExpoente(long long int X)
{
	expoente=X;
}
long long int RealLovelace::getExpoente() const{
	return expoente;
}
void RealLovelace::setCasasDecimaisExibicao(long long int n)
{
	casasDecimaisExibicao=n;
}
long long int RealLovelace::getCasasDecimaisExibicao()
{
	return casasDecimaisExibicao;
}
RealLovelace & RealLovelace::atribuir(const double A)
{
	//Vai ser chato, melhor forma é converter pra string esse carai...
}
RealLovelace & RealLovelace::atribuir(const string A)
{
	//Esperando definição da função para Inteiro Lovelace
}
RealLovelace & RealLovelace::atribuir(const RealLovelace &A)
{
	this->copiarAlgarismos(A,*this);
	this->setQuantidadeAlgarismos(A.getQuantidadeAlgarismos());
	this->setTamanho(A.getTamanho());
	this->setZero(A.eZero());
	this->setExpoente(A.getExpoente());
	this->setSinal(A.getSinal());
}
RealLovelace RealLovelace::somar(const RealLovelace B) const
{	if(this->getExpoente()==B.getExpoente())
	{
		InteiroLovelace auxA((toInteiroLovelace(0)));//Bug estranho, checar!
		InteiroLovelace auxB(B.toInteiroLovelace(0));
		return auxA.somar(B);//Tem que converter esse resultado
	}
	if(this->getExpoente()>B.getExpoente())
	{
		long long int zeros = (this->getExpoente()-B.getExpoente());
		InteiroLovelace auxA((toInteiroLovelace(zeros)));
		InteiroLovelace auxB(B.toInteiroLovelace(0));
		return auxA.somar(B);
	}
	else
	{
		long long int zeros = (this->getExpoente()-B.getExpoente());
		InteiroLovelace auxA((toInteiroLovelace(0)));
		InteiroLovelace auxB(B.toInteiroLovelace(zeros));
		return auxA.somar(B);
	}
}
RealLovelace RealLovelace::subtrair(RealLovelace B) const
{
	if(this->getExpoente()==B.getExpoente())
	{
		InteiroLovelace auxA((toInteiroLovelace(0)));
		InteiroLovelace auxB(B.toInteiroLovelace(0));
		return auxA.subtrair(B);
	}
	if(this->getExpoente()>B.getExpoente())
	{
		long long int zeros = (this->getExpoente()-B.getExpoente());
		InteiroLovelace auxA((toInteiroLovelace(zeros)));
		InteiroLovelace auxB(B.toInteiroLovelace(0));
		return auxA.subtrair(B);
	}
	else
	{
		long long int zeros = (this->getExpoente()-B.getExpoente());
		InteiroLovelace auxA((toInteiroLovelace(0)));
		InteiroLovelace auxB(B.toInteiroLovelace(zeros));
		return auxA.subtrair(B);
	}
}
RealLovelace RealLovelace::multiplicar(RealLovelace B) const
{
	InteiroLovelace auxA((toInteiroLovelace(0)));
	InteiroLovelace auxB(B.toInteiroLovelace(0));


}
RealLovelace RealLovelace::dividir(RealLovelace B) const
{

}
RealLovelace RealLovelace::inverter() const
{

}
RealLovelace RealLovelace::exponenciar(RealLovelace X) const
{

}
void RealLovelace::imprimir() const
{

}
void RealLovelace::ler()
{

}
