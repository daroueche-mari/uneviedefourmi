#include "ants.hpp"
#include <iostream>

// Constructeur : On initialise toutes nos variables et notre graphe !
Fourmiliere::Fourmiliere()
{
    this->fourmi = 1;
    this->vitesse = 10;
    this->moveFourmi = -1;
    this->nbfourmi_ROne = 0;
    this->nbfourmi_RTwo = 0;

    // Attribution des positions numériques fictives pour tes if
    this->positionV = 0;
    this->positionR_un = 1;
    this->positionR_deux = 2;
    this->positionD = 3;

    // Le graphe complet (la structure réelle de la fourmilière)
    m_graphe["Sv"] = {"S1", "S2"}; // Le Vestibule mène BIEN à S1 et S2
    m_graphe["S1"] = {"Sd"};       // Salle 1 vers Dépôt
    m_graphe["S2"] = {"Sd"};       // Salle 2 vers Dépôt
    m_graphe["Sd"] = {};           // Le dépôt n'a pas de sortie
}

// Configuration de la fourmi
void Fourmiliere::set_PlayerFourmi(int playerF, int speed, int choicemove)
{
    if (nbfourmi_ROne == 1 && nbfourmi_RTwo == 1)
    {
        choicemove = -1;
    }

    this->fourmi = playerF;
    this->vitesse = speed;
    this->moveFourmi = choicemove;
}

// Le Vestibule
void Fourmiliere::set_vestibule(int posV)
{
    this->positionV = posV;
    if (this->moveFourmi == this->positionV)
    {
        std::cout << "Vous etes au vestibule." << std::endl;
    }
}

// Le Dépot (Destination)
void Fourmiliere::set_depotfourmi(int posD)
{
    this->positionD = posD;
    if (this->moveFourmi == this->positionD)
    {
        std::cout << "Vous etes au depot !" << std::endl;
    }
}

// La Salle 1
void Fourmiliere::set_SalleUn(std::string nomSalle, int posRoomone)
{
    this->salle_un = nomSalle;
    this->positionR_un = posRoomone;

    if (this->moveFourmi == this->positionR_un)
    {
        this->nbfourmi_ROne++;
        std::cout << "Vous etes a la salle 1. Nombre de Fourmis ici : " << this->nbfourmi_ROne << std::endl;
    }
    else if (this->nbfourmi_ROne > 1)
    {
        this->moveFourmi = -1;
        std::cout << "Alerte ! Une seule fourmi est autorisee !" << std::endl;
    }
    else if (this->moveFourmi != this->positionR_un)
    {
        if (this->nbfourmi_ROne > 0)
            this->nbfourmi_ROne--;
        std::cout << "La salle 1 est disponible." << std::endl;
    }
}

// La Salle 2
void Fourmiliere::set_SalleDeux(std::string nomSalle, int posRoomtwo)
{
    this->salle_deux = nomSalle;
    this->positionR_deux = posRoomtwo;

    if (this->moveFourmi == this->positionR_deux)
    {
        this->nbfourmi_RTwo++;
        std::cout << "Vous etes a la salle 2. Nombre de Fourmis ici : " << this->nbfourmi_RTwo << std::endl;
    }
    else if (this->nbfourmi_RTwo > 1)
    {
        this->moveFourmi = -1;
        std::cout << "Alerte ! Une seule fourmi est autorisee !" << std::endl;
    }
    else if (this->moveFourmi != this->positionR_deux)
    {
        if (this->nbfourmi_RTwo > 0)
            this->nbfourmi_RTwo--;
        std::cout << "La salle 2 est disponible." << std::endl;
    }
}

// L'ALGORITHME DFS (Parcours en profondeur)
void Fourmiliere::executerDFS(std::string salleActuelle, int numerofourmi)
{
    // 1. Marquer la salle actuelle comme visitée et assigner le numéro
    this->fourmi = numerofourmi;
    m_visite[salleActuelle] = true;
    std::cout << "\n[Fourmi " << this->fourmi << "] -> Exploration du noeud : " << salleActuelle << std::endl;
    // 2. Faire le lien entre le nom du graphe ("S1", "S2"...) et tes méthodes de salle
    if (salleActuelle == "Sv")
    {
        this->moveFourmi = this->positionV;
        set_vestibule(this->positionV);
    }
    else if (salleActuelle == "S1")
    {
        this->moveFourmi = this->positionR_un;
        set_SalleUn(salleActuelle, this->positionR_un);
    }
    else if (salleActuelle == "S2")
    {
        this->moveFourmi = this->positionR_deux;
        set_SalleDeux(salleActuelle, this->positionR_deux);
    }
    else if (salleActuelle == "Sd")
    {
        this->moveFourmi = this->positionD;
        set_depotfourmi(this->positionD);
        return; // Destination atteinte, on arrête cette branche
    }

    // 3. Explorer récursivement les salles voisines non visitées
    for (std::string voisin : m_graphe[salleActuelle])
    {
        // SI C'EST LA FOURMI 1 -> On bloque l'accès à la Salle 2
        if (this->fourmi == 1 && voisin == "S2")
        {
            // std::cout << "[Securite] Fourmi 1 : Acces refuse a S2 !" << std::endl;
            continue; // Ignore S2 et passe directement au voisin suivant
        }

        // SI C'EST LA FOURMI 2 -> On bloque l'accès à la Salle 1
        if (this->fourmi == 2 && voisin == "S1")
        {
            // std::cout << "[Securite] Fourmi 2 : Acces refuse a S1 !" << std::endl;
            continue; // Ignore S1 et passe directement au voisin suivant
        }
        if (!m_visite[voisin])
        {
            // CORRECTION : On retransmet bien "numerofourmi" à l'appel suivant !
            executerDFS(voisin, numerofourmi);
        }
    }
}

// Permet de vider l'historique des visites si tu veux relancer le DFS
void Fourmiliere::reinitialiserVisites()
{
    m_visite.clear();
}

// GETTERS
int Fourmiliere::get_fourmi() const { return this->fourmi; }
int Fourmiliere::get_fourmispeed() const { return this->vitesse; }
int Fourmiliere::get_fourmichoicemove() const { return this->moveFourmi; }
int Fourmiliere::get_positionVestibule() const { return this->positionV; }
int Fourmiliere::get_positionDepot() const { return this->positionD; }
std::string Fourmiliere::get_salleOne() const { return this->salle_un; }
int Fourmiliere::get_nombrefourmi_ROne() const { return this->nbfourmi_ROne; }
std::string Fourmiliere::get_salleTwo() const { return this->salle_deux; }
int Fourmiliere::get_nombrefourmi_RTwo() const { return this->nbfourmi_RTwo; }