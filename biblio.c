#include "biblio.h"

void init (T_Bibliotheque *ptrB)
{

ptrB->nbLivres=0;
// ou (*ptrB).nbLivres=0;
}

int ajouterLivre(T_Bibliotheque  *ptrB)
{
if (ptrB->nbLivres<CAPACITE_BIBLIO)// reste t il de la place?
	{
	saisirLivre(&(ptrB->etagere[ptrB->nbLivres]));
	ptrB->nbLivres++;
	return 1;
	}
	
	
return 0;
	
}


int  afficherBibliotheque(const T_Bibliotheque  *ptrB)
{
int i;
if(ptrB->nbLivres==0)
	return 0;
	else
		{
		for(i=0;i<ptrB->nbLivres;i++)
			{
			afficherLivre(&(ptrB->etagere[i]));
			
			}


		
		return 1;
		}
}


int rechercherLivreTitre(const T_Bibliotheque  *ptrB,T_Titre titre){
	int nbLivres = 0;
	int i;
	for(i = 0; i < ptrB->nbLivres; i++){
		if(strcmp(titre, ptrB->etagere[i].titre) == 0){
			nbLivres++;
			afficherLivre(&(ptrB->etagere[i]));
		}
	}
	if (nbLivres == 0)
	{
		printf("Le livre ne se trouve pas dans la bibliothèque\n");
	}else{
		printf("%d\n", nbLivres);
	}
	return nbLivres;
}

int rechercherLivreAuteur(const T_Bibliotheque  *ptrB,T_Aut auteur){
	int nbLivres = 0;
	int i;
	for(i = 0; i < ptrB->nbLivres; i++){
		if(strcmp(auteur, ptrB->etagere[i].auteur) == 0){
			nbLivres++;
			afficherLivre(&(ptrB->etagere[i]));
		}
	}
	if (nbLivres == 0)
	{
		printf("Le livre ne se trouve pas dans la bibliothèque\n");
	}else {
		printf("%d\n", nbLivres);
	}
	return nbLivres;
}
	
int recherchePositionLivre(T_Bibliotheque *ptrB,T_Aut auteur,T_Titre titre){
	  	int n=0;
            for(int i=0;i<ptrB->nbLivres;i++){
               	if((strcmp(ptrB->etagere[i].titre,titre)==0) && (strcmp(ptrB->etagere[i].auteur,auteur)==0))
                {
                    for(int j=i;j<ptrB->nbLivres;j++){
                    	ptrB->etagere[j]=ptrB->etagere[j+1];
                    }
                    ptrB->nbLivres--;
                    i--;
                }
                n++;
            }
        return n;
}

int supprimerLivre(T_Bibliotheque *ptrB,T_Aut auteur,T_Titre titre){
	int placeLivreEtagere = recherchePositionLivre(ptrB, auteur,titre);
	printf("place livre : %d\n",placeLivreEtagere);
	/*if (placeLivreEtagere != -1){
		//suppression du livre = décalage des livres qui se trouvent après
		int i = placeLivreEtagere;
		for(i = placeLivreEtagere; i < ptrB->nbLivres-1; i++){
			ptrB->etagere[placeLivreEtagere] = ptrB->etagere[placeLivreEtagere+1];
		}
		ptrB->nbLivres --;
		printf("suppression réussie\n");
	}*/

	return 0;
}

int emprunterLivre(T_Bibliotheque *ptrB, T_Titre titre, T_Aut auteur, T_Emp nom_Emprunteur){
	//on récupère la position du livre dans l'étagère
	int placeLivreEtagere = recherchePositionLivre(ptrB, auteur,titre);
	printf("place livre : %d\n",placeLivreEtagere);
	if (placeLivreEtagere != -1){
		strcpy(&ptrB->etagere[placeLivreEtagere].emprunteur, nom_Emprunteur);
		printf("emprunt réussi\n");
	}
	return 0;
}

int rendreLivre(T_Bibliotheque *ptrB, T_Titre titre, T_Aut auteur){
	int placeLivreEtagere = recherchePositionLivre(ptrB,auteur,titre);
	if(placeLivreEtagere != -1){
		ptrB->etagere[placeLivreEtagere].emprunteur[0] = '\0';
		printf("livre rendu\n");
	}
	return 0;
}

int triTitre(T_Bibliotheque *ptrB){
	int i = 0;
	int j = 0;
	T_livre aux;

	//tri sélection
	for(i = 0; i < ptrB->nbLivres; i++){
		for(j = 0; j < ptrB->nbLivres; j++){
			if(strcmp(ptrB->etagere[i].titre,ptrB->etagere[j].titre)<0){
				aux = ptrB->etagere[i];
				ptrB->etagere[i] = ptrB->etagere[j];
				ptrB->etagere[j] = aux;
			}
		}
	}
	return 0;
	return 0;
}

int triAuteur(T_Bibliotheque *ptrB){
	int i = 0;
	int j = 0;
	T_livre aux;

	//tri sélection
	for(i = 0; i < ptrB->nbLivres; i++){
		for(j = 0; j < ptrB->nbLivres; j++){
			if(strcmp(ptrB->etagere[i].auteur,ptrB->etagere[j].auteur)<0){
				aux = ptrB->etagere[i];
				ptrB->etagere[i] = ptrB->etagere[j];
				ptrB->etagere[j] = aux;
			}
		}
	}
	return 0;
}

int triAnnee(T_Bibliotheque *ptrB){
	int i = 0;
	int j = 0;
	T_livre aux;

	//tri sélection
	for(i = 0; i < ptrB->nbLivres; i++){
		for(j = 0; j < ptrB->nbLivres; j++){
			if(ptrB->etagere[i].annee < ptrB->etagere[j].annee){
				aux = ptrB->etagere[i];
				ptrB->etagere[i] = ptrB->etagere[j];
				ptrB->etagere[j] = aux;
			}
		}
	}
	return 0;
}