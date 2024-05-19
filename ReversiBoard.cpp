/*
 * ReversiBoard.cpp
 *
 *  Created on: 17-Nov-2023
 *      Author: Priyanka
 */

#include "ReversiBoard.h"
#include <iostream>
using namespace std;
#include <array>


ReversiBoard::ReversiBoard(int size) : size(size)
	      {
	        // Initialize the board with empty fields
	        board = new FieldState*[size];
	        for (int i = 0; i < size; ++i) {
	            board[i] = new FieldState[size];
	            for (int j = 0; j < size; ++j) {
	                board[i][j] = FieldState::EMPTY;

	            }
	        }
	        board[3][3] = FieldState::PLAYER1;
	        board[4][4] = FieldState::PLAYER1;
	        board[4][3] = FieldState::PLAYER2;
	        board[3][4] = FieldState::PLAYER2;
	    }


ReversiBoard::~ReversiBoard()
{
	// TODO Auto-generated destructor stub
	for (int i = 0; i < size; ++i) {
		            delete[] board[i];
		        }
		        delete[] board;
		    }

// Getter for field state
FieldState ReversiBoard::get_field_state
             (int row, int col) const
{
    return board[row][col];
}

int ReversiBoard::getSize() const {
    return size;
}

// Setter for field state

bool ReversiBoard::set_field_state
(int row, int col, int player)
{
    if (row < 0 || row >= size || col < 0 || col >= size ||
    		board[row][col] != FieldState::EMPTY) {
        return false; // Invalid move
    }
    const int rows = 8;
//    const int cols = 8;
    // Determine the size dynamically based on enum criteria
    int array4Size = rows - row;
    int* array4 = new int[array4Size];
    int array2Size = col+1;
    int* array2 = new int[array2Size];

    int array3Size = row+1;
    int* array3 = new int[array3Size];
    int array1Size = 8 - col;
    int* array1 = new int[array1Size];

    //
    int maxSizeUpRight = std::min(row + 1, size - col) + 1;
    int diagonalUpRight[maxSizeUpRight];
    int sizeOfDiagonalUpRight = 0;

    //
    int maxSizeDownRight = std::min(size - row, size - col) + 1;
    int diagonalDownRight[maxSizeDownRight];
    int sizeOfDiagonalDownRight = 0;

    // For
    int maxSizeUpLeft = std::min(row + 1, col + 1) + 1;
    int diagonalUpLeft[maxSizeUpLeft];
    int sizeOfDiagonalUpLeft = 0;

    // For diagonalDownLeft
    int maxSizeDownLeft = std::min(size - row, col + 1) + 1;
    int diagonalDownLeft[maxSizeDownLeft];
    int sizeOfDiagonalDownLeft = 0;


    // Store elements in the up-right diagonal
        cout<<"diagnol elements of upright are : ";
        for (int i = 0; row - i >= 0 && col + i < size; ++i) {
        	diagonalUpRight[i] = static_cast<int>(board[row - i][col + i]);
            std::cout << diagonalUpRight[i] << " ";
            // Update size for each iteration
            sizeOfDiagonalUpRight = i + 1;
        }
        cout<<endl;

        // Store elements in the down-right diagonal
            cout<<"diagnol elements of downright are : ";
            for (int i = 0; row + i < size && col + i < size; ++i) {
            	diagonalDownRight[i] = static_cast<int>(board[row + i]
															  [col + i]);
                std::cout << diagonalDownRight[i] << " ";
                sizeOfDiagonalDownRight = i + 1;
            }
            cout<<endl;
            // Store elements in the up-left diagonal
               cout<<"diagnol elements of upleft are : ";
               for (int i = 0; row - i >= 0
               && col - i >= 0; ++i) {
            	   diagonalUpLeft[i] =
            			   static_cast<int>(board[row - i][ col - i]);
                   std::cout << diagonalUpLeft[i] << " ";
                   sizeOfDiagonalUpLeft = i + 1;
               }
                cout<<endl;
               // Store elements in the down-left diagonal
                  cout<<"diagnol elements of downleft are : ";
                  for (int i = 0; row + i < size && col - i >= 0; ++i)
                  {
                	  diagonalDownLeft[i] =
                			  static_cast<int>(board[row + i][ col - i]);
                      std::cout << diagonalDownLeft[i] << " ";
                      sizeOfDiagonalDownLeft = i + 1;
                  }
             cout<<endl;

    // to print right left top bottom of the position

    if(player==int(FieldState::PLAYER1)||
    		player==int(FieldState::PLAYER2))
    {

    	// towards x direction right
    	for (int j = col; j < 8; j++) {
    	            array1[j-col] = static_cast<int>
    	            (board[row][j]);
    	            cout <<array1[j-col] << " ";

    	        }

    	        cout << endl;
        // towards x direction left

    	        for (int j = col; j > -1; j--) {
    	                array2[col-j] = static_cast<int>
    	                (board[row][j]);
    	                std::cout << array2[col-j] << " ";
    	            }
    	          cout << endl;

    	// towards y direction up
    	       for (int i=row; i>-1;i--) {
    	         array3[row-i] = static_cast<int>
    	         (board[i][col]);
    	         cout <<array3[row-i] << " ";
    	        }
    	        cout << endl;

    	// towards y direction down

    	        for (int i = row; i < rows; ++i) {
    	            array4[i - row] = static_cast<int>
    	            (board[i][col]);
    	            std::cout << array4[i - row] << " ";
    	        }
    	 cout<<endl;


// diagnol check

    	 int counterfalse=0;

    // to find the valid position for first player
    if(player==int(FieldState::PLAYER1))
    {
    	// diagnol check : DiagnolUpright
    	int counterUR=0;
       	if(diagonalUpRight[1]==1)
        	{
        		for(int j=1;j<sizeOfDiagonalUpRight;j++)
        		{
        			if(diagonalUpRight[j]==2)
        			{
        				for(int k=2;k<sizeOfDiagonalUpRight;k++)
        				{
        					if(diagonalUpRight[k]==1){
        						counterUR++;
        					}
        				}
        			}
        			else{
        				counterfalse++;
        			}
        		}
        	}

        	if(diagonalUpRight[1]==2){
        		for (int j=1;j<sizeOfDiagonalUpRight;j++ ){
        			if(diagonalUpRight[j]==1)
        			{
        				counterUR++;
        			}
        			else{
        				counterfalse++;
        			}
        		}
        	}
        	if(diagonalUpRight[1]==0){
        		counterfalse++;
        	}

          	 if(counterUR)
          	 {
            	cout<< "valid move"<< endl;
            	board[row][col] = (player == 1) ?
            			FieldState::PLAYER1 : FieldState::PLAYER2;
            //flipping for upright

   	    		if(board[row][col]==FieldState::PLAYER1)
   	    		{
   	    			int row1=row-1;
   	    			int col1=col+1;
   	    		while (row1>=0 && col1 <size)
   	    	    {
   	    			cout<<row1<<endl;
   	    			cout<<col1<<endl;
   	    			cout<<static_cast<int>(board[row1][col1])<<endl;
   	    			if(board[row1] [col1 ]== FieldState::PLAYER1)
   	    			{
   	    				cout<<"getting in another loop"<<endl;
   	    			    break;
   	    			}
   	    		    if(board[row1][col1]==FieldState::PLAYER2)
   	    		    {
   	    		    	cout<<"getting in loop"<<endl;
   	    			    board[row1][col1]=FieldState::PLAYER1;
   	    			}

   	    		row1--;
   	    		col1++;
   	    		}
   	    		}
   	    		cout<<"reached here"<<endl;
   	    	}



        	// Diagnol check :Downright
          	int counterDR=0;
           	if(diagonalDownRight[1]==1)
            	{
            		for(int j=1;j<sizeOfDiagonalDownRight;j++)
            		{
            			if(diagonalDownRight[j]==2)
            			{
            				for(int k=2;k<sizeOfDiagonalDownRight;k++)
            				{
            					if(diagonalDownRight[k]==1){
            						counterDR++;
            					}
            				}
            			}
            			else{
            				counterfalse++;
            			}
            		}
            	}
            	if(diagonalDownRight[1]==2){
            		for (int j=1;j<sizeOfDiagonalDownRight;j++ ){
            			if(diagonalUpRight[j]==1)
            			{
            				counterDR++;
            			}
            			else{
            				counterfalse++;
            			}
            		}
            	}
            	if(diagonalDownRight[1]==0){
            		counterfalse++;
            	}
         if(counterDR)
         {
         	cout<< "valid move"<< endl;
         	board[row][col] = (player == 1) ?
         			FieldState::PLAYER1 : FieldState::PLAYER2;
         	//flipping downright

	    		if(board[row][col]==FieldState::PLAYER1)
	    		{
	    			int row1=row+1;
	    			int col1=col+1;
	    		while (row1 < size && col1 <size)
	    	    {
	    			cout<<row1<<endl;
	    			cout<<col1<<endl;
	    			cout<<static_cast<int>(board[row1][col1])<<endl;
	    			if(board[row1] [col1 ]== FieldState::PLAYER1)
	    			{
	    				cout<<"getting in another loop"<<endl;
	    			    break;
	    			}
	    		    if(board[row1][col1]==FieldState::PLAYER2)
	    		    {
	    		    	cout<<"getting in loop"<<endl;
	    			    board[row1][col1]=FieldState::PLAYER1;
	    			}

	    		row1++;
	    		col1++;
	    		}
	    		}

         }

         // Diagnol: upleft
         int counterUL=0;
               	if(diagonalUpLeft[1]==1)
                	{
                		for(int j=1;j<sizeOfDiagonalUpLeft;j++)
                		{
                			if(diagonalUpLeft[j]==2)
                			{
                				for(int k=2;k<sizeOfDiagonalUpLeft ;k++)
                				{
                					if(diagonalUpLeft[k]==1){
                						counterUL++;
                					}
                				}
                			}
                			else{
                				counterfalse++;
                			}
                		}
                	}
                	if(diagonalUpLeft[1]==2){
                		for (int j=1;j<sizeOfDiagonalUpLeft;j++ ){
                			if(diagonalUpLeft[j]==1)
                			{
                				counterUL++;
                			}
                			else{
                				counterfalse++;
                			}
                		}
                	}
                	if(diagonalUpLeft[1]==0){
                		counterfalse++;
                	}
                    if(counterUL)
                    {
                    	cout<< "valid move"<< endl;
                    	board[row][col] = (player == 1) ?
                    			FieldState::PLAYER1 : FieldState::PLAYER2;

           	    		if(board[row][col]==FieldState::PLAYER1)
           	    		{
           	    			int row1=row-1;
           	    			int col1=col-1;
           	    		while (row1>=0 && col1 >=0)
           	    	    {
           	    			cout<<row1<<endl;
           	    			cout<<col1<<endl;
           	    			cout<<static_cast<int>(board[row1][col1])<<endl;
           	    			if(board[row1] [col1 ]== FieldState::PLAYER1)
           	    			{
           	    				cout<<"getting in another loop"<<endl;
           	    			    break;
           	    			}
           	    		    if(board[row1][col1]==FieldState::PLAYER2)
           	    		    {
           	    		    	cout<<"getting in loop"<<endl;
           	    			    board[row1][col1]=FieldState::PLAYER1;
           	    			}

           	    		row1--;
           	    		col1--;
           	    		}
           	    		}
                    }


          // Diagnol : Downleft
                    int counterDL=0;
                   	if(diagonalDownLeft[1]==1)
                    	{
                    		for(int j=1;j<sizeOfDiagonalDownLeft;j++)
                    		{
                    			if(diagonalUpLeft[j]==2)
                    			{
                    				for(int k=2 ;k<sizeOfDiagonalDownLeft
                    				;k++)
                    				{
                    					if(diagonalDownLeft[k]==1){
                    						counterDL++;
                    					}
                    				}
                    			}
                    			else{
                    				counterfalse++;
                    			}
                    		}
                    	}
                    	if(diagonalDownLeft[1]==2){
                    		for (int j=1;j<sizeOfDiagonalDownLeft;j++ ){
                    			if(diagonalDownLeft[j]==1)
                    			{
                    				counterDL++;
                    			}
                    			else{
                    				counterfalse++;
                    			}
                    		}
                    	}
                    	if(diagonalDownLeft[1]==0){
                    		counterfalse++;
                    	}
                        if(counterDL)
                        {
                        	cout<< "valid move"<< endl;
                        	board[row][col] = (player == 1) ?
                        			FieldState::PLAYER1 : FieldState::PLAYER2;
               	    		if(board[row][col]==FieldState::PLAYER1)
               	    		{
               	    			int row1=row+1;
               	    			int col1=col-1;
               	    		while (row1< size && col1 >=0)
               	    	    {
               	    			cout<<row1<<endl;
               	    			cout<<col1<<endl;
               	    			cout<<static_cast<int>(board[row1][col1])<<endl;
               	    			if(board[row1] [col1 ]== FieldState::PLAYER1)
               	    			{
               	    				cout<<"getting in another loop"<<endl;
               	    			    break;
               	    			}
               	    		    if(board[row1][col1]==FieldState::PLAYER2)
               	    		    {
               	    		    	cout<<"getting in loop"<<endl;
               	    			    board[row1][col1]=FieldState::PLAYER1;
               	    			}

               	    		row1++;
               	    		col1++;
               	    		}
               	    		}
                        }



    	//array1
        cout<<"1st position is :"<<array1[1]<<endl;
    	cout<<"size:"<<array1Size<<endl;
    	int counter1=0;
    	if(array1[1]==1)
    	{
    		for(int j=1;j<array1Size;j++)
    		{
    			if(array1[j]==2)
    			{
    				for(int k=2;k<array1Size;k++)
    				{
    					if(array1[k]==1){
    						counter1++;
    					}
    				}
    			}
    			else{
    				counterfalse++;
    			}
    		}
    	}
    	if(array1[1]==2){
    		for (int j=1;j<array1Size;j++ ){
    			if(array1[j]==1)
    			{
    				counter1++;
    			}
    			else{
    				counterfalse++;
    			}
    		}
    	}
    	if(array1[1]==0){
    		counterfalse++;
    	}
    	if(counter1)
    	{
        	cout<< "valid move"<< endl;
        	board[row][col] = (player == 1) ?
        			FieldState::PLAYER1 : FieldState::PLAYER2;
        	for(int i=col+1;i<size;i++)
        	{
        		if(board[row][i]==FieldState::PLAYER1)
        		{
        			break;
        		}
        		if(board[row][i]==FieldState::PLAYER2)
        		{
        			board[row][i]=FieldState::PLAYER1;
        		}
        	}

    	}

    	//array 2
    	cout<<"1st position is :"<<array2[1]<<endl;
    	cout<<"size:"<<array2Size<<endl;
    	int counter2=0;
    	if(array2[1]==1){
    	    		for(int j=1;j<array2Size;j++)
    	    		{
    	    			if(array2[j]==2)
    	    			{
    	    				for(int k=2;k<array2Size;k++)
    	    				{
    	    					if(array2[k]==1)
    	    					{
    	    						counter2++;
    	    					}
    	    				}
    	    			}
    	    			else{
    	    				counterfalse++;
    	    			}
    	    		}
    	    	}

    	 if(array2[1]==2)
    	 {
    		 for(int j=1;j<array2Size;j++)
    		 {
    			 if(array2[j]==1)
    			 {
    				 counter2++;
    			 }
    			 else
    			 {
    				 counterfalse++;
    			 }
    		 }
    	 }
    	 if(array2[1]==0){
    	    		counterfalse++;
    	    	}
     	if(counter2)
     	{
         	cout<< "valid move"<< endl;
         	board[row][col] = (player == 1) ?
         			FieldState::PLAYER1 : FieldState::PLAYER2;
        	for(int i=col-1;i<size;i--)
        	{
        		if(board[row][i]==FieldState::PLAYER1)
        		{
        			break;
        		}
        		if(board[row][i]==FieldState::PLAYER2)
        		{
        			board[row][i]=FieldState::PLAYER1;
        		}
        	}
     	}


// array 3
    	    cout<<"1st position is :"<<array3[1]<<endl;
        	cout<<"size:"<<array3Size<<endl;
        	int counter3=0;
    	    if(array3[1]==1){
    	    	    	for(int j=1;j<array3Size;j++)
    	    	    	    {
    	    	    	     if(array3[j]==2)
    	    	    	     {
    	    	    	    	 for(int k=2;k<array3Size;k++)
    	    	    	    	 {
    	    	    	    		if(array3[k]==1)
    	    	    	    		{
    	    	    	    	     counter3++;
    	    	    	    	     }
    	    	    	    	 }
    	    	    	     }
    	    	    	     else{
    	    	    	    	   counterfalse++;
    	    	    	    	  }
    	    	    	     }
    	    }
    	    if(array3[1]==2){
    	    	    	  for (int j=1;j<array3Size;j++ ){
    	    	    	    		if(array3[j]==1)
    	    	    	    			{
    	    	    	    				counter3++;
    	    	    	    			}
    	    	    	    		else{
    	    	    	    				counterfalse++;
    	    	    	    			}
    	    	    	    		}
    	    	    	    	}
    	   if(array3[1]==0){
    	    	    	    counterfalse++;
    	    	    	    }
        	if(counter3)
        	{
            	cout<< "valid move"<< endl;
            	board[row][col] = (player == 1) ?
            			FieldState::PLAYER1 : FieldState::PLAYER2;
            	for(int j=row-1;j>-1;j--)
            	{
            		if(board[j][col]==FieldState::PLAYER1)
            		{
            			break;
            		}
            		if(board[j][col]==FieldState::PLAYER2)
            		{
            			board[j][col]=FieldState::PLAYER1;
            		}
            	}
        	}


    	  //array4
    	   cout<<"1st position is :"<<array4[1]<<endl;
       	   cout<<"size:"<<array4Size<<endl;
       	   int counter4=0;
    	   if(array4[1]==1){
    	      for(int j=1;j<array4Size;j++)
    	      {
    	       if(array4[j]==2)
    	        {
    	    	   for(int k=2;k<array4Size;k++){
    	    		   if(array4[k]==1){
    	    			   counter4++;
    	    		   }
    	    	   }
    	        }
    	    	else{
    	    	    counterfalse++;
    	    	    }
    	   	  }
    	    }
    	    if(array4[1]==2){
    	    for (int j=1;j<array4Size;j++ ){
    	    if(array4[j]==1)
    	    {
    	     counter4++;
    	    }
    	    else{
    	    	 counterfalse++;
    	    	}
    	    }
    	  }
    	   if(array4[1]==0){
    	    counterfalse++;
    	  }
       	if(counter4)
       	{

	    	cout<< "valid move"<< endl;
           	board[row][col] = (player == 1) ?
           			FieldState::PLAYER1 : FieldState::PLAYER2;
        	for(int j=row+1;j>-1;j++)
        	{
        		if(board[j][col]==FieldState::PLAYER1)
        		{
        			break;
        		}
        		if(board[j][col]==FieldState::PLAYER2)
        		{
        			board[j][col]=FieldState::PLAYER1;
        		}
        	}
    	}



    }
    //
    //to find the valid position for player 2

    else
    {
    	// diagnol check : DiagnolUpright
    	int counterUR=0;
       	if(diagonalUpRight[1]==2)
        	{
        		for(int j=1;j<sizeOfDiagonalUpRight;j++)
        		{
        			if(diagonalUpRight[j]==1)
        			{
        				for(int k=2;k<sizeOfDiagonalUpRight;k++)
        				{
        					if(diagonalUpRight[k]==2){
        						counterUR++;
        					}
        				}
        			}
        			else{
        				counterfalse++;
        			}
        		}
        	}

        	if(diagonalUpRight[1]==1){
        		for (int j=1;j<sizeOfDiagonalUpRight;j++ ){
        			if(diagonalUpRight[j]==2)
        			{
        				counterUR++;
        			}
        			else{
        				counterfalse++;
        			}
        		}
        	}
        	if(diagonalUpRight[1]==0){
        		counterfalse++;
        	}
           	if(counterUR)
           	{
    	    	cout<< "valid move"<< endl;
               	board[row][col] = (player == 1) ?
               	 FieldState::PLAYER1 : FieldState::PLAYER2;
   	    		if(board[row][col]==FieldState::PLAYER2)
   	    		{
   	    			int row1=row-1;
   	    			int col1=col+1;
   	    		while (row1>=0 && col1 <size)
   	    	    {
   	    			cout<<row1<<endl;
   	    			cout<<col1<<endl;
   	    			cout<<static_cast<int>(board[row1][col1])<<endl;
   	    			if(board[row1] [col1 ]== FieldState::PLAYER2)
   	    			{
   	    				cout<<"getting in another loop"<<endl;
   	    			    break;
   	    			}
   	    		    if(board[row1][col1]==FieldState::PLAYER1)
   	    		    {
   	    		    	cout<<"getting in loop"<<endl;
   	    			    board[row1][col1]=FieldState::PLAYER2;
   	    			}

   	    		row1--;
   	    		col1++;
   	    		}
   	    		}

           	}
        	// Diagnol check :Downright
           	int counterDR=0;
           	if(diagonalDownRight[1]==2)
            	{
            		for(int j=1;j<sizeOfDiagonalDownRight;j++)
            		{
            			if(diagonalDownRight[j]==1)
            			{
            				for(int k=2;k<sizeOfDiagonalDownRight;k++)
            				{
            					if(diagonalDownRight[k]==2){
            						counterDR++;
            					}
            				}
            			}
            			else{
            				counterfalse++;
            			}
            		}
            	}
            	if(diagonalDownRight[1]==1){
            		for (int j=1;j<sizeOfDiagonalDownRight;j++ ){
            			if(diagonalDownRight[j]==2)
            			{
            				counterDR++;
            			}
            			else{
            				counterfalse++;
            			}
            		}
            	}
            	if(diagonalDownRight[1]==0){
            		counterfalse++;
            	}
               	if(counterDR)
               	{
        	    	for(int j=row;j>-1;j--)cout<< "valid move"<< endl;
                   	board[row][col] = (player == 1) ?
                   			FieldState::PLAYER1 : FieldState::PLAYER2;
       	    		if(board[row][col]==FieldState::PLAYER2)
       	    		{
       	    			int row1=row+1;
       	    			int col1=col+1;
       	    		while (row1<size && col1 <size)
       	    	    {
       	    			cout<<row1<<endl;
       	    			cout<<col1<<endl;
       	    			cout<<static_cast<int>(board[row1][col1])<<endl;
       	    			if(board[row1] [col1 ]== FieldState::PLAYER2)
       	    			{
       	    				cout<<"getting in another loop"<<endl;
       	    			    break;
       	    			}
       	    		    if(board[row1][col1]==FieldState::PLAYER1)
       	    		    {
       	    		    	cout<<"getting in loop"<<endl;
       	    			    board[row1][col1]=FieldState::PLAYER2;
       	    			}

       	    		row1++;
       	    		col1++;
       	    		}
       	    		}
               	}


         // Diagnol: upleft
               	int counterUL=0;
               	if(diagonalUpLeft[1]==2)
                	{
                		for(int j=1;j<sizeOfDiagonalUpLeft;j++)
                		{
                			if(diagonalUpLeft[j]==1)
                			{
                				for(int k=2;k<sizeOfDiagonalUpLeft ;k++)
                				{
                					if(diagonalUpLeft[k]==2){
                						counterUL++;
                					}
                				}
                			}
                			else{
                				counterfalse++;
                			}
                		}
                	}
                	if(diagonalUpLeft[1]==1){
                		for (int j=1;j<sizeOfDiagonalUpLeft;j++ ){
                			if(diagonalUpLeft[j]==2)
                			{
                				counterUL++;
                			}
                			else{
                				counterfalse++;
                			}
                		}
                	}
                	if(diagonalUpLeft[1]==0){
                		counterfalse++;
                	}
                   	if(counterUL)
                   	{
            	    	for(int j=row;j>-1;j--)cout<< "valid move"<< endl;
                       	board[row][col] = (player == 1) ?
                       			FieldState::PLAYER1 : FieldState::PLAYER2;
            	    	//up left
           	    		if(board[row][col]==FieldState::PLAYER2)
           	    		{
           	    			int row1=row-1;
           	    			int col1=col-1;
           	    		while (row1>=0 && col1>=0)
           	    	    {
           	    			cout<<row1<<endl;
           	    			cout<<col1<<endl;
           	    			cout<<static_cast<int>(board[row1][col1])<<endl;
           	    			if(board[row1] [col1 ]== FieldState::PLAYER2)
           	    			{
           	    				cout<<"getting in another loop"<<endl;
           	    			    break;
           	    			}
           	    		    if(board[row1][col1]==FieldState::PLAYER1)
           	    		    {
           	    		    	cout<<"getting in loop"<<endl;
           	    			    board[row1][col1]=FieldState::PLAYER2;
           	    			}

           	    		row1--;
           	    		col1--;
           	    		}
           	    		}
                   	}

          // Diagnol : Downleft
                   	int counterDL=0;
                   	if(diagonalDownLeft[1]==2)
                    	{
                    		for(int j=1;j<sizeOfDiagonalDownLeft;j++)
                    		{
                    			if(diagonalDownLeft[j]==1)
                    			{
                    				for(int k=2 ;k<sizeOfDiagonalDownLeft
                    				;k++)
                    				{
                    					if(diagonalDownLeft[k]==2){
                    						counterDL++;
                    					}
                    				}
                    			}
                    			else{
                    				counterfalse++;
                    			}
                    		}
                    	}
                    	if(diagonalDownLeft[1]==1){
                    		for (int j=1;j<sizeOfDiagonalDownLeft;j++ ){
                    			if(diagonalDownLeft[j]==2)
                    			{
                    				counterDL++;
                    			}
                    			else{
                    				counterfalse++;
                    			}
                    		}
                    	}
                    	if(diagonalDownLeft[1]==0){
                    		counterfalse++;
                    	}
                       	if(counterDL)
                       	{
                	    	cout<< "valid move"<< endl;
                           	board[row][col] = (player == 1) ?
                            FieldState::PLAYER1 : FieldState::PLAYER2;
               	    		if(board[row][col]==FieldState::PLAYER2)
               	    		{
               	    			int row1=row+1;
               	    			int col1=col-1;
               	    		while (row1<size && col1 >=0)
               	    	    {
               	    			cout<<row1<<endl;
               	    			cout<<col1<<endl;
               	    			cout<<static_cast<int>(board[row1][col1])
               	    					<<endl;
               	    			if(board[row1] [col1 ]== FieldState::PLAYER2)
               	    			{
               	    				cout<<"getting in another loop"<<endl;
               	    			    break;
               	    			}
               	    		    if(board[row1][col1]==FieldState::PLAYER1)
               	    		    {
               	    		    	cout<<"getting in loop"<<endl;
               	    			    board[row1][col1]=FieldState::PLAYER2;
               	    			}

               	    		row1++;
               	    		col1--;
               	    		}
               	    		}
                       	}


// Array1
    	cout<<"1st position is :"<<array1[1]<<endl;
    	cout<<"size:"<<array1Size<<endl;
    	int counter1=0;
    	if(array1[1]==2)
    	{
    		for(int j=1;j<array1Size;j++)
    		{
    			if(array1[j]==1)
    			{
    				for(int k=2;k<array1Size;k++)
    				{
    					if(array1[k]==2){
    						counter1++;
    					}
    				}
    			}
    			else{
    				counterfalse++;
    			}
    		}
    	}
    	if(array1[1]==1){
    		for (int j=1;j<array1Size;j++ ){
    			if(array1[j]==2)
    			{
    				counter1++;
    			}
    			else{
    				counterfalse++;
    			}
    		}
    	}
    	if(array1[1]==0){
    		counterfalse++;
    	}
    	if(counter1)
    	{
	    	for(int j=row;j>-1;j--)cout<< "valid move"<< endl;
           	board[row][col] = (player == 1) ?
           			FieldState::PLAYER1 : FieldState::PLAYER2;
        	for(int i=col+1;i<size;i++)
        	{
        		if(board[row][i]==FieldState::PLAYER2)
        		{
        			break;
        		}
        		if(board[row][i]==FieldState::PLAYER1)
        		{
        			board[row][i]=FieldState::PLAYER2;
        		}
        	}
    	}

    	//array 2
    	cout<<"1st position is :"<<array2[1]<<endl;
    	cout<<"size:"<<array2Size<<endl;
    	int counter2=0;
    	    	if(array2[1]==2){
    	    	    		for(int j=1;j<array2Size;j++)
    	    	    		{
    	    	    			if(array2[j]==1)
    	    	    			{
    	    	    				for(int k=2;k<array2Size;k++)
    	    	    				{
    	    	    					if(array2[k]==2)
    	    	    					{
    	    	    						counter2++;
    	    	    					}
    	    	    				}
    	    	    			}
    	    	    			else{
    	    	    				counterfalse++;
    	    	    			}
    	    	    		}
    	    	    	}
    	    	if(array2[1]==1){
    	    	    		for (int j=1;j<array2Size;j++ ){
    	    	    			if(array2[j]==2){
    	    	    				counter2++;
    	    	    				continue;
    	    	    			   }
    	    	    			else{
    	    	    				counterfalse++;
    	    	    				continue;
    	    	    			    }
    	    	    		}
    	    	}
    	    	 if(array2[1]==0){
    	    	    		counterfalse++;
    	    	    	}
    	     	if(counter2)
    	     	{
    	 	    	for(int j=row;j>-1;j--)cout<< "valid move"<< endl;
    	            	board[row][col] = (player == 1) ?
    	            			FieldState::PLAYER1 : FieldState::PLAYER2;
    	            	for(int i=col-1;i<size;i--)
    	            	{
    	            		if(board[row][i]==FieldState::PLAYER2)
    	            		{
    	            			break;
    	            		}
    	            		if(board[row][i]==FieldState::PLAYER1)
    	            		{
    	            			board[row][i]=FieldState::PLAYER2;
    	            		}
    	            	}
    	     	}

// array 3
    	    cout<<"1st position is :"<<array3[1]<<endl;
    	    cout<<"size:"<<array3Size<<endl;
    	    int counter3=0;
    	    if(array3[1]==2){
    	    	    	for(int j=1;j<array3Size;j++)
    	    	    	    {
    	    	    	     if(array3[j]==1)
    	    	    	     {
    	    	    	    	 for(int k=2;k<array3Size;k++)
    	    	    	    	 {
    	    	    	    		if(array3[k]==2)
    	    	    	    		{
    	    	    	    	     counter3++;
    	    	    	    	     }
    	    	    	    	 }
    	    	    	     }
    	    	    	     else{
    	    	    	    	   counterfalse++;
    	    	    	    	  }
    	    	    	     }
    	    }
    	    if(array3[1]==1){
    	    	    	  for (int j=1;j<array3Size;j++ ){
    	    	    	    		if(array3[j]==2)
    	    	    	    			{
    	    	    	    				counter3++;
    	    	    	    			}
    	    	    	    		else{
    	    	    	    				counterfalse++;
    	    	    	    			}
    	    	    	    		}
    	    	    	    	}
    	   if(array3[1]==0){
    	    	    	    counterfalse++;
    	    	    	    }
	     	if(counter3)
	     	{
	 	    	    cout<< "valid move"<< endl;
	            	board[row][col] = (player == 1) ?
	            			FieldState::PLAYER1 : FieldState::PLAYER2;
	            	for(int j=row-1;j>-1;j--)
	            	{
	            		if(board[j][col]==FieldState::PLAYER2)
	            		{
	            			break;
	            		}
	            		if(board[j][col]==FieldState::PLAYER1)
	            		{
	            			board[j][col]=FieldState::PLAYER2;
	            		}
	            	}
	     	}

    	  //array4
    	   cout<<"size:"<<array4Size<<endl;
    	   cout<<"1st position is :"<<array4[1]<<endl;
    	   int counter4=0;
    	   if(array4[1]==2){
    	      for(int j=1;j<array4Size;j++)
    	      {
    	       if(array4[j]==1)
    	        {
    	    	   for(int k=2;k<array4Size;k++){
    	    		   if(array4[k]==2){
    	    			   counter4++;
    	    		   }
    	    	   }
    	        }
    	    	else{
    	    	    counterfalse++;
    	    	    }
    	   	  }
    	    }
    	    if(array4[1]==1){
    	    for (int j=1;j<array4Size;j++ ){
    	    if(array4[j]==2)
    	    {
    	     counter4++;
    	    }
    	    else{
    	    	 counterfalse++;
    	    	}
    	    }
    	    }

    	   if(array4[1]==0){
    	    counterfalse++;
    	  }
	     	if(counter4)
	     	{
	 	    	cout<< "valid move"<< endl;
	            board[row][col] = (player == 1) ?
	            		FieldState::PLAYER1 : FieldState::PLAYER2;
	        	for(int j=row+1;j>-1;j++)
	        	{
	        		if(board[j][col]==FieldState::PLAYER2)
	        		{
	        			break;
	        		}
	        		if(board[j][col]==FieldState::PLAYER1)
	        		{
	        			board[j][col]=FieldState::PLAYER2;
	        		}
	        	}

             }

    if(counter1>0 || counter2>0 || counter3>0 || counter4>0
    		|| counterDL>0 ||counterUL>0 || counterDR>0 || counterUR )
    {

            	return true;
            }
            else
            {
             cout<< "invalid move"<< endl;
             return false;
            }

    delete[] array1;
    delete[] array2;
    delete[] array3;
    delete[] array4;

    }
    }
    return true;
    }


ReversiConsoleView::ReversiConsoleView
(const ReversiBoard& board) : board(board) {}

void ReversiConsoleView::print_board() const {
    for (int i = 0; i < board.getSize(); i++) {
        for (int j = 0; j < board.getSize(); j++) {
           cout << int(board.get_field_state(i, j)) << "\t";
        }
           std::cout << '\n';
    }
}






