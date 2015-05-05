/************************************************************************
*																		*
*						Trabalho 1 - Complexidade						*
*							Profª. Cândida								*
*																		*
*		Aluno: Francisco A. C. C. B. Guiraldelli	RA: 379840			*
*																		*
************************************************************************/


#include <stdio.h>

#define MAX 10000

int main() {

	int quantidade_numeros_da_sequencia;
	int sequencias_dadas[MAX];
	long long int produto_da_sequencia;
	long long int maior_numero_ida;
	long long int maior_numero_volta;
	int i;
	quantidade_numeros_da_sequencia = 1;

	while (quantidade_numeros_da_sequencia) {

		/*Inicialização de variáveis*/
		produto_da_sequencia = 1;
		maior_numero_ida = 1;
		maior_numero_volta = 1;

		/*Lê da entrada padrão a sequência*/
		scanf("%d", &quantidade_numeros_da_sequencia);

		/*Preenche o vetor*/
		for (i = 0; i < quantidade_numeros_da_sequencia; i++)
			scanf("%d", &sequencias_dadas[i]);

		/*Faz o produto dos elementos do vetor da esquerda para a direita (ida)*/
		for (i = 0; i < quantidade_numeros_da_sequencia; i++) {
			produto_da_sequencia *= sequencias_dadas[i];
			if (produto_da_sequencia == 0)
				produto_da_sequencia = 1;
			if (produto_da_sequencia > maior_numero_ida)
				maior_numero_ida = produto_da_sequencia;
		}

		produto_da_sequencia = 1;

		/*Faz o produto dos elementos do vetor da direita para a esquerda (volta)*/
		for (i = quantidade_numeros_da_sequencia - 1; i >= 0; i--) {
			produto_da_sequencia *= sequencias_dadas[i];
			if (produto_da_sequencia == 0)
				produto_da_sequencia = 1;
			if (produto_da_sequencia > maior_numero_volta)
				maior_numero_volta = produto_da_sequencia;
		}
		/*Faz a comparação entre o produto da ida e da volta e imprime o maior produto*/
		if (quantidade_numeros_da_sequencia != 0) {
			if (maior_numero_ida >= maior_numero_volta)
				printf("%lld\n", maior_numero_ida);
			else
				printf("%lld\n", maior_numero_volta);
		}
	}
	return 0;
}