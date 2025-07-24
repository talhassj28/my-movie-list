#include <gtest/gtest.h>

#include "my_movie_list.hpp"

TEST(MovieTest, ReturnsCorrectTitle) {
    Movie m("Inception");
    EXPECT_EQ(m.getTitle(), "Inception");
}
