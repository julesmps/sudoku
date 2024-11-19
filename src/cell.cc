#include "cell.h"

Cell::Cell(unsigned char default_value) : value(default_value) {
  for(unsigned char i = 0; i < 9; i++)
    notes[i] = false;
}

bool Cell::SetValue(unsigned char new_value) {
  if(new_value > 9)
    return false;

  value = new_value;
  return true;
}

bool Cell::AddNote(unsigned char number) {
  if(number < 1 || number > 9)
    return false;

  notes[number-1] = true;
  return true;
}

bool Cell::ClearNote(unsigned char number) {
  if(number < 1 || number > 9)
    return false;

  notes[number-1] = false;
  return true;
}

bool Cell::IsEmpty() const {
  return (value == 0);
}

unsigned char Cell::GetValue() const {
  return value;
}

bool Cell::HasNote(unsigned char number) const {
  if(number < 1 || number > 9)
    return false;

  return notes[number - 1];
}
