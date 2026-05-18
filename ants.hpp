#ifndef Foumiliere_hpp
#define Fourmiliere_hpp

#include <iostream>

class Fourmiliere {

private :

int fourmi;
std::string S_vestibule;
std::string S_depot;
int salle_un;
int salle_deux;
int vitesse;
int positionV;
int positionD;

public :

    Fourmiliere(int fourmi, std::string S_vestibule, std:: string S_depot, int salle_un, int salle_deux, int vitesse, int positionV,
    int positionD){
        this-> fourmi = fourmi;
        this-> S_vestibule = S_vestibule;
        this-> S_depot = S_depot;
        this-> salle_un = salle_un;
        this-> salle_deux = salle_deux;
        this-> vitesse = vitesse;
        this-> positionV = positionV;
        this-> positionD = positionD;
    }

    //setters
    void set_NbFourmi(int nbfourmi) {
        this-> fourmi = nbfourmi;
    }
    void set_vestibule(std::string txtvestibule, int posV) {
        this-> S_vestibule = txtvestibule;
        this-> positionV = posV;
    }
    void set_depotfourmi(std::string txtdepot, int posD) {
        this-> S_depot = txtdepot;
        this-> positionD = posD;
    }
    void set_numSalleUn(int numSalleOne) {
        this-> salle_un = numSalleOne;
    }
    void set_numSalleDeux(int numSalleTwo) {
        this-> salle_deux = numSalleTwo;
    }

    //getters
    int get_nbfourmi() const{
        return this-> fourmi;
    }


    std::string get_alertvestibule() const{
        return this-> S_vestibule;
    }
    int get_positionVestibule() const{
        return this-> positionV;
    }


    std::string get_depot() const{
        return this-> S_depot;
    }
    int get_positionDepot() const{
        return this-> positionD;
    }



    int get_salleOne() const{
        return this-> salle_un;
    }
    int get_salleTwo() const{
        return this-> salle_deux;
    }

};




#endif