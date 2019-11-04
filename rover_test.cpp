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