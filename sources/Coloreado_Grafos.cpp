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
#include <list> 
using namespace std; 


template <class T>
class Grafo {
    T V; ///Número de Vértices
    list<T> * nodos; ///Lista de adyacencia


    public:
        Grafo(T size){
            V=size;
            nodos=new list<T>[V]; 
        }


        /**
         * Añade vértices al grafo
         *  
         * Se le asigna a cada nodo su relación simulando vétices y aristas
         * 
         * @param dos vértices que son genéricos
         * 
         */
        void sumar_vertice(T v1, T v2){
            nodos[v1].push_back(v2); 
            nodos[v2].push_back(v1);
        }

        /**
         * Colorea todos los nodos buscando el menor número de colores
         * 
         * Se utiliza una estructura externa de booleanos para mantener un control de coloreado,
         * entonces con base en esa estructura se van analizando de manera iterativa qué color siguen
         * tomando en consideración la adyacencia.
         * 
        */
        void colorear(){ 
            T resultado[V]; 

            resultado[0]  = 0; ///Asignamos siempre el color uno en el primer vetice

            for (int u = 1; u < V; u++) {
                resultado[u] = -1; 
            }

            bool available[V]; ///Arreglo de booleanos para tener un control sobre que nodos ha sido coloreados

            for (int i = 0; i < V; i++) {
                available[i] = false; 
            }

            ///Asignación del color
            for (int j = 1; j < V; j++) 
            { 
                list<int>::iterator i; 
                for (i = nodos[j].begin(); i != nodos[j].end(); ++i){
                    if (resultado[*i] != -1) {
                        available[resultado[*i]] = true; 
                    }
                }

                int color; 
                for (color = 0; color < V; color++) {
                    if (available[color] == false) {
                        break; 
                    }
                }
                resultado[j] = color; 

                for (i = nodos[j].begin(); i != nodos[j].end(); ++i) {
                    if (resultado[*i] != -1) {
                        available[resultado[*i]] = false; 
                    }
                }
        }

            for (int j = 0; j < V; j++){
                cout << "Nodo " << j << "-> Color "<< resultado[j] << endl;
            }
        }
        ~Grafo(){
            delete[]nodos;
        } 

};


    int main() 
    { 
        ///Para observar la composición visual del grafo leer el README.md
        Grafo <int> g(6); 
  
        g.sumar_vertice(0, 1); 
        g.sumar_vertice(0, 2); 
        g.sumar_vertice(0, 4);
        g.sumar_vertice(0, 5);

        g.sumar_vertice(1, 2); 
        g.sumar_vertice(1, 3); 
        g.sumar_vertice(1, 5);

        g.sumar_vertice(2, 3); 
        g.sumar_vertice(2, 4);

        g.sumar_vertice(3, 4); 
        g.sumar_vertice(3, 5); 

        g.sumar_vertice(4, 5); 

        cout << "Colores del grafo\n"; 
        g.colorear();  

        return 0; 
    } 