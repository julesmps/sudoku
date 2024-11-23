#include "src/cell.h"
#include "gtest/gtest.h"

TEST(CellTest, NewCellIsEmpty) {
  Cell cell = {};
  EXPECT_TRUE(cell.IsEmpty());
}

TEST(CellTest, SetValueValid) {
  Cell cell = {};
  EXPECT_NE(cell.GetValue(), 5);
  cell.SetValue(5);
  EXPECT_EQ(cell.GetValue(), 5);
}

TEST(CellTest, CellNotEmptyAfterSet) {
  Cell cell = {};
  cell.SetValue(2);
  EXPECT_FALSE(cell.IsEmpty());
}

TEST(CellTest, SetValueInvalid) {
  Cell cell = {};
  unsigned char prev = cell.GetValue();
  cell.SetValue(10);
  EXPECT_EQ(cell.GetValue(), prev);
}

TEST(CellTest, NewCellHasNoNotes) {
  Cell cell = {};
  for(size_t i = 1; i <= 9; i++) {
    EXPECT_FALSE(cell.HasNote(i));
  }
}

TEST(CellTest, AddClearNoteValid) {
  Cell cell = {};
  unsigned char n = 9;
  EXPECT_FALSE(cell.HasNote(n));
  cell.AddNote(n);
  EXPECT_TRUE(cell.HasNote(n));
  cell.ClearNote(n);
  EXPECT_FALSE(cell.HasNote(n));
}

TEST(CellTest, AddNoteInvalid) {
  Cell cell = {};
  unsigned char n = 11;
  cell.AddNote(n);
  EXPECT_FALSE(cell.HasNote(n));
}

TEST(CellTest, AddNoteZeroIsInvalid) {
  Cell cell = {};
  unsigned char n = 0;
  cell.AddNote(n);
  EXPECT_FALSE(cell.HasNote(n));
}

TEST(CellTest, IsEmptyWithNote) {
  Cell cell = {};
  cell.AddNote(1);
  EXPECT_TRUE(cell.IsEmpty());
}
