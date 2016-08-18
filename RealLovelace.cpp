#include "RealLovelace.hpp"
long long int RealLovelace::casasDecimaisExibicao=100;

RealLovelace::RealLovelace()
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
	//Utilizar atribuir como base
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

}
RealLovelace RealLovelace::somar(const RealLovelace B) const
{

}
RealLovelace RealLovelace::subtrair(RealLovelace B) const
{

}
RealLovelace RealLovelace::multiplicar(RealLovelace B) const
{

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
