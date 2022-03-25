#pragma once
#include <iostream>
#include "automate.h"
#include "symbole.h"

class Etat0;
class Etat1;
class Etat2;
class Etat3;
class Etat4;
class Etat5;
class Etat6;
class Etat7;
class Etat8;
class Etat9;
class EtatAccepter;

class Automate;

class Etat 
{
    protected:

    public:
        Etat(){}
        virtual ~Etat(){}
        virtual bool transition(Automate* automate, Symbole* symbole) = 0;
        virtual int numEtat() = 0;
        
};

class Etat0: public Etat 
{
    protected:
    
    public:
        Etat0() {}
        virtual ~Etat0(){}
        bool transition(Automate* automate, Symbole* symbole);
        int numEtat(){ return 0;}
    
};



class Etat1: public Etat 
{
    protected:
    
    public:
    Etat1() {}
    bool transition(Automate* automate, Symbole* symbole);
    int numEtat(){ return 1;}
    
};

class Etat2: public Etat 
{
    protected:
    
    public:
    Etat2() {}
    bool transition(Automate* automate, Symbole* symbole);
    int numEtat(){ return 2;}
    
};

class Etat3: public Etat 
{
    protected:
    
    public:
    Etat3() {}
    bool transition(Automate* automate, Symbole* symbole);
    int numEtat(){ return 3;}
    
};

class Etat4: public Etat 
{
    protected:
    
    public:
    Etat4() {}
    bool transition(Automate* automate, Symbole* symbole);
    int numEtat(){ return 4;}
    
};

class Etat5: public Etat 
{
    protected:
    
    public:
    Etat5() {}
    bool transition(Automate* automate, Symbole* symbole);
    int numEtat(){ return 5;}
    
};

class Etat6: public Etat 
{
    protected:
    
    public:
    Etat6(){}
    bool transition(Automate* automate, Symbole* symbole);
    int numEtat(){ return 6;}
    
};

class Etat7: public Etat 
{
    protected:
    
    public:
    Etat7(){}
    bool transition(Automate* automate, Symbole* symbole);
    int numEtat(){ return 7;}
    
};

class Etat8: public Etat 
{
    protected:
    
    public:
    Etat8(){}
    bool transition(Automate* automate, Symbole* symbole);
    int numEtat(){ return 8;}
    
};

class Etat9: public Etat 
{
    protected:
    
    public:
    Etat9(){}
    bool transition(Automate* automate, Symbole* symbole);
    int numEtat(){ return 9;}
    
};


class EtatAccepter: public Etat 
{
    protected:
    
    public:
    EtatAccepter(){}
    bool transition(Automate* automate, Symbole* symbole);
    int numEtat(){ return 10;}
    
};

