#include <iostream>
#include "lexer.h"
#include "automate.h"

int main(void) {
   string chaine("((2+5)*5+8)*2+7*3+2");
   cout << "Operation: " << chaine << endl;
   
   Lexer l(chaine);
   Automate automate (chaine);
   automate.run();
   return 0;
}

