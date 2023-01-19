//implementation des function membre
#include "drive.h"

void 
Drive::detect_external_support() { 
// Code pour détecter les supports externes
// Ajoutez chaque support détecté à la variable membre m_external_support
add_external_support("Support 1");
add_external_support("Support 2");
}

void Drive::add_external_support(std::string support) {
    m_external_support.push_back(support);
}

//définir le chemin du drive local :
void Drive::set_local_path(std::string path) {
    m_local_path = path;
}

// Ajouter un fichier au vecteur de fichiers
void Drive::addFile(KFichier file) {
    files.push_back(file);
}

// Supprimer un fichier du vecteur de fichiers
void Drive::removeFile(KFichier file) {
    files.erase(std::remove(files.begin(), files.end(), file), files.end());
}

void Drive::detect_external_support() {
    // Boucle sur les lecteurs de l'ordinateur
    for (auto& p : std::filesystem::directory_iterator("/")) {
        if (p.is_directory()) {
            auto path = p.path();
            // Vérifie s'il y a un dossier keyce_drive sur le lecteur
            auto keyce_drive_path = path / "keyce_drive";
            if (std::filesystem::exists(keyce_drive_path)) {
                // Ajout du support externe détecté au vecteur externalDrives
                externalDrives.push_back(path);
            }
        }
    }
}

// Obtenir le chemin du drive local
std::filesystem::path Drive::getLocalDrivePath() {
    return localDrivePath;
}

// Obtenir les supports externes détectés
std::vector<std::filesystem::path> Drive::getExternalDrives() {
    return externalDrives;
}
