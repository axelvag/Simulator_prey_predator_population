# Simulator Prey Predator Population

Mon objectif est de programmer un mini jeu où l’ordinateur « apprend » un camouflage pour
une population d’insectes se faisant dévorer par votre souris 🖱️​. La phase d’apprentissage est une
simulation de l’évolution génétique des gènes de couleur que pourrait faire une espèce
d’insectes voulant maximiser ses chances de survie.

2 Environnements sont disponibles:

CHAMPS:

Au debut tout les insectes ont des couleurs aleatoires

![image](image/Insecte1.jpg)

Apres quelques generations une couleur devient plus optimale pour moins etre visible et survivre 

![image](image/Insecte2.jpg)

OCEANS:

Idem ici ou les poissons ont des couleurs aleatoires au debut du programme

![image](image/Insecte3.jpg)

Puis la couleur s'uniforme au bout de plusieurs generations d'individus

![image](image/Insecte4.jpg)

# Play

Choisissez l'environnement dans le menu en bas a gauche (vous pouvez en rajouter facilement dans le code).

Puis mettez votre souris 🖱️​ sur les particules de couleurs que vous voyez pour les effacer.

Une fois que vous n'en voyez plus appuyez sur Space ​⌨️​ pour creer une nouvelles generation d'insecte.

Continuez jusqu'a voir quel couleur devient domminante !

# GrAPiC 

## Starting

Linux, Windows and Mac instruction :

http://licence-info.univ-lyon1.fr/grapic

## Introduction

GrAPiC is a small, easy-to-use framework to add graphical functionalities to your C/C++ code. 
Its main goal is to provide easy graphical functions to be used in introduction courses of algorithm and programming in C/C++. 
It is based on SDL2 but to use it you need to know only few very simples functions. 
The Grapic archive comes with the needed SDL part, you do not have to install SDL. Just unzip and enjoy ! 

## Starting

Compiling from the github (which is not the standard way).

* On Linux you need to install:
- g++
- doxygen
- zip
- lib-sdl2-dev lib-sdl2 sd2_image... sdl2_ttf...

1. sudo apt install g++ premake4 zip doxygen libsdl2-dev libsdl2-mixer-dev libsdl2-image-dev
2. make premake
3. make
(4. script/make_linux_test.sh): to test the archive doc/download/grapic-linux.tgz
(5. script/make_web.sh): to create the zip files in doc/download or to sync everything to the webpage (need passwd).


* On windows
0. Install CB 20
1. run premake-cb20.bat to generate the projects files    or     run premake-lifami.bat to generate lifami projects 
2. open build/windows-cb20/grapic.workspace

## Best way to make a projet in windows

(windows): 
 - Open build/windows-cb20/grapic.workspace in CodeBlocks
 - In the left part (Management) of the logiciel, double clic in the projet of yours choice (it's those in /apps)
 - Finally clic in the green arrow in the top of the screen

![OpenFolder](image/OpenFolder.jpg)
![OpenFile](image/OpenFile.jpg)

## Put your new project in GraPic

Add your directory with your cpp files in "apps" and add the path in "premake4".

