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

}