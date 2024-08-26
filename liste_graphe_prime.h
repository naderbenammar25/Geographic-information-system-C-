#ifndef LSTGRFPRIM_H_INCLUDED
#define LSTGRFPRIM_H_INCLUDED
#include "elt_gouvernorat_prime.h"
#include "liste_graphe.h"
Node createNode(ELEMENT , int );
Graph createGraph(int );
void addEdge(Graph , ELEMENT, ELEMENT, int);
void printGraph(Graph );
void shortestPath(Graph , char [], char [] );
void printGraph2(Graph2 );
void shortestPath2(Graph2 , char , char  );

#endif // LSTGRFPRIM_H_INCLUDED
