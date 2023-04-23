#include <stdio.h>
#include <stdlib.h>
#define TAMANIO 3 //defino una constante
//Programa de TATETI
//Tablero inicializado con las posiciones de 1 a 9
void IniciarTablero(char tablero[TAMANIO][TAMANIO]);
void MostrarTablero(char tablero[TAMANIO][TAMANIO]);
int VerificarPosicion(char tablero[TAMANIO][TAMANIO], int posicion);
int VerificarNumero(int posicion);
void Jugar(char tablero[TAMANIO][TAMANIO], int numerodejugador);
int SiguienteJugador(int numerodejugador);
int ComprobarGanador(char tablero[TAMANIO][TAMANIO]);
int main(void){

 char tablero[TAMANIO][TAMANIO]; //Tablero de 9 char en una matriz de 3 x 3
 int numerodejugador = 1; //Arranca el jugador 1
 int ganador = 0; //No hay Ganador
 //inicio el tablero de 3 x 3
 IniciarTablero(tablero); //pongo los numeros del 1 al 9
 //Muestro el tablero
 MostrarTablero(tablero); //Muestro el tablero
 while (ganador==0){ //Mientras no tengamos ganador
 Jugar(tablero, numerodejugador); //El jugador juega
 numerodejugador = SiguienteJugador(numerodejugador); //Se cambia de jugador
 MostrarTablero(tablero); //Se muetras se progreso
 ganador = ComprobarGanador(tablero); //Se verifica si termino el juego
 }


return 0;
}

void IniciarTablero(char tablero[TAMANIO][TAMANIO]){
 tablero[0][0] = '1';
 tablero[0][1] = '2';
 tablero[0][2] = '3';
 tablero[1][0] = '4';
 tablero[1][1] = '5';
 tablero[1][2] = '6';
 tablero[2][0] = '7';
 tablero[2][1] = '8';
 tablero[2][2] = '9';
}
void MostrarTablero(char tablero[TAMANIO][TAMANIO]){
 for (int i =0; i<TAMANIO;i++){
 for (int j=0; j<TAMANIO;j++){
 printf(" %c | ",tablero[i][j]) ;
 }//cierro el for de columna
 printf("\n");
 }//Cierro el for de renglon

};
int VerificarPosicion(char tablero[TAMANIO][TAMANIO], int posicion){

int retorno = 0; //Devuelvo 0 si esta libre, 1 si esta ocupad
 switch (posicion){
case 1: if(tablero[0][0] =='O'||tablero[0][0] =='X'){printf("Posicion Ocupada!!!\n\a");
retorno = 1;};
break;
case 2: if(tablero[0][1] =='O'||tablero[0][1] =='X'){printf("Posicion Ocupada!!!\n\a");
retorno = 1;};
break;
case 3: if(tablero[0][2] =='O'||tablero[0][2] =='X'){printf("Posicion Ocupada!!!\n\a");
retorno = 1;};
break;
case 4: if(tablero[1][0] =='O'||tablero[1][0] =='X'){printf("Posicion Ocupada!!!\n\a");
retorno = 1;};
break;
case 5: if(tablero[1][1] =='O'||tablero[1][1] =='X'){printf("Posicion Ocupada!!!\n\a");
retorno = 1;};
break;
case 6: if(tablero[1][2] =='O'||tablero[1][2] =='X'){printf("Posicion Ocupada!!!\n\a");
retorno = 1;};
break;
case 7: if(tablero[2][0] =='O'||tablero[2][0] =='X'){printf("Posicion Ocupada!!!\n\a");
retorno = 1;};
break;
case 8: if(tablero[2][1] =='O'||tablero[2][1] =='X'){printf("Posicion Ocupada!!!\n\a");
retorno = 1;};
break;
case 9: if(tablero[2][2] =='O'||tablero[2][2] =='X'){printf("Posicion Ocupada!!!\n\a");
retorno = 1;};
break;
 }

return retorno;
};
int VerificarNumero(int posicion){
int retorno = 0;
if(posicion<1|| posicion>9){
 retorno = 1;
}
return retorno;
};

void Jugar(char tablero[TAMANIO][TAMANIO], int numerodejugador){
int posicion = 0;
printf("Turno del jugador %d, ¿en que posicion quiere jugar? \n", numerodejugador);
scanf("%d", &posicion);

int numeroincorrecto = VerificarNumero(posicion);
if (numeroincorrecto ==1){
 printf("\aPOSICION INCORRECTA. \n");
 Jugar(tablero, numerodejugador);
}
int posicionocupada = VerificarPosicion(tablero, posicion);
if (posicionocupada==0){
if (numerodejugador ==2){
 switch (posicion){
case 1: tablero[0][0] ='X'; break;
case 2: tablero[0][1] ='X'; break;
case 3: tablero[0][2] ='X'; break;
case 4: tablero[1][0] ='X'; break;
case 5: tablero[1][1] ='X'; break;
case 6: tablero[1][2] ='X'; break;
case 7: tablero[2][0] ='X'; break;
case 8: tablero[2][1] ='X'; break;
case 9: tablero[2][2] ='X'; break;
 }//cierra el switch
}
if (numerodejugador ==1){
 switch (posicion){
case 1: tablero[0][0] ='O'; break;
case 2: tablero[0][1] ='O'; break;
case 3: tablero[0][2] ='O'; break;
case 4: tablero[1][0] ='O'; break;
case 5: tablero[1][1] ='O'; break;
case 6: tablero[1][2] ='O'; break;
case 7: tablero[2][0] ='O'; break;
case 8: tablero[2][1] ='O'; break;
case 9: tablero[2][2] ='O'; break;
 }//cierra el switch
}
}
if(posicionocupada==1){
 Jugar(tablero, numerodejugador);
}
}//Cierra el jugar
int SiguienteJugador(int numerodejugador){
int retorno = 0;
if (numerodejugador==1){retorno =2;};
if (numerodejugador==2){retorno =1;};
return retorno;
}

int ComprobarGanador(char tablero[TAMANIO][TAMANIO]){
 int retorno = 0; //Si no hay ganador se queda en 0
 //verifico si hay ganador por renglon
 for (int i = 0; i<3; i++){
 if(tablero[i][0]=='O'&&tablero[i][1]=='O'&&tablero[i][2]=='O'){
 retorno= 1;
 printf("Felicidades, gano el jugador: %d \n", retorno);
 }//cierra el if
 if(tablero[i][0]=='X'&&tablero[i][1]=='X'&&tablero[i][2]=='X'){
 retorno= 2;
 printf("Felicidades, gano el jugador: %d \n", retorno);
 }//cierra el if
 }//Cierro renglon
 //verifico si hay ganador por columna
 for (int i = 0; i<3; i++){
 if(tablero[0][i]=='O'&&tablero[1][i]=='O'&&tablero[2][i]=='O'){
 retorno= 1;
 printf("Felicidades, gano el jugador: %d \n", retorno);
 }//cierra el if
 if(tablero[1][i]=='X'&&tablero[1][i]=='X'&&tablero[2][i]=='X'){
 retorno= 2;
 printf("Felicidades, gano el jugador: %d \n", retorno);
 }//cierra el if
 }//Cierro columna
 //verifico las diagonales
 if(tablero[0][0]=='O'&&tablero[1][1]=='O'&&tablero[2][2]=='O'){
 retorno= 1;
 printf("Felicidades, gano el jugador: %d \n", retorno);
 }
 if(tablero[0][0]=='X'&&tablero[1][1]=='X'&&tablero[2][2]=='X'){
 retorno= 2;
 printf("Felicidades, gano el jugador: %d \n", retorno);
 }
 if(tablero[0][2]=='O'&&tablero[1][1]=='O'&&tablero[2][0]=='O'){
 retorno= 1;
 printf("Felicidades, gano el jugador: %d \n", retorno);
 }
 if(tablero[0][2]=='X'&&tablero[1][1]=='X'&&tablero[2][0]=='X'){
 retorno= 2;
 printf("Felicidades, gano el jugador: %d \n", retorno);
 }
return retorno;
}//Cierro comprobar
