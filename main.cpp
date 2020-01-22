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



//------------------------------------------------------ Include personnel


#include "Logs.h"
#include "Fichier.h"
#include "Donnees.h"
#include <string>
#include <iostream>

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

bool estExclusion(string option);
bool estHeure(string option);
bool estGraphe(string option);
int recupHeure(string option);

int main(int argc, char *argv[])
{
	if(argc == 1)
	{
		cerr << "Pas de nom de fichier de logs." << endl;
		return 0;
	}

	string nomFichierLog = string(argv[argc-1]);
	if (nomFichierLog.find(".log") == string::npos) 
	{
		cerr << "Le nom de fichier rentré ne contient pas l'extension '.log'." << endl;
		return 0;
	}


	Donnees data = Donnees();
	bool traceGraphe = false;

	switch(argc)
	{

		case 2:
			data.update(0);
			break;
		case 3:
			if(estExclusion(string(argv[1]))) // -e
				data.update(1);
			else
			{
				cerr << "Option non reconnue. Veuillez réessayer." << endl;
				return 0;
			}
			break;
		case 4:
			if(estGraphe(string(argv[1]))) // -g
			{
				traceGraphe = true;
				data.update(0);
			} else if(estHeure(string(argv[1]))) // -t
			{
				int heure;
				heure = recupHeure(string(argv[2]));
				if(heure == -1)	
					return 0;
				data.update(2, heure);
			} else
			{
				cerr << "Option non reconnue. Veuillez réessayer." << endl;
				return 0;
			}
			break;
		case 5:
			if(estExclusion(string(argv[1]))) // -e
			{
				if(estGraphe(string(argv[2]))) // -g
				{
					traceGraphe = true;
					data.update(1);
				} else if(estHeure(string(argv[2]))) // -t
				{
					int heure;
					heure = recupHeure(string(argv[3]));
					if(heure == -1)	
						return 0;
					data.update(3, heure);
				}
				else
				{
					cerr << "Option non reconnue. Veuillez réessayer." << endl;
					return 0;
				}
			} else if(estHeure(string(argv[1]))) // -t
			{			
				int heure;
				heure = recupHeure(string(argv[2]));
				if(heure == -1)	
					return 0;
				if(estExclusion(string(argv[3]))) // -e
					data.update(3, heure);
				else
				{
					cerr << "Option non reconnue. Veuillez réessayer." << endl;
					return 0;
				}
			} else if(estGraphe(string(argv[1]))) // -g
			{			
				traceGraphe = true;
				if(estExclusion(string(argv[3]))) // -e
					data.update(1);
				else
				{
					cerr << "Option non reconnue. Veuillez réessayer." << endl;
					return 0;
				}
			} else
			{
				cerr << "Option non reconnue. Veuillez réessayer." << endl;
				return 0;
			}
			break;
		case 6:
			if(estHeure(string(argv[1]))) // -t
			{			
				int heure;
				heure = recupHeure(string(argv[2]));
				if(heure == -1)	
					return 0;
				if(estGraphe(string(argv[3]))) // -g
				{
					traceGraphe = true;
					data.update(2, heure);
				} else
				{
					cerr << "Option non reconnue. Veuillez réessayer." << endl;
					return 0;
				}
			} else if(estGraphe(string(argv[1]))) // -g
			{			
				traceGraphe = true;
				if(estHeure(string(argv[3]))) // -t
				{			
					int heure;
					heure = recupHeure(string(argv[4]));
					if(heure == -1)	
						return 0;
					data.update(2, heure);
				} else
				{
					cerr << "Option non reconnue. Veuillez réessayer." << endl;
					return 0;
				}
			} else
			{
				cerr << "Option non reconnue. Veuillez réessayer." << endl;
				return 0;
			}
			break;
		case 7:
			if(estHeure(string(argv[1]))) // -t
			{			
				int heure;
				heure = recupHeure(string(argv[2]));
				if(heure == -1)	
					return 0;
				if(estGraphe(string(argv[3]))) // -g
				{
					traceGraphe = true;
					if(estExclusion(string(argv[5]))) // -e
					{
						data.update(3, heure);
					} else
					{
						cerr << "Option non reconnue. Veuillez réessayer." << endl;
						return 0;
					}
				} else if(estGraphe(string(argv[4]))) // -g
				{
					traceGraphe = true;
					if(estExclusion(string(argv[3]))) // -e
					{
						data.update(3, heure);
					} else
					{
						cerr << "Option non reconnue. Veuillez réessayer." << endl;
						return 0;
					}
				} else
				{
					cerr << "Option non reconnue. Veuillez réessayer." << endl;
					return 0;
				}
			} else if(estGraphe(string(argv[1]))) // -g
			{			
				traceGraphe = true;
				if(estHeure(string(argv[3]))) // -t
				{			
					int heure;
					heure = recupHeure(string(argv[4]));
					if(heure == -1)	
						return 0;
					if(estExclusion(string(argv[5]))) // -e
						data.update(3, heure);
					else
					{
						cerr << "Option non reconnue. Veuillez réessayer." << endl;
						return 0;
					}
				} else if(estHeure(string(argv[4]))) // -t
				{			
					int heure;
					heure = recupHeure(string(argv[5]));
					if(heure == -1)	
						return 0;
					if(estExclusion(string(argv[3]))) // -e
						data.update(3, heure);
					else
					{
						cerr << "Option non reconnue. Veuillez réessayer." << endl;
						return 0;
					}
				} else
				{
					cerr << "Option non reconnue. Veuillez réessayer." << endl;
					return 0;
				}
			} else if(estExclusion(string(argv[1]))) // -e
			{
				if(estHeure(string(argv[2]))) // -t
				{			
					int heure;
					heure = recupHeure(string(argv[3]));
					if(heure == -1)	
						return 0;
					if(estGraphe(string(argv[4]))) // -g
					{
						traceGraphe = true;
						data.update(3, heure);
					} else
					{
						cerr << "Option non reconnue. Veuillez réessayer." << endl;
						return 0;
					}
				} else if(estGraphe(string(argv[2]))) // -g
				{			
					traceGraphe = true;
					if(estHeure(string(argv[4]))) // -t
					{			
						int heure;
						heure = recupHeure(string(argv[5]));
						if(heure == -1)	
							return 0;
						data.update(3, heure);
					} else
					{
						cerr << "Option non reconnue. Veuillez réessayer." << endl;
						return 0;
					}
				} else
				{
					cerr << "Option non reconnue. Veuillez réessayer." << endl;
					return 0;
				}
			} else
			{
				cerr << "Option non reconnue. Veuillez réessayer." << endl;
				return 0;
			}
			break;
		default:
			break;
	}
	
	cout << "Fin du gros switch." << endl;

	
	
	Fichier monFic(nomFichierLog);
	string line;

	while(!(line = monFic.getLine()).compare("EOF") && !line.compare("ERREUR"))
	{
		Logs monLog(line);
		data.ajouter(monLog.geturl_referer(), monLog.geturl_doc(), monLog.getheure());
	}
	

	data.afficher(2);
	data.TopTen();

	if(traceGraphe)
	{
		cout << "Traçons le graphe !" << endl;
		data.graph();
	}

	cout << "Fin du programme." << endl;
	
  return 0;
} //----- Fin de main



bool estExclusion(string option)
{
	if(option.compare("-e"))
	{
		//cerr << "Option non reconnue. Veuillez réessayer." << endl;
		return false;
	}
	return true;
}

bool estHeure(string option)
{
	if(option.compare("-t"))
	{
		//cerr << "Option non reconnue. Veuillez réessayer." << endl;
		return false;
	}
	return true;
}

bool estGraphe(string option)
{
	if(option.compare("-g"))
	{
		//cerr << "Option non reconnue. Veuillez réessayer." << endl;
		return false;
	}
	return true;
}

int recupHeure(string option)
{
	int heure;
	if(option.length() > 2)
	{
		cerr << "Heure non valide. Veuillez réessayer." << endl;
		return -1;
	}	
	try
	{
		heure = stoi(option);
		if(heure > 24 || heure < 0)
		{
			cerr << "Heure non valide. Veuillez réessayer." << endl;
			return -1;
		}
		cout << heure << endl;
	}
	catch (std::invalid_argument const &e)
	{
		cerr << "Heure non valide. Veuillez réessayer." << endl;
		return -1;
	}
	catch (std::out_of_range const &e)
	{
		cerr << "Heure non valide. Veuillez réessayer." << endl;
		return -1;
	}
	return heure;
}

