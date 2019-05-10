// 010-TestCase.cpp

// Let Catch provide main():
#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include "../EndlessMaze/Header.h"

TEST_CASE("Test1") {
	REQUIRE(2 == 1);
	REQUIRE(2 == 2);
	REQUIRE(3 == 6);
	REQUIRE(4 == 3628800);
}
