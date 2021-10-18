#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct cadastroAlunos {

    char nome[20];
    float nota[4];
    float media;
} aluno[3];

int main() {

    int i;
    int j;
    float somaNota;

    char vNome[3][20];
    float vMedia[3];

    char nomeTemp[20];
    float mediaTemp;

    setlocale(LC_ALL, "");

    /*** ENTRADA ***/

    printf("Cadastro Alunos\n");
    printf("\n");

    i = 0;  /* aluno */
    while ( i < 3 ) {

        printf("Informe o nome do %d� aluno: ", i+1);
        scanf("%s", &aluno[i].nome);

        j = 0;  /* nota */
        while ( j < 4 ) {

            printf("Informe a %d� nota: ", j+1);
            scanf("%f", &aluno[i].nota[j]);

            j++;
        }

        printf("\n");

        i++;
    }

    /*** PROCESSAMENTO ***/

    /* m�dias */

    i = 0;  /* aluno */
    while ( i < 3 ) {

        somaNota = 0;
        j = 0;  /* nota */
        while ( j < 4 ) {

            somaNota += aluno[i].nota[j];

            j++;
        }

        aluno[i].media = somaNota/j;

        i++;
   }

   /* classifica��o */

   /* preenche vetores */

   i = 0;   /* aluno */
   while ( i < 3 ) {

        strcpy(vNome[i], aluno[i].nome);
        vMedia[i] = aluno[i].media;

    i++;

   }

    /* m�todo bolha */

    i = 0;
    while ( i < 3 - 1 ) {

        j = 0;
        while ( j < 3 - 1 - i ) {

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

    /*** SA�DA ***/

    /* m�dia */

    printf("*** M�dias ***\n");

    printf("\n");

    i = 0;  /* aluno */
    while ( i < 3 ) {

        printf("%s: \t %.1f\n", aluno[i].nome, aluno[i].media);

        i++;
    }

    printf("\n");

    /* classifica��o */

    printf("*** Classifica��o geral ***\n");

    printf("\n");

    i = 0;
    while ( i < 3 ) {

        printf("%d� lugar: %s \t M�dia: %.1f\n", i+1, vNome[i], vMedia[i]);

        i++;
    }

    return 0;
}
