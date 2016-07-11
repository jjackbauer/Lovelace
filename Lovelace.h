#ifndef LOVELACE_H
#define LOVELACE_H

class Lovelace
{	
	private:
		char *Algarismos;
		long long int Tamanho;
		bool Sinal;
		bool Ezero;
		
	public:
		static long long int Precisao;
		static char* TabelaDeConversao;
		static long long int AlgarismosExibicao;
		
		Lovelace();
		~Lovelace();
		
		void SetDigito(long long int Posicao, char Digito);
		void SetTamanho(long long int Tamanho);
		void SetSinal(int Sinal);
		void SetBitWise(long long int Posicao,char A, char B);//Faltou parametro posição no UML.
		void SetAlgarismosExibicao(long long int Numero);

		char GetDigito(long long int Posicao);
		long long int GetTamanho();
		int GetSinal();
		void GetBitWise(long long int Posicao,char &A, char &B);//Correção do diagrama: setor desnecessário
		long long int GetAlgarismosExibicao();

		&Lovelace Atribuicao(int A);
		&Lovelace Atribuicao(Lovelace &A, Lovelace B);
		&Lovelace Soma(Lovelace A, Lovelace B);
		&Lovelace Subtracao(Lovelace A, Lovelace B);
		&Lovelace Multiplicacao(Lovelace A, Lovelace B);
		&Lovelace Divisao(Lovelace A, Lovelace B);
		&Lovelace InversaoDeSinal(Lovelace A);
		&Lovelace Inversao(Lovelace A);
		&Lovelace Exponenciacao(Lovelace A, Lovelace X);
		&Lovelace Fatorial(Lovelace N);
		bool VerificaEzero(); // Nome redefinido por possuir nome conflitante com atributo no diagrama UML.
		void SetZero(bool Zero);
		void Imprime();

};

#endif
