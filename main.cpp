#include <iostream>
#include <string>
#include <fstream>

//Void pour afficher le nom de l'application
void afficheNom(){
    std::cout << "|––––––––––––––––––––––––––––––––––––|" << std::endl;
    std::cout << "|-----GESTRIONNAIRE DE STOCK---------|" << std::endl;
    std::cout << "|-----------BY ATHOHCK---------------|" << std::endl;
    std::cout << "|____________________________________|" << std::endl;
   
    
}

void menuChoix(){
    std::cout << " 1: Enregistrer un produit + stock dispo " << std::endl;
    std::cout << " 2: Consulter le stock disponibe " << std::endl;
    std::cout << " 3: Supprimer un produit " << std::endl;
    std::cout << " 4: Modifier la stock d'un produit " << std::endl;
    std::cout << " 5: Quitter " << std::endl;

}

//nP = nomProdsuit sP = stockProduit
void renseignementProduit(std::string &nP, double &sP){
    std::cout << " Entre le nom de ton produit : ";
    std::getline(std::cin, nP);
    std::cout << "\n";

    std::cout << " Entre le nombre de produit en stock disponible : ";
    std::cin >> sP;

    //gestion d'erreur pour le sP
    if (std::cin.fail())
    {
        std::cout << "❌ ERREUR : Ce n'est pas un nombre !\n";
        std::cin.clear();
        std::cin.ignore(10000, '\n');  // ← SIMPLE : vide 10000 caractères max
    }
      
}

// Void qui permet d'enregistrement du produit dans le Ofstream
void enregistrement(std::string nP, double sP){
    std::ofstream fichierSauvegarde ("stock.txt", std::ios::app);//Le fichier .txt senregistre dans le dossier du main.cpp

    if (fichierSauvegarde.is_open())
    {
        std::cout << " Ton produit : " << nP << " stock : " << sP << " Sont bien enregistrer ✅ " << std::endl;
        fichierSauvegarde << "|Produit : " << nP << " Stock : " << sP << " |" << std::endl; 
        fichierSauvegarde.close();
    }
    else{
        std::cout << " Erreur lors de la creation du fichier ❌ ";
    }
    
}

// Void qui permet d'afficher dans le terminal le stock disponnible 
void afficherStock() {
    std::ifstream fichierLecture("stock.txt");//Le fichier .txt est lue depuis le dossier du main.cpp
    
    if (fichierLecture.is_open()) {
        std::string ligne;
        
        std::cout << "\n=== STOCK DISPONIBLE ===\n";
        
        while (std::getline(fichierLecture, ligne)) {
            std::cout << ligne << std::endl;
        }
        
        fichierLecture.close();
    }
    else {
        std::cout << "❌ Erreur : Impossible d'ouvrir le fichier !\n";
    }
}

//Void qui permet de supprimer un produit du stock 
void supprimerUnProduit(std::string produitASupprimer){
    std::ifstream fichierASupprimer("stock.txt"); //Ouvrir et lire stock.txt
    std::ofstream nouveauFichier("temp.txt");    //Créé un fichier temporaire

    std::string ligne;  //Variable pour stocker une ligne

    while (std::getline(fichierASupprimer, ligne))  //Tant qu'il y a des lignes a lire 
    {   //Si la ligne ne continet pas le produit a supprimer
        if (ligne.find(produitASupprimer) == std::string::npos)
        {
            nouveauFichier << ligne << "\n"; // On la copie dans temp.txt

        }
        //Sinon on ne la copie pas on la supprime 
    }

    //On ferme les deux fichier ouvert 
    fichierASupprimer.close();
    nouveauFichier.close();

    //On supprime le (stock.txt) grace a remove
    remove("stock.txt");

    //On renome (temp.txt) ➡️ (stock.txt)
    rename("temp.txt", "stock.txt");
}

//Void qui permet de modifier la quantié d'un produit en stock
void modificationProduitStock(std::string produitAModifier, double nouvelleQuantite){
    std::ifstream lectureStock("stock.txt");    //Ouvrir et lire dans ("stock.txt")
    std::ofstream nouveauFichier("temp.txt");   //Cree un nouveau fichier ("temp.txt")

    std::string ligne; //Variable pour stocker une ligne

    while (std::getline(lectureStock, ligne))
    {
        if (ligne.find(produitAModifier) != std::string::npos)
        {   
            // SI ON TROUVE le produit
            // On RÉÉCRIT avec la NOUVELLE quantité
            nouveauFichier << "|Produit : " << produitAModifier << " Stock : " << nouvelleQuantite << "\n";
        }
        else 
        {
            // SI ON NE TROUVE PAS le produit
            // On COPIE la ligne d'origine (sans modification)
            nouveauFichier << ligne << "\n";
        }    
    }
        //On ferme les deux fichier avec le .close()
    lectureStock.close();
    nouveauFichier.close();
    //On supprime le (stock.txt) grace a remove
    remove("stock.txt");

    //On renome (temp.txt) ➡️ (stock.txt)
    rename("temp.txt", "stock.txt");
    
}

int main(){
    int choixPourMenu;
    std::string choixUtilisateur = " ";// Variable pour que l'utilisateur entre son nom de produit
    double stockUtilisateur;// stock pour que l'utilisateur entre son nombre de produit en stock

    //Affiche dans le terminal le nom de l'application
    afficheNom();
    std::cout << "\n";

    do
    {
        //Affiche le menuChoix
        menuChoix();
        std::cin >> choixPourMenu;
        std::cin.ignore();  // Vide le \n restant

        //Gestion d'erreur pour le choixPourMenu
        if (std::cin.fail())
        {
            std::cout << "❌ ERREUR : Ce n'est pas un nombre !\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');  // ← SIMPLE : vide 10000 caractères max
        }

        else if (choixPourMenu == 1)
        {
            renseignementProduit(choixUtilisateur, stockUtilisateur);
            enregistrement(choixUtilisateur, stockUtilisateur);
        }
        else if (choixPourMenu == 2)
        {
            afficherStock();
        }
        else if (choixPourMenu == 3) 
        {
            std::string produitASupprimer;  //Variable pour supprimer le stock de l'utilisateur 
            afficherStock(); //On affiche le stock afin que l'utilisateur vois sont stock
            std::cout << " Quel produit veux-tu supprimer ? (Entre le nom complet): ";
            std::getline(std::cin, produitASupprimer);

            supprimerUnProduit(produitASupprimer);
            
        }
        else if (choixPourMenu == 4)
        {
            std::string nomDuProduit;     //Variable pour modifier le stock de l'utilisateur 
            double nouvelleQuantite;
            afficherStock();    //On affiche le stock pour que l'utilisateur vois sont stock

            std::cout << " Entre le nom (Complet) de ton produit pour modifier le stock : ";
            std::getline(std::cin, nomDuProduit);
            std::cout << " Nouvelle quantite : ";
            std::cin >> nouvelleQuantite;

            modificationProduitStock(nomDuProduit, nouvelleQuantite);   //Appelle de la fonction pour modifier le stock





        }
        else if (choixPourMenu == 5)
        {
            std::cout << "Au revoir " << std::endl;
        }
        
        else {
            std::cout << "❌ Choix invalide !\n";
        }
        

        
    } while (choixPourMenu != 5);


    return 0;
}