# 📦 Gestionnaire de Stock en C++

Un gestionnaire de stock simple et efficace en ligne de commande développé en C++.

## 📋 Description

Ce programme permet de gérer un inventaire de produits avec leur quantité en stock. Idéal pour les petites entreprises ou les gestionnaires qui ont besoin d'un outil simple et rapide.

## ✨ Fonctionnalités

- ➕ **Enregistrer un produit** : Ajouter un nouveau produit avec sa quantité en stock
- 📊 **Consulter le stock** : Afficher tous les produits enregistrés
- 💾 **Sauvegarde automatique** : Les données sont sauvegardées dans un fichier texte
- ⚠️ **Gestion d'erreurs** : Validation des entrées utilisateur

## 🛠️ Technologies utilisées

- **Langage** : C++
- **Concepts** : Fonctions, fichiers (ifstream/ofstream), gestion d'erreurs, boucles
- **Bibliothèques** : iostream, string, fstream

## 📦 Installation et Compilation

### Prérequis
- Un compilateur C++ (g++, clang++, ou MSVC)
- macOS, Linux ou Windows

### Compilation

**Sur macOS/Linux :**
```bash
g++ -std=c++11 main.cpp -o gestion_stock
./gestion_stock
```

**Sur Windows :**
```bash
g++ -std=c++11 main.cpp -o gestion_stock.exe
gestion_stock.exe
```

## 🎯 Comment utiliser

1. Lancez le programme
2. Choisissez une option dans le menu :
   - **1** : Enregistrer un nouveau produit
   - **2** : Consulter le stock actuel
   - **3** : Quitter le programme
3. Les données sont sauvegardées dans `stock.txt`

## 🎥 Exemple d'utilisation
```
|––––––––––––––––––––––––––––––––––––|
|-----GESTIONNAIRE DE STOCK---------|
|-----------BY ATHOHCK---------------|
|____________________________________|

 1: Enregistrer un produit + stock dispo 
 2: Consulter le stock disponible
> 1

 Entre le nom de ton produit : Burger
 Entre le nombre de produit en stock disponible : 50

 Ton produit : Burger stock : 50 Sont bien enregistré ✅
```

## 🚀 Améliorations futures

- [ ] Supprimer un produit
- [ ] Modifier la quantité en stock
- [ ] Rechercher un produit spécifique
- [ ] Alertes pour stock faible
- [ ] 
## 👨‍💻 Auteur

**athohck** - Projet d'apprentissage C++ (Décembre 2025)

## 📝 Licence

Ce projet est libre d'utilisation à des fins éducatives.

---

⭐ N'hésitez pas à laisser une étoile si ce projet vous plaît !
