#include <string>

enum Facing {North, East, South, West};

class Rover{
private:
	int x,y;
	Facing facing;
public:
	Rover(int x, int y, Facing facing) {
		this->x = x;
		this->y = y;
		this->facing = facing;
	}

	int getX() { return x; }
	int getY() { return y; }
	int getFacing() { return facing; }


	void moveF() {
		switch (facing) {
			case Facing::North:
				++y;
				break;
			case Facing::East:
				++x;
				break;
			case Facing::South:
				--y;
				break;
			case Facing::West:
				--x;
				break;
			default:
				throw "Somehow the rover managed to face none of N,E,S,W.";
		}
	}

	void moveB() {

		switch (facing) {
			case Facing::North:
				--y;
				break;
			case Facing::East:
				--x;
				break;
			case Facing::South:
				++y;
				break;
			case Facing::West:
				++x;
				break;
			default:
				throw "Somehow the rover managed to face none of N,E,S,W.";
		}
	}

	void rotateR() {
		//the following lines equivalent to
		// facing = (Facing) (((char)facing +1) % 4);
		//but this seemed slightly more readable and may prevent future errors if the enum is changed slightly
		switch (facing) {
			case Facing::North:
				facing = Facing::East;
				break;
			case Facing::East:
				facing = Facing::South;
				break;
			case Facing::South:
				facing = Facing::West;
				break;
			case Facing::West:
				facing = Facing::North;
				break;
			default:
				throw "Somehow the rover managed to face none of N,E,S,W.";
		}
	}

	void rotateL() {
		// facing = (Facing) (((char)facing +4 -1) % 4);
		switch (facing) {
			case Facing::North:
				facing = Facing::West;
				break;
			case Facing::East:
				facing = Facing::North;
				break;
			case Facing::South:
				facing = Facing::East;
				break;
			case Facing::West:
				facing = Facing::South;
				break;
			default:
				throw "Somehow the rover managed to face none of N,E,S,W.";
		}
	}

	void move(const std::string & str) {
		if (str == "F") {
			moveF();
		} else if (str == "B") {
			moveB();
		} else if (str == "R") {
			rotateR();
		} else if (str == "L") {
			rotateL();
		}
	}
};