#include<iostream>
#include<stdio.h>
using namespace std;
void board();
int win();
void playGame();
char block[]= {'0','1','2','3','4','5','6','7','8','9'};
char sym1,sym2;             /*To decide the symbol of the player*/
int flag=0;

int  main()
{
        char sym1,sym2;
		int flag=0;
		cout<<"Tic Toe Game "<<endl;
		cout<<endl;
		cout<<"2019  \u00a9"<<"| Tic Tac Toe  |   Abhinav Singh"<<endl;
		cout<<endl;
        if(getchar())
        {
            system("cls");
        }
		playGame();
        return 0;
}
void printMenu()
{

}
/*To start game*/
void playGame()
{
    do
    {
		cout<<"Player 1 enter your symbol"<<endl;
		char ch;
		cin>>ch;
		if(ch=='X'||ch=='x')
		{
		    sym1='X';
		    sym2='O';
            cout<<"Player 1 Symbol-X    Player 2 Symbol-O"<<endl;
		}
		else if(ch=='O'||ch=='o')
		{
		    sym1='O';
		    sym2='X';
            cout<<"Player 1-O    Player 2-X"<<endl;
		}
		else
		{
			cout<<"Wrong choice!!"<<endl;
			cout<<endl;
			flag=1;
		}
    }
    while(flag==1);
    int player=1,ptr=0,move,i;
    char sym;
    cout<<endl;
    board();
    do
    {
        if(ptr%2==0)
            player=1;
        else
            player=2;
        if(player==1)
            sym=sym1;
        if(player==2)
            sym=sym2;
        cout<<"Player "  <<player<< " enter block number"<<endl;
        cin>>move;
        ptr++;
        if(move==1 && block[1]=='1')
            block[1]=sym;
        else if(move==2 && block[2]=='2')
            block[2]=sym;
        else if(move==3 && block[3]=='3')
            block[3]=sym;
        else if(move==4 && block[4]=='4')
            block[4]=sym;
        else if(move==5 && block[5]=='5')
            block[5]=sym;
        else if(move==6 && block[6]=='6')
            block[6]=sym;
        else if(move==7 && block[7]=='7')
            block[7]=sym;
        else if(move==8 && block[8]=='8')
            block[8]=sym;
        else if(move==9 && block[9]=='9')
            block[9]=sym;
        else
        {
            cout<<"Wrong move"<<endl;
            ptr--;
        }
        i=win();
        system("cls");
        board();
    }while(i==0);

if(i==1)
    cout<<"Player " << player <<" win"<<endl;
if(i==-1)
    cout<<endl<<"Game Draw"<<endl;

}

/*To calculate which player win*/
int win()
{
    if(block[1]==block[2]&&block[2]==block[3])
        return 1;
    else if(block[4]==block[5]&&block[5]==block[6])
        return 1;
    else if(block[7]==block[8]&&block[8]==block[9])
        return 1;
    else if(block[1]==block[4]&&block[4]==block[7])
        return 1;
    else if(block[2]==block[5]&&block[5]==block[8])
        return 1;
    else if(block[3]==block[6]&&block[6]==block[9])
        return 1;
    else if(block[1]==block[5]&&block[5]==block[9])
        return 1;
    else if(block[3]==block[5]&&block[5]==block[7])
        return 1;
    else if(block[1]!='1' && block[2]!='2' && block[3]!='3' && block[4]!='4' && block[5]!='5' && block[6]!='6' && block[7]!='7' && block[8]!='8' && block[9]!='9')
        return -1;
    else
        return 0;
}

/*To Print Board*/
void board()
{
    int k=0;
    for(int i=1;i<=9;i++)
    {
        for(int j=1;j<=11;j++)
        {
            if((i==2||i==5||i==8)&&(j==2||j==6||j==10))
            {
                cout<<block[++k];
            }
            else
            {
                if(i==3||i==6)
                {
                    if(j==4||j==8)
                    {
                        cout<<"|";
                    }
                    else
                    {
                        cout<<"_";
                    }
                }
                else
                {
                    if(j==4||j==8)
                    {
                        cout<<"|";
                    }
                    else
                    {
                        cout<<" ";
                    }
                }
            }
        }
        cout<<"\n";
    }
    cout<<endl;
}


