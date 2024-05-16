#include "MenuManager.h"
#include <iostream>
#include <string>

using namespace std;

/*! Main function */
int main() { 
    MenuManager* mm = new MenuManager();
    mm->checkPassword();
    delete mm;
    return 0;
}
