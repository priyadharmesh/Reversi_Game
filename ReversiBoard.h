/*
 * ReversiBoard.h
 *
 *  Created on: 17-Nov-2023
 *      Author: Priyanka
 */

#ifndef REVERSIBOARD_H_
#define REVERSIBOARD_H_

/*
 * a enum to store the states of the board EMPTY= 0
 * PLAYER1 =1 , PLAYER2=2
 *
 */
enum class FieldState {
    EMPTY,
    PLAYER1,
    PLAYER2
};
/*
 * Class Reversi Board which contains all the method and
 * variables related to board conditions
 */
class ReversiBoard
{
private:
	/*
	 * size indicating the size of the board
	 * board indicating the board itself which is of pointer of enum type
	 */
        int size;
        FieldState** board;
public:

	ReversiBoard(int size = 8);

	~ReversiBoard() ;

	 /*
	  * Getter for field state
	  * it gets the board position at the passed row and column
	  */
	 FieldState get_field_state(int row, int col) const;

	 /*
	  * set the field
	  * sets the board position for the rows and columns
	  * first it checks for the valid position
	  * also if valid flips the required field
	  * and returns true or false accordingly
	  */
	 bool set_field_state(int row, int col, int player) ;

	 /*
	  * to get the size of board
	  */
	 int getSize() const;


};

class ReversiConsoleView {
public:
	/*
	 * class written to print the complete board after each turn on
	 * the console
	 * it calls get_field_state and then prints it with the help of
	 * print_board function : prints the updated board to user
	 */
    ReversiConsoleView(const ReversiBoard& board);

    void print_board() const;

private:
    const ReversiBoard& board;
};


#endif /* REVERSIBOARD_H_ */
