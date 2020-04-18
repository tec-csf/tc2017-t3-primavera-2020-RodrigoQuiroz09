/**
 * Este archivo es parte de la tarea 3
 *
 * Desarrollado para la clase de Análisis y diseño de Algoritmos.
 * Este producto fue desarrollado por Rodrigo Quiroz Reyes.
 * Ver el arichivo de COPYRIGHT al inicio del directorio
 * para detalles del la autenticidad del código
 * 
 * Este es un programa libre: usted puede redistribuirlo y/o modiicarlo
 * bajo los términos de la Licencia Pública General de GNU publicada por 
 * Free Software Foundation, ya sea la versión 3 de la Licencia o
 * (a su elección) cualquier versión posterior
 * 
 * Este programa se distribuye con la esperanza de que sea útil,
 * pero SIN NINGUNA GARANTÍA; sin siquiera la garantía implícita de
 * COMERCIABILIDAD o APTITUD PARA UN PROPÓSITO EN PARTICULAR.
 * Vea la Licencia Pública General de GNU para más detalles.
 *
 * Debería haber recibido una copia de GNU General Public License
 * junto con este programa. Si no, vea <https://www.gnu.org/licenses/>.
 */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <stdlib.h> 
#include <vector>
using namespace std; 

char tablero [3][3]  = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
char humano='X';
char ai='O';
int turno=0;

int posible[9];

/**
* Checa que casillas hay disponibles en el tablero.
*  
* Se van comparando cada una de las casillas y si esta se encuentra vacia almacena la tupla
* que simboliza una pocisión en el tablero.
*
* @param vector conformado por pares el cual es pasado por referencia.
* 
*/

void checar_disponibilidad(vector <pair<int,int> > &regreso){

    int z=0;

    for (int i =0;i<3;i++){

        for (int j =0;j<3;j++){
          if(tablero[i][j]==' '){
            regreso[z].first=i;
            regreso[z].second=j;
          }else{
            regreso[z].first=3;
            regreso[z].second=3;
          }
            z++;
          
        }
   
    }

    cout<<"\n";
}

/**
* Checa que el número de casillas disponibles en el tablero.
*  
* Se van comparando cada una de las casillas y si esta se encuentra vacia 
* se añade a un contador.
*
* @return int tamaño de casillas disponibles.
* 
*/
int antes_de_checar_disponibilidad(){
    int tamano=0;

     for (int v =0;v<3;v++){

        for (int j =0;j<3;j++){

            if(tablero[v][j]== ' '){
                ++tamano;
            }
        }
    }

  return tamano;  
}


/**
* Comparaciones para no repetir codigo en la funcion checkWinner().
*
* @param char a,b,c; -> Son las casillas de una linea.
* @return bool -> Regresa si todas son iguales pero diferente de espacio vacio.
* 
*/
bool comparacion(char a, char b, char c) {
  return (a == b && b == c && a !=' ');
}



//Dar formato a la impresión de el tablero.
void imprimir_tablero(){
  int z=0;
    for (int i=0;i<3;++i,z++){
          cout<<"    "<<z<<"|    "<<z+1<<"|   "<<z+2<<endl;
        for (int j=0;j<3;++j){
            if(j<2){
            cout<<"  "<<tablero[i][j]<<"  |";
            }
            else
            {
            cout<<"  "<<tablero[i][j];
            }
        }
        z++;
        z++;
        cout<<"\n";
        if(i<2)
        cout<<"_____|_____|_____"<<endl;

    }
    cout<<"     |     |    "<<endl;
}

/**
* Comparaciones para escoger un ganador.
*
* Realiza por cada tipo de caso de éxito las comparaciones de lineas iguales.
*
* @return char ganador regresa el caractér que ha ganado o si ha sido un empate.
* 
*/
char checar_ganador() {
  char ganador = ' ';

  // horizontal
  for (int i = 0; i < 3; i++) {
    if (comparacion(tablero[i][0], tablero[i][1], tablero[i][2])) {
      ganador = tablero[i][0];
    }
  }

  // Vertical
  for (int i = 0; i < 3; i++) {
    if (comparacion(tablero[0][i], tablero[1][i], tablero[2][i])) {
      ganador = tablero[0][i];
    }
  }

  // Diagonal
  if (comparacion(tablero[0][0], tablero[1][1], tablero[2][2])) {
    ganador = tablero[0][0];
  }
  if (comparacion(tablero[2][0], tablero[1][1], tablero[0][2])) {
    ganador = tablero[2][0];
  }
  int check=antes_de_checar_disponibilidad();
  if(check==0){
    return '1';
  }

  if (ganador == ' ') {
    return '0';
  } else {
    return ganador;
  }
}

/**
* Metodo recursivo que decide la mejor opción de la ai.
*
* Realiza todo tipo de combinaciones al llamarse recursivamente cubriendo todos los casos
* y va regresando el caso que tenga mayor beneficio para la ia.
*
* @return int beneficio con el cual decicimos si es una opción óptima o no.
* 
*/
int minimax(bool es_max){

  char resultado=checar_ganador();
  if(resultado!='0'){
    if(resultado=='X'){

      return -1;
    }else if(resultado=='O'){

      return 1;
    }else if(resultado=='1'){

      return 0;
    }
  }

  
  if (es_max){
    int mejor_puntaje=-1000;
    for (int i =0;i<3;i++){
      for (int j =0;j<3;j++){
          if(tablero[i][j]== ' '){
            tablero[i][j]=ai;
            int puntaje=minimax(false);
            tablero[i][j]=' ';
            mejor_puntaje=max(puntaje,mejor_puntaje);
          }
      }
  }
  return mejor_puntaje;
  }else{
     int mejor_puntaje=1000;
    for (int i =0;i<3;i++){
      for (int j =0;j<3;j++){
          if(tablero[i][j]== ' '){
            tablero[i][j]=humano;
            int puntaje=minimax(true);
            tablero[i][j]=' ';
             mejor_puntaje=min(puntaje,mejor_puntaje);
          }
      }
  }
 return mejor_puntaje;
  }

}

/**
* Metodo auxiliar que empieza la recursividad.
*
* Empieza por un ciclo anidado que va decidiendo conforme al método recursivo, la mejor decisión
* y genera el cambio en el tablero.
* 
*/
void mejor_movimiento(){
  int mejor_puntaje=-100000;
  int casilla [2];
     for (int i =0;i<3;i++){
        for (int j =0;j<3;j++){
            if(tablero[i][j]== ' '){
              tablero[i][j]=ai;
            
              int puntaje = minimax(false);
              tablero[i][j]=' ';
               
              if(puntaje>mejor_puntaje){
              mejor_puntaje=puntaje;
              casilla[0]=i;
              casilla[1]=j;
              }
            }
        }
    }

      
    tablero[casilla[0]][casilla[1]]=ai;   
    turno=0;

}

/**
* Metodo del movimiento del jugador.
*
* Con base en el vector de disponibilidades va checando si el input del usuario es válido o no
* y si es válido modifica el tablero con la posición asignada.
*
* @param vector diponibilidad en el tablero de manera actualizada.
* 
*/

void movimiento_jugador(int x, vector <pair<int,int> > &lista_disponibilidad){

    int s=antes_de_checar_disponibilidad();
    int j=0;
    int todas_casillas[9]={0,1,2,3,4,5,6,7,8};

    for(int i=0;i<9;i++){
      if(lista_disponibilidad[i].first!=3){
        posible[j]=i;
        j++;
      }
    }

    int z=0;
    for(int i=0;i<j;i++){
      if(posible[i]==x){
        z++;
      }
    }
    if(z==0){
      cout<<"escoja otra casilla valida"<<endl;
    return;
    }
    int indice = todas_casillas[x];

    int casilla [2]={lista_disponibilidad[indice].first,lista_disponibilidad[indice].second};
    tablero[casilla[0]][casilla[1]]=humano;
    turno=1;
}


int main(){
  char ganador;
  bool juego=true;
  int casilla=0;

  vector <pair<int,int> > disponibilidad(9);

    while(juego){
      checar_disponibilidad(disponibilidad);

      if(turno ==0){
        
        imprimir_tablero();
        cout<<"Jugador: ";
        cin>>casilla;
        movimiento_jugador(casilla,disponibilidad);

      }else {
        mejor_movimiento();
      }

      ganador=checar_ganador();
      
        if(ganador=='1'){
          juego=false;
          imprimir_tablero();
          cout<<"EMPATE"<<endl;
        } else if(ganador!='0'){
          juego=false;
          imprimir_tablero();
          cout<<ganador<<"GANA"<<endl;
        }
    }
    return 0;
}