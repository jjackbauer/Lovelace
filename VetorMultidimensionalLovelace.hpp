#ifndef VETORMULTIDIMENSIONALLOVELACE_HPP_
#define VETORMULTIDIMENSIONALLOVELACE_HPP_

class VetorMuldimensionalLovelace {
	private:
		long long int multidimensao;
		VetorLovelace dimensoes;
	public:
		VetorMuldimensionalLovelace();
		~VetorMuldimensionalLovelace();
		void imprimir();
		long long int 	getMultidimensao();
		void 			setMultidimensao(long long int novaMultidimensao);
		RealLovelace 	getElemento(long long int dimensao, long long int posicao);
		void 			setElemento(long long int dimensao, long long int posicao, RealLovelace X);
		VetorMuldimensionalLovelace somar(const VetorMuldimensionalLovelace &B) const;
		VetorMuldimensionalLovelace subtrair(const VetorMuldimensionalLovelace &B) const;
		VetorMuldimensionalLovelace multiplicar(const RealLovelace &K) const;
		VetorMuldimensionalLovelace multipliar(const VetorMuldimensionalLovelace &B) const;
};



#endif /* VETORMULTIDIMENSIONALLOVELACE_HPP_ */
