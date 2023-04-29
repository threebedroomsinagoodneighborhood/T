#pragma once

#include "../Arena.h"


struct ArenaTest: public testing::Test {

	Arena * arena; Prey * prey; Predator * predator;
	void SetUp() {
		prey = new Prey("Tester Sergey",Point2D(7,5),true);
		predator = new Predator("Tester Grisha",Point2D(0,0),true);
		arena = new Arena(10,10,prey,predator);
	}

	void TearDown() {
		delete arena;
	}
};

//TEST_F(ArenaTest,location){
//	ASSERT_EQ(Point2D(7,5),arena->PreyLocation());
//	ASSERT_EQ(prey->getLocation(),arena->PreyLocation());
//	ASSERT_EQ(Point2D(0,0),arena->PredatorLocation());
//	ASSERT_EQ(predator->getLocation(),arena->PredatorLocation());
//}

TEST_F(ArenaTest,gameover) {
	prey->moveTo(1,1); predator->moveTo(1,1);
	ASSERT_TRUE(arena->gameover());
}