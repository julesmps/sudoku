#ifndef SUDOKU_BOARD_H
#define SUDOKU_BOARD_H

#include "cell.h"
#include "group.h"

class Board {
public:
  Board();

  bool WriteToCell(unsigned char rowN, unsigned char colN, unsigned char value);
  bool EraseCell(unsigned char rowN, unsigned char colN);
  bool WriteNote(unsigned char rowN, unsigned char colN, unsigned char value);
  bool EraseNote(unsigned char rowN, unsigned char colN, unsigned char value);

  unsigned char GetValueAt(unsigned char rowN, unsigned char colN) const;
  bool HasNote(unsigned char rowN, unsigned char colN,
               unsigned char value) const;
  void PrintBoard() const;
  bool IsSolved() const;

private:
  Cell cells[9][9];
  Group rows[9];
  Group columns[9];
  Group blocks[9];
};

#endif // SUDOKU_BOARD_H
