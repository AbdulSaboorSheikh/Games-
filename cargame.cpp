#include<iostream>
#include<conio.h>
#include<dos.h>
#include<windows.h>
//#include"classes.h"
#include<time.h>
#define screen_width 190
#define screen_height 26
#define win_width 70
using namespace std;
HANDLE console =GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;
int enemyY[3];
int enemyX[3];
int enemyflag[3];
char car[4][4]={ ' ','±','±',' ',
                  '±','±','±','±',
                  ' ','±','±',' ',
                  '±','±','±','±' };
               int car_pos=win_width/2;
               int score=0;
               void gotoxy(int x,int y){
               	CursorPosition.X=x;
               	CursorPosition.Y=y;
               	SetConsoleCursorPosition(console,CursorPosition);
			   }
			   void setcursor(bool visible, DWORD size){
			   	if(size==0)
			   	size=20;
			   	
			   CONSOLE_CURSOR_INFO lpCursor;
			   lpCursor.bVisible=visible;
			   lpCursor.dwSize=size;
			   SetConsoleCursorInfo(console,&lpCursor);
		}
		void drawborder(){
			for(int i=0;i<screen_height;i++){
				for(int j=0;j<17;j++){
					gotoxy(0+j,i);cout<<"±";
					gotoxy(win_width-j,i);cout<<"±";
				}
			}
			for(int i=0;i<screen_height;i++){
				gotoxy(screen_width,i);cout<<"±";
			}
		}
		void gen_enemy(int ind){
			enemyX[ind]=17+rand()%(33);
		}
		void drawenemy(int ind){
			if(enemyflag[ind]==true){
				gotoxy(enemyX[ind],enemyY[ind]);  cout<<"****";
				gotoxy(enemyX[ind],enemyY[ind]+1);cout<<" ** ";
				gotoxy(enemyX[ind],enemyY[ind]+2);cout<<"****";
				gotoxy(enemyX[ind],enemyY[ind]+3);cout<<" ** ";
			}
		}
		void eraseenemy(int ind){
			if(enemyflag[ind]==true){
				gotoxy(enemyX[ind],enemyY[ind]);  cout<<"    ";
				gotoxy(enemyX[ind],enemyY[ind]+1);cout<<"    ";
				gotoxy(enemyX[ind],enemyY[ind]+2);cout<<"    ";
				gotoxy(enemyX[ind],enemyY[ind]+3);cout<<"    ";
			}
		}
		void resetenemy(int ind){
			eraseenemy(ind);
			enemyY[ind]=1;
			gen_enemy(ind);
		}
		void drawcar(){
			for(int i=0;i<4;i++){
				for(int j=0;j<4;j++){
					gotoxy(j+car_pos,i+22);cout<<car[i][j];
				}
			}
		}
		void erasecar(){
			for(int i=0;i<4;i++){
				for(int j=0;j<4;j++){
		        gotoxy(j+car_pos,i+22);cout<<" "; 
				}
	       }
		}
		int collison(){
			if(enemyY[0]+4>=23){
				if(enemyX[0]+4 - car_pos>=0 && enemyX[0]+4 - car_pos<9){
					return 1;
				}
			}
			return 0;
		}
		void gameover(){
			system("cls");
			cout<<endl;
			cout<<"\t\t-------------------------"<<endl;
			cout<<"\t\tGAME OVER\t\t"<<endl;
			cout<<"\t\t------------------------------"<<endl;
			cout<<"Press any key to go back to menu"<<endl;
			getch();
		}
		void updatescore(){
			gotoxy(win_width+7,5);cout<<"Score: "<<score<<endl;
		}
		void instruction(){
			cout<< endl << endl << "Instructions"<<endl;
			cout<<"--------------------------"<<endl;
			cout<<"Avoid predators by moving left or right"<<endl;
			cout<<"Press a to move left"<<endl;
			cout<<"Press d to move right"<<endl;
			cout<<"Press escape to exit"<<endl;
			cout<<"Press any key to go back to menu"<<endl;
			getch();
		}
		void play(){
			car_pos= -1+win_width/2;
			score=0;
			enemyflag[0]=1;
			enemyflag[1]=0;
			enemyY[0]=enemyY[1]=1;
			system("cls");
			drawborder();
			updatescore();
			gen_enemy(0);
			gen_enemy(1);
			gotoxy(win_width +7, 2);cout<<"\t\t ALIEN V/S PREDATOR"<<endl;
			gotoxy(win_width +6, 4);cout<<"------------------";
			gotoxy(win_width +6, 6);cout<<"------------------";
			gotoxy(win_width +7, 12);cout<<"Control";
			gotoxy(win_width +7, 13);cout<<"---------------";
			gotoxy(win_width +2, 14);cout<<"A key left";
			gotoxy(win_width +2, 15);cout<<"D key right";
			gotoxy(18,5);cout<<"Press any key to start";
			getch();
			gotoxy(18,5);cout<<"                 ";
			while(1){
				if(kbhit()){
					char ch=getch();
					if(ch=='a' || ch=='A'){
						if (car_pos>18)
						car_pos-=4;
					}
					if(ch=='d' || ch=='D'){
						if (car_pos<50)
						car_pos+=4;
				}
				if(ch==27){
					break;
				}
			}
			drawcar();
			drawenemy(0);
			drawenemy(1);
			if(collison()==1){
				gameover();
				return;
			}
			Sleep(40);
			erasecar();
			eraseenemy(0);
			eraseenemy(1);
			if(enemyY[0]==10)
			if(enemyflag[1]==0)
			enemyflag[1]=1;
			if(enemyflag[0]==1)
			enemyY[0]+=1;
			if(enemyflag[1]==1)
			enemyY[1]+=1;
			if(enemyY[0]>screen_height-4){
				resetenemy(0);
				score++;
				updatescore();
			}
			if(enemyY[1]>screen_height-4){
				resetenemy(1);
				score++;
				updatescore();
			}
		}
	}
int main(){
	setcursor(0,0);
	srand((unsigned)time(NULL));
	do{
		system("cls");
		gotoxy(10,4);cout<<"WELCOME TO THE WORLD OF GAMES";
		gotoxy(10,5);cout<<"-----------------------------------";
		gotoxy(10,6);cout<<"         ALIEN V/S PREDATOR             ";
		gotoxy(10,7);cout<<"-----------------------------------";
		gotoxy(10,9);cout<<"1. Start game";
		gotoxy(10,10);cout<<"2. Instructions";
		gotoxy(10,11);cout<<"3. Quit game";
		gotoxy(10,13);cout<<"Select option: ";
		char op=getche();
		if(op=='1') play();
		else if(op=='2') instruction();
		else if(op=='3') exit(0);
	}while(1);
	return 0;
}
