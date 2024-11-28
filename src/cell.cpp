#include "cell.h"

Cell::Cell(unsigned char value)
    : value_(value), locked_(false), notes_mask_(0) {
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

  notes_mask_ |= 1 << (number - 1);
  return true;
}

bool Cell::ClearNote(unsigned char number) {
  if(number < 1 || number > 9)
    return false;

  notes_mask_ &= ~(1 << (number - 1));
  return true;
}

void Cell::ClearAllNotes() {
  notes_mask_ = 0;
}

void Cell::SetAllNotes() {
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Woverflow"
  notes_mask_ =  ~0;
  #pragma GCC diagnostic pop
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

  return notes_mask_ & (1 << (number - 1));
}

bool Cell::IsLocked() const {
  return locked_;
}
