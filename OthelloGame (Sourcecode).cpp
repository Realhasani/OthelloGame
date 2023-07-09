#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <ctype.h>
#include <windows.h>
#include <time.h>

using namespace std;

void Display(char[8][8]);
void gotoxy(short x , short y)
{
COORD pos = {x , y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void Display(char Board[8][8])
{
    system("cls");
    
    int i; 
    for(i = 0; i < 8 ; i++)
    {
    cout << "\t   +---+---+---+---+---+---+---+---+\n";
    cout << "\t"<<i+1 <<"  |"<<Board[i][0]<<"  |" <<Board[i][1] <<"  |"<<Board[i][2]<<"  |"<<Board[i][3]<<"  |"<<Board[i][4]<<"  |"<<Board[i][5] <<"  |"<<Board[i][6]<<"  |"<<Board[i][7]<<"  |"<<Board[i][8] <<endl;
    }
        cout << "\t   +---+---+---+---+---+---+---+---+\n";
        cout << "\t     A   B   C   D   E   F   G   H   ";
}
int main()
{
 Intro:
 srand(time(0));
system("cls");
int i , j , w , Done , Melon = 0;
char A , B , pos[2] , X , Y , Board[8][8];
for(i = 0 ; i < 8 ; i++)
{
    for (j = 0 ; j < 8 ; j++)
        Board[i][j] = ' ';
}  
cout << "\t\t\t\t   ####******************************####\t" <<endl;
cout << "\t\t\t\t   ##             OTHELLO GAME         ##" << endl;
cout << "\t\t\t\t   ####******************************####\t" << endl;
cout << "The Rules Are As Usual:\n\n";
cout << "In The End, Player Which Will Have More Tokens Than Its Opponent Winss The Game.\n\n";
cout << " !    @    #    $    $    ^    &    *    (    )    /    -    +    = \n\n";
Sleep(3000);
cout << "Enter Your Token Symbol: ";
cin >> A;
cout << "Enter Opponent's Token Symbol: ";
cin >> B;
if(A == B)
{
    cout << "\n\t\tOhh !!! Both The Tokens Are Same........";
    Sleep(1000);
    goto Intro;
}
char tICK = A;
char Tick = B;
char *Quote [5] = {"AND" , "THE" , "GAME" , "STARTS" , "NOW !!!"};
for ( i = 0 ; i < 5 ; i++)
{
    cout << "\n\n"<<"\t\t\t"<<Quote[i]<<"   ";
    Sleep(500);
} 
    Sleep(1000);
    Board[3][3] = A;  Board[3][4] = B;
    Board[4][3] = B;  Board[4][4] = A;
    start:
    Display(Board);
    A = tICK;
    cout << endl << "Your ("<<A<<") Turn........";
    Sleep(1000);
    cout << "\nEnter Position: (A1 , G6 , C3 , etc.)";
    cin >> pos;
    cout << endl;
    pos[0] = toupper(pos[0]);
        if(pos[0] == 'A')
        X = 0;
        else if(pos[0] == 'B')
        X = 1;
        else if(pos[0] == 'C')
        X = 2;
        else if(pos[0] == 'D')
        X = 3;
        else if(pos[0] == 'E')
        X = 4;
        else if(pos[0] == 'F')
        X = 5;
        else if(pos[0] == 'G')
        X= 6;
        else if(pos[0] == 'H')
        X = 7;
        else 
        {
            cout << "Enter Again...";
            Sleep(500);
            goto start;
        }
        if(pos[1] == '1')
        Y = 0;
        else if(pos[1] == '2')
        Y = 1;
        else if(pos[1] == '3')
        Y = 2;
        else if(pos[1] == '4')
        Y = 3;
        else if(pos[1] == '5')
        Y = 4;
        else if(pos[1] == '6')
        Y = 5;
        else if(pos[1] == '7')
        Y = 6;
        else if(pos[1] == '8')
        Y = 7;
        else 
        {
            cout << "Enter Again...";
            Sleep(500);
            goto start;
        }
        if (Board[Y][X] != ' ')
        {
            cout << "Enter Again...";
            Sleep(500);
            goto start;
        }
        Board[Y][X] = A;
        B = Tick;
        
        for(j = X-1 ; j>=0 ; j--)
        {
            if(Board[Y][j] == B)
                Board[Y][j] = A;
                else 
                break;
        }
        if(Board[Y][j] != A)
        {
            for(j = X-1 ; j>=0 ; j++)
            {
                if(Board[Y][j] == A)
                    Board[Y][j] = B;
                    else
                    break;
            }
        }
        
        for(j = X+1 ; j < 8 ; j++)
        {
             if(Board[Y][j] == B)
                    Board[Y][j] = A;
                    else
                    break;
        }
        if (Board[Y][j] != A)
        {
            for(j = X+1; j<8 ; j++)
            {
                if(Board[Y][j] == A)
                    Board[Y][j] = B;
                    else
                    break;
            }
        }
        
        for( i = Y-1 ; i >= 0 ; i--)
        {
            if(Board[i][X] == B)
                    Board[i][X] = A;
                    else
                    break;
        }
        if(Board[i][X] != A)
        {
            for( i = Y-1 ; i >= 0 ; i--)
            {
                if(Board[i][X] == A)
                    Board[i][X] = B;
                    else
                    break;
            }
        }
        
        for(i = Y+1 ; i < 8 ; i++)
        {
            if(Board[i][X] == B)
                    Board[i][X] = A;
                    else
                    break;
        }
        if(Board[i][X] != A)
        {
            for(i = Y+1 ; i < 8 ; i++)
            {
                 if(Board[i][X] == A)
                    Board[i][X] = B;
                    else
                    break;
            }
        }
        
        i = Y - 1;   j= X - 1;
        while (i>=0 && j>= 0 )
        {
            if(Board[i][j] == B)
            Board[i][j]  = A;
            else
            break;
            i--;  j--;
        }
        if(Board[i][j] != A)
        {
            i = Y - 1;   j= X - 1;
             while (i>=0 && j>= 0 )
        {
            if(Board[i][j] == A)
            Board[i][j]  = B;
            else
            break;
            i--;  j--;
        }
    }
    
    i = Y - 1;   j= X + 1;
        while (i>=0 && j< 8 )
        {
            if(Board[i][j] == B)
            Board[i][j]  = A;
            else
            break;
            i--;  j++;
        }
        if(Board[i][j] != A)
        {
            i = Y - 1;   j= X + 1;
             while (i>=0 && j< 8 )
        {
            if(Board[i][j] == A)
            Board[i][j]  = B;
            else
            break;
            i--;  j++;
        }
    }
    
    i = Y + 1;   j= X - 1;
             while (i<8 && j>= 0 )
        {
            if(Board[i][j] == B)
            Board[i][j] = A;
            else
            break;
            i++;  j--;
        }
  if(Board[i][j] != A)
        {
            i = Y + 1;   j= X - 1;
             while (i<8 && j>=0 )
        {
            if(Board[i][j] == A)
            Board[i][j]  = B;
            else
            break;
            i++;  j--;
        }
    }  
    
     i = Y + 1;   j= X + 1;
             while (i<8 && j< 8 )
        {
            if(Board[i][j] == B)
            Board[i][j]  = A;
            else
            break;
            i++;  j++;
        }
        if(Board[i][j] != A)
        {
            i = Y + 1;   j= X + 1;
             while (i<8 && j< 0 )
        {
            if(Board[i][j] == A)
            Board[i][j]  = B;
            else
            break;
            i++;  j++;
        }
    }  
    Display(Board);
    Sleep(500);
    Done = 1;
    for( i = 0 ; i < 8 ; i++)
    {
        for(j = 0 ; j < 8 ; j++)
        {
            if( Board [i][j] == ' ')
                Done = 0;
        }
    }
    if (Done == 1)
        goto end;
        
        cout << endl<<"Opponent's ("<<B<<") Turn.........";
        Sleep(1000);
        again:
        X = rand()%8;
        Y = rand()%8;
        w = 0;
        if(Board[Y][X] != ' ')
            goto again;
        if(Board[Y+1][X] == A)
            w++;
            if(Board[Y][X+1] == A)
            w++;
            if(Board[Y+1][X+1] == A)
            w++;
            if(Board[Y-1][X] == A)
            w++;
            if(Board[Y][X-1] == A)
            w++;
            if(Board[Y-1][X-1] == A)
            w++;
            if(Board[Y+1][X-1] == A)
            w++;
            if(Board[Y-1][X+1] == A)
            w++;
            if(w==0 && Melon < 15)
                goto again;
                Board[Y][X] = B;
                Melon++;
                
                for(j = X - 1 ; j >= 0 ; j--)
                {
                    if(Board [Y][j] == A)
                        Board [Y][j] = B;
                        else
                        break;
                }
                if(Board[Y][j] != B)
                {
                    for(j = X -1 ; j >= 0 ; j--)
                    {
                        if(Board[Y][j] == B)
                            Board [Y][j] = A;
                            else
                            break;
                    }
                }
                
                for( j = X + 1 ; j<8 ; j++)
                {
                    if(Board[Y][j] == A)
                        Board[Y][j] = B;
                        else
                        break;
                }
              if(Board[Y][j] != B)
                {
                    for(j = X + 1 ; j < 8 ; j++)
                    {
                        if(Board[Y][j] == B)
                            Board [Y][j] = A;
                            else
                            break;
                    }
                }  
                
                for(i = Y - 1 ; j >= 0 ; i--)
                    {
                        if(Board[i][X] == A)
                            Board [i][X] = B;
                            else
                            break;
                    }
                    if(Board[i][X] != B)
                {
                    for(i = Y - 1 ; i >= 8 ; i--)
                    {
                        if(Board[i][X] == B)
                            Board [i][X] = A;
                            else
                            break;
                    }
                } 

                    for(i = Y + 1 ; i < 8 ; i++)
                    {
                        if(Board[i][X] == A)
                            Board [i][X] = B;
                            else
                            break;
                    }
                  if(Board[i][X] != B)
                {
                    for(i = Y + 1 ; i < 8 ; i++)
                    {
                        if(Board[i][X] == B)
                            Board [i][X] = A;
                            else
                            break;
                    }
                } 
                
              i = Y - 1;   j= X - 1;
             while (i >= 0 && j >= 0 )
        {
            if(Board[i][j] == A)
            Board[i][j]  = B;
            else
            break;
            i--;  j--;
        }
        if(Board[i][j] != B)
        {
            i = Y - 1;   j= X - 1;
             while (i>=0 && j>= 0 )
        {
            if(Board[i][j] == B)
            Board[i][j]  = A;
            else
            break;
            i--;  j--;
        }
    }  
    
            i = Y - 1;   j= X + 1;
             while (i>=0 && j< 8)
        {
            if(Board[i][j] == A)
            Board[i][j]  = B;
            else
            break;
            i--;  j++;
        }
        if(Board[i][j] != B)
        {
            i = Y - 1;   j= X + 1;
             while (i>=0 && j< 8 )
        {
            if(Board[i][j] == B)
            Board[i][j]  = A;
            else
            break;
            i--;  j++;
        }
    }  
    
             i = Y + 1;   j= X - 1;
             while (i<8 && j>= 0 )
        {
            if(Board[i][j] == A)
            Board[i][j]  = B;
            else
            break;
            i++ ;  j--;
        }
        if(Board[i][j] != B)
        {
            i = Y + 1;   j= X - 1;
             while (i < 8 && j >= 0 )
        {
            if(Board[i][j] == B)
            Board[i][j]  = A;
            else
            break;
            i++;  j--;
        }
    }  
    
    i = Y;   j= X;
             while (i < 8 && j < 8 )
        {
            if(Board[i][j] == A)
            Board[i][j]  = B;
            else
            break;
            i++;  j++;
        }
        if(Board[i][j] != B)
        {
            i = Y;   j= X;
             while (i < 8 && j < 8 )
        {
            if(Board[i][j] == B)
            Board[i][j]  = A;
            else
            break;
            i++;  j++;
        }
    }  
    Display(Board);
    Sleep(500);
    Done = 1 ; 
    for(i = 0 ; i < 8 ; i++)
    {
        for (j = 0 ; j < 8 ; j++)
        {
            if(Board[i][j] == ' ')
                Done = 0;
        }
    }
    if(Done == 1) 
        goto end;
        goto start;
        end:
        cout << endl;
        Sleep(1000);
        int Pla = 0 , Opp = 0;
        for(i = 0 ; i < 8 ; i++)
        {
            for ( j = 0 ; j < 8 ; j++)
            {
                if( Board[i][j] == A)
                    Pla++;
                    if( Board[i][j] == B)
                    Opp++;
            }
        }
        system("cls");
        if (Pla > Opp)
        {
            gotoxy(30 , 10);
            cout << "You Won The Game!!!!!!";
            cout << endl;
            cout << "You :" << Pla <<"\t"<<"Opponent :" << Opp << endl;
        }
        if (Pla < Opp)
        {
            gotoxy(30 , 10);
            cout << "Opponent Won The Game!!!!!!";
            cout << endl;
            cout << "You :" << Pla <<"\t"<<"Opponent :" << Opp << endl;
        }
        if (Pla > Opp)
        {
            gotoxy(30 , 10);
            cout << "It Is Draw!!!!!!";
            cout << endl;
            cout << "You :" << Pla <<"\t"<<"Opponent :" << Opp << endl;
        }
        getch();
  return 0;
}	
					


