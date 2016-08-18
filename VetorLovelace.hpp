#ifndef VETORLOVELACE_HPP_
#define VETORLOVELACE_HPP_
class VetorLovelace {
	private:
		long long int dimensionalidade;
		RealLovelace *elementos;
	public:
		VetorLovelace();
		~VetorLovelace();
		void imprimir();
		RealLovelace 	getElemento(long long int posicao);
		void 			setElemento(long long int posicao, RealLovelace X);
		long long int 	getDimensionalidade();
		void			setDimensionalidade(long long int novaDimensionalidade);
		VetorLovelace	somar(const VetorLovelace &B) const;
		VetorLovelace	subtrair(const VetorLovelace &B) const;
		RealLovelace 	produtoInterno(const VetorLovelace &B) const;
		VetorLovelace	multiplicar(const RealLovelace &K) const;
};




#endif /* VETORLOVELACE_HPP_ */
