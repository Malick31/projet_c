#include <stdio.h>
#include "choix.h"
#include <stdio.h>
#include <string.h>
#include "perroq.h"
#include <stdlib.h>

void Menu()

{
    int choix;
    char perroquet[256];
    char source_name[] = "source.txt";
    char dest_name[] = "dest.crt";

    printf("Entrez votre perroquet : ");
    fgets(perroquet, sizeof(perroquet), stdin);
    //perroquet[strcspn(perroquet, "\n")] = '\0';
    enreg_perroquet(perroquet);

    loadPerroquet(perroquet, sizeof(perroquet));

    do
    {
        printf("\nMenu:\n");
        printf("1. Chiffrer le fichier source\n");
        printf("2. Supprimer le fichier source\n");
        printf("3. Quitter\n");
        printf("Choix : ");
        scanf("%d", &choix);

        switch (choix)
        {
            case 1:

                chiffr_file(perroquet, source_name, dest_name);
                break;
            case 2:
                supp_file(source_name);
                break;
            case 3:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide. Essayez à nouveau.\n");
        }
    } while (choix != 3);
}
