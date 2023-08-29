



// fontion loadPerroquet Cette fonction est responsable du chargement du perroquet � partir du fichier "peroq.def" dans le tableau de caract�res perroquet

void loadPerroquet(char *perroquet, int long_max)

{
    FILE *perroquet_file = fopen("peroq.def", "rt");
    if (perroquet_file == NULL)
    {
        printf("Erreur lors de l'ouverture du fichier");
        return EXIT_FAILURE;
    }

    fread(perroquet, sizeof(char), long_max -1 , perroquet_file);
    perroquet[long_max - 1] = '\0'; // ON s'assure que  la chaine est bien termin�
    fclose(perroquet_file);
}













// La fonction supprime le fichier source apr�s que le texte ait �t� chiffr�
void supp_source()
{
    const char *source_name = "source.txt";

    if (remove(source_name) != 0) {
        perror("Erreur lors de la suppression du fichier source");
    } else {
        printf("Fichier source supprim� avec succ�s.\n");
    }
}
