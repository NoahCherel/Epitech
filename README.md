# Epitech Projects

## Description
Ce dépôt contient l'ensemble de mes projets réalisés durant mes études à **Epitech**, une école spécialisée dans l'informatique et les nouvelles technologies. Ces projets couvrent une grande variété de langages et de concepts, reflétant le programme intensif et diversifié d'Epitech.

Chaque dossier représente un projet spécifique, accompagné de son code source, ses objectifs pédagogiques et, dans certains cas, d'une documentation supplémentaire.

## Langages utilisés
Ce dépôt met en avant une diversité de langages et de technologies utilisés dans le cadre des projets :
- **C** (37.7%) : Langage principal pour les projets système et bas niveau.
- **JavaScript** (21.8%) : Utilisé pour les projets web et Node.js.
- **C++** (21.4%) : Pour les projets orientés objets et les programmes complexes.
- **Python** (8.2%) : Pour les scripts, l'automatisation et les projets IA.
- **Haskell** (6.7%) : Pour les projets fonctionnels.
- **Makefile** (2.2%) : Pour la gestion des builds de projets.
- **Autres** (2%) : Divers outils et langages additionnels.

## Table des matières
1. [Organisation du dépôt](#organisation-du-dépôt)
2. [Installation et Configuration](#installation-et-configuration)
3. [Exemples de projets notables](#exemples-de-projets-notables)

## Organisation du dépôt
Le dépôt est organisé en plusieurs dossiers, chacun représentant un projet distinct. Voici un aperçu général :

Epitech/
│
├── Tek1/ # Projets de première année │ 
├── my_printf/ # Implémentation de printf en C │ 
├── palindromes/ # Vérification et génération de palindromes │
└── ...
│ 
├── Tek2/ # Projets de deuxième année │
├── zappy/ # Jeu en réseau multijoueur │ 
├── pushswap/ # Algorithme de tri │
└── ...
│ 
├── Tek3/ # Projets de troisième année │ 
├── arcade/ # Framework pour jeux rétro │ 
├── plazza/ # Simulation de gestion de commandes │
└── ...
│
├── B4/ # Projets de quatrième année │
├── AI/ # Projets liés à l'intelligence artificielle │
├── web/ # Applications web complexes 
│ 
└── ...
│
└── misc/ # Projets divers ou indépendants

Chaque dossier contient :
- **Code source** : Les fichiers `.c`, `.cpp`, `.py`, etc.
- **Documentation** : Des fichiers `README.md` locaux ou des commentaires dans le code.
- **Fichiers Makefile** : Pour compiler les projets en C/C++.

## Installation et Configuration
1. Clonez ce dépôt :
   ```bash
   git clone https://github.com/NoahCherel/Epitech.git
   cd Epitech

    Si un projet nécessite des dépendances spécifiques, consultez le fichier README.md ou les instructions dans le dossier du projet concerné.
   ````

    Pour compiler un projet en C/C++, utilisez les commandes Makefile :
    ```bash
    make
    ./executable
    ```

## Exemples de projets notables
1. My_printf (B1)

    Langage : C
    Description : Réimplémentation de la fonction standard printf en C.
    Points clés :
        Gestion de divers formats (%d, %s, %x, etc.).
        Approfondissement des notions de pointeurs et de buffers.

2. Arcade (B3)

    Langage : C++
    Description : Framework permettant de créer et exécuter des jeux rétro avec des interfaces interchangeables.
    Points clés :
        Utilisation de bibliothèques graphiques (SFML, SDL, NCurses).
        Conception modulaire et extensible.

3. Zappy (B2)

    Langage : C
    Description : Jeu en réseau multijoueur simulant une gestion de ressources.
    Points clés :
        Programmation réseau avec sockets.
        Synchronisation entre clients et serveur.

4. AI Projects (B4)

    Langage : Python
    Description : Divers projets explorant les concepts d'intelligence artificielle, comme les algorithmes de recherche et les réseaux neuronaux.
    Points clés :
        Implémentation d'algorithmes comme A* ou Minimax.
        Utilisation de bibliothèques comme NumPy.
