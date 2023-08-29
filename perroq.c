#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "perroq.h"


//Enregistrer le peroquet dans un fichier perof.def
void enreg_perroquet(const char *perroquet)
{
    FILE *perroquet_file = fopen("peroq.def", "w+t");
    if (perroquet_file == NULL)
    {
        printf("Erreur pour ecrire dans ce fichier");
        return;
    }
    fputs(perroquet, perroquet_file);
    fclose(perroquet_file);

    printf("Bien enregistré\n");
}

// fontion loadPerroquet Cette fonction est responsable du chargement du perroquet à partir du fichier "peroq.def" dans le tableau de caractères perroquet

void loadPerroquet(char *perroquet, int long_max)

{
    FILE *perroquet_file = fopen("peroq.def.txt", "rt");
    if (perroquet_file == NULL)
    {
        printf("Erreur lors de l'ouverture du fichier");
        return EXIT_FAILURE;
    }

    fread(perroquet, sizeof(char), long_max -1 , perroquet_file);
    perroquet[long_max - 1] = '\0'; // ON s'assure que  la chaine est bien terminé
    fclose(perroquet_file);
}



// fonction qui chiffre un texte en fonctio d'un mot perroquet qui lui ai foruni



void chiffr_text(char *text, const char *perroquet)

{
    int text_long = strlen(text);
    int perroquet_long = strlen(perroquet);

    for (int i = 0; i < text_long; i++)
    {
        char chiffr_char = text[i] - perroquet[i % perroquet_long] + 'a'; // a pour qu'il revienne sur la plage ascii
        putchar(chiffr_char);
    }
}



// Fonction pour chiffrer le fichier source et écrire le texte chiffré dans dest.crt
int chiffr_file(const char *perroquet, const char *source_name, const char *dest_name)
{
    char source_text[1000];

    printf("Entrez votre perroquet : ");
    fgets(perroquet, sizeof(perroquet), stdin);
    enreg_perroquet(perroquet);

    //sloadPerroquet(perroquet, sizeof(perroquet));

    FILE *source_file = fopen(source_name, "rt");
    if (source_file == NULL)
    {
        printf("Erreur");
        return 0;
    }
    if (fgets(source_text, sizeof(source_text), source_file) == NULL)

    {
        printf("Erreur lors de la lecture du fichier source");
        fclose(source_file);
        return 0;
    }
    fclose(source_file);

    chiffr_text(source_text, perroquet);

    FILE *dest_file = fopen(dest_name, "w+t");
    if (dest_file == NULL) {
        perror("Impossible d'écrire dans le fichier dest_name");
        return 0;
    }
    fputs(source_text, dest_file);
    fclose(dest_file);

    supp_file(source_name);

    printf("Le texte encrypt se trouve dans dest.crt\n");

    return 1;
}








// La fonction supprime le fichier source après que le texte ait été chiffré
void supp_file(const char *source_name)
{
    //const char *source_name = "source.txt";

    if (remove(source_name) != 0) {
        perror("Erreur lors de la suppression du fichier source");
    } else {
        printf("Le fichier source est supprimé.\n");
    }
}
