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
		if (facing == Facing::North) {
			++y;
		} else if (facing == Facing::East) {
			++x;
		} else if (facing == Facing::South) {
			--y;
		} else if (facing == Facing::West) {
			--x;
		} else {
			throw "Somehow the rover managed to face none of N,E,S,W.";
		}
	}

	void moveB() {
		if (facing == Facing::North) {
			--y;
		} else if (facing == Facing::East) {
			--x;
		} else if (facing == Facing::South) {
			++y;
		} else if (facing == Facing::West) {
			++x;
		} else {
			throw "Somehow the rover managed to face none of N,E,S,W.";
		}
	}

	void move(const std::string & str) {
		if (str == "F") {
			moveF();
		} else if (str == "B") {
			moveB();
		}
	}
};