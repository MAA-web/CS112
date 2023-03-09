#include <iostream>
#include <utility>
#include <windows.h>

using namespace std;

char Board[8][9],Display_Board[8][9] , playerA_sym{'O'}, playerB_sym{'0'};
int kill_count_a{0}, kill_count_b{0};

namespace salted_potato {
    [[nodiscard]] bool pawn_check (string a, char player_sym) {
        string n1, n2;
        n1 = a[0];
        n2 = a[1];
        return (Board[stoi(n2)-1][stoi(n1)-1] == player_sym);
    }
    void inversion(bool *playerA, bool *playerB){
        if(*playerA && !*playerB){
            *playerA = false;
            *playerB = true;
        } else if (*playerB && !*playerA){
            *playerA = true;
            *playerB = false;
        }
    }
}

class Piece {//piece class
    std::string Player;
    char thisPlayer_sym{};
    int LocationX{};
    int LocationY{};
    bool isKing{};

public:

    [[nodiscard]] bool get_Is_King() const { return this->isKing; }
    [[nodiscard]] int getX() const { return this->LocationX; }
    [[nodiscard]] int getY() const { return this->LocationY; }
    [[nodiscard]] string getPlayer() const { return this->Player; }
    void TakeMove(int x , int y){//takes move
        cout<<x<<" "<<y<<endl;
        this->LocationX = x;
        this->LocationY = y;
    }
    void set_king(bool a){//makes king
        cout<<"Pawn at location " <<LocationX + 1 << LocationY + 1 << " Made King!\n";
        this->isKing = a;
    }
    void Seppuku(){//killing function
        cout<<LocationY<<" "<<LocationX;
        this->LocationY = {-1}, this->LocationX = {-1};
        (this->Player == "b") ? kill_count_a++ : kill_count_b++;
    }
	//forward right
    [[nodiscard]] bool specific_ValidMove1() const {return (Board[LocationY - 1][LocationX + 1] == '-' && LocationX != -1 && LocationY != -1);}
	//forward left
    [[nodiscard]] bool specific_ValidMove2() const {return (Board[LocationY - 1][LocationX - 1] == '-' && LocationX != -1 && LocationY != -1);}
	//forward right capturing pawn
    [[nodiscard]] bool specific_ValidMove3() const {
        return (Board[LocationY - 2][LocationX + 2] == '-' && LocationX != 7 && LocationX != -1 && LocationY != -1 &&
        LocationY != 0) && (Board[LocationY - 1][LocationX + 1] != thisPlayer_sym && Board[LocationY - 1][LocationX + 1] != '-');}
	//forward left capturing pawn
    [[nodiscard]] bool specific_ValidMove4() const {
        return ((Board[LocationY - 2][LocationX - 2] == '-' && LocationY != 0 && LocationX != -1 && LocationY != -1 && LocationX != 0)
            && (Board[LocationY - 1][LocationX - 1] != thisPlayer_sym &&
            Board[LocationY - 1][LocationX - 1] != '-'));}
	//Backwards right capturing opponent pawn
    [[nodiscard]] bool specific_ValidMove5() const {
		return ((Board[LocationY + 2][LocationX + 2] == '-' && LocationX != 7 && LocationX != -1 && LocationY != -1 && LocationY != 7 )
        && (Board[LocationY + 1][LocationX + 1] != thisPlayer_sym &&
        Board[LocationY + 1][LocationX + 1] != '-'));}
	//Backwards Left capturing opponent pawn
	[[nodiscard]] bool specific_ValidMove6() const {
        return ((Board[LocationY + 2][LocationX - 2] == '-' && LocationX != -1 && LocationY != -1 && LocationX != 0 && LocationY != 7)
            && (Board[LocationY + 1][LocationX - 1] != thisPlayer_sym &&
            Board[LocationY + 1][LocationX - 1] != '-'));}
	//Backwards right
    [[nodiscard]] bool specific_ValidMove7() const{return (Board[LocationY + 1][LocationX + 1] == '-' && this->getX() != 7 && LocationX != -1 && LocationY != -1); return false;}
	//Backwards left
    [[nodiscard]] bool specific_ValidMove8() const{return (Board[LocationY + 1][LocationX - 1] == '-' && LocationX != -1 && LocationY != -1); return false;}
    //further possible moves
    [[nodiscard]] bool further_moves() const {
        return (((thisPlayer_sym == '0' && LocationX != -1 && LocationY != -1)
            && (specific_ValidMove3() || specific_ValidMove4())
            || (isKing && (specific_ValidMove5() || specific_ValidMove6())))
            ||((thisPlayer_sym == 'O' && LocationX != -1 && LocationY != -1)
            && ((specific_ValidMove5() || specific_ValidMove6()))
            || (isKing && (specific_ValidMove3() || specific_ValidMove4()))));}

    [[nodiscard]] bool ValidMove() const {
        if (this->thisPlayer_sym == '0' && this->getX() != -1 && LocationX != -1 && LocationY != -1) {
            if ((Board[LocationY - 1][LocationX + 1] == '-')
            || (Board[LocationY - 1][LocationX - 1] == '-')
            || (Board[LocationY - 2][LocationX + 2] == '-' && Board[LocationY - 1][LocationX + 1] != thisPlayer_sym && Board[LocationY - 1][LocationX + 1] != '-')
            || (Board[LocationY - 2][LocationX - 2] == '-' && Board[LocationY - 1][LocationX - 1] != thisPlayer_sym && Board[LocationY - 1][LocationX - 1] != '-'))return true;
            if (this->isKing) {
                if ((Board[LocationY + 2][LocationX + 2] == '-' && Board[LocationY + 1][LocationX + 1] != thisPlayer_sym &&
                Board[LocationY + 1][LocationX + 1] != '-')
                || (Board[LocationY + 2][LocationX - 2] == '-' &&Board[LocationY + 1][LocationX - 1] != thisPlayer_sym && Board[LocationY + 1][LocationX - 1] != '-')
                || (Board[LocationY + 1][LocationX + 1] == '-') || (Board[LocationY + 1][LocationX - 1] == '-'))return true;
            }
        }
        if (this->thisPlayer_sym == 'O' && LocationX != -1 && LocationY != -1){
            if ((Board[LocationY + 2][LocationX + 2] == '-' && this->getX() != 7 && Board[LocationY + 1][LocationX + 1] != thisPlayer_sym && Board[LocationY + 1][LocationX + 1] != '-')
            || (Board[LocationY + 2][LocationX - 2] == '-' && Board[LocationY + 1][LocationX - 1] != thisPlayer_sym && Board[LocationY + 1][LocationX - 1] != '-')
            || (Board[LocationY + 1][LocationX + 1] == '-' || Board[LocationY + 1][LocationX - 1] == '-'))return true;
            if(isKing){
                if ((Board[LocationY - 1][LocationX + 1] == '-' || Board[LocationY - 1][LocationX - 1] == '-')
                || (Board[LocationY - 2][LocationX + 2] == '-' && this->getX() != 7 && Board[LocationY - 1][LocationX + 1] != thisPlayer_sym && Board[LocationY - 1][LocationX + 1] != '-')
                || (Board[LocationY - 2][LocationX - 2] == '-' && Board[LocationY - 1][LocationX - 1] != thisPlayer_sym && Board[LocationY - 1][LocationX - 1] != '-'))return true;
            }
        }
        return false;
    }

    void Assignment_func (char symbol, std::string Player_P = "a", int Location_X = -1, int Location_Y = -1){
        this->thisPlayer_sym = symbol;
        this->Player = std::move(Player_P);
        this->LocationY = Location_Y;
        this->LocationX = Location_X;
    }
};

string piece_choice = "00";

int main() {
    HANDLE colour=GetStdHandle(STD_OUTPUT_HANDLE);//setting colour
    Piece pieces[24];
    //                              player a -> O   player b -> 0
    pieces[0].Assignment_func(playerA_sym, "a", 1, 0);
    pieces[1].Assignment_func(playerA_sym, "a", 3, 0);
    pieces[2].Assignment_func(playerA_sym, "a", 5, 0);
    pieces[3].Assignment_func(playerA_sym, "a", 7, 0);
    pieces[4].Assignment_func(playerA_sym, "a", 0, 1);
    pieces[5].Assignment_func(playerA_sym, "a", 2, 1);
    pieces[6].Assignment_func(playerA_sym, "a", 4, 1);
    pieces[7].Assignment_func(playerA_sym, "a", 6, 1);
    pieces[8].Assignment_func(playerA_sym, "a", 1, 2);
    pieces[9].Assignment_func(playerA_sym, "a", 3, 2);
    pieces[10].Assignment_func(playerA_sym, "a", 5, 2);
    pieces[11].Assignment_func(playerA_sym, "a", 7, 2);

    pieces[12].Assignment_func(playerB_sym, "b", 0, 5);
    pieces[13].Assignment_func(playerB_sym, "b", 2, 5);
    pieces[14].Assignment_func(playerB_sym, "b", 4, 5);
    pieces[15].Assignment_func(playerA_sym, "b", 6, 5);
    pieces[16].Assignment_func(playerB_sym, "b", 1, 6);
    pieces[17].Assignment_func(playerB_sym, "b", 3, 6);
    pieces[18].Assignment_func(playerB_sym, "b", 5, 6);
    pieces[19].Assignment_func(playerB_sym, "b", 7, 6);
    pieces[20].Assignment_func(playerB_sym, "b", 0, 7);
    pieces[21].Assignment_func(playerB_sym, "b", 2, 7);
    pieces[22].Assignment_func(playerB_sym, "b", 4, 7);
    pieces[23].Assignment_func(playerB_sym, "b", 6, 7);

    cout<<"2022291 & 2022369\n";
    std::cout << "\t\t\t=========== CS112 Assignment 2 : Checkers ===========\n\n\t\t\t\t   (Press ENTER to start the game)" << std::endl<<std::endl;

    bool playerA = true, playerB = false;
    char player_symbol,white = -37, red = -37;
    int playerA_moves = -1, playerB_moves = -1;
    int playerA_special_moves{0}, playerB_special_moves{0}, A_pieces_further_moves{0}, B_pieces_further_moves = 0;
    while(playerA_moves != 0 && playerB_moves != 0 && kill_count_b != 12 && kill_count_a != 12) {
        bool move_possible = true, normal_moves = true;
        int move_taken = 0;
        playerA_moves = -1;playerB_moves = -1;
        A_pieces_further_moves = 0;B_pieces_further_moves = 0;
        playerA && !playerB ? (player_symbol = playerA_sym, SetConsoleTextAttribute(colour, 4), cout << "\t\t\tPlayer A's move", cout<<" -> O\n")
                            : (player_symbol = playerB_sym, SetConsoleTextAttribute(colour, 10),
                cout << "\t\t\tPlayer B's move", cout<<" -> 0\n");

        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if ((i + j) % 2 == 0) { Display_Board[i][j] = white; Board[i][j] = '-'; }
                else { Display_Board[i][j] = red; Board[i][j] = '-'; }
            }
        }

        for (const auto & piece : pieces) {
            if (piece.getPlayer() == "a" && (piece.specific_ValidMove3() || piece.specific_ValidMove4() ||
            piece.specific_ValidMove5() || piece.specific_ValidMove6())) {
                playerA_special_moves++;
            }
            if (piece.getPlayer() == "b" && (piece.specific_ValidMove3() || piece.specific_ValidMove4() ||
            piece.specific_ValidMove5() || piece.specific_ValidMove6())) {
                playerB_special_moves++;
            }
            if (piece.getX() != -1) {
                if (piece.getPlayer() == "a") {
                    if(piece.get_Is_King()){
                        Display_Board[piece.getY()][piece.getX()] = 'K';
                        Board[piece.getY()][piece.getX()] = playerA_sym;
                    } else {
                        Board[piece.getY()][piece.getX()] = playerA_sym;
                        Display_Board[piece.getY()][piece.getX()] = playerA_sym;
                    }
                } else {
                    if(piece.get_Is_King()){
                        Display_Board[piece.getY()][piece.getX()] = 'K';
                        Board[piece.getY()][piece.getX()] = playerB_sym;
                    }else{
                    Board[piece.getY()][piece.getX()] = playerB_sym;
                    Display_Board[piece.getY()][piece.getX()] = playerB_sym;
                    }
                }
            }
        }
        //Displaying board
        SetConsoleTextAttribute(colour, 7);
        cout << "\t\t\t\t\t   1 2 3 4 5 6 7 8   X-axis" << endl;
        for (int i = 0; i < 8; i++) {
            SetConsoleTextAttribute(colour, 7);
            cout <<"\t\t\t\t\t"<< i + 1 << "  ";
            for (int j = 0; j < 8; j++){
                if((i + j) % 2 == 0) {
                    if(Board[i][j] == '0'){
                        SetConsoleTextAttribute(colour, 10);//green
                        std::cout << Display_Board[i][j] << ' ';
                    }
                    else if(Board[i][j] == 'O'){
                        SetConsoleTextAttribute(colour, 4);//red
                        std::cout << Display_Board[i][j] << ' ';
                    }
                    else if (Board[i][j] == '-') {
                        SetConsoleTextAttribute(colour, 4);//red
                        std::cout << Display_Board[i][j] << ' ';
                    }
                }
                if ((i + j) % 2 != 0){
                    if(Board[i][j] == '0'){
                        SetConsoleTextAttribute(colour, 10);//green
                        std::cout << Display_Board[i][j] << ' ';
                    }
                    else if(Board[i][j] == 'O'){
                        SetConsoleTextAttribute(colour, 4);//red
                        std::cout << Display_Board[i][j] << ' ';
                    } else if (Board[i][j] == '-') {
                        SetConsoleTextAttribute(colour, 10);//green
                        std::cout << Display_Board[i][j] << ' ';
                    }
                }
            }std::cout << std::endl;
        }
        SetConsoleTextAttribute(colour, 7);//white
        cout << "\t\t\t\t\tY-axis\n";cout<<"\t\t    Player A has killed "<<kill_count_a<< " Pawns.     Player B has killed "<<kill_count_b<< " Pawns."<<endl;
        for (const auto & piece : pieces) {
            if (player_symbol == 'O') {
                if (piece.getPlayer() == "a"  && piece.getX() != -1 && piece.getY() != -1 && piece.further_moves()) {
                    cout << "Pawn of A " << piece.getX() + 1 << piece.getY() + 1
                         << " can capture an opponents pawn!\n";
                    A_pieces_further_moves++;
                    normal_moves = false;
                }
            }
            if (player_symbol == '0') {
                if (piece.getPlayer() == "b"  && piece.getX() != -1 && piece.getY() != -1 && piece.further_moves()) {
                    cout << "Pawn of B " << piece.getX() + 1 << piece.getY() + 1
                         << " can capture an opponents pawn!\n";
                    B_pieces_further_moves++;
                    normal_moves = false;
                }
            }

            if (piece.getPlayer() == "a" && piece.ValidMove()) {
                playerA_moves++;
            } else if (piece.getPlayer() == "b" && piece.ValidMove()) {
                playerB_moves++;
            }
        }
        cin.ignore();
        cout << "choose a piece (XY): ";
        while (true) {
            getline(cin, piece_choice);

            if (piece_choice == "00" || piece_choice.empty() || stoi(piece_choice) < 0 || piece_choice.length() < 2 ||
                piece_choice.length() > 2) {
                cout << "Type a non-negative number that is of size 2: ";
                continue;
            }
            if (salted_potato::pawn_check(piece_choice, player_symbol)) {
                cout << "pawn " << piece_choice << " selected\n";
            } else {
                cout << "You can not choose this pawn choose another one: ";
                continue;
            }
            break;
        }

        string px, py;
        px = piece_choice[0];
        py = piece_choice[1];
        Piece *chosen_pawn;

        for (auto & piece : pieces) {
            if (piece.getX() == (stoi(px) - 1) && piece.getY() == (stoi(py) - 1)) {
                chosen_pawn = &piece;
            }
        }

        int i = 0;
        while (move_possible) {
            if (chosen_pawn->getPlayer() == "b" && chosen_pawn->ValidMove()) {
                cout << "This piece can perform the following possible moves\n";
                if (chosen_pawn->specific_ValidMove3()) {
                    cout << "1. right diagonal while capturing opponent pawn\n";}
                if (chosen_pawn->specific_ValidMove4())
                    cout << "2. left diagonal while capturing opponent pawn\n";
                if (normal_moves && chosen_pawn->specific_ValidMove1() && !chosen_pawn->specific_ValidMove3() &&
                    !chosen_pawn->specific_ValidMove4())
                    cout << "3. right diagonal\n";
                if (normal_moves && chosen_pawn->specific_ValidMove2() && !chosen_pawn->specific_ValidMove3() &&
                    !chosen_pawn->specific_ValidMove4())
                    cout << "4. left diagonal\n";
                if (chosen_pawn->get_Is_King()) {
                    if (chosen_pawn->specific_ValidMove5())
                        cout << "5. Backwards right capturing opponent pawn\n";
                    if (chosen_pawn->specific_ValidMove6())
                        cout << "6. Backwards Left capturing opponent pawn\n";
                    if (normal_moves && chosen_pawn->specific_ValidMove7() && !chosen_pawn->specific_ValidMove3() &&
                        !chosen_pawn->specific_ValidMove4() && !chosen_pawn->specific_ValidMove5() &&
                        !chosen_pawn->specific_ValidMove6())
                        cout << "7. Backwards right\n";
                    if (normal_moves && chosen_pawn->specific_ValidMove8() && !chosen_pawn->specific_ValidMove3() &&
                        !chosen_pawn->specific_ValidMove4() && !chosen_pawn->specific_ValidMove5() &&
                        !chosen_pawn->specific_ValidMove6())
                        cout << "8. Backwards left\n";
                }
            }

            if (chosen_pawn->getPlayer() == "a" && chosen_pawn->ValidMove()) {
                cout << "This piece can perform the following possible moves\n";
                if (chosen_pawn->specific_ValidMove5())
                    cout << "5. Forward left diagonal while capturing opponents pawn\n";
                if (chosen_pawn->specific_ValidMove6())
                    cout << "6. Forward right diagonal while capturing opponents pawn\n";
                if (normal_moves && chosen_pawn->specific_ValidMove7() && !chosen_pawn->specific_ValidMove5() &&
                    !chosen_pawn->specific_ValidMove6())
                    cout << "7. Forward left Diagonal\n";
                if (normal_moves && chosen_pawn->specific_ValidMove8() && !chosen_pawn->specific_ValidMove6() &&
                    !chosen_pawn->specific_ValidMove5())
                    cout << "8. Forward right Diagonal\n";
                if (chosen_pawn->get_Is_King()) {
                    if (chosen_pawn->specific_ValidMove3())
                        cout << "1. Backwards right diagonal capturing opponents pawn\n";
                    if (chosen_pawn->specific_ValidMove4())
                        cout << "2. Backwards left diagonal while capturing opponents pawn\n";
                    if (normal_moves && chosen_pawn->specific_ValidMove1() && !chosen_pawn->specific_ValidMove3() &&
                        !chosen_pawn->specific_ValidMove4() && !chosen_pawn->specific_ValidMove5() &&
                        !chosen_pawn->specific_ValidMove6())
                        cout << "3. Backwards right diagonal\n";
                    if (normal_moves && chosen_pawn->specific_ValidMove2() && !chosen_pawn->specific_ValidMove3() &&
                        !chosen_pawn->specific_ValidMove4() && !chosen_pawn->specific_ValidMove5() &&
                        !chosen_pawn->specific_ValidMove6())
                        cout << "4. Backwards left diagonal\n";
                }
            }
            cout << "0. Deselect Pawn";
            cout << endl;
            cout << "Choose a move from the list above: ";
            cin >> i;

            switch (i) {
                case 1://right diagonal while capturing opponent pawn
                    for (auto &piece: pieces) {
                        if (piece.getX() == (chosen_pawn->getX() + 1) && piece.getY() == (chosen_pawn->getY() - 1)) {
                            piece.Seppuku();
                            break;
                        }
                    }
                    chosen_pawn->TakeMove(chosen_pawn->getX() + 2, chosen_pawn->getY() - 2);
                    move_taken++;
                    break;
                case 2://left diagonal while capturing opponent paw
                    for (auto &piece: pieces) {
                        if (piece.getX() == chosen_pawn->getX() - 1 && piece.getY() == chosen_pawn->getY() - 1) {
                            piece.Seppuku();
                            break;
                        }
                    }
                    chosen_pawn->TakeMove(chosen_pawn->getX() - 2, chosen_pawn->getY() - 2);
                    move_taken++;
                    break;
                case 3://forward right diagonal
                    chosen_pawn->TakeMove(chosen_pawn->getX() + 1, chosen_pawn->getY() - 1);
                    move_taken++;
                    break;
                case 4://forward left diagonal
                    chosen_pawn->TakeMove(chosen_pawn->getX() - 1, chosen_pawn->getY() - 1);
                    move_taken++;
                    break;
                case 5://Backwards right capturing opponent pawn
                    for (auto &piece: pieces) {
                        if (piece.getX() == chosen_pawn->getX() + 1 && piece.getY() == chosen_pawn->getY() + 1) {
                            piece.Seppuku();
                            break;
                        }
                    }
                    chosen_pawn->TakeMove(chosen_pawn->getX() + 2, chosen_pawn->getY() + 2);
                    move_taken++;
                    break;
                case 6://Backwards Left capturing opponent pawn
                    for (auto &piece: pieces) {
                        if (piece.getX() == chosen_pawn->getX() - 1 && piece.getY() == chosen_pawn->getY() + 1) {
                            piece.Seppuku();
                            break;
                        }
                    }
                    chosen_pawn->TakeMove(chosen_pawn->getX() - 2, chosen_pawn->getY() + 2);
                    move_taken++;
                    break;
                case 7://Backwards right
                    chosen_pawn->TakeMove(chosen_pawn->getX() + 1, chosen_pawn->getY() + 1);
                    move_taken++;
                    break;
                case 8://Backwards left
                    chosen_pawn->TakeMove(chosen_pawn->getX() - 1, chosen_pawn->getY() + 1);
                    move_taken++;
                    break;
                case 0://pawn deselection
                    break;
                default:
                    cout << "Type the right number\n";continue;
            }
            //cout << "\033[2J\033[1;1H";//clear screen
            system("CLS");//clear screen
            if (chosen_pawn->getPlayer() == "a" && chosen_pawn->getY() == 7 && !chosen_pawn->get_Is_King())
                if (chosen_pawn->getX() == 0 || chosen_pawn->getX() == 1 || chosen_pawn->getX() == 2 ||
                    chosen_pawn->getX() == 3 || chosen_pawn->getX() == 4 || chosen_pawn->getX() == 5 ||
                    chosen_pawn->getX() == 6 || chosen_pawn->getX() == 7)
                    chosen_pawn->set_king(true);
            if (chosen_pawn->getPlayer() == "b" && chosen_pawn->getY() == 0 && !chosen_pawn->get_Is_King())
                if (chosen_pawn->getX() == 0 || chosen_pawn->getX() == 1 || chosen_pawn->getX() == 2 ||
                    chosen_pawn->getX() == 3 || chosen_pawn->getX() == 4 || chosen_pawn->getX() == 5 ||
                    chosen_pawn->getX() == 6 || chosen_pawn->getX() == 7)
                    chosen_pawn->set_king(true);

            if (chosen_pawn->further_moves()) {
                move_possible = true;
                normal_moves = false;
                cout << "\nFurther moves possible so pawn can't be deselected.\n";
                continue;
            } else if (move_taken > 0) {
                move_possible = false;
                normal_moves = false;
                move_taken = 0;
                salted_potato::inversion(&playerA, &playerB);
                break;
            } else {
                move_possible = false;
                normal_moves = false;
                break;
            }
        }
    }
    if (kill_count_a == 12 || playerB_moves == 0) {
        cout << "\n\n\t\t\tplayer A won! " << endl;
        if(kill_count_a == 12){
            cout<<"Player A has Killed all of the opponents pawns!\n";
        }
        else if(playerB_moves == 0){
            cout<<"Player B does not have any moves left!\n";
        }
    }
    if (kill_count_b == 12 || playerA_moves == 0) {
        cout << "\n\n\t\t\tplayer B won" << endl;
        if(kill_count_b == 12){
            cout<<"Player B has Killed all of the opponents pawns!\n";
        }
        else if(playerA_moves == 0){
            cout<<"Player A does not have any moves left!\n";
        }
    }

    return 0;
}