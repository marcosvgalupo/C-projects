include <stdio.h>

int main() {
  int x, y, i, j;
  scanf("%i %i", &x, &y);
  float vendas[40][20], somaprod[x], somavend[y], soma;

  do {
    scanf("%i %i", &i, &j);
    scanf("%f", &vendas[j][i]);

  } while ((i != 0) || (j != 0) || (vendas[j][i] != 0));

  for (j = 1; j <= x; j++) {
    soma = 0;
    for (i = 1; i <= y; i++) {
      soma += vendas[j][i];
    }
    somaprod[j] = soma;
  }
  for (i = 1; i <= y; i++) {
    soma = 0;
    for (j = 1; j <= x; j++) {
      soma += vendas[j][i];
    }
    somavend[i] = soma;
  }
  system("clear");
  printf("Tabela de Vendas (p = produto, v = vendedor)\n\n");
  printf("           ");
  for (int j = 1; j <= y; j++) {
    printf("v%i", j);
    printf("       ");
  }
  printf("\n");
  printf("   +");

  for (i = 1; i <= y; i++) {
    printf("---------");
  }
  printf("--");
  printf("+");

  for (j = 1; j <= x; j++) {
    printf("\np%i |  ", j);
    for (i = 1; i <= y; i++) {
      printf("  %6.2f ", vendas[j][i]);
    }
    printf("|   %.2f", somaprod[j]);
  }
  printf("\n");
  printf("   +");
  for (i = 1; i <= y; i++) {
    printf("---------");
  }
  printf("--");
  printf("+");
  printf("\n");
  printf("        ");
  for (i = 1; i <= y; i++) {
    printf("%.2f   ", somavend[i]);
  }
  printf("\n");
  return 0;
}
