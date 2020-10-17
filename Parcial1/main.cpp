#include <iostream>
using namespace std;
#include<math.h>
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


************************************
************************************
Al estar en la ofensiva, se exactamente la posicion en x y h a la cual esta el cañon ofensivo


*/
void Generar_disparos_ofensivos();
void Generar_disparos_defensivos();


//variables globales
int disparos_ofensivos[3]={0};
int disparos_defensivos[3]={0};

float g=9.81;
float pi=3.141592;

float x_0=0;
float y_0=0;
float vx0=0;
float vy0=0;
float t0=2.5;

float x0_0=0;
float v0_0=0;
float H0=1;
float grados0=0;
float rad0=0;
//***************************

float x_D=0;
float y_D=0;
float vxD=0;
float vyD=0;
float tD=2.5;

float x0_D=0;
float v0_D=0;
float HD=1;
float gradosD=0;
float radD=0;
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
            Generar_disparos_defensivos();
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

//infiltrado
void Generar_disparos_ofensivos(){

    for(int i=0;i<3;i++){
        cout<<"Ingrese velocidad inicial: ";cin>>v0_0;
        cout<<"Ingrese grados_0: ";cin>>grados0;
        rad0=grados0*(pi/180);
        cout<<"Ingrese ditancia en y: ";cin>>H0;

        vx0=v0_0+cos(rad0);
        vy0=v0_0*sin(rad0)-g*t0;

        x_0=0+vx0*t0;
        y_0=H0+vy0*t0-(g*t0*t0)/2;
    }


}




void Generar_disparos_defensivos(){


}
