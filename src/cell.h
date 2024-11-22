#ifndef SUDOKU_CELL_H
#define SUDOKU_CELL_H

class Cell {
public:
  Cell();

  bool SetValue(unsigned char new_value);
  bool AddNote(unsigned char number);
  bool ClearNote(unsigned char number);

  bool IsEmpty() const;
  unsigned char GetValue() const;
  bool HasNote(unsigned char number) const;

private:
  unsigned char value_;
  bool notes_[9];
};

#endif // SUDOKU_CELL_H
