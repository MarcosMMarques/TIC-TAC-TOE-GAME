#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void board_drawing(int players, int s[]){
  int i=0,j=0,x=0,board2[3][3],rounds=1,line,column,winx=0,wino=0,winner=0,start=1;
  if(start){
  printf("\n\n---------------------------\n");
  printf("|       GAME STARTED      |\n");
  printf("---------------------------\n\n");
  start=0;
  }
   for(i=0;i<3;i++){
      for(j=0;j<3;j++){
          board2[i][j]=255;
      }
    }
  while(rounds<=10){
    wino=0;
   //Verifying if have a winner in the lines
    for(i=0;i<3;i++){
      for(j=0;j<3;j++){
        if(board2[i][j]==88){
          winx++;
        }else if(board2[i][j]==79){
          wino++;
        }
        if(winx==3){
          winner=88;
        }else if(wino==3){
          winner=79;
        }
      }
      wino=0;
      winx=0;
    }
    //Verifying if have a winner in the column
    for(j=0;j<3;j++){
      for(i=0;i<3;i++){
        if(board2[i][j]==88){
          winx++;
        }else if(board2[i][j]==79){
          wino++;
        }
        if(winx==3){
          winner=88;
        }else if(wino==3){
          winner=79;
        }
      }
      wino=0;
      winx=0;
    }
    //Verifying if have a winner for cross method
    if(board2[1][1]==79){
      if(board2[0][0]==79 && board2[2][2]==79){
        winner=79;
      }else if(board2[0][2]==79 && board2[2][0]==79){
        winner=79;
      }
    }else if(board2[1][1]==88){
      if(board2[0][0]==88 && board2[2][2]==88){
        winner=88;
      }else if(board2[0][2]==88 && board2[2][0]==88){
        winner=88;
      }
    }
    if(players==2 || rounds==1){
    printf("         1   2    3\n\n");
    printf("    1   %c  | %c  | %c\n",(char)board2[0][0],(char)board2[0][1],(char)board2[0][2]);
    printf("        ------------\n");
    printf("    2   %c  | %c  | %c\n",(char)board2[1][0],(char)board2[1][1],(char)board2[1][2]);
    printf("        ------------\n");
    printf("    3   %c  | %c  | %c\n\n\n",(char)board2[2][0],(char)board2[2][1],(char)board2[2][2]);
    }else if(players==1 && rounds%2!=0 || winner!=0 || rounds==10){
      printf("         1   2    3\n\n");
      printf("    1   %c  | %c  | %c\n",(char)board2[0][0],(char)board2[0][1],(char)board2[0][2]);
      printf("        ------------\n");
      printf("    2   %c  | %c  | %c\n",(char)board2[1][0],(char)board2[1][1],(char)board2[1][2]);
      printf("        ------------\n");
      printf("    3   %c  | %c  | %c\n\n\n",(char)board2[2][0],(char)board2[2][1],(char)board2[2][2]);
    }
    //If have a winner, stop the game
    if(winner!=0){
      printf("---------------------\n");
      printf("|       %c Won      |\n",(char)winner);
      printf("---------------------\n\n");
      if(winner==88)
        s[0]++;
      else
        s[1]++;
      printf("       X  |  O\n");
      printf("Score: %d  |  %d\n\n",s[0],s[1]);
      break;
    }else if(winner==0 && rounds==10){
      printf("---------------------\n");
      printf("|       DRAW        |\n");
      printf("---------------------\n\n");
      break;
    }
    //Rounds in the player one is X
    if(rounds%2!=0){
      printf("\n\nWrite the line and column for you want play(You is the X).\n\n");
      scanf("%d%d",&line,&column);
       printf("\n\n");
       //Limiting the line and column for the intervale 1 and 3
      if(line>3 || line<1 || column>3 || column<1){
        printf("This valor for the line or columns is invalid!\n\n");
        continue;
      }
      for(i=0;i<3;i++){
        for(j=0;j<3;j++){
          if(i+1==line && j+1==column && board2[i][j]==255){
            board2[i][j]=88;
          }else if(i+1==line && j+1==column && board2[i][j]==79){
            printf("\n\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
            printf("!This zone already has an O!\n");
            printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n");
            rounds-=1;
          }else if(i+1==line && j+1==column && board2[i][j]==88){
            printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
            printf("!You don't can play in this zone, have a X!\n");
            printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n");
            rounds-=1;
          }
        }
      }
    }else if(rounds%2==0 && players==2){//Rounds in the player two is O
      printf("\n\nWrite the line and column for you want play(You is the O).\n\n");
      scanf("%d%d",&line,&column);
      printf("\n\n");
      //Limiting the line and column for the intervale 1 and 3
      if(line>3 || line<1 || column>3 || column<1){
        printf("This valor for the line or columns is invalid!\n\n");
        continue;
      }
      for(i=0;i<3;i++){
        for(j=0;j<3;j++){
          if(i+1==line && j+1==column && board2[i][j]==255){
            board2[i][j]=79;
          }else if(i+1==line && j+1==column && board2[i][j]==88){
            printf("\n\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
            printf("!This zone already has an X!\n");
            printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n");
            rounds-=1;
          }else if(i+1==line && j+1==column && board2[i][j]==79){
            printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
            printf("!You don't can play in this zone, have a O!\n");
            printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n");
            rounds-=1;
        }
        }
      }
    }else{
      //Rounds for bot
      int nextplay=0;
      wino=0,winx=0;
      //Verifying if the bot have a possibility of won
      if(nextplay==0){
        for(i=0;i<3;i++){
          for(j=0;j<3;j++){
            if(board2[i][j]==79){
              wino++;
            }
            if(wino==2){
              for(x=0;x<3;x++){
                if(board2[i][x]==255){
                  board2[i][x]=79;
                nextplay=1;
                }
              }
            }
          }
          wino=0;
        }
      }
      if(nextplay==0){
        for(j=0;j<3;j++){
          for(i=0;i<3;i++){
            if(board2[i][j]==79){
              wino++;
            }
            if(wino==2){
              for(x=0;x<3;x++){
                if(board2[x][j]==255){
                  board2[x][j]=79;
                  nextplay=1;
                }
              }
            }
          }
        wino=0;
        }
      }
      if(nextplay==0){
        if(board2[0][0]==79 || board2[1][1]==79 || board2[0][2]==79){
          if(board2[0][0]==79 && board2[1][1]==79 || board2[0][0]==79 && board2[2][2]==79){
            if(board2[1][1]==255){
              board2[1][1]=79;
              nextplay=1;
            }else if(board2[2][2]==255){
              board2[2][2]=79;
              nextplay=1;
            }
          }else if(board2[0][2]==79 && board2[1][1]==79 || board2[0][2]==79 && board2[2][0]==79){
            if(board2[1][1]==255){
              board2[1][1]=79;
              nextplay=1;
            }else if(board2[2][0]==255){
              board2[2][0]=79;
              nextplay=1;
            }
          }else if(board2[1][1]==79 && board2[2][0]==79 || board2[1][1]==79 && board2[2][2]==79){
            if(board2[0][2]==255 && board2[1][1]==79 && board2[2][0]==79){
              board2[0][2]=79;
              nextplay=1;
            }else if(board2[0][0]==255 && board2[1][1]==79 && board2[2][2]==79){
              board2[0][0]=79;
              nextplay=1;
            }
          }
        }
      }
      if(nextplay==0){//Verifying if player have chance of the won
        for(i=0;i<3;i++){
          for(j=0;j<3;j++){
            if(board2[i][j]==88){
              winx++;
            }
            if(winx==2){
              for(x=0;x<3;x++){
                if(board2[i][x]==255){
                  board2[i][x]=79;
                nextplay=1;
                }
              }
            }
          }
          winx=0;
        }
      }
      if(nextplay==0){
        for(j=0;j<3;j++){
          for(i=0;i<3;i++){
            if(board2[i][j]==88){
              winx++;
            }
            if(winx==2){
              for(x=0;x<3;x++){
                if(board2[x][j]==255){
                  board2[x][j]=79;
                  nextplay=1;
                }
              }
            }
          }
        winx=0;
        }
      }
      if(nextplay==0){
        if(board2[0][0]==88 || board2[1][1]==88 || board2[0][2]==88){
          if(board2[0][0]==88 && board2[1][1]==88 || board2[0][0]==88 && board2[2][2]==88){
            if(board2[1][1]==255){
              board2[1][1]=79;
              nextplay=1;
            }else if(board2[2][2]==255){
              board2[2][2]=79;
              nextplay=1;
            }
          }else if(board2[0][2]==88 && board2[1][1]==88 || board2[0][2]==88 && board2[2][0]==88){
            if(board2[1][1]==255){
              board2[1][1]=79;
              nextplay=1;
            }else if(board2[2][0]==255){
              board2[2][0]=79;
              nextplay=1;
            }
          }else if(board2[1][1]==88 && board2[2][0]==88 || board2[1][1]==88 && board2[2][2]==88){
            if(board2[0][2]==255 && board2[1][1]==88 && board2[2][0]==88){
              board2[0][2]=79;
              nextplay=1;
            }else if(board2[0][0]==255 && board2[1][1]==88 && board2[2][2]==88){
              board2[0][0]=79;
              nextplay=1;
            }
          }
        }
      }
        while(nextplay==0){//A random play for bot if it not played before
          srand(time(NULL));
          i=rand()%3;
          j=rand()%3;
          if(board2[i][j]==255){
            board2[i][j]=79;
            nextplay=1;
          }
        }
        nextplay=0;
    }
  rounds++;
  }
}
int main(){
  int players=1,score[2]={0,0};
  while(players==1 || players==2 || players==0){
  printf("---------------------------------\n");
  printf("|        TIC-TAC-TOE GAME       |\n");
  printf("---------------------------------\n");
  printf("Created by Marcos Marques\n");
    printf("\nOne or Two players?\n");
    scanf("%d",&players);
    if(players==1){
      printf("\n");
      board_drawing(1,score);
    }else if(players==2){
      printf("\n");
      board_drawing(2,score);
    }else{
      printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
      printf("!NOT SUPPORTED THIS NUMBER OF PLAYERS!\n");
      printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n");
      players=0;
    }
  }
  return 0;
}
