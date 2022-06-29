#include<bits/stdc++.h>


#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <deque>
#include <vector>
#include <fstream>
#include <chrono>

#include <string.h> // memcpy on linux

using namespace std;


// Next default values for new objects
//

#define IDI_ICON1                       101
#define _APS_NEXT_RESOURCE_VALUE        102
#define _APS_NEXT_COMMAND_VALUE         40001
#define _APS_NEXT_CONTROL_VALUE         1001
#define _APS_NEXT_SYMED_VALUE           101





#define WHITE_SQUARE 0xDB
#define BLACK_SQUARE 0xFF
#define EMPTY_SQUARE 0x20



std::string next_message="";

const char ach_debug_rooks_only[8][8] =
{
   { 'R',  0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 'R' },
   { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
   { 'R',  0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 'R' },
};

const char ach_debug_bishops_only[8][8] =
{
   { 0x20, 0x20, 'B',  0x20, 0x20, 'B',  0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 'b',  0x20, 0x20, 'b',  0x20, 0x20 },
};

const char ach_debug_queens_only[8][8] =
{
   { 0x20, 0x20, 0x20, 'Q',  0x20, 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 'q',  0x20, 0x20, 0x20, 0x20 },
};

const char ach_debug_kings_only[8][8] =
{
   { 0x20, 0x20, 0x20, 0x20, 'K',  0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20, 'k',  0x20, 0x20, 0x20 },
};

const char ach_debug_check[8][8] =
{
   { 0x20, 0x20, 0x20, 'Q', 'K',   0x20, 0x20, 'R' },
   { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 'q',  'k',  0x20, 0x20, 'R' },
};

const char ach_debug_jeopardy[8][8] =
{
   { 0x20, 0x20, 0x20, 0x20, 'K' , 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
   { 'Q' , 0x20, 0x20, 0x20, 'R' , 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 'B'  },
   { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20, 'k',  0x20, 0x20, 0x20 },
};

const char ach_debug_checkmate[8][8] =
{
   { 'R',  'N',  'B',  'Q',  'K',  'B',  'N',  'R'  },
   { 'P',  'P',  'P',  'P',  0x20, 0x20, 'P',  'P'  },
   { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20,  'n', 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20,  'r',  'r', 0x20, 0x20 },
   { 'p',  'p',  'p',  'p',  0x20,  'p',  'p',  'p' },
   { 0x20,  'n',  'b',  'q',  'k',  'b', 0x20,  0x20},
};

const char ach_debug_not_checkmate[8][8] =
{
   { 'R',  'N',  'B',  'Q',  'K',  'B',  'N',  'R'  },
   { 'P',  'P',  'P',  'P',  'P',  0x20, 'P',  'P'  },
   { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20,  'n', 0x20, 0x20, 0x20 },
   { 0x20, 0x20, 0x20, 0x20, 0x20,  'r', 0x20, 0x20 },
   { 'p',  'p',  'p',  'p',  0x20,  'p',  'p',  'p' },
   { 0x20,  'n',  'b',  'q',  'k',  'b', 0x20,  0x20},
};

// DEBUG
//memcpy(board, ach_debug_rooks_only,  sizeof(char) * 8 * 8);
//memcpy(board, ach_debug_bishops_only, sizeof(char) * 8 * 8);
//memcpy(board, ach_debug_queens_only,  sizeof(char) * 8 * 8);
//memcpy(board, ach_debug_kings_only,   sizeof(char) * 8 * 8);
//memcpy(board, ach_debug_check, sizeof(char) * 8 * 8);



void printEmptyBoard(void)
{
   int CELL = 8;

   for (int i = 0; i < 8; i++)
   {
      // Line starting with WHITE
      if ( i%2 == 0)
      {
         for (int z = 0; z < CELL/2; z++)
         {
            cout << "   ";
            for (int w = 0; w < 4; w++)
            {
               for (int j = 0; j < CELL; j++)
               {
                  cout << char(0xDB);
               }

               for (int j = 0; j < CELL; j++)
               {
                  cout << char(0xFF);
               }
            }
            cout << "\n";
          }
      }
      // Line starting with BLACK
      else
      {
         for (int z = 0; z < CELL/2; z++)
         {
            cout << "   ";
            for (int w = 0; w < 4; w++)
            {
                  for (int j = 0; j < CELL; j++)
                  {
                     cout << char(0xFF);
                  }

                  for (int j = 0; j < CELL; j++)
                  {
                     cout << char(0xDB);
                  }
            }
            cout << "\n";
         }
      }
   }
}

void printChessPiecesUnicode()
{

   std::cout << L'\u2654' << ' ' <<  L'\u2655' << ' ' << L'\u2656' << ' ' << L'\u2657' << ' ' << L'\u2658' << ' ' << L'\u2659' << endl;
   std::cout << L'\u265A' << ' ' <<  L'\u265B' << ' ' << L'\u265C' << ' ' << L'\u265D' << ' ' << L'\u265E' << ' ' << L'\u265F' << endl;
}














class Chess
{
    public:
        static int getPieceColor( char chPiece );

        static bool isWhitePiece( char chPiece );

        static bool isBlackPiece( char chPiece );

        static std::string describePiece( char chPiece );

   enum PieceColor
   {
      WHITE_PIECE = 0,
      BLACK_PIECE = 1
   };

   enum Player
   {
      WHITE_PLAYER = 0,
      BLACK_PLAYER = 1
   };

   enum Side
   {
      QUEEN_SIDE = 2,
      KING_SIDE  = 3
   };

   enum Direction
   {
      HORIZONTAL = 0,
      VERTICAL,
      DIAGONAL,
      L_SHAPE
   };

   struct Position
   {
      int iRow;
      int iColumn;
   };

   struct EnPassant
   {
      bool bApplied;
      Position PawnCaptured;
   };

   struct Castling
   {
      bool bApplied;
      Position rook_before;
      Position rook_after;
   };

   struct Promotion
   {
      bool bApplied;
      //Position  pos;
      char chBefore;
      char chAfter;
   };

   struct IntendedMove
   {
      char chPiece;
      Position from;
      Position to;
   };

   struct Attacker
   {
      Position  pos;
      Direction dir;
   };

   struct UnderAttack
   {
      bool bUnderAttack;
      int iNumAttackers;
      Attacker attacker[9]; //maximum theorical number of attackers
   };

   const char initial_board[8][8] =
   {
      // This represents the pieces on the board.
      // Keep in mind that pieces[0][0] represents A1
      // pieces[1][1] represents B2 and so on.
      // Letters in CAPITAL are white
      { 'R',  'N',  'B',  'Q',  'K',  'B',  'N',  'R' },
      { 'P',  'P',  'P',  'P',  'P',  'P',  'P',  'P' },
      { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
      { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
      { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
      { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
      { 'p',  'p',  'p',  'p',  'p',  'p',  'p',  'p' },
      { 'r',  'n',  'b',  'q',  'k',  'b',  'n',  'r' },
   };
};




class Game : Chess
{
public:
   Game();
   ~Game();

   void movePiece( Position present, Position future, Chess::EnPassant* S_enPassant, Chess::Castling* S_castling, Chess::Promotion* S_promotion );

   void undoLastMove();

   bool undoIsPossible();

   bool castlingAllowed( Side iSide, int iColor );

   char getPieceAtPosition( int iRow, int iColumn );

   char getPieceAtPosition( Position pos );

   char getPiece_considerMove( int iRow, int iColumn, IntendedMove* intended_move = nullptr );

   UnderAttack isUnderAttack( int iRow, int iColumn, int iColor, IntendedMove* pintended_move = nullptr );

   bool isReachable( int iRow, int iColumn, int iColor );

   bool isSquareOccupied( int iRow, int iColumn );

   bool isPathFree( Position startingPos, Position finishingPos, int iDirection );

   bool canBeBlocked( Position startingPos, Position finishinPos, int iDirection );

   bool isCheckMate();

   bool isKingInCheck( int iColor, IntendedMove* intended_move = nullptr );

   bool playerKingInCheck( IntendedMove* intended_move = nullptr );

   bool wouldKingBeInCheck( char chPiece, Position present, Position future, EnPassant* S_enPassant );

   Position findKing( int iColor );

   void changeTurns( void );

   bool isFinished( void );

   int getCurrentTurn( void );

   int getOpponentColor( void );

   void parseMove( string move, Position* pFrom, Position* pTo, char* chPromoted = nullptr );

   void logMove( std::string &to_record );

   string getLastMove( void );

   void deleteLastMove( void );

   // Save all the moves
   struct Round
   {
      string white_move;
      string black_move;
   };

   //std::deque<std::string> moves;
   std::deque<Round> rounds;

   // Save the captured pieces
   std::vector<char> white_captured;
   std::vector<char> black_captured;

private:

   // Represent the pieces in the board
   char board[8][8];

   // Undo is possible?
   struct Undo
   {
      bool bCanUndo;
      bool bCapturedLastMove;

      bool bCastlingKingSideAllowed;
      bool bCastlingQueenSideAllowed;

      EnPassant en_passant;
      Castling  castling;
      Promotion promotion;
   } m_undo;

   // Castling requirements
   bool m_bCastlingKingSideAllowed[2];
   bool m_bCastlingQueenSideAllowed[2];

   // Holds the current turn
   int  m_CurrentTurn;

   // Has the game finished already?
   bool m_bGameFinished;
};















int Chess::getPieceColor(char chPiece)
{
   if (isupper(chPiece))
   {
      return WHITE_PIECE;
   }
   else
   {
      return BLACK_PIECE;
   }
}

bool Chess::isWhitePiece(char chPiece)
{
   return getPieceColor(chPiece) == Chess::WHITE_PIECE ? true : false;
}

bool Chess::isBlackPiece(char chPiece)
{
   return getPieceColor(chPiece) == Chess::BLACK_PIECE ? true : false;
}

std::string Chess::describePiece(char chPiece)
   {
      std::string description;

      if (isWhitePiece(chPiece))
      {
         description += "White ";
      }
      else
      {
         description += "Black ";
      }

      switch (toupper(chPiece))
      {
         case 'P':
         {
            description += "pawn";
         }
         break;

         case 'N':
         {
            description += "knight";
         }
         break;

         case 'B':
         {
            description += "bishop";
         }
         break;

         case 'R':
         {
            description += "rook";
         }
         break;

         case 'Q':
         {
            description += "queen";
         }
         break;

         default:
         {
            description += "unknow piece";
         }
         break;
      }

      return description;
   }


// -------------------------------------------------------------------
// Game class
// -------------------------------------------------------------------
Game::Game()
{
   // White player always starts
   m_CurrentTurn = WHITE_PLAYER;

   // Game on!
   m_bGameFinished = false;

   // Nothing has happend yet
   m_undo.bCapturedLastMove         = false;
   m_undo.bCanUndo                  = false;
   m_undo.bCastlingKingSideAllowed  = false;
   m_undo.bCastlingQueenSideAllowed = false;
   m_undo.en_passant.bApplied       = false;
   m_undo.castling.bApplied         = false;

   // Initial board settings
   memcpy(board, initial_board, sizeof(char) * 8 * 8);

   // Castling is allowed (to each side) until the player moves the king or the rook
   m_bCastlingKingSideAllowed[WHITE_PLAYER]  = true;
   m_bCastlingKingSideAllowed[BLACK_PLAYER]  = true;

   m_bCastlingQueenSideAllowed[WHITE_PLAYER] = true;
   m_bCastlingQueenSideAllowed[BLACK_PLAYER] = true;
}

Game::~Game()
{
   white_captured.clear();
   black_captured.clear();
   rounds.clear();
}

void Game::movePiece(Position present, Position future, Chess::EnPassant* S_enPassant, Chess::Castling* S_castling, Chess::Promotion* S_promotion)
{
   // Get the piece to be moved
   char chPiece = getPieceAtPosition(present);

   // Is the destination square occupied?
   char chCapturedPiece = getPieceAtPosition(future);

   // So, was a piece captured in this move?
   if (0x20 != chCapturedPiece)
   {
      if (WHITE_PIECE == getPieceColor(chCapturedPiece))
      {
         // A white piece was captured
         white_captured.push_back(chCapturedPiece);
      }
      else
      {
         // A black piece was captured
         black_captured.push_back(chCapturedPiece);
      }

      // Set Undo structure. If a piece was captured, then no "en passant" move performed
      m_undo.bCapturedLastMove = true;

      // Reset m_undo.castling
      memset( &m_undo.en_passant, 0, sizeof( Chess::EnPassant ));
   }
   else if (true == S_enPassant->bApplied)
   {
      char chCapturedEP = getPieceAtPosition(S_enPassant->PawnCaptured.iRow, S_enPassant->PawnCaptured.iColumn);

      if (WHITE_PIECE == getPieceColor(chCapturedEP))
      {
         // A white piece was captured
         white_captured.push_back(chCapturedEP);
      }
      else
      {
         // A black piece was captured
         black_captured.push_back(chCapturedEP);
      }

      // Now, remove the captured pawn
      board[S_enPassant->PawnCaptured.iRow][S_enPassant->PawnCaptured.iColumn] = EMPTY_SQUARE;

      // Set Undo structure as piece was captured and "en passant" move was performed
      m_undo.bCapturedLastMove = true;
      memcpy(&m_undo.en_passant, S_enPassant, sizeof(Chess::EnPassant));
   }
   else
   {
      m_undo.bCapturedLastMove   = false;

      // Reset m_undo.castling
      memset( &m_undo.en_passant, 0, sizeof( Chess::EnPassant ));
   }

   // Remove piece from present position
   board[present.iRow][present.iColumn] = EMPTY_SQUARE;

   // Move piece to new position
   if ( true == S_promotion->bApplied )
   {
      board[future.iRow][future.iColumn] = S_promotion->chAfter;

      // Set Undo structure as a promotion occured
      memcpy(&m_undo.promotion, S_promotion, sizeof(Chess::Promotion));
   }
   else
   {
      board[future.iRow][future.iColumn] = chPiece;

      // Reset m_undo.promotion
      memset( &m_undo.promotion, 0, sizeof( Chess::Promotion ));
   }

   // Was it a castling move?
   if ( S_castling->bApplied == true  )
   {
      // The king was already move, but we still have to move the rook to 'jump' the king
      char chPiece = getPieceAtPosition(S_castling->rook_before.iRow, S_castling->rook_before.iColumn);

      // Remove the rook from present position
      board[S_castling->rook_before.iRow][S_castling->rook_before.iColumn] = EMPTY_SQUARE;

      // 'Jump' into to new position
      board[S_castling->rook_after.iRow][S_castling->rook_after.iColumn] = chPiece;

      // Write this information to the m_undo struct
      memcpy(&m_undo.castling, S_castling, sizeof(Chess::Castling));

      // Save the 'CastlingAllowed' information in case the move is undone
      m_undo.bCastlingKingSideAllowed  = m_bCastlingKingSideAllowed[getCurrentTurn()] ;
      m_undo.bCastlingQueenSideAllowed = m_bCastlingQueenSideAllowed[getCurrentTurn()];
   }
   else
   {
      // Reset m_undo.castling
      memset( &m_undo.castling, 0, sizeof( Chess::Castling ));
   }

   // Castling requirements
   if ( 'K' == toupper(chPiece) )
   {
      // After the king has moved once, no more castling allowed
      m_bCastlingKingSideAllowed[getCurrentTurn()]  = false;
      m_bCastlingQueenSideAllowed[getCurrentTurn()] = false;
   }
   else if ('R' == toupper(chPiece) )
   {
      // If the rook moved from column 'A', no more castling allowed on the queen side
      if ( 0 == present.iColumn )
      {
         m_bCastlingQueenSideAllowed[getCurrentTurn()] = false;
      }

      // If the rook moved from column 'A', no more castling allowed on the queen side
      else if ( 7 == present.iColumn )
      {
         m_bCastlingKingSideAllowed[getCurrentTurn()] = false;
      }
   }

   // Change turns
   changeTurns();

   // This move can be undone
   m_undo.bCanUndo = true;
}

void Game::undoLastMove()
{
   string last_move = getLastMove();

   // Parse the line
   Chess::Position from;
   Chess::Position to;
   parseMove(last_move, &from, &to);

   // Since we want to undo a move, we will be moving the piece from (iToRow, iToColumn) to (iFromRow, iFromColumn)
   char chPiece = getPieceAtPosition(to.iRow, to.iColumn);

   // Moving it back
   // If there was a castling
   if ( true == m_undo.promotion.bApplied )
   {
      board[from.iRow][from.iColumn] = m_undo.promotion.chBefore;
   }
   else
   {
      board[from.iRow][from.iColumn] = chPiece;
   }

   // Change turns
   changeTurns();

   // If a piece was captured, move it back to the board
   if (m_undo.bCapturedLastMove)
   {
      // Let's retrieve the last captured piece
      char chCaptured;

      // Since we already changed turns back, it means we should we pop a piece from the oponents vector
      if (WHITE_PLAYER == m_CurrentTurn)
      {
         chCaptured = black_captured.back();
         black_captured.pop_back();
      }
      else
      {
         chCaptured = white_captured.back();
         white_captured.pop_back();
      }

      // Move the captured piece back. Was this an "en passant" move?
      if (m_undo.en_passant.bApplied)
      {
         // Move the captured piece back
         board[m_undo.en_passant.PawnCaptured.iRow][m_undo.en_passant.PawnCaptured.iColumn] = chCaptured;

         // Remove the attacker
         board[to.iRow][to.iColumn] = EMPTY_SQUARE;
      }
      else
      {
         board[to.iRow][to.iColumn] = chCaptured;
      }
   }
   else
   {
      board[to.iRow][to.iColumn] = EMPTY_SQUARE;
   }

   // If there was a castling
   if ( m_undo.castling.bApplied )
   {
      char chRook = getPieceAtPosition(m_undo.castling.rook_after.iRow, m_undo.castling.rook_after.iColumn);

      // Remove the rook from present position
      board[m_undo.castling.rook_after.iRow][m_undo.castling.rook_after.iColumn] = EMPTY_SQUARE;

      // 'Jump' into to new position
      board[m_undo.castling.rook_before.iRow][m_undo.castling.rook_before.iColumn] = chRook;

      // Restore the values of castling allowed or not
      m_bCastlingKingSideAllowed[getCurrentTurn()]  = m_undo.bCastlingKingSideAllowed;
      m_bCastlingQueenSideAllowed[getCurrentTurn()] = m_undo.bCastlingQueenSideAllowed;
   }

   // Clean m_undo struct
   m_undo.bCanUndo             = false;
   m_undo.bCapturedLastMove    = false;
   m_undo.en_passant.bApplied  = false;
   m_undo.castling.bApplied    = false;
   m_undo.promotion.bApplied   = false;

   // If it was a checkmate, toggle back to game not finished
   m_bGameFinished = false;

   // Finally, remove the last move from the list
   deleteLastMove();
}

bool Game::undoIsPossible()
{
   return m_undo.bCanUndo;
}

bool Game::castlingAllowed(Side iSide, int iColor)
{
   if ( QUEEN_SIDE == iSide )
   {
      return m_bCastlingQueenSideAllowed[iColor];
   }
   else //if ( KING_SIDE == iSide )
   {
      return m_bCastlingKingSideAllowed[iColor];
   }
}

char Game::getPieceAtPosition(int iRow, int iColumn)
{
   return board[iRow][iColumn];
}

char Game::getPieceAtPosition(Position pos)
{
   return board[pos.iRow][pos.iColumn];
}

char Game::getPiece_considerMove(int iRow, int iColumn, IntendedMove* intended_move)
{
   char chPiece;

   // If there is no intended move, just return the current position of the board
   if (nullptr == intended_move)
   {
      chPiece = getPieceAtPosition(iRow, iColumn);
   }
   else
   {
      // In this case, we are trying to understand what WOULD happed if the move was made,
      // so we consider a move that has not been made yet
      if (intended_move->from.iRow == iRow && intended_move->from.iColumn == iColumn)
      {
         // The piece wants to move from that square, so it would be empty
         chPiece = EMPTY_SQUARE;
      }
      else if (intended_move->to.iRow == iRow && intended_move->to.iColumn == iColumn)
      {
         // The piece wants to move to that square, so return the piece
         chPiece = intended_move->chPiece;
      }
      else
      {
         chPiece = getPieceAtPosition(iRow, iColumn);
      }
   }

   return chPiece;
}

Chess::UnderAttack Game::isUnderAttack(int iRow, int iColumn, int iColor, IntendedMove* pintended_move)
{
   UnderAttack attack = { 0 };

   // a) Direction: HORIZONTAL
   {
      // Check all the way to the right
      for (int i = iColumn + 1; i < 8; i++)
      {
         char chPieceFound = getPiece_considerMove(iRow, i, pintended_move);
         if (EMPTY_SQUARE == chPieceFound)
         {
            // This square is empty, move on
            continue;
         }

         if ( iColor == getPieceColor(chPieceFound) )
         {
            // This is a piece of the same color, so no problem
            break;
         }
         else if ( (toupper(chPieceFound) == 'Q') ||
                   (toupper(chPieceFound) == 'R') )
         {
            // There is a queen or a rook to the right, so the piece is in jeopardy
            attack.bUnderAttack = true;
            attack.iNumAttackers += 1;

            attack.attacker[attack.iNumAttackers-1].pos.iRow = iRow;
            attack.attacker[attack.iNumAttackers-1].pos.iColumn = i;
            attack.attacker[attack.iNumAttackers-1].dir = HORIZONTAL;
            break;
         }
         else
         {
            // There is a piece that does not attack horizontally, so no problem
            break;
         }
      }

      // Check all the way to the left
      for (int i = iColumn - 1; i >= 0; i--)
      {
         char chPieceFound = getPiece_considerMove(iRow, i, pintended_move);
         if (EMPTY_SQUARE == chPieceFound)
         {
            // This square is empty, move on
            continue;
         }

         if  (iColor == getPieceColor(chPieceFound) )
         {
            // This is a piece of the same color, so no problem
            break;
         }
         else if ( (toupper(chPieceFound) == 'Q') ||
                   (toupper(chPieceFound) == 'R') )
         {
            // There is a queen or a rook to the right, so the piece is in jeopardy
            attack.bUnderAttack = true;
            attack.iNumAttackers += 1;

            attack.attacker[attack.iNumAttackers-1].pos.iRow    = iRow;
            attack.attacker[attack.iNumAttackers-1].pos.iColumn = i;
            attack.attacker[attack.iNumAttackers-1].dir = HORIZONTAL;
            break;
         }
         else
         {
            // There is a piece that does not attack horizontally, so no problem
            break;
         }
      }
   }

   // b) Direction: VERTICAL
   {
      // Check all the way up
      for (int i = iRow + 1; i < 8; i++)
      {
         char chPieceFound = getPiece_considerMove(i, iColumn, pintended_move);
         if (EMPTY_SQUARE == chPieceFound)
         {
            // This square is empty, move on
            continue;
         }

         if ( iColor == getPieceColor(chPieceFound) )
         {
            // This is a piece of the same color, so no problem
            break;
         }
         else if ( (toupper(chPieceFound) == 'Q') ||
                   (toupper(chPieceFound) == 'R')  )
         {
            // There is a queen or a rook to the right, so the piece is in jeopardy
            attack.bUnderAttack = true;
            attack.iNumAttackers += 1;

            attack.attacker[attack.iNumAttackers-1].pos.iRow    = i;
            attack.attacker[attack.iNumAttackers-1].pos.iColumn = iColumn;
            attack.attacker[attack.iNumAttackers-1].dir = VERTICAL;
            break;
         }
         else
         {
            // There is a piece that does not attack vertically, so no problem
            break;
         }
      }

      // Check all the way down
      for (int i = iRow - 1; i >= 0; i--)
      {
         char chPieceFound = getPiece_considerMove(i, iColumn, pintended_move);
         if (EMPTY_SQUARE == chPieceFound)
         {
            // This square is empty, move on
            continue;
         }

         if ( iColor == getPieceColor(chPieceFound) )
         {
            // This is a piece of the same color, so no problem
            break;
         }
         else if ((toupper(chPieceFound) == 'Q') ||
                  (toupper(chPieceFound) == 'R') )
         {
            // There is a queen or a rook to the right, so the piece is in jeopardy
            attack.bUnderAttack = true;
            attack.iNumAttackers += 1;

            attack.attacker[attack.iNumAttackers-1].pos.iRow    = i;
            attack.attacker[attack.iNumAttackers-1].pos.iColumn = iColumn;
            attack.attacker[attack.iNumAttackers-1].dir = VERTICAL;
            break;
         }
         else
         {
            // There is a piece that does not attack vertically, so no problem
            break;
         }
      }
   }

   // c) Direction: DIAGONAL
   {
      // Check the diagonal up-right
      for (int i = iRow + 1, j = iColumn + 1; i < 8 && j < 8; i++, j++)
      {
         char chPieceFound = getPiece_considerMove(i, j, pintended_move);
         if (EMPTY_SQUARE == chPieceFound)
         {
            // This square is empty, move on
            continue;
         }

         if ( iColor == getPieceColor(chPieceFound) )
         {
            // This is a piece of the same color, so no problem
            break;
         }
         else if ( (toupper(chPieceFound) == 'P' ) &&
                   (   i   == iRow    + 1        ) &&
                   (   j   == iColumn + 1        ) &&
                   (iColor == WHITE_PIECE ) )
         {
            // A pawn only puts another piece in jeopardy if it's (diagonally) right next to it
            attack.bUnderAttack = true;
            attack.iNumAttackers += 1;

            attack.attacker[attack.iNumAttackers-1].pos.iRow    = i;
            attack.attacker[attack.iNumAttackers-1].pos.iColumn = j;
            attack.attacker[attack.iNumAttackers-1].dir = DIAGONAL;
            break;
         }
         else if ( (toupper(chPieceFound) == 'Q') ||
                   (toupper(chPieceFound) == 'B'))
         {
            // There is a queen or a bishop in that direction, so the piece is in jeopardy
            attack.bUnderAttack = true;
            attack.iNumAttackers += 1;

            attack.attacker[attack.iNumAttackers-1].pos.iRow    = i;
            attack.attacker[attack.iNumAttackers-1].pos.iColumn = j;
            attack.attacker[attack.iNumAttackers-1].dir = DIAGONAL;
            break;
         }
         else
         {
            // There is a piece that does not attack diagonally, so no problem
            break;
         }
      }

      // Check the diagonal up-left
      for (int i = iRow + 1, j = iColumn - 1; i < 8 && j > 0; i++, j--)
      {
         char chPieceFound = getPiece_considerMove(i, j, pintended_move);
         if (EMPTY_SQUARE == chPieceFound)
         {
            // This square is empty, move on
            continue;
         }

         if ( iColor == getPieceColor(chPieceFound) )
         {
            // This is a piece of the same color, so no problem
            break;
         }
         else if ( (toupper(chPieceFound) == 'P' ) &&
                   (   i   == iRow    + 1        ) &&
                   (   j   == iColumn - 1        ) &&
                   (iColor == WHITE_PIECE ) )
         {
            // A pawn only puts another piece in jeopardy if it's (diagonally) right next to it
            attack.bUnderAttack = true;
            attack.iNumAttackers += 1;

            attack.attacker[attack.iNumAttackers-1].pos.iRow    = i;
            attack.attacker[attack.iNumAttackers-1].pos.iColumn = j;
            attack.attacker[attack.iNumAttackers-1].dir = DIAGONAL;
            break;
         }
         else if ( (toupper(chPieceFound) == 'Q') ||
                   (toupper(chPieceFound) == 'B'))
         {
            // There is a queen or a bishop in that direction, so the piece is in jeopardy
            attack.bUnderAttack = true;
            attack.iNumAttackers += 1;

            attack.attacker[attack.iNumAttackers-1].pos.iRow    = i;
            attack.attacker[attack.iNumAttackers-1].pos.iColumn = j;
            attack.attacker[attack.iNumAttackers-1].dir = DIAGONAL;
            break;
         }
         else
         {
            // There is a piece that does not attack diagonally, so no problem
            break;
         }
      }

      // Check the diagonal down-right
      for (int i = iRow - 1, j = iColumn + 1; i > 0 && j < 8; i--, j++)
      {
         char chPieceFound = getPiece_considerMove(i, j, pintended_move);
         if (EMPTY_SQUARE == chPieceFound)
         {
            // This square is empty, move on
            continue;
         }

         if ( iColor == getPieceColor(chPieceFound) )
         {
            // This is a piece of the same color, so no problem
            break;
         }
         else if ( (toupper(chPieceFound) == 'P' ) &&
                   (   i   == iRow    - 1        ) &&
                   (   j   == iColumn + 1        ) &&
                   (iColor == BLACK_PIECE ) )
         {
            // A pawn only puts another piece in jeopardy if it's (diagonally) right next to it
            attack.bUnderAttack = true;
            attack.iNumAttackers += 1;

            attack.attacker[attack.iNumAttackers-1].pos.iRow    = i;
            attack.attacker[attack.iNumAttackers-1].pos.iColumn = j;
            attack.attacker[attack.iNumAttackers-1].dir = DIAGONAL;
            break;
         }
         else if ( (toupper(chPieceFound) == 'Q') ||
                   (toupper(chPieceFound) == 'B') )
         {
            // There is a queen or a bishop in that direction, so the piece is in jeopardy
            attack.bUnderAttack = true;
            attack.iNumAttackers += 1;

            attack.attacker[attack.iNumAttackers-1].pos.iRow    = i;
            attack.attacker[attack.iNumAttackers-1].pos.iColumn = j;
            attack.attacker[attack.iNumAttackers-1].dir = DIAGONAL;
            break;
         }
         else
         {
            // There is a piece that does not attack diagonally, so no problem
            break;
         }
      }

      // Check the diagonal down-left
      for (int i = iRow - 1, j = iColumn - 1; i > 0 && j > 0; i--, j--)
      {
         char chPieceFound = getPiece_considerMove(i, j, pintended_move);
         if (EMPTY_SQUARE == chPieceFound)
         {
            // This square is empty, move on
            continue;
         }

         if ( iColor == getPieceColor(chPieceFound) )
         {
            // This is a piece of the same color, so no problem
            break;
         }
         else if ( (toupper(chPieceFound) == 'P' ) &&
                   (   i   == iRow    - 1        ) &&
                   (   j   == iColumn - 1        ) &&
                   (iColor == BLACK_PIECE ) )
         {
            // A pawn only puts another piece in jeopardy if it's (diagonally) right next to it
            attack.bUnderAttack = true;
            attack.iNumAttackers += 1;

            attack.attacker[attack.iNumAttackers-1].pos.iRow    = i;
            attack.attacker[attack.iNumAttackers-1].pos.iColumn = j;
            attack.attacker[attack.iNumAttackers-1].dir = DIAGONAL;
            break;
         }
         else if ( (toupper(chPieceFound) == 'Q') ||
                     (toupper(chPieceFound) == 'B') )
         {
            // There is a queen or a bishop in that direction, so the piece is in jeopardy
            attack.bUnderAttack = true;
            attack.iNumAttackers += 1;

            attack.attacker[attack.iNumAttackers-1].pos.iRow    = i;
            attack.attacker[attack.iNumAttackers-1].pos.iColumn = j;
            attack.attacker[attack.iNumAttackers-1].dir = DIAGONAL;
            break;
         }
         else
         {
            // There is a piece that does not attack diagonally, so no problem
            break;
         }
      }
   }

   // d) Direction: L_SHAPED
   {
      // Check if the piece is put in jeopardy by a knigh

      Position knight_moves[8] = { {  1, -2 }, {  2, -1 }, {  2, 1 }, {  1, 2 },
                                   { -1, -2 }, { -2, -1 }, { -2, 1 }, { -1, 2 } };
      for (int i = 0; i < 8; i++)
      {
         int iRowToTest    = iRow    + knight_moves[i].iRow;
         int iColumnToTest = iColumn + knight_moves[i].iColumn;

         if (iRowToTest < 0 || iRowToTest > 7 || iColumnToTest < 0 || iColumnToTest > 7)
         {
            // This square does not even exist, so no need to test
            continue;
         }

         char chPieceFound = getPiece_considerMove(iRowToTest, iColumnToTest, pintended_move);
         if (EMPTY_SQUARE == chPieceFound)
         {
            // This square is empty, move on
            continue;
         }

         if (iColor == getPieceColor(chPieceFound))
         {
            // This is a piece of the same color, so no problem
            continue;
         }
         else if ( (toupper(chPieceFound) == 'N') )
         {
            attack.bUnderAttack = true;
            attack.iNumAttackers += 1;

            attack.attacker[attack.iNumAttackers-1].pos.iRow    = iRowToTest;
            attack.attacker[attack.iNumAttackers-1].pos.iColumn = iColumnToTest;
            break;
         }
      }
   }

   return attack;
}

bool Game::isReachable( int iRow, int iColumn, int iColor )
{
   bool bReachable = false;

   // a) Direction: HORIZONTAL
   {
      // Check all the way to the right
      for (int i = iColumn + 1; i < 8; i++)
      {
         char chPieceFound = getPieceAtPosition(iRow, i);
         if (EMPTY_SQUARE == chPieceFound)
         {
            // This square is empty, move on
            continue;
         }

         if ( iColor == getPieceColor(chPieceFound) )
         {
            // This is a piece of the same color
            break;
         }
         else if ( (toupper(chPieceFound) == 'Q') ||
                   (toupper(chPieceFound) == 'R') )
         {
            // There is a queen or a rook to the right, so the square is reachable
            bReachable = true;
            break;
         }
         else
         {
            // There is a piece that does not move horizontally
            break;
         }
      }

      // Check all the way to the left
      for (int i = iColumn - 1; i >= 0; i--)
      {
         char chPieceFound = getPieceAtPosition(iRow, i);
         if (EMPTY_SQUARE == chPieceFound)
         {
            // This square is empty, move on
            continue;
         }

         if  (iColor == getPieceColor(chPieceFound) )
         {
            // This is a piece of the same color
            break;
         }
         else if ( (toupper(chPieceFound) == 'Q') ||
                   (toupper(chPieceFound) == 'R') )
         {
            // There is a queen or a rook to the left, so the square is reachable
            bReachable = true;
            break;
         }
         else
         {
            // There is a piece that does not move horizontally
            break;
         }
      }
   }

   // b) Direction: VERTICAL
   {
      // Check all the way up
      for (int i = iRow + 1; i < 8; i++)
      {
         char chPieceFound = getPieceAtPosition(i, iColumn);
         if (EMPTY_SQUARE == chPieceFound)
         {
            // This square is empty, move on
            continue;
         }

         if ( iColor == getPieceColor(chPieceFound) )
         {
            // This is a piece of the same color
            break;
         }
         else if ( (toupper(chPieceFound)       == 'P' )         &&
                   (getPieceColor(chPieceFound) == BLACK_PIECE ) &&
                   ( i  == iRow + 1 )                            )
         {
            // There is a pawn one square up, so the square is reachable
            bReachable = true;
            break;
         }
         else if ( (toupper(chPieceFound) == 'Q') ||
                   (toupper(chPieceFound) == 'R')  )
         {
            // There is a queen or a rook on the way up, so the square is reachable
            bReachable = true;
            break;
         }
         else
         {
            // There is a piece that does not move vertically
            break;
         }
      }

      // Check all the way down
      for (int i = iRow - 1; i >= 0; i--)
      {
         char chPieceFound = getPieceAtPosition(i, iColumn);
         if (EMPTY_SQUARE == chPieceFound)
         {
            // This square is empty, move on
            continue;
         }

         if ( iColor == getPieceColor(chPieceFound) )
         {
            // This is a piece of the same color
            break;
         }
         else if ( (toupper(chPieceFound)       == 'P' )         &&
                   (getPieceColor(chPieceFound) == WHITE_PIECE ) &&
                   ( i  == iRow - 1 )                            )
         {
            // There is a pawn one square down, so the square is reachable
            bReachable = true;
            break;
         }
         else if ((toupper(chPieceFound) == 'Q') ||
                  (toupper(chPieceFound) == 'R') )
         {
            // There is a queen or a rook on the way down, so the square is reachable
            bReachable = true;
            break;
         }
         else
         {
            // There is a piece that does not move vertically
            break;
         }
      }
   }

   // c) Direction: DIAGONAL
   {
      // Check the diagonal up-right
      for (int i = iRow + 1, j = iColumn + 1; i < 8 && j < 8; i++, j++)
      {
         char chPieceFound = getPieceAtPosition(i, j);
         if (EMPTY_SQUARE == chPieceFound)
         {
            // This square is empty, move on
            continue;
         }

         if ( iColor == getPieceColor(chPieceFound) )
         {
            // This is a piece of the same color
            break;
         }
         else if ( (toupper(chPieceFound) == 'Q') ||
                   (toupper(chPieceFound) == 'B'))
         {
            // There is a queen or a bishop in that direction, so the square is reachable
            bReachable = true;
            break;
         }
         else
         {
            // There is a piece that does not move diagonally
            break;
         }
      }

      // Check the diagonal up-left
      for (int i = iRow + 1, j = iColumn - 1; i < 8 && j > 0; i++, j--)
      {
         char chPieceFound = getPieceAtPosition(i, j);
         if (EMPTY_SQUARE == chPieceFound)
         {
            // This square is empty, move on
            continue;
         }

         if ( iColor == getPieceColor(chPieceFound) )
         {
            // This is a piece of the same color
            break;
         }
         else if ( (toupper(chPieceFound) == 'Q') ||
                   (toupper(chPieceFound) == 'B'))
         {
            // There is a queen or a bishop in that direction, so the square is reachable
            bReachable = true;
            break;
         }
         else
         {
            // There is a piece that does not move diagonally
            break;
         }
      }

      // Check the diagonal down-right
      for (int i = iRow - 1, j = iColumn + 1; i > 0 && j < 8; i--, j++)
      {
         char chPieceFound = getPieceAtPosition(i, j);
         if (EMPTY_SQUARE == chPieceFound)
         {
            // This square is empty, move on
            continue;
         }

         if ( iColor == getPieceColor(chPieceFound) )
         {
            // This is a piece of the same color
            break;
         }
         else if ( (toupper(chPieceFound) == 'Q') ||
                   (toupper(chPieceFound) == 'B') )
         {
            // There is a queen or a bishop in that direction, so the square is reachable
            bReachable = true;
            break;
         }
         else
         {
            // There is a piece that does not move diagonally
            break;
         }
      }

      // Check the diagonal down-left
      for (int i = iRow - 1, j = iColumn - 1; i > 0 && j > 0; i--, j--)
      {
         char chPieceFound = getPieceAtPosition(i, j);
         if (EMPTY_SQUARE == chPieceFound)
         {
            // This square is empty, move on
            continue;
         }

         if ( iColor == getPieceColor(chPieceFound) )
         {
            // This is a piece of the same color
            break;
         }
         else if ( (toupper(chPieceFound) == 'Q') ||
                   (toupper(chPieceFound) == 'B') )
         {
            // There is a queen or a bishop in that direction, so the square is reachable
            bReachable = true;
            break;
         }
         else
         {
            // There is a piece that does not move diagonally
            break;
         }
      }
   }

   // d) Direction: L_SHAPED
   {
      // Check if the piece is put in jeopardy by a knigh

      Position knight_moves[8] = { {  1, -2 }, {  2, -1 }, {  2, 1 }, {  1, 2 },
                                   { -1, -2 }, { -2, -1 }, { -2, 1 }, { -1, 2 } };
      for (int i = 0; i < 8; i++)
      {
         int iRowToTest    = iRow    + knight_moves[i].iRow;
         int iColumnToTest = iColumn + knight_moves[i].iColumn;

         if (iRowToTest < 0 || iRowToTest > 7 || iColumnToTest < 0 || iColumnToTest > 7)
         {
            // This square does not even exist, so no need to test
            continue;
         }

         char chPieceFound = getPieceAtPosition(iRowToTest, iColumnToTest);
         if (EMPTY_SQUARE == chPieceFound)
         {
            // This square is empty, move on
            continue;
         }

         if (iColor == getPieceColor(chPieceFound))
         {
            // This is a piece of the same color
            continue;
         }
         else if ( (toupper(chPieceFound) == 'N') )
         {
            bReachable = true;
            break;
         }
      }
   }

   return bReachable;
}

bool Game::isSquareOccupied(int iRow, int iColumn)
{
   bool bOccupied = false;

   if ( 0x20 != getPieceAtPosition(iRow,iColumn) )
   {
      bOccupied = true;
   }

   return bOccupied;
}

bool Game::isPathFree(Position startingPos, Position finishingPos, int iDirection)
{
   bool bFree = false;

   switch(iDirection)
   {
      case Chess::HORIZONTAL:
      {
         // If it is a horizontal move, we can assume the startingPos.iRow == finishingPos.iRow
         // If the piece wants to move from column 0 to column 7, we must check if columns 1-6 are free
         if (startingPos.iColumn == finishingPos.iColumn)
         {
            cout << "Error. Movement is horizontal but column is the same\n";
         }

         // Moving to the right
         else if (startingPos.iColumn < finishingPos.iColumn)
         {
            // Settting bFree as initially true, only inside the cases, guarantees that the path is checked
            bFree = true;

            for (int i = startingPos.iColumn + 1; i < finishingPos.iColumn; i++)
            {
               if (isSquareOccupied(startingPos.iRow, i))
               {
                  bFree = false;
                  cout << "Horizontal path to the right is not clear!\n";
               }
            }
         }

         // Moving to the left
         else //if (startingPos.iColumn > finishingPos.iColumn)
         {
            // Settting bFree as initially true, only inside the cases, guarantees that the path is checked
            bFree = true;

            for (int i = startingPos.iColumn - 1; i > finishingPos.iColumn; i--)
            {
               if (isSquareOccupied(startingPos.iRow, i))
               {
                  bFree = false;
                  cout << "Horizontal path to the left is not clear!\n";
               }
            }
         }
      }
      break;

      case Chess::VERTICAL:
      {
         // If it is a vertical move, we can assume the startingPos.iColumn == finishingPos.iColumn
         // If the piece wants to move from column 0 to column 7, we must check if columns 1-6 are free
         if (startingPos.iRow == finishingPos.iRow)
         {
            cout << "Error. Movement is vertical but row is the same\n";
           throw("Error. Movement is vertical but row is the same");
         }

         // Moving up
         else if (startingPos.iRow < finishingPos.iRow)
         {
            // Settting bFree as initially true, only inside the cases, guarantees that the path is checked
            bFree = true;

            for (int i = startingPos.iRow + 1; i < finishingPos.iRow; i++)
            {
               if ( isSquareOccupied(i, startingPos.iColumn) )
               {
                  bFree = false;
                  cout << "Vertical path up is not clear!\n";
               }
            }
         }

         // Moving down
         else //if (startingPos.iColumn > finishingPos.iRow)
         {
            // Settting bFree as initially true, only inside the cases, guarantees that the path is checked
            bFree = true;

            for (int i = startingPos.iRow - 1; i > finishingPos.iRow; i--)
            {
               if ( isSquareOccupied(i, startingPos.iColumn) )
               {
                  bFree = false;
                  cout << "Vertical path down is not clear!\n";
               }
            }
         }
      }
      break;

      case Chess::DIAGONAL:
      {
         // Moving up and right
         if ( (finishingPos.iRow > startingPos.iRow) && (finishingPos.iColumn > startingPos.iColumn) )
         {
            // Settting bFree as initially true, only inside the cases, guarantees that the path is checked
            bFree = true;

            for (int i = 1; i < abs(finishingPos.iRow - startingPos.iRow); i++)
            {
               if (isSquareOccupied(startingPos.iRow + i, startingPos.iColumn + i))
               {
                  bFree = false;
                  cout << "Diagonal path up-right is not clear!\n";
               }
            }
         }

         // Moving up and left
         else if ( (finishingPos.iRow > startingPos.iRow) && (finishingPos.iColumn < startingPos.iColumn) )
         {
            // Settting bFree as initially true, only inside the cases, guarantees that the path is checked
            bFree = true;

            for (int i = 1; i < abs(finishingPos.iRow - startingPos.iRow); i++)
            {
               if (isSquareOccupied(startingPos.iRow+i, startingPos.iColumn-i))
               {
                  bFree = false;
                  cout << "Diagonal path up-left is not clear!\n";
               }
            }
         }

         // Moving down and right
         else if ( (finishingPos.iRow < startingPos.iRow) && (finishingPos.iColumn > startingPos.iColumn) )
         {
            // Settting bFree as initially true, only inside the cases, guarantees that the path is checked
            bFree = true;

            for (int i = 1; i < abs(finishingPos.iRow - startingPos.iRow); i++)
            {
               if (isSquareOccupied(startingPos.iRow - i, startingPos.iColumn + i))
               {
                  bFree = false;
                  cout << "Diagonal path down-right is not clear!\n";
               }
            }
         }

         // Moving down and left
         else if ( (finishingPos.iRow < startingPos.iRow) && (finishingPos.iColumn < startingPos.iColumn) )
         {
            // Settting bFree as initially true, only inside the cases, guarantees that the path is checked
            bFree = true;

            for (int i = 1; i < abs(finishingPos.iRow - startingPos.iRow); i++)
            {
               if (isSquareOccupied(startingPos.iRow - i, startingPos.iColumn - i))
               {
                  bFree = false;
                  cout << "Diagonal path down-left is not clear!\n";
               }
            }
         }

         else
         {
            throw("Error. Diagonal move not allowed");
         }
      }
      break;
   }

   return bFree;
}

bool Game::canBeBlocked(Position startingPos, Position finishingPos, int iDirection)
{
   bool bBlocked = false;

   Chess::UnderAttack blocker = {0};

   switch(iDirection)
   {
      case Chess::HORIZONTAL:
      {
         // If it is a horizontal move, we can assume the startingPos.iRow == finishingPos.iRow
         // If the piece wants to move from column 0 to column 7, we must check if columns 1-6 are free
         if (startingPos.iColumn == finishingPos.iColumn)
         {
            cout << "Error. Movement is horizontal but column is the same\n";
         }

         // Moving to the right
         else if (startingPos.iColumn < finishingPos.iColumn)
         {
            for (int i = startingPos.iColumn + 1; i < finishingPos.iColumn; i++)
            {
               if ( true == isReachable( startingPos.iRow, i, getOpponentColor() ) )
               {
                  // Some piece can block the way
                  bBlocked = true;
               }
            }
         }

         // Moving to the left
         else //if (startingPos.iColumn > finishingPos.iColumn)
         {
            for (int i = startingPos.iColumn - 1; i > finishingPos.iColumn; i--)
            {
               if ( true == isReachable( startingPos.iRow, i, getOpponentColor() ) )
               {
                  // Some piece can block the way
                  bBlocked = true;
               }
            }
         }
      }
      break;

      case Chess::VERTICAL:
      {
         // If it is a vertical move, we can assume the startingPos.iColumn == finishingPos.iColumn
         // If the piece wants to move from column 0 to column 7, we must check if columns 1-6 are free
         if (startingPos.iRow == finishingPos.iRow)
         {
            cout << "Error. Movement is vertical but row is the same\n";
           throw("Error. Movement is vertical but row is the same");
         }

         // Moving up
         else if (startingPos.iRow < finishingPos.iRow)
         {
            for (int i = startingPos.iRow + 1; i < finishingPos.iRow; i++)
            {
               if ( true == isReachable( i, startingPos.iColumn, getOpponentColor() ) )
               {
                  // Some piece can block the way
                  bBlocked = true;
               }
            }
         }

         // Moving down
         else //if (startingPos.iColumn > finishingPos.iRow)
         {
            for (int i = startingPos.iRow - 1; i > finishingPos.iRow; i--)
            {
               if ( true == isReachable( i, startingPos.iColumn, getOpponentColor() ) )
               {
                  // Some piece can block the way
                  bBlocked = true;
               }
            }
         }
      }
      break;

      case Chess::DIAGONAL:
      {
         // Moving up and right
         if ( (finishingPos.iRow > startingPos.iRow) && (finishingPos.iColumn > startingPos.iColumn) )
         {
            for (int i = 1; i < abs(finishingPos.iRow - startingPos.iRow); i++)
            {
               if ( true == isReachable( startingPos.iRow + i, startingPos.iColumn + i, getOpponentColor() ) )
               {
                  // Some piece can block the way
                  bBlocked = true;
               }
            }
         }

         // Moving up and left
         else if ( (finishingPos.iRow > startingPos.iRow) && (finishingPos.iColumn < startingPos.iColumn) )
         {
            for (int i = 1; i < abs(finishingPos.iRow - startingPos.iRow); i++)
            {
               if ( true == isReachable( startingPos.iRow + i, startingPos.iColumn - i, getOpponentColor() ) )
               {
                  // Some piece can block the way
                  bBlocked = true;
               }
            }
         }

         // Moving down and right
         else if ( (finishingPos.iRow < startingPos.iRow) && (finishingPos.iColumn > startingPos.iColumn) )
         {
            for (int i = 1; i < abs(finishingPos.iRow - startingPos.iRow); i++)
            {
               if ( true == isReachable( startingPos.iRow - i, startingPos.iColumn + i, getOpponentColor() ) )
               {
                  // Some piece can block the way
                  bBlocked = true;
               }
            }
         }

         // Moving down and left
         else if ( (finishingPos.iRow < startingPos.iRow) && (finishingPos.iColumn < startingPos.iColumn) )
         {
            for (int i = 1; i < abs(finishingPos.iRow - startingPos.iRow); i++)
            {
               if ( true == isReachable( startingPos.iRow - i, startingPos.iColumn - i, getOpponentColor() ) )
               {
                  // Some piece can block the way
                  bBlocked = true;
               }
            }
         }

         else
         {
            cout << "Error. Diagonal move not allowed\n";
            throw("Error. Diagonal move not allowed");
         }
      }
      break;
   }

   return bBlocked;
}

bool Game::isCheckMate()
{
   bool bCheckmate = false;

   // 1. First of all, it the king in check?
   if ( false == playerKingInCheck() )
   {
      return false;
   }

   // 2. Can the king move the other square?
   Chess::Position king_moves[8]  = { {  1, -1 },{  1, 0 },{  1,  1 }, { 0,  1 },
                                      { -1,  1 },{ -1, 0 },{ -1, -1 }, { 0, -1 } };

   Chess::Position king = findKing(getCurrentTurn() );

   for (int i = 0; i < 8; i++)
   {
      int iRowToTest    = king.iRow    + king_moves[i].iRow;
      int iColumnToTest = king.iColumn + king_moves[i].iColumn;

      if ( iRowToTest < 0 || iRowToTest > 7 || iColumnToTest < 0 || iColumnToTest > 7 )
      {
         // This square does not even exist, so no need to test
         continue;
      }

      if ( EMPTY_SQUARE != getPieceAtPosition(iRowToTest, iColumnToTest) )
      {
         // That square is not empty, so no need to test
         continue;
      }

      Chess::IntendedMove intended_move;
      intended_move.chPiece      = getPieceAtPosition(king.iRow, king.iColumn);
      intended_move.from.iRow    = king.iRow;
      intended_move.from.iColumn = king.iColumn;
      intended_move.to.iRow      = iRowToTest;
      intended_move.to.iColumn   = iColumnToTest;

      // Now, for every possible move of the king, check if it would be in jeopardy
      // Since the move has already been made, current_game->getCurrentTurn() now will return
      // the next player's color. And it is in fact this king that we want to check for jeopardy
      Chess::UnderAttack king_moved = isUnderAttack( iRowToTest, iColumnToTest, getCurrentTurn(), &intended_move );

      if ( false == king_moved.bUnderAttack )
      {
         // This means there is at least one position when the king would not be in jeopardy, so that's not a checkmate
         return false;
      }
   }

   // 3. Can the attacker be taken or another piece get into the way?
   Chess::UnderAttack king_attacked = isUnderAttack( king.iRow, king.iColumn, getCurrentTurn() );
   if ( 1 == king_attacked.iNumAttackers )
   {
      // Can the attacker be taken?
      Chess::UnderAttack king_attacker = { 0 };
      king_attacker = isUnderAttack( king_attacked.attacker[0].pos.iRow, king_attacked.attacker[0].pos.iColumn, getOpponentColor() );

      if ( true == king_attacker.bUnderAttack )
      {
         // This means that the attacker can be taken, so it's not a checkmate
         return false;
      }
      else
      {
         // Last resort: can any piece get in between the attacker and the king?
         char chAttacker = getPieceAtPosition( king_attacked.attacker[0].pos.iRow, king_attacked.attacker[0].pos.iColumn );

         switch( toupper(chAttacker) )
         {
            case 'P':
            case 'N':
            {
               // If it's a pawn, there's no space in between the attacker and the king
               // If it's a knight, it doesn't matter because the knight can 'jump'
               // So, this is checkmate
               bCheckmate = true;
            }
            break;

            case 'B':
            {
               if ( false == canBeBlocked(king_attacked.attacker[0].pos, king, Chess::DIAGONAL ) )
               {
                  // If no piece can get in the way, it's a checkmate
                  bCheckmate = true;
               }
            }
            break;

            case 'R':
            {
               if ( false == canBeBlocked(king_attacked.attacker[0].pos, king, king_attacked.attacker[0].dir ) )
               {
                  // If no piece can get in the way, it's a checkmate
                  bCheckmate = true;
               }
            }
            break;

            case 'Q':
            {
               if ( false == canBeBlocked(king_attacked.attacker[0].pos, king, king_attacked.attacker[0].dir ) )
               {
                  // If no piece can get in the way, it's a checkmate
                  bCheckmate = true;
               }
            }
            break;


            default:
            {
               throw("!!!!Should not reach here. Invalid piece");
            }
            break;
         }
      }
   }
   else
   {
      // If there is more than one attacker and we reached this point, it's a checkmate
      bCheckmate      = true;
   }

   // If the game has ended, store in the class variable
   m_bGameFinished = bCheckmate;

   return bCheckmate;
}

bool Game::isKingInCheck(int iColor, IntendedMove* pintended_move)
{
   bool bCheck = false;

   Position king = { 0 };

   // Must check if the intended move is to move the king itself
   if ( nullptr != pintended_move && 'K' == toupper( pintended_move->chPiece) )
   {
      king.iRow    = pintended_move->to.iRow;
      king.iColumn = pintended_move->to.iColumn;
   }
   else
   {
      king = findKing( iColor );
   }

   UnderAttack king_attacked = isUnderAttack( king.iRow, king.iColumn, iColor, pintended_move );

   if ( true == king_attacked.bUnderAttack )
   {
      bCheck = true;
   }

   return bCheck;
}

bool Game::playerKingInCheck(IntendedMove* intended_move)
{
   return isKingInCheck( getCurrentTurn(), intended_move);
}

bool Game::wouldKingBeInCheck(char chPiece, Position present, Position future, EnPassant* S_enPassant)
{
   IntendedMove intended_move;

   intended_move.chPiece      = chPiece;
   intended_move.from.iRow    = present.iRow;
   intended_move.from.iColumn = present.iColumn;
   intended_move.to.iRow      = future.iRow;
   intended_move.to.iColumn   = future.iColumn;

   return playerKingInCheck(&intended_move);
}

Chess::Position Game::findKing(int iColor)
{
   char chToLook = (WHITE_PIECE == iColor) ? 'K': 'k';
   Position king = { 0 };

   for (int i = 0; i < 8; i++)
   {
      for (int j = 0; j < 8; j++)
      {
         if ( chToLook == getPieceAtPosition(i, j) )
         {
            king.iRow    = i;
            king.iColumn = j;
         }
      }
   }

   return king;
}

void Game::changeTurns(void)
{
   if (WHITE_PLAYER == m_CurrentTurn)
   {
      m_CurrentTurn = BLACK_PLAYER;
   }
   else
   {
      m_CurrentTurn = WHITE_PLAYER;
   }
}

bool Game::isFinished( void )
{
   return m_bGameFinished;
}

int Game::getCurrentTurn(void)
{
   return m_CurrentTurn;
}

int Game::getOpponentColor(void)
{
   int iColor;

   if (Chess::WHITE_PLAYER == getCurrentTurn())
   {
      iColor = Chess::BLACK_PLAYER;
   }
   else
   {
      iColor = Chess::WHITE_PLAYER;
   }

   return iColor;
}

void Game::parseMove(string move, Position* pFrom, Position* pTo, char* chPromoted)
{
   pFrom->iColumn = move[0];
   pFrom->iRow    = move[1];
   pTo->iColumn   = move[3];
   pTo->iRow      = move[4];

   // Convert columns from ['A'-'H'] to [0x00-0x07]
   pFrom->iColumn = pFrom->iColumn - 'A';
   pTo->iColumn   = pTo->iColumn   - 'A';

   // Convert row from ['1'-'8'] to [0x00-0x07]
   pFrom->iRow  = pFrom->iRow  - '1';
   pTo->iRow    = pTo->iRow    - '1';

   if ( chPromoted != nullptr )
   {
      if ( move[5] == '=' )
      {
         *chPromoted = move[6];
      }
      else
      {
         *chPromoted = EMPTY_SQUARE;
      }
   }
}

void Game::logMove(std::string &to_record)
{
   // If record contains only 5 chracters, add spaces
   // Because when
   if ( to_record.length() == 5 )
   {
      to_record += "  ";
   }

   if ( WHITE_PLAYER == getCurrentTurn() )
   {
      // If this was a white player move, create a new round and leave the black_move empty
      Round round;
      round.white_move = to_record;
      round.black_move = "";

      rounds.push_back(round);
   }
   else
   {
      // If this was a black_move, just update the last Round
      Round round = rounds[rounds.size() - 1];
      round.black_move = to_record;

      // Remove the last round and put it back, now with the black move
      rounds.pop_back();
      rounds.push_back(round);
   }
}

string Game::getLastMove(void)
{
   string last_move;

   // Who did the last move?
   if (BLACK_PLAYER == getCurrentTurn())
   {
      // If it's black's turn now, white had the last move
      last_move = rounds[rounds.size() - 1].white_move;
   }
   else
   {
      // Last move was black's
      last_move = rounds[rounds.size() - 1].black_move;
   }

   return last_move;
}

void Game::deleteLastMove( void )
{
   // Notice we already changed turns back
   if (WHITE_PLAYER == getCurrentTurn())
   {
      // Last move was white's turn, so simply pop from the back
      rounds.pop_back();
   }
   else
   {
      // Last move was black's, so let's
      Round round = rounds[rounds.size() - 1];
      round.black_move = "";

      // Pop last round and put it back, now without the black move
      rounds.pop_back();
      rounds.push_back(round);
   }
}


















void createNextMessage( string msg );
void appendToNextMessage( string msg );
void clearScreen( void );
void printLogo( void );
void printLogo( void );
void printMenu( void );
void printMessage( void );
void printLine( int iLine, int iColor1, int iColor2, Game& game );
void printSituation( Game& game );
void printBoard(Game& game);



void createNextMessage( string msg )
{
   next_message = msg;
}

void appendToNextMessage( string msg )
{
   next_message += msg;
}
void clearScreen(void)
{
   system("cls");
}

void printLogo(void)
{
   cout << "    ======================================\n";
   cout << "       _____ _    _ ______  _____ _____\n";
   cout << "      / ____| |  | |  ____|/ ____/ ____|\n";
   cout << "     | |    | |__| | |__  | (___| (___ \n";
   cout << "     | |    |  __  |  __|  \\___ \\\\___ \\ \n";
   cout << "     | |____| |  | | |____ ____) |___) |\n";
   cout << "     \______|_|  |_|______|_____/_____/\n\n";
   cout << "    ======================================\n\n";
}

void printMenu(void)
{
   cout << "Commands: (N)ew game\t(M)ove \t(U)ndo \t(S)ave \t(L)oad \t(Q)uit \n";
}

void printMessage(void)
{
   cout << next_message << endl;

   next_message = "";
}

void printLine(int iLine, int iColor1, int iColor2, Game& game)
{
   // Example (for CELL = 6):

   //  [6-char]
   //  |______| subline 1
   //  |___Q__| subline 2
   //  |______| subline 3

   // Define the CELL variable here.
   // It represents how many horizontal characters will form one square
   // The number of vertical characters will be CELL/2
   // You can change it to alter the size of the board (an odd number will make the squares look rectangular)
   int CELL = 6;

   // Since the width of the characters BLACK and WHITE is half of the height,
   // we need to use two characters in a row.
   // So if we have CELL characters, we must have CELL/2 sublines
   for (int subLine = 0; subLine < CELL/2; subLine++)
   {
      // A sub-line is consisted of 8 cells, but we can group it
      // in 4 iPairs of black&white
      for (int iPair = 0; iPair < 4; iPair++)
      {
         // First cell of the pair
         for (int subColumn = 0; subColumn < CELL; subColumn++)
         {
            // The piece should be in the "middle" of the cell
            // For 3 sub-lines, in sub-line 1
            // For 6 sub-columns, sub-column 3
            if ( subLine == 1 && subColumn == 3)
            {
               cout << char(game.getPieceAtPosition(iLine, iPair*2) != 0x20 ? game.getPieceAtPosition(iLine, iPair*2) : iColor1);
            }
            else if(iColor1!=0xDB && iColor1!=0xFF ){

               cout << char(iColor1);
            }
            else
            {
               cout << char(0x20);
            }
         }

         // Second cell of the pair
         for (int subColumn = 0; subColumn < CELL; subColumn++)
         {
            // The piece should be in the "middle" of the cell
            // For 3 sub-lines, in sub-line 1
            // For 6 sub-columns, sub-column 3
            if ( subLine == 1 && subColumn == 3)
            {
               cout << char(game.getPieceAtPosition(iLine,iPair*2+1) != 0x20 ? game.getPieceAtPosition(iLine,iPair*2+1) : iColor2);
            }
            else if(iColor2!=0xDB && iColor2!=0xFF ){

               cout << char(iColor2);
            }
            else
            {
               cout << char(0x20);
            }
         }
      }

      // Write the number of the line on the right
      if ( 1 == subLine )
      {
         cout << "   " << iLine+1;
      }

      cout << "\n";

   }
}

void printSituation(Game& game)
{
   // Last moves - print only if at least one move has been made
   if ( 0 != game.rounds.size() )
   {
      cout << "Last moves:\n";

      int iMoves = game.rounds.size();
      int iToShow = iMoves >= 5 ? 5 : iMoves;

      string space = "";

      while( iToShow-- )
      {
         if ( iMoves < 10 )
         {
            // Add an extra hardspace to allign the numbers that are smaller than 10
            space = " ";
         }

         cout << space << iMoves << " ..... " <<  game.rounds[iMoves-1].white_move.c_str() << " | " << game.rounds[iMoves - 1].black_move.c_str() << "\n";
         iMoves--;
      }

      cout << "\n";
   }

   // Captured pieces - print only if at least one piece has been captured
   if ( 0 != game.white_captured.size() || 0 != game.black_captured.size() )
   {
      cout << "---------------------------------------------\n";
      cout << "WHITE captured: ";
      for (unsigned i = 0; i < game.white_captured.size(); i++)
      {
         cout << char(game.white_captured[i]) << " ";
      }
      cout << "\n";

      cout << "black captured: ";
      for (unsigned i = 0; i < game.black_captured.size(); i++)
      {
         cout << char(game.black_captured[i]) << " ";
      }
      cout << "\n";

      cout << "---------------------------------------------\n";
   }

   // Current turn
   cout << "Current turn: " << (game.getCurrentTurn() == Chess::WHITE_PIECE ? "WHITE (upper case)" : "BLACK (lower case)") << "\n\n";

}

void printBoard(Game& game)
{
   cout << "   A     B     C     D     E     F     G     H\n\n";

   for (int iLine = 7; iLine >= 0; iLine--)
   {
      if ( iLine%2 == 0)
      {
         // Line starting with BLACK
         printLine(iLine, BLACK_SQUARE, WHITE_SQUARE, game);
      }

      else
      {
         // Line starting with WHITE
         printLine(iLine, WHITE_SQUARE, BLACK_SQUARE, game);
      }
   }
}





















//---------------------------------------------------------------------------------------
// Global variable
//---------------------------------------------------------------------------------------
Game* current_game = NULL;


//---------------------------------------------------------------------------------------
// Helper
// Auxiliar functions to determine if a move is valid, etc
//---------------------------------------------------------------------------------------
bool isMoveValid(Chess::Position present, Chess::Position future, Chess::EnPassant* S_enPassant, Chess::Castling* S_castling, Chess::Promotion* S_promotion)
{
   bool bValid = false;

   char chPiece = current_game->getPieceAtPosition(present.iRow, present.iColumn);

   // ----------------------------------------------------
   // 1. Is the piece  allowed to move in that direction?
   // ----------------------------------------------------
   switch( toupper(chPiece) )
   {
      case 'P':
      {
         // Wants to move forward
         if ( future.iColumn == present.iColumn )
         {
            // Simple move forward
            if ( (Chess::isWhitePiece(chPiece) && future.iRow == present.iRow + 1) ||
                 (Chess::isBlackPiece(chPiece) && future.iRow == present.iRow - 1) )
            {
               if ( EMPTY_SQUARE == current_game->getPieceAtPosition(future.iRow, future.iColumn) )
               {
                  bValid = true;
               }
            }

            // Double move forward
            else if ( (Chess::isWhitePiece(chPiece) && future.iRow == present.iRow + 2) ||
                      (Chess::isBlackPiece(chPiece) && future.iRow == present.iRow - 2) )
            {
               // This is only allowed if the pawn is in its original place
               if ( Chess::isWhitePiece(chPiece) )
               {
                  if ( EMPTY_SQUARE == current_game->getPieceAtPosition(future.iRow-1, future.iColumn) &&
                       EMPTY_SQUARE == current_game->getPieceAtPosition(future.iRow, future.iColumn)   &&
                                1   == present.iRow )
                  {
                     bValid = true;
                  }
               }
               else // if ( isBlackPiece(chPiece) )
               {
                  if ( EMPTY_SQUARE == current_game->getPieceAtPosition(future.iRow + 1, future.iColumn) &&
                       EMPTY_SQUARE == current_game->getPieceAtPosition(future.iRow, future.iColumn)     &&
                                6   == present.iRow)
                  {
                     bValid = true;
                  }
               }
            }
            else
            {
               // This is invalid
               return false;
            }
         }

         // The "en passant" move
         else if ( (Chess::isWhitePiece(chPiece) && 4 == present.iRow && 5 == future.iRow && 1 == abs(future.iColumn - present.iColumn) ) ||
                   (Chess::isBlackPiece(chPiece) && 3 == present.iRow && 2 == future.iRow && 1 == abs(future.iColumn - present.iColumn) ) )
         {
            // It is only valid if last move of the opponent was a double move forward by a pawn on a adjacent column
            string last_move = current_game->getLastMove();

            // Parse the line
            Chess::Position LastMoveFrom;
            Chess::Position LastMoveTo;
            current_game->parseMove(last_move, &LastMoveFrom, &LastMoveTo);

            // First of all, was it a pawn?
            char chLstMvPiece = current_game->getPieceAtPosition(LastMoveTo.iRow, LastMoveTo.iColumn);

            if (toupper(chLstMvPiece) != 'P')
            {
               return false;
            }

            // Did the pawn have a double move forward and was it an adjacent column?
            if ( 2 == abs(LastMoveTo.iRow - LastMoveFrom.iRow) && 1 == abs(LastMoveFrom.iColumn - present.iColumn) )
            {
               cout << "En passant move!\n";
               bValid = true;

               S_enPassant->bApplied = true;
               S_enPassant->PawnCaptured.iRow    = LastMoveTo.iRow;
               S_enPassant->PawnCaptured.iColumn = LastMoveTo.iColumn;
            }
         }

         // Wants to capture a piece
         else if (1 == abs(future.iColumn - present.iColumn))
         {
            if ( (Chess::isWhitePiece(chPiece) && future.iRow == present.iRow + 1) || (Chess::isBlackPiece(chPiece) && future.iRow == present.iRow - 1))
            {
               // Only allowed if there is something to be captured in the square
               if (EMPTY_SQUARE != current_game->getPieceAtPosition(future.iRow, future.iColumn))
               {
                  bValid = true;
                  cout << "Pawn captured a piece!\n";
               }
            }
         }
         else
         {
            // This is invalid
            return false;
         }

         // If a pawn reaches its eight rank, it must be promoted to another piece
         if ( (Chess::isWhitePiece( chPiece ) && 7 == future.iRow) ||
              (Chess::isBlackPiece( chPiece ) && 0 == future.iRow) )
         {
            cout << "Pawn must be promoted!\n";
            S_promotion->bApplied = true;
         }
      }
      break;

      case 'R':
      {
         // Horizontal move
         if ( (future.iRow == present.iRow) && (future.iColumn != present.iColumn) )
         {
            // Check if there are no pieces on the way
            if ( current_game->isPathFree(present, future, Chess::HORIZONTAL) )
            {
               bValid = true;
            }
         }
         // Vertical move
         else if ( (future.iRow != present.iRow) && (future.iColumn == present.iColumn) )
         {
            // Check if there are no pieces on the way
            if ( current_game->isPathFree(present, future, Chess::VERTICAL) )
            {
               bValid = true;
            }
         }
      }
      break;

      case 'N':
      {
         if ( (2 == abs(future.iRow - present.iRow)) && (1 == abs(future.iColumn - present.iColumn)) )
         {
            bValid = true;
         }

         else if (( 1 == abs(future.iRow - present.iRow)) && (2 == abs(future.iColumn - present.iColumn)) )
         {
            bValid = true;
         }
      }
      break;

      case 'B':
      {
         // Diagonal move
         if ( abs(future.iRow - present.iRow) == abs(future.iColumn - present.iColumn) )
         {
            // Check if there are no pieces on the way
            if ( current_game->isPathFree(present, future, Chess::DIAGONAL) )
            {
               bValid = true;
            }
         }
      }
      break;

      case 'Q':
      {
         // Horizontal move
         if ( (future.iRow == present.iRow) && (future.iColumn != present.iColumn) )
         {
            // Check if there are no pieces on the way
            if ( current_game->isPathFree(present, future, Chess::HORIZONTAL))
            {
               bValid = true;
            }
         }
         // Vertical move
         else if ( (future.iRow != present.iRow) && (future.iColumn == present.iColumn) )
         {
            // Check if there are no pieces on the way
            if ( current_game->isPathFree(present, future, Chess::VERTICAL))
            {
               bValid = true;
            }
         }

         // Diagonal move
         else if ( abs(future.iRow - present.iRow) == abs(future.iColumn - present.iColumn) )
         {
            // Check if there are no pieces on the way
            if ( current_game->isPathFree(present, future, Chess::DIAGONAL))
            {
               bValid = true;
            }
         }
      }
      break;

      case 'K':
      {
         // Horizontal move by 1
         if ( (future.iRow == present.iRow) && (1 == abs(future.iColumn - present.iColumn) ) )
         {
            bValid = true;
         }

         // Vertical move by 1
         else if ( (future.iColumn == present.iColumn) && (1 == abs(future.iRow - present.iRow) ) )
         {
            bValid = true;
         }

         // Diagonal move by 1
         else if ( (1 == abs(future.iRow - present.iRow) ) && (1 == abs(future.iColumn - present.iColumn) ) )
         {
            bValid = true;
         }

         // Castling
         else if ( (future.iRow == present.iRow) && (2 == abs(future.iColumn - present.iColumn) ) )
         {
            // Castling is only allowed in these circunstances:

            // 1. King is not in check
            if ( true == current_game->playerKingInCheck() )
            {
               return false;
            }

            // 2. No pieces in between the king and the rook
            if ( false == current_game->isPathFree( present, future, Chess::HORIZONTAL ) )
            {
               return false;
            }

            // 3. King and rook must not have moved yet;
            // 4. King must not pass through a square that is attacked by an enemy piece
            if ( future.iColumn > present.iColumn )
            {
               // if future.iColumn is greather, it means king side
               if ( false == current_game->castlingAllowed(Chess::Side::KING_SIDE, Chess::getPieceColor(chPiece) ) )
               {
                  createNextMessage("Castling to the king side is not allowed.\n");
                  return false;
               }
               else
               {
                  // Check if the square that the king skips is not under attack
                  Chess::UnderAttack square_skipped = current_game->isUnderAttack( present.iRow, present.iColumn + 1, current_game->getCurrentTurn() );
                  if ( false == square_skipped.bUnderAttack )
                  {
                     // Fill the S_castling structure
                     S_castling->bApplied = true;

                     // Present position of the rook
                     S_castling->rook_before.iRow    = present.iRow;
                     S_castling->rook_before.iColumn = present.iColumn + 3;

                     // Future position of the rook
                     S_castling->rook_after.iRow    = future.iRow;
                     S_castling->rook_after.iColumn = present.iColumn + 1; // future.iColumn -1

                     bValid = true;
                  }
               }
            }
            else //if (future.iColumn < present.iColumn)
            {
               // if present.iColumn is greather, it means queen side
               if (false == current_game->castlingAllowed(Chess::Side::QUEEN_SIDE, Chess::getPieceColor(chPiece)))
               {
                  createNextMessage("Castling to the queen side is not allowed.\n");
                  return false;
               }
               else
               {
                  // Check if the square that the king skips is not attacked
                  Chess::UnderAttack square_skipped = current_game->isUnderAttack( present.iRow, present.iColumn - 1, current_game->getCurrentTurn() );
                  if ( false == square_skipped.bUnderAttack )
                  {
                     // Fill the S_castling structure
                     S_castling->bApplied = true;

                     // Present position of the rook
                     S_castling->rook_before.iRow    = present.iRow;
                     S_castling->rook_before.iColumn = present.iColumn - 4;

                     // Future position of the rook
                     S_castling->rook_after.iRow    = future.iRow;
                     S_castling->rook_after.iColumn = present.iColumn - 1; // future.iColumn +1

                     bValid = true;
                  }
               }
            }
         }
      }
      break;

      default:
      {
         cout << "!!!!Should not reach here. Invalid piece: " << char(chPiece) << "\n\n\n";
      }
      break;
   }

   // If it is a move in an invalid direction, do not even bother to check the rest
   if ( false == bValid )
   {
      cout << "Piece is not allowed to move to that square\n";
      return false;
   }


   // -------------------------------------------------------------------------
   // 2. Is there another piece of the same color on the destination square?
   // -------------------------------------------------------------------------
   if (current_game->isSquareOccupied(future.iRow, future.iColumn))
   {
      char chAuxPiece = current_game->getPieceAtPosition(future.iRow, future.iColumn);
      if ( Chess::getPieceColor(chPiece) == Chess::getPieceColor(chAuxPiece) )
      {
         cout << "Position is already taken by a piece of the same color\n";
         return false;
      }
   }

   // ----------------------------------------------
   // 3. Would the king be in check after the move?
   // ----------------------------------------------
   if ( true == current_game->wouldKingBeInCheck(chPiece, present, future, S_enPassant) )
   {
      cout << "Move would put player's king in check\n";
      return false;
   }

   return bValid;
}

void makeTheMove(Chess::Position present, Chess::Position future, Chess::EnPassant* S_enPassant, Chess::Castling* S_castling, Chess::Promotion* S_promotion)
{
   char chPiece = current_game->getPieceAtPosition(present.iRow, present.iColumn);

   // -----------------------
   // Captured a piece?
   // -----------------------
   if ( current_game->isSquareOccupied(future.iRow, future.iColumn) )
   {
      char chAuxPiece = current_game->getPieceAtPosition(future.iRow, future.iColumn);

      if ( Chess::getPieceColor(chPiece) != Chess::getPieceColor(chAuxPiece))
      {
         createNextMessage(Chess::describePiece(chAuxPiece) + " captured!\n");
      }
      else
      {
         cout << "Error. We should not be making this move\n";
         throw("Error. We should not be making this move");
      }
   }
   else if (true == S_enPassant->bApplied)
   {
      createNextMessage("Pawn captured by \"en passant\" move!\n");
   }

   if ( (true == S_castling->bApplied) )
   {
      createNextMessage("Castling applied!\n");
   }

   current_game->movePiece(present, future, S_enPassant, S_castling, S_promotion);
}

//---------------------------------------------------------------------------------------
// Commands
// Functions to handle the commands of the program
// New game, Move, Undo, Save game, Load game, etc
//---------------------------------------------------------------------------------------
void newGame(void)
{
   if (NULL != current_game)
   {
      delete current_game;
   }

   current_game = new Game();
}

void undoMove(void)
{
   if ( false == current_game->undoIsPossible() )
   {
      createNextMessage("Undo is not possible now!\n");
      return;
   }

   current_game->undoLastMove();
   createNextMessage("Last move was undone\n");
}

void movePiece(void)
{
   std::string to_record;

   // Get user input for the piece they want to move
   cout << "Choose piece to be moved. (example: A1 or b2): ";

   std::string move_from;
   getline(cin, move_from);

   if ( move_from.length() > 2 )
   {
      createNextMessage("You should type only two characters (column and row)\n");
      return;
   }

   Chess::Position present;
   present.iColumn = move_from[0];
   present.iRow    = move_from[1];

   // ---------------------------------------------------
   // Did the user pick a valid piece?
   // Must check if:
   // - It's inside the board (A1-H8)
   // - There is a piece in the square
   // - The piece is consistent with the player's turn
   // ---------------------------------------------------
   present.iColumn = toupper(present.iColumn);

   if ( present.iColumn < 'A' || present.iColumn > 'H' )
   {
      createNextMessage("Invalid column.\n");
      return;
   }

   if ( present.iRow < '0' || present.iRow > '8' )
   {
      createNextMessage("Invalid row.\n");
      return;
   }

   // Put in the string to be logged
   to_record += present.iColumn;
   to_record += present.iRow;
   to_record += "-";

   // Convert column from ['A'-'H'] to [0x00-0x07]
   present.iColumn = present.iColumn - 'A';

   // Convert row from ['1'-'8'] to [0x00-0x07]
   present.iRow  = present.iRow  - '1';

   char chPiece = current_game->getPieceAtPosition(present.iRow, present.iColumn);
   cout << "Piece is " << char(chPiece) << "\n";

   if ( 0x20 == chPiece )
   {
      createNextMessage("You picked an EMPTY square.\n");
      return;
   }

   if ( Chess::WHITE_PIECE == current_game->getCurrentTurn() )
   {
      if ( false == Chess::isWhitePiece(chPiece) )
      {
         createNextMessage("It is WHITE's turn and you picked a BLACK piece\n");
         return;
      }
   }
   else
   {
      if ( false == Chess::isBlackPiece(chPiece) )
      {
         createNextMessage("It is BLACK's turn and you picked a WHITE piece\n");
         return;
      }
   }

   // ---------------------------------------------------
   // Get user input for the square to move to
   // ---------------------------------------------------
   cout << "Move to: ";
   std::string move_to;
   getline(cin, move_to);

   if ( move_to.length() > 2 )
   {
      createNextMessage("You should type only two characters (column and row)\n");
      return;
   }

   // ---------------------------------------------------
   // Did the user pick a valid house to move?
   // Must check if:
   // - It's inside the board (A1-H8)
   // - The move is valid
   // ---------------------------------------------------
   Chess::Position future;
   future.iColumn = move_to[0];
   future.iRow    = move_to[1];

   future.iColumn = toupper(future.iColumn);

   if ( future.iColumn < 'A' || future.iColumn > 'H' )
   {
      createNextMessage("Invalid column.\n");
      return;
   }

   if ( future.iRow < '0' || future.iRow > '8' )
   {
      createNextMessage("Invalid row.\n");
      return;
   }

   // Put in the string to be logged
   to_record += future.iColumn;
   to_record += future.iRow;

   // Convert columns from ['A'-'H'] to [0x00-0x07]
   future.iColumn = future.iColumn - 'A';

   // Convert row from ['1'-'8'] to [0x00-0x07]
   future.iRow = future.iRow - '1';

   // Check if it is not the exact same square
   if ( future.iRow == present.iRow && future.iColumn == present.iColumn )
   {
      createNextMessage("[Invalid] You picked the same square!\n");
      return;
   }

   // Is that move allowed?
   Chess::EnPassant  S_enPassant  = { 0 };
   Chess::Castling   S_castling   = { 0 };
   Chess::Promotion  S_promotion  = { 0 };

   if ( false == isMoveValid(present, future, &S_enPassant, &S_castling, &S_promotion) )
   {
      createNextMessage("[Invalid] Piece can not move to that square!\n");
      return;
   }

   // ---------------------------------------------------
   // Promotion: user most choose a piece to
   // replace the pawn
   // ---------------------------------------------------
   if ( S_promotion.bApplied == true )
   {
      cout << "Promote to (Q, R, N, B): ";
      std::string piece;
      getline(cin, piece);

      if ( piece.length() > 1 )
      {
         createNextMessage("You should type only one character (Q, R, N or B)\n");
         return;
      }

      char chPromoted = toupper(piece[0]);

      if ( chPromoted != 'Q' && chPromoted != 'R' && chPromoted != 'N' && chPromoted != 'B' )
      {
         createNextMessage("Invalid character.\n");
         return;
      }

      S_promotion.chBefore = current_game->getPieceAtPosition(present.iRow, present.iColumn);

      if (Chess::WHITE_PLAYER == current_game->getCurrentTurn())
      {
         S_promotion.chAfter = toupper(chPromoted);
      }
      else
      {
         S_promotion.chAfter = tolower(chPromoted);
      }

      to_record += '=';
      to_record += toupper(chPromoted); // always log with a capital letter
   }

   // ---------------------------------------------------
   // Log the move: do it prior to making the move
   // because we need the getCurrentTurn()
   // ---------------------------------------------------
   current_game->logMove( to_record );

   // ---------------------------------------------------
   // Make the move
   // ---------------------------------------------------
   makeTheMove(present, future, &S_enPassant, &S_castling, &S_promotion);

   // ---------------------------------------------------------------
   // Check if this move we just did put the oponent's king in check
   // Keep in mind that player turn has already changed
   // ---------------------------------------------------------------
   if ( true == current_game->playerKingInCheck() )
   {
      if (true == current_game->isCheckMate() )
      {
         if (Chess::WHITE_PLAYER == current_game->getCurrentTurn())
         {
            appendToNextMessage("Checkmate! Black wins the game!\n");
         }
         else
         {
            appendToNextMessage("Checkmate! White wins the game!\n");
         }
      }
      else
      {
         // Add to the string with '+=' because it's possible that
         // there is already one message (e.g., piece captured)
         if (Chess::WHITE_PLAYER == current_game->getCurrentTurn())
         {
            appendToNextMessage("White king is in check!\n");
         }
         else
         {
            appendToNextMessage("Black king is in check!\n");
         }
      }
   }

   return;
}

void saveGame(void)
{
   string file_name;
   cout << "Type file name to be saved (no extension): ";

   getline(cin, file_name);
   file_name += ".dat";

   std::ofstream ofs(file_name);
   if (ofs.is_open())
   {
      // Write the date and time of save operation
      auto time_now = std::chrono::system_clock::now();
      std::time_t end_time = std::chrono::system_clock::to_time_t(time_now);
      ofs << "[Chess console] Saved at: " << std::ctime(&end_time);

      // Write the moves
      for (unsigned i = 0; i < current_game->rounds.size(); i++)
      {
         ofs << current_game->rounds[i].white_move.c_str() << " | " << current_game->rounds[i].black_move.c_str() << "\n";
      }

      ofs.close();
      createNextMessage("Game saved as " + file_name + "\n");
   }
   else
   {
      cout << "Error creating file! Save failed\n";
   }

   return;
}

void loadGame(void)
{
   string file_name;
   cout << "Type file name to be loaded (no extension): ";

   getline(cin, file_name);
   file_name += ".dat";

   std::ifstream ifs(file_name);

   if (ifs)
   {
      // First, reset the pieces
      if (NULL != current_game)
      {
         delete current_game;
      }

      current_game = new Game();

      // Now, read the lines from the file and then make the moves
      std::string line;

      while (std::getline(ifs, line) )
      {
         // Skip lines that starts with "[]"
         if ( 0 == line.compare(0, 1, "["))
         {
            continue;
         }

         // There might be one or two moves in the line
         string loaded_move[2];

         // Find the separator and subtract one
         std::size_t separator = line.find(" |");

         // For the first move, read from the beginning of the string until the separator
         loaded_move[0] = line.substr(0, separator);

         // For the second move, read from the separator until the end of the string (omit second parameter)
         loaded_move[1] = line.substr(line.find("|") + 2);

         for (int i = 0; i < 2 && loaded_move[i] != ""; i++)
         {
            // Parse the line
            Chess::Position from;
            Chess::Position to;

            char chPromoted = 0;

            current_game->parseMove(loaded_move[i], &from, &to, &chPromoted);

            // Check if line is valid
            if ( from.iColumn < 0 || from.iColumn > 7 ||
                 from.iRow    < 0 || from.iRow    > 7 ||
                 to.iColumn   < 0 || to.iColumn   > 7 ||
                 to.iRow      < 0 || to.iRow      > 7 )
            {
               createNextMessage("[Invalid] Can't load this game because there are invalid lines!\n");

               // Clear everything and return
               current_game = new Game();
               return;
            }

            // Is that move allowed? (should be because we already validated before saving)
            Chess::EnPassant S_enPassant = { 0 };
            Chess::Castling  S_castling  = { 0 };
            Chess::Promotion S_promotion = { 0 };

            if ( false == isMoveValid(from, to, &S_enPassant, &S_castling, &S_promotion) )
            {
               createNextMessage("[Invalid] Can't load this game because there are invalid moves!\n");

               // Clear everything and return
               current_game = new Game();
               return;
            }

            // ---------------------------------------------------
            // A promotion occurred
            // ---------------------------------------------------
            if ( S_promotion.bApplied == true )
            {
               if ( chPromoted != 'Q' && chPromoted != 'R' && chPromoted != 'N' && chPromoted != 'B' )
               {
                  createNextMessage("[Invalid] Can't load this game because there is an invalid promotion!\n");

                  // Clear everything and return
                  current_game = new Game();
                  return;
               }

               S_promotion.chBefore = current_game->getPieceAtPosition(from.iRow, from.iColumn);

               if (Chess::WHITE_PLAYER == current_game->getCurrentTurn())
               {
                  S_promotion.chAfter = toupper(chPromoted);
               }
               else
               {
                  S_promotion.chAfter = tolower(chPromoted);
               }
            }


            // Log the move
            current_game->logMove(loaded_move[i]);

            // Make the move
            makeTheMove(from, to, &S_enPassant, &S_castling, &S_promotion);
         }
      }

      // Extra line after the user input
      createNextMessage("Game loaded from " + file_name + "\n");

      return;
   }
   else
   {
      createNextMessage("Error loading " + file_name + ". Creating a new game instead\n");
      current_game = new Game();
      return;
   }
}

int main()
{
   bool bRun = true;

   // Clear screen an print the logo
   clearScreen();
   printLogo();

   string input = "";

   while( bRun )
   {
      printMessage();
      printMenu();

      // Get input from user
      cout << "Type here: ";
      getline(cin, input);

      if (input.length() != 1)
      {
         cout << "Invalid option. Type one letter only\n\n";
         continue;
      }

      try
      {
         switch (input[0])
         {
            case 'N':
            case 'n':
            {
               newGame();
               clearScreen();
               printLogo();
               printSituation(*current_game);
               printBoard(*current_game);
            }
            break;

            case 'M':
            case 'm':
            {
               if (NULL != current_game)
               {
                  if ( current_game->isFinished() )
                  {
                     cout << "This game has already finished!\n";
                  }
                  else
                  {
                     movePiece();
                     //clearScreen();
                     printLogo();
                     printSituation( *current_game );
                     printBoard( *current_game );
                  }
               }
               else
               {
                  cout << "No game running!\n";
               }

            }
            break;

            case 'Q':
            case 'q':
            {
               bRun = false;
            }
            break;

            case 'U':
            case 'u':
            {
               if (NULL != current_game)
               {
                  undoMove();
                  //clearScreen();
                  printLogo();
                  printSituation(*current_game);
                  printBoard(*current_game);
               }
               else
               {
                  cout << "No game running\n";
               }
            }
            break;

            case 'S':
            case 's':
            {
               if (NULL != current_game)
               {
                  saveGame();
                  clearScreen();
                  printLogo();
                  printSituation(*current_game);
                  printBoard(*current_game);
               }
               else
               {
                  cout << "No game running\n";
               }
            }
            break;

            case 'L':
            case 'l':
            {
               loadGame();
               clearScreen();
               printLogo();
               printSituation(*current_game);
               printBoard(*current_game);
            }
            break;

            default:
            {
               cout << "Option does not exist\n\n";
            }
            break;

         }

      }
      catch (const char* s)
      {
         s;
      }
   }


   return 0;
}
