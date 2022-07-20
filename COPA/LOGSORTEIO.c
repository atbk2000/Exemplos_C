#include"LOGSORTEIO.h"
#include"STRUCTS.h"
#include"SORTEIO.h"
#include"MENU.h"


void gotoxy(int x,int y)
{
    static HANDLE h = NULL;
    if(!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { x,y };
    SetConsoleCursorPosition(h,c);

}

void probabilidade(int n, char**s,pote *p)
{
    FILE*fp3=fopen("cadastro.txt","r");
    rewind(fp3);
    p=organizaPote(fp3);
    int i=0,j,r;
    grupo *g=(grupo*)calloc(8,sizeof(grupo));
    float c1=0.0;
    float contador=0.0;
    gotoxy(45,1);
    printf("Calculando...");
    gotoxy(41,8);
    printf("Aguenta o suspense!!!!");
    gotoxy(38,4);
    printf("|");
    gotoxy(64,4);
    printf("|");
    gotoxy(39,4);

        while(contador!=500000)
        {
            free(g);
            g=(grupo*)calloc(8,sizeof(grupo));
            while(sortear(p,g))
            {
                for(i=0; i<8; i++)
                {
                    for(j=0; j<4; j++)
                    {
                        g[i].a[j].ranking=0;
                        strcpy(g[i].a[j].confederacao,"!!!!");
                    }
                }
            };

            for(i=0; i<8; i++)
            {
                if( n == 2)
                {
                    if(verificaPais(g,s[0],i)==1&&verificaPais(g,s[1],i)==1)
                    {
                        c1++;
                    }
                }
                if( n == 3)
                {
                    if(verificaPais(g,s[0],i)==1&&verificaPais(g,s[1],i)==1&&verificaPais(g,s[2],i)==1)
                    {
                        c1++;
                    }
                }
                if( n == 4)
                {
                    if(verificaPais(g,s[0],i)==1&&verificaPais(g,s[1],i)==1&&verificaPais(g,s[2],i)==1&&verificaPais(g,s[3],i)==1)
                    {
                        c1++;
                    }
                }

            }


            contador++;
            r = contador;
            if(r%20000==0){
                printf("*");
            }
        }

    system("cls");
    printf("\n");
    setlocale(LC_ALL,"Portuguese");
    printf(" Porcentagem: %.4f \n", 100*(c1/contador));
    fflush(stdin);
    char c;
    do
    {
        printf(" \n Sair(S): ");
        scanf(" %c", &c);
    }
    while(toupper(c)!='S');
    system("cls");
    menu();
    do
    {
        printf(" \n Sair(S): ");
        scanf(" %c", &c);
    }
    while(toupper(c)!='S');
    system("cls");
    menu();
}



int verificaPais(grupo *g,char s[],int n)
{
    int i;
    for(i=0; i<4; i++)
    {
        if(strncmp(g[n].a[i].nome,s,strlen(s))==0)
        {
            return 1;
        }
    }
    return 0;
}



void temporeal(FILE *fp4,pote *p)
{
    fp4 = fopen("log.txt","r+");
    char c;
    char *w;
    int grupo,posicao,tamanho,i,ordem;
    char s[8];
    int j,k,n=0;
    for(i=0; i<8; i++)
    {
        s[i] = 'A' + i;
    }
    for(i=0;i<4;i++){
            for(j=0;j<4;j++){
    gotoxy(3+30*i,19+j);
    printf("%d)", j+1);
            }
    }
    for(i=0;i<4;i++){
            for(j=0;j<4;j++){
    gotoxy(3+30*i,28+j);
    printf("%d)", j+1);
            }
    }
    for(k=0;k<4;k++){
    for(i=0;i<5;i++){
        gotoxy(2+30*k,18+i);
        printf("|");
        gotoxy(21+30*k,18+i);
        printf("|");
    }
    }
    for(k=0;k<4;k++){
    for(i=0;i<5;i++){
        gotoxy(2+30*k,27+i);
        printf("|");
        gotoxy(21+30*k,27+i);
        printf("|");
    }
    }
    for(k=0;k<4;k++){
    for(i=0;i<18;i++){
        gotoxy(3+i+30*k,17);
        printf("-");
        gotoxy(3+i+30*k,23);
        printf("-");

    }
    }

    for(k=0;k<4;k++){
    for(i=0;i<18;i++){
        gotoxy(3+i+30*k,26);
        printf("-");
        gotoxy(3+i+30*k,32);
        printf("-");

    }
    }
    for(i=0; i<4; i++)
    {
        gotoxy(3+30*i,18);
        printf("GRUPO %c",s[i]);
    }
    for(i=0; i<4; i++)
    {
        gotoxy(3+30*i,27);
        printf("GRUPO %c",s[i+4]);
    }
    setlocale(LC_ALL,"C");
    for(k=0;k<4;k++){
    for(i=0;i<14;i++){
        gotoxy(3+i+30*k,2);
        printf("-");
        gotoxy(3+i+30*k,14);
        printf("-");
    }
    for(i=0;i<11;i++){
        gotoxy(2+30*k,3+i);
        printf("|");
        gotoxy(17+30*k,3+i);
        printf("|");
    }

        gotoxy(7+30*k,3);
        printf("POTE %d", k+1);

    }
    for(i=0; i<4; i++)
    {
        for(j=0; j<8; j++)
        {
            gotoxy(3+30*i,5+j);
            for(k=0; p[i].a[j].nome[k]!='\0'; k++)
            {
                if( p[i].a[j].nome[k] == '_')
                {
                    p[i].a[j].nome[k] = ' ';
                }
            }

            printf("%s",p[i].a[j].nome);
        }
    }

    ordenaarquivo(fp4);
    rewind(fp4);
    while(n<32)
    {
        c = fgetc(fp4);
        if( c == '\n'){
             n++;
        }
        tamanho = 0;
        if( c == '*')
        {
            c = fgetc(fp4);
            tamanho++;
            while( c!= '*')
            {
                tamanho++;
                c = fgetc(fp4);
            }
            w = (char*)calloc(tamanho+1,sizeof(char));
            fseek(fp4,-tamanho,SEEK_CUR);
            c = fgetc(fp4);
            tamanho = 0;
            while( c!= '*')
            {
                if( c == '_')
                {
                    c = ' ';
                }
                w[tamanho] = c;
                tamanho++;
                c = fgetc(fp4);
            }
            w[tamanho] = '\0';
            c = fgetc(fp4);
            while( c!= '*')
            {
                c = fgetc(fp4);
            }
            c = fgetc(fp4);
            grupo = c - 48;
            c = fgetc(fp4);
            c = fgetc(fp4);
            while( c!= '*')
            {
                c = fgetc(fp4);
            }
            c = fgetc(fp4);
            posicao = c - 48;
            getch();
            printa(grupo,posicao,w,p);
            free(w);
            c = fgetc(fp4);
        }
    }
    fclose(fp4);

}

void printa(int grupo,int posicao,char *nome,pote *p)
{
    int i,j,k;
    setlocale(LC_ALL,"C");
    for(i=0; i<4; i++)
    {
        for(j=0; j<8; j++)
        {
            gotoxy(3+30*i,5+j);
            for(k=0; p[i].a[j].nome[k]!='\0'; k++)
            {
                if( p[i].a[j].nome[k] == '_')
                {
                    p[i].a[j].nome[k] = ' ';
                }
            }
            if(strcmp(nome,p[i].a[j].nome)==0){
                for(k=0;k<strlen(p[i].a[j].nome);k++){
                    p[i].a[j].nome[k] = ' ';
                }
            }
            printf("%s",p[i].a[j].nome);
        }
    }

    if(grupo<5)
    {
        gotoxy(5+30*(grupo-1),18+posicao);
        printf("%s",nome);
    }
    if(grupo>=5)
    {
        gotoxy(5+30*(grupo-5),27+posicao);
        printf("%s",nome);
    }

}

void ordenaarquivo(FILE *fp4){
    ordena a[32];
    ordena aux;
    int n = 0,i,j;
    char c;
    while(n<32)
    {
        c = fgetc(fp4);
        if( c == '\n'){
             n++;
        }
        if( c == '*')
        {
            a[n].pote = 1;
            c = fgetc(fp4);
            while( c!= '*')
            {
                i = 0;
                for(c=c;c!='*';c=fgetc(fp4)){
                    a[n].nome[i] = c;
                    i++;
                }
            }
            a[n].nome[i] = '\0';
            c = fgetc(fp4);

            while( c!= '*')
            {
                c = fgetc(fp4);
            }
            c = fgetc(fp4);
            a[n].grupo = c - 48;
            c = fgetc(fp4);
            c = fgetc(fp4);
            while( c!= '*')
            {
                c = fgetc(fp4);
            }
            c = fgetc(fp4);
            a[n].posicao = c - 48;
            if( n > 7){
                while( c!= '|'){
                    c = fgetc(fp4);
                }
                c = fgetc(fp4);
                a[n].ordem = c;

            c = fgetc(fp4);
            c = fgetc(fp4);
            while( c!= '*'){
                c = fgetc(fp4);
            }
            c = fgetc(fp4);
            a[n].pote = c;
            c = fgetc(fp4);
            c = fgetc(fp4);
            }
            c = fgetc(fp4);
            c = fgetc(fp4);
        }
    }
    for(n=0;n<32;n++){
             for(j=n;j<32;j++){
                if( (a[j].pote > 1 && a[j].pote == a[n].pote) && a[j].ordem < a[n].ordem){
                    aux = a[j];
                    a[j] = a[n];
                    a[n] = aux;
                }
             }
    }
    rewind(fp4);
    setlocale(LC_ALL,"Portuguese");
    for(n=0;n<32;n++){
        fprintf(fp4, " %d  =>  Nome  =>  *%s*  Grupo  =>  *%d*  Pos.  =>  *%d*   \n", n+1,a[n].nome,a[n].grupo,a[n].posicao);
    }


}
