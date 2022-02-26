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
        virtual void transition(Automate* automate, Symbole* symbole) = 0;
        
};

class Etat0: public Etat 
{
    protected:
    
    public:
        Etat0() {}
        virtual ~Etat0(){}
        void transition(Automate* automate, Symbole* symbole);
    
};



class Etat1: public Etat 
{
    protected:
    
    public:
    Etat1() {}
    void transition(Automate* automate, Symbole* symbole);
    
};

class Etat2: public Etat 
{
    protected:
    
    public:
    Etat2() {}
    void transition(Automate* automate, Symbole* symbole);
    
};

class Etat3: public Etat 
{
    protected:
    
    public:
    Etat3() {}
    void transition(Automate* automate, Symbole* symbole);
    
};

class Etat4: public Etat 
{
    protected:
    
    public:
    Etat4() {}
    void transition(Automate* automate, Symbole* symbole);
    
};

class Etat5: public Etat 
{
    protected:
    
    public:
    Etat5() {}
    void transition(Automate* automate, Symbole* symbole);
    
};

class Etat6: public Etat 
{
    protected:
    
    public:
    Etat6();
    void transition(Automate* automate, Symbole* symbole);
    
};

class Etat7: public Etat 
{
    protected:
    
    public:
    Etat7();
    void transition(Automate* automate, Symbole* symbole);
    
};

class Etat8: public Etat 
{
    protected:
    
    public:
    Etat8();
    void transition(Automate* automate, Symbole* symbole);
    
};

class Etat9: public Etat 
{
    protected:
    
    public:
    Etat9();
    void transition(Automate* automate, Symbole* symbole);
    
};


class EtatAccepter: public Etat 
{
    protected:
    
    public:
    EtatAccepter();
    void transition(Automate* automate, Symbole* symbole);
    
};

