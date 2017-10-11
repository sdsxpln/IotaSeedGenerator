#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int main(void){

    char nome_do_arquivo[255],biblioteca[]={"ABCDEFGHIJKLMNOPQRSTUVXYWZ9"},*seed,c,*tamanho;
    int i,tamanho_inteiro;
    FILE *arq;
    tamanho=malloc(255*sizeof(char));

    srand(time(NULL));

    printf("ATENCAO A SEED SERA GERADA SEGUINDO ESSAS LETRAS E NUMERO 9 \n\n%s\n===========================================\n",biblioteca);
    printf("\n\n\nATENCAO O TAMANHO DEVE SER ENTRE 30 A 81\n\n ");


    do{fgets(tamanho,255,stdin);
    tamanho_inteiro = atoi(tamanho);
    if (tamanho_inteiro<30||tamanho_inteiro>81)
        printf("Digite um numero entre 30 e 81\n");}
    while(tamanho_inteiro<30||tamanho_inteiro>81);

    printf("Valor digitado foi %d\n",tamanho_inteiro);

    printf("Aperte enter para confirmar a escolha\n");

    while ((c = getchar()) != '\n' && c != EOF) {} /*consume \n*/

    printf("\n\n\nDigite o nome do Arquivo a ser criado\n\n");

    fgets(nome_do_arquivo,255,stdin);

    printf("\n Nome do arquivo eh = ");
    puts(nome_do_arquivo);

    arq=fopen(nome_do_arquivo,"w+a+");

    if(arq==NULL){
        printf("ERRO na ABERTURA\n");
        fclose(arq);
    }
    seed=malloc( tamanho_inteiro * sizeof(int));
    printf("Gerando SEED\n\n\n");
    for(i=0;i<tamanho_inteiro;i++){
        seed[i] = biblioteca[rand()%27];
        }
        printf("\nSEED = %d\n",strlen(seed));


    printf("Seed Gerada com Sucesso\n\n %s \n",seed);

    fprintf(arq,"SEED CARTEIRA IOTA \n\n\n    %s",seed);

    fclose(arq);
    free(seed);
    free(tamanho);


    return 0;

    }
