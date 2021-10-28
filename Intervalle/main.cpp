#include <iostream>
#include "Intervalle.h"
using namespace std; 

int main()
{
    Intervalle I1(1,3); 
    Intervalle* I2 = new Intervalle(2, 9.3); 
    I2->consulter();
    I1.consulter();
    
    cout << I1[4] << endl; 

    Intervalle I3 = I1 | *I2; 
    Intervalle I4 = I1 & *I2;
    I3.consulter(); 
    I4.consulter();
    
}
