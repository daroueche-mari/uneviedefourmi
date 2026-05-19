#include "ants.hpp"
#include "ants.cpp"
#include <iostream>

int main() 
{
    // FOURMILIERE ZERO
    std::cout << "========= DEBUT DE LA FOURMILIERE ZERO =========" << std::endl;
    Fourmiliere PlayerOne;
    Fourmiliere PlayerTwo;
    std::cout << "LA FOURMI 1 PART DU VESTIBULE" <<std::endl;
    PlayerOne.executerDFS("Sv", 1);
    PlayerOne.reinitialiserVisites();
    std::cout << "\nLA FOURMI 2 PART DU VESTIBULE" <<std::endl;
    PlayerTwo.executerDFS("Sv", 2);

    std::cout << "\n========= FIN DE LA FOURMILIERE ZERO =========" << std::endl;
    return 0;
    
}