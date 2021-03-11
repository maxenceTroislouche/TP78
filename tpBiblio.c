// TP GESTION D'UNE BIBLIOTHEQUE
#include "biblio.h"

int menu()
{
	int choix;
// au programme du TP6 :
printf("\n\n 1 - ajouter un nouveau livre dans la bibliotheque ");
printf("\n 2 - afficher tous les livres de la bibliotheque ");
printf("\n 3 - rechercher un livre (par son titre)");  // il peut y avoir plusieurs livres de même titre. Dans ce cas, indiquez le nombre d'exemplaires disponibles
printf("\n 4 - rechercher et afficher tous les livres d'un auteur");
printf("\n 5 - supprimer un livre de la bibliotheque");
// si les 5 choix ci dessus sont bien codés, modifiez votre structure T_Livre et passez à 5 champs (avec code,editeur et annee)


// au programme du TP7 :
// ajouter le champ emprunteur à votre structure T_Livre

printf("\n 6 - emprunter un livre de la bibliotheque");
printf("\n 7 - restituer/rendre un livre de la bibliotheque");
printf("\n 8 - trier les livres (par titre)");
printf("\n 9 - trier les livres (par auteur)");
printf("\n 10 - trier les livres (par annee)");

// si les 5 choix (6-10) sont bien codés, changez le type T_Emp et remplacez-le par la structure T_Emp visible dans livre.h
// vous pourrez alors faire les menus 11,12,etc...
// printf("\n 11- lister les livres disponibles ");
// printf("\n 12 - lister les emprunts en retard "); //on suppose qu'un emprunt dure 7 jours.
// printf("\n 13 - ... imaginez vous même vos propres fonctionnalités ")

printf("\n 0 - QUITTER");
printf("\n Votre choix : ");
scanf("%d[^\n]",&choix);getchar();
return choix;


}

void sauvegarde(T_Bibliotheque *ptrB)
{
FILE *fic=NULL; //le type FILE
int i;
fic=fopen("baseLivres","w"); // w = le mode = write avec ECRASEMENT
//fopen renvoie NULL si probleme (disque plein, disque non accessible ...
if (fic!=NULL)
	{
	for(i=0;i<ptrB->nbLivres;i++)
		{
//fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream)
    fwrite(  &(ptrB->etagere[i])        ,sizeof(T_livre),1,fic);

		}
	fclose(fic);
	puts("SAUVEGARDE REUSSIE ..............");



	}
	else puts("ECHEC DE SAUVEGARDE  !!!!!  ");




}

void chargement(T_Bibliotheque *ptrB)
{
FILE *fic=NULL; //le type FILE
int i=0;
fic=fopen("baseLivres","r"); // r = le mode read
//fopen renvoie NULL si probleme (disque plein, disque non accessible ...
if (fic!=NULL)
	{
	do
		{

		fread(  &(ptrB->etagere[i]) ,sizeof(T_livre),1,fic);
		i++;
		}
		while(!feof(fic));
	fclose(fic);
	ptrB->nbLivres=i-1;
	puts("CHARGEMENT  REUSSI ..............");
	}
	else puts("ECHEC DE CHARGEMENT  !!!!!  ");

}

int main()
{
int reponse,chx;
char* titreLivre[1000];
char* auteurLivre[1000];
char* nomEmprunteur[1000];
T_Bibliotheque B;
init(&B);
chargement(&B);

do
{
chx= menu();
switch(chx)
	{
	case 0 :
		sauvegarde(&B);
		break;

	case  1 : reponse = ajouterLivre(&B);
				if (reponse==1){
					printf(" ajout reussi !!");
					sauvegarde(&B);
				}else{
					printf("impossible d ajouter (bibliotheque pleine)");
				}
			break;
	case 2 : reponse=afficherBibliotheque(&B);
			if (reponse==0)
					printf("La bibliotheque est vide");

			break;
	case 3 : printf("Donnez le titre du livre que vous cherchez\n");
		lireChaine("titre",titreLivre,100);
		rechercherLivreTitre(&B, titreLivre);
		break;

	case 4 : printf("Donnez l'auteur du livre que vous cherchez\n");
		lireChaine("auteur",auteurLivre,100);
		rechercherLivreAuteur(&B, auteurLivre);
		break;

	case 5 : printf("Quel livre voulez vous supprimer\n");
		printf("Donnez le titre du livre que vous voulez supprimer\n");
		lireChaine("titre",titreLivre,100);
		printf("Donnez l'auteur du livre que vous voulez supprimer\n");
		lireChaine("auteur",auteurLivre,100);
		supprimerLivre(&B, auteurLivre, titreLivre);
		sauvegarde(&B);
		break;
	case 6: printf("Quel est le nom de l'emprunteur ?\n");
		lireChaine("emprunteur",nomEmprunteur,100);
		printf("Donnez le titre du livre que vous voulez emprunter\n");
		lireChaine("titre",titreLivre,100);
		printf("Donnez l'auteur du livre que vous voulez emprunter\n");
		lireChaine("auteur",auteurLivre,100);
		emprunterLivre(&B,titreLivre,auteurLivre,nomEmprunteur);
		break;
	case 7:
		printf("Donnez le titre du livre que vous voulez rendre\n");
		lireChaine("titre",titreLivre,100);
		printf("Donnez l'auteur du livre que vous voulez rendre\n");
		lireChaine("auteur",auteurLivre,100);
		//rendreLivre(&B,titreLivre,auteurLivre);
		break;
	case 8:
		triTitre(&B);
		break;
	case 9:
		triAuteur(&B);
		break;
	case 10:
		triAnnee(&B);
		break;
}

}while(chx!=0);






return 0;

}
