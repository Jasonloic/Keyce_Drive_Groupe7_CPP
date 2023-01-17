#include <cstdio>

/*
 * Function to copy binary file
 * @param source_file: path to the source file
 * @param dest_file: path to the destination file
 * @return true if the copy was successful, false otherwise
 */
bool copy_binary_file(const char* source_file, const char* dest_file) {
    // Open the source file in binary read mode
    FILE* src = fopen(source_file, "rb");
    // Check if the file was opened successfully
    if (!src) {
        printf("Failed to open source file: %s\n", source_file);
        return false;
    }

    // Open the destination file in binary write mode
    FILE* dst = fopen(dest_file, "wb");
    // Check if the file was opened successfully
    if (!dst) {
        printf("Failed to open destination file: %s\n", dest_file);
        // Close the source file if opening the destination file failed
        fclose(src);
        return false;
    }

    // Buffer to hold data while reading and writing
    const size_t buffer_size = 4096;
    char buffer[buffer_size];
    // Number of bytes read from the source file
    size_t bytes_read = 0;
    // Loop until all data is read from the source file
    while ((bytes_read = fread(buffer, 1, buffer_size, src)) > 0) {
        // Write the data from the buffer to the destination file
        fwrite(buffer, 1, bytes_read, dst);
    }

    // Close the source and destination files
    fclose(src);
    fclose(dst);

    return true;
}


/*Ce code utilise la fonction fopen() pour ouvrir les fichiers source et de destination en mode binaire, en utilisant "rb" pour lire le fichier source et "wb" pour écrire le fichier de destination. Il utilise également la fonction fread() pour lire les données du fichier source par blocs de taille buffer_size et la fonction fwrite() pour écrire ces données dans le fichier de destination. Enfin, il utilise les fonctions fclose() pour fermer les fichiers source et de destination après la fin de la copie. Si l'ouverture d'un des fichiers échoue, il affiche un message d'erreur et retourne false. Sinon, il retourne true une fois la copie terminée.*/


#include <cstdio>

/*
 * Fonction pour copier un fichier binaire
 * @param source_file: chemin du fichier source
 * @param dest_file: chemin du fichier de destination
 * @return true si la copie a réussi, false sinon
 */
bool copier_fichier_binaire(const char* source_file, const char* dest_file) {
    // Ouvrir le fichier source en mode lecture binaire
    FILE* src = fopen(source_file, "rb");
    // Vérifier si le fichier a été ouvert avec succès
    if (!src) {
        printf("Impossible d'ouvrir le fichier source: %s\n", source_file);
        return false;
    }

    // Ouvrir le fichier de destination en mode écriture binaire
    FILE* dst = fopen(dest_file, "wb");
    // Vérifier si le fichier a été ouvert avec succès
    if (!dst) {
        printf("Impossible d'ouvrir le fichier de destination: %s\n", dest_file);
        // Fermer le fichier source si l'ouverture du fichier de destination a échoué
        fclose(src);
        return false;
    }

    // Tampon pour stocker les données lors de la lecture et de l'écriture
    const size_t buffer_size = 4096;
    char buffer[buffer_size];
    // Nombre d'octets lus depuis le fichier source
    size_t bytes_read = 0;
    // Boucle jusqu'à ce que toutes les données soient lues depuis le fichier source
    while ((bytes_read = fread(buffer, 1, buffer_size, src)) > 0) {
        // Écrire les données du tampon dans le fichier de destination
        fwrite(buffer, 1, bytes_read, dst);
    }

    // Fermer les fichiers source et de destination
    fclose(src);
    fclose(dst);

    return true;
}

