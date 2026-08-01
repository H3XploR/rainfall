#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // Contient la fonction isprint()

#define MIN_STRING_LEN 4 // Longueur minimale pour être considérée comme une string

int main(int argc, char *argv[]) {
    // 1. Vérifier si l'utilisateur a bien passé un fichier en argument
    if (argc != 2) {
        printf("Utilisation : %s <nom_du_fichier>\n", argv[0]);
        return 1;
    }

    // 2. Ouvrir le fichier en mode "Read Binary" (rb)
    FILE *file = fopen(argv[1], "rb");
    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return 1;
    }

    int c;
    char buffer[1024]; // Un buffer pour stocker la string en cours de lecture
    int length = 0;    // Compteur de la longueur de la string

    // 3. Lire le fichier octet par octet jusqu'à la fin (EOF = End Of File)
    while ((c = fgetc(file)) != EOF) {
        
        // 4. isprint() vérifie si le caractère est lisible (ASCII 32 à 126)
        // On accepte aussi les tabulations ('\t')
        if (isprint(c) || c == '\t') {
            // On ajoute le caractère au buffer (en évitant de le déborder)
            if (length < sizeof(buffer) - 1) {
                buffer[length] = c;
                length++;
            }
        } else {
            // Si on tombe sur un caractère non lisible (comme du code machine),
            // on vérifie si ce qu'on a accumulé avant est assez long.
            if (length >= MIN_STRING_LEN) {
                buffer[length] = '\0'; // On termine proprement la string
                printf("%s\n", buffer); // On l'affiche
            }
            // On remet le compteur à zéro pour chercher la string suivante
            length = 0; 
        }
    }

    // 5. Gérer le cas où le fichier se termine pile sur une string
    if (length >= MIN_STRING_LEN) {
        buffer[length] = '\0';
        printf("%s\n", buffer);
    }

    // 6. Toujours fermer le fichier proprement
    fclose(file);
    return 0;
}
