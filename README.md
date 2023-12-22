# Simulator Prey Predator Population

My goal is to program a mini game where the computer “learns” a camouflage for
a population of insects being devoured by your mouse 🖱️​. The learning phase is a
simulation of the genetic evolution of color genes that a species could make
insects wanting to maximize their chances of survival.

2 Environments are available:

FIELDS:

At the beginning all insects have random colors

![image](image/Insecte1.jpg)

After a few generations a color becomes more optimal to be less visible and survive

![image](image/Insecte2.jpg)

OCEANS:

Idem ici ou les poissons ont des couleurs aleatoires au debut du programme

![image](image/Insecte3.jpg)

Then the color becomes uniform after several generations of individuals

![image](image/Insecte4.jpg)

# Play

Choose the environment in the menu at the bottom left (you can easily add more in the code).

Then put your mouse 🖱️​ on the colored particles you see to erase them.

Once you no longer see any, press Space ​⌨️​ to create a new generation of insects.

Continue until you see which color becomes dominant!

# Subject

```
1. An insect is represented by a position (x,y), a color (r,g,b), a birth time
and a lifespan. A population of insects is represented by a table of
NB_INSECTS insects and a background image representing the landscape in which the insects
live.

  Declare these two structures, as well as a Color structure with the operators
  addition, subtraction, multiplication and division by a real number.

2. Write the following two procedures for initializing the insect world.

 void initInsect(SomeInsects& if, Color good, int range)
 - Initializes insects. Their position is chosen at random. Their color will be chosen
 randomly in a radius around the color good. The field of lifespan
 is initialized to -1: a negative number means that the insect is still alive, a positive
 indicates how long he lived.

 void init(SomeInsects& if)
 - Initializes the landscape image and calls the procedure that initializes the insects.

3. Write the draw procedure which takes the insect population as a parameter and displays it, thus
than the landscape image. Each insect is a solid circle of radius 3 with the color stored
in the structure.

4. Write the Update procedure with 2 aspects: death of an insect (question 5), regeneration of
the entire insect population (question 6).

5. Insects within 20 pixels of the mouse are eaten. The mouse is the predator.
A dead insect is no longer visible and will have its lifespan field which will contain the duration
that he lived before being eaten by the mouse. Use:
 ElapsedTime() which returns the duration since the program was launched.

6. Once all the insects are dead we will keep the insects best adapted to their
environment, and select their color to regenerate a population.

 a. Write the procedure minMaxLifeTime which finds the minimum life and the
 maximum lifespan in an insect population.

 b. Write the averageColorOfGoodInsects function that calculates the average color
 insects whose lifespan has exceeded a certain duration.

 c. In an update procedure add code that regenerates a new
 population with a better suited color calculated by questions a. and B.

```

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

