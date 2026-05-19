#include "ants.hpp"
#include <iostream>
#include <vector>
#include <map>
#include <string>

int main() 
{
    // Configuration de tes Graphes
    std::map<std::string, std::vector<std::string>> FourmiliereZero = {
        {"Sv", {"S1", "S2"}}, {"S1", {"Sd"}}, {"S2", {"Sd"}}, {"Sd", {}}
    };

    std::map<std::string, std::vector<std::string>> FourmiliereUn = {
        {"Sv", {"S1"}}, {"S1", {"S2"}}, {"S2", {"Sd"}}, {"Sd", {}}
    };

    // ====================================================
    // 1. SIMULATION : FOURMILIERE ZERO
    // ====================================================
    std::cout << "========= FOURMILIERE ZERO =========" << std::endl;
    Fourmiliere PlayerSimulation0(FourmiliereZero);

    std::vector<std::string> cheminF1 = PlayerSimulation0.obtenirChemin("Sv", "Sd", 1);
    std::vector<std::string> cheminF2 = PlayerSimulation0.obtenirChemin("Sv", "Sd", 2);

    std::vector<ClientFourmi> fourmisF0 = {
        {1, cheminF1, 0, false},
        {2, cheminF2, 0, false}
    };
    
    // CORRECTION : Appel de la méthode depuis l'objet
    PlayerSimulation0.executerSimulationParEtapes(fourmisF0);


    // ====================================================
    // 2. SIMULATION : FOURMILIERE UN
    // ====================================================
    std::cout << "========= FOURMILIERE UN =========" << std::endl;
    Fourmiliere PlayerSimulation1(FourmiliereUn);
    
    std::vector<std::string> cheminUnique = PlayerSimulation1.obtenirChemin("Sv", "Sd", 3);

    std::vector<ClientFourmi> fourmisF1 = {
        {1, cheminUnique, 0, false},
        {2, cheminUnique, 0, false},
        {3, cheminUnique, 0, false},
        {4, cheminUnique, 0, false},
        {5, cheminUnique, 0, false}
    };
    
    // CORRECTION : Appel de la méthode depuis l'objet
    PlayerSimulation1.executerSimulationParEtapes(fourmisF1);

    return 0;
}