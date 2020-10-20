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


//prototipo de funciones
void Generar_disparos_ofensivos();
void Generar_disparos_defensivos();
void disparos_defensivos3();
//void disparos_defensivos4();
//**************************************
//**************************************

//variables globales
float disparos_ofensivosx_0[3]={0};
float disparos_ofensivosy_0[3]={0};
float velocidadi_ofensivos_0[3]={0};
float angulo_ofensivo[3]={0};
float tiempo_ofensivo[3]={0};

float disparos_defensivosx_D[3]={0};
float disparos_defensivosy_D[3]={0};

float g=9.81;
float pi=3.141592;
//***************************

float d=100;//100 metros
float d_0=0.05*d; //radio del circulo de destruccion de 0
float d_D=0.025*d; //radio del circulo de destruccion de D

float h0=100; //metros
float hD=200; //metros
//*************************************************************
//enemigo
float t0=0;
float rad0=0;
float grados0=0;
float vi0=0;
float vx0=0;
float vy0=0;
//posicion en x y y del cañon 0
float x_0=0; //sistema de referencia en (0.0)
float y_0=h0;

//float xi_0=0;
//float yi_0=0;

//posiciones de las balas  0
float x_0genera=0;
float y_0genera=0;
//*************************************************************
//base donde estoy
float tD=0;
float radD=0;
float gradosD=0;
float viD=0;
float vxD=0;
float vyD=0;
//posicion en x y y del cañon D
float x_D=d;
float y_D=hD;

//float xi_D=0;
//float yi_D=0;
//posiciones de las balas de D
float x_Dgenera=0;
float y_Dgenera=0;

//***************************
int n=0;
//***************************


int main()
{


    cout<<"Sistema de control de disparo defensivo"<<endl;
    cout<<"1. Generar disparos ofensivos"<<endl;
    cout<<"2. Generar disparos defensivos"<<endl;
    cout<<"3. Dado un disparo ofensivo"<<endl;
    //cout<<"4. Dado un disparo ofensivo"<<endl;
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
            disparos_defensivos3();
            break;

            //case 4:
            //disparos_defensivos4();
            //break;


            default:
            cout<<"Numero invalido"<<endl<<endl;

        }

    }while(n!=0);




    return 0;
}

void disparos_defensivos3(){


    float t=2.5; // 2,5 segundos de retraso
    float raiz;
    float distancia=0;

    //disparo 0 posicion  x y y
    float disparo0x=0;
    float disparo0y=0;
    float velocidadi0=0;
    float angulo0=0;
    float t0=0;

    float Xmax0=0;
    float Ymax0=0;
    float XmaxD=0;
    float YmaxD=0;

    cout<<"\n\n---Disparos de la defensiva---\n\n"<<endl;
    for(int i=0;i<3;i++){

        disparo0x=disparos_ofensivosx_0[i];
        disparo0y=disparos_ofensivosy_0[i];
        velocidadi0=velocidadi_ofensivos_0[i];
        angulo0=angulo_ofensivo[i];
        t0=tiempo_ofensivo[i];

        if(disparo0x>0 && disparo0y>0 && velocidadi0>0){

            //while () {

                Xmax0=(pow(velocidadi0,2)*sin(2*angulo0))/g;
                Ymax0=(velocidadi0*velocidadi0*sin(angulo0)*sin(angulo0))/(2*g);

                //Generar disparos
                //**************************************************
                viD=2*velocidadi0*(-1);
                tD=t+t0;
                radD=angulo0*(pi/180);

                vxD=viD+cos(radD);
                vyD=viD*sin(radD)-g*tD;

                x_Dgenera=x_D+vxD*tD;
                y_Dgenera=y_D+vyD*tD-(g*tD*tD)/2;
                //**************************************************


                XmaxD=(pow(viD,2)*sin(2*radD))/g;
                YmaxD=(viD*viD*sin(radD)*sin(radD))/(2*g);



                raiz=pow((Xmax0-XmaxD),2)+pow((Ymax0-YmaxD),2);
                distancia=sqrt(raiz);


                if(distancia<=d_D && distancia<=d_0){
                    cout<<"\n!!Disparo de D cancelado!!\n"<<endl;
                    break;
                }

                /*
                else{
                    cout<<"\nDisparo de D fuera del rango\n"<<endl;
                }*/


            //}

        }
    }
    cout<<"\n\n-------------------------\n\n"<<endl;
}







//base 0, el infiltrado nos da todo los datos
void Generar_disparos_ofensivos(){

    float raiz;
    float distancia=0;
    cout<<"\n\n---Disparos de la ofensiva---\n\n"<<endl;
    for(int i=0;i<3;i++){
        cout<<"Ingrese velocidad inicial: ";cin>>vi0;
        cout<<"Ingrese grados_D: ";cin>>grados0;
        cout<<"Ingrese tiempo_0: ";cin>>t0;
        rad0=grados0*(pi/180);

        vx0=vi0+cos(rad0);
        vy0=vi0*sin(rad0)-g*t0;

        x_0genera=x_0+vx0*t0;
        y_0genera=y_0+vy0*t0-(g*t0*t0)/2;


        //Rango de destruccion
        //distancia entre el origen de la bala y cañon D
        raiz=pow((x_0genera-x_D),2)+pow((y_0genera-y_D),2);
        distancia=sqrt(raiz);

        //Ver si el rango de destruccion de la bala del cañon de 0 compromete el cañon D
        if(distancia<=d_0){
            cout<<"\n!!Disparo de 0 efectivo!!\n"<<endl;
            disparos_ofensivosx_0[i]=x_0genera;
            disparos_ofensivosy_0[i]=y_0genera;
            velocidadi_ofensivos_0[i]=vi0;
            angulo_ofensivo[i]=rad0;
            angulo_ofensivo[i]=t0;
        }
        else{
            cout<<"\nDisparo de 0 fuera del rango\n"<<endl;
        }
    }
    cout<<"\n\n-------------------------\n\n"<<endl;
}




//base D, donde estoy, velocidad negativa
void Generar_disparos_defensivos(){

    int raiz;
    int distancia=0;
    cout<<"\n\n---Disparos de la defensiva---\n\n"<<endl;
    for(int i=0;i<3;i++){
        cout<<"Ingrese velocidad inicial: ";cin>>viD;
        cout<<"Ingrese grados_D: ";cin>>gradosD;
        cout<<"Ingrese tiempo_0: ";cin>>tD;
        radD=gradosD*(pi/180);

        vxD=viD+cos(radD);
        vyD=viD*sin(radD)-g*tD;

        x_Dgenera=x_D+vxD*tD;
        y_Dgenera=y_D+vyD*tD-(g*tD*tD)/2;


        //Rango de destruccion
        //distancia entre el origen de la bala y cañon 0
        raiz=pow((x_Dgenera-x_0),2)+pow((y_Dgenera-y_0),2);
        distancia=sqrt(raiz);

        //Ver si el rango de destruccion de la bala del cañon de D compromete el cañon 0
        if(distancia<=d_D){
            cout<<"\n!!Disparo de D efectivo!!\n"<<endl;
            disparos_defensivosx_D[i]=x_Dgenera;
            disparos_defensivosy_D[i]=y_Dgenera;
        }
        else{
            cout<<"\nDisparo de D fuera del rango\n"<<endl;
        }
    }
    cout<<"\n\n-------------------------\n\n"<<endl;
}
