#ifndef LSTGRF_H_INCLUDED
#define LSTGRF_H_INCLUDED
#include "elt_gouvernorat_prime.h"

typedef struct structNode {
ELEMENT info;
int weight;
struct structNode* next;
} structNode, *Node;
typedef struct {
int V;
Node adjList[26];
} strucGraph, *Graph;


typedef struct structNode2 {
ELEMENT2 info;
int weight;
struct structNode2* next;
} structNode2, *Node2;
typedef struct {
int V;
Node2 adjList[26];
} strucGraph2, *Graph2;
#endif
