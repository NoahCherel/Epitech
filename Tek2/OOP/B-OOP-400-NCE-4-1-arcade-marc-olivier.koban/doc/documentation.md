**Documentation du projet Arcade**

## Jeux implémentés:
    - Snake
    - Nibbler

## Snake
# Description
Le jeu Snake est un jeu de serpent qui se déplace sur une grille. Le but du jeu est de manger des pommes pour grandir et éviter de se mordre la queue. Le serpent se déplace en continu et le joueur peut changer de direction à tout moment. Le jeu se termine lorsque le serpent se mord la queue ou touche un mur.

# Nibbler
# Description
Le jeu Nibbler est un jeu de serpent qui se déplace sur une grille. Le but du jeu est de manger des pommes pour grandir et éviter de se mordre la queue. Le serpent se déplace en continu et le joueur peut changer de direction à tout moment. Le jeu se termine lorsque le serpent se mord la queue ou touche un mur.

## Commandes
- Flèches directionnelles : changer de direction
- F1 : Passer a la lib d'avant
- F2 : Passer a la lib d'après
- F3 : Passer au jeu d'avant
- F4 : Passer au jeu d'après
- R : recommencer une partie
- ESC : quitter le jeu
- Entrée : recommencer une partie

## Librairies graphiques implémentées:
- SDL2
- SFML
- NCURSES

## Compilation
- make re
- make clean
- make fclean

## Exécution
- ./arcade lib/lib_arcade_sdl2.so

## Auteurs
- Marc-Olivier Koban
- Noah Cherel
- Nathan Tranchant

## Groupe avec qui nous avons partagé nos interfaces
- Romain Oeil

## Interface des jeux
```cpp
class IGame {
    public:
        virtual ~IGame() = default;                                          // Destructeur virtuel
        virtual std::string getName() = 0;                                   // Retourne le nom du jeu (Snake, Nibbler, ...)
        virtual void init() = 0;                                             // Initialise le jeu (la map, le snake, le nibbler, verifie si la map est valide, ...)
        virtual int stop() = 0;                                              // Stop le jeu (libère les ressources, ...)
        virtual bool isRunning() = 0;                                        // Retourne true si le jeu est en cours, false sinon
        virtual void endGame() = 0;                                          // Termine le jeu en mettant isRunning à false
        virtual std::vector<std::string> handleEvent(std::string event) = 0; // Gère les évènements (flèches directionnelles, ESC, R, ...)
        virtual std::string getMap() = 0;                                    // Retourne la map du jeu sous forme de string
    protected:
    private:
};
```

## Interface des librairies graphiques
```cpp
class ILibrary {
    public:
        ILibrary() = default;                                               // Constructeur par défaut
        virtual ~ILibrary() = default;                                      // Destructeur virtuel
        virtual std::string getName() = 0;                                  // Retourne le nom de la librairie (SDL2, SFML, NCURSES, ...)
        virtual void init() = 0;                                            // Initialise la librairie (crée la fenêtre, ...)
        virtual void stop() = 0;                                            // Stop la librairie (libère les ressources, ...)
        virtual void clear() = 0;                                           // Efface la fenêtre (la map) en mettant tout en noir (ou blanc)
        virtual void display(std::string map) = 0;                          // Affiche la map
        virtual std::string getEvent() = 0;                                 // Retourne l'évènement (flèches directionnelles, ESC, R, ...)
    protected:
    private:
};
```

# Interface du core
```cpp
class ICore {
        public:
            virtual ~ICore() = default;                                         // Destructeur virtuel
            virtual void init() = 0;                                            // Initialise le core (charge les librairies, ...)
            virtual void stop() = 0;                                            // Stop le core (libère les ressources, ...)
            virtual void run() = 0;                                             // Lance le core (boucle infinie)
            virtual void setGame(std::string game) = 0;                         // Change le jeu courant
            virtual void setLibrary(std::string library) = 0;                   // Change la librairie courante
            virtual std::vector<std::string> getGames() = 0;                    // Retourne la liste des jeux
            virtual std::vector<std::string> getLibraries() = 0;                // Retourne la liste des librairies
        protected:
        private:
    };
```
