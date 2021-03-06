/*
 * File:   menu.c
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


/*Fun��o Menu Principal  1*/
char Menu_Princ(int x)
{
    char i;

    if(x == 1)
    {
        i = '6';
        return i;
    }

    puts("          ****  MENU PRINCIPAL  ****\n");
    puts("  Escolher  Espaco e Populacao Simulacao   \t: 1");
    puts("  Escrever Espacos                         \t: 2");
    puts("  Escrever Populacao                       \t: 3");
    puts("  Preparacao dos espacos                   \t: 4");
    puts("  Inicia Distribuicao                      \t: 5");
    puts("  Iniciar Simulacao                        \t: 6");
    puts("  Recuperar Ultima  Execucao do Programa   \t: 7");
    puts("  Guardar e Terminar                       \t: 8");
    puts("\n");
    do
    {
        printf("  Escolha uma opcao: ");
        scanf(" %s",&i);
        puts("\n");

    }
    while (i <'1' || i >'8');

    return i;
}
/*Fim Fun��o Menu_Princ 1*/


/*Fun��o Menu para a escolha de Espa�os 2*/
char Menu_Espacos()
{
    char i;
    puts("  **** MENU ESPACOS ****\n");
    puts("  Espaco E1.bin     : 1");
    puts("  Espaco E2.bin     : 2");
    puts("  Espaco E3.bin     : 3");
    puts("  Espaco local2.dat : 4");
    puts("\n");
    do
    {
        printf("  Escolha uma opcao: ");
        scanf(" %s",&i);
        puts("\n");
    }
    while (i <'1' || i >'4');

    return i;
}
/*Fim Fun��o Menu_Espa�os 2*/


/*Fun��o Menu para a escolha do ficheiro Popula�ao  3*/
char Menu_Pop()
{
    char i;
    puts("  **** MENU  POPULACOES ****\n");
    puts("  Populacao pessoasA.txt : 1");
    puts("  Populacao pessoasB.txt : 2");
    puts("  Populacao pessoasC.txt : 3");
    puts("  Populacao pessoasD.txt : 4");
    puts("\n");
    do
    {
        printf("  Escolha uma opcao: ");
        scanf(" %s",&i);
        puts("\n");
    }
    while (i <'1' || i >'4');

    return i;
}
/*Fim Fun��o Menu_Pop 3*/


/*Fun��o Menu para a Intera��es  4*/
char Menu_Interacao()
{
    char i;
    puts("  **** Menu de Interacoes ****\n");
    puts("  Avancar proxima Interacao  :\t 1");
    puts("  Recuar Interacoes          :\t 2");
    puts("  Adicionar Doente           :\t 3");
    puts("  Mudar Pessoas de Sala      :\t 4");
    puts("  Apresentar Estatisticas    :\t 5");
    puts("  Voltar                     :\t 6");
    puts("\n");
    do
    {
        printf("  Escolha uma opcao: ");
        scanf(" %s",&i);
        puts("\n");
    }
    while (i <'1' || i >'6');

    return i;
}
/*Fim Fun��o Menu_Intera��o 4*/
