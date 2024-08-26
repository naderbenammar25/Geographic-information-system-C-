#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include "liste_graphe_prime.h"
#include "elt_gouvernorat_prime.h"
#include <unistd.h>
Node createNode(ELEMENT e, int weight){
    Node n;
    n =(Node)malloc(sizeof(structNode));
    if(!n)
    printf ("\nPlus d'espace");
    else
    {
    elementAffecter(&n->info, e);
    n->next = NULL;
    n->weight = weight;
    }
return n;
}

int pos2(Graph2 G,char ch){
    int trouve=0,i=1;
    while(i<=G->V && !trouve){
        if(ch==G->adjList[i]->info->nom)
            trouve=1;
        else i++;
    }
    return i;
}

Node2 createNode2(ELEMENT2 e, int weight){
    Node2 n;
    n =(Node2)malloc(sizeof(structNode2));
    if(!n)
    printf ("\nPlus d'espace");
    else
    {
    elementAffecter(&n->info, e);
    n->next = NULL;
    n->weight = weight;
    }
return n;
}

Graph createGraph(int V){
    Graph G;
    G = (Graph)malloc(sizeof(strucGraph));
    G->V=V;
    return G;
}


void printGraph(Graph G){
    int i;
    for(i=1;i<=G->V;i++){
        Node n;
        printf("\n%s : ",G->adjList[i]->info->nom);
        for(n=G->adjList[i]->next;n!= NULL;n=n->next){
            if(n->next!=NULL)
                printf("%s(%i),",n->info->nom,n->weight);
            else
                printf("%s(%i)",n->info->nom,n->weight);

        }
    }
}
void printGraph2(Graph2 G){
    int i;
    for(i=1;i<=G->V;i++){
        Node2 n;
        printf("\n\t\t%c ",G->adjList[i]->info->nom);printf(": ");
        for(n=G->adjList[i]->next;n!= NULL;n=n->next){
                printf("%c(%i)",n->info->nom,n->weight);
        }
    }
    getch();
}
void addEdge(Graph G, ELEMENT src, ELEMENT dest, int weight){
    int i=1,trouve1=0,trouve2=0;
    Node q=G->adjList[i];
    while ((!trouve1 || !trouve2) && i<=G->V){
        if (elementComparer(q->info,src)){
            trouve1=1;
            Node p=q;
            while(p->next!=NULL)p=p->next;
            p->next=createNode(dest,weight);

        }
        if(elementComparer(q->info,dest)){
            trouve2=1;
            Node p=q;
            while(p->next!=NULL)p=p->next;
            p->next=createNode(src,weight);

        }
        i++;
        q=G->adjList[i];
    }
}
void shortestPath(Graph G, char source[], char dest[]){
    int dist[G->V],vist[G->V],pare[G->V];
    char ch[25];
    for(int i=1;i<=G->V;i++){
        dist[i]=INT_MAX;
        vist[i]=0;
        pare[i]=-1;
    }
    dist[find_ch(source,G)]=0;
    for (int i = 1; i <=G->V - 1; i++) {
        int u = minimum(dist, vist,G);
        vist[u] = 1;
        for(Node q=G->adjList[u];q!=NULL;q=q->next){
            int v = find_ch(q->info->nom,G);
            if (vist[v] == 0 && dist[u] != INT_MAX &&
                dist[u] + q->weight < dist[v]) {
                dist[v] = dist[u] + q->weight;
                pare[v] = u;
            }
        }
    }
    afficher(pare,source,dest,G->V,G,dist,vist);
}


void shortestPath2(Graph2 G, char source, char dest){
    int dist[G->V],vist[G->V],pare[G->V];
    char ch;
    for(int i=1;i<=G->V;i++){
        dist[i]=INT_MAX;
        vist[i]=0;
        pare[i]=-1;
    }
    dist[pos2(G,source)]=0;

    for (int i = 1; i <=G->V - 1; i++) {
        int u = mini(dist, vist,G);
        vist[u] = 1;
        for(Node2 q=G->adjList[u];q!=NULL;q=q->next){
            int v = pos2(G,q->info->nom);
            if (vist[v] == 0 && dist[u] != INT_MAX && dist[u] + q->weight < dist[v]) {
                dist[v] = dist[u] + q->weight;
                pare[v] = u;
            }
        }
    }
    afficher2(pare,source,dest,G->V,G,dist);
    getch();
}
int find_ch(char ch[],Graph G){
    int trouve=0,i=1;
    while(i<=G->V && !trouve){
        if(!strcmp(ch,G->adjList[i]->info->nom))
            trouve=1;
        else i++;
    }
    return i;
}
int mini (int min[],int x,int temp,Graph G){
    int m=INT_MAX,p=-1,i;

    for(i=1;i<=x;i++){
        if(m>=min[i] && min[i]!=-1){
            m=min[i];
            p=i;
        }
    }
    return p;
}


int parent(int k,Graph G,int vist[])
{
    int test=0;
    for(Node q=G->adjList[k];q!=NULL;q=q->next){
        if(vist[find_ch(q->info->nom,G)]){
            return 1;
        }
    }
    return test;
}

int minimum(int dist[], int sptSet[],Graph G) {
    int min=INT_MAX, m;
    for (int v=1; v<=G->V;v++) {
        if (sptSet[v]==0 && dist[v]<=min) {
            min=dist[v];
            m=v;
        }
    }
    return m;
}

void afficher(int pare[],char src[],char dest[], int v,Graph G,int dist[],int vist[]){
    char ch[25],path[v][25];


    int k=2;
    strcpy(ch,dest);
    printf("\nvous allez traverser le chemin suivant :\n");
    strcpy(path[1],ch);
    do{
        strcpy(path[k],G->adjList[pare[find_ch(ch,G)]]->info->nom);
        strcpy(ch,G->adjList[pare[find_ch(ch,G)]]->info->nom);
        k++;
    }while(find_ch(ch,G)!=find_ch(src,G));
    for(int i=k-1;i>=1;i--){
        if(i>1)printf("%s->",path[i]);
        else printf("%s",path[i]);
    }
    printf("\nla distance sera de %i km",dist[find_ch(dest,G)]);

}
void afficher2(int pare[],char src,char dest, int v,Graph2 G,int dist[]){
    char ch,chemin[v];

    int k=2;
    ch=dest;
    printf("\nLE CHEMIN :");
    chemin[1]=ch;
    do{
        chemin[k]=G->adjList[pare[pos2(G,ch)]]->info->nom;
        ch=G->adjList[pare[pos2(G,ch)]]->info->nom;
        k++;
    }while(pos2(G,ch)!=pos2(G,src));
    for(int i=k-1;i>=1;i--){
        printf("%c",chemin[i]);
        printf("->");
    }
    printf("\n\t\tLA DISTANCE : ");
    printf("%i\n",dist[pos2(G,dest)]);

}
