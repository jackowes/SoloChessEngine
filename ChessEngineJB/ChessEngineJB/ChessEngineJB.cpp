// ChessEngineJB.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <bitset>


#include "ChessEngineJB.h"


typedef struct _move {
    std::string movestr;
    bitboard bboard;
}move;



class Pieces
{
    private:
        bool color;
        bitboard bboard;

        bitboard pawns;
        bitboard rooks;
        bitboard bishops;
        bitboard knights;
        bitboard queens;
        bitboard king;

        uint8_t pawnsNum;
        uint8_t rooksNum;
        uint8_t bishopsNum;
        uint8_t knightsNum;
        uint8_t queensNum;
        uint8_t kingNum;

    public:

        /* Constructors */
        Pieces(bool sColor)
        {
            color = sColor;

            if( color == pieceColor::WHITE )
            {
                pawns = pieceBitboards[WHITEPAWNS];
                rooks = pieceBitboards[WHITEROOKS];
                bishops = pieceBitboards[WHITEBISHOPS];
                knights = pieceBitboards[WHITEKNIGHTS];
                queens = pieceBitboards[WHITEQUEENS];
                king = pieceBitboards[WHITEKING];

            }

            else if ( color == pieceColor::BLACK )
            {
                pawns = pieceBitboards[WHITEPAWNS];
                rooks = pieceBitboards[WHITEROOKS];
                bishops = pieceBitboards[WHITEBISHOPS];
                knights = pieceBitboards[WHITEKNIGHTS];
                queens = pieceBitboards[WHITEQUEENS];
                king = pieceBitboards[WHITEKING];
            }

            
            pawnsNum = 8;
            rooksNum = 2;
            bishopsNum = 2;
            knightsNum = 2;
            queensNum = 1;
            kingNum = 1;
        }



        /* Setters and Getters*/
        bitboard getPawns() const { return pawns; }
        void setPawns(bitboard npawns) { pawns = npawns; }

        bitboard getRooks() const { return rooks; }
        void setRooks(bitboard nrooks) { rooks = nrooks; }

        bitboard getBishops() const { return bishops; }
        void setBishops(bitboard nbishops) { bishops = nbishops; }

        bitboard getKnights() const { return knights; }
        void setKnights(bitboard nknights) { knights = nknights; }

        bitboard getKing() const { return king; }
        void setKing(bitboard nking) { king = nking; }
        
        bitboard getQueens() const { return queens; }
        void setColor(bool nqueens) { queens = nqueens; }
        
        bitboard getBBoard() const { return bboard; }
        void setColor(bool nbboard) { bboard = nbboard; }

        bitboard getColor() const { return color; }
        void setColor(bool ncolor) { color = ncolor; }
        


        /* functionality */
        //returns a list of square indexes that pawns are at
        int * getPawnPositions() const
        {
            int pawnsPos[pawnsNum];
            int t = 0;
            for ( int i = 0; i < sizeof(pawns) * 8; i++ )
            {
                if( pawns & (1ull <<  i))
                {
                    pawnsPos[t] = i;
                    t += 1;
                }
            }
            return pawnsPos;
        }



        
};


// //likely should do operations 
// class ChessBoard
// {
//     public:

    
//         ChessBoard()
//         {
            
//         }
// }

//first I need to be able to produce valid 

//function that takes a bitboard with only one piece and returns that square letter-number
// ul -> "string"

int get_bit_square(bitboard square)
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

bitboard square_to_bit(int square)
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
int main()
{

    for ( int i = WHITEPAWNS; i <= BLACKKING; i++ )
    {
        std::cout << pieceBitboardNames[i] << std::endl;
        printBoard(pieceBitboards[i]);
    }
    
    printBoard(pieceBitboards[BLACKKING]);
    printBoard(pieceBitboards[BLACKKING] >> 8);
    printBoard(pieceBitboards[BLACKKING] >> 8 * 2);

    char t = '1';
    

    //compass
    //we are white and the opposition is playing black
    //North (+ 8) or ( << 8)
    //South (- 8) or ( >> 8)
    //West ( + 9)

    std::string bstring = "";

    for ( char t = '8' ; t > '0'; t-- )
    {
        for ( char c = 'a' ; c < 'i'; c++)
        {
            bstring += c;
            bstring += t;
            bstring += " ";
        }
        bstring += "\n";
    }
    std::cout << bstring << std::endl;


    //initial
    bitboard btest = 1ull << enumSquare::e4;

    std::cout << "e4" << std::endl;
    printBoard(btest);
    btest = movePiece(btest, enumSquare::e4, enumSquare::f6);
    printBoard(btest);


    






    

}


// oct 23rd 2.5 hours 
// got a bit of the board representation done. Incorporated enough so that I can get the squares
// I want and all initial piece positions are ready to go

//Things to do for next time
//Start on the board and pieces classes. Maybe just make it a board class?
// need to be actively thinking about valid move generation.


//1.5 hours more

