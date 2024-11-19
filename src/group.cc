#include "group.h"

#include "cell.h"

Group::Group() {
  for(unsigned char i = 0; i < 9; i++)
    cells[i] = nullptr;
}

void Group::UpdatePtr(unsigned char index, const Cell* new_cell) {
  if(index >= 9)
    return;

  cells[index] = new_cell;
}

bool Group::IsWellDefined() const {
  for(unsigned char i = 0; i < 9; i++) {
    if(cells[i] == nullptr)
      return false;
  }
  return true;
}

bool Group::HasEmptyCell() const {
  for(unsigned char i = 0; i < 9; i++) {
    if(cells[i]->IsEmpty())
      return true;
  }
  return false;
}

unsigned char Group::GroupSum() const {
  unsigned char sum = 0;
  for(unsigned char i = 0; i < 9; i++) {
    sum += cells[i]->GetValue();
  }
  return sum;
}

bool Group::IsValidSolution() const {
  if(!IsWellDefined() || GroupSum() != 45)
    return false;

  bool value_present[9] = {};
  for(unsigned char i = 0; i < 9; i++) {
    if(cells[i]->GetValue() < 1 || cells[i]->GetValue() > 9)
      return false;

    if(!value_present[cells[i]->GetValue()-1]) {
      value_present[cells[i]->GetValue()-1] = true;
    } else {
      // Found duplicate
      return false;
    }
  }
  return true;
}
