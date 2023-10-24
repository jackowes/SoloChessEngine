// ChessEngineJB.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <bitset>

//function that takes a bitboard with only one piece and returns that square letter-number
// ul -> "string"

int get_bit_square(uint64_t square)
{
    for(int i = 0; i < 64; i++)
    {
        if( square & (1ull << i))
        {
            return i;
        }
    }
    //if there was no bit set return -1. (Should not happen)
    return -1;
}

int square_to_bit(int square)
{
    if ( square >= 0 && square < 64)
    {
        return 1ull << square;
    }
    
    else { return -1; }
}


enum enumSquare {
  h1, g1, f1, e1, d1, c1, b1, a1,
  h2, g2, f2, e2, d2, c2, b2, a2,
  h3, g3, f3, e3, d3, c3, b3, a3,
  h4, g4, f4, e4, d4, c4, b4, a4,
  h5, g5, f5, e5, d5, c5, b5, a5,
  h6, g6, f6, e6, d6, c6, b6, a6,
  h7, g7, f7, e7, d7, c7, b7, a7,
  h8, g8, f8, e8, d8, c8, b8, a8
};

std::string squareString[] {
    "h1", "g1", "f1", "e1", "d1", "c1", "b1", "a1", 
    "h2", "g2", "f2", "e2", "d2", "c2", "b2", "a2", 
    "h3", "g3", "f3", "e3", "d3", "c3", "b3", "a3", 
    "h4", "g4", "f4", "e4", "d4", "c4", "b4", "a4", 
    "h5", "g5", "f5", "e5", "d5", "c5", "b5", "a5", 
    "h6", "g6", "f6", "e6", "d6", "c6", "b6", "a6", 
    "h7", "g7", "f7", "e7", "d7", "c7", "b7", "a7", 
    "h8", "g8", "f8", "e8", "d8", "c8", "b8", "a8", 
};



enum {
    WHITEPAWNS,
    WHITEKNIGHTS,
    WHITEBISHOPS,
    WHITEROOKS,
    WHITEQUEENS,
    WHITEKING,
    BLACKPAWNS,
    BLACKKNIGHTS,
    BLACKBISHOPS,
    BLACKROOKS,
    BLACKQUEENS,
    BLACKKING
};


std::string pieceBitboardNames[] = {
    "WHITEPAWNS",
    "WHITEKNIGHTS",
    "WHITEBISHOPS",
    "WHITEROOKS",
    "WHITEQUEENS",
    "WHITEKING",
    "BLACKPAWNS",
    "BLACKKNIGHTS",
    "BLACKBISHOPS",
    "BLACKROOKS",
    "BLACKQUEENS",
    "BLACKKING"
};

uint64_t pieceBitboards[] = {
    0x000000000000FF00, //WHITEPAWNS
    0x0000000000000042, //WHITEKNIGHTS
    0x0000000000000024, //WHITEBISHOPS
    0x0000000000000081, //WHITEROOKS
    0x0000000000000010, //WHITEQUEENS //000010000
    0x0000000000000008, //WHITEKING
    0x00FF000000000000, //BLACKPAWNS
    0x4200000000000000, //BLACKKNIGHTS
    0x2400000000000000, //BLACKBISHOPS
    0x8100000000000000, //BLACKROOKS
    0x1000000000000000, //BLACKQUEENS
    0x0800000000000000, //BLACKKING

};


class Pieces
{
    public:
        uint64_t pawns;
        uint64_t rooks;
        uint64_t bishops;
        uint64_t knights;
        uint64_t king;
        
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

void printBoard(uint64_t row)
{
    std::string boardstr = "";
    for( int i = 0; i < sizeof(row) * 8; i++ )
    {
        if( row & (1ull << (63 - i)))
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


    std::cout << "test" << std::endl;




    

}


// oct 23rd 2.5 hours 
// got a bit of the board representation done. Incorporated enough so that I can get the squares
// I want and all initial piece positions are ready to go

//Things to do for next time
//Start on the board and pieces classes. Maybe just make it a board class?
// need to be actively thinking about valid move generation.

