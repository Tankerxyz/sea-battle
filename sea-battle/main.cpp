#include <iostream>
#include <iomanip>
#include <string.h>
#include <conio.h>
#include <windows.h>
#define CLR system("cls");
#define N 10
using namespace std;
int schetchik=0,vistrel_udalsya[2][2];

void gotoxy(short x, short y)
{
    HANDLE StdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD  coord  = {x, y};
    SetConsoleCursorPosition(StdOut, coord);
}
void SetColor(int text, int background=0)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}


struct pole
{
	unsigned kub:2;
};
struct korab
{
	unsigned sost:2;
	int i;
	int j;
};
struct korabli
{
	int four;
	int three;
	int two;
	int one;
	korab Four[4],Three[2][3],Two[3][2],One[4][1];
}player1={1,2,3,4},player2={1,2,3,4};

int proverka(pole a[][N],int key,int razmer,int i,int j,int b)
{
	int temp_i=i,temp_j=j;
	if(!b)
	{
		if(!a[i][j].kub);
		else return 0;
	}
	for(int k=0;k<razmer;k++)
	{
		if(i<0||j<0||i>9||j>9) return 0;
		
		if(i==0)
			if(j==0)
				if(!b)
				{
					if(!a[i][j+1].kub&&!a[i+1][j].kub&&!a[i+1][j+1].kub);
					else return 0;
				}
				else
				{
					a[i][j+1].kub=2;a[i+1][j].kub=2;a[i+1][j+1].kub=2;
				}
			else if(j==9)
				if(!b)
				{
					if(!a[i+1][j].kub&&!a[i][j-1].kub&&!a[i+1][j-1].kub);
					else return 0;
				}
				else
				{
					a[i+1][j].kub=2;a[i][j-1].kub=2;a[i+1][j-1].kub=2;
				}
				
			else
			{
				if(!b)
				{
					if(!a[i][j-1].kub&&!a[i][j+1].kub&&!a[i+1][j].kub&&!a[i+1][j-1].kub&&!a[i+1][j+1].kub);
					else return 0;
				}
				else
				{
					a[i][j-1].kub=2;a[i][j+1].kub=2;a[i+1][j].kub=2;a[i+1][j-1].kub=2;a[i+1][j+1].kub=2;
				}
			}

		else if(i==9)
			if(j==9)
			{
				if(!b)
				{
					if(!a[i-1][j].kub&&!a[i][j-1].kub&&!a[i-1][j-1].kub);
					else return 0;
				}
				else
				{
					a[i-1][j].kub=2;a[i][j-1].kub=2;a[i-1][j-1].kub=2;
				}
			}
			else if(j==0)
			{
				if(!b)
				{
					if(!a[i-1][j].kub&&!a[i][j+1].kub&&!a[i-1][j+1].kub);
					else return 0;
				}
				else
				{
					a[i-1][j].kub=2;a[i][j+1].kub=2;a[i-1][j+1].kub=2;
				}
			}
			else
			{
				if(!b)
				{
					if(!a[i][j-1].kub&&!a[i][j+1].kub&&!a[i-1][j].kub&&!a[i-1][j-1].kub&&!a[i-1][j+1].kub);
					else return 0;
				}
				else
				{
					a[i][j-1].kub=2;a[i][j+1].kub=2;a[i-1][j].kub=2;a[i-1][j-1].kub=2;a[i-1][j+1].kub=2;
				}
			}

		else if(j==0)
		{
			if(!b)
			{
				if(!a[i-1][j].kub&&!a[i+1][j].kub&&!a[i][j+1].kub&&!a[i-1][j+1].kub&&!a[i+1][j+1].kub);
					else return 0;
			}
			else
			{
				a[i-1][j].kub=2;a[i+1][j].kub=2;a[i][j+1].kub=2;a[i-1][j+1].kub=2;a[i+1][j+1].kub=2;

			}
		}

		else if(j==9)
		{
			if(!b)
			{
				if(!a[i-1][j].kub&&!a[i+1][j].kub&&!a[i][j-1].kub&&!a[i-1][j-1].kub&&!a[i+1][j-1].kub);
					else return 0;
			}
			else
			{
				a[i-1][j].kub=2;a[i+1][j].kub=2;a[i][j-1].kub=2;a[i-1][j-1].kub=2;a[i+1][j-1].kub=2;
			}
		}
		else
		{
			if(!b)
			{
				if(!a[i-1][j].kub&&!a[i-1][j+1].kub&&!a[i][j+1].kub&&!a[i+1][j+1].kub&&!a[i+1][j].kub&&!a[i+1][j-1].kub&&!a[i][j-1].kub&&!a[i-1][j-1].kub);
				else return 0;
			}
			else
			{
				a[i-1][j].kub=2;a[i-1][j+1].kub=2;a[i][j+1].kub=2;a[i+1][j+1].kub=2;a[i+1][j].kub=2;a[i+1][j-1].kub=2;a[i][j-1].kub=2;a[i-1][j-1].kub=2;
			}
		}

		if(key==0) i--;
		else if(key==1) j++;
		else if(key==2) i++;
		else if(key==3) j--;
	}
	if(b)
	{
		i=temp_i;j=temp_j;
		for(int k=0;k<razmer;k++)
		{
			a[i][j].kub=3;
			if(key==0) i--;
			else if(key==1) j++;
			else if(key==2) i++;
			else if(key==3) j--;
		}
		return 0;
	}
	return 1;
}
int proverka_na_sost(pole b[][N],korabli &player)
{
	int i,g,l,c=1;
	for(i=0;i<4;i++)//Проверка на уничтожение четырех палубного
		if(player.Four[i].sost)
			break;
	if(i==4)
	{
		if(player.Four[0].i==player.Four[1].i)
		{
			if(player.Four[0].j>player.Four[1].j) g=3;
			else g=1;	
		}
		else
		{
			if(player.Four[0].i>player.Four[1].i) g=0;
			else g=2;
		}
		c=proverka(b,g,4,player.Four[0].i,player.Four[0].j,1);
		player.four--;
		for(i=0;i<4;i++)
			player.Four[i].sost=2;
	}
	for(i=0;i<2;i++)//Проверка на уничтожение трех палубного
	{
		for(l=0;l<3;l++)
		{
			if(player.Three[i][l].sost)
				break;
		}
		if(l==3)
		{
				if(player.Three[i][0].i==player.Three[i][1].i)
				{
					if(player.Three[i][0].j>player.Three[i][1].j) g=3;
					else g=1;	
				}
				else
				{
					if(player.Three[i][0].i>player.Three[i][1].i) g=0;
					else g=2;
				}
				c=proverka(b,g,3,player.Three[i][0].i,player.Three[i][0].j,1);
				player.three--;
				for(int l=0;l<3;l++)
					player.Three[i][l].sost=2;
		}
	}
	for(i=0;i<3;i++)//Проверка на уничтожение двух палубного
	{
		for(l=0;l<2;l++)
		{
			if(player.Two[i][l].sost)
				break;
		}
		if(l==2)
		{
				if(player.Two[i][0].i==player.Two[i][1].i)
				{
					if(player.Two[i][0].j>player.Two[i][1].j) g=3;
					else g=1;	
				}
				else
				{
					if(player.Two[i][0].i>player.Two[i][1].i) g=0;
					else g=2;
				}
				c=proverka(b,g,2,player.Two[i][0].i,player.Two[i][0].j,1);
				player.two--;
				for(int l=0;l<2;l++)
					player.Two[i][l].sost=2;
		}
	}
	for(i=0;i<4;i++)//Проверка на уничтожение однопалубного
	{
		if(player.One[i][0].sost);
		else
		{
				c=proverka(b,0,1,player.One[i][0].i,player.One[i][0].j,1);
				player.one--;
				player.One[i][0].sost=2;
		}
	}
	return c;
}
int proverka_na_podbitie(korabli &player,int i,int j)
{
	for(int k=0;k<4;k++)
	{
		if(i==player.Four[k].i&&j==player.Four[k].j)
		{
			player.Four[k].sost=0;return 1;
		}
	}
	for(int k=0;k<2;k++)
		for(int l=0;l<3;l++)
			if(i==player.Three[k][l].i&&j==player.Three[k][l].j)
			{
				player.Three[k][l].sost=0;return 1;
			}

	for(int k=0;k<3;k++)
		for(int l=0;l<2;l++)
			if(i==player.Two[k][l].i&&j==player.Two[k][l].j)
			{
				player.Two[k][l].sost=0;return 1;
			}

	for(int k=0;k<4;k++)
		if(i==player.One[k][0].i&&j==player.One[k][0].j)
		{
			player.One[k][0].sost=0;return 1;
		}
}
void ustanovka(pole a[][N],int key,int razmer,int i,int j,korabli &player)
{
	for(int k=0;k<razmer;k++)
	{
		if(razmer==4)
		{
			player.Four[k].i=i;
			player.Four[k].j=j;
			player.Four[k].sost=1;
		}
		else if(razmer==3)
		{
			player.Three[schetchik][k].i=i;
			player.Three[schetchik][k].j=j;
			player.Three[schetchik][k].sost=1;
		}
		else if(razmer==2)
		{
			player.Two[schetchik][k].i=i;
			player.Two[schetchik][k].j=j;
			player.Two[schetchik][k].sost=1;
		}
		else if(razmer==1)
		{
			player.One[schetchik][k].i=i;
			player.One[schetchik][k].j=j;
			player.One[schetchik][k].sost=1;
		}
		a[i][j].kub=1;
		if(key==0) i--;
		else if(key==1) j++;
		else if(key==2) i++;
		else if(key==3) j--;
	}
	if(razmer == 3&&schetchik==0)
		schetchik++;
	else if(razmer == 3)
		schetchik=0;
	else if(razmer == 2&&schetchik==0||schetchik==1)
		schetchik++;
	else if(razmer == 2)
		schetchik=0;
	else if(razmer == 1&&schetchik==0||schetchik==1||schetchik==2)
		schetchik++;
	else if(razmer == 1)
		schetchik=0;
}
int shot(pole a[][N],pole b[][N],int i,int j,int g,int h)
{
	if(g==0)//стреляет игрок
	{
		if(a[i][j].kub==0&&b[i][j].kub==0)
		{
			b[i][j].kub=2;return 1;
		}
		else if(a[i][j].kub==1&&b[i][j].kub==0)
		{
			if(h==1) proverka_na_podbitie(player2,i,j);
			else proverka_na_podbitie(player1,i,j);
			a[i][j].kub=2;
			b[i][j].kub=1;
			return 2;
		}
		return 0;
	}
	if(g==1)//стреляет бот
	{
		if(a[i][j].kub==0&&b[i][j].kub==0)
		{
			b[i][j].kub=2;return 1;
		}
		else if(a[i][j].kub==1&&b[i][j].kub==1)
		{
			proverka_na_podbitie(player1,i,j);
			vistrel_udalsya[0][0]=i;vistrel_udalsya[0][1]=j;
			a[i][j].kub=2;
			b[i][j].kub=3;
			return 2;
		}
		return 0;
	}
	
}
void autoput(pole ar[][N],korabli *player)
{
	int kor,napr,i,j;
	while(player->four>0||player->three>0||player->two>0||player->one>0)
	{
		if(player->four>0) kor=4;
		else if(player->three>0) kor=3;
		else if(player->two>0) kor=2;
		else if(player->one>0) kor=1;
		else break;
		while(1)
		{
			napr=rand()%4;
			i=rand()%N;
			j=rand()%N;
			if(proverka(ar,napr,kor,i,j,0)) 
			{
				if(kor==4&&player->four>0)
				{
					player->four--;
					ustanovka(ar,napr,kor,i,j,*player);
					break;
				}
				if(kor==3&&player->three>0)
				{
					player->three--;
					ustanovka(ar,napr,kor,i,j,*player);
					break;
				}
				if(kor==2&&player->two>0)
				{
					player->two--;
					ustanovka(ar,napr,kor,i,j,*player);
					break;
				}
				if(kor==1&&player->one>0)
				{
					player->one--;
					ustanovka(ar,napr,kor,i,j,*player);
					break;
				}
			}
		}
	}
}
void koor(char key[],int &i,int &j)
{
	if(key[0]>0&&key[1]>0)
	{
		if(isdigit(key[0])&&isalpha(key[1]))
		{
			if((int)key[1]>=65&&(int)key[1]<=74)
			{
				 i=key[0]-48;j=key[1]-65;
			}
			else if((int)key[1]>=97&&(int)key[1]<=106)
			{
				i=key[0]-48;j=key[1]-97;
			}
		}
		else if(isdigit(key[1])&&isalpha(key[0]))
		{
			if((int)key[0]>=65&&(int)key[0]<=74)
			{
				 i=key[1]-48;j=key[0]-65;
			}
			else if((int)key[0]>=97&&(int)key[0]<=106)
			{
				i=key[1]-48;j=key[0]-97;
			}
		}
	}
}
void handput(pole ar[][N])
{
	int kor,napr=0,i=10,j=10,s4etchik=0;
	char key[3];
			while(1)
			{
				gotoxy(0,12);
				cout<<"Осталось кораблей:\n";
				cout<<"  Одинарный - "<<player1.one<<" осталось\n";
				cout<<"  Двойной - "<<player1.two<<" осталось\n";
				cout<<"  Тройной - "<<player1.three<<" осталось\n";
				cout<<"  Четверной - "<<player1.four<<" осталось\n";
				if(player1.one>0&&player1.two==0&&player1.three==0&&player1.four==0){kor=1;cout<<"Вы устанавливаете Одинарный";break;}
				else if(player1.two>0&&player1.three==0&&player1.four==0){kor=2;cout<<"Вы устанавливаете Двойной";break;}
				else if(player1.three>0&&player1.four==0){kor=3;cout<<"Вы устанавливаете Тройной";break;}
				else if(player1.four>0){kor=4; cout<<"Вы устанавливаете Четверной";break;}
			}
			while(kor!=1)
			{
				gotoxy(0,19);
				cout<<"Выберите направление нажав стрелку на клавиатуре:";
				napr=_getch();
				if(napr==72){napr=0;break;}
				else if(napr==75){napr=3;break;}
				else if(napr==77){napr=1;break;}
				else if(napr==80){napr=2;break;}
			}
			gotoxy(0,19);cout<<"											                             ";
			gotoxy(0,19);
			cout<<"Введите координату:";
			cin>>key;
			koor(key,i,j);
			if(i<10&&i>=0&&j<10&&j>=0)
			{
				if(proverka(ar,napr,kor,i,j,0)) 
				{
					if(kor==4&&player1.four>0)
					{
						player1.four--;
						ustanovka(ar,napr,kor,i,j,player1);
					}
					if(kor==3&&player1.three>0)
					{
						player1.three--;
						ustanovka(ar,napr,kor,i,j,player1);
					}
					if(kor==2&&player1.two>0)
					{
						player1.two--;
						ustanovka(ar,napr,kor,i,j,player1);
					}
					if(kor==1&&player1.one>0)
					{
						player1.one--;
						ustanovka(ar,napr,kor,i,j,player1);
					}
				}
				else
				{
					gotoxy(0,19);cout<<"Ошибка координат...";Sleep(1500);
				}
			}
			else 
			{
				gotoxy(0,19);cout<<"error";Sleep(1500);
			}
}
void show(pole ar[][N],int b)
{
	int x=30,y=0;
	char c='A';
	if(b==1) gotoxy(x,y);
	cout<<"  ";
	for(int i=0;i<N;i++,c++)
		cout<<" "<<c;
	cout<<endl;
	for(int i=0;i<N;i++)
	{
		if(b==1) gotoxy(x,++y);
		cout<<i<<" |";
		for(int j=0;j<N;j++)
		{
			if(ar[i][j].kub==0&&j==N-1)
			{
				SetColor(3,1);
				cout<<"_"<<setw(1);
				SetColor(7,0);
			}
			else if(ar[i][j].kub==0)
			{
				SetColor(3,1);
				cout<<"_|"<<setw(1);
				SetColor(7,0);
			}
			else if(ar[i][j].kub==1&&j==N-1)
			{
				SetColor(7,6);
				cout<<"X"<<setw(1);
				SetColor(7,0);
			}
			else if(ar[i][j].kub==1&&(ar[i][j+1].kub==0||ar[i][j+1].kub==2))
			{
				SetColor(7,6);
				cout<<"X"<<setw(1);
				SetColor(3,1);
				cout<<"|"<<setw(1);
				SetColor(7,0);
			}
			else if(ar[i][j].kub==1)
			{
				SetColor(7,6);
				cout<<"X "<<setw(1);
				SetColor(7,0);
			}
			else if(ar[i][j].kub==2&&j==N-1)
			{
				SetColor(3,1);
				cout<<"0"<<setw(1);
				SetColor(7,0);
			}else if(ar[i][j].kub==2)
			{
				SetColor(3,1);
				cout<<"0"<<setw(1);
				SetColor(3,1);
				cout<<"|"<<setw(1);
				SetColor(7,0);
				
			}
			else if(ar[i][j].kub==3&&j==N-1)
			{
				SetColor(0,4);
				cout<<"X";
				SetColor(7,0);
				
			}
			else if(ar[i][j].kub==3&&(ar[i][j+1].kub==0||ar[i][j+1].kub==2))
			{
				SetColor(0,4);
				cout<<"X";
				SetColor(3,1);
				cout<<"|"<<setw(1);
				SetColor(7,0);
			}
			else if(ar[i][j].kub==3)
			{
				SetColor(0,4);
				cout<<"X ";
				SetColor(7,0);
				
			}
			else
			{
				
				SetColor(0,4);
				cout<<"X ";
				SetColor(7,0);
			}			
		}
		cout<<"|"<<endl;
	}
	cout<<endl<<endl;
}
int winer(pole ar[][N])
{
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			if(ar[i][j].kub==1)
				return 1;
	return 0;
	
}
int popal(pole a[][N],pole b[][N],int i,int j)
	
{
	int shot,temp_i,temp_j;
	if((i>0&&i<9)&&(j>0&&j<9))//Центр----------------------------------------------------------------------
	{
		if(b[i+1][j].kub!=2||b[i-1][j].kub!=2||b[i][j+1].kub!=2||b[i][j-1].kub!=2)
		{
			if(b[i+1][j].kub==3||b[i-1][j].kub==3||b[i][j+1].kub==3||b[i][j-1].kub==3)
			{
				if(b[i+1][j].kub==3&&(b[i-1][j].kub==0||b[i-1][j].kub==1)||b[i-1][j].kub==3&&(b[i+1][j].kub==0||b[i+1][j].kub==1))
				{
						if(b[i+1][j].kub==3) i--;
						else i++;
						if(a[i][j].kub==1)
						{
							vistrel_udalsya[1][0]=i; vistrel_udalsya[1][1]=j;
							a[i][j].kub=2; b[i][j].kub=3;  proverka_na_podbitie(player1,i,j);
							return 2;
						}
						else if(a[i][j].kub==0&&b[i][j].kub==0)
						{
							vistrel_udalsya[1][0]=-1;
							b[i][j].kub=2;return 1;
						}
				}
				else if(b[i][j+1].kub==3&&(b[i][j-1].kub==1||b[i][j-1].kub==0)||b[i][j-1].kub==3&&(b[i][j+1].kub==0||b[i][j+1].kub==1))
				{
						if(b[i][j+1].kub==3) j--;
						else j++;
						if(a[i][j].kub==1)
						{
							vistrel_udalsya[1][0]=i; vistrel_udalsya[1][1]=j;
							a[i][j].kub=2; b[i][j].kub=3;  proverka_na_podbitie(player1,i,j);
							return 2;
						}
						else if(a[i][j].kub==0&&b[i][j].kub==0)
						{
							vistrel_udalsya[1][0]=-1;
							b[i][j].kub=2;return 1;
						}
				}
				else if(vistrel_udalsya[1][0]==-1)
				{
					vistrel_udalsya[0][0]=-1;return 0;
				}
				else 
				{
					vistrel_udalsya[1][0]=-1;return 0;
				}
			}
			else if(b[i+1][j].kub!=3&&b[i-1][j].kub!=3&&b[i][j+1].kub!=3&&b[i][j-1].kub!=3)
			{
				while(1)
				{
					temp_i=i;temp_j=j;
					shot=rand()%4;
					if(shot==0) i--;
					else if(shot==1) j++;
					else if(shot==2) i++;
					else if(shot==3) j--;
					if(a[i][j].kub==1&&b[i][j].kub==1)
					{
						vistrel_udalsya[1][0]=i; vistrel_udalsya[1][1]=j;
						a[i][j].kub=2; b[i][j].kub=3;  proverka_na_podbitie(player1,i,j);
						return 2;
					}
					else if(a[i][j].kub==0&&b[i][j].kub==0)
					{
						b[i][j].kub=2;return 1;
					}
					else 
					{
						i=temp_i;j=temp_j;
					}
				}
			}
			else if(b[i+1][j].kub==0||b[i-1][j].kub==0||b[i][j+1].kub==0||b[i][j-1].kub==0)
			{
				while(1)
				{
					temp_i=i;temp_j=j;
					shot=rand()%4;
					if(shot==0) i--;
					else if(shot==1) j++;
					else if(shot==2) i++;
					else if(shot==3) j--;
					if(a[i][j].kub==1&&b[i][j].kub==1)
					{
						vistrel_udalsya[1][0]=i; vistrel_udalsya[1][1]=j;
						a[i][j].kub=2; b[i][j].kub=3;  proverka_na_podbitie(player1,i,j);
						return 2;
					}
					else if(a[i][j].kub==0&&b[i][j].kub==0)
					{
						b[i][j].kub=2;return 1;
					}
					else 
					{
						i=temp_i;j=temp_j;
					}
				}
			}
			else
			{
				vistrel_udalsya[0][0]=-1;return 0;
			}
		}
		else
		{
			vistrel_udalsya[0][0]=-1;return 0;
		}
	}
	else if(i==0&&j==0)//Верхний левый угол----------------------------------------------------------
	{
		if(b[i+1][j].kub!=2||b[i][j+1].kub!=2)
		{ 
			if(b[i+1][j].kub==2&&(b[i][j+1].kub==0||b[i][j+1].kub==1)||(b[i+1][j].kub==0||b[i+1][j].kub==1)&&b[i][j+1].kub==2)
			{
					if(b[i+1][j].kub==2) j++;
					else i++;
					if(a[i][j].kub==1)
					{
						vistrel_udalsya[1][0]=i; vistrel_udalsya[1][1]=j;
						a[i][j].kub=2; b[i][j].kub=3;  proverka_na_podbitie(player1,i,j);
						return 2;
					}
					else if(a[i][j].kub==0&&b[i][j].kub==0)
					{
						vistrel_udalsya[1][0]=-1;
						b[i][j].kub=2;return 1;
					}
			}
			else if((b[i+1][j].kub==0||b[i+1][j].kub==1)&&(b[i][j+1].kub==0||b[i][j+1].kub==1))
			{
				while(1)
				{
					shot=rand()%2;
					if(shot==0) j++;
					else if(shot==1) i++;
					if(a[i][j].kub==1&&b[i][j].kub==1)
					{
						vistrel_udalsya[1][0]=i; vistrel_udalsya[1][1]=j;
						a[i][j].kub=2; b[i][j].kub=3;  proverka_na_podbitie(player1,i,j);
						return 2;
					}
					else if(a[i][j].kub==0&&b[i][j].kub==0)
					{
						b[i][j].kub=2;return 1;
					}
				}
			}
			else if(b[i+1][j].kub==3||b[i][j+1].kub==3) 
			{
				if(vistrel_udalsya[1][0]==-1)
				{
					vistrel_udalsya[0][0]=-1;return 0;
				}
				else 
				{
					vistrel_udalsya[1][0]=-1;return 0;
				}
			}
			else 
			{
				vistrel_udalsya[0][0]=-1;return 0;
			}
		}
		else 
		{
			vistrel_udalsya[0][0]=-1;return 0;
		}
	}
	else if(i==0&&j>0&&j<9)//Верхний центр------------------------------------------------------------
	{
		if((b[i][j+1].kub==3&&b[i][j-1].kub==3)||(b[i][j+1].kub==3&&b[i][j-1].kub==2)||(b[i][j+1].kub==2&&b[i][j-1].kub==3))
		{
			vistrel_udalsya[0][0]=-1;return 0;	
		}
		else if(b[i+1][j].kub==3&&vistrel_udalsya[1][0]==-1)
		{
			vistrel_udalsya[0][0]=-1;return 0;	
		}
		else if(b[i+1][j].kub==3)
		{
			vistrel_udalsya[1][0]=-1;return 0;	
		}
		if(b[i+1][j].kub!=2||b[i][j+1].kub!=2||b[i][j-1].kub!=2)
		{
			if(b[i+1][j].kub==2)
			{
				if(b[i][j+1].kub==3&&(b[i][j-1].kub==1||b[i][j-1].kub==0)||b[i][j-1].kub==3&&(b[i][j+1].kub==0||b[i][j+1].kub==1))
				{
						if(b[i][j+1].kub==3) j--;
						else j++;
						if(a[i][j].kub==1)
						{
							vistrel_udalsya[1][0]=i; vistrel_udalsya[1][1]=j;
							a[i][j].kub=2; b[i][j].kub=3;  proverka_na_podbitie(player1,i,j);
							return 2;
						}
						else if(a[i][j].kub==0&&b[i][j].kub==0)
						{
							vistrel_udalsya[1][0]=-1;
							b[i][j].kub=2;return 1;
						}
				}
				else
				{
					while(1)
					{
						temp_i=i;temp_j=j;
						shot=rand()%2;
						if(shot==0) j++;
						else if(shot==1) j--;
						if(a[i][j].kub==1)
						{
							vistrel_udalsya[1][0]=i; vistrel_udalsya[1][1]=j;
							a[i][j].kub=2; b[i][j].kub=3;  proverka_na_podbitie(player1,i,j);
							return 2;
						}
						else if(a[i][j].kub==0&&b[i][j].kub==0)
						{
							vistrel_udalsya[1][0]=-1;
							b[i][j].kub=2;return 1;
						}
						else 
						{
							i=temp_i;j=temp_j;
						}
					}
				}
			}
			else if(b[i][j+1].kub==3||b[i][j-1].kub==3)
			{
				if(b[i][j+1].kub==3) j--;
				else j++;
				if(a[i][j].kub==1)
				{
					vistrel_udalsya[1][0]=i; vistrel_udalsya[1][1]=j;
					a[i][j].kub=2; b[i][j].kub=3;  proverka_na_podbitie(player1,i,j);
					return 2;
				}
				else if(a[i][j].kub==0&&b[i][j].kub==0)
				{
					vistrel_udalsya[1][0]=-1;
					b[i][j].kub=2;return 1;
				}
			}
			else
			{
				i++;
				if(a[i][j].kub==1)
				{
					vistrel_udalsya[1][0]=i; vistrel_udalsya[1][1]=j;
					a[i][j].kub=2; b[i][j].kub=3;  proverka_na_podbitie(player1,i,j);
					return 2;
				}
				else if(a[i][j].kub==0&&b[i][j].kub==0)
				{
					vistrel_udalsya[1][0]=-1;
					b[i][j].kub=2;return 1;
				}
				else
				{
					vistrel_udalsya[0][0]=-1;return 0;
				}
			}
		}
		else
		{
			vistrel_udalsya[0][0]=-1;return 0;
		}
	}
	else if(i==0&&j==9)//Верхний правый угол------------------------------------------------------------
	{
		if(b[i+1][j].kub!=2||b[i][j-1].kub!=2)
		{
			if(b[i+1][j].kub==2&&(b[i][j-1].kub==0||b[i][j-1].kub==1)||(b[i+1][j].kub==0||b[i+1][j].kub==1)&&b[i][j-1].kub==2)
			{
					if(b[i+1][j].kub==2) j--;
					else i++;
					if(a[i][j].kub==1)
					{
						vistrel_udalsya[1][0]=i; vistrel_udalsya[1][1]=j;
						a[i][j].kub=2; b[i][j].kub=3;  proverka_na_podbitie(player1,i,j);
						return 2;
					}
					else if(a[i][j].kub==0&&b[i][j].kub==0)
					{
						vistrel_udalsya[1][0]=-1;
						b[i][j].kub=2;return 1;
					}
			}
			else if((b[i+1][j].kub==0||b[i+1][j].kub==1)&&(b[i][j-1].kub==0||b[i][j-1].kub==1))
			{
				while(1)
				{
					shot=rand()%2;
					if(shot==0) j--;
					else if(shot==1) i++;
					if(a[i][j].kub==1&&b[i][j].kub==1)
					{
						vistrel_udalsya[1][0]=i; vistrel_udalsya[1][1]=j;
						a[i][j].kub=2; b[i][j].kub=3;  proverka_na_podbitie(player1,i,j);
						return 2;
					}
					else if(a[i][j].kub==0&&b[i][j].kub==0)
					{
						b[i][j].kub=2;return 1;
					}
				}
			}
			else if(b[i+1][j].kub==3||b[i][j-1].kub==3) 
			{
				if(vistrel_udalsya[1][0]==-1)
				{
					vistrel_udalsya[0][0]=-1;return 0;
				}
				else 
				{
					vistrel_udalsya[1][0]=-1;return 0;
				}
				
			}
			else 
			{
				vistrel_udalsya[0][0]=-1;return 0;
			}
		}
		else 
		{
			vistrel_udalsya[0][0]=-1;return 0;
		}
	}
	else if(j==9&&i>0&&i<9)//Правый центр------------------------------------------------------------
	{
		if((b[i+1][j].kub==3&&b[i-1][j].kub==3)||(b[i+1][j].kub==3&&b[i-1][j].kub==2)||(b[i+1][j].kub==2&&b[i-1][j].kub==3))
		{
			vistrel_udalsya[0][0]=-1;return 0;	
		}
		else if(b[i][j-1].kub==3&&vistrel_udalsya[1][0]==-1)
		{
			vistrel_udalsya[0][0]=-1;return 0;	
		}
		else if(b[i][j-1].kub==3)
		{
			vistrel_udalsya[1][0]=-1;return 0;	
		}
		if(b[i+1][j].kub!=2||b[i][j-1].kub!=2||b[i-1][j].kub!=2)
		{
			if(b[i][j-1].kub==2)
			{
				if(b[i+1][j].kub==3&&(b[i-1][j].kub==1||b[i-1][j].kub==0)||b[i-1][j].kub==3&&(b[i+1][j].kub==0||b[i+1][j].kub==1))
				{
						if(b[i+1][j].kub==3) i--;
						else i++;
						if(a[i][j].kub==1)
						{
							vistrel_udalsya[1][0]=i; vistrel_udalsya[1][1]=j;
							a[i][j].kub=2; b[i][j].kub=3;  proverka_na_podbitie(player1,i,j);
							return 2;
						}
						else if(a[i][j].kub==0&&b[i][j].kub==0)
						{
							vistrel_udalsya[1][0]=-1;
							b[i][j].kub=2;return 1;
						}
				}
				else
				{
					temp_i=i;temp_j=j;
					while(1)
					{
						shot=rand()%2;
						if(shot==0) i++;
						else if(shot==1) i--;
						if(a[i][j].kub==1)
						{
							vistrel_udalsya[1][0]=i; vistrel_udalsya[1][1]=j;
							a[i][j].kub=2; b[i][j].kub=3;  proverka_na_podbitie(player1,i,j);
							return 2;
						}
						else if(a[i][j].kub==0&&b[i][j].kub==0)
						{
							vistrel_udalsya[1][0]=-1;
							b[i][j].kub=2;return 1;
						}
						else 
						{
							i=temp_i;j=temp_j;
						}
					}
				}
			}
			else if(b[i+1][j].kub==3||b[i-1][j].kub==3)
			{
				if(b[i+1][j].kub==3) i--;
				else i++;
				if(a[i][j].kub==1)
				{
					vistrel_udalsya[1][0]=i; vistrel_udalsya[1][1]=j;
					a[i][j].kub=2; b[i][j].kub=3;  proverka_na_podbitie(player1,i,j);
					return 2;
				}
				else if(a[i][j].kub==0&&b[i][j].kub==0)
				{
					vistrel_udalsya[1][0]=-1;
					b[i][j].kub=2;return 1;
				}
			}
			else
			{
				j--;
				if(a[i][j].kub==1)
				{
					vistrel_udalsya[1][0]=i; vistrel_udalsya[1][1]=j;
					a[i][j].kub=2; b[i][j].kub=3;  proverka_na_podbitie(player1,i,j);
					return 2;
				}
				else if(a[i][j].kub==0&&b[i][j].kub==0)
				{
					vistrel_udalsya[1][0]=-1;
					b[i][j].kub=2;return 1;
				}
				else
				{
					vistrel_udalsya[0][0]=-1;return 0;
				}
			}
		}
		else
		{
			vistrel_udalsya[0][0]=-1;return 0;
		}
	}
	else if(i==9&&j==9)//Нижний правый угол------------------------------------------------------------
	{
		if(b[i-1][j].kub!=2||b[i][j-1].kub!=2)
		{
			if(b[i-1][j].kub==2&&(b[i][j-1].kub==0||b[i][j-1].kub==1)||(b[i-1][j].kub==0||b[i-1][j].kub==1)&&b[i][j-1].kub==2)
			{
					if(b[i-1][j].kub==2) j--;
					else i--;
					if(a[i][j].kub==1)
					{
						vistrel_udalsya[1][0]=i; vistrel_udalsya[1][1]=j;
						a[i][j].kub=2; b[i][j].kub=3;  proverka_na_podbitie(player1,i,j);
						return 2;
					}
					else if(a[i][j].kub==0&&b[i][j].kub==0)
					{
						vistrel_udalsya[1][0]=-1;
						b[i][j].kub=2;return 1;
					}
			}
			else if((b[i-1][j].kub==0||b[i-1][j].kub==1)&&(b[i][j-1].kub==0||b[i][j-1].kub==1))
			{
				while(1)
				{
					shot=rand()%2;
					if(shot==0) j--;
					else if(shot==1) i--;
					if(a[i][j].kub==1&&b[i][j].kub==1)
					{
						vistrel_udalsya[1][0]=i; vistrel_udalsya[1][1]=j;
						a[i][j].kub=2; b[i][j].kub=3;  proverka_na_podbitie(player1,i,j);
						return 2;
					}
					else if(a[i][j].kub==0&&b[i][j].kub==0)
					{
						b[i][j].kub=2;return 1;
					}
				}
			}
			else if(b[i-1][j].kub==3||b[i][j-1].kub==3) 
			{
				if(vistrel_udalsya[1][0]==-1)
				{
					vistrel_udalsya[0][0]=-1;return 0;
				}
				else 
				{
					vistrel_udalsya[1][0]=-1;return 0;
				}
			}
			else
			{
				vistrel_udalsya[0][0]=-1;return 0;
			}
		}
		else 
		{
			vistrel_udalsya[0][0]=-1;return 0;
		}
	}
	else if(i==9&&j>0&&j<9)//Нижний центр------------------------------------------------------------
	{
		if((b[i][j+1].kub==3&&b[i][j-1].kub==3)||(b[i][j+1].kub==3&&b[i][j-1].kub==2)||(b[i][j+1].kub==2&&b[i][j-1].kub==3))
		{
			vistrel_udalsya[0][0]=-1;return 0;	
		}
		else if(b[i-1][j].kub==3&&vistrel_udalsya[1][0]==-1)
		{
			vistrel_udalsya[0][0]=-1;return 0;	
		}
		else if(b[i-1][j].kub==3)
		{
			vistrel_udalsya[1][0]=-1;return 0;	
		}
		if(b[i-1][j].kub!=2||b[i][j-1].kub!=2||b[i][j+1].kub!=2)
		{
			if(b[i-1][j].kub==2)
			{
				if(b[i][j-1].kub==3&&(b[i][j+1].kub==1||b[i][j+1].kub==0)||b[i][j+1].kub==3&&(b[i][j-1].kub==0||b[i][j-1].kub==1))
				{
						if(b[i][j+1].kub==3) j--;
						else j++;
						if(a[i][j].kub==1)
						{
							vistrel_udalsya[1][0]=i; vistrel_udalsya[1][1]=j;
							a[i][j].kub=2; b[i][j].kub=3;  proverka_na_podbitie(player1,i,j);
							return 2;
						}
						else if(a[i][j].kub==0&&b[i][j].kub==0)
						{
							vistrel_udalsya[1][0]=-1;
							b[i][j].kub=2;return 1;
						}
				}
				else
				{
					while(1)
					{
						temp_i=i;temp_j=j;
						shot=rand()%2;
						if(shot==0) j++;
						else if(shot==1) j--;
						if(a[i][j].kub==1)
						{
							vistrel_udalsya[1][0]=i; vistrel_udalsya[1][1]=j;
							a[i][j].kub=2; b[i][j].kub=3;  proverka_na_podbitie(player1,i,j);
							return 2;
						}
						else if(a[i][j].kub==0&&b[i][j].kub==0)
						{
							vistrel_udalsya[1][0]=-1;
							b[i][j].kub=2;return 1;
						}
						else 
						{
							i=temp_i;j=temp_j;
						}
					}
				}
			}
			else if(b[i][j+1].kub==3||b[i][j-1].kub==3)
			{
				if(b[i][j+1].kub==3) j--;
				else j++;
				if(a[i][j].kub==1)
				{
					vistrel_udalsya[1][0]=i; vistrel_udalsya[1][1]=j;
					a[i][j].kub=2; b[i][j].kub=3;  proverka_na_podbitie(player1,i,j);
					return 2;
				}
				else if(a[i][j].kub==0&&b[i][j].kub==0)
				{
					vistrel_udalsya[1][0]=-1;
					b[i][j].kub=2;return 1;
				}
			}
			else
			{
				i--;
				if(a[i][j].kub==1)
				{
					vistrel_udalsya[1][0]=i; vistrel_udalsya[1][1]=j;
					a[i][j].kub=2; b[i][j].kub=3;  proverka_na_podbitie(player1,i,j);
					return 2;
				}
				else if(a[i][j].kub==0&&b[i][j].kub==0)
				{
					vistrel_udalsya[1][0]=-1;
					b[i][j].kub=2;return 1;
				}
				else
				{
					vistrel_udalsya[0][0]=-1;return 0;
				}
			}
		}
		else
		{
			vistrel_udalsya[0][0]=-1;return 0;
		}
	}
	else if(i==9&&j==0)//Нижний левый угол----------------------------------------------------------
	{
		if(b[i-1][j].kub!=2||b[i][j+1].kub!=2)
		{ 
			if(b[i-1][j].kub==2&&(b[i][j+1].kub==0||b[i][j+1].kub==1)||(b[i-1][j].kub==0||b[i-1][j].kub==1)&&b[i][j+1].kub==2)
			{
					if(b[i-1][j].kub==2) j++;
					else i--;
					if(a[i][j].kub==1)
					{
						vistrel_udalsya[1][0]=i; vistrel_udalsya[1][1]=j;
						a[i][j].kub=2; b[i][j].kub=3;  proverka_na_podbitie(player1,i,j);
						return 2;
					}
					else if(a[i][j].kub==0&&b[i][j].kub==0)
					{
						vistrel_udalsya[1][0]=-1;
						b[i][j].kub=2;return 1;
					}
			}
			else if((b[i-1][j].kub==0||b[i-1][j].kub==1)&&(b[i][j+1].kub==0||b[i][j+1].kub==1))
			{
				while(1)
				{
					shot=rand()%2;
					if(shot==0) j++;
					else if(shot==1) i--;
					if(a[i][j].kub==1&&b[i][j].kub==1)
					{
						vistrel_udalsya[1][0]=i; vistrel_udalsya[1][1]=j;
						a[i][j].kub=2; b[i][j].kub=3;  proverka_na_podbitie(player1,i,j);
						return 2;
					}
					else if(a[i][j].kub==0&&b[i][j].kub==0)
					{
						b[i][j].kub=2;return 1;
					}
				}
			}
			else if(b[i-1][j].kub==3||b[i][j+1].kub==3) 
			{
				if(vistrel_udalsya[1][0]==-1)
				{
					vistrel_udalsya[0][0]=-1;return 0;
				}
				else 
				{
					vistrel_udalsya[1][0]=-1;return 0;
				}
			}
			else 
			{
				vistrel_udalsya[0][0]=-1;return 0;
			}
		}
		else 
		{
			vistrel_udalsya[0][0]=-1;return 0;
		}
	}
	else if(j==0&&i>0&&i<9)//Левый центр------------------------------------------------------------
	{
		if((b[i+1][j].kub==3&&b[i-1][j].kub==3)||(b[i+1][j].kub==3&&b[i-1][j].kub==2)||(b[i+1][j].kub==2&&b[i-1][j].kub==3))
		{
			vistrel_udalsya[0][0]=-1;return 0;	
		}
		else if(b[i][j+1].kub==3&&vistrel_udalsya[1][0]==-1)
		{
			vistrel_udalsya[0][0]=-1;return 0;	
		}
		else if(b[i][j+1].kub==3)
		{
			vistrel_udalsya[1][0]=-1;return 0;	
		}
		if(b[i+1][j].kub!=2||b[i][j+1].kub!=2||b[i-1][j].kub!=2)
		{
			if(b[i][j+1].kub==2)
			{
				if(b[i+1][j].kub==3&&(b[i-1][j].kub==1||b[i-1][j].kub==0)||b[i-1][j].kub==3&&(b[i+1][j].kub==0||b[i+1][j].kub==1))
				{
						if(b[i+1][j].kub==3) i--;
						else i++;
						if(a[i][j].kub==1)
						{
							vistrel_udalsya[1][0]=i; vistrel_udalsya[1][1]=j;
							a[i][j].kub=2; b[i][j].kub=3;  proverka_na_podbitie(player1,i,j);
							return 2;
						}
						else if(a[i][j].kub==0&&b[i][j].kub==0)
						{
							vistrel_udalsya[1][0]=-1;
							b[i][j].kub=2;return 1;
						}
				}
				else
				{
					temp_i=i;temp_j=j;
					while(1)
					{
						shot=rand()%2;
						if(shot==0) i++;
						else if(shot==1) i--;
						if(a[i][j].kub==1)
						{
							vistrel_udalsya[1][0]=i; vistrel_udalsya[1][1]=j;
							a[i][j].kub=2; b[i][j].kub=3;  proverka_na_podbitie(player1,i,j);
							return 2;
						}
						else if(a[i][j].kub==0&&b[i][j].kub==0)
						{
							vistrel_udalsya[1][0]=-1;
							b[i][j].kub=2;return 1;
						}
						else 
						{
							i=temp_i;j=temp_j;
						}
					}
				}
			}
			else if(b[i+1][j].kub==3||b[i-1][j].kub==3)
			{
				if(b[i+1][j].kub==3) i--;
				else i++;
				if(a[i][j].kub==1)
				{
					vistrel_udalsya[1][0]=i; vistrel_udalsya[1][1]=j;
					a[i][j].kub=2; b[i][j].kub=3;  proverka_na_podbitie(player1,i,j);
					return 2;
				}
				else if(a[i][j].kub==0&&b[i][j].kub==0)
				{
					vistrel_udalsya[1][0]=-1;
					b[i][j].kub=2;return 1;
				}
			}
			else
			{
				j++;
				if(a[i][j].kub==1)
				{
					vistrel_udalsya[1][0]=i; vistrel_udalsya[1][1]=j;
					a[i][j].kub=2; b[i][j].kub=3;  proverka_na_podbitie(player1,i,j);
					return 2;
				}
				else if(a[i][j].kub==0&&b[i][j].kub==0)
				{
					vistrel_udalsya[1][0]=-1;
					b[i][j].kub=2;return 1;
				}
				else
				{
					vistrel_udalsya[0][0]=-1;
					return 0;
				}
			}
		}
		else
		{
			vistrel_udalsya[0][0]=-1;
			return 0; 
		}
	}
	else return 0;
}
void AI(pole ar[][N]/*pole4 поле показа*/,pole ar2[][N]/*pole1 поле проверки на выигрыш*/,pole bot1[][N])
{
	int i=10,j=10,b=5,c,time=1500;
	char key[3];
	while(1)
	{
		if(time>150) time-=150;
		c=1;
		if(b!=0||b==5){
			gotoxy(0,0); show(ar,0); show(bot1,1);
			for(int i=0;i<N;i++){gotoxy(25,i+1);cout<<" <-";}
			gotoxy(0,13);cout<<"\n\t\t\t\t Ходит ИИ...";Sleep(time);}
		if(vistrel_udalsya[0][0]==-1&&vistrel_udalsya[1][0]==-1)
		{
			i=rand()%10;
			j=rand()%10;
			/*cin>>key;
			koor(key,i,j);*/
			b=shot(ar2,ar,i,j,1,0);
		}
		else if(vistrel_udalsya[1][0]==-1)
			b=popal(ar2,ar,vistrel_udalsya[0][0],vistrel_udalsya[0][1]);
		else
			b=popal(ar2,ar,vistrel_udalsya[1][0],vistrel_udalsya[1][1]);
		c=proverka_na_sost(ar,player1);
		if(c==0)
		{
			vistrel_udalsya[1][0]=-1;vistrel_udalsya[0][0]=-1;
			time=1500;
		}
		else if(b==2) continue;
		else if(b==1) break;
		else if(b==3) break;
		if(!winer(ar2)) break;
	}
	gotoxy(0,12);cout<<"								           			                             	\n								           			                             	";
}
void show_korabli(korabli &player,korabli &player2,int b=0)
{
	gotoxy(56,0);cout<<"P1";gotoxy(62,0);b>0?cout<<"P2":cout<<"AI";
	gotoxy(56,2);cout<<player.four<<" ";SetColor(0,6);cout<<"XXXX";SetColor(7,0);cout<<" "<<player2.four;
	gotoxy(56,4);cout<<player.three<<"  ";SetColor(0,6);cout<<"XXX";SetColor(7,0);cout<<" "<<player2.three;
	gotoxy(56,6);cout<<player.two<<"   ";SetColor(0,6);cout<<"XX";SetColor(7,0);cout<<" "<<player2.two;
	gotoxy(56,8);cout<<player.one<<"    ";SetColor(0,6);cout<<"X";SetColor(7,0);cout<<" "<<player2.one;
}
void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand((unsigned)time(NULL));
	setlocale(LC_ALL,"");
	pole pole1[N][N],pole2[N][N],pole3[N][N],pole4[N][N];
	char key[3];
	int x,i,j,b=0;
	vistrel_udalsya[0][0]=-1;
	vistrel_udalsya[1][0]=-1;
	do
	{
		for(int i=0;i<N;i++)
				for(int j=0;j<N;j++){
				pole1[i][j].kub=0;pole2[i][j].kub=0;pole3[i][j].kub=0;pole4[i][j].kub=0;}
		player1.four=1;player2.four=1;
		player1.three=2;player2.three=2;
		player1.two=3;player2.two=3;
		player1.one=4;player2.one=4;
		while(1)
		{
		CLR
		cout<<"-------------------------------------------------------------------\n";
		cout<<" 1.Играть с ИИ.\t\t\t \n";
		cout<<"-------------------------------------------------------------------\n";
		cout<<" 2.Играть с другом.\n";
		cout<<"-------------------------------------------------------------------\n";
		cout<<" 3.Выход.\n";
		cout<<"-------------------------------------------------------------------\n";
		x=_getch();
		if(x==49){ x=1;break;}
		else if(x==50){x=2;break;}
		else if(x==51){x=3;break;}		
		}
		switch(x)
		{
		case 1:									//Игра с ИИ
			autoput(pole2,&player2);
			CLR
			while(1){
			CLR
			cout<<"-------------------------------------------------------------------\n";
			cout<<" 1.Установить корабли автоматически.\n";
			cout<<"-------------------------------------------------------------------\n";
			cout<<" 2.Установить корабли вручную.\n";
			cout<<"-------------------------------------------------------------------\n";
			x=_getch();
			if(x==49){ x=1;break;}
			else if(x==50){x=2;break;}
			}
			switch(x)
			{
			case 1:
				CLR
				while(1)
				{
					autoput(pole1,&player1);
					show(pole1,0);
					cout<<"\n Чтобы подтвердить нажмите Enter\n\n Чтобы сменить нажмите любую клавишу";
					if(_getch()==13) break;
					else
					{
						for(int i=0;i<N;i++)
							for(int j=0;j<N;j++)
								pole1[i][j].kub=0;
						player1.four=1;player1.three=2;player1.two=3;player1.one=4;
						gotoxy(0,0);
					}
				}
			case 2:
				CLR
				while(player1.one>0||player1.two>0||player1.three>0||player1.four>0)
				{
					gotoxy(0,0);
					show(pole1,0);
					handput(pole1);CLR
				}
			}
			for(int i=0;i<N;i++)
				for(int j=0;j<N;j++)
					pole4[i][j]=pole1[i][j];
			player1.four=1;player2.four=1;
			player1.three=2;player2.three=2;
			player1.two=3;player2.two=3;
			player1.one=4;player2.one=4;
			CLR
			while(x)
			{
				while(1)
				{
					i=10,j=10;
					gotoxy(0,0);
					proverka_na_sost(pole3,player2);
					show(pole4,0);show(pole3,1);
					show_korabli(player1,player2);
					for(int i=0;i<N;i++){gotoxy(25,i+1);cout<<"-> ";}
					gotoxy(0,13);cout<<"\nВведите координату: ";
					cin>>key;					
					gotoxy(0,12);cout<<"					                                                	\n								           			                             	";
					koor(key,i,j);
					if(i<10&&i>=0&&j<10&&j>=0) b=shot(pole2,pole3,i,j,0,1);
					else 
					{
						gotoxy(0,14);cout<<"Ошибка координат\n";Sleep(1500);CLR continue;
					}
					if(!b) 
					{
						gotoxy(0,14);cout<<"Введите координату, куда вы не стреляли\n";Sleep(1500);CLR continue;
					}
					break;
				}
				if(!(x=winer(pole2))) 
				{
					gotoxy(0,0);
					proverka_na_sost(pole3,player2);
					show(pole4,0);show(pole3,1);	
					show_korabli(player1,player2);
					gotoxy(0,13);cout<<"Вы выиграли\n";_getch();break;
				}				
				if(b!=2) AI(pole4,pole1,pole3);	
				if(!(x=winer(pole1)))
				{
					for(int i=0;i<N;i++)
						for(int j=0;j<N;j++)
						{
							if(pole2[i][j].kub==1)
								pole3[i][j].kub=1;
						}	
					gotoxy(0,0);
					show(pole4,0);show(pole3,1);
					show_korabli(player1,player2);
					gotoxy(0,13);cout<<"Выиграл ИИ\n";_getch();break;

				}
			}break;
		case 2:								//Игра на двоих
			CLR		
			char player_name1[15],player_name2[15];
			cout<<"-------------------------------------------------------------------\n";
			cout<<" Введите имя игрока 1 :\n";
			cout<<"-------------------------------------------------------------------\n";
			gotoxy(23,1);cin.getline(player_name1,20);CLR
			cout<<"-------------------------------------------------------------------\n";
			cout<<" Введите имя игрока 2 :\n";
			cout<<"-------------------------------------------------------------------\n";
			gotoxy(23,1);cin.getline(player_name2,20);CLR
			autoput(pole1,&player1);
			autoput(pole2,&player2);
			player1.four=1;player2.four=1;
			player1.three=2;player2.three=2;
			player1.two=3;player2.two=3;
			player1.one=4;player2.one=4;
			x=1;
			while(x)
			{
				while(1)
				{
					while(1)			//Ходит игрок1
					{
						i=10,j=10;
						gotoxy(0,0);
						proverka_na_sost(pole3,player2);
						show(pole4,0);show(pole3,1);
						for(int i=0;i<N;i++){gotoxy(25,i+1);cout<<"-> ";}
						gotoxy(3,11);cout<<player_name1;
						gotoxy(33,11);cout<<player_name2<<endl;
						show_korabli(player1,player2,1);
						gotoxy(0,12);cout<<"\nВведите координату: ";
						cin>>key;
						gotoxy(0,13);cout<<"											                	";
						koor(key,i,j);
						if(i<10&&i>=0&&j<10&&j>=0) b=shot(pole2,pole3,i,j,0,1);
						else 
						{
							gotoxy(0,13);cout<<"Ошибка координат";Sleep(1500);CLR continue;
						}
						if(!b) 
						{
							gotoxy(0,13);cout<<"Введите координату, куда вы не стреляли";Sleep(1500);CLR continue;
						}
						if(!winer(pole2)) x=0;
						break;
					}
					if(x==0) break;
					if(b!=2) break;
				}
				if(!x)
				{
					for(int i=0;i<N;i++)
						for(int j=0;j<N;j++)
						{
							if(pole1[i][j].kub==1)
								pole4[i][j].kub=1;
						}	
					gotoxy(0,0);
					proverka_na_sost(pole3,player2);
					show(pole4,0);show(pole3,1);	
					show_korabli(player1,player2,1);
					gotoxy(3,11);cout<<player_name1;gotoxy(33,11);cout<<player_name2<<endl;
					cout<<"   Выиграл "<<player_name1<<"!!!"<<endl;_getch();break;
				}
				while(1)//Ходит игрок2
				{
					while(1)
					{
						i=10,j=10;
						gotoxy(0,0);
						proverka_na_sost(pole4,player1);
						show(pole4,0);show(pole3,1);
						for(int i=0;i<N;i++){gotoxy(25,i+1);cout<<" <-";}
						gotoxy(3,11);cout<<player_name1;
						gotoxy(33,11);cout<<player_name2<<endl;
						show_korabli(player1,player2,1);
						gotoxy(0,12);cout<<"\nВведите координату: ";
						cin>>key;
						gotoxy(0,13);cout<<"											                	";
						koor(key,i,j);
						if(i<10&&i>=0&&j<10&&j>=0) b=shot(pole1,pole4,i,j,0,0);
						else 
						{
							gotoxy(0,13);cout<<"Ошибка координат";Sleep(1500);CLR continue;
						}
						if(!b) 
						{
							gotoxy(0,13);cout<<"Введите координату, куда вы не стреляли";Sleep(1500);CLR continue;
						}
						if(!winer(pole1)) x=0;
						break;
					}
					if(x==0) break;
					if(b!=2) break;
				}
				if(!x)
				{
					for(int i=0;i<N;i++)
						for(int j=0;j<N;j++)
						{
							if(pole1[i][j].kub==1)
								pole3[i][j].kub=1;
						}		
					gotoxy(0,0);
					proverka_na_sost(pole4,player2);
					show(pole4,0);show(pole3,1);
					show_korabli(player1,player2,1);
					gotoxy(3,11);cout<<player_name1;gotoxy(33,11);cout<<player_name2<<endl;
					cout<<"\t\t Выиграл "<<player_name2<<"!!!"<<endl;_getch();break;
				}
			}CLR break;
		case 3:break;				
		}
	}while(x!=3);
}