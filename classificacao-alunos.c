#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

# define MAX_NOTAS 2
# define MAX_ALUNOS 3

struct cadastroAlunos {
    char nome[20];
    float nota[MAX_NOTAS];
    float media;
} aluno[MAX_ALUNOS];

int main() {

    int i;
    int j;
    float somaNota;

	// arrays
    char vNome[MAX_ALUNOS][20];
    float vMedia[MAX_ALUNOS];

	// temps
    char nomeTemp[20];
    float mediaTemp;

    setlocale(LC_ALL, "");

    /*** ENTRADA ***/

    printf("Cadastro Alunos\n");
    printf("\n");

    i = 0;  /* aluno */
    while ( i < MAX_ALUNOS ) {
        printf("Informe o nome do %dº aluno: ", i+1);
        scanf("%s", &aluno[i].nome);
        j = 0;  /* nota */
        while ( j < MAX_NOTAS ) {
            printf("Informe a %dª nota: ", j+1);
            scanf("%f", &aluno[i].nota[j]);
            j++;
        }
        printf("\n");
        i++;
    }

    /*** PROCESSAMENTO ***/

    /* médias */

    i = 0;  /* aluno */
    while ( i < MAX_ALUNOS ) {
        somaNota = 0;
        j = 0;  /* nota */
        while ( j < MAX_NOTAS ) {
            somaNota += aluno[i].nota[j];
            j++;
        }
        aluno[i].media = somaNota/j;
        i++;
   }

   /* classificação */

   /* preenche vetores */

   i = 0;   /* aluno */
   while ( i < MAX_ALUNOS ) {
        strcpy(vNome[i], aluno[i].nome);
        vMedia[i] = aluno[i].media;
    i++;
   }

    /* método bolha */

    i = 0;
    while ( i < MAX_ALUNOS - 1 ) {
        j = 0;
        while ( j < MAX_ALUNOS - 1 - i ) {
            if ( vMedia[j] < vMedia[j+1] ) {
                strcpy(nomeTemp,vNome[j]);
                strcpy(vNome[j], vNome[j+1]);
                strcpy(vNome[j+1], nomeTemp);

                mediaTemp = vMedia[j];
                vMedia[j] = vMedia[j+1];
                vMedia[j+1] = mediaTemp;
            }
            j++;
        }
        i++;
    }

    /*** SAÍDA ***/

    /* média */

    printf("*** Médias ***\n");

    putchar('\n');

    i = 0;  /* aluno */
    while ( i < MAX_ALUNOS ) {
        printf("%s: \t %.1f\n", aluno[i].nome, aluno[i].media);
        i++;
    }

    putchar('\n');

    /* classificação */

    printf("*** Classificação geral ***\n");

    putchar('\n');

    i = 0;
    while ( i < MAX_ALUNOS ) {
        printf("%dº lugar: %s \t Média: %.1f\n", i+1, vNome[i], vMedia[i]);
        i++;
    }

	system("pause");

    return 0;
}

