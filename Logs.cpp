/*************************************************************************
Logs  -  réalisation de la classe Logs
-------------------
Début             : Decembre 2019
Copyright         : (C) 2019 par Paul Grévaud, Yohan MEYER  (Binôme )
E-mail            : yohan.meyer@insa-lyon.fr - paul.grevaud@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Logs> (fichier Logs.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

using namespace std;

//------------------------------------------------------ Include personnel
#include "Logs.h"
#include <regex>
#include <iostream>
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
int Logs:: getheure()
{
return stoi(heure);
}

string Logs:: getaction()
{
return action;
}

string Logs:: getip()
{
return ip;
}

string Logs:: getstatus()
{
return status;
}

string Logs:: geturl_doc()
{
return url_doc;
}

string Logs:: geturl_referer()
{
return url_referer;
}

string Logs:: getquant_data()
{
return quant_data;
}


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

Logs::Logs(string line)
{
#ifdef MAP
	cout << "Constructeur du Logs" << endl;
#endif
	regex rheure("\\[\\d+\\/\\w+\\/\\d+:(\\d+)[^.]+");
	regex raction("\\d+]..(\\w+)[^.]+");
	regex rdoc("\\d+]..\\w+.([^\\s]+)[^.]+");
	regex rref("\"[^\"]+.[^\"]+.([^\"]+)[^.]+");
	regex rip("\\d{3}.\\d{3}.\\d.\\d");
	regex rqtdata("\\d+]..\\w+.[^\\s]+[^\"]+\".[^\\s]+.([^\\s]+)");
	regex rstatus("\\d+]..\\w+.[^\\s]+[^\"]+\".([^\\s]+)");
	
	smatch match;
	regex_search(line,match,rheure);
	heure = match.str(1);
	
	regex_search(line,match,raction);
	action = match.str(1);
	
	regex_search(line,match,rdoc);
	url_doc = match.str(1);
	
	regex_search(line,match,rref);
	url_referer = match.str(1);
	
	regex_search(line,match,rip);
	ip = match.str(0);
	
	regex_search(line,match,rqtdata);
	quant_data = match.str(1);
	
	regex_search(line,match,rstatus);
	status = match.str(1);
	//cout << "heure : " << heure << endl;
	//cout << url_doc << endl;
	
	
} //----- Fin de Logs


Logs::~Logs()
{
#ifdef MAP
	cout << "Destruction du Logs" << endl;
#endif
	
} //----- Fin de ~Logs

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
