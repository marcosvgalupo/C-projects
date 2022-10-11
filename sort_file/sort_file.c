#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[30];
  int cell;
  char twitter[20];
} registro;

void sort(registro agenda[], int n) {
  registro k; 
  for (int i = n; i > 1; i--) {
    for (int j = 0; j < i - 1; j++) {
      if (strcmp(agenda[j].name, agenda[j + 1].name) >0) { 
        k = agenda[j];
        agenda[j] = agenda[j + 1];
        agenda[j + 1] = k;
      }
    }
  }
}

int main(void) {
  int i, lines = 1;
  FILE *arq;
  char ex;
  registro agenda[100];
  arq = fopen("agenda.csv", "rt");
  if (arq == NULL) {
    printf("File not found!!");
    getchar();
    exit(999);
  }

  while (!feof(arq)) {
    ex = fgetc(arq);
    if (ex == '\n') {
      lines++;
    }
  }
  fclose(arq);
  

  arq = fopen("agenda.csv", "rt");
  for (i = 0; i < lines; i++) {
    fscanf(arq, "%[^;]s", agenda[i].name);
    fgetc(arq);
    fscanf(arq, "%d", &agenda[i].cell);
    fgetc(arq);
    fscanf(arq, "%s\n", agenda[i].twitter);
  }

  sort(agenda, lines);
  fclose(arq);

  arq = fopen("agenda-ord.csv", "w");
  for (i = 0; i < lines; i++) {
    fprintf(arq, "%s;%i;%s\n", agenda[i].name, agenda[i].cell,agenda[i].twitter);
  }
  fclose(arq);
}
