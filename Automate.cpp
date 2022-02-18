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