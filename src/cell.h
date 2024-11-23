#ifndef SUDOKU_CELL_H
#define SUDOKU_CELL_H

class Cell {
public:
  Cell();

  bool SetValue(unsigned char new_value);
  bool ClearValue(); // alias for SetValue(0)
  bool AddNote(unsigned char number);
  bool ClearNote(unsigned char number);
  void Lock();
  void Unlock();

  bool IsEmpty() const; // ignores notes
  unsigned char GetValue() const;
  bool HasNote(unsigned char number) const;
  bool IsLocked() const;

private:
  unsigned char value_;
  bool notes_[9];
  bool locked_;
};

#endif // SUDOKU_CELL_H
