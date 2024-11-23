#include "cell.h"

Cell::Cell() : value_(0), locked_(false) {
  for(unsigned char i = 0; i < 9; i++)
    notes_[i] = false;
}

bool Cell::SetValue(unsigned char new_value) {
  if(new_value > 9 || IsLocked())
    return false;

  value_ = new_value;
  return true;
}

bool Cell::ClearValue() {
  return SetValue(0);
}

bool Cell::AddNote(unsigned char number) {
  if(number < 1 || number > 9)
    return false;

  notes_[number-1] = true;
  return true;
}

bool Cell::ClearNote(unsigned char number) {
  if(number < 1 || number > 9)
    return false;

  notes_[number-1] = false;
  return true;
}

void Cell::Lock() {
  locked_ = true;
}
void Cell::Unlock() {
  locked_ = false;
}

bool Cell::IsEmpty() const {
  return (value_ == 0);
}

unsigned char Cell::GetValue() const {
  return value_;
}

bool Cell::HasNote(unsigned char number) const {
  if(number < 1 || number > 9)
    return false;

  return notes_[number - 1];
}

bool Cell::IsLocked() const {
  return locked_;
}
