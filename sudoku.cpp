#include<iostream>
#include<iomanip>
#include<windows.h>
#include<conio.h>
#include<cmath>
using namespace std;
void playSudoku();
void exitmenu();
void checkgame();
void upkey();
void downkey();
void leftkey();
void rightkey();
void pausegame();
void helpsudoku(string located);
void setpuzzle(int level);
void makepuzzle(string target,string puzzle);
void setnumberkey(string value);
void show_progress_hardmode(double finalprogress);
void hidecursor(bool condition);
void gotomenu(char choice);
void colorSet(int tint);
void gamepart(string part);
void maingame();
char gamelevel();
int level=0;
int correct=0;
int sudokupointer=0;
int sudokupuzzlesize;
int sudokubuildnumber;
double finalprogress=0;
string sudokustatus;
string sudokupuzzle[81];
string sudokuhighlight[81];
string sudokusolution[81];
int main(){
	hidecursor(true);  //hide cursor
	SetConsoleTitle(("Sudoku"));
	int choice; //variable
	//display
	while(true){
		system("cls");
		system("COLOR CF");
		colorSet(4); //red
		gamepart("line_small_left");
		colorSet(15);//white
		cout<<"SUDOKU";
		colorSet(4);
		gamepart("line_small_right");
		colorSet(15);
		cout<<"[1]";
		colorSet(11); //cyan
		cout<<"START"<<endl;
		colorSet(15);
		cout<<"[2]";
		colorSet(14);
		cout<<"INSTRUCTIONS"<<endl;
		colorSet(15);
		cout<<"[3]";
		colorSet(12);
		cout<<"EXIT"<<endl;
		colorSet(4);
		gamepart("seperator");
		colorSet(7);
		//get user choice
		cout<<endl<<"Press number of your choice: ";
		colorSet(15);
		char select=getch();
		if(!(select<'1' || select>'3')){
			choice=select;
			break;
		}
	}
	//goto menu of users choice
	gotomenu(choice);
}
void gotomenu(char choice){
		system("COLOR DF");
	if(choice=='1'){
		playSudoku();//goto to play menu
	}
	else if(choice=='2'){
		helpsudoku("main");//instructions
	}
	else if(choice=='3'){
		exitmenu();//exit 
	}
}
void playSudoku(){
			//game level
	char setlevel=gamelevel();
	//condition level
	if(setlevel=='4'){
		//goto menu
		main();
	}
	else{
		level=(int)setlevel-48;  //initialize level
		setpuzzle(level);  //set level
		sudokustatus= "playing";  //set status
		sudokupointer=0; //reset pointer
		checkgame(); //for progress
		maingame(); //enter the game
	}
	//pause
	getch();
	//goto main menu
	main();
}
char gamelevel(){
	//gamevcentral
	char choice;
	do{
		//display
		system("cls");
		colorSet(4);
		gamepart("line_small_left");
		colorSet(15); //white
		cout<<"SUDOKU";
		colorSet(4); //red
		gamepart("line_small_right");
		colorSet(13);
		cout<<setw(29)<<right<<"Select difficulty level"<<endl;
		colorSet(4);
		gamepart("seperator");
		colorSet(15);
		cout<<"[1]";
		colorSet(10);
		cout<<"Easy"<<endl;
		colorSet(15);
		cout<<"[2]";
		colorSet(14); //yellow
		cout<<"Medium"<<endl;
		colorSet(15);  
		cout<<"[3]";
		colorSet(12);
		cout<<"Hard"<<endl;
		colorSet(4);
		gamepart("seperator");
		colorSet(15);
		cout<<"[4]";
		colorSet(11); //light grey
		cout<<"Back"<<endl;
		colorSet(4);
		gamepart("seperator");
		colorSet(7);
		cout<<"press the number of your choice";
		colorSet(15);
		char select=getch();
		//get user choice
		if(!(select<'1' ||select>'4')){
			choice=select;
			break;
		}
	}while(true);
		return choice;
}
//hard level progress
void show_progress_hardmode(double finalprogress){
	if(finalprogress>=69){
		if(finalprogress>=84){
			if(finalprogress>=94){
				cout<<"Just a little bit";
				
	finalprogress=round(((double(correct)/81.0)*100.0));
	cout<<endl<<finalprogress;
	}
	else{
	    cout<<"Almost there!";
	    
	finalprogress=round(((double(correct)/81.0)*100.0));
	}
}
	else{
		cout<<"Half way there!";
		
	finalprogress=round(((double(correct)/81.0)*100.0));
	}
}
	else{
		cout<<"Unfinished";
		
	finalprogress=round(((double(correct)/81.0)*100.0));
	}
}
//sets the puzzle
void setpuzzle(int level){
	string dot= ".";
	string puzzle,highlight,solution;
	system("COLOR EF");

	if(level==1){
		//easy level
		puzzle  = ( " .7.8|3.1. | . . "   +  dot
		        +   " .4. | .2.6|5. . "   +  dot
		        +   "6. . |9.4.7|8. .1"   +  dot
		        
		        +   "2. . | . . | .4. "   +  dot
		        +   "5. . |7. .1| . .2"   +  dot
		        +   " .1. | . . | . .3"   +  dot
		        
		        +   "4. .5| . . | . .9"   +  dot
		        +   " . .1|4.5. | .2. "   +  dot
		        +   " . . | .9.2|4.7. ");
		        
	highlight   =  ( "0.F.F|F.F.0|0.0.0"  +  dot
		        +    "0.F.0|0.F.F|F.0.0"  +  dot
		        +    "F.0.0|F.F.F|F.0.F"  +  dot
		        
		        +    "F.0.0|0.0.0|0.F.0"  +  dot
		        +    "F.0.0|F.0.F|0.0.F"  +  dot
		        +    "0.F.0|0.0.0|0.0.F"  +  dot
		        
		        +    "F.0.F|0.0.0|0.0.F"  +  dot
		        +    "0.0.F|F.F.0|0.F.0"  +  dot
		        +    "0.0.0|0.F.F|F.F.0");      
		        
	solution    =( "9.7.8|3.1.5|2.6.4"    +  dot
		        +  "1.4.3|8.2.6|5.9.7"    +  dot
		        +  "6.5.2|9.4.7|8.3.1"    +  dot
		        
		        +  "2.3.7|5.8.9|1.4.6"    +  dot
		        +  "5.6.4|7.3.1|9.8.2"    +  dot
		        +  "8.1.9|2.6.4|7.5.3"    +  dot
		        
		        +  "4.2.5|6.7.8|3.1.9"    +  dot
		        +  "7.9.1|4.5.3|6.2.8"    +  dot
		        +  "3.8.6|1.9.2|4.7.5");
	}
	else if(level==2){
		//medium level
		puzzle  = ( " .8.4|2. . | . .9"  +  dot
		        +   "1. .2|8. . |5. . "  +  dot
		        +   "9. . | .6. | . .3"  +  dot
		        
		        +   " .9. | . . |2.7. "  +  dot
		        +   "5. . | . . | . .8"  +  dot
		        +   " .4.8| . . | .3. "  +  dot
		        
		        +   "7. . | .2. | . .1"  +  dot
		        +   " . .3| . .6|7. .4"  +  dot
		        +   "4. . | . .5|3.9. ");
		        
	highlight  = ("0.F.F|F.0.0|0.0.F"  +  dot
		       +  "F.0.F|F.0.0|F.0.0"  +  dot
		       +  "F.0.0|0.F.0|0.0.F"  +  dot
		        
		       +  "0.F.0|0.0.0|F.F.0"  +  dot
		       +  "F.0.0|0.0.0|0.0.F"  +  dot
		       +  "0.F.F|0.0.0|0.F.0"  +  dot
		        
		       +  "F.0.0|0.F.0|0.0.F"  +  dot
		       +  "0.0.F|0.0.F|F.0.F"  +  dot
		       +  "F.0.0|0.0.F|F.F.0");      
		        
	solution    =( "3.8.4|2.5.7|1.6.9"  +  dot
		        +  "1.6.2|8.3.9|5.4.7"  +  dot
		        +  "9.7.5|1.6.4|8.2.3"  +  dot
		        
		        +  "6.9.1|3.4.8|2.7.5"  +  dot
		        +  "5.3.7|6.9.2|4.1.8"  +  dot
		        +  "2.4.8|5.7.1|9.3.6"  +  dot
		        
		        +  "7.5.9|4.2.3|6.8.1"  +  dot
		        +  "8.2.3|9.1.6|7.5.4"  +  dot
		        +  "4.1.6|7.8.5|3.9.2");
	}
	else{
		//hard level
		puzzle =( " .8. |5.2. |6.4. "  +  dot
		       +  "7. .6| . . | . .2"  +  dot
		       +  "4.2. | . . | .3. "  +  dot
		        
		       +  " .5. | . .1| . . "  +  dot
		       +  "6. . |7.8.3| . .9"  +  dot
		       +  " . . |9. . | .6. "  +  dot
		        
		       +  " .3. | . . | .2.6"  +  dot
		       +  "1. . | . . |3. .5"  +  dot
		       +  " .9.2| .3.5| . . ");
		        
	highlight  = ("0.F.0|F.F.0|F.F.0"  +  dot
		       +  "F.0.F|0.0.0|0.0.F"  +  dot
		       +  "F.F.0|0.0.0|0.F.0"  +  dot
		        
		       +  "0.F.0|0.0.F|0.0.0"  +  dot
		       +  "F.0.0|F.F.F|0.0.F"  +  dot
		       +  "0.0.0|F.0.0|0.F.0"  +  dot
		        
		       +  "0.F.0|0.0.0|0.F.F"  +  dot
		       +  "F.0.0|0.0.0|F.0.F"  +  dot
		       +  "0.F.F|0.F.F|0.0.0");      
		        
	solution    =( "9.8.3|5.2.7|6.4.1"  +  dot
		        +  "7.1.6|3.4.8|5.9.2"  +  dot
		        +  "4.2.5|1.9.6|7.3.8"  +  dot
		        
		        +  "2.5.9|4.6.1|8.7.3"  +  dot
		        +  "6.4.1|7.8.3|2.5.9"  +  dot
		        +  "3.7.8|9.5.2|1.6.4"  +  dot
		        
		        +  "5.3.7|8.1.4|9.2.6"  +  dot
		        +  "1.6.4|2.7.9|3.8.5"  +  dot
		        +  "8.9.2|6.3.5|4.1.7");
	}
	//create the puzzle
	makepuzzle("puzzle_layout",puzzle);
	makepuzzle("highlight_layout",highlight);
	makepuzzle("solution_layout",solution);
}
//convert string puzzle to array
void makepuzzle(string target, string puzzle){
    //Variables
    char cpuzzle[puzzle.length()];
    int i;
    int pointer = 0;
    //Loop Function
    for (i = 0; i < sizeof(cpuzzle); i++) {
        cpuzzle[i] = puzzle[i];
        if(!(cpuzzle[i] == '.'||cpuzzle[i] == '|')){
        	
        	string sudokunumber(1, cpuzzle[i]);
        	if(target == "puzzle_layout"){
        		//cout <<"["<<pointer<<"]: "<<sudokuNumber<<"  ";
        		sudokupuzzle[pointer] = sudokunumber;	
			}
			else if(target == "highlight_layout"){
				//cout <<"["<<pointer<<"]: "<<sudokuNumber<<"  ";
				sudokuhighlight[pointer] = sudokunumber;
			}
			else if(target == "solution_layout"){
				//cout <<"["<<pointer<<"]: "<<sudokuNumber<<"  ";
				sudokusolution[pointer] = sudokunumber;
			}
        	pointer++;
		}
		
    }
    cout<<endl<<endl;
    
}
//main game
void maingame(){
	//---HEADER----
	system("cls");
	colorSet(4);
	gamepart("line_small_left");
	colorSet(15);
	cout<<"SUDOKU";
	colorSet(4);
	gamepart("line_small_right");
	//level and collect part
	switch(level){
		case 1:
			colorSet(10);
			cout<<setw(24)<<right<<"EASY LEVEL"<<endl;
			break;
		case 2:
			colorSet(14);
			cout<<setw(24)<<right<<"MEDIUM LEVEL"<<endl;
			break;
		default:
			colorSet(12);
			cout<<setw(24)<<right<<"HARD LEVEL"<<endl;
	}
	colorSet(4);
	gamepart("seperator");
	cout<<endl;
	//set table color
	int colortable=5;
	//if player quits
	//gets sudoku puzzlesize
	sudokupuzzlesize = (sizeof(sudokupuzzle)/sizeof(sudokupuzzle[0]));
	//fetch solution
	if(sudokustatus == "quitted"){
		for(int checker=0 ; checker < sudokupuzzlesize ; checker++){
			sudokupuzzle[checker] = sudokusolution[checker];
		}
	}
	//sudoku build table
	sudokubuildnumber=0;//reset sudoku build number
	for(int tpart=1;tpart<=182;tpart++){
		//sudoku outer border
		if(tpart==1 || tpart==62 || tpart==122 || tpart==182){
			colorSet(colortable);
			gamepart("sudoku_outer_border");
		}
		//sudoku outer vertical border, part by part
		else if(tpart==2   || tpart==8   || tpart==14  || tpart==22  || tpart==28  || tpart==34  ||
		        tpart==42  || tpart==49  || tpart==55  || tpart==63  || tpart==69  || tpart==75  ||
				tpart==83  || tpart==89  || tpart==95  || tpart==103 || tpart==109 || tpart==115 ||
				tpart==123 || tpart==129 || tpart==135 || tpart==143 || tpart==149 || tpart==155 ||
				tpart==163 || tpart==169 || tpart==175){
					colorSet(colortable);
					gamepart("sudoku_outer_vertical_border_small");
				}
				else if(tpart==20  || tpart==40  || tpart==61 || tpart==81 || tpart==101 || tpart==121 ||
				        tpart==141 || tpart==161 || tpart==181){
				        	colorSet(colortable);
				        		gamepart("sudoku_outer_vertical_border_next_line");
						}
						else if(tpart==3   || tpart==5   || tpart==7   || tpart==9   || tpart==11  ||tpart==13 ||
								tpart==15   || tpart==17  || tpart==19  || tpart==23 || tpart==25  ||
								tpart==27  || tpart==29  || tpart==31  || tpart==33  ||
								tpart==35  || tpart==37  || tpart==39  || tpart==43  || tpart==45  ||
								tpart==47  || tpart==50  || tpart==52  || tpart==54  || tpart==56  ||
								tpart==58  || tpart==60  || tpart==64  || tpart==66  || tpart==68  ||
				                tpart==70  || tpart==72  || tpart==74  || tpart==76  || tpart==78  ||
								tpart==80  || tpart==84  || tpart==86  || tpart==88  || tpart==90  ||
								tpart==92  || tpart==94  || tpart==96  || tpart==98  || tpart==100 ||
				                tpart==104 || tpart==106 || tpart==108 || tpart==110 || tpart==112 || 
								tpart==114 || tpart==116 || tpart==118 || tpart==120 || tpart==124 ||
								tpart==126 || tpart==128 || tpart==130 || tpart==132 || tpart==134 ||
				                tpart==136 || tpart==138 || tpart==140 || tpart==144 || tpart==146 ||
								tpart==148 || tpart==150 || tpart==152 || tpart==154 || tpart==156 ||
								tpart==158 || tpart==160 || tpart==164 || tpart==166 || tpart==168 ||
								tpart==170 || tpart==172 || tpart==174 ||tpart==176  || tpart==178 ||
								tpart==180){
					               colorSet(15);
					if(sudokuhighlight[sudokubuildnumber]=="0"){
						colorSet(15);
					}
					else if(sudokuhighlight[sudokubuildnumber]=="F"){
						colorSet(14);
					}
					if(sudokustatus == "quitted"  || sudokustatus == "finished"){
						cout<<sudokupuzzle[sudokubuildnumber];
					}
					else{
						if(sudokubuildnumber==sudokupointer){
							colorSet(10);
							if(sudokuhighlight[sudokupointer]=="F"){
								colorSet(11);
								cout<<sudokupuzzle[sudokubuildnumber];
							}
					else{
						if(sudokupuzzle[sudokubuildnumber] == "1" || sudokupuzzle[sudokubuildnumber]== "2"  ||
						   sudokupuzzle[sudokubuildnumber] == "2" || sudokupuzzle[sudokubuildnumber]== "3"  || 
						   sudokupuzzle[sudokubuildnumber] == "4" || sudokupuzzle[sudokubuildnumber]== "5"  ||
						   sudokupuzzle[sudokubuildnumber] == "6" || sudokupuzzle[sudokubuildnumber]== "7"  || 
						   sudokupuzzle[sudokubuildnumber] == "8" || sudokupuzzle[sudokubuildnumber]== "9"){
						  cout<<sudokupuzzle[sudokubuildnumber];
		}
		else{
			cout<<"x" ;
		}
	}
		
					}
					else{
						cout<<sudokupuzzle[sudokubuildnumber];
					}
				}
					sudokubuildnumber++;
					}
					else if(tpart==4   || tpart==6   || tpart==10  || tpart==12  || tpart==16  ||tpart==18   ||
		                    tpart==24  || tpart==26  || tpart==30  || tpart==32  || tpart==36  || tpart==38  ||
				            tpart==44  || tpart==46  || tpart==51  || tpart==53  || tpart==57  || tpart==59  ||
				            tpart==65  || tpart==67  || tpart==71  || tpart==73  || tpart==77  || tpart==79  ||
				            tpart==85  || tpart==87  || tpart==91  || tpart==93  || tpart==97  || tpart==99  ||
				            tpart==105 || tpart==107 || tpart==111 || tpart==113 || tpart==117 || tpart==119 ||
			                tpart==125 || tpart==127 || tpart==131 || tpart==133 || tpart==137 || tpart==139 || 
							tpart==145 || tpart==147 || tpart==151 || tpart==153 || tpart==157 || tpart==159 ||
							tpart==165 || tpart==167 || tpart==171 || tpart==173 || tpart==177 || tpart==179 ){
					colorSet(colortable);
					gamepart("sudoku_inner_vertical_border_small");
				}
					else if(tpart==21 || tpart==41 || tpart==82 || tpart==102 || tpart==142 || tpart==162){
						colorSet(colortable);
						gamepart("sudoku_inner__border");
					}
	
	}
	
	cout<<endl;
	finalprogress=round(((double(correct)/81.0)*100.0));
	if(sudokustatus == "playing"){
		colorSet(11);
		cout<<" progress: ";
		colorSet(15);
		switch(level){
			case 1:
				cout<<correct<<"/81";
				break;
			case 2:
				cout<<finalprogress<<"%";
				break;
			default:
				show_progress_hardmode(finalprogress);
		}
		cout<<endl;
		colorSet(14);
		cout<<" press ";
		colorSet(12);
		cout<<" [ESC]";
		colorSet(15);
		cout<<" or ";
		colorSet(12);
		cout<<" [P] ";
		colorSet(14);
		cout<<"to pause the game";
	}
	else if(sudokustatus == "quitted" ){
		colorSet(14);
		cout<<"sorry you did not finish"<<endl
            <<"the sudoku puzzle"<<endl;
			colorSet(13);
			cout<<" Better luck next time"<<endl;
			colorSet(15);
			cout<<" By the way thats the soluition"<<endl<<endl;
			colorSet(7);
			cout<<"Press any key to exit the game";
			getch();
			main();   		
	}
	else if(sudokustatus == "finished"){
		colorSet(10);
		cout<<"Congratulations you solved"<<endl
		    <<"the Sudoku puzzle"<<endl;
			colorSet(11);
			cout<<"Your Sudoku Skills are"<<endl
			    <<"quite impressive!"<<endl<<endl;
			 colorSet(7);
			 cout<<"Press any key to exit the game";
			 getch();
			 main();
	}
	else{
		cout<<"Pointer: "<<sudokupointer<<endl;
		cout<<"Highlight: "<<sudokuhighlight[sudokupointer]<<endl;
	}
	while(true){
		int keypress;
		colorSet(15);
		keypress=0;
		keypress=getch();
		if(keypress==0 || keypress==224){
			keypress=256+getch();
			if(keypress==328){
				upkey();
				break;
			}
			else if(keypress==336){
				downkey();
				break;
			}
			else if(keypress==331){
				leftkey();
				break;
			}
			else if(keypress==333){
				rightkey();
				break;
			}
			else if(keypress==339){
				setnumberkey("clear");
				break;
			}
		}
		else{
			if(keypress==119 || keypress==87){
				upkey();
				break;
			}
			else if(keypress==115 || keypress==83){
				downkey();
				break;
			}
			else if(keypress==97 || keypress==65){
				leftkey();
				break;
			}
			else if(keypress==100 || keypress==68){
				rightkey();
				break;
			}
			if(keypress==49){
				setnumberkey("1");
				break;
			}
			else if(keypress==50){
				setnumberkey("2");
				break;
			}
			else if(keypress==51){
				setnumberkey("3");
				break;
			}
			else if(keypress==52){
				setnumberkey("4");
				break;
			}
			else if(keypress==53){
				setnumberkey("5");
				break;
			}
			else if(keypress==54){
				setnumberkey("6");
				break;
			}
			else if(keypress==55){
				setnumberkey("7");
				break;
			}
			else if(keypress==56){
				setnumberkey("8");
				break;
			}
			else if(keypress==57){
				setnumberkey("9");
				break;
			}
			else if(keypress==0){
				setnumberkey("clear");
				break;
			}
			else if(keypress==27 || keypress==112 || keypress==80){
				pausegame();
				break;
			}
			else{
				continue;
			}
		}
	}
	checkgame();
}
void checkgame(){
	sudokupuzzlesize= (sizeof(sudokupuzzle)/sizeof(sudokupuzzle[0]));
	correct=0;
	for(int sudokupointing=0;sudokupointing<sudokupuzzlesize;sudokupointing++){
		if(sudokupuzzle[sudokupointing]==sudokusolution[sudokupointing]){
			correct++;
		}
	}
	if(correct==sudokupuzzlesize){
		sudokustatus = "finished";  
	}
	maingame();
}
void upkey(){
	sudokupointer=sudokupointer-9;
	if(sudokupointer==-9){
		sudokupointer=72;
	}
	else if(sudokupointer==-8){
		sudokupointer=73;
	}
	else if(sudokupointer==-7){
		sudokupointer=74;
	}
	else if(sudokupointer==-6){
		sudokupointer=75;
	}
	else if(sudokupointer==-5){
		sudokupointer=76;
	}
	else if(sudokupointer==-4){
		sudokupointer=77;
	}
	else if(sudokupointer==-3){
		sudokupointer=78;
	}
	else if(sudokupointer==-2){
		sudokupointer=79;
	}
	else if(sudokupointer==-1){
		sudokupointer=80;
	}
}
void downkey(){
	sudokupointer=sudokupointer+9;
	if(sudokupointer==81){
		sudokupointer=0;
	}
	else if(sudokupointer==82){
		sudokupointer=1;
	}
	else if(sudokupointer==83){
		sudokupointer=2;
	}
	else if(sudokupointer==84){
		sudokupointer=3;
	}
	else if(sudokupointer==85){
		sudokupointer=4;
	}
	else if(sudokupointer==86){
		sudokupointer=5;
	}
	else if(sudokupointer==87){
		sudokupointer=6;
	}
	else if(sudokupointer==88){
		sudokupointer=7;
	}
	else if(sudokupointer==89){
		sudokupointer=8;
	}
}
void leftkey(){
	sudokupointer=sudokupointer-1;
	if(sudokupointer==62){
		sudokupointer=71;
	}
	else if(sudokupointer==71){
		sudokupointer=80;
	}
	else if(sudokupointer==53){
		sudokupointer=62;
	}
	else if(sudokupointer==44){
		sudokupointer=53;
	}
	else if(sudokupointer==35){
		sudokupointer=44;
	}
	else if(sudokupointer==26){
		sudokupointer=35;
	}
	else if(sudokupointer==17){
		sudokupointer=26;
	}
	else if(sudokupointer==8){
		sudokupointer=17;
	}
	else if(sudokupointer==-1){
		sudokupointer=8;
	}
}
void rightkey(){
	sudokupointer=sudokupointer+1;
	if(sudokupointer==81){
		sudokupointer=72;
	}
	else if(sudokupointer==72){
		sudokupointer=63;
	}
	else if(sudokupointer==63){
		sudokupointer=54;
	}
	else if(sudokupointer==54){
		sudokupointer=45;
	}
	else if(sudokupointer==45){
		sudokupointer=36;
	}
	else if(sudokupointer==36){
		sudokupointer=27;
	}
	else if(sudokupointer==27){
		sudokupointer=18;
	}
	else if(sudokupointer==18){
		sudokupointer=9;
	}
	else if(sudokupointer==9){
		sudokupointer=0;
	}
}
void setnumberkey(string value){
	
	if(!(value == "clear")){
		if(sudokuhighlight[sudokupointer] == "0"){
		sudokupuzzle[sudokupointer] = value;
		}
	}
	else{
		if(sudokuhighlight[sudokupointer] == "0"){
		sudokupuzzle[sudokupointer] = " ";
		}
	}

}
void pausegame(){
	do{
		system("cls");
		colorSet(4);
		gamepart("line_small_left");
		colorSet(15);
		cout<<"SUDOKU";
		colorSet(4);
		gamepart("line_small_right");
		colorSet(13);
		cout<<setw(24)<<right<<"GAME PAUSE"<<endl;
		colorSet(4);
		gamepart("seperator");
		colorSet(15);
		cout<<"[1]";
		colorSet(14);
		cout<<"RESUME"<<endl;
		colorSet(15);
		cout<<"[2]";
		colorSet(10);
		cout<<"INSTRUCTIONS"<<endl;
		colorSet(15);
		cout<<"[3]";
		colorSet(12);
		cout<<"QUIT";
		colorSet(4);
		gamepart("seperator");
		colorSet(7);
		cout<<"Press the number of your choice";
		colorSet(15);
		char select=getch();
		if(!(select<'1' || select>'3')){
			cout<<endl;
			if(select=='2'){
				helpsudoku("in-game");
			}
			else if(select== '3'){
				sudokustatus = "quitted";
			
				break;
			}
			else{
				break;
			}
		}
	}while(true);
}
void helpsudoku(string located){
	system("cls");
	colorSet(4);
	gamepart("line_small_left");
	colorSet(15);
	cout<<"SUDOKU";
	colorSet(4);
	gamepart("line_small_right");
	colorSet(13);
	cout<<setw(25)<<right<<"INSTRUCTIONS"<<endl;
	colorSet(4);
	gamepart("seperator");
	colorSet(10);
	cout<<"How to Play: "<<endl;
	colorSet(15);
	cout<<"* The sudoku puzzle consist of"<<endl
	    <<" a 9*9 grid, you have to fill"<<endl
	    <<" the empty squares using the"<<endl
	    <<" numbers 1 to 9."<<endl
	    <<"* use the 1-9 keys in your"<<endl
	    <<" keyboard to fill the sudoku"<<endl
	    <<"puzzle"
	    <<"* To move around the sudoku"<<endl
	    <<" puzzle,use the WASD letter"<<endl
	    <<" keys or the arrow keys"<<endl
	    <<"* Use backspace or delete key to"<<endl
	    <<" clear the number selected in"<<endl
	    <<" the sudoku puzzle"<<endl
	    <<"* Once you finish the sudoku"<<endl
	    <<" puzzle,it will prompt you that"<<endl
	    <<" you finished it if not you can"<<endl
	    <<" Press P that you can choose"<<endl
	    <<" \"QUIT\" in the pause menu"<<endl
	    <<" if your having a hard time."<<endl;
	colorSet(4);
	gamepart("seperator");
	colorSet(7);
	cout<<"Press any key to go back";
	colorSet(15);
	getch();
	if(located== "main" ){
		main();
	}
}
void exitmenu(){
	do{
		system("cls");
		colorSet(4);
		gamepart("line_small_left");
		colorSet(15);
		cout<<"SUDOKU";
		colorSet(4);
		gamepart("line_small_right");
		colorSet(13);
		cout<<setw(28)<<right<<"DO YOU WANT TO EXIT"<<endl;
		colorSet(4);
		gamepart("seperator");
		colorSet(15);
		cout<<"[1]";
		colorSet(12);
		cout<<"YES"<<endl;
		colorSet(15);
		cout<<"[2]";
		colorSet(10);
		cout<<"NO"<<endl;
		colorSet(4);
		gamepart("seperator");
		colorSet(7);
		cout<<"Press the number of your choice";
		colorSet(15);
		char select = getch();
		if(!(select<'1' || select>'2')){
			cout<<endl;
			if(select=='1'){
				exit(0);
			}
			else{
				main();
			}
		}
	}while(true);
}
void colorSet(int tint){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),tint);
}
void gamepart(string part){
	if(part == "line_small_left"){
		cout<<"=============== ";
	}
	else if(part == "line_small_right"){
		cout<<" ================"<<endl;
	}
	else if(part == "seperator"){
		cout<<"======================================="<<endl;
	}
	else if(part == "sudoku_outer_border"){
		cout<<" $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
	}
	else if(part == "sudoku_outer_vertical_border_small"){
		cout<<" $ ";
	}
	else if(part == "sudoku_outer_vertical_border_next_line"){
		cout<<" $"<<endl;
	}
	else if(part == "sudoku_inner_vertical_border_small"){
		cout<<" | ";
	}
	else if(part == "sudoku_inner_border"){
		cout<<" $---*---*---$---*---*---$---*---*---$"<<endl;
	}
	else{
		cout<<"";
	}
	
}
void hidecursor(bool condition){
	HANDLE out=GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible=(!(condition));
	GetConsoleCursorInfo(out, &cursorInfo);
}
