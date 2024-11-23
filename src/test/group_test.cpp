#include "src/group.h"
#include "gtest/gtest.h"

TEST(GroupTest, NewGroupNotWellDefined) {
  Group group = {};
  EXPECT_FALSE(group.IsWellDefined());
}

class GroupEmptyCellsTest : public testing::Test {
protected:
  void SetUp() override {
    for(size_t n = 0; n < 9; n++)
      group.UpdatePtr(n, &cells[n]);
  }

  Group group;
  Cell cells[9];
};

TEST_F(GroupEmptyCellsTest, EmptyCellsAreWellDefined) {
  EXPECT_TRUE(group.IsWellDefined());
}

TEST_F(GroupEmptyCellsTest, EmptyCellsHasEmptyCell) {
  ASSERT_TRUE(group.IsWellDefined());
  EXPECT_TRUE(group.HasEmptyCell());
}

TEST_F(GroupEmptyCellsTest, EmptyCellsSumIsZero) {
  ASSERT_TRUE(group.IsWellDefined());
  EXPECT_EQ(group.GroupSum(), 0);
}

TEST_F(GroupEmptyCellsTest, EmptyCellsNotValidSolution) {
  ASSERT_TRUE(group.IsWellDefined());
  EXPECT_FALSE(group.IsValidSolution());
}

class GroupSameCellsTest : public testing::Test {
protected:
  void SetUp() override {
    for(size_t n = 0; n < 9; n++) {
      cells[n].SetValue(1);
      group.UpdatePtr(n, &cells[n]);
    }
  }

  Group group;
  Cell cells[9];
};

TEST_F(GroupSameCellsTest, SameCellsHasNoEmptyCell) {
  ASSERT_TRUE(group.IsWellDefined());
  EXPECT_FALSE(group.HasEmptyCell());
}

TEST_F(GroupSameCellsTest, SameCellsGroupSum) {
  ASSERT_TRUE(group.IsWellDefined());
  unsigned char value = cells[0].GetValue();
  EXPECT_EQ(group.GroupSum(), value * 9);
}

TEST_F(GroupSameCellsTest, SameCellsNotValidSolution) {
  ASSERT_TRUE(group.IsWellDefined());
  EXPECT_FALSE(group.IsValidSolution());
}

class GroupAscendingPlusEmpty : public testing::Test {
protected:
  void SetUp() override {
    for(size_t n = 0; n < 9; n++) {
      cells[n].SetValue(n); // 1 blank + No. 1-8
      group.UpdatePtr(n, &cells[n]);
    }
  }

  Group group;
  Cell cells[9];
};

TEST_F(GroupAscendingPlusEmpty, UniquePlusEmptyHasEmptyCell) {
  ASSERT_TRUE(group.IsWellDefined());
  EXPECT_TRUE(group.HasEmptyCell());
}

TEST_F(GroupAscendingPlusEmpty, AscendingPlusEmptySum) {
  ASSERT_TRUE(group.IsWellDefined());
  EXPECT_EQ(group.GroupSum(), 36); // n*(n+1)/2 with n=8
}

TEST_F(GroupAscendingPlusEmpty, AscendingPlusEmptyNotValidSolution) {
  ASSERT_TRUE(group.IsWellDefined());
  EXPECT_FALSE(group.IsValidSolution());
}

class GroupUniqueAscendingTest : public testing::Test {
protected:
  void SetUp() override {
    for(size_t n = 0; n < 9; n++) {
      cells[n].SetValue(n+1); // 1-9
      group.UpdatePtr(n, &cells[n]);
    }
  }

  Group group;
  Cell cells[9];
};

TEST_F(GroupUniqueAscendingTest, UniqueNonemptyHasNoEmptyCells) {
  ASSERT_TRUE(group.IsWellDefined());
  EXPECT_FALSE(group.HasEmptyCell());
}

TEST_F(GroupUniqueAscendingTest, CorrectAscendingSumIs45) {
  ASSERT_TRUE(group.IsWellDefined());
  EXPECT_EQ(group.GroupSum(), 45);
}

TEST_F(GroupUniqueAscendingTest, CorrectAscendingIsValidSolution) {
  ASSERT_TRUE(group.IsWellDefined());
  EXPECT_TRUE(group.IsValidSolution());
}
