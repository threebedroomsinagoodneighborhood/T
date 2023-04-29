#pragma once

#include "../Characters.h"


struct PredatorTest: public testing::Test {

	Predator * predator;

	void SetUp() {
		predator = new Predator("Tester Grisha",Point2D(0,0),true);
	}

	void TearDown() {
		delete predator;
	}
};


TEST_F(PredatorTest,init_class) {
	EXPECT_STREQ(predator->getName().c_str(),"Tester Grisha");

	EXPECT_TRUE(predator->isNPC());
	ASSERT_TRUE(Point2D(0,0) == predator->getLocation());
}
