#ifndef Fourmiliere_hpp
#define Fourmiliere_hpp

#include <iostream>
#include <vector>
#include <map>
#include <string>

class Fourmiliere
{
private:
    // Variables de la classe
    int fourmi;
    std::string S_vestibule;
    std::string S_depot;
    std::string salle_un;   
    std::string salle_deux; 
    int vitesse;
    int moveFourmi;
    
    // Positions numériques
    int positionV;
    int positionD;
    int positionR_un;
    int positionR_deux;
    
    // Compteurs de fourmis
    int nbfourmi_ROne;
    int nbfourmi_RTwo;

    // Graphe de la fourmilière
    std::map<std::string, std::vector<std::string>> m_graphe;
    std::map<std::string, bool> m_visite;

public:
    // Constructeur par défaut
    Fourmiliere();

    // Setters
    void set_PlayerFourmi(int playerF, int speed, int choicemove);
    void set_vestibule(int posV);
    void set_depotfourmi(int posD);
    void set_SalleUn(std::string nomSalle, int posRoomone);
    void set_SalleDeux(std::string nomSalle, int posRoomtwo);

    // CORRECTION : Ajout de ", int numerofourmi" pour correspondre au .cpp
    void executerDFS(std::string salleActuelle, int numerofourmi);
    void reinitialiserVisites();

    // Getters
    int get_fourmi() const;
    int get_fourmispeed() const;
    int get_fourmichoicemove() const;
    int get_positionVestibule() const;
    int get_positionDepot() const;
    std::string get_salleOne() const;
    int get_nombrefourmi_ROne() const;
    std::string get_salleTwo() const;
    int get_nombrefourmi_RTwo() const;
};

#endif