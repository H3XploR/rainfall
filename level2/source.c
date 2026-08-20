/*
 * source.c — Reconstruction du binaire du level 2 (Rainfall / 42)
 *
 * ATTENTION : ce fichier n'est PAS le code source d'origine.
 * C'est une lecture fidèle du code machine (objdump -d), reformulée en C
 * pour que n'importe quel dev comprenne ce que fait le binaire.
 *
 * Ce que fait le niveau :
 *   p() lit une ligne depuis stdin dans un tampon fixe avec gets() (SANS
 *   limite -> buffer overflow possible), puis teste les 4 octets qui se
 *   trouvent APRÈS le tampon sur la pile — c'est-à-dire l'adresse de
 *   retour sauvegardée de p() — contre un "nombre magique".
 *   Si (retour & 0xb0000000) == 0xb0000000, il affiche la valeur et quitte.
 *
 * Layout de la pile (de la basse vers la haute adresse) :
 *   [ebp - 0x4c]  buffer[76]            <-- gets() écrit ici (0x4c = 76 octets)
 *   [ebp]         saved ebp
 *   [ebp + 0x4]   saved eip  <-- C'EST l'objectif de l'overflow
 *
 * Le check "nombre magique" : (valeur & 0xb0000000) == 0xb0000000
 *   -> le byte haute de l'adresse doit être dans [0xB0..0xBF].
 *   -> En clair : tu dois réussir à ré-écrire l'adresse de retour avec une
 *      valeur dont le plus grand octet a ce bit-pattern (0b1011xxxx).
 */

#include <stdio.h>
#include <stdlib.h>   /* strdup (chemin d'échec) */
#include <unistd.h>   /* _exit */

void p(void)
{
    char buffer[76];                 /* [ebp-0x4c] .. [ebp-1]  (76 octets)      */

    fflush(stdout);                  /* vide le buffer stdout                   */
    gets(buffer);                    /* lit une ligne, SANS borne -> overflow   */

    /* Lit les 4 octets à [ebp+0x4], i.e. l'adresse de retour sauvegardée de p().
       C'est exactement l'emplacement qu'un gets() suffisamment long a écrasé
       (80 octets plus loin que le début du buffer). En C "propre" on ne ferait
       pas ça ; le binaire, lui, lit cette case pile.                            */
    unsigned int magique = *(unsigned int *)(buffer + 80);

    if ((magique & 0xb0000000) != 0xb0000000)
    {                                /* --- chemin ÉCHEC (pas le bon pattern) -- */
        puts(buffer);                /* affiche le contenu du buffer (gribouillis) */
        (void)strdup(buffer);        /* alloue une copie (laissé en l'air, sans-op)  */
        /* retombe sur l'épilogue : ret -> retourne chez main() */
        return;
    }

    /* --- chemin RÉUSSITE (nombre magique présent dans l'adresse de retour) --- */
    printf("(%p)\n", (void *)magique);   /* affiche ex. (0xb0000000)             */
    _exit(1);                            /* quitte immédiatement avec le code 1   */
}

int main(void)
{
    p();
    return 0;
}
