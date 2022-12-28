#include <iostream>
#include <vector>
using namespace std;

void greet(){
    cout<<"\n";
    cout<<"\n";
    cout<<"                      ===================\n";
    cout<<"                          TIC-TAC-TOE\n";
    cout<<"                      ===================\n";
    cout<<"\n";
    cout<<"\n";
    cout<<"             .--\n";
    cout<<"       ==-   .\\#\\\n";
    cout<<"          ,-._\\ \\=- .\n";
    cout<<"          |#___\"\\ \\_);\n";
    cout<<"   =--      '  \\\\#\\\n";
    cout<<"      ==--      \\`--'\n";
    cout<<"                 \"\"         .--\n";
    cout<<"                     ==--   .\\#\\\n";
    cout<<"                         ,-._\\ \\=- .               )\n";
    cout<<"                  ==-    |#___\"\\ \\_);              (\n";
    cout<<"                           '  \\\\#\\                 ))\n";
    cout<<"                        ==-    \\`--'               ((\n";
    cout<<"                                \"\"                  ))\n";
    cout<<"      ______________                __              (  __\n";
    cout<<"    ,'              `.            ('__`>           , ) __`.\n";
    cout<<"   /                  \\____       /==(^)     ______ ( -'_--`.\n";
    cout<<"  |   Let's play        ,-'        `\\_-/    |()|::::)= '_`.  .\n";
    cout<<"  |      TIC-TAC-TOE!  |     _____ / /\\  /)____||____\\_-``.\n";
    cout<<"  |   Woot! Woot!      |          `-------'            \\-`   ,\n";
    cout<<"   \\                  /      &  ,   .  &  ,   .  &  ,   | '\n";
    cout<<"    `.______________,'       _\'     `/_\'     `/_\'    |\n";
    cout<<"                             _|`.   ,'|_|`.   ,'|_|`.   |\n";
    cout<<"                                                        |\\\n";
    cout<<"                             __________________________/__\\\n";
    cout<<"                                                     .`.-_-\\\n";
    cout<<"                                                    `_`.'_-_\\\n";
    cout<<"                                                       -- -\n";
    cout<<"\n";
    cout<<"\n";
    cout<<"Instructions: Pick the number of the position you want to place\nyour mark.\n";
    cout<<"\n";
    cout<<"\n";
}

// Construct grid/board ------------
string grid = "         ";


// Dispay grid to terminal ---------
string board_contents;
void show_grid(){
    string round_contents;

    cout<<"    Play:                   Reference:\n\n    ";    
    for (int i=0; i<9; i++){
        round_contents += ' ';
        !grid[i] ? round_contents.push_back(' ') : round_contents.push_back(grid[i]);
        round_contents += ' ';
        if ((i+1)%3!=0) {
            round_contents += '|';
        } else if (i==2 || i==5) {
            round_contents += "              ";
            round_contents += i+47;
            round_contents += " | ";
            round_contents += i+48;
            round_contents += " | ";
            round_contents += i+49;
            round_contents += "\n    ===========             ===========\n    ";
        };
    } 
            round_contents += "              ";
            round_contents += '7';
            round_contents += " | ";
            round_contents += '8';
            round_contents += " | ";
            round_contents += '9';
    
    board_contents = round_contents;
    cout<<board_contents<<"\n\n";
}


// Check grid if filled ------------
bool is_filled = false;
void check_filled(){
    grid[0]!=' ' && grid[1]!=' ' && grid[2]!=' ' && grid[3]!=' ' && grid[4]!=' ' && grid[5]!=' ' && grid[6]!=' ' && grid[7]!=' ' && grid[8]!=' ' ? is_filled=true : is_filled=false;
}


// Determine winner ----------------
string winner;
bool has_winner = false;
void check_winner(){
    if (grid[0]==grid[3] && grid[3]==grid[6] && grid[0] != ' '){
        grid[0]=='X' ? winner='X' : winner = 'O';
        has_winner = true;
    } else if (grid[1]==grid[4] && grid[4]==grid[7] && grid[1] != ' '){
        grid[1]=='X' ? winner='X' : winner = 'O';
        has_winner = true;
    } else if (grid[2]==grid[5] && grid[5]==grid[8] && grid[2] != ' '){
        grid[2]=='X' ? winner='X' : winner = 'O';
        has_winner = true;
    } else if (grid[0]==grid[1] && grid[1]==grid[2] && grid[0] != ' '){
        grid[0]=='X' ? winner='X' : winner = 'O';
        has_winner = true;
    } else if (grid[3]==grid[4] && grid[4]==grid[5] && grid[3] != ' '){
        grid[2]=='X' ? winner='X' : winner = 'O';
        has_winner = true;
    } else if (grid[6]==grid[7] && grid[7]==grid[8] && grid[6] != ' '){
        grid[6]=='X' ? winner='X' : winner = 'O';
        has_winner = true;
    } else if (grid[0]==grid[4] && grid[4]==grid[8] && grid[0] != ' '){
        grid[0]=='X' ? winner='X' : winner = 'O';
        has_winner = true;
    } else if (grid[2]==grid[4] && grid[4]==grid[6] && grid[2] != ' '){
        grid[2]=='X' ? winner='X' : winner = 'O';
        has_winner = true;
    }
}


// Take Turn -----------------------
int boxes_filled=0, turn=0;
void take_turn(){
    int current_boxes_filled=boxes_filled;
    if (turn==0){
        while (current_boxes_filled==boxes_filled){   
            cout<<"Pick a box to mark X: ";
            int box;
            cin>>box;
            box--;

            if (grid[box]=='X'||grid[box]=='O'){
                cout<<"\nOops! That box has already been filled or you inputed the wrong character. Please try again.\n\n";
            } else {
                grid[box]='X';
                current_boxes_filled++;
            }

        }
        boxes_filled++;
        turn=1;
    } else {
        while (current_boxes_filled==boxes_filled){   
            cout<<"Pick a box to mark O: ";
            int box;
            cin>>box;
            box--;

            if (grid[box]=='X'||grid[box]=='O'){
                cout<<"\nOops! That box has already been filled or you inputed the wrong character. Please try again.\n\n";
            } else {
                grid[box]='O';
                current_boxes_filled++;
            }
        }
        boxes_filled++;
        turn=0;
    }
    cout<<"\n";
}


// Choose game mode ----------------
int mode = 0, player_1, player_2, round=1;
void choose_game_mode(){
    cout<<"Select mode:\n";
    cout<<"(1) Sudden Death\n";
    cout<<"(3) Best of 3\n";
    cout<<"(5) Best of 5\n";
    while (mode == 0) {
        int selection;
        cout<<"Mode: ";
        cin>>selection;
        if (selection==1 || selection==3 || selection==5){
            mode=selection;
        } else {
            cout<<"\nPlease choose between 1, 3 and 5.\n";
        }
    }
    cout<<"\n";
}


// Run Game ------------------------
void play(){
    show_grid();
    while (has_winner==false && is_filled==false) {
        take_turn();
        show_grid();
        check_winner();
        check_filled();
    }

    if (winner=="X"){
        cout<<"Player 1 won the match!\n\n";
        player_1++;
    } else if (winner=="O"){
        cout<<"Player 1 won the match!\n\n";
        player_2++;
    } else {
        cout<<"We have a tie!\n\n";
    }
}

void reset_game(){
    grid="         ";
    board_contents="";
    has_winner=false;
    is_filled=false;
    boxes_filled=0;
    turn=0;
    winner="";
}

void best_of_3(){
    while(round<3 && player_1<2 && player_2<2){
        round++;
        cout<<"Best of Three Score: "<<player_1<<":"<<player_2<<"\n\n"<<"Round "<<round<<" of 3\n\n";
        reset_game();
        play();
    }
    
    if (player_1>player_2){
        cout<<"Player 1 won the Best of Three game!\n";
    } else if (player_2>player_1){
        cout<<"Player 2 won the Best of Three game!\n";
    } else {
        cout<<"We have a tied game.\n";
    }
}

void best_of_5(){
    while(round<6 && player_1<3 && player_2<3){
        round++;
        cout<<"Best of Five Score: "<<player_1<<":"<<player_2<<"\n\n"<<"Round "<<round<<" of 5\n\n";
        reset_game();
        play();
    }

    if (player_1>player_2){
        cout<<"Player 1 won the Best of Five game!\n";
    } else if (player_2>player_1){
        cout<<"Player 2 won the Best of Five game!\n";
    } else {
        cout<<"We have a tied game.\n";
    }
}

void check_mode(){
    switch(mode){
        case 1:
            break;
        case 3:
            best_of_3();
            break;
        case 5:
            best_of_5();
            break;
    }
}


// Show credits --------------------
void show_credits(){
    cout<< "===================================\n";
    cout<< "\n";
    cout<<"QMMNmdyo+:.    /hNMMMMMMMMMMMh\n";
    cout<<"MMMMMMMMMMmho-   -odMMMMMMMMMM\n";
    cout<<"MMMMMMMMMMMMMMmo.  `-yMMMMMMMy\n";
    cout<<"MMMMMMMMMMMMMMMMNh:   -hMMMMMy\n";
    cout<<"-/+MMMMMMMMMMMMMMMNh:  `+NMMMd\n";
    cout<<"    -/+oyhmMMMMMMMMMNy.  .hMMm\n";
    cout<<"Dbn-     `ohNMMMMMMMMMm/  `oMM\n";
    cout<<"MMNNddo.   -odMMMMMMMMMNs`  om\n";
    cout<<"MMMMNNmy+-  `:dMMMMMMMMMMs   .\n";
    cout<<"NMMMMMMMNy.   `sMMMMMMMMMMM+  \n";
    cout<<"mMMMMMMMMMMN+   +MMMMMMMMMMN- \n";
    cout<<"MMMMMMMMMMMMMo   +MMMMMMMMMMm`\n";
    cout<<"MMMMMMMMMMMMMM/   dMMMMMMMMMM:\n";
    cout<<"NMMMMMMMMMMMMMm   -MMMMMMMMMMs\n";
    cout<<"yNNNNMMMMMNMMNh`   sNNNNNNNNNo\n";
    cout<< "\n";
    cout<< "Program created by Daniel Labrador.\n";
    cout<< "https://github.com/daniellabrador/codecademy-cpp-tic_tac_toe.git\n";
}