#include <stdio.h>
#include <stdlib.h>

// Structure pour représenter une tâche
typedef struct {
    int id;
    char titre[100];
    char description[200];
    char deadline[20];
    char statut[30];
} Tache;

// Fonction pour ajouter une nouvelle tâche
void ajouterTache(Tache* taches, int* nbTaches) {
    // Vérifier si le nombre de tâches atteint la limite
    if (*nbTaches >= 100) {
        printf("La liste de tâches est pleine. Impossible d'ajouter une nouvelle tâche.\n");
        return;
    }
    
    // Demander les informations de la nouvelle tâche à l'utilisateur
    Tache nouvelleTache;
    printf("Identifiant de la tâche : ");
    scanf("%d", &nouvelleTache.id);
    printf("Titre de la tâche : ");
    scanf(" %[^\n]s", nouvelleTache.titre);
    printf("Description de la tâche : ");
    scanf(" %[^\n]s", nouvelleTache.description);
    printf("Deadline de la tâche : ");
    scanf(" %[^\n]s", nouvelleTache.deadline);
    printf("Statut de la tâche : ");
    scanf(" %[^\n]s", nouvelleTache.statut);
    
    // Ajouter la nouvelle tâche à la liste
    taches[*nbTaches] = nouvelleTache;
    (*nbTaches)++;
    
    printf("La tâche a été ajoutée avec succès.\n");
}

// Fonction pour afficher la liste de toutes les tâches
void afficherTaches(Tache* taches, int nbTaches) {
    printf("Liste de toutes les tâches :\n");
    printf("Identifiant | Titre | Description | Deadline | Statut\n");
    for (int i = 0; i < nbTaches; i++) {
        printf("%d | %s | %s | %s | %s\n", taches[i].id, taches[i].titre, taches[i].description, taches[i].deadline, taches[i].statut);
    }
}

// Fonction principale
int main() {
    Tache taches[100];
    int nbTaches = 0;
    int choix;
    
    do {
        printf("\nMenu principal :\n");
        printf("1. Ajouter une nouvelle tâche\n");
        printf("2. Afficher la liste de toutes les tâches\n");
        printf("0. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);
        
        switch (choix) {
            case 1:
                ajouterTache(taches, &nbTaches);
                break;
            case 2:
                afficherTaches(taches, nbTaches);
                break;
            case 0:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
                break;
        }
    } while (choix != 0);
    
    return 0;
}
