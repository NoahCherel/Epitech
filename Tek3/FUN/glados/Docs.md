Langage de programmation : Haskell
Projet : GlaDOS

## Description

Le but de ce projet est de créer un interpréteur Lisp en Haskell avec les fonctionnalités suivantes :

## Fonctionnalités

-   [x] Interpréteur Lisp
-   [x] Gestion des erreurs
-   [x] Compilateur
-   [x] Machine virtuelle

## Utilisation

Pour lancer l'interpréteur Lisp, il suffit de lancer la commande suivante :

-   make re
-   ./glados

Vous arriverez alors dans l'interpréteur Lisp.

## Tests

Pour lancer les tests depuis leurs fichiers sources, il suffit de lancer la commande suivante
dans l'interpréteur Lisp :

-   load "chemin_ou_nom_du_fichier_test.lisp"

Le pipeline lance les tests automatiquement de stack test à chaque push sur la branche main.
Vous pouvez retrouver les résultats des tests dans l'onglet Actions de Github.

Sinon, vous pouvez lancer les tests manuellement avec la commande suivante :

-   stack test

Vous trouverez dans le dossier `examples` les fichiers de fonctions testées dans le dossier `test`.

## Auteurs

-   Nathan Tranchant
-   Noah Cherel
-   Marc-Olivier Koban
-   Arnaud Vitale
-   Fabien Gelorse
