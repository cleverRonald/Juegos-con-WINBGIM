///AUTOR: CLEVER RONALD LAURA AYAMAMANI

#include <conio.h>
#include <iostream>
#include <winbgim.h>
#include <math.h>
#include <time.h>

using namespace std;
int ancho=25;
#define color_muro 14
#define color_persona 3
#define color_meta 12
#define color_ganar 13
void dib_muro(int x,int y,int color){
    //setcolor(color);
    setfillstyle(1,color);
    bar(x+1,y+1,x+ancho-1,y+ancho-1);
    //rectangle(x+1,y+1,x+ancho-1,y+ancho-1);
    //line(x+1,y+1,x+ancho-1,y+ancho-1);
    //line(x+ancho-1,y+1,x+1,y+ancho-1);
}
void dib_personita(int x,int y,int color){
    //setcolor(color);
    setfillstyle(1,color);
    fillellipse(x+ancho/2,y+ancho/2,ancho/2-1,ancho/2-1);

    //circle(x+ancho/2,y+ancho/2,ancho/2-1);
}
void borrar(int x,int y){
    setcolor(0);
    //rectangle(x,y,x+ancho,y+ancho);
    setfillstyle(1,0);
    fillellipse(x+ancho/2,y+ancho/2,ancho/2-1,ancho/2-1);
}
void dib_matriz(int x,int y,int mat[21][21]){
    for(int i=0;i<21;i++){
        for(int j=0;j<21;j++){
            if(mat[i][j]==0){
                borrar(x+ancho*j,y+ancho*i);
            }
            if(mat[i][j]==1){
                dib_muro(x+ancho*j,y+ancho*i,color_muro);
            }
            if(mat[i][j]==2){
                dib_personita(x+ancho*j,y+ancho*i,color_persona);
            }
            if(mat[i][j]==3){
                dib_personita(x+ancho*j,y+ancho*i,color_meta);
            }
            if(mat[i][j]==4){
                dib_personita(x+ancho*j,y+ancho*i,color_ganar);
            }
        }
    }
}
void informacion ()
{
    settextstyle( DEFAULT_FONT, 0, 3 );
    setcolor (10);
    outtextxy(40,10,"Autor: CLEVER RONALD LAURA AYAMAMANI");

    setfillstyle(1,color_persona);
    fillellipse(700,100,ancho/2-1,ancho/2-1);
    settextstyle( DEFAULT_FONT, 0, 3 );
    setcolor (color_persona);
    outtextxy(730,85,"PERSONA");

    setfillstyle(1,color_meta);
    fillellipse(700,140,ancho/2-1,ancho/2-1);
    settextstyle( DEFAULT_FONT, 0, 3 );
    setcolor (color_meta);
    outtextxy(730,125,"META");

    setfillstyle(1,color_ganar);
    fillellipse(700,180,ancho/2-1,ancho/2-1);
    settextstyle( DEFAULT_FONT, 0, 3 );
    setcolor (color_ganar);
    outtextxy(730,165,"GANÓ");
}
void ganar ()
{
    settextstyle( DEFAULT_FONT, 0, 3 );
    setcolor (13);
    outtextxy(600,300,"Llegó a la meta,");
    outtextxy(600,340," Presione ENTER");
    outtextxy(600,380,"   para salir");

}
int main(){
    int iPer=1; //1
    int jPer=2;//2

    int iMur=0;
    int jMur=0;

    int salir=false;
    int tecla;
    int cont=0;
    char cadena[100];
    int b=0;
    int mat[21][21]={  ///LABERINTO
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,0,1,0,1,1,1,0,1,0,1,0,1,1,1},
        {1,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,1},
        {1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1},
        {1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,0,1},
        {1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,1},
        {1,0,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1},
        {1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
        {1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,1},
        {1,0,1,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,1},
        {1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1},
        {1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,1,0,0,0,1},
        {1,1,1,1,1,0,1,1,1,0,1,0,1,1,1,0,1,1,1,0,1},
        {1,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,1},
        {1,0,1,0,1,1,1,0,1,1,1,1,1,0,1,0,1,0,1,1,1},
        {1,0,0,0,1,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1},
        {1,0,1,1,1,0,1,1,1,1,1,0,1,0,1,0,1,1,1,1,1},
        {1,0,3,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    };
    initwindow(1000,700);
    informacion();
    mat[iPer][jPer]=2;
    dib_matriz(50,70,mat);
    srand(time(NULL));//time.h
    tecla=0;
    tecla=getch();
    while(tecla!=13){ //salir==false
        tecla=getch();
        //cout <<tecla<< endl;

        if(b==0){

        if(tecla==72){//arriba
            if (mat[iPer-1][jPer]==3)
            {
                mat[iPer][jPer]=0;
                iPer--;
                mat[iPer][jPer]=4;
                cont++;
                b=1;
                ganar();
            }
            if(mat[iPer-1][jPer]==0){
                mat[iPer][jPer]=0;
                iPer--;
                mat[iPer][jPer]=2;
                cont++;
            }
        }
        if(tecla==80){//abajo
            if(mat[iPer+1][jPer]==3){
                mat[iPer][jPer]=0;
                iPer++;
                mat[iPer][jPer]=4;
                 cont++;
                 b=1;
                 ganar();
            }
            if(mat[iPer+1][jPer]==0){
                mat[iPer][jPer]=0;
                iPer++;
                mat[iPer][jPer]=2;
                 cont++;

            }
        }
        if(tecla==75){//izquierda
            if(mat[iPer][jPer-1]==3){
                mat[iPer][jPer]=0;
                jPer--;
                mat[iPer][jPer]=4;
                 cont++;
                 b=1;
                 ganar();
            }
            if(mat[iPer][jPer-1]==0){
                mat[iPer][jPer]=0;
                jPer--;
                mat[iPer][jPer]=2;
                 cont++;
            }
        }
        if(tecla==77){//derecha
            if(mat[iPer][jPer+1]==3){
                mat[iPer][jPer]=0;
                jPer++;
                mat[iPer][jPer]=4;
                 cont++;
                 b=1;
                 ganar();
            }
            if(mat[iPer][jPer+1]==0){
                mat[iPer][jPer]=0;
                jPer++;
                mat[iPer][jPer]=2;
                 cont++;
            }
        }
        if(iPer==iMur && jPer==jMur){
            sprintf(cadena,"PERDISTE: %d");
        }
        }
        dib_matriz(50,70,mat);
    }
 }
