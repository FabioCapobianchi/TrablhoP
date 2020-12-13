/*
 * File:   Functions.h
 * Author: FabioSouza
 * Numero:2018015299
 * Created on 13 de junho de 2020, 15:54
 */

#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

typedef struct estatistica stat, *pstat;/*Estrutura que armazena as estatisticas das interacoes 1*/
typedef struct locais local, *plocais;/*Estrutura que armazena os Locais 2*/
typedef struct grupo pessoa, *ppessoas;/*Estrutura que armazena as Pessoas 3*/
typedef struct distribuicao salas, *psalas;/*Estrutura que armazena a distribuicao das pessoas pelos locais 4*/
typedef struct person people, *ppeople;/*Estrutura que armazena as pessoas dentro da estrutura salas 5*/
typedef struct interacoes interact, *pinteract;/*Estrutura que armazena as Interacoes 6*/

/*Estrutura que armazena as estatisticas das interacoes 1*/
struct estatistica/*pstat*/
{
    int id;
    int np;
    int dt;
    int sal;
    int imu;
    pstat next;
};

/*Estrutura que armazena os Locais 2*/
struct locais /*plocais*/
{
    int id;
    int capacidade;
    int liga[3];
};

/*Estrutura que armazena as Pessoas 3*/
struct grupo /*ppessoas*/
{
    char nome[100];
    int idade;
    char estado;
    int dias;
};

/*Estrutura que armazena a distribuicao das pessoas pelos locais 4*/
struct distribuicao /*psalas*/
{
    int idd;
    int ctp;
    int sick;
    int sal;
    int imu;
    local  lc;
    ppeople lista;
    psalas next;

};

/*Estrutura que armazena as pessoas dentro da estrutura salas 5*/
struct person /*ppeople*/
{
    char nome[100];
    int idade;
    char estado;
    int dias;
    ppeople prox;
};

void Doente_maisnovo(psalas p);

void initRandom();

pessoa *Le_Person(char *f,int *np,int *dt);//1

void Escreve_Person(pessoa *p,int *cont);//2

local* Le_Local(char *space,int *t);//3

int Verifica_Local(local *p, int *t);//4

void Escreve_Espacos(local *tab, int *n);//5

void Escreve_Info(local x);//6

int Capac_Total(plocais lc,int cl);//7

salas *Cria_Salas(local *lcc, int *cd, int cl);//8

salas *Distribuicao(psalas sl, local *lcc,pessoa * p, int cd, int cp, int captot, int *flag);//9

void Escreve_Distri(psalas p);//10

psalas Atualiza_Dias(psalas ps);//11

psalas Interact(psalas p);//12

int Taxa_Diss(int pop, float tx);//13

void Guarda_Interacao(psalas p, char *nomeF, int ctd);//14

psalas Recupera_Inter(char *nomeF);//15

ppeople insereFinalP(ppeople p, ppeople novo);//16

psalas insereFinalL(psalas p, psalas nova);//17

void Cria_Fich(char *res,int interac);//18

psalas Adiciona_Doente(psalas ps);//19

psalas Muda_Pessoas(psalas ps);//20

int Verifica_Idsala(psalas p, int ido);//21

int Verifica_Liga(psalas p,int ido, int idd);//22

int Verifica_CapacO(psalas p,int ido,int npm);//23

int Verifica_CapacD(psalas p,int idd,int npm);//24

psalas Move_Pessoas(psalas p,int ido,int idd);//25

pstat Calcula_Estat(psalas p);//26

pstat Novo_Estat(int id,int tp,int dt,int sal,int imu);//27

int Calculo_Aux(int est,int np);//28

pstat insereFinalE(pstat p, pstat nova);//29

void Mostra_Estat(pstat statistc);//30

void Guarda_EstadoFim(psalas pp, char *nomeF,int ctd);//31

void Guarda_Tudo(psalas pp, char *nomeF,int ctd,pstat st);//32

void Liberta_Lista(salas *p);//33

#endif // FUNCTIONS_H_INCLUDED
