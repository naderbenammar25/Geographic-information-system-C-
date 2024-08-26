#include <stdio.h>
#include <stdlib.h>
#include "elt_gouvernorat_prime.h"
#include "liste_graphe_prime.h"

#include "unistd.h"

#include <conio.h>

int main()
{
    int choix1;
    int choix2;
    int choix3;
    int choix4;
    int choix5;
    int choix9;
    int choix8;
    char dest[25];
    char src[25];
    system("color F5");

    /*
     printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
     printf("                                                 chargement en cours                                                    ");
     printf("                                 ########                                             10%%");
     sleep(1);
     system("cls");
     printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
     printf("                                                 chargement en cours.                                                    ");
     printf("                                 ####################                                 30%%");
     sleep(1);
     system("cls");
     printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
     printf("                                                 chargement en cours.                                                    ");
     printf("                                 #######################                              35%%");
     sleep(1);
     system("cls");
     printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
     printf("                                                 chargement en cours..                                                  ");
     printf("                                 ########################################             80%%");
     sleep(1);
     system("cls");
     printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
     printf("                                                 chargement en cours...                                                 ");
     printf("                                 #################################################### 100%%");
     sleep(1);
     system("cls");
     printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
     printf("                                                       BIENVENUE                                                            ");
     sleep(2);
     system("cls");
    */


    do
    {
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("                                      TAPEZ 1 POUR CONTINUER AVEC LE MAP DE LA TUNISIE\n                                         TAPEZ 2 POUR CONSTRUIRE VOTRE PROPRE GRAPHE\n                                                            CHOIX: ");
        scanf("%i",&choix2);
        while(choix2!=1 && choix2!=2)
        {
            printf("\nreponse invalide! : ");
            scanf("%i",&choix2);
        }
        choix4=1;
        while(choix2==2 && choix4==1)
        {
            int v;
            printf("\ndonner le nombre de sommets du graphe : ");
            scanf("%i",&v);
            while(!(v>1 && choix2<=24))
            {
                printf("\nvaleure importante ou inferieure a 1, veuillez reessayer : ");
                scanf("%i",&choix2);
            }
            Graph G=createGraph(v);
            for(int i=1;i<=v;i++){

                ELEMENT2 elt=elementCreer2();
                elementLire2(&elt);
                G->adjList[i]=createNode2(elt,0);
            }


            while(choix4)
            {
                system("cls");
                printf("\n\n\n\n\n\n\n\n\n\n\n\n");
                printf("                                     TAPEZ 1 POUR AJOUTER DES ARRRET");
                printf("\n                                     TAPEZ 2 POUR AFFICHER LE GRAPH");
                printf("\n                                     TAPEZ 3 POUR AFFICHER LE PLUS COURT CHEMIN");
                printf("\n                                     TAPEZ 0 POUR REVENIR AU MENU PRINCIPALE : ");
                scanf("%i",&choix4);
                while(choix4!=1 && choix4!=2 && choix4!=3 && choix4!=0)
                {
                    printf("\nchoix incorrecte ! : ");
                    scanf("%i",&choix4);
                }
                if(choix4==1)
                {

                    for(int i=1; i<=G->V; i++)
                    {
                        printf("\n %i: %s",i,G->adjList[i]->info->nom);
                    }

                    printf("\nVEUILLEZ CHOISIR LE 1er SOMMET : ");
                    scanf("%i",&choix9);
                    while(choix9<1 || choix9>G->V)
                    {
                        printf("\nvous avez choisis un sommet qui n'existe pas >:( ! : ");
                        scanf("%i",&choix9);
                    }

                    printf("\nVEUILLEZ CHOISIR LE 2eme SOMMET : ");
                    scanf("%i",&choix8);
                    while(choix8<1 || choix8>24)
                    {
                        printf("\nvous avez choisis un sommet qui n'existe pas >:( ! : ");
                        scanf("%i",&choix8);
                    }
                    int poids;
                    printf("\nVEUILLEZ CHOISIR LA LONGEURE DE CETTE ARETE : ");
                    scanf("%i",&poids);
                    while(poids<1)
                    {
                        printf("\nla longeure doit etre > a 0 ! : ");
                        scanf("%i",&poids);
                    }
                    addEdge(G,G->adjList[choix9]->info,G->adjList[choix8]->info,poids);
                }
                else if(choix4==2)
                {
                    printGraph2(G);
                }
                else if(choix4==3)
                {
                       char src,dest;
                    for(int i=1;i<=G->V;i++){
                    printf("\n %i: %c",i,G->adjList[i]->info->nom);
                    }
                    int rep;
                    printf("\nTAPEZ VOTRE POINT DE DEPART : ");
                    scanf("%i",&rep);
                    while(rep<1 || rep>G->V){
                        printf("\nCHOIX INVALIDE !! : ");
                        scanf("%i",&rep);
                    }
                    src=G->adjList[rep]->info->nom;
                    printf("\nTAPEZ VOTRE POINT D'ARRIVEE : ");
                    scanf("%i",&rep);
                    while(rep<1 || rep>G->V){
                        printf("\nCHOIX INVALIDE !! : ");
                        scanf("%i",&rep);
                    }
                    dest=G->adjList[rep]->info->nom;
                    shortestPath2(G,src,dest);
                }
            }
            choix2=0;
        }




        printf("\nTAPEZ 1 POUR CONTINUER\nTAPEZ 2 POUR QUITTEZ : ");
        scanf("%i",&choix4);
        while(choix4!=1 && choix4!=2)
        {
            printf("\nreponse invalide! : ");
            scanf("%i",&choix4);
        }

        choix5=1;
        while(choix2==1 && choix5==1)
        {
            Graph G=createGraph(24);
            ELEMENT A=elementCreer(),
                    B=elementCreer(),
                    C=elementCreer(),
                    D=elementCreer(),
                    E=elementCreer(),
                    F=elementCreer(),
                    G1=elementCreer(),
                    H=elementCreer(),
                    I=elementCreer(),
                    J=elementCreer(),
                    K=elementCreer(),
                    L=elementCreer(),
                    M=elementCreer(),
                    N=elementCreer(),
                    O=elementCreer(),
                    P=elementCreer(),
                    Q=elementCreer(),
                    R=elementCreer(),
                    S=elementCreer(),
                    T=elementCreer(),
                    U=elementCreer(),
                    V=elementCreer(),
                    W=elementCreer(),
                    X=elementCreer();



            A->date_creation.a=1983;
            A->date_creation.m=12;
            A->date_creation.j=3;
            strcpy(A->nom,"ARIANA");
            A->nombre_municipalites=6;
            A->population=576088;
            A->superficie=482;
            G->adjList[1]=createNode(A,0);


            B->date_creation.a=1956;
            B->date_creation.m=6;
            B->date_creation.j=21;
            strcpy(B->nom,"BEJA");
            B->nombre_municipalites=12;
            B->population=303032;
            B->superficie=3740;
            G->adjList[2]=createNode(B,0);

            C->date_creation.a=1983;
            C->date_creation.m=12;
            C->date_creation.j=3;
            strcpy(C->nom,"BEN AROUS");
            C->nombre_municipalites=13;
            C->population=631842;
            C->superficie=761;
            G->adjList[3]=createNode(C,0);

            D->date_creation.a=1956;
            D->date_creation.m=6;
            D->date_creation.j=21;
            strcpy(D->nom,"BIZERTE");
            D->nombre_municipalites=17;
            D->population=568219;
            D->superficie= 3750;
            G->adjList[4]=createNode(D,0);

            E->date_creation.a=1956;
            E->date_creation.m=6;
            E->date_creation.j=21;
            strcpy(E->nom,"GABES");
            E->nombre_municipalites=16;
            E->population= 374300 ;
            E->superficie= 7166 ;
            G->adjList[5]=createNode(E,0);

            F->date_creation.a=1956;
            F->date_creation.m=6;
            F->date_creation.j=21;
            strcpy(F->nom,"GAFSA");
            F->nombre_municipalites=13;
            F->population=337331;
            F->superficie=7807;
            G->adjList[6]=createNode(F,0);

            G1->date_creation.a=1956;
            G1->date_creation.m=6;
            G1->date_creation.j=21;
            strcpy(G1->nom,"JENDOUBA");
            G1->nombre_municipalites=14;
            G1->population=401477 ;
            G1->superficie=3100;
            G->adjList[7]=createNode(G1,0);

            H->date_creation.a=1956;
            H->date_creation.m=6;
            H->date_creation.j=21;
            strcpy(H->nom,"KAIROUAN");
            H->nombre_municipalites=19;
            H->population=570559 ;
            H->superficie=6712;
            G->adjList[8]=createNode(H,0);

            I->date_creation.a=1956;
            I->date_creation.m=6;
            I->date_creation.j=21;
            strcpy(I->nom,"KASSERINE");
            I->nombre_municipalites=19;
            I->population=439243;
            I->superficie=8260;
            G->adjList[9]=createNode(I,0);

            K->date_creation.a= 1981 ;
            K->date_creation.m=1;
            K->date_creation.j=1;
            strcpy(K->nom,"KEBILI");
            K->nombre_municipalites=8;
            K->population=156961;
            K->superficie= 22454 ;
            G->adjList[10]=createNode(K,0);

            L->date_creation.a=1956;
            L->date_creation.m=6;
            L->date_creation.j=21;
            strcpy(L->nom,"KEF");
            L->nombre_municipalites=15;
            L->population=243156;
            L->superficie=5081          ;
            G->adjList[11]=createNode(L,0);

            M->date_creation.a=1974;
            M->date_creation.m=6;
            M->date_creation.j=21;
            strcpy(M->nom,"MAHDIA");
            M->nombre_municipalites=18;
            M->population=410812;
            M->superficie=2878;
            G->adjList[12]=createNode(M,0);

            N->date_creation.a=2000;
            N->date_creation.m=6;
            N->date_creation.j=21;
            strcpy(N->nom,"MANOUBA");
            N->nombre_municipalites=10;
            N->population=379518;
            N->superficie=1137          ;
            G->adjList[13]=createNode(N,0);


            O->date_creation.a=1956;
            O->date_creation.m=6;
            O->date_creation.j=21;
            strcpy(O->nom,"MEDENINE");
            O->nombre_municipalites=10;
            O->population=479520;
            O->superficie=9167;
            G->adjList[14]=createNode(O,0);

            P->date_creation.a=1974;
            P->date_creation.m=6;
            P->date_creation.j=5;
            strcpy(P->nom,"MONASTIR");
            P->nombre_municipalites=31;
            P->population= 548828 ;
            P->superficie=1024;
            G->adjList[15]=createNode(P,0);

            Q->date_creation.a=1956;
            Q->date_creation.m=6;
            Q->date_creation.j=21;
            strcpy(Q->nom,"NABEUL");
            Q->nombre_municipalites=27;
            Q->population=787920 ;
            Q->superficie= 2840;
            G->adjList[16]=createNode(Q,0);

            R->date_creation.a=1956;
            R->date_creation.m=6;
            R->date_creation.j=21;
            strcpy(R->nom,"SFAX");
            R->nombre_municipalites=23;
            R->population=955421 ;
            R->superficie=7545;
            G->adjList[17]=createNode(R,0);

            S->date_creation.a=1973;
            S->date_creation.m=1;
            S->date_creation.j=1;
            strcpy(S->nom,"SIDI BOUZID");
            S->nombre_municipalites=17;
            S->population=429912;
            S->superficie= 7400 ;
            G->adjList[18]=createNode(S,0);

            T->date_creation.a=1974;
            T->date_creation.m=6;
            T->date_creation.j=5;
            strcpy(T->nom,"SILIANA");
            T->nombre_municipalites=12;
            T->population= 223087 ;
            T->superficie=4642;
            G->adjList[19]=createNode(T,0);

            U->date_creation.a=1956;
            U->date_creation.m=6;
            U->date_creation.j=21;
            strcpy(U->nom,"SOUSSE");
            U->nombre_municipalites=18;
            U->population=674971 ;
            U->superficie= 2669 ;
            G->adjList[20]=createNode(U,0);

            V->date_creation.a=1981;
            V->date_creation.m=3;
            V->date_creation.j=2;
            strcpy(V->nom,"TATAOUINE");
            V->nombre_municipalites=7;
            V->population=149453;
            V->superficie=38889;
            G->adjList[21]=createNode(V,0);

            W->date_creation.a=1956;
            W->date_creation.m=6;
            W->date_creation.j=21;
            strcpy(W->nom,"TOZEUR");
            W->nombre_municipalites=6;
            W->population=107912 ;
            W->superficie=5593 ;
            G->adjList[22]=createNode(W,0);

            X->date_creation.a=1956;
            X->date_creation.m=6;
            X->date_creation.j=21;
            strcpy(X->nom,"TUNIS");
            X->nombre_municipalites=8;
            X->population=1056247;
            X->superficie=288 ;
            G->adjList[23]=createNode(X,0);

            J->date_creation.a=1976;
            J->date_creation.m=1;
            J->date_creation.j=1;
            strcpy(J->nom,"ZAGHOUAN");
            J->nombre_municipalites=8;
            J->population=176945        ;
            J->superficie=2820 ;
            G->adjList[24]=createNode(J,0);


            addEdge(G,D,A,64);
            addEdge(G,D,N,72);
            addEdge(G,D,B,104);
            addEdge(G,A,X,13);
            addEdge(G,A,N,14);
            addEdge(G,X,C,11);
            addEdge(G,X,N,10);
            addEdge(G,N,B,105);
            addEdge(G,N,C,21);
            addEdge(G,N,J,63);
            addEdge(G,C,J,50);
            addEdge(G,C,Q,60);
            addEdge(G,Q,J,64);
            addEdge(G,Q,U,109);
            addEdge(G,B,J,117);
            addEdge(G,B,G1,51);
            addEdge(G,B,T,103);
            addEdge(G,G1,T,97);
            addEdge(G,G1,L,57);
            addEdge(G,L,T,78);
            addEdge(G,L,I,123);
            addEdge(G,T,J,92);
            addEdge(G,T,I,145);
            addEdge(G,T,H,101);
            addEdge(G,T,S,163);
            addEdge(G,J,U,96);
            addEdge(G,J,H,105);
            addEdge(G,U,H,55);
            addEdge(G,U,P,22);
            addEdge(G,U,M,59);
            addEdge(G,P,M,45);
            addEdge(G,H,M,104);
            addEdge(G,H,S,106);
            addEdge(G,I,S,74);
            addEdge(G,I,F,110);
            addEdge(G,M,R,119);
            addEdge(G,R,S,132);
            addEdge(G,R,F,202);
            addEdge(G,R,E,137);
            addEdge(G,S,F,103);
            addEdge(G,F,E,157);
            addEdge(G,F,K,111);
            addEdge(G,F,W,92);
            addEdge(G,W,K,96);
            addEdge(G,E,K,119);
            addEdge(G,E,O,76);
            addEdge(G,O,V,52);
            addEdge(G,O,K,194);
            addEdge(G,K,V,233);
            for(int i=1; i<=G->V; i++)
            {
                printf("\n %i: %s",i,G->adjList[i]->info->nom);
            }
            printf("\nCHOISIR VOTRE POINT DE DEPART : ");
            scanf("%i",&choix1);
            while(choix1<1 || choix1>24)
            {
                printf("\nCHOIX INCORRECTE !! : ");
                scanf("%i",&choix1);
            }
            strcpy(src,G->adjList[choix1]->info->nom);
            printf("\nTAPEZ VOTRE POINT D'ARRIVEE : ");
            scanf("%i",&choix1);
            while(choix1<1 || choix1>24)
            {
                printf("\nCHOIX INCORRECTE !! : ");
                scanf("%i",&choix1);
            }
            strcpy(dest,G->adjList[choix1]->info->nom);
            shortestPath(G,src,dest);
            printf("\nTAPEZ 1 POUR CONTINUER\nTAPEZ 2 POUR QUITTEZ : ");
            scanf("%i",&choix5);
            while(choix5!=1 && choix5!=2)
            {
                printf("\nreponse invalide! : ");
                scanf("%i",&choix5);
            }
        }

    }
    while(choix3!=1);
    return 0;
}
