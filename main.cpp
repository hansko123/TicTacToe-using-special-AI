#include <iostream>             // Header Files
#include  <conio.h>
#include   <cstdlib>
#include   <windows.h>
#include  <time.h>


using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
void gotoxy (int x, int y)
    {
         COORD coordinates;     // coordinates is declared as COORD
         coordinates.X = x;     // defining x-axis
         coordinates.Y = y;     //defining  y-axis
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordinates);
    }


void hinteasy(  int layar[3][3], int &kursorx, int &kursory)
{
    do{
    kursorx=rand()%3;
    kursory=rand()%3;
    }while(layar[kursorx][kursory]);
    if(layar[1][1]==0)
        {
            kursorx=1;  kursory=1;
        }
}


 int hintmedium(int layar[3][3],int  look,int &kursorx, int  &kursory)
{
   int i;
    int result=0;
        for(i=0;i<=2;i++)
            if (layar[i][0]+layar[i][1]+layar[i][2] == look )
            {
                kursorx=i;
                if(layar[i][0]==0) kursory=0;
                else
                if(layar[i][1]==0) kursory=1;
                else
                if(layar[i][2]==0) kursory=2;
                result++;
            }

        for(i=0;i<=2;i++)
           if( layar[0][i]+layar[1][i]+layar[2][i]==look)
           {
                kursory=i;
                if(layar[0][i]==0) kursorx=0;
                else
                if(layar[1][i]==0) kursorx=1;
                else
                if(layar[2][i]==0) kursorx=2;
                result++;
           }
         if (layar[0][0]+layar[1][1]+layar[2][2]==look)
         {
            if (layar[0][0]==0)
            {
                kursorx=0;
                kursory=0;
            }else
             if (layar[1][1]==0)
            {
                kursorx=1;
                kursory=1;
            }else
            if (layar[2][2]==0)
            {
                kursorx=2;
                kursory=2;
            }
            result++;
         }
          if (layar[0][2]+layar[1][1]+layar[2][0]==look )
          {
              if (layar[0][2]==0)
            {
                kursorx=0;
                kursory=2;
            }else
             if (layar[1][1]==0)
            {
                kursorx=1;
                kursory=1;
            }else
            if (layar[2][0]==0)
            {
                kursorx=2;
                kursory=0;
            }
            result++;
          }
  return result;
}


bool hinthard(int layar[3][3],int  look,int &kursorx, int  &kursory)
{
    int i,j;

    for(i=0;i<=2;i++)
        for(j=0;j<=2;j++)
          if(layar[i][j]==0)
            {
                layar[i][j]=look/2;
                if(hintmedium(layar, look,kursorx,kursory)>1)
                {
                    kursorx=i;
                    kursory=j;
                    layar[i][j]=0;
                    return true;
                }
                layar[i][j]=0;
            }
   return false;
}

int main()
{

    int i,result,winner=0,langkah=0;
    int kursorx=1,kursory=1;
    char ch;

    int layar[3][3]={0,0,0,  0,0,0 , 0,0,0};

    int giliran=1;

     srand(time(NULL));

    for (i=0;i<=39;i++)
    {   gotoxy(i,0);      cout<<"#";
        gotoxy(i,8);      cout<<"#";
        gotoxy(i,16);      cout<<"#";
        gotoxy(i,24);      cout<<"#";

         if(i<24)
            {gotoxy(0,i);      cout<<"#";
             gotoxy(13,i);      cout<<"#";
             gotoxy(26,i);      cout<<"#";
             gotoxy(39,i);      cout<<"#";
         }
     }


     while(true)
     {
         if(kbhit())
         {
             ch=getch();

             if(ch=='h'||ch=='H')
             {

                        if(giliran==1) //player 1 turn
                        {
                           if (!hintmedium(layar, 40,kursorx,kursory))
                               if(!hintmedium(layar, -4,kursorx,kursory))
                                  if(!hinthard(layar, 40,kursorx,kursory))
                                    if(!hinthard(layar, -4,kursorx,kursory))
                                 hinteasy(layar,kursorx,kursory);
                        }
                        else
                        {   //player 2
                            if ( !hintmedium(layar, -4,kursorx,kursory))
                               if(!hintmedium(layar, 40,kursorx,kursory))
                                if(!hinthard(layar, -4,kursorx,kursory))
                                    if(!hinthard(layar, 40,kursorx,kursory))
                                 hinteasy(layar,kursorx,kursory);
                        }

                        switch(langkah)
                        {
                        case 0:
                               do{
                                kursorx=rand()%2;
                                kursory=rand()%2;
                                }while(kursorx!=kursory);
                            break;
                        case 1:
                            if(layar[1][1]==0)
                           {
                               kursorx=1;
                               kursory=1;
                           }else
                           {
                               kursorx=0;kursory=0;
                           }

                            break;
                            case 2:


                               if(layar[1][1]==20)
                               {
                                   if(layar[0][1]==-2||layar[1][0]==-2||layar[2][1]==-2||layar[1][2]==-2) {kursorx=0;kursory=0;}

                               }
                               else
                               {

                                     if(layar[0][1]==20||layar[1][0]==20||layar[2][1]==20||layar[1][2]==20) {kursorx=0;kursory=0; }

                               }



                               if(layar[1][1])
                               {
                                   if (layar[0][0]) {kursorx=2;kursory=2;}
                                   if (layar[2][2]) {kursorx=0;kursory=0;}
                                   if (layar[0][2]) {kursorx=2;kursory=0;}
                                   if (layar[2][0]) {kursorx=0;kursory=2;}

                               }



                               if(layar[1][1]==0)
                               {
                                   if(layar[2][0]&&layar[0][2])
                                   {
                                       kursorx=2;kursory=2;
                                   }
                                   if(layar[0][0]&&layar[2][2])
                                   {
                                       kursorx=2;kursory=0;
                                   }
                               }


                            break;
                            case 3:

                            if(layar[0][0]&&layar[1][1]&&layar[2][2])
                            {
                              if(layar[1][1]==-2){kursorx=0;kursory=1;}
                                else
                                {
                                    kursorx=0;kursory=2;
                                }

                            }
                            if(layar[2][0]&&layar[1][1]&&layar[0][2])
                            {
                                //cout<< "aaaaaa";
                                if(layar[1][1]==-2){kursorx=0;kursory=1;}
                                else
                                {
                                    kursorx=0;kursory=0;
                                }
                            }



                            break;
                        }







                gotoxy(kursorx*13+6,kursory*8+5);
                ch=32;
             }

             if(ch==32) //space, player move
             {
                if(giliran==1)
                {
                    if(layar[kursorx][kursory]==0)
                    {
                        SetConsoleTextAttribute(hConsole, 9);cout<<"\2";
                        giliran=2;
                        layar[kursorx][kursory]=20;
                        langkah++;
                    }

                }else
                {
                    if(layar[kursorx][kursory]==0)
                    {
                      SetConsoleTextAttribute(hConsole, 12);cout<<"\1";
                      giliran=1;
                        layar[kursorx][kursory]=-2;
                        langkah++;
                    }
                }

             }


             if(ch<0)
             {
                 ch=getch();
                 switch(ch)
                 {
                     case 72: if(kursory) kursory--;break;
                     case 75: if(kursorx) kursorx--;break;
                     case 80: if(kursory<2) kursory++; break;
                     case 77: if(kursorx<2) kursorx++;break;
                 }
             }
         }//kbhit

        gotoxy(kursorx*13+6,kursory*8+5);


        //cek for win
        for(i=0;i<=2;i++)
        {
           result = layar[i][0]+layar[i][1]+layar[i][2];
           if(result==60) winner=1;
           if(result==-6) winner=2;
        }
        for(i=0;i<=2;i++)
        {
           result = layar[0][i]+layar[1][i]+layar[2][i];
           if(result==60) winner=1;
           if(result==-6) winner=2;
        }
        result = layar[0][0]+layar[1][1]+layar[2][2];
           if(result==60) winner=1;
           if(result==-6) winner=2;

        result = layar[0][2]+layar[1][1]+layar[2][0];
           if(result==60) winner=1;
           if(result==-6) winner=2;



          if(winner)
          {
              gotoxy(0,0); cout << "The winner is ";
              if(winner==1)
                  cout << "player 1  ";
              else
                  cout << "player 2  ";
              break;
          }

          if(langkah==9)
          {
              gotoxy(0,0); cout << "The Game is Draw  ";
              break;
          }


     }//While true


 getch();
}
