// apps/LIFAMI/TPColorInsects.cpp
#include <Grapic.h>
#include <math.h>
#include <iostream>

using namespace grapic;
using namespace std;

const int DIMW=1000;
const int NBINSECTE=50;


struct Complex
{
    float x,y;
};

Complex make_complex(float x,float y)
{
    Complex z;
    z.x=x;
    z.y=y;
    return z;
}

Complex operator-(Complex opg,Complex opd)
{
    Complex res;
    res.x=opg.x-opd.x;
    res.y=opg.y-opd.y;
    return res;
}

struct Color
{
    int r,g,b;
};

Color make_color(int r,int g, int b )
{
    Color z;
    z.r=r;
    z.g=g;
    z.b=b;
    return z;
}

Color operator+(Color opg,Color opd)
{
    Color res;
    res.r=opg.r+opd.r;
    res.g=opg.g+opd.g;
    res.b=opg.b+opd.b;
    return res;
}

Color operator-(Color opg,Color opd)
{
    Color res;
    res.r=opg.r-opd.r;
    res.g=opg.g-opd.g;
    res.b=opg.b-opd.b;
    return res;
}

Color operator*(float opg, Color opd)
{
    return make_color(opg*opd.r,opg*opd.g,opg*opd.b);
}

Color operator*(Color opg, float opd)
{
    return opd*opg;
}

Color operator/(Color opg, float opd)
{
    return opg * (1.0 / opd);
}

struct Insecte
{
    Complex positions;
    Color couleur;
    float dateNaissance;
    float dateMort;
    float ageMort;
};

struct PopulationInsectes
{
    Insecte tab[NBINSECTE];
    Image fond;
    int nbInsectes;
    int nbInsectesVivants;
    int amplitude;
};

void initInsectes(PopulationInsectes&si,Color good,int range)
{
    for(int i=0;i<si.nbInsectes;i++)
    {
        si.tab[i].positions=make_complex(rand()%DIMW,rand()%DIMW);
        si.tab[i].couleur=make_color(good.r+rand()%(2*range)-range,good.g+rand()%(2*range)-range,good.b+rand()%(2*range)-range);
        si.tab[i].dateNaissance=elapsedTime();
        si.tab[i].dateMort=-1;
        si.tab[i].ageMort=-1;
    }
    si.nbInsectesVivants=si.nbInsectes;
}

void init1(PopulationInsectes&si)
{
    si.nbInsectes=40;
    initInsectes(si,make_color(128,128,128),128);
    si.fond=image("../data/lifami_insecte/fond.jpg");
}

void init2(PopulationInsectes&si)
{
    si.nbInsectes=40;
    initInsectes(si,make_color(128,128,128),128);
    si.fond=image("../data/lifami_insecte/fond2.jpg");
}


float distance(Complex v)
{
    return sqrt(v.x*v.x + v.y*v.y);
}

void updateMangerInsectes(PopulationInsectes & si)
{
    int x,y;
    mousePos(x,y);
    Complex souris=make_complex(x,y);
    for(int i=0;i<si.nbInsectes;i++)
    {
        if(si.tab[i].dateMort==-1)
        {
            if(distance(souris-si.tab[i].positions)<=20)        //TAILLE CERCLE RECHERCHE
            {
                si.tab[i].dateMort=elapsedTime();
                si.tab[i].ageMort=si.tab[i].dateMort-si.tab[i].dateNaissance;
                si.nbInsectesVivants--;
            }
        }
    }
}

void minMaxLifetime(PopulationInsectes si,float &mini,float& maxi)
{
    mini=si.tab[0].ageMort;
    maxi=si.tab[0].ageMort;
    for(int i=1;i<si.nbInsectes;i++)
    {
        if(si.tab[i].ageMort<mini)
            mini=si.tab[i].ageMort;
        if(si.tab[i].ageMort>maxi)
            maxi=si.tab[i].ageMort;
    }
}

Color averageColorOfGoodInsectes(PopulationInsectes si,float duree)
{
    int r=0,g=0,b=0,nb=0;
    for(int i=1;i<si.nbInsectes;i++)
    {
        if(si.tab[i].ageMort>duree)
        {
            r=r+si.tab[i].couleur.r;
            g=g+si.tab[i].couleur.g;
            b=b+si.tab[i].couleur.b;
            nb++;
        }
    }
    return make_color(r/nb,g/nb,b/nb);
}

void updateReinitialiserPopulation(PopulationInsectes& si)
{
    float ageMin,ageMax;
    minMaxLifetime(si,ageMin,ageMax);
    Color Cm=averageColorOfGoodInsectes(si,(ageMax+ageMin)/2.0);
    si.amplitude=si.amplitude/2;
    initInsectes(si,Cm,si.amplitude);
}

void update(PopulationInsectes & si)
{
    if(si.nbInsectesVivants>0)
    {
        updateMangerInsectes(si);
    }
    else
    {
        updateReinitialiserPopulation(si);
    }
}

void draw(PopulationInsectes si)
{
    image_draw(si.fond,0,0,DIMW,DIMW);
    for(int i=0;i<si.nbInsectes;i++)
    {
        if(si.tab[i].dateMort==-1)
        {
            color(si.tab[i].couleur.r,si.tab[i].couleur.g,si.tab[i].couleur.b);
            circleFill(si.tab[i].positions.x,si.tab[i].positions.y,3);
        }
    int x,y;
    mousePos(x,y);
    color(255,255,255);
    circle(x,y,20);
    }
}

int main(int , char**)
{
    bool stop=false;
    winInit("INSECTES",DIMW,DIMW);

    Menu men;
    menu_add(men,"FLEUR");
    menu_add(men,"OCEAN");

    PopulationInsectes pop1;
    PopulationInsectes pop2;
    init1(pop1);                    //champ fleur
    init2(pop2);                    //ocean
    while(!stop)
    {
        winClear();
        switch(menu_select(men))
        {
            case 0 : draw(pop1); menu_draw(men,5,10,100,100); update(pop1);
                    if(isKeyPressed(SDLK_SPACE))
                    {
                        pop1.nbInsectesVivants=0;
                    }break;
            case 1 : draw(pop2); menu_draw(men,5,10,100,100); update(pop2);
                    if(isKeyPressed(SDLK_SPACE))
                    {
                        pop2.nbInsectesVivants=0;
                    }break;
            default: draw(pop1); menu_draw(men,5,10,100,100); update(pop1);
                    if(isKeyPressed(SDLK_SPACE))
                    {
                        pop1.nbInsectesVivants=0;
                    }break;
        }
        stop=winDisplay();
    }
    winQuit();
    return 0;
}
