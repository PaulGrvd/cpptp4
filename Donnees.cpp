/*************************************************************************
Donnees  -  réalisation de la classe Donnees
-------------------
Début             : Decembre 2019
Copyright         : (C) 2019 par Paul Grévaud, Yohan MEYER  (Binôme )
E-mail            : yohan.meyer@insa-lyon.fr - paul.grevaud@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Donnees> (fichier Donnees.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

using namespace std;

//------------------------------------------------------ Include personnel
#include "Donnees.h"
#include <iostream>
#include <fstream>
#include <iterator>
#include <unordered_map>
#include <map>
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC



//----------------------------------------------------- Méthodes publiques
void Donnees:: update (int opt, int h)
{
	doption = opt;
	dheure = h;
}


int Donnees::TopTen()
{
	if (noeuds.size()<10)
	{
	cout<<"Il y a moins de 10 url, nous ne pouvons pas faire de top 10.."<<endl;	
	return 0;
	}
	multimap <int, string,greater<int>> tten;
	for(auto i=noeuds.begin();i!=noeuds.end();i++)
	{
		tten.insert(pair<int,string>(i->second,i->first));
	}
	
	auto it=tten.begin();
	int n=0;
	cout<<"top ten :"<<endl;
	//affichage 
	while (n<10)
	{
		n++;
		it++;
		cout << (*it).first << " => " << (*it).second << '\n';
	}
	return 1;
}

void Donnees:: graph()
{
	ofstream f;
	f.open("graph.dot", ofstream::out);
	f<<"digraph {\n";
	
		for (auto i=noeuds.begin();i!=noeuds.end();i++)
		{
			f<<"\""<<i->first<<"\";\n";
		}
		
		for (auto i=arcs.begin();i!=arcs.end();i++)
		{
			pair <string,string>p = i-> first;
			string pf = p.first;
			string ps = p.second;
			
			f<<"\""<<pf<<"\" -> \""<<ps << "\" [label = \""<<i->second<<"\"];\n";
			
		}
	f<<"}";
	f.close();
	//system("dot -Tpng graph.png graph.dot");
}

void Donnees::afficher(int c)
{

	int n;
	switch(c)
	{
	case 1:
		for (auto i=arcs.begin();i!=arcs.end();i++)
		{
			n=i->second; 
			cout<<n<<"second"<<endl;
		}
		break;
	case 2 : 
		for (auto i=noeuds.begin();i!=noeuds.end();i++)
		{
			n=i->second;
			//cout<<"ici"<<n<<endl;
		}
		break;
	
	}
}

bool Donnees::arc_exists(string urlref, string urldoc)
{
	pair<string,string> p = make_pair(urlref, urldoc);
	auto it = arcs.find(p);
	if (it == arcs.end())
	{
		//cout<<"cet arc n'existe pas"<<endl<<endl;
		return false; //no exists
	}
	else
	{
		return true; //exists
	}
}

bool Donnees:: noeud_exists(string url)
{
	auto it = noeuds.find(url);
	if (it == noeuds.end())
	{
		//cout<<"ce noeud n'existe pas"<<endl<<endl;
		return false; //no exists
	}
	else
	{
		return true; //exists
	}
}

int Donnees::ajouter(string urldoc, string urlref,int h)
{
	switch(doption)
	{
	case 0:
		if (arc_exists(urldoc, urlref))
		{
			//cout<<"j'ajoute 1 à arcs pour"<<urldoc<<"et"<<urlref<<endl;
			arcs[make_pair(urldoc,urlref)]+=1;
		}
		else 
		{
			//cout<<"je mets à 1 arcs pour"<<urldoc<<"et"<<urlref<<endl;
			arcs[make_pair(urldoc,urlref)]=1;
		}
		
		if (noeud_exists(urldoc))
		{
			//cout<<"j'ajoute 1 à noeuds pour"<<urldoc<<endl;
			noeuds[urldoc]+=1;
		}
		else 
		{
			//cout<<"je mets à 1 noeuds pour"<<urldoc<<endl;
			noeuds[urldoc]=1;
		}
		
		if (noeud_exists(urlref))
		{
			//cout<<"j'ajoute 1 à noeuds pour"<<urlref<<endl;
			noeuds[urlref]+=1;
		}
		else 
		{
			//cout<<"je mets à 1 noeuds pour"<<urlref<<endl;
			noeuds[urlref]=1;
		}
		break;

	case 1 : 
			if ((urldoc.find(".ico")!=string::npos||urldoc.find(".gif")!=string::npos||urldoc.find(".jpg")!=string::npos||urldoc.find(".js")!=string::npos||urldoc.find(".png")!=string::npos||urldoc.find(".jpeg")!=string::npos||urldoc.find(".css")!=string::npos)&&(urlref.find(".ico")!=string::npos||urlref.find(".gif")!=string::npos||urlref.find(".jpg")!=string::npos||urlref.find(".js")!=string::npos||urlref.find(".png")!=string::npos||urlref.find(".jpeg")!=string::npos||urlref.find(".css")!=string::npos))
			{
			cout<<"les deux sont des images"<<endl;
			cout<<urldoc<<endl;
			cout<<urlref<<endl;
				return 1;
			}else if(urlref.find(".ico")!=string::npos||urlref.find(".gif")!=string::npos||urlref.find(".jpg")!=string::npos||urlref.find(".js")!=string::npos||urlref.find(".png")!=string::npos||urlref.find(".jpeg")!=string::npos||urlref.find(".css")!=string::npos)
			{
			cout<<"ref est une image"<<endl;
			cout<<urlref<<endl;
				if (noeud_exists(urldoc))
				{
					//cout<<"j'ajoute 1 à noeuds pour"<<urldoc<<endl;
					noeuds[urldoc]+=1;
				}
				else 
				{
					//cout<<"je mets à 1 noeuds pour"<<urldoc<<endl;
					noeuds[urldoc]=1;
				}
			}else if(urldoc.find(".ico")!=string::npos||urldoc.find(".gif")!=string::npos||urldoc.find(".jpg")!=string::npos||urldoc.find(".js")!=string::npos||urldoc.find(".png")!=string::npos||urldoc.find(".jpeg")!=string::npos||urldoc.find(".css")!=string::npos)
			{
			cout<<"doc est une image"<<endl;
			cout<<urldoc<<endl;
				if (noeud_exists(urlref))
				{
					//cout<<"j'ajoute 1 à noeuds pour"<<urlref<<endl;
					noeuds[urlref]+=1;
				}
				else 
				{
					//cout<<"je mets à 1 noeuds pour"<<urlref<<endl;
					noeuds[urlref]=1;
				}
			}
			break;
	case 2 :
		if (h<dheure+1 && h>=dheure)
		{
			if (arc_exists(urldoc, urlref))
			{
				//cout<<"j'ajoute 1 à arcs pour"<<urldoc<<"et"<<urlref<<endl;
				arcs[make_pair(urldoc,urlref)]+=1;
			}
			else 
			{
				//cout<<"je mets à 1 arcs pour"<<urldoc<<"et"<<urlref<<endl;
				arcs[make_pair(urldoc,urlref)]=1;
			}
			
			if (noeud_exists(urldoc))
			{
				//cout<<"j'ajoute 1 à noeuds pour"<<urldoc<<endl;
				noeuds[urldoc]+=1;
			}
			else 
			{
				//cout<<"je mets à 1 noeuds pour"<<urldoc<<endl;
				noeuds[urldoc]=1;
			}
			
			if (noeud_exists(urlref))
			{
				//cout<<"j'ajoute 1 à noeuds pour"<<urlref<<endl;
				noeuds[urlref]+=1;
			}
			else 
			{
				//cout<<"je mets à 1 noeuds pour"<<urlref<<endl;
				noeuds[urlref]=1;
			}
		}	
		else 
		{
			return 1;
		}
		break;
	case 3 :
	 
		if (h<dheure+1 && h>=dheure)
		{
			if (arc_exists(urldoc, urlref))
			{
				//cout<<"j'ajoute 1 à arcs pour"<<urldoc<<"et"<<urlref<<endl;
				arcs[make_pair(urldoc,urlref)]+=1;
			}
			else 
			{
				//cout<<"je mets à 1 arcs pour"<<urldoc<<"et"<<urlref<<endl;
				arcs[make_pair(urldoc,urlref)]=1;
			}
			
			if (noeud_exists(urldoc))
			{
				//cout<<"j'ajoute 1 à noeuds pour"<<urldoc<<endl;
				noeuds[urldoc]+=1;
			}
			else 
			{
				//cout<<"je mets à 1 noeuds pour"<<urldoc<<endl;
				noeuds[urldoc]=1;
			}
			
			if (noeud_exists(urlref))
			{
				//cout<<"j'ajoute 1 à noeuds pour"<<urlref<<endl;
				noeuds[urlref]+=1;
			}
			else 
			{
				//cout<<"je mets à 1 noeuds pour"<<urlref<<endl;
				noeuds[urlref]=1;
			}
		}
		else 
		{
			return 1;
		}
		
		if ((urldoc.find(".ico")!=string::npos||urldoc.find(".gif")!=string::npos||urldoc.find(".jpg")!=string::npos||urldoc.find(".js")!=string::npos||urldoc.find(".png")!=string::npos||urldoc.find(".jpeg")!=string::npos||urldoc.find(".css"))!=string::npos&&(urlref.find(".ico")!=string::npos||urlref.find(".gif")!=string::npos||urlref.find(".jpg")!=string::npos||urlref.find(".js")!=string::npos||urlref.find(".png")!=string::npos||urlref.find(".jpeg")!=string::npos||urlref.find(".css")!=string::npos))
			{
				return 1;
			}else if(urlref.find(".ico")!=string::npos||urlref.find(".gif")!=string::npos||urlref.find(".jpg")!=string::npos||urlref.find(".js")!=string::npos||urlref.find(".png")!=string::npos||urlref.find(".jpeg")!=string::npos||urlref.find(".css")!=string::npos)
			{
				if (noeud_exists(urldoc))
				{
					//cout<<"j'ajoute 1 à noeuds pour"<<urldoc<<endl;
					noeuds[urldoc]+=1;
				}
				else 
				{
					//cout<<"je mets à 1 noeuds pour"<<urldoc<<endl;
					noeuds[urldoc]=1;
				}
			}else if(urldoc.find(".ico")!=string::npos||urldoc.find(".gif")!=string::npos||urldoc.find(".jpg")!=string::npos||urldoc.find(".js")!=string::npos||urldoc.find(".png")!=string::npos||urldoc.find(".jpeg")!=string::npos||urldoc.find(".css"))
			{
				if (noeud_exists(urlref))
				{
					//cout<<"j'ajoute 1 à noeuds pour"<<urlref<<endl;
					noeuds[urlref]+=1;
				}
				else 
				{
					//cout<<"je mets à 1 noeuds pour"<<urlref<<endl;
					noeuds[urlref]=1;
				}
			}
		break;
	}
	return 1;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

Donnees::Donnees()
{
#ifdef MAP
	cout << "Constructeur du Donnees" << endl;
#endif


	
} //----- Fin de Donnees


Donnees::~Donnees()
{
#ifdef MAP
	cout << "Destruction du Donnees" << endl;
#endif
	
} //----- Fin de ~Donnees

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
