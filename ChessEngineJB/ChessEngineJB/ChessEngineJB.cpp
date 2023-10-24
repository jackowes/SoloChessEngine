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

class Pieces
{
    public:
        uint64_t pawns;
        
}


//likely should do operations 
class ChessBoard
{
    public:

    
        ChessBoard()
        {
            
        }
}

//first I need to be able to produce valid 
int main()
{


    
}

