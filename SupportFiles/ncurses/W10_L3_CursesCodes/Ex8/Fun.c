#include<ncurses.h>
void printSnake(WINDOW *gameWin, int length, char* body, int *yLoc, int *xLoc)
{
	clear();
	for(int i=0;i<length;i++)
		mvwprintw(gameWin,*(yLoc+i),*(xLoc+i),"%c",*(body+i));

	wrefresh(gameWin);
	return;
}


void mvSnake(WINDOW *gameWin, int length, char* body, int *yLoc, int *xLoc,char *dir,int pressK)
{
	int tempX=*xLoc,tempY=*yLoc,modifyFlag=0;
	keypad(gameWin,true);
	wrefresh(gameWin);
	if ((pressK==KEY_UP)&&(*dir!='d')){*dir='u';modifyFlag=1;(*yLoc)--;}
	if ((pressK==KEY_DOWN)&&(*dir!='u')){*dir='d';modifyFlag=1;(*yLoc)++;}
	if ((pressK==KEY_RIGHT)&&(*dir!='l')){*dir='r';modifyFlag=1;(*xLoc)++;}
	if ((pressK==KEY_LEFT)&&(*dir!='r')){*dir='l';modifyFlag=1;(*xLoc)--;}
	
	if( modifyFlag==1)
	{
		for (int i=length-1;i>1;i--)
		{*(yLoc+i)=*(yLoc+i-1);  *(xLoc+i)=*(xLoc+i-1);}

		*(yLoc+1)=tempY;        *(xLoc+1)=tempX;
	}
	wrefresh(gameWin);
	return;
}

