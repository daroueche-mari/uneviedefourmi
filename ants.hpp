#ifndef Fourmiliere_hpp
#define Fourmiliere_hpp

#include <iostream>
#include <vector>
#include <map>
#include <string>

// Ta structure pour suivre l'état de chaque fourmi par étape
struct ClientFourmi {
    int id;
    std::vector<std::string> chemin; // Son itinéraire (ex: {"Sv", "S1", "Sd"})
    int indexActuel;                 // Position actuelle dans le vecteur (0 = Sv, 1 = S1...)
    bool arrivee;                    // true si elle est au dortoir
};

class Fourmiliere
{
private:
    int fourmi;
    int vitesse;
    int moveFourmi;
    
    std::map<std::string, std::vector<std::string>> m_graphe;
    std::map<std::string, bool> m_visite;
    
    // Variable interne pour mémoriser le chemin trouvé par le DFS
    std::vector<std::string> m_cheminTrouve;

    // Version récursive interne du DFS pour collecter les pièces
    bool chercherCheminDFS(std::string salleActuelle, std::string cible, int numerofourmi);

public:
    Fourmiliere(std::map<std::string, std::vector<std::string>> configurationGraphe);

    // Découvre le chemin via le DFS et le renvoie au main
    std::vector<std::string> obtenirChemin(std::string depart, std::string arrivee, int numerofourmi);
    void reinitialiserVisites();

    void executerSimulationParEtapes(std::vector<ClientFourmi>& listeFourmis);
};

#endif