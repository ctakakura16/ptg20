
#include <stdio.h>
#include <math.h>

void main()
{
	float a, b, c, delta, x1, x2;
	printf("Digite o valor de A: ");
	scanf_s("%f", &a);
	printf("Digite o valor de B: ");
	scanf_s("%f", &b);
	printf("Digite o valor de C: ");
	scanf_s("%f", &c);
	if (a != 0) {
		delta = (b * b) - (4 * a * c);
		if (delta == 0) {
			x1 = (-b + sqrt(delta))/(2*a);
			printf("x1 = x2 = %.2f", x1);
		}
		else {
			if (delta > 0) {
				x1 = (-b + sqrt(delta))/(2*a);
				x2 = (-b - sqrt(delta))/(2*a);
				printf("x1 = %.2f\n", x1);
				printf("x2 = %.2f", x2);
			}
			else {
				printf("Não há raízes reais");
			}
		}
	}
	else {
		printf("Não é equação de 2º grau");
	}
}
