#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "elt_gouvernorat_prime.h"
#define ELEMENT_VIDE NULL
int verification_nom(char nom){
    int i=0,test=1;
    if(nom<'A' && nom>'Z')
        test=0;

    return test;
}

void elementLire(ELEMENT* elt) {
do{
    printf(" \nnom : ") ;
    fflush(stdin);
    scanf("%c",&(*elt)->nom);
    fflush(stdin);
}while (verification_nom((*elt)->nom)==0);
}

void elementLire2(ELEMENT2* elt) {
do{
    printf(" \nnom : ") ;
    fflush(stdin);
    scanf("%c",&(*elt)->nom);
    fflush(stdin);
}while (verification_nom((*elt)->nom)==0);
}


ELEMENT elementCreer (void) {
ELEMENT L;
L = (ELEMENT) malloc(sizeof(gov));
return L;
}

ELEMENT2 elementCreer2 (void) {
ELEMENT2 L;
L = (ELEMENT2) malloc(sizeof(noeud));
return L;
}
void elementDetruire (ELEMENT elt) {
free (elt);
}

void elementAfficher(ELEMENT elt) {
printf("\nnom : %s\ndate de creation :%i/%i/%i\npopulation : %i\nsuperficie : %f\nnombre de municipalite : %i ",elt->nom, elt->date_creation.j,elt->date_creation.m,elt->date_creation.a, elt->population,elt->superficie,elt->nombre_municipalites);
}

void elementCopier(ELEMENT *e1, ELEMENT e2) {
**e1=*e2;
}
int elementComparer(ELEMENT e1, ELEMENT e2) {
return (!strcmp((e1->nom),(e2->nom))) ;
}
void elementAffecter(ELEMENT* e1, ELEMENT e2) {
*e1 = e2 ;
}
