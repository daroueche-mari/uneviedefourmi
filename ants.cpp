#include "ants.hpp"
#include <iostream>

Fourmiliere::Fourmiliere(std::map<std::string, std::vector<std::string>> configurationGraphe)
{
    this->fourmi = 1;
    this->vitesse = 10;
    this->moveFourmi = -1;
    this->m_graphe = configurationGraphe;
}

void Fourmiliere::reinitialiserVisites()
{
    m_visite.clear();
    m_cheminTrouve.clear();
}

// Méthode publique appelée par le main pour générer la route d'une fourmi
std::vector<std::string> Fourmiliere::obtenirChemin(std::string depart, std::string arrivee, int numerofourmi)
{
    reinitialiserVisites();
    if (chercherCheminDFS(depart, arrivee, numerofourmi)) {
        return m_cheminTrouve;
    }
    return {}; // Renvoie un chemin vide s'il n'y a pas d'accès
}

// Algorithme DFS modulaire
bool Fourmiliere::chercherCheminDFS(std::string salleActuelle, std::string cible, int numerofourmi)
{
    m_visite[salleActuelle] = true;
    m_cheminTrouve.push_back(salleActuelle); // On enregistre la salle dans l'itinéraire

    if (salleActuelle == cible) {
        return true; // Destination atteinte !
    }

    for (std::string voisin : m_graphe[salleActuelle])
    {
        // On conserve tes règles de guidage d'origine !
        if (numerofourmi == 1 && voisin == "S2") {
            continue; 
        }
        if (numerofourmi == 2 && voisin == "S1") {
            continue; 
        }

        if (!m_visite[voisin])
        {
            if (chercherCheminDFS(voisin, cible, numerofourmi)) {
                return true; // Si le voisin mène à la sortie, on valide le chemin
            }
        }
    }

    // Backtracking : si on s'est trompé de galerie, on retire la pièce du chemin
    m_cheminTrouve.pop_back();
    return false;
}
// Fonction générique pour faire avancer un groupe de fourmis par tours
void Fourmiliere::executerSimulationParEtapes(std::vector<ClientFourmi>& listeFourmis)
{
    int etape = 1;
    bool toutesArrivees = false;
    int totalFourmis = listeFourmis.size();

    while (!toutesArrivees)
    {
        std::cout << "Etape " << etape << " : ";
        int nbFourmisAuDepot = 0;

        // Une carte pour mémoriser quelles salles sont occupées pendant CE TOUR précis
        std::map<std::string, bool> salleOccupeeCeTour;

        for (int i = 0; i < totalFourmis; i++)
        {
            if (listeFourmis[i].arrivee) {
                nbFourmisAuDepot++;
                continue; // Fourmi déjà arrivée, on passe à la suivante
            }

            std::string salleActuelle = listeFourmis[i].chemin[listeFourmis[i].indexActuel];
            std::string salleSuivante = listeFourmis[i].chemin[listeFourmis[i].indexActuel + 1];

            // RÈGLE DE SÉCURITÉ : On avance si la salle suivante est le dépôt ("Sd")
            // OU si elle n'est pas déjà réservée par une autre fourmi ce tour-ci
            if (salleSuivante == "Sd" || !salleOccupeeCeTour[salleSuivante])
            {
                listeFourmis[i].indexActuel++; // La fourmi avance d'un nœud
                
                // Affichage strict demandé par l'énoncé
                std::cout << "f" << listeFourmis[i].id << "-" << salleActuelle << "-" << salleSuivante << "   ";

                if (salleSuivante != "Sd") {
                    salleOccupeeCeTour[salleSuivante] = true; // On bloque la salle pour le reste du tour
                } else {
                    listeFourmis[i].arrivee = true; // Arrivée finale !
                }
            }
            else if (salleActuelle != "Sv") {
                // Si elle ne peut pas avancer, elle attend sur place. 
                // Elle bloque donc sa salle actuelle (sauf si elle est encore au Vestibule).
                salleOccupeeCeTour[salleActuelle] = true;
            }
        }

        std::cout << std::endl; // Fin de l'étape

        if (nbFourmisAuDepot == totalFourmis) toutesArrivees = true;
        else etape++;
    }
    std::cout << "=> Reussite en " << etape - 1 << " etapes !\n" << std::endl;
}