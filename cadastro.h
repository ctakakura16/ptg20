#define MAXLIN 1000
#define MAXSTR 200

void extrair(char* l, int e, char* d);
void criarInd(char* narq, char* nind);

typedef struct INDICECAD {
	char nome[MAXSTR];
	unsigned long loc;
} IndiceCadastro;