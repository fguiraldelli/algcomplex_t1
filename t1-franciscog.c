/************************************************************************
*																		*
*						Trabalho 1 - Complexidade						*
*							Profª. Cândida								*
*																		*
*		Aluno: Francisco A. C. C. B. Guiraldelli	RA: 379840			*
*																		*
************************************************************************/


#include <stdio.h>

#define MAX 1000000

int main() {

	int quantidade_numeros_da_sequencia;
	int sequencias_dadas[MAX];
	long long int soma_da_sequencia;
	long long int maior_numero_ida;
	long long int maior_numero_volta;
	int i;
	quantidade_numeros_da_sequencia = 1;

	while (quantidade_numeros_da_sequencia) {

		/*Inicialização de variáveis*/
		soma_da_sequencia = 0;

		maior_numero_ida = 0;
		maior_numero_volta = 0;

		/*Lê da entrada padrão a sequência*/
		scanf("%d", &quantidade_numeros_da_sequencia);

		/*Preenche o vetor*/
		for (i = 0; i < quantidade_numeros_da_sequencia; i++)
			scanf("%d", &sequencias_dadas[i]);


		/*Faz a soma dos elementos do vetor da esquerda para a direita (ida)*/
		for (i = 0; i < quantidade_numeros_da_sequencia; i++) {
			soma_da_sequencia += sequencias_dadas[i];
			if (soma_da_sequencia > maior_numero_ida)
				maior_numero_ida = soma_da_sequencia;
			else if(soma_da_sequencia <= 0)
				soma_da_sequencia = 0;
		}

		soma_da_sequencia = 0;

		/*Faz a soma dos elementos do vetor da direita para a esquerda (volta)*/
		for (i = quantidade_numeros_da_sequencia - 1; i >= 0; i--) {
			soma_da_sequencia += sequencias_dadas[i];
			if (soma_da_sequencia > maior_numero_volta)
				maior_numero_volta = soma_da_sequencia;
			else if(soma_da_sequencia <= 0)
				soma_da_sequencia = 0;
		}
		/*Faz a comparação entre a soma da ida e da volta e imprime a maior soma*/
		if (quantidade_numeros_da_sequencia != 0) {
			if (maior_numero_ida >= maior_numero_volta)
				printf("%lld\n", maior_numero_ida);
			else
				printf("%lld\n", maior_numero_volta);
		}
	}
	return 0;
}