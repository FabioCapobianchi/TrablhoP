/*
 * File:   Functions.c
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
#define MAX 3
#define TX 0.5
#define TXI 0.20
#define EST 100


/*Função que le o ficheiro de texto com a populaçao escolhida e guarda em um array dinamico de estruturas 1*/
pessoa *Le_Person(char *f,int *n, int *dt)
{
    FILE *f1;
    pessoa *d,*c = NULL;
    int v,ct=0;
    char ch = 'D';

    f1=fopen(f,"r");
    if(f1==NULL)
    {
        printf("  *** Erro no acesso ao ficheiro %s ***\n",f);
    }
    if(c == NULL)
    {
        c = malloc(sizeof(pessoa)* 1);
    }

    while((v = fscanf(f1,"%s %d %c %d", c[ct].nome, &c[ct].idade, &c[ct].estado, &c[ct].dias)!=EOF))
    {

        ct+=v;
        d = realloc(c, sizeof (pessoa) * (ct+1));
        if(d == 0)
        {
            printf(" *** Erro de alocacao.txt ***");
            return d;
        }
        c = d;
        if ((c[ct - 1].estado) != ch)
        {
            c[ct - 1].dias = 0;
        }
        else
        {
            if ((c[ct - 1].estado) == ch)
                *dt += 1;
        }
    }
    *n=ct;
    return c;
}
/*Fim Função Le_Person 1*/


/*Função Mostra no ecra as pessoas guardadas no array dinamico de estruturas 2*/
void Escreve_Person(pessoa *p,int *cont)
{
    int i;
    if(p == NULL)
    {
        printf("   ****** Falta Escolher a Populacao opcao '1' ******\7\n");
    }else{
        printf("   ***** O Ficheiro escolhido tem %d pessoas *****\n\n",*cont);
    for(i=0; i<*cont; i++)
    {
        printf(" %s %d %c %d\n", p[i].nome, p[i].idade, p[i].estado, p[i].dias);
    }
    }
    puts("\n\n");
}
/*Fim Função Escreve_Person 2*/


/*Função que le o ficheiro binario com os locais escolhidos e guarda em um array dinamico de estruturas 3*/
local* Le_Local(char *space,int *t)
{

    FILE *f1;
    local *lc1 = NULL,*lc2 = NULL;
    int v,contlc=0,res;
    *t = 0;

    f1 = fopen(space, "rb");
    if(f1==NULL)
    {
        printf("  *** Erro no acesso ao ficheirobin ***\n");
        return lc2;
    }
    lc1 = malloc(sizeof(local)* 1);
    while((v = fread(lc1, sizeof(local), 1, f1)) == 1)
    {
        contlc+=v;
    }
    fclose(f1);

    lc1 = malloc(sizeof(local)* contlc);
    if(lc1 == NULL)
    {
        printf(" *** Erro de alocacao.bin ***");
        return lc1;
    }

    f1 = fopen(space, "rb");
    if(f1==NULL)
    {
        printf("    *** Erro no acesso ao ficheirobin ***\n");
        return lc2;
    }
    fread(lc1, sizeof(local), contlc, f1);
    fclose(f1);
    *t=contlc;

    if ((res = Verifica_Local(lc1, t)) == 0)
    {
        printf("   *** Erro na verificacao dos locais ***\7\n\n");
        printf("      ******* Fim do Programa ******\n");
        return lc2;
        exit(0);
    }
    return lc1;
}
/*Fim Função Le_Local 3*/


/*Função que Verifica se as ligações e ids dos locais correspondem  e se  ids são positivos 4*/
int Verifica_Local(local *p, int *t)
{
    int i,ii,iii,j, k, m = 0, flag = 1;
    for(i=0; i<*t; i++)
    {
        if(p[i].id<0)
        {
            flag = 0;
            return flag;
        }
    }
    for(ii=0; ii<*t; ii++)
    {
        for(iii=ii+1; iii<*t; iii++)
            if(p[ii].id == p[iii].id)
            {
                flag = 0;
                return flag;
            }
    }


    for (j = 0; j < *t; j++)
    {
        for (k = 0; k < MAX; k++)
        {
            if ((p[j].liga[k]) != -1)
                for (m = 0; m < 3; m++)
                {
                    if ((p[j].liga[k]) == p[m].id)
                    {
                        if ((p[j].id) != p[m].liga[0] && p[j].id != p[m].liga[1] && p[j].id != p[m].liga[2])
                        {
                            flag = 0;
                        }
                    }
                }
        }
    }

    if (flag == 0)
    {
        return flag;
    }
    flag = 1;
    return flag;
}
/*Fim Função Verifica_Local 4*/


/*Funçao que escreve no ecra toda a informação dos espaços 5*/
void Escreve_Espacos(local *tab, int *n)
{
    int i;
    if(*n==0)
    {
        printf("   ******  Falta escolher Espacos opcao '1'  ******\7\n\n");
    }else{
        printf("   ***** O espaco escolhido tem %d salas *****\n\n",*n);
    for (i = 0; i<*n; i++)
    {
        Escreve_Info(tab[i]);
    }
}
}
/*Fim Função Escreve_Espaços 5*/


/*Função que escreve toda informação de um local 6*/
void Escreve_Info(local x)
{
    int i;
    printf(" Id     : %d\n", x.id);
    printf(" Capacidade   : %d\n", x.capacidade);
    for (i = 0; i < 3; i++)
    {
        printf(" Ligacoes  : %d\n",x.liga[i]);
    }
    puts("\n");
}
/*Fim Função Escreve_Info 6*/


/*Função que Conta a capacidade total dos locais 7*/
int Capac_Total(plocais lc,int cl)
{
    plocais aux;
    int i,tot=0;
    aux=lc;
    for(i=0; i<cl; i++)
    {
        tot+=aux[i].capacidade;
    }

    return tot;
}
/*Fim Função Capac_Total 7*/

/*Função que cria a lista ligada das salas 8*/
salas *Cria_Salas(local *lcc, int *cd, int cl)
{

    psalas novo,aux=NULL,aux1;
    int i;

    if(lcc == NULL)
    {
        printf("   ******  Falta escolher Espacos e Populacao opcao '1'  ******\7\n\n");
        return aux;
    }


    for(i=0; i<cl; i++)
    {
        novo=malloc(sizeof(salas));
        if(novo==NULL)
        {
            return NULL;
        }
        novo->idd = i;
        novo->ctp = 0;
        novo->sick = 0;
        novo->sal = 0;
        novo->imu = 0;
        novo->lc = lcc[i];
        novo->lista=NULL;
        novo->next=NULL;

        if(aux==NULL)
        {

            aux = novo;

        }
        else
        {
            aux1 = aux;
            while(aux1->next != NULL)
                aux1=aux1->next;
            aux1->next = novo;
        }
        *cd+=1;
    }
    printf("  ******  Foram Preparados %d Salas  ******\n\n",*cd);

    return aux;
}
/*Fim da função Cria_Salas 8*/


/*Função que faz a Distribuicão das pessoas pelos locais  9*/
salas *Distribuicao(psalas sl, plocais lcc,ppessoas  p, int cd, int cp, int captot, int *flag)
{
    psalas aux;
    ppeople novo;

    int aleat;
    int i=0;
    int cap=0;
    char d = 'D';
    char sa = 'S';
    char imu = 'I';

    if(sl==NULL)
    {
        printf("  ******  Falta Preparacao dos Espacos opcao '4'  ******\7\n\n");
        return sl;
    }

    do
    {
        if(captot == cap)
        {
            printf("      ******  Foram distribuidas %d pessoas por %d salas  ******\n\n",cap,cd);
            aux = sl;
            *flag +=1;
            return aux;
        }
        aux = sl;
        aleat=intUniformRnd(1,cd);
        while(aux != NULL && aux->idd !=aleat-1)
        {
            aux = aux->next;
        }
        if(aux->ctp < aux->lc.capacidade )
        {

            novo = malloc(sizeof(people));
            if(novo == NULL)
            {
                printf(" ***  Erro de alocacao novo people  ***\n");
            }
            strcpy(novo->nome, p->nome);
            novo->idade = p->idade;
            novo->estado = p->estado;
            if(novo->estado == d)
            {
                aux->sick+=1;
            }
            else if(novo->estado == sa)
            {
                aux->sal+=1;
            }
            else if(novo->estado == imu)
            {
                aux->imu+=1;
            }
            novo->dias = p->dias;
            novo->prox = aux->lista;
            aux->lista = novo;
            aux->ctp++;
            p++;
            i++;
            cap++;
        }
    }
    while(i<cp);
    aux = sl;
    *flag +=1;
    printf("        ******  Foram distribuidas %d pessoas por %d salas  ******\n\n",cp,cd);
    return aux;
}
/*FIM da funçao Distribuição 9*/

/*Função que mostra no ecrã a distribuição de pessoas pelos locais 10*/
void Escreve_Distri(psalas p)
{
    ppeople aux;

    while(p != NULL)
    {
        printf("  idd: %d\t local: %d\t n pessoas: %d\t capacidade: %d\t  doentes : %d\t  saudaveis : %d\t  imunes : %d\n",p->idd, p->lc.id, p->ctp,p->lc.capacidade,p->sick,p->sal,p->imu);
        aux = p->lista;
        while(aux != NULL)
        {
            printf("  %s %d %c %d\n",aux->nome,aux->idade,aux->estado,aux->dias);
            aux = aux->prox;
        }
        p = p->next;
        printf("\n");
    }
}
/*FIM da função Escreve_Distri 10*/


/*Função que atualiza dias do doente 11*/
psalas Atualiza_Dias(psalas ps)
{
    int recupera;
    psalas p;
    p = ps;
    ppeople aux;

    while(p != NULL)
    {
        aux = p->lista;

        while(aux != NULL)
        {
            if(aux->estado == 'D')
            {
                aux->dias +=1;
                recupera = aux->idade;
                if((aux->dias > (recupera / 10)+4))
                {
                    aux->estado = 'S';
                    aux->dias = 0;
                    if(p->sick == 0)
                    {
                        p->sal++;
                    }
                    else if(p->sick > 0)
                    {
                        p->sick--;
                        p->sal++;
                    }
                }
                recupera = 1/recupera;
                if((probEvento(recupera)) == 1)
                {
                    aux->estado = 'S';
                    aux->dias = 0;
                    if(p->sick == 0)
                    {
                        p->sal++;
                    }
                    else if(p->sick > 0)
                    {
                        p->sick--;
                        p->sal++;
                    }
                }
                if((probEvento(TXI)) == 1)
                {
                    aux->estado = 'I';
                    aux->dias = 0;
                    if(p->sick == 0)
                    {
                        p->imu++;
                    }
                    else if(p->sick > 0)
                    {
                        p->sick--;
                        p->imu++;
                    }
                }
            }

            aux = aux->prox;
        }
        p = p->next;

    }
    return ps;
}
/*FIM da função atualiza_Dias 11*/


/*Funcao que faz interacões 12*/
psalas Interact(psalas ps)
{
    psalas p;
    p = ps;
    ppeople aux;
    int tx=0;
    int infec=0;
    int cti = 0;

    p = Atualiza_Dias(p);

    while(p != NULL)
    {
        tx = Taxa_Diss(p->ctp,TX);
        infec = (p->sick * tx);
        aux = p->lista;

        while(aux != NULL && infec > 0)
        {
            if(aux->estado == 'S')
            {
                aux->estado = 'D';
                aux->dias +=1;
                p->sick++;
                p->sal--;
                infec-=1;
            }

            aux = aux->prox;
        }
        p = p->next;

    }
    cti++;

    Escreve_Distri(ps);
    return ps;
}
/*FIM da função Interact 12*/


/*Funcao que calcula a taxa de disemminaçao 13*/
int Taxa_Diss(int pop, float tx)
{
    int res = 0;
    res = pop*tx;
    if (res < 1)
    {
        res = 1;
    }
    return res;
}
/*Fim da funcao Taxa_Dis 13*/

/*Função que guarda as interacoes em ficheiro 14*/
void Guarda_Interacao(psalas pp, char *nomeF,int ctd)
{
    FILE *f;
    int total;
    psalas p;
    p=pp;
    ppeople aux;

    f = fopen(nomeF, "wb");
    if(f == NULL) return;

    total = ctd;
    fwrite(&total, sizeof(int), 1, f);
    while(p != NULL)
    {
        fwrite(p, sizeof(salas), 1, f);
        aux = p->lista;
        while(aux != NULL)
        {
            fwrite(aux->nome, sizeof(char), 100, f);
            fwrite(&aux->idade, sizeof(int), 1, f);
            fwrite(&aux->estado, sizeof(char), 1, f);
            fwrite(&aux->dias, sizeof(int), 1, f);
            aux = aux->prox;
        }
        p = p->next;
    }
    fclose(f);
}
/*FIM da função Guarda_Interacao 14*/


/*Funcão que recupera as interações do ficheiro 15*/
psalas Recupera_Inter(char *nomeF)
{
    FILE *f;
    psalas p = NULL, novaL;
    int total, i, j;
    ppeople novoP;

    f = fopen(nomeF, "rb");
    if(f == NULL)
    {
        printf("   *** Ficheiro nao Encontrado ***\n");
        return p;
    }
    fread(&total, sizeof(int), 1, f);
    for(i=0; i<total; i++)
    {
        novaL = malloc(sizeof(salas));
        if(novaL == NULL)
        {
            fclose(f);
            printf("ERRO");
            return NULL;
        }
        fread(novaL, sizeof(salas), 1, f);
        novaL->next = NULL;
        novaL->lista = NULL;
        p = insereFinalL(p, novaL);
        for(j=0; j<novaL->ctp; j++)
        {
            novoP = malloc(sizeof(people));
            if(novoP == NULL)
            {
                fclose(f);
                return NULL;
            }
            novoP->prox = NULL;
            fread(novoP->nome, sizeof(char), 100, f);
            fread(&novoP->idade, sizeof(int), 1, f);
            fread(&novoP->estado, sizeof(char), 1, f);
            fread(&novoP->dias, sizeof(int), 1, f);

            novaL->lista = insereFinalP(novaL->lista, novoP);

        }
    }
    fclose(f);
    Escreve_Distri(p);
    return p;
}
/*FIM da função Recupera_Inter 15*/

/*Funcão que insere uma struct salas no fim da lista 16*/
psalas insereFinalL(psalas p, psalas nova)
{
    psalas aux;

    if(p==NULL)
        p = nova;
    else
    {
        aux = p;
        while(aux->next != NULL)
            aux = aux->next;
        aux->next = nova;
    }
    return p;
}
/*FIM da função insereFinalL 16*/

/*Funcão que insere uma struct people no fim da lista 17*/
ppeople insereFinalP(ppeople p, ppeople novo)
{
    ppeople aux;

    if(p==NULL)
        p = novo;
    else
    {
        aux = p;
        while(aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novo;
    }
    return p;
}
/*FIM da função insereFinalP 17*/

/*Funcão cria os nomes dos ficheiros 18*/
void Cria_Fich(char *res, int inter)
{
    char ch[]= "interact";
    char c[]= "@";
    char fixo[]=".dat";
    c[0]+=inter;

    strcat(ch,c);
    strcat(ch,fixo);
    strcpy(res,ch);

}
/*FIM da função Cria_Fich 18*/

/*Funcão que adiciona doentes as sala escolhida 19*/
psalas Adiciona_Doente(psalas ps)
{

    psalas p;
    p = ps;
    ppeople novoD;
    int idtemp;
    do
    {
        printf("  Digite o Id do local a adicionar o doente : \n");
        scanf("%d",&idtemp);
    }
    while((Verifica_Idsala(ps,idtemp)) == 0);

    while(p != NULL || p->lc.id != idtemp)
    {

        if(p->lc.id == idtemp)
        {

            if(p->ctp == p->lc.capacidade)
            {
                printf("  *** Nao e Possivel Adicionar Doente na Sala %d  ***\n",p->lc.id);
                printf("  *** CAPACIDADE COMPLETA ***\n\n");
                return ps;
            }

            novoD = malloc(sizeof(people));
            if(novoD == NULL)
            {
                return ps;
            }
            printf("Digite o nome : \n");
            scanf(" %s",novoD->nome);
            printf("Digite a idade : \n");
            scanf("%d",&novoD->idade);
            printf("Digite a dias que esta doente : \n");
            scanf("%d",&novoD->dias);
            novoD->estado = 'D';
            novoD->prox = p->lista;
            p->lista = novoD;
            p->ctp+=1;
            p->sick++;
            Escreve_Distri(ps);
            return ps;
        }

        p = p->next;
    }
    printf("\n");
    Escreve_Distri(ps);
    return ps;
}
/*FIM da função Adiciona_Doente 19*/


/*Funcao principal para a mudar pessoas de sala 20*/
psalas Muda_Pessoas(psalas ps)
{

    psalas p;
    int ido,idd,np,liga,i;
    p = ps;

    do
    {
        printf(" *** Digite o lugar de origem : "),
               scanf("%d",&ido);
    }
    while((Verifica_Idsala(p,ido)) == 0);

    do
    {
        printf(" *** Digite o lugar de destino : "),
               scanf("%d",&idd);
    }
    while(idd == ido || (Verifica_Idsala(p,idd)) == 0);

    liga = Verifica_Liga(p,ido,idd);
    if(liga == 0)
    {
        return p;
    }
    do
    {
        printf(" *** Digite o numero de pessoas : ");
        scanf("%d",&np);
    }
    while(Verifica_CapacO(p,ido,np)== 0 || Verifica_CapacD(p,idd,np) == 0 );

    for(i=0; i<np; i++)
    {
        p = Move_Pessoas(p,ido,idd);
    }
    printf("\n");
    return p;

}
/*Fim da funcao Muda_Pessoas 20*/

/*Funcão verifica se o Id da sala existe 21*/
int Verifica_Idsala(psalas p, int ido)
{

    psalas aux;
    aux = p;

    while(aux != NULL)
    {
        if(aux->lc.id == ido)
        {
            return 1;
        }
        aux = aux->next;
    }
    printf(" *** Local nao encontrado  ***\n\n");
    return 0;
}/*Fim da funcao Verifica_sala 21*/

/*Funcao que verifica se as ligacoes dos locais escolhidos correspondem 22*/
int Verifica_Liga(psalas p,int ido, int idd)
{

    psalas aux;
    aux = p;

    while(aux != NULL)
    {
        if(aux->lc.id == ido)
        {
            if(aux->lc.liga[0] == idd || aux->lc.liga[1] == idd || aux->lc.liga[2] == idd)
            {
                return 1;
            }
            printf(" *** Nao Existem Ligacoes do Local %d para o Local %d  ***\n\n",ido,idd);
            return 0;
        }
        aux = aux->next;
    }

    return 0;

}
/*Fim da funcao Verifica_Liga 22*/

/*Funcao que verifica a capacidade do local de origem 23*/
int Verifica_CapacO(psalas p,int ido,int npm)
{

    psalas aux;
    aux = p;

    while(aux != NULL)
    {
        if(aux->lc.id == ido)
        {
            if(npm <= aux->ctp)
            {
                return 1;
            }
            printf(" *** Nao Existem %d Pessoas no Local %d ***\n",npm,aux->lc.id);
            printf("       *** Digite '0' pra sair  ***\n\n");
            return 0;
        }
        aux = aux->next;
    }

    return 0;
}
/*Fim funcao Verifica_CapacD 23*/

/*Funcao que verifica a capacidade do local de destino 24*/
int Verifica_CapacD(psalas p,int idd,int npm)
{

    psalas aux;
    aux = p;

    while(aux != NULL)
    {
        if(aux->lc.id == idd)
        {
            if(npm <= ((aux->lc.capacidade) -  (aux->ctp)))
            {
                return 1;
            }
            printf(" *** Nao Local %d Nao Tem Capacidade para Mais %d Pessoas ***\n",aux->lc.id,npm);
            printf("       *** Digite '0' pra sair  ***\n\n");
            return 0;
        }
        aux = aux->next;
    }

    return 0;
}
/*Fim funcao Verifica_CapacD 24*/

/*Funcao que faz a mudanca de pessoas de sala 25*/
psalas Move_Pessoas(psalas p,int ido,int idd)
{


    psalas aux,auxs1,auxs2;
    ppeople aux1=NULL;
    aux = p;

    while(aux != NULL)
    {
        if(aux->lc.id == ido)
        {
            auxs1 = aux;
        }
        if(aux->lc.id == idd)
        {
            auxs2 = aux;
        }
        aux = aux->next;
    }

    aux1 = auxs1->lista;
    auxs1->lista = auxs1->lista->prox;
    aux1->prox = auxs2->lista;
    auxs2->lista = aux1;
    auxs1->ctp-=1;
    auxs2->ctp+=1;
    if(aux1->estado == 'D')
    {
        auxs1->sick-=1;
        auxs2->sick+=1;
    }
    else if(aux1->estado == 'S')
    {
        auxs1->sal-=1;
        auxs2->sal+=1;
    }
    else if(aux1->estado == 'I')
    {
        auxs1->imu-=1;
        auxs2->imu+=1;
    }



    return p;

}
/*Fim da funcao Move_Pessoas 25 */
void Doente_maisnovo(psalas p){
psalas pp;
ppeople aux, aux2;
int idade=100;

    while(p != NULL)
    {
        aux = p->lista;

        while(aux != NULL)
        {
            if(aux->estado == 'D'){
              if(aux->idade < idade){
                aux2 = aux;
                pp = p;
                idade = aux->idade;
              }
        }
            aux = aux->prox;
        }
        p = p->next;
    }
    printf(" O Doente mais novo e: %s  idade: %d  dias : %d  esta na sala %d\n\n",aux2->nome,aux2->idade,aux2->dias,pp->lc.id);

}

/*Funcao Principal para calcular estatisticas das interacoes 26*/
/*Criacao da struct stat que armazena estatisticas */
pstat Calcula_Estat(psalas ps)
{

    pstat estat=NULL,estaux;
    psalas p;
    int id,tp,dt,sal=0,imu=0;
    p = ps;
    while(p != NULL)
    {
        id = p->lc.id;
        tp = p->ctp;
        dt = p->sick;
        sal = p->sal;
        imu = p->imu;
        estaux = Novo_Estat(id,tp,dt,sal,imu);
        id=tp=dt=sal=imu=0;
        estat = insereFinalE(estat, estaux);
        p = p->next;

    }
    return estat;
}
/*Fim da funcao Calcula_Estat 26*/

/*Cria e preenche uma nova struct stat 27*/
pstat Novo_Estat(int id,int np,int dt,int sal,int imu)
{
    pstat novo;
    novo = malloc(sizeof(stat));

    novo->id = id;
    novo->np = np;
    novo->dt = Calculo_Aux(dt,np);
    novo->sal = Calculo_Aux(sal,np);
    novo->imu = Calculo_Aux(imu,np);
    novo->next = NULL;

    return novo;
}
/*Fim da funcao Novo_Estat 27*/

/*Funcao Que calcula as estatisticas 28*/
int Calculo_Aux(int est,int np)
{
    int res=0;

    res = (est * EST)/np;

    return res;
}
/*Fim da funcao Calculo_Aux 28*/

/*Funcao que adiciona a nova Struct stat no fim da lista 29*/
pstat insereFinalE(pstat p, pstat nova)
{
    pstat aux;

    if(p==NULL)
        p = nova;
    else
    {
        aux = p;
        while(aux->next != NULL)
            aux = aux->next;
        aux->next = nova;
    }
    return p;
}
/*Fim da funcao insereFinaE 29*/

/*Funcao que mostra no ecra as estatisticas das interacoes 30*/
void Mostra_Estat(pstat p)
{
    while(p != NULL)
    {
        printf(" *** Estatistica do Local : %d  Numero de Pessoas : %d  Doentes : %d%%  Saudaveis : %d%%  Imunes : %d%%  ***\n\n",p->id,p->np,p->dt,p->sal,p->imu);
        p = p->next;
    }
    printf("\n");
}
/*Fim da funcao Mostra_Estat 30*/

/*Funcao que Guarda a ultima interacao em um ficheiro escolhido pelo utilizador 31*/
void Guarda_EstadoFim(psalas pp, char *nomeF,int ctd)
{
    FILE *f;
    psalas p;
    p=pp;
    ppeople aux;

    f = fopen(nomeF, "w");
    if(f == NULL) return;

    fprintf(f,"  **** Relatorio da Ultima Interaçao ****\n");
    fprintf(f,"  Interacao  %d\n",ctd);
    while(p != NULL)
    {
        fprintf(f,"  idd: %d\t local: %d\t ctp: %d\t capacidade: %d\t  doentes : %d\t  saudaveis : %d\t  imunes : %d\t\n",p->idd, p->lc.id, p->ctp,p->lc.capacidade,p->sick,p->sal,p->imu);
        aux = p->lista;
        while(aux != NULL)
        {
            fprintf(f,"   %s %d %c %d\n",aux->nome,aux->idade,aux->estado,aux->dias);
            aux = aux->prox;
        }
        p = p->next;
    }
    fclose(f);
    printf("   **** Relatorio da Situacao Atual Gravado com Sucesso  ***\n\n");
}
/*Fim da funca o Guarda_EstadoFim 31*/

/*Funcao que guarda toda informacao necessaria em um ficheiro de texto 32*/
void Guarda_Tudo(psalas pp, char *nomeF,int ctd,pstat st)
{
    FILE *f;
    psalas p;
    pstat sta;
    p=pp;
    sta=st;
    ppeople aux;

    f = fopen(nomeF, "w");
    if(f == NULL)
    {
        return;
    }
    fprintf(f,"                          **** Relatorio Final ****\n\n");
    fprintf(f,"                         **** Numero Interacoes : %d  ****\n\n",ctd);
    fprintf(f,"                        **** Estado da Ultima Interacao ****\n\n");
    while(p != NULL && sta != NULL)
    {
        fprintf(f,"  *** Estatistica do Local : %d  Numero de Pessoas : %d  Doentes : %d%%  Saudaveis : %d%%  Imunes : %d%%  ***\n\n",sta->id,sta->np,sta->dt,sta->sal,sta->imu);
        fprintf(f, "  idd: %d\t local: %d\t ctp: %d\t capacidade: %d\t  doentes : %d\t  saudaveis : %d\t  imunes : %d\t\n",p->idd, p->lc.id, p->ctp,p->lc.capacidade,p->sick,p->sal,p->imu);
        aux = p->lista;
        while(aux != NULL)
        {
            fprintf(f,"  %s %d %c %d\n",aux->nome,aux->idade,aux->estado,aux->dias);
            aux = aux->prox;
        }
        fprintf(f,"\n");
        p = p->next;
        sta = sta->next;
    }


    fclose(f);
    printf("      **** Relatorio Final Gravado com Sucesso  ***\n");
}
/*Fim da funca Guarda_Tudo 32*/


/*Função que liberta a memoria alocada pelas listas 33*/
void Liberta_Lista(salas *p)
{
    salas *aux;
    while(p != NULL)
    {
        aux = p;
        p = p->next;
        free(aux);
    }
}
/*Fim da função Liberta_Listas 33*/
