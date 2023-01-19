#include <iostream>
#include <fstream>

/*
 * Fonction pour copier un fichier binaire
 * @param source_file: chemin vers le fichier source
 * @param dest_file: chemin vers le fichier de destination
 * @return true si la copie a réussi, false sinon
 */
bool copy_binary_file(const std::string& source_file, const std::string& dest_file) {
    // Ouvre le fichier source en mode lecture binaire
    std::ifstream src(source_file, std::ios::binary);
    // Vérifie si l'ouverture du fichier a réussi
    if (!src) {
        std::cout << "Impossible d'ouvrir le fichier source: " << source_file << std::endl;
        return false;
    }

    // Ouvre le fichier de destination en mode écriture binaire
    std::ofstream dst(dest_file, std::ios::binary);
    // Vérifie si l'ouverture du fichier a réussi
    if (!dst) {
        std::cout << "Impossible d'ouvrir le fichier de destination: " << dest_file << std::endl;
        // Ferme le fichier source si l'ouverture du fichier de destination a échoué
        src.close();
        return false;
    }

    // Tampon pour stocker les données lors de la lecture et de l'écriture
    constexpr size_t buffer_size = 4096;
    char buffer[buffer_size];

    // Boucle jusqu'à ce que toutes les données soient lues depuis le fichier source
    while (src.read(buffer, buffer_size)) {
        // Ecrit les données du tampon dans le fichier de destination
        dst.write(buffer, src.gcount());
    }

    // Ferme les fichiers source et de destination
    src.close();
    dst.close();

    return true;
}
