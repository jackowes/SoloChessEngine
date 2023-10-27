// ChessEngineJB.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <bitset>
#include <vector>
#include <cstring>


#include "ChessEngineJB.h"


typedef struct _move {
    std::string movestr;
    bitboard bboard;
}move;

class Piece
{
    private:
    public:
        bitboard pieceBitboard;

    

        /* Constructors */
        Piece()
        {
            pieceBitboard = EMPTYSET;
        }

        Piece(bitboard bboard)
        {
            pieceBitboard = bboard;
        }

        /* Getters and Setters */
        bitboard getBitboard() const { return pieceBitboard; }
        void setBitboard(bitboard bboard) { pieceBitboard = bboard; }


        /* functionality */
        /* returns the count of the piece type on the board*/
        int getCount() const
        {
            int c = 0;
            for (int i = 0; i < sizeof(bitboard) * 8; i++)
            {
                if ( pieceBitboard & (1ull << i) )
                {
                    c += 1;
                }
            }
            return c;
        }

    
        //returns a list of square indexes that pawns are at
        std::vector<int> getPositions() const
        {
            std::vector<int> piecePos;
            int c = getCount();
            int t = 0;
            for (int i = 0; i < sizeof(bitboard) * 8; i++)
            {
                if (pieceBitboard & (1ull << i))
                {
                    piecePos.push_back(i);
                }
            }
            return piecePos;
        }
};



class Player
{
    private:
    public:
        bool color;

        Piece pawns;
        Piece rooks;
        Piece bishops;
        Piece knights;
        Piece queens;
        Piece king;

        Piece* pieceArray[6];

    

        /* Constructors */
        Player()
        {
            color = WHITE;

            if (color == pieceColor::WHITE)
            {
                pawns = Piece(pieceBitboards[WHITEPAWNS]);
                rooks = Piece(pieceBitboards[WHITEROOKS]);
                bishops = Piece(pieceBitboards[WHITEBISHOPS]);
                knights = Piece(pieceBitboards[WHITEKNIGHTS]);
                queens = Piece(pieceBitboards[WHITEQUEENS]);
                king = Piece(pieceBitboards[WHITEKING]);

            }
            pieceArray[0] = &pawns;
            pieceArray[1] = &rooks;
            pieceArray[2] = &bishops;
            pieceArray[3] = &knights;
            pieceArray[4] = &queens;
            pieceArray[5] = &king;
            
        }


        Player(bool pColor)
        {
            color = pColor;

            if( color == pieceColor::WHITE )
            {
                pawns = Piece(pieceBitboards[WHITEPAWNS]);
                rooks = Piece(pieceBitboards[WHITEROOKS]);
                bishops = Piece(pieceBitboards[WHITEBISHOPS]);
                knights = Piece(pieceBitboards[WHITEKNIGHTS]);
                queens = Piece(pieceBitboards[WHITEQUEENS]);
                king = Piece(pieceBitboards[WHITEKING]);

            }

            else if ( color == pieceColor::BLACK )
            {
                pawns = Piece(pieceBitboards[BLACKPAWNS]);
                rooks = Piece(pieceBitboards[BLACKROOKS]);
                bishops = Piece(pieceBitboards[BLACKBISHOPS]);
                knights = Piece(pieceBitboards[BLACKKNIGHTS]);
                queens = Piece(pieceBitboards[BLACKQUEENS]);
                king = Piece(pieceBitboards[BLACKKING]);
            }
            pieceArray[0] = &pawns;
            pieceArray[1] = &rooks;
            pieceArray[2] = &bishops;
            pieceArray[3] = &knights;
            pieceArray[4] = &queens;
            pieceArray[5] = &king;

        }



        /* Setters and Getters*/
        bool getColor() const { return color; }
        void setColor(bool ncolor) { color = ncolor; }

        bitboard getPlayerBoard() const 
        { 
            return pawns.getBitboard() | rooks.getBitboard() | bishops.getBitboard() | knights.getBitboard() | queens.getBitboard() | king.getBitboard(); 
        }
        //not sure if I should be adding this setter yet?
};



class Chessboard
{

    private:
    public:
        bool turn;
        Player white;
        Player black;

    


        Chessboard()
        {
            turn = pieceColor::WHITE;
            white = Player(pieceColor::WHITE);
            black = Player(pieceColor::BLACK);

 
        }

        bitboard getBoard() const 
        { 
            return white.getPlayerBoard() | black.getPlayerBoard();
        }

        Player getPlayer(bool color)
        {
            if (color = pieceColor::WHITE)
            {
                return white;
            }
            else if (color = pieceColor::BLACK)
            {
                return black;
            }
        }

        void printBoardStyle()
        {
            char boardstr[64];
            memset(boardstr, '0', 64);
            
            Player players[2];
            players[0] = black;
            players[1] = white;

            int playerCharVal[2] = {32, 0};
            std::vector<int> v;

            for (int j = pieceColor::BLACK; j <= pieceColor::WHITE; j++)
            {
                v = players[j].pawns.getPositions();
                for (int i = 0; i < v.size(); i++)
                {
                    boardstr[v[i]] = 'p' - playerCharVal[j];
                }
                v = players[j].rooks.getPositions();
                for (int i = 0; i < v.size(); i++)
                {
                    boardstr[v[i]] = 'r' - playerCharVal[j];
                }
                v = players[j].bishops.getPositions();
                for (int i = 0; i < v.size(); i++)
                {
                    boardstr[v[i]] = 'b' - playerCharVal[j];
                }
                v = players[j].knights.getPositions();
                for (int i = 0; i < v.size(); i++)
                {
                    boardstr[v[i]] = 'n' - playerCharVal[j];
                }
                v = players[j].queens.getPositions();
                for (int i = 0; i < v.size(); i++)
                {
                    boardstr[v[i]] = 'q' - playerCharVal[j];
                }
                v = players[j].king.getPositions();
                for (int i = 0; i < v.size(); i++)
                {
                    boardstr[v[i]] = 'k' - playerCharVal[j];
                }
            }

            for (int i = sizeof(bitboard) * 8 - 1; i >= 0; i--)
            {
                std::cout << boardstr[i];
                std::cout << " ";
                
                if ((i) % 8 == 0)
                {
                    std::cout << "\n";
                }
            }
        }
};

//first I need to be able to produce valid 

//function that takes a bitboard with only one piece and returns that square letter-number
// ul -> "string"

int bit_to_index(bitboard square)
{
    for (int i = 0; i < 64; i++)
    {
        if (square & (1ull << i))
        {
            return i;
        }
    }
    //if there was no bit set return -1. (Should not happen)
    return -1;
}

bitboard index_to_bit(int square)
{
    if (square >= 0 && square < 64)
    {
        return 1ull << square;
    }

    else { return -1; }
}

bitboard movePiece(bitboard bboard, int fromSquare, int toSquare)
{
    //if there is no piece at the fromSquare then delete it
    if ((bboard & (1ull << fromSquare)) == 0)
    {
        std::cout << "No square at " + squareString[fromSquare] << std::endl;
        return -1;
    }

    //else then move the square and with the not of the square to get rid of it
    // then or with the new square
    else
    {
        bboard &= ~(1ull << fromSquare);
        bboard |= 1ull << toSquare;
        return bboard;
    }
}

void printBoard(bitboard bboard)
{
    std::string boardstr = "";
    for( int i = 0; i < sizeof(bboard) * 8; i++ )
    {
        if( bboard & (1ull << (63 - i)))
        {
            boardstr += "1 ";
        }
        else{ boardstr += "0 "; }

        if ( (i + 1 ) % 8 == 0)
        {
            boardstr += "\n";
        }
    }

    std::cout << boardstr << std::endl;



}


void printValueBoard()
{
    std::string bstring = "";

    for (char t = '8'; t > '0'; t--)
    {
        for (char c = 'a'; c < 'i'; c++)
        {
            bstring += c;
            bstring += t;
            bstring += " ";
        }
        bstring += "\n";
    }
    std::cout << bstring << std::endl;
}


int main()
{

    //compass
    //we are white and the opposition is playing black
    //North (+ 8) or ( << 8)
    //South (- 8) or ( >> 8)
    //West ( + 9)

    printValueBoard();

    Chessboard cboard = Chessboard();

    printBoard(cboard.getBoard());

    printBoard(cboard.white.pawns.getBitboard());

    std::vector<int> vec = cboard.white.pawns.getPositions();


    cboard.printBoardStyle();


    char c = 'p';
    char t = 'P';
    int diff = c - t;

    std::cout << diff;





}


// oct 23rd 2.5 hours 
// got a bit of the board representation done. Incorporated enough so that I can get the squares
// I want and all initial piece positions are ready to go

//Things to do for next time
//Start on the board and pieces classes. Maybe just make it a board class?
// need to be actively thinking about valid move generation.


//1.5 hours more

//another 1 hour trying to figure out how I might gracefully get all these positions

