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

        delete(this->pileEtats->top());
        this->pileEtats->pop();
        delete(this->pileEtats->top());
        this->pileEtats->pop();
        delete(this->pileEtats->top());
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

        delete(this->pileEtats->top());
        this->pileEtats->pop();
        delete(this->pileEtats->top());
        this->pileEtats->pop();
        delete(this->pileEtats->top());
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

        delete(this->pileEtats->top());
        this->pileEtats->pop();        
        delete(this->pileEtats->top());
        this->pileEtats->pop();
        delete(this->pileEtats->top());
        this->pileEtats->pop();

        this->pileEtats->top()->transition(this, op1);
        break;
    }
    case 5:
    {
        Expression *val = new Expression(this->pileSymboles->top()->val());
        this->pileSymboles->pop();
        delete(this->pileEtats->top());
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
    int parenthese = 0;
    while (this->pileEtats->top()->numEtat() != 10 && transitionCorrecte)
    {
        if(*(symboleCourant) == CLOSEPAR) parenthese--;
        else if(*(symboleCourant) == OPENPAR) parenthese++;


        transitionCorrecte = this->pileEtats->top()->transition(this, symboleCourant);
        if (*(symboleCourant) != FIN)
        {
            this->lexer->Avancer();
            symboleCourant = this->lexer->Consulter();
        }
    }
    /*if (!transitionCorrecte)
    {
        cout << "SYNTAX ERROR (transition)" << endl;
        return;
    }*/
    //cout << this->pileEtats->size();
    if (parenthese == 0 && this->pileEtats->top()->numEtat() == 10 && this->pileSymboles->size() == 2 && *(this->pileSymboles->top()) == FIN && transitionCorrecte && *(symboleCourant) == FIN)
    {
        this->pileSymboles->pop();
        cout << "Resultat: " << this->pileSymboles->top()->val() << endl;
    }else{
        cout << "SYNTAX ERROR (symbole : " ;
        this->pileSymboles -> top() ->Affiche();
        cout<<")" <<endl;
        
    }
    
}
Automate::~Automate()
{
    delete this->pileEtats;
    delete this->pileSymboles;
    delete lexer;
}
