#include "gtest/gtest.h"

#include "test_Point2D.h"
#include "test_Prey.h"
#include "test_Predator.h"
#include "test_Arena.h"




int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}