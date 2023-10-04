//Marcos Ruíz González 361603
//27/09/23
//
//RGM_A08_432
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#define M 10
void Menu(void);
int vali_num(int ri, int rf, char msge[]);
void vect_man(int vect1[], int m, int ri, int rf);
void vect_alea(int v2[], int m);
void vect3(int v1[], int v2[], int v3[], int m);
void imprim_vects(int vect1[], int vect2[], int vect3[], int m);
void Mat4x4(int Mat[][4], int m, int n, int vect1[], int vect2[]);
void imprim_Mat(int Mat[][4], int m, int n);
int main()
{
    Menu();
    srand(time(NULL));
    return 0;
}
void Menu(void)
{
    int opc;
    int v1[M], v2[M], v3[M*2], Mat[4][4];
    do
    {
        printf("MENU\n");
        printf("1. LLENAR VECTOR 1 \n");
        printf("2. LLENAR VECTOR 2 \n");
        printf("3. LLENAR VECTOR 3 \n");
        printf("4. IMPRIMIR VECTORES \n");
        printf("5. LLENA MATRIZ 4X4 \n");
        printf("6. IMPRIMIR MATRIZ\n");
        printf("0. SALIR\n");
        scanf("%d",& opc);
        switch (opc)
        {
            case 1:
                vect_man(v1,M,30,70);
                break;
            case 2:
                vect_alea(v2,M);
                break;
            case 3:
                vect3(v1,v2,v3,M);
                break;
            case 4:
                imprim_vects(v1, v2, v3, M);
                break;
            case 5:
                break;
            case 6:
                break;
            case 0:
                break;
            default:
                printf("Introdujo un valor equivocado");
                break;
        }
    }while (opc!=0);
}
int vali_num(int ri, int rf, char msge[])
{
    int num;
    char xnum[30];
    do
    {
        puts(msge);
        fflush(stdin);
        gets(xnum);
        num=atoi(xnum);
    }while(num<ri or num>rf);
    return num;
}
void vect_man(int v1[], int m, int ri, int rf)
{
    int i, rango;
    rango=(rf-ri)+1;
    for(i=0;i<m;i++)
    {
        v1[i]=vali_num(ri,rf,"Dame un numero entre 30 y 70");
    }
}
void vect_alea(int v2[], int m)
{
    int i;
    for (i=0;i<m;i++)
    {
        v2[i]=rand()%20;
    }  
}
void vect3(int v1[], int v2[], int v3[], int m)
{
    int i;
    
    for(i=0;i<m;i++)
    {
        v3[i]=v1[i];  
        v3[i+10]=v2[i];
    }
}
void imprim_vects(int v1[], int v2[], int v3[], int m)
{
    int i;
    printf("Vector 1\n");
    for(i=0;i<m;i++)
    {
        printf("%d.- %d\n", i, v1[i]);
    }
     printf("Vector 2\n");
    for(i=0;i<m;i++)
    {
        printf("%d.- %d\n", i, v2[i]);
    }
     printf("Vector 3\n");
    for(i=0;i<m*2;i++)
    {
        printf("%d.- %d\n", i, v3[i]);
    }
}
void Mat4x4(int Mat[][4], int m, int n, int v1[], int v2[])
{
    int i, j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            Mat[i][j]=v1[i],v2[i];
        }
    }
}
void imprim_Mat(int Mat[][4], int m, int n)
{
    int i, j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d", Mat[i][j]);
        }
    }
}