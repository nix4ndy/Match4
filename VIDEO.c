#include <windows.h>
#include <stdio.h>
//------------COLORES----------------
#define NEGRO 0X0000
#define AZUL 0X0001
#define VERDE 0X0002
#define CYAN 0X0003
#define ROJO 0X0004
#define MAGENTA 0X0005
#define AMARILLO 0X0006
#define GRIS_CLARO 0X0007
#define GRIS_OSCURO 0X0008
#define BLANCO 0X000F
////----------COLORES INTENSOS---------
#define AZULI 0X0009
#define VERDEI 0X000A
#define CYANI 0X000B
#define ROJOI 0X000C
#define MAGENTAI 0X000D
#define AMARILLOI 0X000E
//-----------ABREVIACIONES-----------
#define setD setDefault
#define setT setTexto
#define setTF setTextoFondo
#define MAX 100

//EJEMPLO setT(AZUL); printf ("55\n"); setD();

void gotoxy(int x, int y){
        HANDLE hCon;
        hCon=GetStdHandle(STD_OUTPUT_HANDLE);
        COORD dwPos;
        dwPos.X=x;
        dwPos.Y=y;
        SetConsoleCursorPosition(hCon,dwPos);
}

void setDefault() {
    HANDLE hCon;
    hCon=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute (hCon,GRIS_CLARO);
}

void setTexto(int texto) {
    HANDLE hCon;
    hCon=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute (hCon,texto);
}

void setTextoFondo(int texto, int fondo){
    HANDLE hCon;
    int numero;
    hCon=GetStdHandle(STD_OUTPUT_HANDLE);
    numero = fondo*16+texto;
	SetConsoleTextAttribute (hCon,numero);
}

void setTitle (const char *texto){
    SetConsoleTitle(texto);
}

int longitud(char c[MAX]){
    int l=0;
    while(c[l]!='\0'){
        l++;
    }
    return l;
}

void centrar(char texto[MAX],int x,int y){
    int l1;

    l1=longitud(texto);

    gotoxy(x-(l1/2),y);
    printf("%s",texto);
}

void centrarT(const char* texto,int x,int y){
    int l1;

    l1=longitud(texto);

    gotoxy(x-(l1/2),y);
    printf("%s",texto);
}

// Creador en C++: Pablo Lavezzi
// Traduccion a C: Matias Picon
// Funciones extras: Johanna Olivera


