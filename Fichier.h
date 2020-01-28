/*************************************************************************
Fichier.h - Interface de la classe Fichier
--------------------------------------------------------------------------
Début             : Decembre 2019
Copyright         : (C) 2019 par Paul Grévaud, Yohan MEYER  (Binôme )
E-mail            : yohan.meyer@insa-lyon.fr - paul.grevaud@insa-lyon.fr
*************************************************************************/

//------- Interface de la classe <Fichier> (fichier Fichier.h) -------
#ifndef Fichier_H
#define Fichier_H

//--------------------------------------------------- Interfaces utilisées

//-------------------------------------------------------- Include système

#include <cstring>
#include <fstream>
using namespace std;

//------------------------------------------------------------------------
// Rôle de la classe <Fichier>
//
//------------------------------------------------------------------------
class Fichier
{

//----------------------------------------------------------------- PUBLIC
public:
  ifstream lect;

//----------------------------------------------------- Méthodes publiques
  string getLine()
  {
    if(lect.eof())
      return "EOF";
    else if(!lect)
      return "ERREUR";
    string tampon;
    getline(lect, tampon);
    if(tampon.size() < 3)
      return "EOFF";
    return tampon;
  }
  bool etatFichier()
  {
      return !lect.fail();
  }

//-------------------------------------------- Constructeurs - destructeur
  Fichier(string nomFichier)
  {
  #ifdef MAP
  	cout << "Constructeur du Fichier" << endl;
  #endif
    lect.open(nomFichier.c_str());
  };
  virtual ~Fichier()
  {
  #ifdef MAP
  	cout << "Destruction du Fichier" << endl;
  #endif
    lect.close();
  };

//------------------------------------------------------------------ PRIVE
private:

//------------------------------------------------------- Attributs privés
  
};

#endif // Fichier_H
