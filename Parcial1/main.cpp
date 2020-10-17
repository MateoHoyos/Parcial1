#include <iostream>
using namespace std;

/*
 *
 * Opciones del programa
0- salir

1 Generar disparos (al menos tres) ofensivos que comprometan la integridad del cañón defen-
sivo.

2. Generar disparos (al menos tres) defensivos que comprometan la integridad del cañón ofen-
sivo.

3. Dado un disparo ofensivo, generar (al menos tres) disparos defensivos que impida que el ca-
ñón defensivo sea destruido sin importar si el cañón ofensivo pueda ser destruido.

4. Dado un disparo ofensivo, generar (al emnos tres) disparo defensivos que impidan que los
cañones defensivo y ofensivo puedan ser destruidos.
*/
void Generar_disparos_ofensivos();
void Generar_disparos_defensivos();

//***************************
//variables globales
float g=9.81;
float H0=1;
float HD=2;
float grados0=0;
float gradosH=0;
int n=0;
//***************************


int main()
{


    cout<<"Sistema de disparo ofensivo"<<endl;
    cout<<"1 Generar disparos"<<endl;
    cout<<"2. Generar disparos"<<endl;
    cout<<"3. Dado un disparo ofensivo"<<endl;
    cout<<"4. Dado un disparo ofensivo"<<endl;
    cout<<"0- salir"<<endl<<endl;


    do  {
        cout<<"Ingrese un numero: ";cin>>n;
        switch(n)
        {
            case 0:
            cout<<"Exit"<<endl<<endl;
            break;

            case 1:
            Generar_disparos_ofensivos();
            break;

            case 2:
            break;

            case 3:
            break;

            case 4:
            break;


            default:
            cout<<"Numero invalido"<<endl<<endl;

        }

    }while(n!=0);




    return 0;
}

void Generar_disparos_ofensivos(){
    cout<<"1 Generar disparos"<<endl;
}
