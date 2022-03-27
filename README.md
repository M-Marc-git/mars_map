# MarsMap
Projection tri-dimentionnelle d'une carte de Mars réalisée d'après les données du Mars Orbiter Laser Altimeter de la NASA.

## Dépendances
***
 - [glfw](https://github.com/glfw/glfw/tree/3.3.6)
 - [glew](https://github.com/nigels-com/glew)
 - [stb image](https://github.com/nothings/stb)

## Compilation et execution
***
 - télécharger les sources avec git clone https://gitlab.com/Marc__M/marsmap.git --recursive
 - installer les bibliothèques GLFW et GLEW sur votre système
 - télécharger premake5 pour votre système (https://premake.github.io/download/) (pour window et linux le fichier se trouve dans build)
 - lancer premake5 pour votre plateforme
 - exécuter world.py (génération des tronçons à partir de la carte globale (mola_mercat.jpg))
 - compiler et exécuter dans le répertoire de base

## Controles
***
 - Déplacement: Z (avancer), Q (gauche), S (reculer), D (droite)
 - Filliforme/Remplis: A

## Rendu
***
![Alt text](images/mars_1.png?raw=true "Mars 1")
![Alt text](images/mars_2.png?raw=true "Mars_2")
