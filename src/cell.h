#ifndef SUDOKU_CELL_H
#define SUDOKU_CELL_H

class Cell {
public:
  Cell(unsigned char value = 0);

  bool SetValue(unsigned char new_value);
  bool ClearValue(); // alias for SetValue(0)
  bool AddNote(unsigned char number);
  bool ClearNote(unsigned char number);
  void ClearAllNotes();
  void SetAllNotes();
  void Lock();
  void Unlock();

  bool IsEmpty() const; // ignores notes
  unsigned char GetValue() const;
  bool HasNote(unsigned char number) const;
  bool IsLocked() const;

private:
  unsigned short value_       : 4;
  unsigned short locked_      : 1;
  unsigned short              : 2;
  unsigned short notes_mask_  : 9;
};

#endif // SUDOKU_CELL_H
