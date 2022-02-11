//
//  main.c
//  Takuzu
//
//  Created by Luc Sky on 14/05/2019.
//  Copyright © 2019 Luc Sky. All rights reserved.
//


#include <stdio.h>
#include <stdlib.h>
#include<time.h>

void menu(void);

int main()
{
    menu();
    return 0;
}


void remplir_carte(int **carte, int SIZE)// rempli la carte de .
{
    int i,j;
    for(i=0; i<SIZE; i++)
    {
        for(j=0; j<SIZE; j++)
        {
            carte[i][j] = 2;
        }
    }
    if (SIZE==4)  // cache 4x4
    {
        srand(time(NULL));
        carte[0][0]=(rand() % (1 + 1 - 0)) + 0;
        carte[3][1]=(rand() % (1 + 1 - 0)) + 0;
        carte[2][2]=(rand() % (1 + 1 - 0)) + 0;
        carte[1][2]=1;
    }
    if (SIZE==8) // cache 8x8
    {
        srand(time(NULL));
        carte[0][5]=(rand() % (1 + 1 - 0)) + 0;
        carte[4][0]=(rand() % (1 + 1 - 0)) + 0;
        carte[1][2]=(rand() % (1 + 1 - 0)) + 0;
        carte[4][7]=(rand() % (1 + 1 - 0)) + 0;
        carte[0][7]=(rand() % (1 + 1 - 0)) + 0;
        carte[7][1]=(rand() % (1 + 1 - 0)) + 0;
        carte[7][3]=(rand() % (1 + 1 - 0)) + 0;
        carte[6][2]=(rand() % (1 + 1 - 0)) + 0;
        carte[4][4]=(rand() % (1 + 1 - 0)) + 0;
        carte[3][5]=(rand() % (1 + 1 - 0)) + 0;
        carte[3][6]=(rand() % (1 + 1 - 0)) + 0;
    }
    
}


void afficher_carte (int** carte, int SIZE) // affiche dans la console
{
    int i, j;

    printf("\n\n    ");
    for (i = 0; i < SIZE; i++)
    {
        printf(" %d",i+1); // bordure de haut
    }
    printf("\n     ");
    for (i = 0; i < (SIZE)*2; i++)
    {
        printf("_");
    }
    printf("\n");
    for (i=0;i<SIZE;i++)
    {
        printf("   %d|", i+1);// bordure de gauche
        for (j=0;j<SIZE;j++)
        {
            switch(carte[i][j])// condition de remplissage du tableau
            {
                case 0:
                    printf("0 ");
                    break;
                case 1:
                    printf("1 ");
                    break;
                case 2:
                    printf(". ");
                    break;
                default:
                    printf("F ");
                    break;
            }
        }
        printf("\n");
    }
    printf("\n");
}

void player(int **carte, int SIZE)
{
    int solution_4x4[4][4]={{1, 0, 0, 1},{1, 0, 1, 0},{0, 1, 1, 0},{0, 1, 0, 1}};
    int solution_8x8[8][8]={{1, 0, 1, 1,0,1,0,0},{1, 0, 1, 0,1,0,0,1},{0, 1, 0, 1,1,0,1,0},{0, 1, 0, 1,0,1,1,0},{1, 0, 1, 0,0,1,0,1},{0, 1, 0, 0,1,0,1,1},{0, 0, 1, 1,0,1,1,0},{1, 1, 0, 0,1,0,0,1}};
    int continuer = 0,l,c,choix;
    do
    {
        printf("choissisez le nombre que vous voulez jouer ");
        scanf("%d", &choix);
    }while(choix >= 2);
    do
    {
        printf("saisir la ligne: ");
        scanf("%d", &l);
        printf("saisir la colonne: ");
        scanf("%d",&c);
        l--;
        c--;
        if ((l<SIZE) && (l>=0) && (c<SIZE) && (c>=0) )//&& (carte[l][c] == 2))
        {
            carte[l][c] = choix;
            continuer=1;
        }
        else
        {
            printf("cette case n'est pas valide");
        }
    }while(continuer != 1);
    if (SIZE == 4)
    {
        if (carte[l][c]==solution_4x4[l][c])
            printf("ce coup est correct\n");
        else
            printf(" ce coup n'est pas correct\n");
    }
    if (SIZE == 8)
    {
        if (carte[l][c]==solution_8x8[l][c])
            printf("ce coup est correct\n");
        else
            printf(" ce coup n'est pas correct\n");
    }
    
}


void same_line(int **carte, int SIZE)
{
    int i,j,same=0;
    for (i=0;i<SIZE-1;i++)
    {
        switch(i)
        {
            case 0:
                same=0;
                for(j=0; j<SIZE; j++)
                {
                    if (carte[0][j] == carte[i+1][j])
                    {
                        same+=1;
                        if (same==4)
                        {
                            printf("la ligne %d et %d sont identiques\n",i,i+1);
                        }
                    }
                }
                break;
            case 1:
                same=0;
                for(j=0; j<SIZE; j++)
                {
                    if (carte[i][j] == carte[i+1][j])
                    {
                        same+=1;
                        if (same==4)
                        {
                            printf("la ligne %d et %d sont identiques\n",i,i+1);
                        }
                    }
                }
                break;
            case 2:
                same=0;
                for(j=0; j<SIZE; j++)
                {
                    if (carte[i][j] == carte[i+1][j])
                    {
                        same+=1;
                        if (same==4)
                        {
                            printf("la ligne %d et %d sont identiques\n",i,i+1);
                        }
                    }
                }
                break;
            case 3:
                same=0;
                for(j=0; j<SIZE; j++)
                {
                    if (carte[i][j] == carte[i+1][j])
                    {
                        same+=1;
                        if (same==4)
                        {
                            printf("la ligne %d et %d sont identiques\n",i,i+1);
                        }
                    }
                }
                break;
            case 4:
                same=0;
                for(j=0; j<SIZE; j++)
                {
                    if (carte[i][j] == carte[i+1][j])
                    {
                        same+=1;
                        if (same==4)
                        {
                            printf("la ligne %d et %d sont identiques\n",i,i+1);
                        }
                    }
                }
                break;
            case 5:
                same=0;
                for(j=0; j<SIZE; j++)
                {
                    if (carte[i][j] == carte[i+1][j])
                    {
                        same+=1;
                        if (same==4)
                        {
                            printf("la ligne %d et %d sont identiques\n",i,i+1);
                        }
                    }
                }
                break;
            case 6:
                same=0;
                for(j=0; j<SIZE; j++)
                {
                    if (carte[i][j] == carte[i+1][j])
                    {
                        same+=1;
                        if (same==4)
                        {
                            printf("la ligne %d et %d sont identiques\n",i,i+1);
                        }
                    }
                }
                break;
            default:
                printf("FFF");
                break;
        }
    }
    for (j=0;j<SIZE-1;j++)
    {
        switch(j)// condition de remplissage du tableau
        {
            case 0:
                same=0;
                for(i=0; i<SIZE; i++)
                {
                    if (carte[i][j] == carte[i][j+1])
                    {
                        same+=1;
                        if (same==4)
                        {
                            printf("la colonne %d et %d sont identiques\n",j,j+1);
                        }
                    }
                }
                break;
            case 1:
                same=0;
                for(i=0; i<SIZE; i++)
                {
                    if (carte[i][j] == carte[i][j+1])
                    {
                        same+=1;
                        if (same==4)
                        {
                            printf("la colonne %d et %d sont identiques\n",j,j+1);
                        }
                    }
                }
                break;
            case 2:
                same=0;
                for(i=0; i<SIZE; i++)
                {
                    if (carte[i][j] == carte[i][j+1])
                    {
                        same+=1;
                        if (same==4)
                        {
                            printf("la colonne %d et %d sont identiques\n",j,j+1);
                        }
                    }
                }
                break;
            case 3:
                same=0;
                for(i=0; i<SIZE; i++)
                {
                    if (carte[i][j] == carte[i][j+1])
                    {
                        same+=1;
                        if (same==4)
                        {
                            printf("la colonne %d et %d sont identiques\n",j,j+1);
                        }
                    }
                }
                break;
            case 4:
                same=0;
                for(i=0; i<SIZE; i++)
                {
                    if (carte[i][j] == carte[i][j+1])
                    {
                        same+=1;
                        if (same==4)
                        {
                            printf("la colonne %d et %d sont identiques\n",j,j+1);
                        }
                    }
                }
                break;
            case 5:
                same=0;
                for(i=0; i<SIZE; i++)
                {
                    if (carte[i][j] == carte[i][j+1])
                    {
                        same+=1;
                        if (same==4)
                        {
                            printf("la colonne %d et %d sont identiques\n",j,j+1);
                        }
                    }
                }
                break;
            case 6:
                same=0;
                for(i=0; i<SIZE; i++)
                {
                    if (carte[i][j] == carte[i][j+1])
                    {
                        same+=1;
                        if (same==4)
                        {
                            printf("la colonne %d et %d sont identiques\n",j,j+1);
                        }
                    }
                }
                break;
            default:
                printf("FFF");
                break;
        }
    }
}



void valide(int **carte, int SIZE, int solution_4x4[4][4], int solution_8x8[8][8] , int l, int c)
{
    if (SIZE == 4 )
    {
        if (solution_4x4[l][c]==carte[l][c])
            printf("ton coup est correct");
        else
            printf(" ton couop n'est pas correct");
    }
    else if (SIZE == 8)
    {
        if (solution_8x8[l][c]==carte[l][c])
            printf("ton coup est correct");
        else
            printf("ton couop n'est pas correct");
    }
}
 
void rule(int **carte, int SIZE)
{
    int i, j, ligne=0, colonne=0;
    ligne=0;
    for (i=0;i<SIZE;i++)
    {
        ligne=0;
        for(j=0; j<SIZE; j++)
        {
            ligne += carte[i][j];
        }
        if (ligne %2 != 0)
        {
            printf(" la ligne %d est incorrect \n",i+1);
        }
        else
            printf(" la ligne %d est correct \n",i+1);
    }
    for (j=0;j<SIZE;j++)
    {
        colonne=0;
        for(i=0; i<SIZE; i++)
        {
            colonne += carte[i][j];
        }
        if (colonne %2 != 0)
        {
            printf(" la colonne %d est incorrect \n",j+1);
        }
        else
            printf(" la colonne %d est correct \n",j+1);
    }
}


void start_takuzu() // mode joueur VS ME
{
    system("cls");
    int win=0, i,j;
    int SIZE=0;
    int solution_4x4[4][4]={{1, 0, 0, 1},{1, 0, 1, 0},{0, 1, 1, 0},{0, 1, 0, 1}};
    int solution_8x8[8][8]={{1, 0, 1, 1,0,1,0,0},{1, 0, 1, 0,1,0,0,1},{0, 1, 0, 1,1,0,1,0},{0, 1, 0, 1,0,1,1,0},{1, 0, 1, 0,0,1,0,1},{0, 1, 0, 0,1,0,1,1},{0, 0, 1, 1,0,1,1,0},{1, 1, 0, 0,1,0,0,1}};
    do{
    printf("qu elle est la taille: " );
    scanf("%d",& SIZE);
    }while (SIZE!=4 && SIZE!=8);// saisie securisé
    int **carte;
    carte = malloc(SIZE * sizeof(*carte));
    
    for(i=0 ; i < SIZE ; i++)
    {
        carte[i] = malloc(SIZE * sizeof(**carte) );
    }
    remplir_carte(carte,SIZE);
    do
    {
        afficher_carte(carte, SIZE);
        player(carte, SIZE);
        rule(carte, SIZE);
        same_line(carte, SIZE);
        system("PAUSE");
        system("cls");
        if (SIZE == 4)
         {
             int verif4 = 0;
         for (i=0; i<SIZE;i++)
         {
         for (j=0; j<SIZE;j++)
         {
         if (carte[i][j] == solution_4x4[i][j])
         {
             verif4+=1;
         }
         }
         }
         if (verif4 == 16)
         {
             win=1;
             printf("\n win\n");
         }
         }
         if (SIZE == 8)
         {
             int verif8 = 0;
         for (i=0; i<SIZE; i++)
         {
         for (j=0; j<SIZE; j++)
         {
         if (carte[i][j] == solution_8x8[i][j])
         {
             verif8+=1;
         }
         }
         }
         if (verif8 == 64)
         {
             win=1;
             printf("\n win\n");
         }
         }
    }while(win != 1);
    system("PAUSE");
}

void menu () // menu
{
    int choix;
    do
    {
        system("cls");
        printf("1.Takuzu\n");
        printf("2.Help\n");
        printf("3.Quit\n");
        scanf("%d", &choix);
        switch (choix)
        {
            case 1:
                start_takuzu();
                break;
            case 2:
                printf(" Chaque grille ne contient que des 0 et des 1 et doit etre completee en respectant trois regles autant de 1 et de 0 sur chaque ligne et sur chaque colonne  pas plus de 2 chiffres identiques cote a cote  2 lignes ou 2 colonnes ne peuvent etre identiques \n");
                break;
            default:
                break;
        }
    }while(choix != 3);
    
}
