#include"SORTEIO.h"
#include <time.h>
#include"STRUCTS.h"

void sleep(int s)
{
    time_t t1,t2;
    t1=time(NULL);
    t2=time(NULL);
    while((t2-t1)*1000<s)
    {
        t2=time(NULL);
    }
}

pote* organizaPote(FILE *fp3)
{
    system("cls");
    int i=0,j;
    pais t[32];
    pais aux;
    char ch;
    int b;
    rewind(fp3);
    while(!feof(fp3))
    {
        if(!feof(fp3))
        {
            ch = fgetc(fp3);
            for(b = 0; ch != '.'; b++)
            {
                t[i].nome[b] = ch;
                ch = fgetc(fp3);
            }
            t[i].nome[b] = '\0';
            fscanf(fp3," %s %d \n", t[i].confederacao,&t[i].ranking);
            i++;
        }
    }
    for(i=1; i<32; i++)
    {
        for(j=i+1; j<32; j++)
        {
            if(t[i].ranking>t[j].ranking)
            {
                aux=t[i];
                t[i]=t[j];
                t[j]=aux;

            }
        }
    }
    pote* p=(pote*)calloc(4,sizeof(pote));
    strcpy(p[0].nome,"POTE 1");
    strcpy(p[1].nome,"POTE 2");
    strcpy(p[2].nome,"POTE 3");
    strcpy(p[3].nome,"POTE 4");
    i = 1;
    int k = 0,l=1;
    j = 8;
    p[0].a[0] = t[0];
    while( k < 4)
    {
        for(i=i ; i < j; i++)
        {

            p[k].a[l] = t[i];
            l++;

        }
        j+=8;
        k++;
        l=0;
    }
    fclose(fp3);
    return p;
}

int sortear1(pote* p,grupo *g)
{
	int i=0,j;
	int k,c1,n,x=1;
	pais aux;
	int *h=randNum(8);
	FILE *fp4 = fopen("log.txt","r+");
	int r;
    for(i=1;i<4;i++){
    for(j=0;j<8;j++){
            if(h[i]==0)
    	{
        	k=h[i];
        	h[i]=h[0];
        	h[0]=k;
    	}
	}
    	}
	for(i=0; i<8; i++)
	{
    	g[i].nome='A'+i;
	}

	g[0].a[0]=p[0].a[0];
     fprintf(fp4,"  %d  =>  Nome  =>  *%s*  Grupo  =>  *%d*  Posicao  =>  *%d*   \n", x,g[0].a[0].nome,1,1);
	for(i=1; i<8; i++)
	{
    	g[i].a[0]=p[0].a[h[i]];
    	x++;
    	fprintf(fp4,"  %d  =>  Nome  =>  *%s*  Grupo  =>  *%d*  Posicao  =>  *%d*   \n", x,g[i].a[0].nome,i+1,1);
	}
	for(i=1; i<4; i++)
	{
    	for(j=0; j<8; j++)
    	{
        	n = rand() % 8;

        	aux = p[i].a[j];
        	p[i].a[j] = p[i].a[n];
        	p[i].a[n] = aux;
    	}
	}
	free(h);
	h=randNum(8);
	for(i=1; i<4; i++)
	{
    	for(j=0; j<8; j++)
    	{
        	srand(time(NULL));
        	c1=j;
        	r = rand()%3 + 1;
        	if( contatime(g,c1) < i + 1)
        	{

            	while( g[c1].a[r].ranking!=0)
            	{
            	    r = rand()%3 + 1;
            	}
            	g[c1].a[r]=p[i].a[h[j]];
        	}
            g[c1].a[r].ordem = j + 1;
        	int contador = 0,c3;
        	while(verificagrupo(g,c1)==0)
        	{
            	c3=trocatimedegrupo(g,c1,r,contador,p,i);
            	if(c3==0){
                    fclose(fp4);
                	return 1;
            	}
            	contador++;
            	j++;
            	if(j<8){
            	g[c1].a[r] = p[i].a[h[j]];
            	g[c1].a[r].ordem = j + 1;
            	}
        	}
    	}
    	}
        for(i=0;i<8;i++){
        if(contatime(g,i)!=4 || uefatem(g,i)==0){
                fclose(fp4);
                return 1;
}
	}
	for(i=1;i<4;i++){
	   for(j=0;j<8;j++){

            n = rand()%3 + 1;

            aux = g[j].a[n];
            g[j].a[n] = g[j].a[i];
            g[j].a[i] = aux;
	   }
	}
	int maior,menor;
	for(i=0;i<8;i++){
        for(j=1;j<4;j++){
                if(j == 1){
                    menor = g[i].a[j].ranking;
                    maior = g[i].a[j].ranking;
                }
                if( g[i].a[j].ranking < menor){
                    menor = g[i].a[j].ranking;
                }
                if( g[i].a[j].ranking > maior){
                    maior = g[i].a[j].ranking;
                }

            }
            for(j=1;j<4;j++){
                    if( g[i].a[j].ranking == menor ){
                        g[i].a[j].ranking = 2;
                    }
                    if( g[i].a[j].ranking == maior ){
                        g[i].a[j].ranking = 4;
                    }
                    if( g[i].a[j].ranking != 4 && g[i].a[j].ranking != 2 ){
                        g[i].a[j].ranking = 3;
                    }

        }

	}
	for(i=1;i<4;i++){
	   for(j=0;j<8;j++){
       c1 = 1;
       while( g[j].a[c1].ranking != i + 1){
        c1++;
       }
	   x++;
       fprintf(fp4,"  %d  =>  Nome  =>  *%s*  Grupo  =>  *%d*  Posicao  =>  *%d* Ordem  =>  |%d|  POTE =>  *%d*    \n", x,g[j].a[c1].nome,j+1,c1+1,g[j].a[c1].ordem,g[j].a[c1].ranking);
	   }
	}
    fclose(fp4);
    return 0;
}

int trocatimedegrupo( grupo *g, int j, int posicao,int contador,pote *p,int q)
{
    contador++;
    int *r = randNum(3), i; /////////////////////////////////////////////////////////////////
    int c1 = j + contador;
    if( c1==8){
         return 0;
    }
    if( contatime(g,c1) > q){
        trocatimedegrupo(g,j,posicao,contador,p,q);
    }
    else
    {
        for(i=0; i<3; i++)
        {
            if(g[c1].a[r[i]+1].ranking==0)
            {

                g[c1].a[r[i]+1] = g[j].a[posicao];
                g[c1].a[r[i]+1].ordem = c1;
                if( verificagrupo(g,c1)==0)
                {
                    g[c1].a[r[i]+1].ranking = 0;
                    strcpy(g[c1].a[r[i]+1].confederacao,"!!!!");
                    trocatimedegrupo(g,j,posicao,contador,p,q);
                }
                break;
            }
        }

    }

    return 1;

}






int *randNum(int n)
{
    int i,j,k;
    srand(time(NULL));
    int* v=(int*)calloc(n,sizeof(int));
    v[0]=rand()%n;
    do
    {
        for(i=0; i<n; i++)
        {
            for(j=i+1; j<n; j++)
            {
                if(v[j]==v[i])
                {
                    k=rand()%n;
                    v[j]=k;
                }
            }
        }
    }
    while(verificaIguais(v,n)==0);
    return v;
}



int verificaIguais(int* v,int n)
{
    int i,j,r=1;
    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(v[j]==v[i])
            {
                r=0;
                break;
            }
        }
    }

    return r;
}


int verificagrupo( grupo *g, int j)
{
    int r = 1,n=0,i;
    int conf[5] = {0,0,0,0,0};
    char *confe[5] = {"UEFA","CAF","AFC","CONCACAF","CONMEBOL"};
    while(n<4)
    {
        for(i=0; i<5; i++)
        {
            if(strcmp(g[j].a[n].confederacao,confe[i])==0)
            {
                conf[i]++;
            }
        }
        n++;
    }
    if(conf[0]>2 || conf[1]>1 || conf[2]>1 || conf[3]>1 || conf[4]>1)
    {
        r = 0;
    }

    return r;
}




int contatime (grupo *g, int i)
{
    int j,contador = 0;
    for(j=0; j<4; j++)
    {
        if( g[i].a[j].ranking != 0)
        {
            contador++;
        }
    }
    return contador;
}

int uefatem(grupo *g, int j){
  char s[5] = "UEFA";
  int i,real = 0;;
  for(i=0;i<4;i++){
    if(strncmp(g[j].a[i].confederacao,s,strlen(s))==0){
        real = 1;
    }
  }
return real;
}


int sortear(pote* p,grupo *g)
{
    int i=0,j;
    int k,c1,n;
    pais aux;
    setlocale(LC_ALL,"C");
    int *h=vetoraleatorio(8);  /////////////////////////////////////////////////////////////////////////////
    int r;
    for(i=1; i<8; i++)
    {
        if(h[i]==0)
        {
            k=h[i];
            h[i]=h[0];
            h[0]=k;
        }
    }

    for(i=0; i<8; i++)
    {
        g[i].nome='A'+i;
    }

    g[0].a[0]=p[0].a[0];
    for(j=1; j<8; j++)
        {
            n = rand() % 7+1;

            aux = p[0].a[j];
            p[0].a[j] = p[0].a[n];
            p[0].a[n] = aux;
        }

    for(i=1; i<8; i++)
    {
        g[i].a[0]=p[0].a[h[i]];

    }
    for(i=1; i<4; i++)
    {
        for(j=0; j<8; j++)
        {
            n = rand() % 8;

            aux = p[i].a[j];
            p[i].a[j] = p[i].a[n];
            p[i].a[n] = aux;
        }
    }
    free(h);
    h=vetoraleatorio(8);    ////////////////////////////////////////////////////////////////
    for(i=1; i<4; i++)
    {
        for(j=0; j<8; j++)
        {
            srand(time(NULL));
            c1=j;
            r=(rand()%3)+1;
            if( contatime(g,c1) < i + 1)
            {
                while( g[c1].a[r].ranking!=0)
                {
                    r=(rand()%3)+1;
                }
                g[c1].a[r]=p[i].a[h[j]];
            }
            int contador = 0,c3;
            while(verificagrupo(g,c1)==0)
            {
                c3=trocatimedegrupo(g,c1,r,contador,p,4);
                if(c3==0)
                {
                    return 1;
                }
                contador++;
                j++;
                if(j<8)
                {
                    g[c1].a[r] = p[i].a[h[j]];
                }
            }
        }
    }
    for(i=0; i<8; i++)
    {
        if(contatime(g,i)!=4)
        {
            return 1;
        }
    }
    return 0;
}

int verifica(int *p,int *vetor,int i){
   int k;
   int real = 1;
   for(k=i-1;k>=0;k--){
    if( vetor[k] == (*p) ){
        real = 0;
    }
   }
   return real;
}


int *vetoraleatorio(int n){
   int *h,i=0;
   h = (int*)calloc(n,sizeof(int));
   srand(time(NULL));
   h[i] = (rand () % n);
   for(i=1;i<n;i++){
      h[i] = (rand () % n);
   while( verifica(&h[i],h,i) == 0){
      h[i] = (rand () % n);
   }
   }


   return h;
}




