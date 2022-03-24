#include "automate.h"
#include <iostream>
#include <stdio.h>

Automate::Automate(string flux)
{
    this->lexer = new Lexer(flux);
    this->pileSymboles = new stack<Symbole *>();
    this->pileEtats = new stack<Etat *>();
    pileEtats->push(new Etat0());
}
void Automate::decalage(Symbole *s, Etat *eProchain)
{
    this->pileSymboles->push(s);
    this->pileEtats->push(eProchain);
}
void Automate::reduction(int nbEtats, Symbole *prochainSymbole)
{
    switch (nbEtats)
    {
    case 2:
    {
        Symbole *op1 = this->pileSymboles->top();
        this->pileSymboles->pop();
        this->pileSymboles->pop();

        Symbole *op2 = this->pileSymboles->top();
        this->pileSymboles->pop();

        this->pileEtats->pop();
        this->pileEtats->pop();
        this->pileEtats->pop();
        this->pileEtats->top()->transition(this, new Expression(op1->val() + op2->val()));
        break;
    }

    case 3:
    {
        Symbole *op1 = this->pileSymboles->top();
        this->pileSymboles->pop();
        this->pileSymboles->pop();

        Symbole *op2 = this->pileSymboles->top();
        this->pileSymboles->pop();

        this->pileEtats->pop();
        this->pileEtats->pop();
        this->pileEtats->pop();
        this->pileEtats->top()->transition(this, new Expression(op1->val() * op2->val()));
        break;
    }
    case 4:
    {
        this->pileSymboles->pop();
        Symbole *op1 = this->pileSymboles->top();
        this->pileSymboles->pop();
        this->pileSymboles->pop();

        this->pileEtats->pop();        
        this->pileEtats->pop();
        this->pileEtats->pop();

        this->pileEtats->top()->transition(this, op1);
        break;
    }
    case 5:
    {
        Expression *val = new Expression(this->pileSymboles->top()->val());
        this->pileSymboles->pop();
        this->pileEtats->pop();

        this->pileEtats->top()->transition(this, val);

        break;
    }
    }
    this->pileEtats->top()->transition(this, prochainSymbole);
}

void Automate::run()
{

    stack<Symbole *> errors;
    bool transitionCorrecte = true;
    Symbole *symboleCourant = this->lexer->Consulter();
    while ( this->pileEtats->top()->numEtat() != 10 && transitionCorrecte)
    {
        transitionCorrecte = this->pileEtats->top()->transition(this, symboleCourant);
        if (*(symboleCourant) != FIN)
        {
            this->lexer->Avancer();
            symboleCourant = this->lexer->Consulter();
        }
    }
    if (!transitionCorrecte)
    {
        cout << "SYNTAX ERROR" << endl;
        return;
    }

    while (this->pileSymboles->size() != 1)
    {
        this->pileSymboles->pop();
    }
    cout << "Resultat: " << this->pileSymboles->top()->val() << endl;
}
Automate::~Automate()
{
    delete this->pileEtats;
    delete this->pileSymboles;
}
