/*************************************************************************
Donnees.h - Interface de la classe Donnees
--------------------------------------------------------------------------
Début             : Decembre 2019
Copyright         : (C) 2019 par Paul Grévaud, Yohan MEYER  (Binôme )
E-mail            : yohan.meyer@insa-lyon.fr - paul.grevaud@insa-lyon.fr
*************************************************************************/

//------- Interface de la classe <Donnees> (fichier Donnees.h) -------
#ifndef Donnees_H
#define Donnees_H

#include <utility> //conteneur pair
#include <unordered_map>
#include <string>


//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------------------
// Rôle de la classe <Donnees>
//
//------------------------------------------------------------------------
// fonction de hashage pour n'importe quel type de pair (essentiel pour unordered_map qui n'a pas de table de haschage pour les pairs)

struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    }
};

class Donnees
{
//----------------------------------------------------------------- PUBLIC
public:

//----------------------------------------------------- Méthodes publiques
  bool arc_exists(string urldoc, string urlref);
  bool noeud_exists(string n);
  void afficher(int c);
  int ajouter(string urldoc,string urlref,int h);
  int TopTen();
  void graph();
	void update (int opt, int h = 0);
		
//-------------------------------------------- Constructeurs - destructeur
  Donnees();
  virtual ~Donnees();

//------------------------------------------------------------------ PRIVE
private:
unordered_map<pair<string,string>, int,hash_pair> arcs;
unordered_map<string,int> noeuds;
int doption;
int dheure;
//------------------------------------------------------- Attributs privés
  
};

#endif // Donnees_H
