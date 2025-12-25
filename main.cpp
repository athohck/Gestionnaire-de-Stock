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
        else if (choixPourMenu == 3) {
            std::cout << " Au revoir\n";
        }
        else {
            std::cout << "❌ Choix invalide !\n";
        }
        

        
    } while (choixPourMenu != 3);






    
    

    
    
















    return 0;
}