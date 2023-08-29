



// fontion loadPerroquet Cette fonction est responsable du chargement du perroquet à partir du fichier "peroq.def" dans le tableau de caractères perroquet

void loadPerroquet(char *perroquet, int long_max)

{
    FILE *perroquet_file = fopen("peroq.def", "rt");
    if (perroquet_file == NULL)
    {
        printf("Erreur lors de l'ouverture du fichier");
        return EXIT_FAILURE;
    }

    fread(perroquet, sizeof(char), long_max -1 , perroquet_file);
    perroquet[long_max - 1] = '\0'; // ON s'assure que  la chaine est bien terminé
    fclose(perroquet_file);
}













// La fonction supprime le fichier source après que le texte ait été chiffré
void supp_source()
{
    const char *source_name = "source.txt";

    if (remove(source_name) != 0) {
        perror("Erreur lors de la suppression du fichier source");
    } else {
        printf("Fichier source supprimé avec succès.\n");
    }
}
