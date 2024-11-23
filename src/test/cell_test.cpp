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

TEST(CellTest, AddMultipleNotes) {
  Cell cell = {};
  const size_t N_LENGTH = 4;
  unsigned char notes[N_LENGTH] = {1,3,5,8};
  bool expected[9] = {1, 0, 1, 0, 1, 0, 0, 1, 0};

  for(size_t n = 0; n < N_LENGTH; n++) {
    cell.AddNote(notes[n]);
  }

  for(size_t n = 0; n < 9; n++) {
    EXPECT_EQ(cell.HasNote(n+1), expected[n]);
  }
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

TEST(CellTest, ClearCellEmpty) {
  Cell cell = {};
  cell.ClearValue();
  EXPECT_TRUE(cell.IsEmpty());
}

TEST(CellTest, ClearCellNonEmpty) {
  Cell cell = {};
  cell.SetValue(5);
  ASSERT_FALSE(cell.IsEmpty());
  cell.ClearValue();
  EXPECT_TRUE(cell.IsEmpty());
}

TEST(CellTest, NewCellUnlocked) {
  Cell cell = {};
  EXPECT_FALSE(cell.IsLocked());
}

TEST(CellTest, CannotSetLockedCell) {
  Cell cell = {};
  unsigned char val = 5, new_val = 3;
  cell.SetValue(val);
  cell.Lock();
  cell.SetValue(new_val);
  EXPECT_NE(cell.GetValue(), new_val);
  EXPECT_EQ(cell.GetValue(), val);
}

TEST(CellTest, CanSetAfterUnlock) {
  Cell cell = {};
  unsigned char val = 1, no_val = 5, new_val = 9;
  cell.SetValue(val);
  cell.Lock();
  cell.SetValue(no_val);
  cell.Unlock();
  cell.SetValue(new_val);
  EXPECT_NE(cell.GetValue(), no_val);
  EXPECT_EQ(cell.GetValue(), new_val);
}

TEST(CellTest, CannotClearWithLock) {
  Cell cell = {};
  unsigned char val = 4;
  cell.SetValue(val);
  cell.Lock();
  cell.ClearValue();
  EXPECT_FALSE(cell.IsEmpty());
  EXPECT_EQ(cell.GetValue(), val);
}

TEST(CellTest, SetAllNotes) {
  Cell cell = {};
  cell.SetAllNotes();
  for(size_t n = 1; n <= 9; n++) {
    EXPECT_TRUE(cell.HasNote(n));
  }
}

TEST(CellTest, ClearMultipleNotes) {
  Cell cell = {};
  cell.AddNote(1);
  cell.AddNote(4);
  cell.AddNote(7);

  cell.ClearAllNotes();
  for(size_t n = 1; n <= 9; n++) {
    EXPECT_FALSE(cell.HasNote(n));
  }
}
