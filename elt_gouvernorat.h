#ifndef ELTGOV_H_INCLUDED
#define ELTGOV_H_INCLUDED

typedef struct{
    int j;
    int m;
    int a;
}date;

typedef struct{
    char nom;
}noeud,*ELEMENT2;

typedef struct{
    char nom[18];
    date date_creation;
    int population;
    float superficie;
    int nombre_municipalites;
}gov,*ELEMENT;

#endif // ELTGOV_H_INCLUDED
