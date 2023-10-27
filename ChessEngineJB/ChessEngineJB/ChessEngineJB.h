typedef uint64_t bitboard;

//extern const uint64_t emptySet = 0xFFFFFFFFFFFFFFFF;
#define EMPTYSET 0xFFFFFFFFFFFFFFFF

enum pieceColor {
    BLACK,
    WHITE
};

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

std::string squareString[]{
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

bitboard pieceBitboards[] = {
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