///AUTOR: CLEVER RONALD LAURA AYAMAMANI

#include <conio.h>
#include <iostream>
#include <winbgim.h>
#include <math.h>
#include <time.h>

using namespace std;
int ancho=50;
#define color_muro 14
#define color_persona 3
#define color_meta 12
#define color_ganar 13
#define color_caja 6

void dib_muro(int x,int y,int color){
    setfillstyle(1,color);
    bar(x+1,y+1,x+ancho-1,y+ancho-1);
}
void dib_caja(int x,int y,int color){

    setfillstyle(1,color);
    bar(x+1,y+1,x+ancho-1,y+ancho-1);

    setcolor(2);

    rectangle(x+1,y+1,x+ancho-1,y+ancho-1);
    line(x+1,y+1,x+ancho-1,y+ancho-1);
    line(x+ancho-1,y+1,x+1,y+ancho-1);
}
void dib_personita(int x,int y,int color){
    //setcolor(color);
    setfillstyle(1,color);
    fillellipse(x+ancho/2,y+ancho/2,ancho/2-1,ancho/2-1);

    //circle(x+ancho/2,y+ancho/2,ancho/2-1);
}
void borrar(int x,int y){
    setfillstyle(1,0);
    bar(x+1,y+1,x+ancho-1,y+ancho-1);

    setcolor(0);

    rectangle(x+1,y+1,x+ancho-1,y+ancho-1);
    line(x+1,y+1,x+ancho-1,y+ancho-1);
    line(x+ancho-1,y+1,x+1,y+ancho-1);

    setcolor(0);
    //rectangle(x,y,x+ancho,y+ancho);
    setfillstyle(1,0);
    fillellipse(x+ancho/2,y+ancho/2,ancho/2-1,ancho/2-1);


}
void dib_matriz(int x,int y,int mat[8][8]){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
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
                dib_caja(x+ancho*j,y+ancho*i,color_caja);
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
    fillellipse(700,160,ancho/2-1,ancho/2-1);
    settextstyle( DEFAULT_FONT, 0, 3 );
    setcolor (color_meta);
    outtextxy(730,145,"META");

    setfillstyle(1,color_caja);
    fillellipse(700,220,ancho/2-1,ancho/2-1);
    settextstyle( DEFAULT_FONT, 0, 3 );
    setcolor (color_caja);
    outtextxy(730,205,"CAJAS");
}
void ganar ()
{
    settextstyle( DEFAULT_FONT, 0, 3 );
    setcolor (13);
    outtextxy(560,300,"Colocó todas las");
    outtextxy(560,340,"cajas en su lugar,");
    outtextxy(560,380," Presione ENTER");
    outtextxy(560,420,"   para salir");

}
int main(){
    int iPer=4; //1
    int jPer=4;//2
    int metai_1=1;
    int metaj_1=3;
    int metai_2=4;
    int metaj_2=1;
    int metai_3=3;
    int metaj_3=6;
    int metai_4=6;
    int metaj_4=4;
    int iMur=0;
    int jMur=0;

    int salir=false;
    int tecla;
    int cont=0;
    char cadena[100];
    int b=0;
    int mat[8][8]={  ///EMPUJA CAJAS
        {0,0,1,1,1,0,0,0},
        {0,0,1,0,1,0,0,0},
        {0,0,1,0,1,1,1,1},
        {1,1,1,4,0,4,0,1},
        {1,0,0,4,0,1,1,1},
        {1,1,1,1,4,1,0,0},
        {0,0,0,1,0,1,0,0},
        {0,0,0,1,1,1,0,0},
    };
    initwindow(1070,700);
    informacion();

    mat[iPer][jPer]=2;
    mat[metai_1][metaj_1]=3;
    mat[metai_2][metaj_2]=3;
    mat[metai_3][metaj_3]=3;
    mat[metai_4][metaj_4]=3;


    dib_matriz(100,100,mat);
    srand(time(NULL));//time.h
    tecla=0;
    tecla=getch();
    while(tecla!=13){ //salir==false
        tecla=getch();
        if(tecla==72){//arriba
            if((mat[iPer-1][jPer]==4)&&(mat[iPer-2][jPer]!=1) ){
                mat[iPer][jPer]=0;
                mat[iPer-1][jPer]=0;
                iPer--;
                mat[iPer-1][jPer]=4;
                dib_matriz(100,100,mat);
                mat[iPer][jPer]=2;
            }
            if(mat[iPer-1][jPer]==0){
                mat[iPer][jPer]=0;
                iPer--;
                mat[iPer][jPer]=2;
                cont++;
            }
        }
        if(tecla==80){//abajo
            if((mat[iPer+1][jPer]==4)&&(mat[iPer+2][jPer]!=1) ){
                mat[iPer][jPer]=0;
                mat[iPer+1][jPer]=0;
                iPer++;
                mat[iPer+1][jPer]=4;
                dib_matriz(100,100,mat);
                mat[iPer][jPer]=2;
            }
            if(mat[iPer+1][jPer]==0){
                mat[iPer][jPer]=0;
                iPer++;
                mat[iPer][jPer]=2;
                 cont++;

            }
        }
        if(tecla==75){//izquierda
            if((mat[iPer][jPer-1]==4)&&(mat[iPer][jPer-2]!=1) ){
                mat[iPer][jPer]=0;
                mat[iPer][jPer-1]=0;
                jPer--;
                mat[iPer][jPer-1]=4;
                dib_matriz(100,100,mat);
                mat[iPer][jPer]=2;
            }
            if(mat[iPer][jPer-1]==0){
                mat[iPer][jPer]=0;
                jPer--;
                mat[iPer][jPer]=2;

            }
        }
        if(tecla==77){//derecha
            if((mat[iPer][jPer+1]==4)&&(mat[iPer][jPer+2]!=1) ){
                mat[iPer][jPer]=0;
                mat[iPer][jPer+1]=0;
                jPer++;
                mat[iPer][jPer+1]=4;
                dib_matriz(100,100,mat);
                mat[iPer][jPer]=2;
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

        dib_matriz(100,100,mat);
        if(mat[metai_1][metaj_1]==4 && mat[metai_2][metaj_2]==4 && mat[metai_3][metaj_3]==4 && mat[metai_4][metaj_4]==4)
        {
            ganar();

        }
    }
 }
