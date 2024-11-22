#ifndef SUDOKU_BOARD_H
#define SUDOKU_BOARD_H

#include "cell.h"
#include "group.h"

class Board {
public:
  Board();

  // rowN, colN : [1-9]   . value : [0-9]
  bool WriteToCell(unsigned char rowN, unsigned char colN, unsigned char value);
  bool EraseCell(unsigned char rowN, unsigned char colN);
  bool WriteNote(unsigned char rowN, unsigned char colN, unsigned char value);
  bool EraseNote(unsigned char rowN, unsigned char colN, unsigned char value);

  unsigned char GetValueAt(unsigned char rowN, unsigned char colN) const;
  bool HasNote(unsigned char rowN, unsigned char colN,
               unsigned char value) const;
  void PrintBoard() const;
  bool IsWellDefined() const;
  bool IsSolved() const;

private:
  Cell cells_[9][9];
  Group rows_[9];
  Group columns_[9];
  Group blocks_[9];
};

#endif // SUDOKU_BOARD_H
