#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
struct persoana
{
    int p;
    char nume[255];
};
void citire(persoana t[100],int &n,FILE*f)
{
    fscanf(f,"%d\n",&n);
    for(int i=1;i<=n;i++)
        fscanf(f,"%d",&t[i].p);
    fscanf(f,"\n");
    for(int i=1;i<=n;i++)
        fgets(t[i].nume,255,f);
}
void afisare(persoana t[100],int n)
{

    for(int i=1;i<=n;i++)
        printf("%d->%s",i,t[i].nume);
}
void parcurgere_bf(persoana t[100],int n,int r,int bf[100],int niv[100],int &nr,int &nrn)
{
    int cap=1,coada=1;
    nrn=0;
    bf[1]=r;
    niv[r]=nrn;
    while(cap<=coada)
    {
        if(nrn!=0&&niv[bf[cap]]==nrn)
            nrn++;
        if(nrn==0)
            nrn++;
        for(int i=1;i<=n;i++)

            if(t[i].p==bf[cap])
            {
                bf[++coada]=i;
                niv[i]=nrn;
            }
        cap++;
        nr=cap;
    }
}
void dfr(persoana t[100],int n,int x,int df1[100],int &nr)
{
    df1[++nr]=x;
    for(int i=1;i<=n;i++)
        if(x==t[i].p)
            dfr(t,n,i,df1,nr);
}
void defe(persoana t[100],int n,int x,int df1[100],int &nr)
{
    nr=0;
    dfr(t,n,x,df1,nr);
}
char meniu()
{
    system("cls");
    printf("Apasati urmatoarele taste:a,b,c,d,1,2,3,4,5,6,7,8 si x");
    printf("\n\ta.Punctul a)Datele de intrare.");
    printf("\n\tb.Punctul b)Parcurgere pe nivele.");
    printf("\n\tc.Punctul c)Parcurgere pe vita.");
    printf("\n\td1.Punctul d1)Fratii unei persoane.");
    printf("\n\td2.Punctul d2)Verisorii primari.");
    printf("\n\td3.Punctul d3)Verisorii de gradul doi.");
    printf("\n\td4.Punctul d4)Unchi si matuse de gradul 1.");
    printf("\n\td5.Punctul d5)Unchi si matuse de gradul 2.");
    printf("\n\td6.Punctul d6)Parinti.");
    printf("\n\td7.Punctul d7)Bunici.");
    printf("\n\td8.Punctul d8)Strabunici.");
    printf("\n\td9.Punctul d9)Stra-strabunici.");
    printf("\n\tx.Inchideti programul\n");
    return getch();

}
int main()
{
    int n,r,bf[100],niv[100],df[100],nr,nr1,nrn,n1,bf1[100],niv1[100],df1[100],arb=0,nrn1,nr2,nr3,nrn2;
    char prs[100];
    char k;
    int pers;
    persoana t[100],t1[100];
    FILE*f=fopen("date.in","r");
    FILE*g=fopen("date1.in","r");
    printf("Alegeti arborele despre care doriti sa obtineti informatii: 1(al tatalui) sau 2(al mamei).");
    scanf("%d",&arb);
    if(arb==1)
    do
    {
        k=meniu();
        switch(k)
        {
            case'a':
            {



                    citire(t,n,f);
                    printf("Acesta este arborele genealogic care porneste de la strabunica din partea tatalui.\n");
                    afisare(t,n);
                getch();
                break;
            }
            case'b':
            {

                citire(t,n,f);
                    parcurgere_bf(t,n,1,bf,niv,nr,nrn);
                    printf("Succesorii pornind din radacina pe nivele ai arborelui tata:\n");
                    for(int i=1;i<nr;i++)
                            printf("%d ",bf[i]);
                    printf("\n");
                    for(int i=1;i<nr;i++)
                            printf("%s",t[bf[i]].nume);

                getch();
                break;
            }
            case'c':
            {
                citire(t,n,f);
                defe(t,n,1,df,nr1);
                printf("\nParcurgerea pe vite a arborelui tata este:\n");
                for(int i=1;i<=nr1;i++)
                    printf("%d ",df[i]);
                for(int i=1;i<nr1;i++)
                            printf("%s",t[df[i]].nume);
                getch();
                break;
            }
            case'1':
            {
                    citire(t,n,f);
                    parcurgere_bf(t,n,1,bf,niv,nr,nrn);
                    printf("Alegeti o persoana pentru care vreti sa gasiti fratii din lista urmatoare:\n");
                    for(int i=1;i<=n;i++)
                        printf("%s",t[i].nume);
                    gets(prs);
                    strcat(prs,"\n");
                    for(int i=1;i<=n;i++)
                        if(stricmp(prs,t[i].nume)==0)
                            pers=i;
                    printf("\n\n");
                    for(int i=1;i<=n;i++)
                        if(niv[i]==niv[pers]&&t[i].p==t[pers].p&&i!=pers)
                            printf("%s",t[i].nume);
                    getch();
                    break;
            }
            case'2':
            {       citire(t,n,f);
                    parcurgere_bf(t,n,1,bf,niv,nr,nrn);
                    printf("Alegeti o persoana pentru care vreti sa gasiti verisorii primari din lista urmatoare:\n");
                    for(int i=1;i<=n;i++)
                        printf("%s",t[i].nume);
                    gets(prs);
                    strcat(prs,"\n");
                    for(int i=1;i<=n;i++)
                        if(stricmp(prs,t[i].nume)==0)
                            pers=i;
                    printf("\n\n");
                    if(niv[pers]>=3)
                    for(int i=1;i<=n;i++)
                        if(niv[i]==niv[pers]&&t[t[i].p].p==t[t[pers].p].p&&i!=pers&&t[i].p!=t[pers].p)
                            printf("%s",t[i].nume);
                    getch();
                    break;
            }
             case'3':
            {       citire(t,n,f);
                    parcurgere_bf(t,n,1,bf,niv,nr,nrn);
                    printf("Alegeti o persoana pentru care vreti sa gasiti verisorii de gradul doi din lista urmatoare:\n");
                    for(int i=1;i<=n;i++)
                        printf("%s",t[i].nume);
                    gets(prs);
                    strcat(prs,"\n");
                    for(int i=1;i<=n;i++)
                        if(stricmp(prs,t[i].nume)==0)
                            pers=i;
                    printf("\n\n");
                    if(niv[pers]>=3)
                    for(int i=1;i<=n;i++)
                        if(niv[i]==niv[pers]&&t[t[i].p].p!=t[t[pers].p].p&&t[t[t[i].p].p].p==t[t[t[pers].p].p].p)
                            printf("%s",t[i].nume);
                    getch();
                    break;
            }
            case'4':
            {       citire(t,n,f);
                    parcurgere_bf(t,n,1,bf,niv,nr,nrn);
                    printf("Alegeti o persoana pentru care vreti sa gasiti unchii si matusile de gradul 1 din lista urmatoare:\n");
                    for(int i=1;i<=n;i++)
                        printf("%s",t[i].nume);
                    gets(prs);
                    strcat(prs,"\n");
                    for(int i=1;i<=n;i++)
                        if(stricmp(prs,t[i].nume)==0)
                            pers=i;
                    printf("\n\n");
                    for(int i=1;i<=n;i++)
                        if(niv[t[pers].p]==niv[i]&&t[i].p==t[t[pers].p].p)
                            printf("%s",t[i].nume);
                    getch();
                    break;
            }
            case'5':
            {       citire(t,n,f);
                    printf("Alegeti o persoana pentru care vreti sa gasiti unchii si matusile de gradul 2 din lista urmatoare:\n");
                    for(int i=1;i<=n;i++)
                        printf("%s",t[i].nume);
                    gets(prs);
                    strcat(prs,"\n");
                    for(int i=1;i<=n;i++)
                        if(stricmp(prs,t[i].nume)==0)
                            pers=i;
                    printf("\n\n");
                    for(int i=1;i<=n;i++)
                        if(niv[t[pers].p]==niv[i]&&t[i].p!=t[t[pers].p].p)
                            printf("%s",t[i].nume);
                    getch();
                    break;
            }
            case'6':
            {       citire(t,n,f);
                    printf("Alegeti o persoana pentru care vreti sa gasiti parintii din lista urmatoare:\n");
                    for(int i=1;i<=n;i++)
                        printf("%s",t[i].nume);
                    gets(prs);
                    strcat(prs,"\n");
                    for(int i=1;i<=n;i++)
                        if(stricmp(prs,t[i].nume)==0)
                                pers=i;
                    printf("\n\n");
                    printf("%s ",t[t[pers].p].nume);
                    getch();
                    break;
            }
            case'7':
            {       citire(t,n,f);
                    printf("Alegeti o persoana pentru care vreti sa gasiti bunicii din lista urmatoare:\n");
                    for(int i=1;i<=n;i++)
                        printf("%s",t[i].nume);
                    gets(prs);
                    strcat(prs,"\n");
                    for(int i=1;i<=n;i++)
                        if(stricmp(prs,t[i].nume)==0)
                            pers=i;
                    printf("\n\n");
                    printf("%s ",t[t[t[pers].p].p].nume);
                    getch();
                    break;
            }
            case'8':
            {       citire(t,n,f);
                    printf("Alegeti o persoana pentru care vreti sa gasiti strabunicii din lista urmatoare:\n");
                    for(int i=1;i<=n;i++)
                        printf("%s",t[i].nume);
                    gets(prs);
                    strcat(prs,"\n");
                    for(int i=1;i<=n;i++)
                        if(stricmp(prs,t[i].nume)==0)
                            pers=i;
                     printf("\n\n");
                    printf("%s ",t[t[t[t[pers].p].p].p].nume);
                    getch();
                    break;
            }
            case'9':
            {       citire(t,n,f);
                    printf("Alegeti o persoana pentru care vreti sa gasiti stra-strabunicii din lista urmatoare:\n");
                    for(int i=1;i<=n;i++)
                        printf("%s",t[i].nume);
                    gets(prs);
                    strcat(prs,"\n");
                    for(int i=1;i<=n;i++)
                        if(stricmp(prs,t[i].nume)==0)
                            pers=i;
                    printf("\n\n");
                    printf("Persoana aleasa nu are stra-strabunici");
                    getch();
                    break;
            }
        }

    }
    while(k!='x');
    if(arb==2)
    do
    {
        k=meniu();
        switch(k)
        {
            case'a':
            {
                citire(t1,n1,g);
                printf("Acesta este arborele genealogic care porneste de la strabunica din partea mamei.\n");
                afisare(t1,n1);
                getch();
                break;
            }
            case'b':
            {

                citire(t1,n1,g);
                parcurgere_bf(t1,n1,1,bf1,niv1,nr2,nrn1);
                printf("Succesorii pornind din radacina pe nivele ai arborelui mama:\n");
                for(int i=1;i<nr2;i++)
                    printf("%d ",bf1[i]);
                for(int i=1;i<nr2;i++)
                            printf("%s",t1[bf1[i]].nume);
                getch();
                break;
            }
            case'c':
            {
                citire(t1,n1,g);
                defe(t1,n1,1,df1,nr3);
                printf("\nParcurgerea pe vite a arborelui mama este:\n");
                for(int i=1;i<=nr3;i++)
                    printf("%d ",df1[i]);
                for(int i=1;i<nr3;i++)
                            printf("%s",t1[df1[i]].nume);
                getch();
                break;
            }
            case'1':
            {
                    citire(t1,n1,g);
                    printf("Alegeti o persoana pentru care vreti sa gasiti fratii din lista urmatoare:\n");
                    for(int i=1;i<=n1;i++)
                        printf("%s",t1[i].nume);
                    gets(prs);
                    strcat(prs,"\n");
                    for(int i=1;i<=n;i++)
                        if(stricmp(prs,t1[i].nume)==0)
                            pers=i;

                    getch();
                    break;
            }
            case'2':
            {
                    citire(t1,n1,g);
                    printf("Alegeti o persoana pentru care vreti sa gasiti verisorii primari din lista urmatoare:\n");
                    for(int i=1;i<=n1;i++)
                        printf("%s",t1[i].nume);
                    gets(prs);
                    strcat(prs,"\n");
                    for(int i=1;i<=n;i++)
                        if(stricmp(prs,t1[i].nume)==0)
                            pers=i;
                    getch();
                    break;
            }
            case'3':
            {
                    citire(t1,n1,g);
                    printf("Alegeti o persoana pentru care vreti sa gasiti verisorii de gradul doi din lista urmatoare:\n");
                    for(int i=1;i<=n1;i++)
                        printf("%s",t1[i].nume);
                    gets(prs);
                    strcat(prs,"\n");
                    for(int i=1;i<=n;i++)
                        if(stricmp(prs,t1[i].nume)==0)
                            pers=i;

                    getch();
                    break;
            }
            case'4':
            {
                    citire(t1,n1,g);
                    printf("Alegeti o persoana pentru care vreti sa gasiti unchii si matusile de gradul 1 din lista urmatoare:\n");
                    for(int i=1;i<=n1;i++)
                        printf("%s",t1[i].nume);
                    gets(prs);
                    strcat(prs,"\n");
                    for(int i=1;i<=n;i++)
                        if(stricmp(prs,t1[i].nume)==0)
                            pers=i;

                    getch();
                    break;
            }
            case'5':
            {
                    citire(t1,n1,g);
                    printf("Alegeti o persoana pentru care vreti sa gasiti unchii si matusile de gradul 2 din lista urmatoare:\n");
                    for(int i=1;i<=n1;i++)
                        printf("%s",t1[i].nume);
                    gets(prs);
                    strcat(prs,"\n");
                    for(int i=1;i<=n;i++)
                        if(stricmp(prs,t1[i].nume)==0)
                            pers=i;

                    getch();
                    break;
            }
            case'6':
            {
                    citire(t1,n1,g);
                    printf("Alegeti o persoana pentru care vreti sa gasiti parintii din lista urmatoare:\n");
                    for(int i=1;i<=n1;i++)
                        printf("%s",t1[i].nume);
                    gets(prs);
                    strcat(prs,"\n");
                    for(int i=1;i<=n;i++)
                        if(stricmp(prs,t1[i].nume)==0)
                            pers=i;

                    getch();
                    break;
            }
            case'7':
            {

                    citire(t1,n1,g);
                    printf("Alegeti o persoana pentru care vreti sa gasiti bunicii din lista urmatoare:\n");
                   for(int i=1;i<=n1;i++)
                        printf("%s",t1[i].nume);
                    gets(prs);
                    strcat(prs,"\n");
                    for(int i=1;i<=n;i++)
                        if(stricmp(prs,t1[i].nume)==0)
                            pers=i;

                    getch();
                    break;
            }
            case'8':
            {

                    citire(t1,n1,g);
                    printf("Alegeti o persoana pentru care vreti sa gasiti strabunicii din lista urmatoare:\n");
                    for(int i=1;i<=n1;i++)
                        printf("%s",t1[i].nume);
                    gets(prs);
                    strcat(prs,"\n");
                    for(int i=1;i<=n;i++)
                        if(stricmp(prs,t1[i].nume)==0)
                            pers=i;

                    getch();
                    break;
            }
            case'9':
            {

                    citire(t1,n1,g);
                    printf("Alegeti o persoana pentru care vreti sa gasiti stra-strabunicii din lista urmatoare\n:");
                    for(int i=1;i<=n1;i++)
                        printf("%s",t1[i].nume);
                    gets(prs);
                    strcat(prs,"\n");
                    for(int i=1;i<=n;i++)
                        if(stricmp(prs,t1[i].nume)==0)
                            pers=i;

                    getch();
                    break;
            }
        }

    }
    while(k!='x');
    if(arb!=1&&arb!=2)
        printf("Nu ati ales un numar corect.");
    return 0;
}
