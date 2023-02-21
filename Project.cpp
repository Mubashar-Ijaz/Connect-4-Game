#include<iostream>
#include<cstdlib>
#include<string>
#include<Windows.h>
#include<stdlib.h>
using namespace std;


int arr[7][6];
int choice, player;
bool finish = false;
int a = 0;
int count1 = 0;
int count2 = 0;

// Fuction prototypes
void check(int x);             //This fuction checks whether a player overwrite the same operation or not.
void draw_match();             //This fuction checks whether a match is a draw or not
void win_checker(string p1, string p2);           // This fuction checks which player is a winner
void player_choice(string p1, string p2);        //This fuction is mafe for the choice of the player for its throw

int main()
{
    string p1, p2;
    system("CLS");
    cout << "\n\t\t\t\t\t\tWELCOME TO CONNECT 4 GAME" << endl;
    cout<<"\t\t\t\t\t\t=========================";
    cout << "\nEnter Player 1 Name = ";
    getline(cin, p1);
    cout << "\nEnter Player 2 Name = ";
    getline(cin, p2);
    Sleep(1);
    draw_match();
    player_choice(p1, p2);
    cout << "\nTotal No of Turns of " << p1 << " = " << count1 << endl;
    cout << "\nTotal No of Turns of " << p2 << " = " << count2 << endl<<endl;
    cout<<"\t\t\t\t\t\tGAME OVER\n";
    system("pause");
    return 0;
}

void draw_match()  //This fuction checks whether a match is a draw or not
{
    system("CLS");
    for (int i = 0; i < 9; i++)
    {
        if (i < 2)
        {
            cout << "-";
        }
        else if (i > 7)
        {
            cout << i - 1 << "--" << endl;
        }
        else {
            cout << i - 1 << "----";
        }
    }
    for (int i = 5; i >= 0; i--)
    {
        for (int j = 0; j < 7; j++)
        {
            if (arr[j][i] != 0)
            {
                if (arr[j][i] == 1)
                {
                    cout << "| R |";

                }
                else
                {
                    cout << "| B |";

                }
            }

            else cout << "|   |";
        } cout << endl;
    }
    for (int i = 0; i < 35; i++)
    {
        cout << "=";
    } cout << endl;
}


void player_choice(string p1, string p2)   // This fuction is mafe for the choice of the player for its throw
{
    player = 1;
    while (finish != true)
    {
        if (player == 1)
        {
            cout << endl << p1 << "'s Turn: ";
            count1++;
        }
        else
        {
            cout << endl << p2 << "'s Turn:  ";
            count2++;
        }
        cin >> choice;
        if (choice > 0 && choice < 8)
        {
            check(choice);
            draw_match();
            if (player == 1)
            {
                player++;
            }
            else
            {
                player--;
            }
        }
        else
        {
            cout << "WRONG CHOICE!" << endl;
        }
        win_checker(p1, p2);
    }
}

void check(int x) //This fuction checks whether a player overwrite the same operation or not.
{
    if (arr[x - 1][a] != 0 && a < 6)
    {
        a++;
        check(x);
    }
    else if (player == 1 && a < 6)
    {
        arr[x - 1][a] = 1;
        a = 0;
    }
    else if (player == 2 && a < 6)
    {
        arr[x - 1][a] = 2;
        a = 0;
    }
    else
    {
        cout << "WRONG!" << endl;
        a = 0;
        player++;
    }
}

void win_checker(string p1, string p2)   // This fuction checks which player is a winner
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (arr[j][i] == 1 && arr[j + 1][i + 1] == 1 && arr[j + 2][i + 2] == 1 && arr[j + 3][i + 3] == 1)
            {
                finish = true;
                cout << "\n*******  Congratulations  ******* \n";
                cout << p1 << " WINS!\n" << endl;
            }
            else if (arr[j][i] == 1 && arr[j + 1][i - 1] == 1 && arr[j + 2][i - 2] == 1 && arr[j + 3][i - 3] == 1)
            {
                cout << "\n*******  Congratulations  ******* \n";
                cout << p1 << " WINS!\n" << endl;
                finish = true;
            }
            else if (arr[j][i] == 2 && arr[j + 1][i - 1] == 2 && arr[j + 2][i - 2] == 2 && arr[j + 3][i - 3] == 2)
            {
                cout << "\n*******  Congratulations  ******* \n";
                cout << p2 << " WINS!\n" << endl;
                finish = true;
            }
            else if (arr[j][i] == 2 && arr[j - 1][i - 1] == 2 && arr[j - 2][i - 2] == 2 && arr[j - 3][i - 3] == 2)
            {
                finish = true;
                cout << "\n*******  Congratulations  ******* \n";
                cout << p2 << " WINS!\n" << endl;
            }
            else if (arr[j][i] == 1 && arr[j][i - 1] == 1 && arr[j][i - 2] == 1 && arr[j][i - 3] == 1)
            {
                cout << "\n*******  Congratulations  ******* \n";
                cout << p1 << " WINS!\n" << endl;
                finish = true;
            }
            else if (arr[j][i] == 1 && arr[j - 1][i] == 1 && arr[j - 2][i] == 1 && arr[j - 3][i] == 1)
            {
                cout << "\n*******  Congratulations  ******* \n";
                cout << p1 << " WINS!\n" << endl;
                finish = true;
            }
            else if (arr[j][i] == 2 && arr[j][i - 1] == 2 && arr[j][i - 2] == 2 && arr[j][i - 3] == 2)
            {
                cout << "\n*******  Congratulations  ******* \n";
                cout << p2 << " WINS!\n" << endl;
                finish = true;
            }
            else if (arr[j][i] == 2 && arr[j - 1][i] == 2 && arr[j - 2][i] == 2 && arr[j - 3][i] == 2)
            {
                cout << "\n*******  Congratulations  ******* \n";
                cout << p2 << " WINS!\n" << endl;
                finish = true;
            }
        }
    }
}