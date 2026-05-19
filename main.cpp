#include "ants.hpp"
#include "ants.cpp"
#include <iostream>

int main() 
{
    std::cout << "========= DEBUT DE LA SIMULATION =========" << std::endl;

    Fourmiliere PlayerOne;
    Fourmiliere PlayerTwo;
    std::cout << "La fourmi 1 part du vestibule" <<std::endl;
    PlayerOne.executerDFS("Sv");
    PlayerOne.reinitialiserVisites();

    std::cout << "La fourmi 2 part du vestibule" <<std::endl;
    PlayerTwo.executerDFS("Sv");

    std::cout << "\n========= FIN DE LA SIMULATION =========" << std::endl;
    return 0;
}