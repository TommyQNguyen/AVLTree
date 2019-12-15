#pragma once

#pragma warning ( disable : 4326 ) // �teint l'avertissement qui sugg�re d'utiliser la fonction "main" qui retourne un "int" et non "void"

#include <Windows.h>
#include <string>

// POUR LE NETTOYAGE DE LA FEN�TRE CONSOLE

void clreol();   // efface la ligne courante � partir du curseur sans le d�placer
void clreoscr(); // efface la fen�tre � partir du curseur sans le d�placer
void clrscr();   // efface toute la fen�tre et remet le curseur au d�but

// POUR LE POSITIONNEMENT DU CURSEUR DE LA FEN�TRE CONSOLE

int wherex();				// retourne la colonne courante du curseur
int wherey();				// retourne la ligne courante du curseur
void gotoxy(int x, int y);	// place le curseur � la colonne x et � la ligne y  ( l'origine = gotoxy(0,0); )


// POUR GERER LES PROPRI�T�S DE LA FEN�TRE CONSOLE

class Console
{
public:
	// Window
	unsigned short get_wLines();
	unsigned short get_wColumn();
	unsigned short get_wMaxLines();
	unsigned short get_wMaxColumn();

	bool set_wSize(unsigned short column, unsigned short lines);
	bool set_wFullscreen();

	// Buffer
	unsigned short get_bLines();
	unsigned short get_bColumn();
	bool set_bLines(unsigned short lines);
	bool set_bColumn(unsigned short column);

	// Windows position
	int get_wPosX();
	int get_wPosY();
	bool set_wPos(int x, int y);

	Console();

private:
	HANDLE h;
	CONSOLE_SCREEN_BUFFER_INFOEX csbi;

	void get_csbi();
	bool set_csbi();
	void set_wRect(SMALL_RECT rect);
};

// POUR LA COLORATION DES CARACT�RES DE LA FEN�TRE CONSOLE

enum cvmColor // �num�ration des couleurs possibles
{
	NOIR = 0x00,
	BLANC = 0x07,
	BLEU = 0x09,
	VERT = 0x0a,
	CYAN = 0x0b,
	ROUGE = 0x0c,
	ROSE = 0x0d,
	JAUNE = 0x0e
};

void cvmSetColor(cvmColor c); // change la couleur courante
void cvmResetColor(); // change la couleur courante en BLANC


// POUR AFFICHER DU TEXTE DE LA FEN�TRE CONSOLE

void cvmCenterTxt(std::string texte, unsigned int Temps = 0, cvmColor couleur = BLANC);
void cvmDefilTxt(std::string texte, unsigned int Temps = 0, cvmColor couleur = BLANC);

//#include "tp_redirect.h"