#include<stdio.h>
#include<time.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>
#include<stdio.h>

#define M 40
#define N 20

int i,j,field[N][M],x,y,gy,head,tail,game,frogs,a,b,var,dir;
void snakeinitialization(){
    for(i=0;i<N;i++)
     {
         for(j=0;j<M;j++)
        {
            field[i][j]=0;
        }

     }
    x=N/2;y=M/2;gy=y;head=5;tail=1;game=0,frogs=0;
        for(i=0;i<head;i++)
        {
            gy++;
            field[x][gy-head]=i+1;
        }

}

void print()
{
    for(i=0;i<=M+1;i++){
        if(i==0){
            printf("%c",201);
        }else if(i==M+1){
            printf("%c",187);
        }
        else{
            printf("%c",205);
        }
     }

    printf("\n");
    for(i=0;i<N;i++){
        printf("%c",186);
        for(j=0;j<M;j++){
            if(field[i][j]==0)
                printf(" ");

            if(field[i][j]> 0&& field[i][j]!=head)
               printf("%c",176);

            if(field[i][j]==head)
               printf("%c",178);
            if(field[i][j]==-1){
               printf("%c",15);
            }
            if(j==M-1)
               printf("%c\n",186);
        }
    }
      for(i=0;i<=M+1;i++)
    {
        if(i==0){
            printf("%c",200);
        }else if(i==M+1){
            printf("%c",188);
        }
        else{
            printf("%c",205);
        }
     }
}
void ResetScreenPosition(){

    HANDLE hOut;
    COORD  Position;
    hOut=GetStdHandle(STD_OUTPUT_HANDLE);
    Position.X=0;
    Position.Y=0;
    SetConsoleCursorPosition(hOut,Position);
}

void Random(){
    srand(time(0));
a=1+rand() % 18;
b=1+rand() % 38;
if(frogs==0 && field[a][b]==0)
    {
    field[a][b]=-1;
    frogs=1;
    }
}
int getch_noblock(){
    if(_kbhit())
    {
        return _getch();
    }
    else
        return -1;
}
void movement()
{
    var = getch_noblock();
    var=tolower(var);
    if(((var=='a')|| (var=='s')|| (var=='d')||(var=='w'))
       &&(abs(dir-var)>5))
    {
        dir=var;
    }
    if(dir=='d')
    {
        y++;
        head++;
        field[x][y]=head;
    }
    if(dir=='a')
    {
        y--;
        head++;
        field[x][y]=head;
    }
    if(dir=='w')
    {
        x--;
        head++;
        field[x][y]=head;
    }
    if(dir=='s')
    {
        x++;
        head++;
        field[x][y]=head;
    }
}
void Tailremove(){
    for(i=0;i<<N;i++){
        for(j=0;j<M;j++){
            if(field[i][j]==tail){
                field[i][j]=0;
            }
        }
    }
tail++;
}

int main()
{
    snakeinitialization();
while(game==0){

    print();
    ResetScreenPosition();
    Random();
    movement();
    Tailremove();
    Sleep(99);
}
    return 0;
}
