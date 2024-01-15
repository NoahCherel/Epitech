# Documentation du Réseau Neuronal pour les Échecs

## Aperçu
Cette documentation fournit des détails sur un simple réseau neuronal pour les échecs implémenté en Python à l'aide de la bibliothèque NumPy. Le réseau neuronal est conçu pour prédire le résultat d'une partie d'échecs (gain, perte ou nulle) en fonction de la position actuelle du plateau au format FEN (Forsyth–Edwards Notation).

## Structure du Script
Le script est organisé en sections suivantes :

1. **Importation des Bibliothèques :**
   - `numpy` : Pour les opérations numériques.
   - `argparse` : Pour l'analyse des arguments de ligne de commande.

2. **Fonctions d'Activation :**
   - `sigmoid` : Fonction d'activation sigmoïde pour introduire de la non-linéarité dans le réseau neuronal.
   - `sigmoid_derivative` : Dérivée de la fonction sigmoïde utilisée pendant la rétropropagation.

3. **Classe du Réseau Neuronal pour les Échecs :**
   - `ChessNN` : Implémentation du réseau neuronal, comprenant l'initialisation, les passes avant et arrière, ainsi que les méthodes d'entraînement.

4. **Fonctions Utilitaires :**
   - `fen_to_input` : Convertit une chaîne FEN en une représentation matricielle 8x8 aplatie.
   - `result_to_label` : Convertit une chaîne de résultat ("1-0", "0-1", "1/2-1/2" ou "*") en une étiquette codée à chaud.
   - `parse_dataset_file` : Analyse un fichier de jeu de données contenant des chaînes FEN et les résultats correspondants.

5. **Analyse des Arguments :**
   - `parse_arguments` : Analyse les arguments de ligne de commande à l'aide de argparse.

6. **Exécution Principale :**
   - Lit les arguments de ligne de commande.
   - Analyse le fichier de jeu de données.
   - Prépare les données d'entraînement.
   - Crée une instance de la classe `ChessNN`.
   - Charge un modèle existant ou entraîne un nouveau en fonction des arguments de ligne de commande.
   - Enregistre le modèle entraîné.
   - Teste le modèle entraîné sur une chaîne FEN d'exemple.

## Méthodes de la Classe du Réseau Neuronal pour les Échecs :

### `__init__(self, input_size, hidden_size, output_size)`
- Initialise le réseau neuronal avec des poids et des biais aléatoires.

### `load_model(self, file_path)`
- Charge les paramètres du modèle (poids et biais) à partir d'un fichier donné.

### `save_model(self, file_path)`
- Enregistre les paramètres du modèle (poids et biais) dans un fichier donné.

### `forward(self, X)`
- Effectue une passe avant à travers le réseau neuronal et renvoie la sortie prédite.

### `backward(self, X, y, learning_rate)`
- Effectue une passe arrière à travers le réseau, calcule les gradients et met à jour les poids et les biais.

### `train(self, X, y, epochs=10000, learning_rate=0.1, batch_size=32)`
- Entraîne le réseau neuronal en utilisant un traitement par lots.

## Fonctions Utilitaires :

### `fen_to_input(fen)`
- Convertit une chaîne FEN en une représentation matricielle 8x8 aplatie.

### `result_to_label(result)`
- Convertit une chaîne de résultat en une étiquette codée à chaud.

### `parse_dataset_file(file_path)`
- Analyse un fichier de jeu de données contenant des chaînes FEN et des résultats.

## Arguments de Ligne de Commande :

- `--train` : S'il est présent, entraîne un nouveau modèle ou continue l'entraînement d'un modèle existant.
- `--model` : Spécifie le chemin du fichier modèle. Par défaut, 'chess_model.npz'.

## Exemple d'Utilisation :
```bash
./my_torch --train --model my_model.npz
```

## Format du Fichier de Jeu de Données :
Le fichier de jeu de données doit avoir le format suivant :
```
FEN: [CHAÎNE_FEN]
RES: [CHAÎNE_RÉSULTAT]
[CONFIGURATION_DU_PLATEAU_1]
[CONFIGURATION_DU_PLATEAU_2]
...
FEN: [CHAÎNE_FEN]
RES: [CHAÎNE_RÉSULTAT]
[CONFIGURATION_DU_PLATEAU_1]
[CONFIGURATION_DU_PLATEAU_2]
...
```

- CHAÎNE_FEN : Représentation en notation Forsyth–Edwards du plateau d'échecs.
- CHAÎNE_RÉSULTAT : Résultat de la partie ("1-0", "0-1", "1/2-1/2" ou "*").
- CONFIGURATION_DU_PLATEAU : Lignes du plateau d'échecs, avec des pièces représentées par des caractères.

## Dépendances :
- Python 3
- NumPy

## Notes :
- Ajustez la plage de troncature dans la fonction `sigmoid` selon vos besoins.
- Le chemin par défaut du fichier de jeu de données est "datasets/datasets/checkmate/10_pieces.txt".
- L'architecture par défaut du réseau neuronal est input_size=64, hidden_size=16, output_size=3.
- Les paramètres d'entraînement par défaut sont epochs=10000, learning_rate=0.1, batch_size=32.
- Le script enregistre le modèle entraîné dans le chemin spécifié ou le chemin du modèle par défaut.

N'hésitez pas à modifier le script et la documentation en fonction de votre cas d'utilisation spécifique et de vos besoins.
