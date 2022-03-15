#include "automate.h"
#include "etat.h"
#include <iostream>
#include <stdio.h>

Automate::Automate(string flux)
{
    this->lexer= new Lexer(flux);
    this->pileSymboles= new stack<Symbole*>();
    this->pileEtats= new stack<Etat*>();
    pileEtats->push(new Etat0());
}
void Automate:: decalage(Symbole* s, Etat* eProchain)
{
    this->pileSymboles->push(s);
    this->pileEtats->push(eProchain);
}
void Automate::reduction(int nbEtats, Symbole* prochainSymbole)
{

}

void Automate:: run()
{

}
Automate:: ~Automate()
{

}
