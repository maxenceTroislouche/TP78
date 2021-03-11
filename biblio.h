#ifndef BIBLIO_H   //compilation conditionnelle
#define BIBLIO_H


#include "livre.h"

#define CAPACITE_BIBLIO 20
 // nb maximum de livres ds la bibliotheque

typedef  T_livre 	T_tabloDeLivres[CAPACITE_BIBLIO];

typedef struct
{
	T_tabloDeLivres etagere;
	int nbLivres;  //nb de livres actuellement ds la bibliotheque

} T_Bibliotheque;




//prototypes
void init (T_Bibliotheque *ptrB);
int ajouterLivre(T_Bibliotheque  *ptrB);
int  afficherBibliotheque(const T_Bibliotheque  *ptrB);
int rechercherLivreTitre(const T_Bibliotheque *ptrB,T_Titre titre);
int rechercherLivreAuteur(const T_Bibliotheque  *ptrB,T_Aut auteur);
int recherchePositionLivre(T_Bibliotheque *ptrB,T_Aut auteur,T_Titre titre);
int supprimerLivre(T_Bibliotheque *ptrB,T_Aut auteur,T_Titre titre);
int emprunterLivre(T_Bibliotheque *ptrB, T_Titre titre, T_Aut auteur, T_Emp nom_Emprunteur);
int rendreLivre(T_Bibliotheque *ptrB, T_Titre titre, T_Aut auteur);
int triTitre(T_Bibliotheque *ptrB);
int triAuteur(T_Bibliotheque *ptrB);
int triAnnee(T_Bibliotheque *ptrB);


#endif