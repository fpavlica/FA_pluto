#define BOOST_TEST_MODULE rover test
#include <boost/test/included/unit_test.hpp>

#include "rover.h"
#define expectEq BOOST_CHECK_EQUAL
#define expect BOOST_CHECK

BOOST_AUTO_TEST_CASE(construct_test) {
	Rover rov(0, 0, Facing::North);

	expectEq(rov.getX(), 0);
	expectEq(rov.getY(), 0);
	expectEq(rov.getFacing(), Facing::North);
}

BOOST_AUTO_TEST_CASE(forward_test) {
	Rover rov (0, 0, Facing::North);

	rov.move("F");
	expectEq(rov.getX(), 0);
	expectEq(rov.getY(), 1);
	expectEq(rov.getFacing(), Facing::North);


	rov.move("F");
	expectEq(rov.getX(), 0);
	expectEq(rov.getY(), 2);
	expectEq(rov.getFacing(), Facing::North);

	Rover rovE(2,2, Facing::East);
	rovE.move("F");
	expectEq(rovE.getX(), 3);
	expectEq(rovE.getY(), 2);
	expectEq(rovE.getFacing(), Facing::East);


	Rover rovS(2,2, Facing::South);
	rovS.move("F");
	expectEq(rovS.getX(), 2);
	expectEq(rovS.getY(), 1);
	expectEq(rovS.getFacing(), Facing::South);


	Rover rovW(2,2, Facing::West);
	rovW.move("F");
	expectEq(rovW.getX(), 1);
	expectEq(rovW.getY(), 2);
	expectEq(rovW.getFacing(), Facing::West);
}

BOOST_AUTO_TEST_CASE(backward_test) {
	Rover rov (0,2, Facing::North);

	expectEq(rov.getX(), 0);
	expectEq(rov.getY(), 2);
	expectEq(rov.getFacing(), Facing::North);

	rov.move("B");
	expectEq(rov.getX(), 0);
	expectEq(rov.getY(), 1);
	expectEq(rov.getFacing(), Facing::North);

	rov.move("B");
	expectEq(rov.getX(), 0);
	expectEq(rov.getY(), 0);
	expectEq(rov.getFacing(), Facing::North);

	Rover rovE(2,2, Facing::East);
	rovE.move("B");
	expectEq(rovE.getX(), 1);
	expectEq(rovE.getY(), 2);
	expectEq(rovE.getFacing(), Facing::East);


	Rover rovS(2,2, Facing::South);
	rovS.move("B");
	expectEq(rovS.getX(), 2);
	expectEq(rovS.getY(), 3);
	expectEq(rovS.getFacing(), Facing::South);


	Rover rovW(2,2, Facing::West);
	rovW.move("B");
	expectEq(rovW.getX(), 3);
	expectEq(rovW.getY(), 2);
	expectEq(rovW.getFacing(), Facing::West);

}

BOOST_AUTO_TEST_CASE (rotate_R_test) {
	Rover rov(2,2, Facing::North);

	rov.move("R");
	expectEq(rov.getX(), 2);
	expectEq(rov.getY(), 2);
	expectEq(rov.getFacing(), Facing::East);


	rov.move("R");
	expectEq(rov.getX(), 2);
	expectEq(rov.getY(), 2);
	expectEq(rov.getFacing(), Facing::South);

	rov.move("R");
	expectEq(rov.getX(), 2);
	expectEq(rov.getY(), 2);
	expectEq(rov.getFacing(), Facing::West);

	rov.move("R");
	expectEq(rov.getX(), 2);
	expectEq(rov.getY(), 2);
	expectEq(rov.getFacing(), Facing::North);

}

BOOST_AUTO_TEST_CASE (rotate_L_test) {
	Rover rov(2,2, Facing::North);

	rov.move("L");
	expectEq(rov.getX(), 2);
	expectEq(rov.getY(), 2);
	expectEq(rov.getFacing(), Facing::West);


	rov.move("L");
	expectEq(rov.getX(), 2);
	expectEq(rov.getY(), 2);
	expectEq(rov.getFacing(), Facing::South);

	rov.move("L");
	expectEq(rov.getX(), 2);
	expectEq(rov.getY(), 2);
	expectEq(rov.getFacing(), Facing::East);

	rov.move("L");
	expectEq(rov.getX(), 2);
	expectEq(rov.getY(), 2);
	expectEq(rov.getFacing(), Facing::North);

}

BOOST_AUTO_TEST_CASE(multi_commands_test) {
	Rover rov(0,0, Facing::North);

	rov.move("FFRF");
	expectEq(rov.getX(), 1);
	expectEq(rov.getY(), 2);
	expectEq(rov.getFacing(), Facing::East);

	Rover rov2(8,8, Facing::South);
	rov2.move("BFLLLLFFBBLR");
	expectEq(rov2.getX(), 8);
	expectEq(rov2.getY(), 8);
	expectEq(rov2.getFacing(), Facing::South);
}

BOOST_AUTO_TEST_CASE (wrap_test) {
	Rover rov1(0, 98, Facing::North);
	rov1.move("FFF");
	expectEq(rov1.getX(), 0);
	expectEq(rov1.getY(), 1);
	expectEq(rov1.getFacing(), Facing::North);


	Rover rov2(0, 98, Facing::South);
	rov2.move("BBB");
	expectEq(rov2.getX(), 0);
	expectEq(rov2.getY(), 1);
	expectEq(rov2.getFacing(), Facing::South);


	Rover rov3(98, 10, Facing::East);
	rov3.move("FFF");
	expectEq(rov3.getX(), 1);
	expectEq(rov3.getY(), 10);
	expectEq(rov3.getFacing(), Facing::East);


	Rover rov4(98, 10, Facing::West);
	rov4.move("BBB");
	expectEq(rov4.getX(), 1);
	expectEq(rov4.getY(), 10);
	expectEq(rov4.getFacing(), Facing::West);
}

BOOST_AUTO_TEST_CASE (wrap_back_test) {

	Rover rov1(0, 1, Facing::South);
	rov1.move("FF");
	expectEq(rov1.getX(), 0);
	expectEq(rov1.getY(), 99);
	expectEq(rov1.getFacing(), Facing::South);


	Rover rov2(0, 1, Facing::North);
	rov2.move("BB");
	expectEq(rov2.getX(), 0);
	expectEq(rov2.getY(), 99);
	expectEq(rov2.getFacing(), Facing::North);


	Rover rov3(1, 10, Facing::West);
	rov3.move("FFF");
	expectEq(rov3.getX(), 98);
	expectEq(rov3.getY(), 10);
	expectEq(rov3.getFacing(), Facing::West);


	Rover rov4(2, 10, Facing::East);
	rov4.move("BBB");
	expectEq(rov4.getX(), 99);
	expectEq(rov4.getY(), 10);
	expectEq(rov4.getFacing(), Facing::East);
}

BOOST_AUTO_TEST_CASE (obstacle_test) {
	std::vector <std::vector<bool>>  obstacles;


	for (int i = 0; i < 10; ++i) {
		std::vector<bool> row(10, false);
		obstacles.push_back(row);
	}
	obstacles.at(2).at(1) = true; // obstacle at x=2, y =1;

	Rover rov(0,0, Facing::North, obstacles);
	rov.move("FRFFFFFFFF");
	expectEq(rov.getX(), 1);
	expectEq(rov.getY(), 1);
	expectEq(rov.getFacing(), Facing::East);
}