#include "automate.h"
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
    stack <Symbole*>* pileEvaluation= new stack<Symbole*>();
    for(int i=0; i<nbEtats; i++)
    {
        //TODO delete pointer in pileEtats
        this->pileEtats->pop();
        pileEvaluation->push(pileSymboles->top());
        //TODO delete pointer in pileSymboles
        this->pileSymboles->pop();
    }
    Expression* expr;
    switch(nbEtats)
    {
        case 1: expr= new Expression(*(pileEvaluation->top())); break;
        case 3: 
        if(*(pileEvaluation->top())==CLOSEPAR)
        {
            pileEvaluation->pop();
            expr= new Expression(*(pileEvaluation->top())); break;
        }
        else 
        {
            int a=*(pileEvaluation->top());
            int b;
            pileEvaluation->pop();
            if (*(pileEvaluation->top())==MULT)
            {
                pileEvaluation->pop();
                b= *(pileEvaluation->top());
                expr= new Expression(a*b);
                break;
            }
            else
            {
                pileEvaluation->pop();
                b= *(pileEvaluation->top());
                expr= new Expression(a+b);
                break;
            }

        }
    }
    pileSymboles->push(expr);
}

void Automate:: run()
{
    bool transitionCorrecte= true;
    Symbole* symbolCourant= this->lexer->Consulter();
    while( transitionCorrecte && *(symbolCourant)!=FIN)
    {
         transitionCorrecte=this->pileEtats->top()->transition(this, symbolCourant);
         this->lexer->Avancer();
         cout<<"avant consulter"<< *symbolCourant<< endl;
         symbolCourant= this->lexer->Consulter();     

    }
}
Automate:: ~Automate()
{

}
