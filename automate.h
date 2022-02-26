#pragma once
#include <iostream>
#include "etat.h"
#include "symbole.h"
#include "lexer.h"

#include <stack>

class Etat;

class Automate
{
    protected:
        Lexer* lexer;
        stack<Symbole*>* pileSymboles; 
        stack<Etat*>* pileEtats; 

    public:
        Automate(string flux);
        ~Automate();

        
        void decalage(Symbole* s, Etat* eProchain);
        void reduction(int nbEtats, Symbole* prochainSymbole);
        void run(); 
        

};