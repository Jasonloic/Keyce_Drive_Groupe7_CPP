    //Déclaration des variables membre 
#include <vector>
#include <filesystem>

class Drive {
private:
    pour stocker les supports externes détectés :
    std::vector<std::string> m_external_support; 
    //pour stocker le chemin du drive local :
    std::string m_local_path; 
    // Un vecteur pour stocker les fichiers éligibles pour la synchronisation
    std::vector<KFichier> files;
    // Le chemin du drive local
    std::filesystem::path localDrivePath;
    // Un vecteur pour stocker les supports externes détectés
    std::vector<std::filesystem::path> externalDrives;

public:
    // Les fonctions membres pour ajouter, supprimer et gérer les fichiers dans le vecteur de KFichier, ainsi que pour gérer les chemins de drive locaux et les supports externes détectés
};

        //Déclaration des function membres 

class Drive {
private:
    std::vector<KFichier> files;
    std::filesystem::path localDrivePath;
    std::vector<std::filesystem::path> externalDrives;

public:

class Drive {
    // Pour détecté un support externe 
public:
    void detect_external_support(); 
};

//pour ajouter un support externe détecté :
    void add_external_support(std::string support); 
    //définir le chemin du drive local :
    void set_local_path(std::string path); 
    // Ajouter un fichier au vecteur de fichiers
    void addFile(KFichier file);
    // Supprimer un fichier du vecteur de fichiers
    void removeFile(KFichier file);
    // Obtenir le chemin du drive local
    std::filesystem::path getLocalDrivePath();
    // Obtenir les supports externes détectés
    std::vector<std::filesystem::path> getExternalDrives();
};