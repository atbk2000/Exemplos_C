#include"MENU.h"
#include"STRUCTS.h"
#include"SORTEIO.h"
#include"LOGSORTEIO.h"

void retirar(char *s)
{
    int i;
    for(i = 0; s[i]!='\n'; i++) {}
    s[i] = '\0';
}

void menu()
{
    FILE *fp1 = fopen("instrucoes","r");
    FILE *fp3 = fopen("cadastro.txt","r");
    FILE *fp4;
    grupo *g = (grupo *)calloc(8,sizeof(grupo));
    char **s,c;
    int i,n,j;
    char b;
    pote *p;
    setlocale(LC_ALL,"Portuguese");
    printf("\n\tSORTEIO DA COPA DO MUNDO DE FUTEBOL 2018\n");
    printf("\n\t1) INSTRUÇÕES\n\t2) CADASTRAR CLASSIFICADOS\n\t3) SORTEAR GRUPOS\n");
    printf("\t4) LOG DO SORTEIO\n\t5) QUAL A PROBABILIDADE?\n\t6) SAIR\n");
    printf("\n\t=> ESCOLHA UMA OPÇÃO: ");
    do
    {
        do
        {
            fflush(stdin);
            scanf("%d", &i);
            if(i<1 || i>6)
            {

                printf("\n Digite novamente, número invalido:  ");
            }
        }
        while(i<1 || i>6);
        switch(i)

        {
        case 1:

            instrucoes(fp1);

            break;

        case 2:
            system("cls");
            printf("\n Caso sim, cadastre os 32 países, ininterruptamente\n");
            do
            {
                printf("\n Tem certeza que deseja cadastrar(S/N)?: ");
                fflush(stdin);
                scanf(" %c", &c);
            }
            while(toupper(c)!='N' && toupper(c)!='S');
            if( toupper(c) == 'S')
            {
                cadastrar();
            }
            if( toupper(c) == 'N')
            {
                system("cls");
                menu();
            }
            break;

        case 3:
        	p = organizaPote(fp3);
         	while(sortear1(p,g)==1){

                for(i=0;i<8;i++){
            	for(j=0;j<4;j++){
                	g[i].a[j].ranking = 0;
                	strcpy(g[i].a[j].confederacao,"!!!!");
            	}
         	}
         	}

         	temporeal(fp4,p);
         	gotoxy(3,37);
         	do{
            printf(" \n Sair(S): ");
            scanf(" %c", &c);
            fflush(stdin);
         	}while(toupper(c)!='S');
        	system("cls");
         	menu();
        	break;



        case 4:

            fp4 = fopen("log.txt","r");
            system("cls");
            i = 1;
            c = 'a';
            printf("\n");
            setlocale(LC_ALL,"C");
            while( !feof(fp4) ){
            c = fgetc(fp4);
            if( !feof(fp4)){
                if( c == '_'){
                  c = ' ';
                }
                if( c == '\n'){
                    i++;
                    printf("\n");
                }
                if( i <= 32 && c!='*'){

                printf("%c", c);

                }
            }
            }
            fclose(fp4);
            gotoxy(0,68);
            do{
            printf(" Sair(S): ");
            fflush(stdin);
            scanf(" %c", &c);
         	}while(toupper(c)!='S');
        	system("cls");
         	menu();

            break;

        case 5:
            setlocale(LC_ALL,"Portuguese");
            system("cls");
            printf("\n QUANTOS TIMES PRETENDE AVALIAR: ");
            scanf("%d", &n);
            while(n<=1 || n>4)
            {
                printf(" NÚMERO INVÁLIDO: ");
                fflush(stdin);
                scanf("%d", &n);
            }
            s = (char **)calloc(n,sizeof(char *));
            for(i=0; i<n; i++)
            {
                s[i] = (char *)calloc(20,sizeof(char ));
            }
            for(i=0; i<n; i++)
            {
                fflush(stdin);
                printf(" NOME DO PAÍS: ");
                fgets(s[i],20,stdin);
            }
            for(i=0; i<n; i++)
            {
                retirar(s[i]);
                for(j=0;s[i][j]!='\0';j++){
                    if( s[i][j] == ' '){
                        s[i][j] = '_';
                    }
                }
            }


            probabilidade(n,s,p);
            free(s);
            for(i=0;i<n;i++){
                free(s[i]);
            }

            break;

        case 6:
            fclose(fp3);
            fclose(fp1);
            do
            {
                printf("\n DESEJA REALMENTE SAIR(S/N)?: ");
                fflush(stdin);
                scanf(" %c", &b);
            }
            while(toupper(b)!='S' && toupper(b)!='N');
            if(toupper(b)=='S')
            {
                exit(1);
            }
            else
            {
                system("cls");
                menu();
            }
        }

    }
    while (i != 6);

}


void instrucoes(FILE *fp1)
{
    char c;
    char ch;
    system("cls");
    rewind(fp1);
    ch = fgetc(fp1);
    while(ch != EOF)
    {
        printf("%c", ch);
        ch = fgetc(fp1);
    }
    do
    {
        printf("\n DESEJA SAIR?(S ou N): ");
        fflush(stdin);
        scanf(" %c", &c);
        if(toupper(c) == 'S')
        {
            fclose(fp1);
            system("cls");
            menu();
        }
        if(toupper(c) == 'N')
        {

            instrucoes(fp1);
        }
    }
    while( toupper(c) != 'N'  || toupper(c)!= 'S');

}

void cadastrar()

{
    FILE *fp3 = fopen("cadastro.txt","w+");
    int c[5] = {UEFA,AFC,CAF,CONCACAF,CONMEBOL};
    char *c1[5] = {"UEFA","AFC","CAF","CONCACAF","CONMEBOL"};
    system("cls");
    pais p[32];
    int i,k,j,l,v=1,r;
    printf("\n PAÍS SEDE: ");
    fflush(stdin);
    char t;
    fgets(p[0].nome,20,stdin);
    retirar(p[0].nome);
    strcat(p[0].nome,".");
    for(k=0; p[0].nome[k]!='.'; k++)
    {
        if(p[0].nome[k]==' ')
        {
            p[0].nome[k]='_';
        }

    }
    do
    {

        printf("\n CONFEDERAÇÃO DO PAÍS SEDE: ");
        fflush(stdin);
        fgets(p[0].confederacao,10,stdin);
        retirar(p[0].confederacao);

        for(k = 0; k < 5; k++)
        {
            r = strcmp(p[0].confederacao,c1[k]);
            if(r == 0)
            {
                c[k]--;
                break;
            }
        }
    }
    while(r != 0);
    do
    {
        printf("\n POSIÇÃO NO RANKING DO PAÍS SEDE: ");
        scanf("%d",&p[0].ranking);
    }
    while( p[0].ranking <=0 || p[0].ranking > 210);
    system("cls");
    printf("\n DIGITE OS PAÍSES DA UEFA: \n");

    for(i=1; i<=c[0]; i++)
    {
        strcpy(p[i].confederacao,"UEFA");
        do
        {
            v = 1;
            printf("\n NOME DO PAÍS: ");
            fflush(stdin);
            fgets(p[i].nome,20,stdin);
            retirar(p[i].nome);
            strcat(p[i].nome,".");
            for(k=0; p[i].nome[k]!='.'; k++)
            {
                if(p[i].nome[k]==' ')
                {
                    p[i].nome[k]='_';
                }

            }
            for(j = 0; j <= i ; j++)
            {
                for(l = j + 1; l <= i ; l++)
                {
                    if(strcmp(p[l].nome,p[j].nome)==0)
                    {
                        v = 0;
                    }
                }
            }
        }
        while( v == 0);
        do
        {
            v = 1;
            printf("\n POSIÇÃO NO RANKING DO PAÍS: ");
            fflush(stdin);
            scanf("%d", &p[i].ranking);
            for(j = 0; j <= i ; j++)
            {
                for(l = j + 1; l <= i ; l++)
                {
                    if(p[l].ranking == p[j].ranking)
                    {
                        v = 0;
                    }
                }

            }
        }
        while( p[i].ranking <= 0 || p[i].ranking > 210 || v == 0);
        system("cls");
    }

    printf("\n DIGITE OS PAÍSES DA AFC: \n");

    for(i=i; i<=c[1] + c[0]; i++)
    {

        strcpy(p[i].confederacao,"AFC");
        do
        {
            v = 1;
            printf("\n NOME DO PAÍS: ");
            fflush(stdin);
            fgets(p[i].nome,20,stdin);
            retirar(p[i].nome);
            strcat(p[i].nome,".");
            for(k=0; p[i].nome[k]!='.'; k++)
            {
                if(p[i].nome[k]==' ')
                {
                    p[i].nome[k]='_';
                }

            }
            for(j = 0; j <= i ; j++)
            {
                for(l = j + 1; l <= i ; l++)
                {
                    if(strcmp(p[l].nome,p[j].nome)==0)
                    {
                        v = 0;
                    }
                }
            }
        }
        while( v == 0);
        do
        {
            v = 1;
            printf("\n POSIÇÃO NO RANKING DO PAÍS: ");
            fflush(stdin);
            scanf("%d", &p[i].ranking);
            for(j = 0; j <= i ; j++)
            {
                for(l = j + 1; l <= i ; l++)
                {
                    if(p[l].ranking == p[j].ranking)
                    {
                        v = 0;
                    }
                }

            }
        }
        while( p[i].ranking <= 0 || p[i].ranking > 210 || v == 0);
        system("cls");
    }

    printf("\n DIGITE OS PAÍSES DA CAF: \n");

    for(i=i; i<=c[2] + c[1] + c[0]; i++)
    {

        strcpy(p[i].confederacao,"CAF");
        do
        {
            v = 1;
            printf("\n NOME DO PAÍS: ");
            fflush(stdin);
            fgets(p[i].nome,20,stdin);
            retirar(p[i].nome);
            strcat(p[i].nome,".");
            for(k=0; p[i].nome[k]!='.'; k++)
            {
                if(p[i].nome[k]==' ')
                {
                    p[i].nome[k]='_';
                }

            }
            for(j = 0; j <= i ; j++)
            {
                for(l = j + 1; l <= i ; l++)
                {
                    if(strcmp(p[l].nome,p[j].nome)==0)
                    {
                        v = 0;
                    }
                }
            }
        }
        while( v == 0);
        do
        {
            v = 1;
            printf("\n POSIÇÃO NO RANKING DO PAÍS: ");
            fflush(stdin);
            scanf("%d", &p[i].ranking);
            for(j = 0; j <= i ; j++)
            {
                for(l = j + 1; l <= i ; l++)
                {
                    if(p[l].ranking == p[j].ranking)
                    {
                        v = 0;
                    }
                }

            }
        }
        while( p[i].ranking <= 0 || p[i].ranking > 210 || v == 0);
        system("cls");
    }

    printf("\n DIGITE OS PAÍSES DA CONCACAF: \n");

    for(i=i; i<=c[3] + c[2] + c[1] + c[0]; i++)
    {

        strcpy(p[i].confederacao,"CONCACAF");
        do
        {
            v = 1;
            printf("\n NOME DO PAÍS: ");
            fflush(stdin);
            fgets(p[i].nome,20,stdin);
            retirar(p[i].nome);
            strcat(p[i].nome,".");
            for(k=0; p[i].nome[k]!='.'; k++)
            {
                if(p[i].nome[k]==' ')
                {
                    p[i].nome[k]='_';
                }

            }
            for(j = 0; j <= i ; j++)
            {
                for(l = j + 1; l <= i ; l++)
                {
                    if(strcmp(p[l].nome,p[j].nome)==0)
                    {
                        v = 0;
                    }
                }
            }
        }
        while( v == 0);
        do
        {
            v = 1;
            printf("\n POSIÇÃO NO RANKING DO PAÍS: ");
            fflush(stdin);
            scanf("%d", &p[i].ranking);
            for(j = 0; j <= i ; j++)
            {
                for(l = j + 1; l <= i ; l++)
                {
                    if(p[l].ranking == p[j].ranking)
                    {
                        v = 0;
                    }
                }

            }
        }
        while( p[i].ranking <= 0 || p[i].ranking > 210 || v == 0);
        system("cls");
    }

    printf("\n DIGITE OS PAÍSES DA CONMEBOL: \n");

    for(i = i; i <= c[4] + c[3] + c[2] + c[1] + c[0]; i++)
    {
        strcpy(p[i].confederacao,"CONMEBOL");
        do
        {
            v = 1;
            printf("\n NOME DO PAÍS: ");
            fflush(stdin);
            fgets(p[i].nome,20,stdin);
            retirar(p[i].nome);
            strcat(p[i].nome,".");
            for(k=0; p[i].nome[k]!='.'; k++)
            {
                if(p[i].nome[k]==' ')
                {
                    p[i].nome[k]='_';
                }

            }
            for(j = 0; j <= i ; j++)
            {
                for(l = j + 1; l <= i ; l++)
                {
                    if(strcmp(p[l].nome,p[j].nome)==0)
                    {
                        v = 0;
                    }
                }
            }
        }
        while( v == 0);
        do
        {
            v = 1;
            printf("\n POSIÇÃO NO RANKING DO PAÍS: ");
            fflush(stdin);
            scanf("%d", &p[i].ranking);
            for(j = 0; j <= i ; j++)
            {
                for(l = j + 1; l <= i ; l++)
                {
                    if(p[l].ranking == p[j].ranking)
                    {
                        v = 0;
                    }
                }

            }
        }
        while( p[i].ranking <= 0 || p[i].ranking > 210 || v == 0);
        system("cls");
    }
    printf("\n PAÍSES CADASTRADOS COM SUCESSO!\n\n ");
    setlocale(LC_ALL,"C");
    for(i = 0; i < 32; i++)
    {

        fprintf(fp3,"%s %s %d \n", p[i].nome, p[i].confederacao, p[i].ranking);
    }

    for(i = 0; i < 32; i++)
    {
        for(k=0; p[i].nome[k]!='.'; k++)
        {
            if(p[i].nome[k]=='_')
            {
                p[i].nome[k]=' ';
            }

        }

        printf(" %s confederação: %s ranking: %d \n ", p[i].nome, p[i].confederacao, p[i].ranking);

    }
    fclose(fp3);
    do{
            printf(" \n\n Sair(S): ");
            scanf(" %c", &t);
         	}while(toupper(t)!='S');
        	system("cls");
         	menu();
}

