#include <iostream>
#include "lexer.h"
#include "automate.h"

int main(void) {
   string chaine("(1+2)*7");

   Lexer l(chaine);

  // Symbole * s;
   //while(*(s=l.Consulter())!=FIN) {
     // s->Affiche();
     // cout<<endl;
     // l.Avancer();
     Automate automate (chaine);
     automate.run();
  // }
   return 0;
}

