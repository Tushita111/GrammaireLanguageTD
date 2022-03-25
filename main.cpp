#include <iostream>
#include "lexer.h"
#include "automate.h"

int main(void) {
   string chaine("(((2+5))*5)");
   cout << "Operation: " << chaine << endl;
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

