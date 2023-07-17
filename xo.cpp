#include<bits/stdc++.h>
using namespace std;
char box[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int row,col=0;
char turn='X';
bool draw=false;
void display(string s,string x)
{
   cout<<"\n\t\t\t\t\t\t"<<s<<" Vs "<<x<<endl;
   cout<<"\t\t\t\t\t\t"<<" ___________________\n";
   cout<<"\t\t\t\t\t\t"<<"|      |      |     |\n";
   cout<<"\t\t\t\t\t\t"<<"|  "<<box[0][0]<<"   |   "<<box[0][1]<<"  |  "<<box[0][2]<<"  |\n";   //displaying box
   cout<<"\t\t\t\t\t\t"<<"|______|______|_____|\n";
   cout<<"\t\t\t\t\t\t"<<"|      |      |     |\n";
   cout<<"\t\t\t\t\t\t"<<"|  "<<box[1][0]<<"   |   "<<box[1][1]<<"  |  "<<box[1][2]<<"  |\n";
   cout<<"\t\t\t\t\t\t"<<"|______|______|_____|\n";
   cout<<"\t\t\t\t\t\t"<<"|      |      |     |\n";
   cout<<"\t\t\t\t\t\t"<<"|  "<<box[2][0]<<"   |   "<<box[2][1]<<"  |  "<<box[2][2]<<"  |\n";
   cout<<"\t\t\t\t\t\t"<<"|______|______|_____|\n";
}
bool finish()
{
    for(int row=0;row<3;row++)
    {
        if(box[0][row]==box[1][row] && box[0][row]==box[2][row])     // checking for win
        return false;
        else if(box[row][0]==box[row][1] && box[row][0]==box[row][2])
        return false;
        else if(box[0][0]==box[1][1] && box[0][0]==box[2][2])
        return false;
        else if(box[1][1]==box[0][2] && box[1][1]==box[2][0])
        return false;
    }

    for(int row=0;row<3;row++)
    {
        for(int col=0;col<3;col++) 
        {
            if(box[row][col]!='O' && box[row][col]!='X')             //check for empty space (or) to continue the game
            return true;
        }
    }

    draw=true;                                                    //checking for draw
    return false;
}
void playerfill(string player1,string player2)
{
    if(turn=='X')
    cout<<"\n\n\t\t\t\t\t\t"<<player1<<"'s turn...Enter your choice...\t\t\t\t\t\t"<<endl;
    else if(turn=='O')
    cout<<"\n\n\t\t\t\t\t\t"<<player2<<"'s turn...Enter your choice...\t\t\t\t\t\t"<<endl;
    int choice;
    cin>>choice;
    if(choice>9)
    {
        cout<<"\n\t\t\t\t\t\tInvalid token...Please Re-Enter..."<<endl;
        playerfill(player1,player2);
    }
    switch(choice)
    {
        case 1:row=0;col=0;break;
        case 2:row=0;col=1;break;
        case 3:row=0;col=2;break;
        case 4:row=1;col=0;break;
        case 5:row=1;col=1;break;
        case 6:row=1;col=2;break;
        case 7:row=2;col=0;break;
        case 8:row=2;col=1;break;
        case 9:row=2;col=2;break;
        default:break;
    }
    if(turn=='X' && box[row][col]!='X' && box[row][col]!='O')
    {
        box[row][col]=turn;
        turn='O';
    }
    else if(turn=='O' && box[row][col]!='X' && box[row][col]!='O')
    {
        box[row][col]=turn;
        turn='X';
    }
    else
    {
        cout<<"\n\n\t\t\t\t\t\tBox already filled !....Choose another box.....!"<<endl;
         playerfill(player1,player2);
    }
}
int main()
{
    string player1;
    string player2;
    cout<<"\n\n\t\t\t\t\t\t* * * Welocme to the Game * * *\t\t\t\t\t\t"<<endl;
    cout<<"\n\t\t * * * Player who fill's box with 3 x's or 3 O's a vertically (or) horizontally (or) digonally will win the game * * *"<<endl;
    cout<<endl;
    cout<<"Enter Player1 Name ~"<<endl;
    cin>>player1;
    cout<<"Enter Player2 Name ~"<<endl;
    cin>>player2;
    int check=finish();
    display(player1,player2);
    while(check)
    {

        playerfill(player1,player2);
        display(player1,player2);
        check=finish();
    }
    cout<<endl;
    if(turn=='X' && draw==false)
    cout<<"\t\t Congrats  "<<player2<<"!.You have won the game."<<endl;
    else if(turn=='O' && draw==false)
    cout<<"\t\t Congrats  "<<player1<<"!.You have won the game."<<endl;
    else
    cout<<"\t\t Game ended in draw "<<endl;
}