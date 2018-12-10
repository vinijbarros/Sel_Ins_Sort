#include <stdio.h>
#include <stdlib.h>

/* Aluno: Vinicius J. Barros - 11228375 */


/* Metodo de Ordenação Insertion Sort */
void InsertionSort(int *vetor, int max)
{

    int i=0, j=0;

    FILE *ler;

    ler = fopen("test.txt", "r");   //Abre o arquivo que deseja ser ordenado. Pode alterar o arquivo colocando
                                    // no lugar de "test.txt"
    for(i=0; i<max; i++)            // Ler os valores do arquivo ate o ultimo, onde,  i == max.
    {    
        fscanf(ler, "%d/n", &vetor[i]);   
    }


    ler = fopen("test_insertion.txt", "w");   //Abre um arquivo que sera salvo o vertor ordenado

//Metodo de Ordenação --> Insertion Sort
int aux=0;

    for (i = 1; i < max; i++) 
    {
            j = i;
            while (j > 0 && vetor[j - 1] > vetor[j]) 
            {
                  aux = vetor[j];
                  vetor[j] = vetor[j - 1];
                  vetor[j - 1] = aux;
                  j--;
            }
    }

for (i = 0; i < max; i++) 
    {
    fprintf (ler,"%d \n",vetor[i]);
    }
    fclose(ler);
}
/* Fim do metodo */


/* Metodo de ordenação Selection Sort */
void SelectionSort(int *vetor, int max)
{

 int i=0, j=0, min=0, temp=0;

    FILE *ler;

    ler = fopen("test.txt", "r");   //Abre o arquivo que deseja ser ordenado. Pode alterar o arquivo colocando
                                    // no lugar de "test.txt"
    for(i=0; i<max; i++)            // Ler os valores do arquivo ate o ultimo, onde,  i == max.
    {
        fscanf(ler, "%d/n", &vetor[i]); 
        
    }


    ler = fopen("test_selection.txt", "w");    //Abre um arquivo que sera salvo o vertor ordenado

//Metodo de ordenação  --> Selection Sort

    for(i=0; i<max; i++)
    {
        min = i;

        for(j=i+1; j<max+1; j++)
        {
            if (vetor[j]<vetor[min])
            { 
                min = j;
            }
        }    
        if(i != min)
        {
            temp = vetor[i];
            vetor[i] = vetor[min];
            vetor[min] = temp;
        }
        fprintf(ler, "%d\n", vetor[i]);
    }

    fclose(ler);
}


//******* MAIN *******

int main()
{
    int elemento=0;
    int maximo=0;
	char letra; 
    char eof = '\n';

    FILE *ler;

    ler = fopen("test.txt", "r");   //Conta os elementos(numeros) que estão no arquivo de entrada
                                    // para descobrir o tamanho do vetor que iremos usar posteriormente    
    while(fread(&letra, sizeof(char),1, ler))
    {
	   if(letra == eof) 
        {
            elemento++;
        }
	}

	fclose(ler);

	maximo = elemento+1;     //Pega o numero total de elementos(numeros) e atribui para a variavel max
                        // que sera usada para determinar o tamanho do vetor.

    int vetor[maximo];     //Inicializa o vetor que sera salvo os elementos do arquivo
                        // e que sera usado na ordenação

    InsertionSort(&vetor[0], maximo);

    SelectionSort(&vetor[0], maximo);

    InsertionSort(&vetor[0], maximo);
    printf("VETOR ORDENADO USANDO O INSERTION SORT\n");

    SelectionSort(&vetor[0], maximo);
    printf("VETOR ORDENADO USANDO O SELECTION SORT\n");
    printf("FIM!\n");
    return 0;
}
/* FIM */

