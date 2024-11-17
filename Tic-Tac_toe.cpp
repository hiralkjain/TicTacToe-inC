#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void Display();
int Result();

char board[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

int main() {
    int player = 1, input, status = -1;
    int opt,r;
    cout<<"Enter 1 to play with computer and 2 to play with friend\n";
    cin>>opt;
   
    Display();
 switch(opt)
    {
        case 1:
    while (status == -1) {
        player = (player % 2 == 0) ? 2 : 1;
        char mark = (player == 1) ? 'X' : 'O';
        if(player==1)
        {
        cout << "Please enter Number For Player " << player << endl;
        cin >> input;
        }
        else
        {
          std::srand(std::time(0));
           r = std::rand() % 9 + 1;
          input=r;
        }
        if (input < 1 || input > 9) {
            cout << "Invalid input\n";
            continue;
        }
        
        if (board[input] == 'X' || board[input] == 'O') {
            cout << "Already taken. Please choose a different spot.\n";
            continue;
        }

        board[input] = mark;
        Display();

        int result = Result();

        if (result == 1) {
            cout << "Player " << player << " is the Winner" << endl;
            return 0;
        } else if (result == 0) {
            cout << "Draw" << endl;
            return 0;
        }

        player++;
    }
       break;
        case 2:
         Display();

    while (status == -1) {
        player = (player % 2 == 0) ? 2 : 1;
        char mark = (player == 1) ? 'X' : 'O';
        cout << "Please enter Number For Player " << player << endl;
        cin >> input;
        if (input < 1 || input > 9) {
            cout << "Invalid input\n";
            continue;
        }
        
        if (board[input] == 'X' || board[input] == 'O') {
            cout << "Already taken. Please choose a different spot.\n";
            continue;
        }

        board[input] = mark;
        Display();

        int result = Result();

        if (result == 1) {
            cout << "Player " << player << " is the Winner" << endl;
            return 0;
        } else if (result == 0) {
            cout << "Draw" << endl;
            return 0;
        }

        player++;
    }
    break;

    return 0;
}
}

void Display() {
    system("cls");
    cout << "\n\n";
    cout << "=== TIC TAC TOE ===\n\n";
    cout << "     |     |     \n";
    cout << "  " << board[1] << "  |  " << board[2] << "  |  " << board[3] << "  \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[4] << "  |  " << board[5] << "  |  " << board[6] << "  \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[7] << "  |  " << board[8] << "  |  " << board[9] << "  \n";
    cout << "     |     |     \n";
    cout << "\n\n";
}

int Result() {
    if (board[1] == board[2] && board[2] == board[3]) {
        return 1;
    }
    if (board[1] == board[4] && board[4] == board[7]) {
        return 1;
    }
    if (board[7] == board[8] && board[8] == board[9]) {
        return 1;
    }
    if (board[3] == board[6] && board[6] == board[9]) {
        return 1;
    }
    if (board[1] == board[5] && board[5] == board[9]) {
        return 1;
    }
    if (board[3] == board[5] && board[5] == board[7]) {
        return 1;
    }
    if (board[2] == board[5] && board[5] == board[8]) {
        return 1;
    }
    if (board[4] == board[5] && board[5] == board[6]) {
        return 1;
    }

    int count = 0;
    for (int i = 1; i <= 9; i++) {
        if (board[i] == 'X' || board[i] == 'O') {
            count++;
        }
    }
    
    if (count == 9) {
        return 0;
    }
    return -1;
}

