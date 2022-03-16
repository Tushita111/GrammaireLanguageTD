#include "etat.h"
#include <iostream>
#include <stdio.h>

void Etat0:: transition(Automate* automate, Symbole* symbole)
{
    switch(*symbole)
    {
        case INT : automate->decalage(symbole, new Etat3()); break;
        case OPENPAR : automate->decalage(symbole, new Etat2()); break;
        case EXPRESSION: automate->decalage(symbole, new Etat1()); break;
        default: break;       

    }
}

void Etat1:: transition(Automate* automate, Symbole* symbole)
{
    switch(*symbole)
    {
        case PLUS : automate->decalage(symbole, new Etat4()); break;
        case MULT : automate->decalage(symbole, new Etat5()); break;
        case FIN : automate->decalage(symbole, new EtatAccepter());break; // Accpeter!
        default: break;       

    }
}

void Etat2:: transition(Automate* automate, Symbole* symbole)
{
    switch(*symbole)
    {
        case INT : automate->decalage(symbole, new Etat3()); break;
        case OPENPAR : automate->decalage(symbole, new Etat2()); break;
        case EXPRESSION: automate->decalage(symbole, new Etat6()); break;
        default: break;       

    }
}

void Etat3:: transition(Automate* automate, Symbole* symbole)
{
    switch(*symbole)
    {
        case PLUS : automate->reduction(1, symbole); break;
        case MULT : automate->reduction(1, symbole); break;
        case CLOSEPAR : automate->reduction(1, symbole); break;
        case FIN : automate->reduction(1, symbole); break;
        default: break;       

    }
}

void Etat4:: transition(Automate* automate, Symbole* symbole)
{
    switch(*symbole)
    {
        case INT : automate->decalage(symbole, new Etat3()); break;
        case OPENPAR : automate->decalage(symbole, new Etat2()); break;
        case EXPRESSION: automate->decalage(symbole, new Etat7()); break;
        default: break;       

    }
}

void Etat5:: transition(Automate* automate, Symbole* symbole)
{
    switch(*symbole)
    {
        case INT : automate->decalage(symbole, new Etat3()); break;
        case OPENPAR : automate->decalage(symbole, new Etat2()); break;
        case EXPRESSION: automate->decalage(symbole, new Etat8()); break;
        default: break;       

    }
}

void Etat6:: transition(Automate* automate, Symbole* symbole)
{
    switch(*symbole)
    {
        case PLUS : automate->decalage(symbole, new Etat4()); break;
        case MULT : automate->decalage(symbole, new Etat5()); break;
        case CLOSEPAR : automate->decalage(symbole, new Etat9()); break;
        default: break;       

    }
}

void Etat7:: transition(Automate* automate, Symbole* symbole)
{
    switch(*symbole)
    {
        case PLUS : automate->reduction(3, symbole); break;
        case MULT : automate->decalage(symbole, new Etat5()); break;
        case CLOSEPAR : automate->reduction(3, symbole); break;
        case FIN : automate->reduction(3, symbole); break;
        default: break;       

    }
}

void Etat8:: transition(Automate* automate, Symbole* symbole)
{
    switch(*symbole)
    {
        case PLUS : automate->reduction(3, symbole); break;
        case MULT : automate->reduction(3, symbole); break;
        case CLOSEPAR : automate->reduction(3, symbole); break;
        case FIN : automate->reduction(3, symbole); break;
        default: break;       

    }
}

void Etat9:: transition(Automate* automate, Symbole* symbole)
{
    switch(*symbole)
    {
        case PLUS : automate->reduction(3, symbole); break;
        case MULT : automate->reduction(3, symbole); break;
        case CLOSEPAR : automate->reduction(3, symbole); break;
        case FIN : automate->reduction(3, symbole); break;
        default: break;       

    }
}

void EtatAccepter:: transition(Automate* automate, Symbole* symbole)
{ 

}