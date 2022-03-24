#include "symbole.h"
#include <iostream>

void Symbole::Affiche() {
   cout<<Etiquettes[ident];
}

void Entier::Affiche() {
   Symbole::Affiche();
   cout<<"("<<valeur<<")";
}
void Expression::Affiche() {
   Symbole::Affiche();
   cout<<"("<<valeur<<")";
}

int Symbole::val() {return -1;}
int Entier::val() {return valeur;}
int Expression::val() {return valeur;}