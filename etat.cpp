#include "etat.h"
#include <iostream>
#include <stdio.h>

bool Etat0:: transition(Automate* automate, Symbole* symbole)
{
    switch(*symbole)
    {
        case INT : automate->decalage(symbole, new Etat3()); return true; 
        case OPENPAR : automate->decalage(symbole, new Etat2()); return true;
        case EXPRESSION: automate->decalage(symbole, new Etat1()); return true; 
        default: return false;        

    }
}

bool Etat1:: transition(Automate* automate, Symbole* symbole)
{
    switch(*symbole)
    {
        case PLUS : automate->decalage(symbole, new Etat4()); return true; 
        case MULT : automate->decalage(symbole, new Etat5()); return true; 
        case FIN : automate->decalage(symbole, new EtatAccepter()); return true; // Accpeter!
        default: return false;       

    }
}

bool Etat2:: transition(Automate* automate, Symbole* symbole)
{
    switch(*symbole)
    {
        case INT : automate->decalage(symbole, new Etat3()); return true; 
        case OPENPAR : automate->decalage(symbole, new Etat2()); return true; 
        case EXPRESSION: automate->decalage(symbole, new Etat6()); return true; 
        default: return false;  
    }
}

bool Etat3:: transition(Automate* automate, Symbole* symbole)
{
    switch(*symbole)
    {
        case PLUS : automate->reduction(1, symbole); return true; 
        case MULT : automate->reduction(1, symbole); return true; 
        case CLOSEPAR : automate->reduction(1, symbole); return true; 
        case FIN : automate->reduction(1, symbole); return true; 
        default:return false;        

    }
}

bool Etat4:: transition(Automate* automate, Symbole* symbole)
{
    switch(*symbole)
    {
        case INT : automate->decalage(symbole, new Etat3());return true; 
        case OPENPAR : automate->decalage(symbole, new Etat2());return true; 
        case EXPRESSION: automate->decalage(symbole, new Etat7()); return true; 
        default:return false;     

    }
}

bool Etat5:: transition(Automate* automate, Symbole* symbole)
{
    switch(*symbole)
    {
        case INT : automate->decalage(symbole, new Etat3());return true; 
        case OPENPAR : automate->decalage(symbole, new Etat2()); return true; 
        case EXPRESSION: automate->decalage(symbole, new Etat8()); return true; 
        default:return false;        

    }
}

bool Etat6:: transition(Automate* automate, Symbole* symbole)
{
    switch(*symbole)
    {
        case PLUS : automate->decalage(symbole, new Etat4()); return true; 
        case MULT : automate->decalage(symbole, new Etat5()); return true; 
        case CLOSEPAR : automate->decalage(symbole, new Etat9()); return true; 
        default: return false;        

    }
}

bool Etat7:: transition(Automate* automate, Symbole* symbole)
{
    switch(*symbole)
    {
        case PLUS : automate->reduction(3, symbole); return true; 
        case MULT : automate->decalage(symbole, new Etat5()); return true; 
        case CLOSEPAR : automate->reduction(3, symbole); return true; 
        case FIN : automate->reduction(3, symbole); return true; 
        default: return false;       

    }
}

bool Etat8:: transition(Automate* automate, Symbole* symbole)
{
    switch(*symbole)
    {
        case PLUS : automate->reduction(3, symbole); return true; 
        case MULT : automate->reduction(3, symbole); return true; 
        case CLOSEPAR : automate->reduction(3, symbole); return true; 
        case FIN : automate->reduction(3, symbole); return true; 
        default: return false ;       

    }
}

bool Etat9:: transition(Automate* automate, Symbole* symbole)
{
    switch(*symbole)
    {
        case PLUS : automate->reduction(3, symbole); return true; 
        case MULT : automate->reduction(3, symbole); return true; 
        case CLOSEPAR : automate->reduction(3, symbole); return true; 
        case FIN : automate->reduction(3, symbole); return true; 
        default: return false ;       

    }
}

bool EtatAccepter:: transition(Automate* automate, Symbole* symbole)
{ 
    return false;
}