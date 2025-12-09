#include "pch.h"
#include "gtest/gtest.h"
#include <sstream>
#include <string>
#include <vector>
#include <tuple>

bool ReadNatural(int& n, std::istream& in, std::ostream& out);
std::vector<std::tuple<int, int, int>> GetPythagoreanTriples(int n);
void PrintPythagoreanTriples(int n, std::ostream& out);

TEST(GetPythagoreanTriplesTest, ZeroAndNegative) {
    std::vector<std::tuple<int, int, int>> r0 = GetPythagoreanTriples(0);
    EXPECT_TRUE(r0.empty());
    std::vector<std::tuple<int, int, int>> rneg = GetPythagoreanTriples(-5);
    EXPECT_TRUE(rneg.empty());
}

TEST(GetPythagoreanTriplesTest, SmallN_NoTriples) {
    EXPECT_TRUE(GetPythagoreanTriples(1).empty());
    EXPECT_TRUE(GetPythagoreanTriples(2).empty());
    EXPECT_TRUE(GetPythagoreanTriples(3).empty());
    EXPECT_TRUE(GetPythagoreanTriples(4).empty());
}

TEST(GetPythagoreanTriplesTest, FirstTriples) {
    std::vector<std::tuple<int, int, int>> r5 = GetPythagoreanTriples(5);
    ASSERT_EQ(r5.size(), 1u);
    EXPECT_EQ(r5[0], std::make_tuple(3, 4, 5));

    std::vector<std::tuple<int, int, int>> r10 = GetPythagoreanTriples(10);
    ASSERT_GE(r10.size(), 2u);
    EXPECT_NE(std::find(r10.begin(), r10.end(), std::make_tuple(3, 4, 5)), r10.end());
    EXPECT_NE(std::find(r10.begin(), r10.end(), std::make_tuple(6, 8, 10)), r10.end());
}

TEST(GetPythagoreanTriplesTest, AllTriplesUpTo20) {
    std::vector<std::tuple<int, int, int>> r20 = GetPythagoreanTriples(20);
    std::vector<std::tuple<int, int, int>> expected = {
        {3,4,5},
        {5,12,13},
        {6,8,10},
        {9,12,15},
        {8,15,17},
        {12,16,20}
    };
    for (size_t i = 0; i < expected.size(); ++i) {
        EXPECT_NE(std::find(r20.begin(), r20.end(), expected[i]), r20.end());
    }
}

TEST(PrintPythagoreanTriplesTest, OutputFormatN5) {
    std::stringstream ss;
    PrintPythagoreanTriples(5, ss);
    std::string out = ss.str();
    EXPECT_EQ(out, "(3, 4, 5)\n");
}

TEST(PrintPythagoreanTriplesTest, OutputFormatN20) {
    std::stringstream ss;
    PrintPythagoreanTriples(20, ss);
    std::string out = ss.str();
    EXPECT_NE(out.find("(3, 4, 5)\n"), std::string::npos);
    EXPECT_NE(out.find("(6, 8, 10)\n"), std::string::npos);
    EXPECT_NE(out.find("(5, 12, 13)\n"), std::string::npos);
    EXPECT_NE(out.find("(8, 15, 17)\n"), std::string::npos);
    EXPECT_NE(out.find("(12, 16, 20)\n"), std::string::npos);
}

TEST(ReadNaturalTest, ValidInputFirstTry) {
    std::stringstream in("7\n");
    std::stringstream out;
    int n = 0;
    bool ok = ReadNatural(n, in, out);
    EXPECT_TRUE(ok);
    EXPECT_EQ(n, 7);
    EXPECT_NE(out.str().find("Natural n:"), std::string::npos);
}

TEST(ReadNaturalTest, InvalidThenValid) {
    std::stringstream in("x\n-3\n4\n");
    std::stringstream out;
    int n = 0;
    bool ok = ReadNatural(n, in, out);
    EXPECT_TRUE(ok);
    EXPECT_EQ(n, 4);
    std::string sout = out.str();
    size_t countErrorMessages = 0;
    std::string marker = "Enter positive natural number.";
    size_t pos = 0;
    while ((pos = sout.find(marker, pos)) != std::string::npos) {
        ++countErrorMessages;
        pos += marker.size();
    }
    EXPECT_GE(countErrorMessages, 2);
}

TEST(ReadNaturalTest, EOFOnInputStream) {
    std::stringstream in("");
    std::stringstream out;
    int n = 0;
    bool ok = ReadNatural(n, in, out);
    EXPECT_FALSE(ok);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}