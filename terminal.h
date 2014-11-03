#ifndef TERMINAL
#define TERMINAL

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

int kbhit(void);
/*
int kbhit(void)
{
    struct timeval tv = { 0, 0 };
    fd_set readfds;

    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO, &readfds);

    return select(STDIN_FILENO + 1, &readfds, NULL, NULL, &tv) == 1;
}
*/

// Efface l'écran
#define clrscr() printf("\033[2J")

//Attributs
#define RESET 0 //Réinitialise tous les attributs
#define BOLD 1 //Haute intensité
#define FAINT 2 //Basse intensité
#define NORMAL 22 //Intensité normale
#define UNDERSCORE 4 //Souligné
#define UNDERSCORE_OFF 24 //Non souligné
#define NEGATIVE 7 //Inverse la couleur du texte et du fond
#define POSITIVE 27 //Remet la couleur du texte et du fond normalement

//Couleurs  du texte
#define BLACK 30
#define RED 31
#define GREEN 32
#define YELLOW 33
#define BLUE 34
#define MAGENTA 35
#define CYAN 36
#define WHITE 37
#define DEFAULT 39

//Couleur du fond
#define BG_BLACK 40
#define BG_RED 41
#define BG_GREEN 42
#define BG_YELLOW 43
#define BG_BLUE 44
#define BG_MAGENTA 45
#define BG_CYAN 46
#define BG_WHITE 47
#define BG_DEFAULT 49

// Sélection des attributs
#define textattr(param) printf("\033[%dm",param)

#define textattrV(param) printf("\033[%dm",param)
// Place le curseur à la position x, y
#define gotoxy(x, y) printf("\033[%d;%dH", y+1,x+1)

//cache le curseur
#define nocursor() printf("\033[?25l")

//affiche le curseur
#define showcursor() printf("\033[?25h]")

#define noecho() system("stty -echo")

#define echo() system("stty echo")

#define raw() system("stty raw")

#define cbreak() system("stty cooked")

#endif
