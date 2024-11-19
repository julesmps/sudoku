#include "board.h"

#include <iostream>
#include "group.h"

Board::Board() {
  for(unsigned char i = 0; i < 9; i++) {
    unsigned char n = i / 3;
    unsigned char p = i - (3*n);
    for(unsigned char j = 0; j < 9; j++) {
      unsigned char m = j / 3;
      unsigned char q = j - (3*m);

      rows[i].UpdatePtr(j, &cells[i][j]);
      columns[j].UpdatePtr(i, &cells[i][j]);
      blocks[3*n+m].UpdatePtr(3*p+q, &cells[i][j]);
    }
  }
}

bool Board::WriteToCell(unsigned char rowN, unsigned chat colN,
                        unsigned char value) {
  if(rowN < 1 || rowN > 9 || colN < 1 || colN > 9)
    return false;

  return cells[rowN-1][colN-1].SetValue(value);
}

bool Board::EraseCell(unsigned char rowN, unsigned char colN) {
  return WriteToCell(rowN, colN, 0);
}

bool Board::WriteNote(unsigned char rowN, unsigned char colN,
                      unsigned char value) {
  if(rowN < 1 || rowN > 9 || colN < 1 || colN > 9)
    return false;

  return cells[rowN-1][colN-1].AddNote(value);
}

bool Board::EraseNote(unsigned char rowN, unsigned char colN) {
  if(rowN < 1 || rowN > 9 || colN < 1 || colN > 9)
    return false;

  return cells[rowN-1][colN-1].ClearNote(value);
}

unsigned char Board::GetValueAt(unsigned char rowN, unsigned char colN) const {
  if(rowN < 1 || rowN > 9 || colN < 1 || colN > 9)
    return 255;

  return cells[rowN-1][colN-1].GetValue();
}

bool Board::HasNote(unsigned char rowN, unsigned char colN,
                    unsigned char value) const {
  if(rowN < 1 || rowN > 9 || colN < 1 || colN > 9)
    return false;

  return cells[rowN-1][colN-1].HasNote(value);
}
