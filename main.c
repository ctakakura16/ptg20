#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cadastro.h"

int main() {
	FILE* fp;

	char linha[MAXLIN];
	char d1[MAXLIN], d2[MAXLIN], d3[MAXLIN];
	char nome[MAXLIN];
	char *ptr;

	fp = fopen("Downloads\cad2020.csv", "r");

	if (!fp) {
		printf("Erro");
		return -1;
	}

	printf("Digite o nome completo: ");
	fgets(nome, MAXLIN, stdin);
	ptr = nome;
	while (*ptr != '\0' && *ptr != '\n') {
		ptr++;
	}
	*ptr = '\0';
	printf("Nome: %s\n", nome);

	while (fgets(linha, MAXLIN, fp)) {
		extrair(linha, 1, d1);
		if (!strcmp(d1, nome)) {
			extrair(linha, 4, d2);
			extrair(linha, 16, d3);

			printf("\n%s \n%s\n%s\n", d1, d2, d3);
			return 0;
		}
	}
}

void extrair(char* l, int e, char* d) {
	char linha[MAXLIN],*p, *q;
	int i = 0;
	strcpy(linha, l);
	p = linha;

	while (*p != '\0') {
		if (e == i) {
			if (*p == '"') p++;
			q = p;
			while (*q != '"') q++;
			*q = '\0';
			strcpy(d, p);
			return;
		}
		if (*p == ';') {
			i++;
		}
		p = p + 1; 
	}
}