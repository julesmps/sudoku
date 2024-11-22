#ifndef SUDOKU_GROUP_H
#define SUDOKU_GROUP_H

#include "cell.h"

class Group {
public:
  Group();

  void UpdatePtr(unsigned char index, const Cell* new_cell);

  bool IsWellDefined() const;
  bool HasEmptyCell() const;
  unsigned char GroupSum() const;
  bool IsValidSolution() const;

private:
  const Cell* cells_[9];
};

#endif // SUDOKU_GROUP_H
