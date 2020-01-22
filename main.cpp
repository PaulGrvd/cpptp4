/*************************************************************************
main  -  fonction principale de l'application
-------------------
Début             : Decembre 2019
Copyright         : (C) 2019 par Paul Grévaud, Yohan MEYER  (Binôme )
E-mail            : yohan.meyer@insa-lyon.fr - paul.grevaud@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <main> (fichier main.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

using namespace std;

//------------------------------------------------------ Include personnel
//#include "GereLogs.h"
#include "Logs.h"
#include "Fichier.h"
#include "Donnees.h"
#include <string>
#include <iostream>

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


int main(int argc, char *argv[])
{
	Fichier * monFic = new Fichier("anonyme.log");
	Donnees* d = new Donnees();
	string line;
  for (int i = 0 ; i < 100 ; ++i)
  {
  	Logs* l= new Logs(monFic->getLine());
  	d->ajouter(l->geturl_referer(),l->geturl_doc());
  	delete l;
  }
  
  d->afficher(2);
  d->TopTen();
  d->graph();
  
  delete monFic;
	delete d;
	
  return 0;
} //----- Fin de main
