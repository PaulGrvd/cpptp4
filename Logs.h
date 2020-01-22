/*************************************************************************
Logs.h - Interface de la classe Logs
--------------------------------------------------------------------------
Début             : Decembre 2019
Copyright         : (C) 2019 par Paul Grévaud, Yohan MEYER  (Binôme )
E-mail            : yohan.meyer@insa-lyon.fr - paul.grevaud@insa-lyon.fr
*************************************************************************/

//------- Interface de la classe <Logs> (fichier Logs.h) -------
#ifndef Logs_H
#define Logs_H
#include <string>

using namespace std;
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------------------
// Rôle de la classe <Logs>
//
//------------------------------------------------------------------------
class Logs
{

//----------------------------------------------------------------- PUBLIC
public:

//----------------------------------------------------- Méthodes publiques
int getheure();
string getaction();
string getip();
string getstatus();
string getquant_data();
string geturl_referer();
string geturl_doc();
string pt(string s);


//-------------------------------------------- Constructeurs - destructeur
  Logs(string line);
  virtual ~Logs();

//------------------------------------------------------------------ PRIVE
private:
//------------------------------------------------------- Attributs privés
string heure;
string action;
string ip;
string status;
string quant_data;
string url_referer;
string url_doc;
//string navigateur; trop compliqué
};

#endif // Logs_H
