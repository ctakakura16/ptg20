#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cadastro.h"

int main() {
	criaIndex("Downloads\cad2020.csv", "Downloads\cad2020.ind");
}

void criarInd(char* narq, char* nind) {
	FILE* entrada, * saida;
	char linha[MAXLIN];
	char d1[MAXSTR];
	IndiceCadastro cad;

	entrada = fopen(narq, "r");
	saida = fopen(nind, "wb");

	if (!entrada || !saida) {
		printf("Erro");
		return;
	}
	while (fgets(linha, MAXLIN, entrada)) {
		extrair(linha, 1, d1);
		strcpy(cad.nome, d1);
		cad.loc = ftell(entrada);
		fwrite(&cad, sizeof(cad), 1, saida);
	}
}