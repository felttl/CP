// ma boite a outils 
#include <stdlib.h>
#include <stdio.h>
typedef enum bool{true, false} bool ; // boolean type as simple usage



/**         Enoncé
 *  
 *  Scénario : Imaginez que vous travaillez sur un gestionnaire 
 * de tâches. Les utilisateurs peuvent ajouter des tâches à 
 * faire et gérer ces tâches. Chaque tâche a un nom, une 
 * description et une priorité. Vous devez implémenter la 
 * gestion de la mémoire pour stocker ces tâches en
 *  utilisant l'allocation dynamique.
 * 
 * obligations :
 * 
 * allocation dynamique
 * stucture
 * fichiers
 * 
*/

#define DEFAULT_FILENAME "save.txt"

typedef struct Task{
    char nom[25];
    char description[40];
    int priorite;
} Task;

/* func -> err

    ajoute une tache dans une liste appelée "conteneur" à la fin de celle-ci
*/
int ajouterTache(Task * ListeConteneur, Task tache){
    int erreur = 0;
    int listetaille = (sizeof(ListeConteneur) / sizeof(ListeConteneur[0]));
    printf("verification taille d'une valeur : %d", sizeof(ListeConteneur[0])); // petite verif
    // réajustement de la taille pour ajouter une valeur dedans    
    ListeConteneur = (Task*) realloc (ListeConteneur, ++listetaille * sizeof(Task));
    // on rajoute la tache au nouvel emplacement

    ListeConteneur[listetaille] = tache;
    return erreur;
}

int afficheTask(Task * conteneur, int index){
    int res = -1; // pas trouvé si -1 == res
    int size = sizeof(conteneur) / sizeof(conteneur[0]);
    if (index < -2 || index >= size){
        printf("l'index recherche n'est pas valide");
        res = -1; 
    } else {
        for (int i=0; i<size; i++){
            if (index == i || index == -2){ // si ça vaut -2 on affiche tout
                printf("index : %d", i);
                printf("nom : %s", conteneur[index].nom);
                printf("description : \n%s", conteneur[index].description);
                printf("proporté : %d", conteneur[index].priorite);
                res = 0;
            }
        }        
    }
    return res;
}

char Menu(){
	char res;
	printf("\n");
	printf("┌─────────── Menu ───────────┐\n");
	printf("│ s : enregistrer & quitter  │\n");
	printf("│   c : créer une nouvelle   │\n");
    printf("│       tache                │\n");	
	printf("│   d : supprimer une tache  │\n");	
	printf("│   a : afficher les taches  │\n");	 
	printf("│     : continuer (faire     │\n");	 
	printf("│       un espace vide)      │\n");
	printf("│   m : modifier une taches  │\n");	     	            	
	printf("└────────────────────────────┘\n");
	printf("- - - - - - - - - - - - - - - \n");  
	printf("  !!!     Attention    !!!    \n");      
 	printf("   le nom doit contenir 25    \n"); 
 	printf("   charctère max et 40 pour   \n");     
 	printf("   la description             \n"); 
 	printf("______________________________\n\n");     
	printf("→");
    // pourquoi le scan est effectué avant les printfs ?
	scanf("%c", &res); // on sait pas si saisie user il y a déja une valeur dedans
	return res; 
}



// procédure par défault
    /**
     * mod :
     *      - a : ajouter a la fin d'un fichier même s'il n'existe pas (il sera créé)
     *      - a+ : ajouter 
     *      - w : écrire
     *      - w+ : écraser si existant puis écrire
     *      - r : lire
    */
    int sauvegarde(char*filename, char*data, char mod){
        FILE *fp;
        fp = fopen(filename, mod);
        if(fp == NULL){
            /* File not created hence exit */
            printf("can't create /edditing file at file : (%s)\n", filename);
            exit(EXIT_FAILURE);
        }
        fputs(data, fp);
        fclose(fp);
        return EXIT_SUCCESS;
    }

    /** 
     * lis un fichier de données avec les taches dedans sous forme de liste exemple :
     * 0 nom:".....etc...", task:".........commentaire...."
     * 1 ... etc....
     * 
    */
    int chargement(char*filepath,int line_num,char* getLine){
        int res = 0;
        // on écrit durectement la donnée brute dans le fichier de sauvegarde 
        // on retranscrit en c avec des chaines
        ///////////////////////////////
        int linen = 0;
        FILE * file;
        char displayText[100];
        bool carry = true;
        file = fopen(filepath, "r");
        if(file == NULL){
            printf("echec ouverture du fichier : %s\n", filepath);
        }
        // parcours des lignes
        while(!feof(file) && carry == true){
            fgets(displayText, 100, file); // récupère une ligne de 100 charactère
            // afichage si vrai :
            if (linen == line_num){
                printf("%s\n", displayText);
                strcpy(getLine, displayText);
                line_num = linen;
                carry = false;
            }
            linen++;
        }
        fclose(file);






        ///////////////////////////////
        printf((res == 0) ? "chargement réussi" : "chargement échoué");
        return res;



    }



int main(){
    // liste de taches pour le stockage
    Task * ListeTaches;
    // allocation dynamique (amplecement d'une seule tache par défaut vide)
    ListeTaches = (Task*) malloc (sizeof(Task));

    bool carry = true;
    char reponse;
    char contenu;
    printf("bienvenu dans le gestionnaire de taches !\n");
    while (carry == true){
        getchar();
        reponse = Menu();
        switch (reponse){
            case 's':
                // sauvegarde
                // quitte
                carry = false;
                break; // je déteste les break -_-
            case 'c':
                // create
                
                break;
            case 'd':
                // supprimer une tache (les afficher avant)
                break;
            case 'a':
                // afficher les taches uniquement
                afficheTask(ListeTaches, -2);
                break;
            
            
        default: // espace
            break;
        }
    }
    printf("merci d'avoir utilise notre systeme de taches\na bientot...\n\n");


    free(ListeTaches);
    return 0;
}



// run : sh ./comp*sh ./prog*c 
// end page