#ifndef ELTGOVPRIM_H_INCLUDED
#define ELTGOVPRIM_H_INCLUDED
#include "elt_gouvernorat.h"
void elementLire(ELEMENT *);
void elementAfficher(ELEMENT);
void elementCopier(ELEMENT *, ELEMENT) ;
int elementComparer(ELEMENT, ELEMENT);
ELEMENT elementCreer(void) ;
void elementAffecter(ELEMENT* , ELEMENT );
void elementDetruire (ELEMENT);


#endif // ELTGOVPRIM_H_INCLUDED
