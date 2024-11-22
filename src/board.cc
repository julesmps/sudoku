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

      rows_[i].UpdatePtr(j, &cells_[i][j]);
      columns_[j].UpdatePtr(i, &cells_[i][j]);
      blocks_[3*n+m].UpdatePtr(3*p+q, &cells_[i][j]);
    }
  }
}

bool Board::WriteToCell(unsigned char rowN, unsigned char colN,
                        unsigned char value) {
  if(rowN < 1 || rowN > 9 || colN < 1 || colN > 9)
    return false;

  return cells_[rowN-1][colN-1].SetValue(value);
}

bool Board::EraseCell(unsigned char rowN, unsigned char colN) {
  return WriteToCell(rowN, colN, 0);
}

bool Board::WriteNote(unsigned char rowN, unsigned char colN,
                      unsigned char value) {
  if(rowN < 1 || rowN > 9 || colN < 1 || colN > 9)
    return false;

  return cells_[rowN-1][colN-1].AddNote(value);
}

bool Board::EraseNote(unsigned char rowN, unsigned char colN, unsigned char value) {
  if(rowN < 1 || rowN > 9 || colN < 1 || colN > 9)
    return false;

  return cells_[rowN-1][colN-1].ClearNote(value);
}

unsigned char Board::GetValueAt(unsigned char rowN, unsigned char colN) const {
  if(rowN < 1 || rowN > 9 || colN < 1 || colN > 9)
    return -1;

  return cells_[rowN-1][colN-1].GetValue();
}

bool Board::HasNote(unsigned char rowN, unsigned char colN,
                    unsigned char value) const {
  if(rowN < 1 || rowN > 9 || colN < 1 || colN > 9)
    return false;

  return cells_[rowN-1][colN-1].HasNote(value);
}

// TODO: temp - move to separate class
void Board::PrintBoard() const {
  for(size_t row = 0; row < 9; row++) {
    if(row == 3 || row == 6)
      std::cout << "---+---+---" << '\n';
    for(size_t col = 0; col < 9; col++) {
      if(col == 3 || col == 6)
        std::cout << "|";
      std::cout << (int) cells_[row][col].GetValue();
    }
    std::cout << '\n';
  }
}

bool Board::IsWellDefined() const {
  for(size_t i = 0; i < 9; i++) {
    if(!rows_[i].IsWellDefined() || !columns_[i].IsWellDefined() || !blocks_[i].IsWellDefined())
      return false;
  }
  return true;
}

// TODO
bool Board::IsSolved() const {
  return false;
}
