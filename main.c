#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include "VIDEO.c"
#define MAX 100
//-----------------------------------------------------------
FILE *arch,*puntaje;
//-----------------------------------------------------------
struct infoPeliculas{
    char grupo[MAX];
    int num;
    char titulo[MAX];
    int aL;
    int duracion;
    float ranking;
    int presupuesto;
    int recaudado;
}movie[32]={
    {"A",1,"Volver al futuro",1985,116,8.5,19,383},
    {"A",2,"Ready Player One",2018,140,7.4,175,582},
    {"A",3,"Sabrina",1995,127,6.3,58,53},
    {"A",4,"Harry Potter y la Orden del Fenix",2007,138,7.5,150,942},
    {"B",1,"La Isla Siniestra",2010,138,8.2,80,294},
    {"B",2,"Jumanji",1995,104,7.0,65,262},
    {"B",3,"Juego de Gemelas",1998,128,6.6,15,92},
    {"B",4,"Matrix",1999,136,8.7,63,467},
    {"C",1,"Mary Poppins",1964,139,7.8,6,103},
    {"C",2,"Rocketman",2019,121,7.3,40,195},
    {"C",3,"Se7en",1995,127,8.6,33,327},
    {"C",4,"Mulan",1998,88,7.6,90,304},
    {"D",1,"Jurassic Park",1993,127,8.2,63,1099},
    {"D",2,"E.T. El Extraterrestre",1982,115,7.9,10,792},
    {"D",3,"Spider-Man: No Way Home",2021,148,8.3,200,1892},
    {"D",4,"Les Miserables",2012,158,7.5,61,442},
    {"E",1,"Nueve Reinas",2000,114,7.9,1,12},
    {"E",2,"Cuestion de Tiempo",2013,123,7.8,12,87},
    {"E",3,"Los Vengadores",2012,143,8.0,220,1518},
    {"E",4,"Mamma Mia!",2008,108,6.4,52,611},
    {"F",1,"Almost Famous",2000,122,7.9,60,47},
    {"F",2,"Forrest Gump",1994,142,8.8,55,678},
    {"F",3,"Star Wars: Episode VI",1983,131,8.3,32,475},
    {"F",4,"La Sociedad de los Poetas Muertos",1989,128,8.1,16,235},
    {"G",1,"tick, tick... Boom!",2021,120,7.5,55,112},
    {"G",2,"Guardianes de la Galaxia",2014,121,8.0,170,773},
    {"G",3,"The Truman Show",1998,103,8.2,60,264},
    {"G",4,"Interstellar",2014,169,8.6,165,701},
    {"H",1,"Votos de Amor",2012,104,6.8,30,196},
    {"H",2,"Coraline y la puerta secreta",2009,100,7.7,60,124},
    {"H",3,"Hombres de Negro",1997,98,7.3,90,589},
    {"H",4,"Sing Street",2016,106,7.9,4,13}
};

struct repCartas{
    char grupo[MAX];
    int num;
    char titulo[MAX];
    int aL;
    int duracion;
    float ranking;
    int presupuesto;
    int recaudado;
}cartasP[32],cartasC[32];
//-----------------------------------------------------------
void base(){
    setT(BLANCO);
    gotoxy(2,1); printf("Trabajo Pr ctico Final   Olivera, Johanna Sayi   Inform tica UNSAM 2022");
    setD();
    setT(MAGENTA);
    gotoxy(0,0); printf("ษออออออออออออออออออออออออหอออออออออออออออออออออออหออออออออออออออออออออออออป");
    gotoxy(0,1); printf("บ"); gotoxy(25,1); printf("บ"); gotoxy(49,1); printf("บ"); gotoxy(74,1); printf("บ");
    gotoxy(0,2); printf("ฬออออออออออออออออออออออออสอออออออออออออออออออออออสออออออออออออออออออออออออน");
    for(int lin=3;lin<18;lin++){
        gotoxy(0,lin); printf("บ"); gotoxy(74,lin); printf("บ");
    }
    gotoxy(0,18);printf("ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ");
    setD();
}

void reglas(){
    base();
    setT(CYANI); gotoxy(3,4); printf(">> REGLAS <<"); setD();
    setT(MAGENTA); gotoxy(34,16); printf("ษอออออออออออออออออออออออออออออออออออออออน");
    gotoxy(34,17); printf("บ"); gotoxy(34,18); printf("ส"); setD();
    setT(BLANCO);
    gotoxy(3,6); printf("1  Recibir s 5 cartas apiladas de modo que solo puedas ver la primera");
    gotoxy(3,7); printf("   al igual que");
    gotoxy(26,7); printf(", el bot que ser  tu contrincante");
    gotoxy(3,9);  printf("2  El juego es iniciado por vos, tendr s que elegir la mejor caracte-");
    gotoxy(3,10); printf("   rกstica de la pelกcula descrita en tu carta superior e ingresar");
    gotoxy(3,11); printf("   la opciขn correspondiente");
    gotoxy(3,13); printf("3  Una vez elegida, se compararan las caracterกsticas de ambas cartas");
    gotoxy(3,14); printf("   segฃn los criterios y se sumar n los puntos debidos a cada jugador");
    gotoxy(36,17); printf("PRESIONE CUALQUIER TECLA PARA AVANZAR");
    setD();
    setT(VERDEI); gotoxy(19,7); printf("NIX4NDY"); setD();
    gotoxy(0,0);
    getch();
    system("CLS");
    base();
    setT(CYANI); gotoxy(3,4); printf(">> REGLAS <<"); setD();
    setT(MAGENTA); gotoxy(34,16); printf("ษอออออออออออออออออออออออออออออออออออออออน");
    gotoxy(34,17); printf("บ"); gotoxy(34,18); printf("ส"); setD();
    setT(BLANCO);
    gotoxy(3,6); printf("4  En caso de empate, las cartas de dicha ronda se descartaran y se");
    gotoxy(3,7); printf("   repartiran unas nuevas, dandole a los jugadores la posibilidad de");
    gotoxy(3,8); printf("   jugar otra ronda m s");
    gotoxy(3,10); printf("5  El juego finaliza cuando se utilizaron las cartas en mano, siendo");
    gotoxy(3,11); printf("   ganador el jugador con m s puntos acumulados");
    gotoxy(36,17); printf("PRESIONE CUALQUIER TECLA PARA AVANZAR");
    setD();
    gotoxy(0,0);
    getch();
    system("CLS");
    base();
    setT(CYANI); gotoxy(3,4); printf(">> CRITERIOS PARA GANAR <<"); setD();
    setT(MAGENTA); gotoxy(27,16); printf("ษออออออออออออออออออออออออออออออออออออออออออออออน");
    gotoxy(27,17); printf("บ"); gotoxy(27,18); printf("ส"); setD();
    setT(BLANCO);
    gotoxy(3,6); printf("1  Aคo de lanzamiento: la pelกcula con m s antigedad ganar ");
    gotoxy(3,8); printf("2  Duraciขn en minutos: la pelกcula m s larga ganar ");
    gotoxy(3,10); printf("3  Ranking segun IMDb: la pelกcula con mayor ranking ganar ");
    gotoxy(3,12); printf("4  Presupuesto: la pelกcula que haya costado menos ganar ");
    gotoxy(3,14); printf("5  Recaudado: la pelกcula con mayor recaudaciขn mundial ganar ");
    gotoxy(29,17); printf("PRESIONE CUALQUIER TECLA PARA VOLVER AL MEN้");
    setD();
    gotoxy(0,0);
    getch();
    system("CLS");
}
//-----------------------------------------------------------
int existe(){
    int opArch,op;

    system("CLS");
    base();
    setT(BLANCO);
    centrarT(">> NUEVA PARTIDA <<",37,4);
    centrarT("YA EXISTE UNA PARTIDA GUARDADA CON",37,8);
    centrarT("ESE NOMBRE, จDESEA REESCRIBIRLA?",37,10);
    setD();
    setT(MAGENTA);
    gotoxy(0,6); printf("ฬอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน");
    centrarT("ษอออหออออป         ษอออหออออป",37,13);
    centrarT("บ   บ    บ >>   << บ   บ    บ",37,14);
    centrarT("ศอออสออออผ         ศอออสออออผ",37,15);
    setD();
    setT(BLANCO);
    gotoxy(25,14); printf("1"); gotoxy(29,14); printf("SI");
    gotoxy(44,14); printf("2"); gotoxy(48,14); printf("NO");
    setD();
    pixelArt(2);
    pixelArt(3);
    for(;;){
       setT(BLANCO); gotoxy(37,14); scanf("%i",&opArch); setD();
        if(opArch==1){
            op=1;
            break;
        }
        else if(opArch==2){
            op=0;
            break;
        }
        else{
            setT(ROJOI); centrarT(" ERROR ",37,14); setD();
            getch();
            setT(MAGENTA); centrarT(">>   <<",37,14); setD();
        }
    }
    return op;
}
//-----------------------------------------------------------
void textosP(int num,int cod){
    setT(BLANCO);
    switch(num){
        case 1:
            centrar(movie[cod].titulo,18,4);
            gotoxy(2,6); printf("Aคo de lanzamiento"); gotoxy(31,6); printf("%i",movie[cod].aL);
            gotoxy(2,7); printf("Duraciขn [min]"); gotoxy(31,7); printf("%4i",movie[cod].duracion);
            gotoxy(2,8); printf("Ranking [IMDb]"); gotoxy(31,8); printf("%4.1f",movie[cod].ranking);
            gotoxy(2,9); printf("Presupuesto [1M]"); gotoxy(31,9); printf("%4i",movie[cod].presupuesto);
            gotoxy(2,10); printf("Recaudado [1M]"); gotoxy(31,10); printf("%4i",movie[cod].recaudado);
            break;
        case 2:
            centrar(movie[cod].titulo,56,4);
            gotoxy(40,6); printf("Aคo de lanzamiento"); gotoxy(69,6); printf("%i",movie[cod].aL);
            gotoxy(40,7); printf("Duraciขn [min]"); gotoxy(69,7); printf("%4i",movie[cod].duracion);
            gotoxy(40,8); printf("Ranking [IMDb]"); gotoxy(69,8); printf("%4.1f",movie[cod].ranking);
            gotoxy(40,9); printf("Presupuesto [1M]"); gotoxy(69,9); printf("%4i",movie[cod].presupuesto);
            gotoxy(40,10); printf("Recaudado [1M]"); gotoxy(69,10); printf("%4i",movie[cod].recaudado);
            break;
        case 3:
            centrar(movie[cod].titulo,18,13);
            gotoxy(2,15); printf("Aคo de lanzamiento"); gotoxy(31,15); printf("%i",movie[cod].aL);
            gotoxy(2,16); printf("Duraciขn [min]"); gotoxy(31,16); printf("%4i",movie[cod].duracion);
            gotoxy(2,17); printf("Ranking [IMDb]"); gotoxy(31,17); printf("%4.1f",movie[cod].ranking);
            gotoxy(2,18); printf("Presupuesto [1M]"); gotoxy(31,18); printf("%4i",movie[cod].presupuesto);
            gotoxy(2,19); printf("Recaudado [1M]"); gotoxy(31,19); printf("%4i",movie[cod].recaudado);
            break;
        case 4:
            centrar(movie[cod].titulo,56,13);
            gotoxy(40,15); printf("Aคo de lanzamiento"); gotoxy(69,15); printf("%i",movie[cod].aL);
            gotoxy(40,16); printf("Duraciขn [min]"); gotoxy(69,16); printf("%4i",movie[cod].duracion);
            gotoxy(40,17); printf("Ranking [IMDb]"); gotoxy(69,17); printf("%4.1f",movie[cod].ranking);
            gotoxy(40,18); printf("Presupuesto [1M]"); gotoxy(69,18); printf("%4i",movie[cod].presupuesto);
            gotoxy(40,19); printf("Recaudado [1M]"); gotoxy(69,19); printf("%4i",movie[cod].recaudado);
            break;
    }
    setD();
}

void cuadrosP(int num){
    setT(CYAN);
    switch(num){
        case 1:
            gotoxy(0,3);  printf("ษอออออออออออออออออออออออออออออออออออป");
            gotoxy(0,4);  printf("บ"); gotoxy(36,4); printf("บ");
            gotoxy(0,5);  printf("ฬอออออออออออออออออออออออออออออออออออน");
            for(int fil=0,y=6;fil<5;fil++,y++){
                gotoxy(0,y);  printf("บ"); gotoxy(36,y); printf("บ");
            }
            gotoxy(0,11); printf("ศอออออออออออออออออออออออออออออออออออผ");
            break;
        case 2:
            gotoxy(38,3);  printf("ษอออออออออออออออออออออออออออออออออออป");
            gotoxy(38,4);  printf("บ"); gotoxy(74,4); printf("บ");
            gotoxy(38,5);  printf("ฬอออออออออออออออออออออออออออออออออออน");
            for(int fil=0,y=6;fil<5;fil++,y++){
                gotoxy(38,y);  printf("บ"); gotoxy(74,y); printf("บ");
            }
            gotoxy(38,11); printf("ศอออออออออออออออออออออออออออออออออออผ");
            break;
        case 3:
            gotoxy(0,12);  printf("ษอออออออออออออออออออออออออออออออออออป");
            gotoxy(0,13);  printf("บ"); gotoxy(36,13); printf("บ");
            gotoxy(0,14);  printf("ฬอออออออออออออออออออออออออออออออออออน");
            for(int fil=0,y=15;fil<5;fil++,y++){
                gotoxy(0,y);  printf("บ"); gotoxy(36,y); printf("บ");
            }
            gotoxy(0,20); printf("ศอออออออออออออออออออออออออออออออออออผ");
            break;
        case 4:
            gotoxy(38,12);  printf("ษอออออออออออออออออออออออออออออออออออป");
            gotoxy(38,13);  printf("บ"); gotoxy(74,13); printf("บ");
            gotoxy(38,14);  printf("ฬอออออออออออออออออออออออออออออออออออน");
            for(int fil=0,y=15;fil<5;fil++,y++){
                gotoxy(38,y);  printf("บ"); gotoxy(74,y); printf("บ");
            }
            gotoxy(38,20); printf("ศอออออออออออออออออออออออออออออออออออผ");
            break;
    }
    setD();
}
//-----------------------------------------------------------
void cuadrosPartida(int num){
    setT(CYANI);
    gotoxy(0,1);  printf("ษอออออออออออออออออออออออออออออออออออป");
    for(int fil=0,y=2;fil<8;fil++,y++){
        gotoxy(0,y);  printf("บ"); gotoxy(36,y); printf("บ");
    }
    gotoxy(0,9); printf("ศอออออออออออออออออออออออออออออออออออผ"); setD();
    setT(CYAN);
    switch(num){
        case 0:
            gotoxy(38,0);  printf("ษอออออออออป");
            gotoxy(38,1);  printf("บ"); gotoxy(48,1); printf("บ");
            gotoxy(38,2);  printf("ฬอออออออออสอออออออออออออออออออออออออป");
            for(int fil=0,y=3;fil<7;fil++,y++){
                gotoxy(38,y);  printf("บฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑบ");
            }
            gotoxy(38,10); printf("ศอออออออออออออออออออออออออออออออออออผ");
            break;
        case 1:
            gotoxy(38,0);  printf("ษอออออออออป");
            gotoxy(38,1);  printf("บ"); gotoxy(48,1); printf("บ");
            gotoxy(38,2);  printf("ฬอออออออออสอออออออออออออออออออออออออป");
            gotoxy(38,3);  printf("บ                                   บ");
            gotoxy(38,4);  printf("ฬอออหอออออออออออออออออออออออออออออออน");
            for(int fil=0,y=5;fil<5;fil++,y++){
                gotoxy(38,y);  printf("บ   บ                               บ");
            }
            gotoxy(38,10); printf("ศอออสอออออออออออออออออออออออออออออออผ");
            break;
    }

    gotoxy(0,10);  printf("ษอออออออออออออออออออออออออออออออออออป");
    gotoxy(0,11);  printf("บ"); gotoxy(36,11); printf("บ");
    gotoxy(0,12);  printf("ฬอออออออออออออออออออออออออออออออออออน");
    gotoxy(0,13);  printf("บ"); gotoxy(36,13); printf("บ");
    gotoxy(0,14);  printf("ฬอออหอออออออออออออออออออออออออออออออน");
    for(int fil=0,y=15;fil<5;fil++,y++){
        gotoxy(0,y);  printf("บ"); gotoxy(4,y); printf("บ"); gotoxy(36,y); printf("บ");
    }
    gotoxy(0,20); printf("ศอออสอออออออออออออออออออออออออออออออผ");
    setD();
    setT(CYANI);
    gotoxy(38,11); printf("ษอออออออออออออออออออออออออออออออออออป");
    gotoxy(38,12); printf("บ"); gotoxy(74,12); printf("บ");
    gotoxy(38,13); printf("ศออหอออออหอออออหอออออหอออออหอออออหออผ");
    gotoxy(38,14); printf("   บ     บ     บ     บ     บ     บ   ");
    gotoxy(38,15); printf("   ศอออออสอออออสอออออสอออออสอออออผ"); setD();
    setT(BLANCO);
    gotoxy(40,1); printf("NIX4NDY");
    gotoxy(45,12); printf("Elija su caracterกstica");
    gotoxy(44,14); printf("1"); gotoxy(50,14); printf("2");
    gotoxy(56,14); printf("3"); gotoxy(62,14); printf("4"); gotoxy(68,14); printf("5");
    gotoxy(41,17); printf(">> ");
    setD();
}
//-----------------------------------------------------------
void infoPelis(){
    int cod=0;
    for(int pagina=0;pagina<8;pagina++){
        setT(CYANI);
        printf("ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป\n");
        printf("บ                        INFORMACIเN DE LAS CARTAS                        บ\n");
        printf("ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ\n"); setD();
        for(int num=1;num<5;num++,cod++){
            textosP(num,cod);cuadrosP(num);
        }
        getch();
        system("CLS");
    }
}

void nuevaPartida(){
    char nameP[MAX];
    char archP[MAX];
    char puntosArchivo[MAX];

    int op=0,pointsC=0,pointsP=0, al=0,p=0,c=0;
    int opArch=0;
    int keyR[32];

    for(;;){
        base();
        setT(BLANCO);
        centrarT(">> NUEVA PARTIDA <<",37,4);
        centrarT(">> INGRESE SU USUARIO <<",37,11);
        setD();
        setT(MAGENTA);
        gotoxy(0,6); printf("ฬอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน");
        setD();
        pixelArt(2);
        pixelArt(3);
        gotoxy(28,13); setT(AMARILLOI); printf(" "); setD();
        setT(BLANCO); scanf("%s",&nameP); setD();

        strcpy(archP,nameP);
        strcpy(puntosArchivo,nameP);
        strcat(archP,".txt");
        strcat(puntosArchivo," puntos.txt");

        if((arch=fopen(archP,"rt"))!=NULL){
            opArch=existe();
            if(opArch==0){
                system("CLS");
                break;
            }
            else{
                arch=fopen(archP,"wt");
            }
        }
        else{
            arch=fopen(archP,"wt");
        }

        for(int i=0;i<32;i++){keyR[i]=0;}

        for(int i=0;i<10;i++){ //REPARTIR
            al=rand()%32;
            if(keyR[al]==0){
                keyR[al]=1;

                if(i%2==0){
                    strcpy(cartasP[p].titulo,movie[al].titulo);
                    strcpy(cartasP[p].grupo,movie[al].grupo);
                    cartasP[p].num=movie[al].num;
                    cartasP[p].aL=movie[al].aL;
                    cartasP[p].duracion=movie[al].duracion;
                    cartasP[p].presupuesto=movie[al].presupuesto;
                    cartasP[p].recaudado=movie[al].recaudado;
                    cartasP[p].ranking=movie[al].ranking;
                    p++;
                }
                else{
                    strcpy(cartasC[c].titulo,movie[al].titulo);
                    strcpy(cartasC[c].grupo,movie[al].grupo);
                    cartasC[c].num=movie[al].num;
                    cartasC[c].aL=movie[al].aL;
                    cartasC[c].duracion=movie[al].duracion;
                    cartasC[c].presupuesto=movie[al].presupuesto;
                    cartasC[c].recaudado=movie[al].recaudado;
                    cartasC[c].ranking=movie[al].ranking;
                    c++;
                }
            }
            else {
                i--;
            }
        }
        system("CLS");

        //---------------- ARCHIVOS ----------------
        fprintf(arch,"\n------------------------------------------------\n");
        fprintf(arch," >> Cartas de %s <<\n",nameP);
        fprintf(arch,"------------------------------------------------\n");
        for(int i=0;i<p;i++){
            fprintf(arch," Pelicula %s%i) %s\n",cartasP[i].grupo,cartasP[i].num,cartasP[i].titulo);
            fprintf(arch," A๑o de lanzamiento                        %4i\n",cartasP[i].aL);
            fprintf(arch," Duracion [min]                            %4i\n",cartasP[i].duracion);
            fprintf(arch," Ranking [IMDb]                            %4.1f\n",cartasP[i].ranking);
            fprintf(arch," Presupuesto [1M]                          %4i\n",cartasP[i].presupuesto);
            fprintf(arch," Recaudado [1M]                            %4i\n",cartasP[i].recaudado);
            fprintf(arch,"------------------------------------------------\n");
        }

        fprintf(arch,"\n------------------------------------------------\n");
        fprintf(arch," >> Cartas de NIX4NDY <<\n");
        fprintf(arch,"------------------------------------------------\n");
        for(int i=0;i<p;i++){
            fprintf(arch," Pelicula %s%i) %s\n",cartasC[i].grupo,cartasC[i].num,cartasC[i].titulo);
            fprintf(arch," A๑o de lanzamiento                        %4i\n",cartasC[i].aL);
            fprintf(arch," Duracion [min]                            %4i\n",cartasC[i].duracion);
            fprintf(arch," Ranking [IMDb]                            %4.1f\n",cartasC[i].ranking);
            fprintf(arch," Presupuesto [1M]                          %4i\n",cartasC[i].presupuesto);
            fprintf(arch," Recaudado [1M]                            %4i\n",cartasC[i].recaudado);
            fprintf(arch,"------------------------------------------------\n");
        }
        //--------------------------------------------------------
        for(int ronda=0;ronda<p;ronda++){
            system("CLS");
            cuadrosPartida(0);
            setT(BLANCO);
            centrar(nameP,18,11);
            centrar(cartasP[ronda].titulo,18,13);
            gotoxy(2,15); printf("1"); gotoxy(6,15); printf("Aคo de lanzamiento       %4i",cartasP[ronda].aL);
            gotoxy(2,16); printf("2"); gotoxy(6,16); printf("Duraciขn [min]           %4i",cartasP[ronda].duracion);
            gotoxy(2,17); printf("3"); gotoxy(6,17); printf("Ranking [IMDb]           %4.1f",cartasP[ronda].ranking);
            gotoxy(2,18); printf("4"); gotoxy(6,18); printf("Presupuesto [1M]         %4i",cartasP[ronda].presupuesto);
            gotoxy(2,19); printf("5"); gotoxy(6,19); printf("Recaudado [1M]           %4i",cartasP[ronda].recaudado);
            gotoxy(44,17); scanf("%i",&op); gotoxy(44,17);
            setD();
            if(op>=1 && op<=5){
                fprintf(arch,"\n------------------------------------------------\n");
                fprintf(arch,"                 >> RONDA %i <<                 \n",ronda+1);
                fprintf(arch,"------------------------------------------------\n");
                cuadrosPartida(1);
                setT(BLANCO);
                centrar(cartasC[ronda].titulo,56,3);
                gotoxy(40,5); printf("1"); gotoxy(44,5); printf("Aคo de lanzamiento       %4i",cartasC[ronda].aL);
                gotoxy(40,6); printf("2"); gotoxy(44,6); printf("Duracion [min]           %4i",cartasC[ronda].duracion);
                gotoxy(40,7); printf("3"); gotoxy(44,7); printf("Ranking [IMDb]           %4.1f",cartasC[ronda].ranking);
                gotoxy(40,8); printf("4"); gotoxy(44,8); printf("Presupuesto [1M]         %4i",cartasC[ronda].presupuesto);
                gotoxy(40,9); printf("5"); gotoxy(44,9); printf("Recaudado [1M]           %4i",cartasC[ronda].recaudado);
                setD();
            }
            switch(op){
                case 1:
                    setT(BLANCO);
                    if(cartasP[ronda].aL<cartasC[ronda].aL){
                        centrar(cartasP[ronda].titulo,18,3);
                        gotoxy(9,5); printf("es mas antigua que");
                        centrar(cartasC[ronda].titulo,18,7);
                        fprintf(arch,"\n %s le gana a NIX4NDY\n",nameP);
                        fprintf(arch," %s: %i\n",cartasP[ronda].titulo,cartasP[ronda].aL);
                        fprintf(arch," %s: %i\n",cartasC[ronda].titulo,cartasC[ronda].aL);
                        pointsP++;
                    }
                    else if(cartasP[ronda].aL>cartasC[ronda].aL){
                        centrar(cartasC[ronda].titulo,18,3);
                        gotoxy(9,5); printf("es mas antigua que");
                        centrar(cartasP[ronda].titulo,18,7);
                        fprintf(arch,"\n NIX4NDY le gana a %s\n",nameP);
                        fprintf(arch," %s: %i\n",cartasP[ronda].titulo,cartasP[ronda].aL);
                        fprintf(arch," %s: %i\n",cartasC[ronda].titulo,cartasC[ronda].aL);
                        pointsC++;
                    }
                    else{
                        gotoxy(11,3); printf("Ambas pelกculas");
                        gotoxy(9,5);  printf("se estrenaron en el");
                        gotoxy(15,7); printf("aคo %i",cartasC[ronda].aL);
                        for(int emp=0;emp<2;emp++){ // ACม SE REPARTEN LAS CARTAS ALEATORIAMENTE
                            al=rand()%32;
                            if(keyR[al]==0){
                                keyR[al]=1;
                                if(emp==0){
                                    strcpy(cartasP[p].titulo,movie[al].titulo);
                                    cartasP[p].aL=movie[al].aL;
                                    cartasP[p].duracion=movie[al].duracion;
                                    cartasP[p].ranking=movie[al].ranking;
                                    cartasP[p].presupuesto=movie[al].presupuesto;
                                    cartasP[p].recaudado=movie[al].recaudado;
                                    fprintf(arch," Carta nueva de %s\n",nameP);
                                    fprintf(arch,"------------------------------------------------\n");
                                    fprintf(arch," Pelicula %s%i) %s\n",cartasP[p].grupo,cartasP[p].num,cartasP[p].titulo);
                                    fprintf(arch," A๑o de lanzamiento                        %4i\n",cartasP[p].aL);
                                    fprintf(arch," Duracion [min]                            %4i\n",cartasP[p].duracion);
                                    fprintf(arch," Ranking [IMDb]                            %4.1f\n",cartasP[p].ranking);
                                    fprintf(arch," Presupuesto [1M]                          %4i\n",cartasP[p].presupuesto);
                                    fprintf(arch," Recaudado [1M]                            %4i\n",cartasP[p].recaudado);
                                    p++;
                                }
                                else{
                                    strcpy(cartasC[c].titulo,movie[al].titulo);
                                    cartasC[c].aL=movie[al].aL;
                                    cartasC[c].duracion=movie[al].duracion;
                                    cartasC[c].ranking=movie[al].ranking;
                                    cartasC[c].presupuesto=movie[al].presupuesto;
                                    cartasC[c].recaudado=movie[al].recaudado;
                                    fprintf(arch,"------------------------------------------------\n");
                                    fprintf(arch," Carta nueva de NIX4NDY\n");
                                    fprintf(arch,"------------------------------------------------\n");
                                    fprintf(arch," Pelicula %s%i) %s\n",cartasC[c].grupo,cartasC[c].num,cartasC[c].titulo);
                                    fprintf(arch," A๑o de lanzamiento                        %4i\n",cartasC[c].aL);
                                    fprintf(arch," Duracion [min]                            %4i\n",cartasC[c].duracion);
                                    fprintf(arch," Ranking [IMDb]                            %4.1f\n",cartasC[c].ranking);
                                    fprintf(arch," Presupuesto [1M]                          %4i\n",cartasC[c].presupuesto);
                                    fprintf(arch," Recaudado [1M]                            %4i\n",cartasC[c].recaudado);
                                    c++;
                                }
                            }
                            else{
                                emp--;
                            }
                        }
                    }
                    setD();
                    getch();
                    break;
                //---------------------------------------------------
                case 2:
                    setT(BLANCO);
                    if(cartasP[ronda].duracion>cartasC[ronda].duracion){
                        centrar(cartasP[ronda].titulo,18,3);
                        gotoxy(10,5); printf("es m s larga que");
                        centrar(cartasC[ronda].titulo,18,7);
                        fprintf(arch,"\n %s le gana a NIX4NDY\n",nameP);
                        fprintf(arch," %s: %i\n",cartasP[ronda].titulo,cartasP[ronda].duracion);
                        fprintf(arch," %s: %i\n",cartasC[ronda].titulo,cartasC[ronda].duracion);
                        pointsP++;
                    }
                    else if(cartasP[ronda].duracion<cartasC[ronda].duracion){
                        centrar(cartasC[ronda].titulo,18,3);
                        gotoxy(10,5); printf("es m s larga que");
                        centrar(cartasP[ronda].titulo,18,7);
                        fprintf(arch,"\n NIX4NDY le gana a %s\n",nameP);
                        fprintf(arch," %s: %i\n",cartasP[ronda].titulo,cartasP[ronda].duracion);
                        fprintf(arch," %s: %i\n",cartasC[ronda].titulo,cartasC[ronda].duracion);
                        pointsC++;
                    }
                    else{
                        gotoxy(11,4); printf("Ambas pelกculas");
                        gotoxy(8,6);  printf("tienen igual duraciขn");

                        for(int emp=0;emp<2;emp++){ // ACม SE REPARTEN LAS CARTAS ALEATORIAMENTE
                            al=rand()%32;
                            if(keyR[al]==0){
                                keyR[al]=1;
                                if(emp==0){
                                    strcpy(cartasP[p].titulo,movie[al].titulo);
                                    cartasP[p].aL=movie[al].aL;
                                    cartasP[p].duracion=movie[al].duracion;
                                    cartasP[p].ranking=movie[al].ranking;
                                    cartasP[p].presupuesto=movie[al].presupuesto;
                                    cartasP[p].recaudado=movie[al].recaudado;
                                    fprintf(arch," Carta nueva de %s\n",nameP);
                                    fprintf(arch,"------------------------------------------------\n");
                                    fprintf(arch," Pelicula %s%i) %s\n",cartasP[p].grupo,cartasP[p].num,cartasP[p].titulo);
                                    fprintf(arch," A๑o de lanzamiento                        %4i\n",cartasP[p].aL);
                                    fprintf(arch," Duracion [min]                            %4i\n",cartasP[p].duracion);
                                    fprintf(arch," Ranking [IMDb]                            %4.1f\n",cartasP[p].ranking);
                                    fprintf(arch," Presupuesto [1M]                          %4i\n",cartasP[p].presupuesto);
                                    fprintf(arch," Recaudado [1M]                            %4i\n",cartasP[p].recaudado);
                                    p++;
                                }
                                else{
                                    strcpy(cartasC[c].titulo,movie[al].titulo);
                                    cartasC[c].aL=movie[al].aL;
                                    cartasC[c].duracion=movie[al].duracion;
                                    cartasC[c].ranking=movie[al].ranking;
                                    cartasC[c].presupuesto=movie[al].presupuesto;
                                    cartasC[c].recaudado=movie[al].recaudado;
                                    fprintf(arch,"------------------------------------------------\n");
                                    fprintf(arch," Carta nueva de NIX4NDY\n");
                                    fprintf(arch,"------------------------------------------------\n");
                                    fprintf(arch," Pelicula %s%i) %s\n",cartasC[c].grupo,cartasC[c].num,cartasC[c].titulo);
                                    fprintf(arch," A๑o de lanzamiento                        %4i\n",cartasC[c].aL);
                                    fprintf(arch," Duracion [min]                            %4i\n",cartasC[c].duracion);
                                    fprintf(arch," Ranking [IMDb]                            %4.1f\n",cartasC[c].ranking);
                                    fprintf(arch," Presupuesto [1M]                          %4i\n",cartasC[c].presupuesto);
                                    fprintf(arch," Recaudado [1M]                            %4i\n",cartasC[c].recaudado);
                                    c++;
                                }
                            }
                            else{
                                emp--;
                            }
                        }
                    }
                    setD();
                    getch();
                    break;
                //---------------------------------------------------
                case 3:
                    setT(BLANCO);
                    if(cartasP[ronda].ranking>cartasC[ronda].ranking){
                        centrar(cartasP[ronda].titulo,18,3);
                        gotoxy(6,5); printf("tiene mejor ranking que");
                        centrar(cartasC[ronda].titulo,18,7);
                        fprintf(arch,"\n %s le gana a NIX4NDY\n",nameP);
                        fprintf(arch," %s: %.1f\n",cartasP[ronda].titulo,cartasP[ronda].ranking);
                        fprintf(arch," %s: %.1f\n",cartasC[ronda].titulo,cartasC[ronda].ranking);
                        pointsP++;
                    }
                    else if(cartasP[ronda].ranking<cartasC[ronda].ranking){
                        centrar(cartasC[ronda].titulo,18,3);
                        gotoxy(6,5); printf("tiene mejor ranking que");
                        centrar(cartasP[ronda].titulo,18,7);
                        fprintf(arch,"\n NIX4NDY le gana a %s\n",nameP);
                        fprintf(arch," %s: %.1f\n",cartasP[ronda].titulo,cartasP[ronda].ranking);
                        fprintf(arch," %s: %.1f\n",cartasC[ronda].titulo,cartasC[ronda].ranking);
                        pointsC++;
                    }
                    else{
                        gotoxy(11,3); printf("Ambas pelกculas");
                        gotoxy(9,5);  printf("fueron puntadas con");
                        gotoxy(12,7); printf("%.1f estrellas",cartasP[ronda].ranking);

                        for(int emp=0;emp<2;emp++){ // ACม SE REPARTEN LAS CARTAS ALEATORIAMENTE
                            al=rand()%32;
                            if(keyR[al]==0){
                                keyR[al]=1;
                                if(emp==0){
                                    strcpy(cartasP[p].titulo,movie[al].titulo);
                                    cartasP[p].aL=movie[al].aL;
                                    cartasP[p].duracion=movie[al].duracion;
                                    cartasP[p].ranking=movie[al].ranking;
                                    cartasP[p].presupuesto=movie[al].presupuesto;
                                    cartasP[p].recaudado=movie[al].recaudado;
                                    fprintf(arch," Carta nueva de %s\n",nameP);
                                    fprintf(arch,"------------------------------------------------\n");
                                    fprintf(arch," Pelicula %s%i) %s\n",cartasP[p].grupo,cartasP[p].num,cartasP[p].titulo);
                                    fprintf(arch," A๑o de lanzamiento                        %4i\n",cartasP[p].aL);
                                    fprintf(arch," Duracion [min]                            %4i\n",cartasP[p].duracion);
                                    fprintf(arch," Ranking [IMDb]                            %4.1f\n",cartasP[p].ranking);
                                    fprintf(arch," Presupuesto [1M]                          %4i\n",cartasP[p].presupuesto);
                                    fprintf(arch," Recaudado [1M]                            %4i\n",cartasP[p].recaudado);
                                    p++;
                                }
                                else{
                                    strcpy(cartasC[c].titulo,movie[al].titulo);
                                    cartasC[c].aL=movie[al].aL;
                                    cartasC[c].duracion=movie[al].duracion;
                                    cartasC[c].ranking=movie[al].ranking;
                                    cartasC[c].presupuesto=movie[al].presupuesto;
                                    cartasC[c].recaudado=movie[al].recaudado;
                                    fprintf(arch,"------------------------------------------------\n");
                                    fprintf(arch," Carta nueva de NIX4NDY\n");
                                    fprintf(arch,"------------------------------------------------\n");
                                    fprintf(arch," Pelicula %s%i) %s\n",cartasC[c].grupo,cartasC[c].num,cartasC[c].titulo);
                                    fprintf(arch," A๑o de lanzamiento                        %4i\n",cartasC[c].aL);
                                    fprintf(arch," Duracion [min]                            %4i\n",cartasC[c].duracion);
                                    fprintf(arch," Ranking [IMDb]                            %4.1f\n",cartasC[c].ranking);
                                    fprintf(arch," Presupuesto [1M]                          %4i\n",cartasC[c].presupuesto);
                                    fprintf(arch," Recaudado [1M]                            %4i\n",cartasC[c].recaudado);
                                    c++;
                                }
                            }
                            else{
                                emp--;
                            }
                        }
                    }
                    setD();
                    getch();
                    break;
                //---------------------------------------------------
                case 4:
                    setT(BLANCO);
                    if(cartasP[ronda].presupuesto<cartasC[ronda].presupuesto){
                        centrar(cartasP[ronda].titulo,18,3);
                        gotoxy(5,5); printf("tuvo menos presupuesto que");
                        centrar(cartasC[ronda].titulo,18,7);
                        fprintf(arch,"\n %s le gana a NIX4NDY\n",nameP);
                        fprintf(arch," %s: %i\n",cartasP[ronda].titulo,cartasP[ronda].presupuesto);
                        fprintf(arch," %s: %i\n",cartasC[ronda].titulo,cartasC[ronda].presupuesto);
                        pointsP++;
                    }
                    else if(cartasP[ronda].presupuesto>cartasC[ronda].presupuesto){
                        centrar(cartasC[ronda].titulo,18,3);
                        gotoxy(5,5); printf("tuvo menos presupuesto que");
                        centrar(cartasP[ronda].titulo,18,7);
                        fprintf(arch,"\n NIX4NDY le gana a %s\n",nameP);
                        fprintf(arch," %s: %i\n",cartasP[ronda].titulo,cartasP[ronda].presupuesto);
                        fprintf(arch," %s: %i\n",cartasC[ronda].titulo,cartasC[ronda].presupuesto);
                        pointsC++;
                    }
                    else{
                        gotoxy(11,4); printf("Ambas pelกculas");
                        gotoxy(10,6);  printf("gastaron lo mismo");

                        for(int emp=0;emp<2;emp++){ // ACม SE REPARTEN LAS CARTAS ALEATORIAMENTE
                            al=rand()%32;
                            if(keyR[al]==0){
                                keyR[al]=1;
                                if(emp==0){
                                    strcpy(cartasP[p].titulo,movie[al].titulo);
                                    cartasP[p].aL=movie[al].aL;
                                    cartasP[p].duracion=movie[al].duracion;
                                    cartasP[p].ranking=movie[al].ranking;
                                    cartasP[p].presupuesto=movie[al].presupuesto;
                                    cartasP[p].recaudado=movie[al].recaudado;
                                    fprintf(arch," Carta nueva de %s\n",nameP);
                                    fprintf(arch,"------------------------------------------------\n");
                                    fprintf(arch," Pelicula %s%i) %s\n",cartasP[p].grupo,cartasP[p].num,cartasP[p].titulo);
                                    fprintf(arch," A๑o de lanzamiento                        %4i\n",cartasP[p].aL);
                                    fprintf(arch," Duracion [min]                            %4i\n",cartasP[p].duracion);
                                    fprintf(arch," Ranking [IMDb]                            %4.1f\n",cartasP[p].ranking);
                                    fprintf(arch," Presupuesto [1M]                          %4i\n",cartasP[p].presupuesto);
                                    fprintf(arch," Recaudado [1M]                            %4i\n",cartasP[p].recaudado);
                                    p++;
                                }
                                else{
                                    strcpy(cartasC[c].titulo,movie[al].titulo);
                                    cartasC[c].aL=movie[al].aL;
                                    cartasC[c].duracion=movie[al].duracion;
                                    cartasC[c].ranking=movie[al].ranking;
                                    cartasC[c].presupuesto=movie[al].presupuesto;
                                    cartasC[c].recaudado=movie[al].recaudado;
                                    fprintf(arch,"------------------------------------------------\n");
                                    fprintf(arch," Carta nueva de NIX4NDY\n");
                                    fprintf(arch,"------------------------------------------------\n");
                                    fprintf(arch," Pelicula %s%i) %s\n",cartasC[c].grupo,cartasC[c].num,cartasC[c].titulo);
                                    fprintf(arch," A๑o de lanzamiento                        %4i\n",cartasC[c].aL);
                                    fprintf(arch," Duracion [min]                            %4i\n",cartasC[c].duracion);
                                    fprintf(arch," Ranking [IMDb]                            %4.1f\n",cartasC[c].ranking);
                                    fprintf(arch," Presupuesto [1M]                          %4i\n",cartasC[c].presupuesto);
                                    fprintf(arch," Recaudado [1M]                            %4i\n",cartasC[c].recaudado);
                                    c++;
                                }
                            }
                            else{
                                emp--;
                            }
                        }
                    }
                    setD();
                    getch();
                    break;
                //---------------------------------------------------
                case 5:
                    setT(BLANCO);
                    if(cartasP[ronda].recaudado>cartasC[ronda].recaudado){
                        centrar(cartasP[ronda].titulo,18,3);
                        gotoxy(4,5); printf("mundialmente recaudข m s que");
                        centrar(cartasC[ronda].titulo,18,7);
                        fprintf(arch,"\n %s le gana a NIX4NDY\n",nameP);
                        fprintf(arch," %s: %i\n",cartasP[ronda].titulo,cartasP[ronda].recaudado);
                        fprintf(arch," %s: %i\n",cartasC[ronda].titulo,cartasC[ronda].recaudado);
                        pointsP++;
                    }
                    else if(cartasP[ronda].recaudado<cartasC[ronda].recaudado){
                        centrar(cartasC[ronda].titulo,18,3);
                        gotoxy(4,5); printf("mundialmente recaudข m s que");
                        centrar(cartasP[ronda].titulo,18,7);
                        fprintf(arch,"\n NIX4NDY le gana a %s\n",nameP);
                        fprintf(arch," %s: %i\n",cartasP[ronda].titulo,cartasP[ronda].recaudado);
                        fprintf(arch," %s: %i\n",cartasC[ronda].titulo,cartasC[ronda].recaudado);
                        pointsC++;
                    }
                    else{
                        gotoxy(11,4); printf("Ambas pelกculas");
                        gotoxy(9,6);  printf("recaudaron lo mismo");

                        for(int emp=0;emp<2;emp++){ // ACม SE REPARTEN LAS CARTAS ALEATORIAMENTE
                            al=rand()%32;
                            if(keyR[al]==0){
                                keyR[al]=1;
                                if(emp==0){
                                    strcpy(cartasP[p].titulo,movie[al].titulo);
                                    cartasP[p].aL=movie[al].aL;
                                    cartasP[p].duracion=movie[al].duracion;
                                    cartasP[p].ranking=movie[al].ranking;
                                    cartasP[p].presupuesto=movie[al].presupuesto;
                                    cartasP[p].recaudado=movie[al].recaudado;
                                    fprintf(arch," Carta nueva de %s\n",nameP);
                                    fprintf(arch,"------------------------------------------------\n");
                                    fprintf(arch," Pelicula %s%i) %s\n",cartasP[p].grupo,cartasP[p].num,cartasP[p].titulo);
                                    fprintf(arch," A๑o de lanzamiento                        %4i\n",cartasP[p].aL);
                                    fprintf(arch," Duracion [min]                            %4i\n",cartasP[p].duracion);
                                    fprintf(arch," Ranking [IMDb]                            %4.1f\n",cartasP[p].ranking);
                                    fprintf(arch," Presupuesto [1M]                          %4i\n",cartasP[p].presupuesto);
                                    fprintf(arch," Recaudado [1M]                            %4i\n",cartasP[p].recaudado);
                                    p++;
                                }
                                else{
                                    strcpy(cartasC[c].titulo,movie[al].titulo);
                                    cartasC[c].aL=movie[al].aL;
                                    cartasC[c].duracion=movie[al].duracion;
                                    cartasC[c].ranking=movie[al].ranking;
                                    cartasC[c].presupuesto=movie[al].presupuesto;
                                    cartasC[c].recaudado=movie[al].recaudado;
                                    fprintf(arch,"------------------------------------------------\n");
                                    fprintf(arch," Carta nueva de NIX4NDY\n");
                                    fprintf(arch,"------------------------------------------------\n");
                                    fprintf(arch," Pelicula %s%i) %s\n",cartasC[c].grupo,cartasC[c].num,cartasC[c].titulo);
                                    fprintf(arch," A๑o de lanzamiento                        %4i\n",cartasC[c].aL);
                                    fprintf(arch," Duracion [min]                            %4i\n",cartasC[c].duracion);
                                    fprintf(arch," Ranking [IMDb]                            %4.1f\n",cartasC[c].ranking);
                                    fprintf(arch," Presupuesto [1M]                          %4i\n",cartasC[c].presupuesto);
                                    fprintf(arch," Recaudado [1M]                            %4i\n",cartasC[c].recaudado);
                                    c++;
                                }
                            }
                            else{
                                emp--;
                            }
                        }
                    }
                    setD();
                    getch();
                    break;
                //---------------------------------------------------
                default:
                    gotoxy(41,17);
                    setT(ROJOI);printf(">> ERROR <<"); setD();
                    getch();
                    ronda--;
                    break;
            }
        }

        fclose(arch);
        system("CLS");
        base();
        if(pointsC<pointsP){
            pixelArt(4);
            setT(MAGENTA);
            centrarT("ษอออออออออออออออออออออออออออออออออออป",37,8);
            for(int y=9;y<12;y++){
                centrarT("บ                                   บ",37,y);
            }
            centrarT("ศอออออออออออออออออออออออออออออออออออผ",37,12);
            setD();
            setT(BLANCO);
            centrarT(strcat(nameP," gana"),37,9);
            gotoxy(34,11); printf("%i",pointsP);
            centrarT("vs",37,11);
            gotoxy(39,11); printf("%i",pointsC);
            setD();
            gotoxy(0,0);
        }
        else{
            setT(MAGENTA);
            centrarT("ษอออออออออออออออออออออออออออออออออออป",37,8);
            for(int y=9;y<12;y++){
                centrarT("บ                                   บ",37,y);
            }
            centrarT("ศอออออออออออออออออออออออออออออออออออผ",37,12);
            setD();
            setT(BLANCO);
            centrarT("NIX4NDY GANA",37,9);
            gotoxy(34,11); printf("%i",pointsP);
            centrarT("vs",37,11);
            gotoxy(39,11); printf("%i",pointsC);
            setD();
            gotoxy(0,0);
        }

        int x;
        puntaje=fopen(puntosArchivo,"rb");

        if(puntaje==NULL){
            fclose(puntaje);
            puntaje=fopen(puntosArchivo,"wb");
            fprintf(puntaje,"%i",pointsP);
            fclose(puntaje);
        }
        else{
            while(feof(puntaje)==0){
                fscanf(puntaje,"%i",&x);
            }
            fclose(puntaje);
            puntaje=fopen(puntosArchivo,"wb");
            fprintf(puntaje,"%i",x+pointsP);
            fclose(puntaje);
        }

        fclose(puntaje);
        getch();
        system("CLS");
        break;
    }
}

void cargarPartida(){
    char nameP[MAX];
    char nArch[MAX];
    char pArch[MAX];
    char caracter;
    int x;

    base();
    setT(BLANCO);
    centrarT(">> CARGAR PARTIDA <<",37,4);
    centrarT(">> INGRESE SU USUARIO <<",37,11);
    setD();
    setT(MAGENTA);
    gotoxy(0,6); printf("ฬอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน");
    setD();
    pixelArt(2);
    pixelArt(3);
    gotoxy(28,13); setT(AMARILLOI); printf(" "); setD();
    setT(BLANCO); scanf("%s",&nameP); setD();
    strcpy(pArch,nameP);
    strcpy(nArch,nameP);
    strcat(pArch," puntos.txt");
    strcat(nArch,".txt");
    if((arch=fopen(nArch,"rt"))!=NULL){
        puntaje=fopen(pArch,"rt");
        system("CLS");
        while(feof(puntaje)==0){
            fscanf(puntaje,"%i",&x);
            printf("------------------------------------------------\n");
            printf("                   PUNTAJE: %i                   \n",x);
            printf("------------------------------------------------\n");
        }
        while(feof(arch)==0){
            fscanf(arch,"%c",&caracter);
            printf("%c",caracter);
        }

    }
    else{
        setT(BLANCO);
        centrarT(">> NO SE ENCUENTRA LA PARTIDA <<",37,13);
        setD();
    }

    fclose(arch);
    getch();
    system("CLS");
}
//-----------------------------------------------------------
void pixelArt(int num){
    switch(num){
        case 1:
            setT(GRIS_OSCURO); centrarT("   Û     ",62,4); centrarT("  ÛÜ     ",62,5); setD();
            setT(AZUL); centrarT("ÛÛÛÛÛÛÛÜÜ",62,7); centrarT("ÛÛÛÛÛÛÛÜÛ",62,8); centrarT("฿ÛÛÛÛÛ฿  ",62,9); setD();
            break;
        case 2:
            gotoxy(5,9);  printf("   ÜÜÛÛÛÛÜÜ");
            gotoxy(5,10); printf(" ÜÛÛÛÛÛ฿฿฿฿฿Ü");
            gotoxy(5,11); printf("ÜÛÛÛÛÛ");
            gotoxy(5,12); printf("ÛÛÛÛÛÛ");
            gotoxy(5,13); printf("฿ÛÛÛÛÛ");
            gotoxy(5,14); printf(" ฿ÛÛÛÛÛÜÜÜÜÜ฿");
            gotoxy(5,15); printf("   ฿฿ÛÛÛÛ฿฿");
            break;
        case 3:
            gotoxy(57,9);  printf("  ÜÜÛÛÛÛÜÜ");
            gotoxy(57,10); printf("Ü฿฿฿฿฿ÛÛÛÛÛÜ");
            gotoxy(57,11); printf("       ÛÛÛÛÛÜ");
            gotoxy(57,12); printf("       ÛÛÛÛÛÛ");
            gotoxy(57,13); printf("       ÛÛÛÛÛ฿");
            gotoxy(57,14); printf("฿ÜÜÜÜÜÛÛÛÛÛ฿");
            gotoxy(57,15); printf("  ฿฿ÛÛÛÛ฿฿");
            break;
        case 4:
            setT(ROJOI);
            gotoxy(7,4); printf("þ"); gotoxy(21,10); printf("þ"); gotoxy(68,16); printf("þ");
            gotoxy(52,6); printf("þ"); gotoxy(62,4); printf("þ"); gotoxy(70,14); printf("þ");
            gotoxy(4,8); printf("þ"); gotoxy(37,12); printf("þ"); gotoxy(5,13); printf("þ");
            gotoxy(15,7); printf("þ"); gotoxy(28,9); printf("þ"); gotoxy(65,13); printf("þ");
            gotoxy(20,15); printf("þ"); gotoxy(42,6); printf("þ");
            setD();
            setT(AMARILLOI);
            gotoxy(14,5); printf("þ"); gotoxy(54,11); printf("þ"); gotoxy(32,13); printf("þ");
            gotoxy(34,6); printf("þ"); gotoxy(3,11); printf("þ"); gotoxy(63,15); printf("þ");
            gotoxy(71,9); printf("þ"); gotoxy(51,10); printf("þ"); gotoxy(29,14); printf("þ");
            gotoxy(22,13); printf("þ"); gotoxy(61,6); printf("þ"); gotoxy(16,9); printf("þ");
            gotoxy(41,10); printf("þ");
            setD();
            setT(VERDEI);
            gotoxy(49,7); printf("þ"); gotoxy(71,12); printf("þ"); gotoxy(60,9); printf("þ");
            gotoxy(8,6); printf("þ"); gotoxy(11,15); printf("þ"); gotoxy(45,16); printf("þ");
            gotoxy(59,4); printf("þ"); gotoxy(30,5); printf("þ"); gotoxy(26,6); printf("þ");
            gotoxy(33,10); printf("þ"); gotoxy(50,14); printf("þ"); gotoxy(28,11); printf("þ");
            setD();
            setT(AZULI);
            gotoxy(70,14); printf("þ"); gotoxy(37,8); printf("þ"); gotoxy(4,15); printf("þ");
            gotoxy(34,4); printf("þ"); gotoxy(21,5); printf("þ"); gotoxy(70,5); printf("þ");
            gotoxy(42,4); printf("þ"); gotoxy(41,13); printf("þ"); gotoxy(58,14); printf("þ");
            gotoxy(7,10); printf("þ"); gotoxy(15,11); printf("þ"); gotoxy(24,9); printf("þ");
            gotoxy(11,13); printf("þ"); gotoxy(30,16); printf("þ"); gotoxy(47,11); printf("þ");
            setD();
            break;
    }
}
//-----------------------------------------------------------
void finPrograma(){
    base();
    setT(BLANCO);
    centrarT(">> FIN DEL PROGRAMA <<",37,10);
    setD();
    gotoxy(74,18);
}

int menuInicio(){
    int opMenu=0;

    base();
    setT(BLANCO);
    centrarT(">> MEN้ <<",25,4);
    centrarT("1)  COMENZAR PARTIDA",25,8);
    centrarT("2)  CARGAR PARTIDA",25,10);
    centrarT("3)  INFORMACIเN DE PELึCULAS",25,12);
    centrarT("4)  CเMO JUGAR",25,14);
    centrarT("5)  SALIDA",25,16);
    centrarT("INGRESE SU OPCIเN",62,14);
    centrarT(">>   <<",62,16);
    setD();
    pixelArt(1);
    setT(MAGENTA);
    gotoxy(0,2); printf("ฬออออออออออออออออออออออออสอออออออออออออออออออออออฮออออออออออออออออออออออออน");
    for(int lin=3;lin<6;lin++){
        gotoxy(0,lin); printf("บ"); gotoxy(49,lin); printf("บ"); gotoxy(74,lin); printf("บ");
    }
    gotoxy(0,6); printf("ฬออออออออออออออออออออออออออออออออออออออออออออออออน"); gotoxy(74,6); printf("บ");
    for(int lin=7;lin<18;lin++){
        gotoxy(0,lin); printf("บ"); gotoxy(49,lin); printf("บ"); gotoxy(74,lin); printf("บ");
    }
    gotoxy(49,12); printf("ฬออออออออออออออออออออออออน");
    gotoxy(0,18);printf("ศออออออออออออออออออออออออออออออออออออออออออออออออสออออออออออออออออออออออออผ");
    setD();

    gotoxy(62,16); setT(BLANCO); scanf("%i",&opMenu); gotoxy(62,16); setD();

    switch(opMenu){
        case 1:
            system("CLS");
            nuevaPartida();
            break;
        case 2:
            system("CLS");
            cargarPartida();
            break;
        case 3:
            system("CLS");
            infoPelis();
            break;
        case 4:
            system("CLS");
            reglas();
            break;
        default:
            if(opMenu==5) break;
            gotoxy(57,16); setT(ROJOI); printf(">> ERROR <<"); setD();
            gotoxy(0,0); getch();
            system("CLS");
            break;
    }
    return opMenu;
}
//-----------------------------------------------------------
void main(){
    int menu;

    system("CLS");
    srand(time(NULL));
    setTitle("Trabajo Pr ctico Final - Olivera, Johanna Sayi");

    for(;;){
        menu=menuInicio();
        if(menu==5) break;
    }

    system("CLS");
    finPrograma();
    return;
}
