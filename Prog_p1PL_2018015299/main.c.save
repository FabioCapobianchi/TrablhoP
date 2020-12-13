/*
 * File:   main.c
 * Author: FabioSouza
 * Numero:2018015299
* Created on 13 de junho de 2020, 15:54
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include<string.h>
#include "Functions.h"
#include "utils.h"
#include "menu.h"

int main(int argc, char** argv)
{

    ppessoas p=NULL;   /*ponteiro para array dinamico de estruturas "grupo\ppessoas*/
    plocais lc=NULL;   /*ponteiro para array dinamico de estruturas "locais\plocais*/
    psalas room=NULL;  /*ponteiro para lista ligada dinamica de estruturas "distribuicao\psalas*/
    pstat statistc;    /*ponteiro para lista ligada dinamica de estruturas "estatisticas\pstat*/
    int doentes = 0,*dt = &doentes;/*armazena numero total de doentes na altura que o ficheiro é lido*/
    int contp = 0;    /*contador total de pessoas*/
    int contlc = 0;   /*contador de locais*/
    int contlig = 0;  /*contador de salas criadas*/
    int captot = 0;   /*contador da capacidade total de um local*/
    int continterac = 0;   /*contador de interacoes*/
    int continteracaux=0;  /*contador de interacoes*/
    int control;   /*contador para verificacao do nome do ficheiro*/
    int flag=0,flagrecu=0,flagcont=0,i,j;  /*flags para o controle de ciclos*/
    char mpri,ml,mp,mm;   /*variaveis para funcao switch dos menu*/
    char res[10];   /*armazena string com o nome do ficheiro a ser criado para gravar a interacao*/
    char fich[20];  /*armazena o nome do ficheiro de texto para gravar a ultima interacao, é escolhido pelo utilizador*/
    char fich1[20]; /*armazena o nome do ficheiro  binario para ler quando e pedido pelo utilizador para voltar interacoes*/
    char fich2[20]; /*armazena o nome do ficheiro binario auxiliar com o mesmo nome do "fich" para a recuperacao da ultima execucao do programa*/
    initRandom();   // esta funcao so deve ser chamada uma vez

    if(room!=NULL)
        flag=1;
    puts("\n");
    puts("   **** BEM VINDO AO SIMULADOR DE CONTAGIO ****\n");

    /*Menu Principal*/
    do
    {
        mpri = Menu_Princ(flagrecu);
        flagrecu = 0;

        switch (mpri)
        {

        case '1':/*Escolhe ficheiro locais e pessoas*/
            room=NULL;
            p=NULL;
            lc=NULL;
            contlig=0;
            contp = 0;
            contlc = 0;
            captot = 0;
            continterac = 0;
            flagcont = 0;
            flag=0;
            do
            {   /*Menu para escolha do ficheiro com locais*/
                ml = Menu_Espacos();
                switch (ml)
                {
                case '1':
                    lc=Le_Local("E1.bin",&contlc);
                    captot = Capac_Total(lc,contlc);
                    if(lc==NULL)
                        exit(0);
                    break;
                case '2':
                    lc=Le_Local("E2.bin",&contlc);
                    captot = Capac_Total(lc,contlc);
                    if(lc==NULL)
                        exit(0);
                    break;
                case '3':
                    lc=Le_Local("E3.bin",&contlc);
                    captot = Capac_Total(lc,contlc);
                    if(lc==NULL)
                        exit(0);
                    break;
                case '4':
                    lc=Le_Local("local2.dat",&contlc);
                    captot = Capac_Total(lc,contlc);
                    if(lc==NULL)
                        exit(0);
                    break;
                }
            }
            while(ml<'1' || ml>'4');

            do
            {   /*Menu para escolha do ficheiro pessoas*/
                mp = Menu_Pop();
                switch (mp)
                {
                case '1':
                    p=Le_Person("pessoasA.txt",&contp,dt);
                    if(p==NULL)
                        exit(0);
                    break;
                case '2':
                    p=Le_Person("pessoasB.txt",&contp,dt);
                    if(p==NULL)
                        exit(0);
                    break;
                case '3':
                    p=Le_Person("pessoasC.txt",&contp,dt);
                    if(p==NULL)
                        exit(0);
                    break;
                case '4':
                    p=Le_Person("pessoasD.txt",&contp,dt);
                    if(p==NULL)
                        exit(0);
                    break;
                }
            }
            while(mp<'1' || mp>'4');
            break;
        /*Fim escolhe ficheiro locais e pessoas*/


        case '2':/*Mostra no ecra toda a informacao dos locais lidos do ficheiro binario*/
            Escreve_Espacos(lc,&contlc);
            break;
        case '3':/*Mostra no ecra toda a informacao das pessoas lidas do ficheiro*/
            Escreve_Person(p,&contp);
            break;
        case '4':/*Cria uma lista ligada com o numero de nos que o numero de locais*/
            room = NULL;
            contlig = 0;
            room = Cria_Salas(lc,&contlig,contlc);
            break;
        case '5':/*Faz a distribuicao aleatoriamente de pessoas pelos locais criados na lista room e mostra no ecra*/
            room = Distribuicao(room, lc, p, contlig, contp, captot, &flag);
            Escreve_Distri(room);
            break;
        case '6':
            if(room == NULL || flag == 0)
            {
                printf("    ******  Falta Fazer a Distribuicao opcao '5'  ******\a\n\n");
                break;
            }
            do
            {
                /*Menu Interacao*/
                mm = Menu_Interacao();
                switch (mm)
                {
                case '1':/*Executa as interacoes*/
                    if(flagcont == 0)/*Compara se sao interacoes atuais ou recuperadas e imprime*/
                    {
                        printf("      ******  Interacao n%d  ********\n\n",continterac+1);
                    }
                    if(flagcont == 1)/*Compara se sao interacoes atuais ou recuperadas e imprime*/
                    {
                        printf("      ******  Interacao n%d  ********\n\n",++continteracaux);
                    }

                    Interact(room);/*Faz a interacao*/
                    continterac++;/*Atualiza o numero de interacoes*/
                    statistc = Calcula_Estat(room);/*Faz o Calculo estatistico e guarda na estrutura*/
                    Cria_Fich(res, continterac);/*Cria o nome para um ficheiro binario como paremetro utiliza o numero de interacoes*/
                    Guarda_Interacao(room,res,contlig);/*Grava em ficheiro a interacao atual*/

                    break;
                case '2':/*Recua nas interacoes*/
                    do
                    {
                        do
                        {
                            printf("  *** Quantas dias deseja retornar? : ");
                            scanf("%d",&continteracaux);
                        }
                        while(continteracaux < 0 || continteracaux > 10);
                        putchar('\n');
                        if(continteracaux >= continterac)
                        {
                            printf("  Nao e Possivel retornar %d interacoes \n\n",continteracaux);

                        }
                    }
                    while(continteracaux >= continterac);
                    continteracaux = (continterac - continteracaux);
                    printf("      ********  Interacao n%d  ********\n\n",continteracaux);
                    Cria_Fich(res,continteracaux);/*Cria o nome do ficheiro como referencia do numero de interacoes a retornar*/
                    room = Recupera_Inter(res);/*Recupera o ficheiro com a interacao pedida grava na estrutura e escreve no ecra*/
                    flagcont = 1;
                    break;
                case '3':/*Adiciona um novo doente a uma sala escolhida pelo utilizador atualiza estatistica da sala e mostra no ecra*/
                    room = Adiciona_Doente(room);
                    statistc = Calcula_Estat(room);
                    break;
                case '4':/*Muda um numero de doentes de uma sala para outra escolhidos pelo utilizador atualiza estatistica e mostra no ecra*/
                    room = Muda_Pessoas(room);
                    statistc = Calcula_Estat(room);
                    Escreve_Distri(room);
                    break;
                case '5':/*Mostra no ecra a estatistica da interacao atual*/
                    Doente_maisnovo(room);
                    Mostra_Estat(statistc);
                    break;
                case '6':
                    break;
                }
            }
            while(mm != '6');

            break;
        case '7':/*No inicio da execucao pede ao utilizador o nome do ficheiro e recupera a ultima interacao de uma execucao anterior do programa*/
            if(room == NULL)
            {
                do
                {
                    printf("  Digite o Nome do Ficheiro Binario para o Recuperar : ");
                    scanf(" %s",fich1);
                    printf("\n");
                    control = strlen(fich1);
                }
                while(fich1[control-1]!= 'n' || fich1[control-2]!= 'i' || fich1[control-3]!= 'b' || fich1[control-4]!= '.');
                room = Recupera_Inter(fich1);
                if(room != NULL)
                {
                    statistc = Calcula_Estat(room);
                    printf("   *** Ultima Execucao Recuperada com Sucesso ***\n\n");
                    flag = 1;
                    flagrecu = 1;
                }
                else
                {
                    printf("   *** Impossivel Recuperar Execucao ***\n\n");
                    flag = 0;
                }
            }
            else
            {
                printf("   *** Impossivel Recuperar Dados Durante a Simulacao ***\n\n");
            }
            break;
        case '8':/*Pede ao utilizador o nome de ficheiro pra guardar a ultima interacao, guarda relatorio final */

            if(room != NULL)
            {
                do
                {
                    printf("  Digite o Nome do Ficheiro de Texto para o Guardar Ultima Interacao : ");
                    scanf(" %s",fich);
                    printf("\n");
                    control = strlen(fich);
                }
                while(fich[control-1]!= 't' || fich[control-2]!= 'x' || fich[control-3]!= 't' || fich[control-4]!= '.');
                Guarda_EstadoFim(room,fich,continterac);
                /*Cria um ficheiro com o mesmo nome do anterior com formato ".bin"*/
                for(i=4,j=0; i<strlen(fich); i++,j++)
                {
                    fich2[j]=fich[j];
                }
                strcat(fich2,".bin");
                Guarda_Tudo(room,"report.txt",continterac,statistc);
                Guarda_Interacao(room,fich2,contlig);
            }
            else
            {
                printf("   **** Nao Existem Dados Para Gravar  ***\n");
            }
            /*Remove os ficheiros criados para gravar interacoes, liberta a memoria e encerra o programa*/
            for(i=0; i<continterac; i++)
            {
                Cria_Fich(res,i+1);
                remove(res);
            }
            free(p);
            free(lc);
            Liberta_Lista(room);
            printf("                   ------------------\n                   Programa terminou!\n                   ------------------\n");
            exit(0);
            break;
        }
    }
    while(mpri!='8');
    /*Fim menu Principal*/

    return 0;
}
