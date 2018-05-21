/*
João Vitor Souza Leite 160038
Kennedy Corrêa         160080
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct endereco{
    char logradouro[80];
    char bairro[20];
    char CEP[10];
    char cidade[20];
    char estado[20];
    char fone[15];
    char cel[15];
    char email[30];
}endereco;

typedef struct info_casa{
    int num_casa;
    char status_casa;
}info_casa;

typedef struct prop{
    int reg_prop;
    char nome[80];
    char CPF[13];
    struct endereco end_prop;
    int qtde_casa;
    struct info_casa casa[5]; /*Obs.: (p->casa+i)->status_casa*/
}prop;

typedef struct adress{
    char logradouro[80];
    char bairro[20];
    char CEP[10];
    char cidade[20];
}adress;

typedef struct info_loc{
    char sigla;
    int reg_loc;
}inf_loc;

void aloca_endereco(endereco **p, int tam);
void aloca_info_casa(info_casa **p, int tam);
void aloca_prop(prop **p, int tam);
void cad_prop(prop *p, int num_reg);
void consulta_prop();
/*void cad_imovel();
void consulta_imovel();
*/
int main()
{
prop *p_prop=NULL;
int  cont=0,op;

do{
  system("cls");
  printf("\n[1]Cadastro de Proprietario\n[2]Consulta de Proprietarios\n[3]Cadastro de Imoveis\n[4]Consulta de Imoveis\n[5]Sair\nOpcao: ");
  scanf("%i",&op);
  fflush(stdin);
  switch(op)
    {
    case 1: aloca_prop(&p_prop,cont+1);
            cad_prop(p_prop,cont);
            cont++;
    break;

    case 2: consulta_prop(p_prop,cont);
    break;
/*
    case 3: cad_imovel(p_prop,cont,&lista,&clista);
    break;

    case 4: consulta_imovel(p_prop,cont);
    break;
*/
    }
  }while(op!=5);
return 0;
}

void aloca_endereco(endereco **p, int tam)
{
	if((*p=(endereco*)realloc(*p,tam*sizeof(endereco)))==NULL)
		exit(1);
}

void aloca_info_casa(info_casa **p, int tam)
{
	if((*p=(info_casa*)realloc(*p,tam*sizeof(info_casa)))==NULL)
		exit(1);
}

void aloca_prop(prop **p, int tam)
{
	if((*p=(prop*)realloc(*p,tam*sizeof(prop)))==NULL)
	{
		exit(1);
	}
}
void cad_prop(prop *p, int i)
{
    fflush(stdin);
	static int reg = 1;
	p->reg_prop = reg;
	fflush(stdin);
	printf("\nNome:");
	gets(p->nome);
	fflush(stdin);
	printf("\nCPF:");
	gets(p->CPF);
	fflush(stdin);
    printf("Logradouro:");
    gets(p->end_prop.logradouro);
    fflush(stdin);
    printf("Bairro:");
    gets(p->end_prop.bairro);
    fflush(stdin);
    printf("CEP:");
    gets(p->end_prop.CEP);
    fflush(stdin);
    printf("Cidade:");
    gets(p->end_prop.cidade);
    fflush(stdin);
    printf("Estado:");
    gets(p->end_prop.estado);
    fflush(stdin);
    printf("Fone:");
    gets(p->end_prop.fone);
    fflush(stdin);
    printf("Cel:");
    gets(p->end_prop.cel);
    fflush(stdin);
    printf("Email:");
    gets(p->end_prop.email);
    fflush(stdin);
	printf("\nInformacao Casa:");
	gets((p->casa+i)->status_casa);

}

void consulta_prop(prop *p, int tam){

}
/*
void cad_imovel(prop *p, int tam){

}
void consulta_imovel(){

}
*/
