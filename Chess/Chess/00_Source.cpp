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
	
	Board board;
	board.intialise_board();

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
		int result = 0;
		char strResult[2];


		result = board.valid_Move(msgFromGraphics);
		
		// should handle the string the sent from graphics
		// according the protocol. Ex: e2e4           (move e2 to e4)
		if (result == 0 || result == 1)
		{
			board.switchTurn();
		}

		board.print_board();

		strResult[0] = char(result + '0');
		strResult[1] = 0;


		// YOUR CODE
		strcpy_s(msgToGraphics, strResult); // msgToGraphics should contain the result of the operation


		// return result to graphics		
		p.sendMessageToGraphics(msgToGraphics);

		// get message from graphics
		msgFromGraphics = p.getMessageFromGraphics();
	}

	p.close();
}