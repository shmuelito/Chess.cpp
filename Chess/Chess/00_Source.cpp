/*
This file servers as an example of how to use Pipe.h file.
It is recommended to use the following code in your project, 
in order to read and write information from and to the Backend
*/

#include "Pipe.h"
#include <iostream>
#include <thread>
#include "stdafx.h"
#include "01_Board.h"

using std::cout;
using std::endl;
using std::string;


void main()
{
	srand(time_t(NULL));
	
	Board board; //ctate new class board
	board.intialise_board(); //intialise it

	Pipe p;
	bool isConnect = p.connect();
	
	string ans;
	while (!isConnect)
	{
		cout << "cant connect to graphics" << endl;
		cout << "Do you try to connect again or exit? (0-try again, 1-exit)" << endl;
		std::cin >> ans;

		if (ans == "0")
		{
			cout << "trying connect again.." << endl;
			Sleep(5000);
			isConnect = p.connect();
		}
		else 
		{
			p.close();
			return;
		}
	}
	char msgToGraphics[1024];
	// msgToGraphics should contain the board string accord the protocol
	// YOUR CODE

	strcpy_s(msgToGraphics, "rnbqkbnrpppppppp################################PPPPPPPPRNBQKBNR0"); // just example...
	
	p.sendMessageToGraphics(msgToGraphics);   // send the board string

	// get message from graphics
	string msgFromGraphics = p.getMessageFromGraphics();


	while (msgFromGraphics != "quit")
	{
		int result = 0; // to get the result from valid_Move
		char strResult[2]; // to send the result for frontend 


		result = board.valid_Move(msgFromGraphics); //set in to result the code from valid_Move
		
		// should handle the string the sent from graphics
		// according the protocol. Ex: e2e4           (move e2 to e4)
		if (result == 0 || result == 1 || result == 8) //if the code is valid Move switchTurn to next player 
		{
			board.switchTurn(); 
		}

		board.print_board(); //print the board

		strResult[0] = char(result + '0'); //convert the result to char so i can send it to frontend
		strResult[1] = 0; // last char need to be 0 idk why the frontend work like this 


		// YOUR CODE
		strcpy_s(msgToGraphics, strResult); // msgToGraphics should contain the result of the operation


		// return result to graphics		
		p.sendMessageToGraphics(msgToGraphics);

		// get message from graphics
		msgFromGraphics = p.getMessageFromGraphics();
	}

	p.close();
}