#include <string>

enum Facing {North, East, South, West};

class Rover{
private:
	int x,y;
	Facing facing;
	int gridSize;
public:
	Rover(int x, int y, Facing facing, int gridSize = 100) {
		this->x = x;
		this->y = y;
		this->facing = facing;
		this->gridSize = 100;
	}

	int getX() { return x; }
	int getY() { return y; }
	int getFacing() { return facing; }


	void moveF() {
		switch (facing) {
			case Facing::North:
				y = (y+1) % gridSize;
				break;
			case Facing::East:
				x = (x+1) % gridSize;
				break;
			case Facing::South:
				y = (y + gridSize - 1) % gridSize;
				break;
			case Facing::West:
				x = (x + gridSize - 1) % gridSize;
				break;
			default:
				throw "Somehow the rover managed to face none of N,E,S,W.";
		}
	}

	void moveB() {
		switch (facing) {
			case Facing::North:
				y = (y + 100 - 1) % 100;
				break;
			case Facing::East:
				x = (x + 100 - 1) % 100;
				break;
			case Facing::South:
				y = (y+1) % 100;
				break;
			case Facing::West:
				x = (x+1) % 100;
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

		for (const char &c : str) {
			switch (c) {
				case 'F':
				case 'f':
					moveF();
					break;
				case 'B':
				case 'b':
					moveB();
					break;
				case 'R':
				case 'r':
					rotateR();
					break;
				case 'L':
				case 'l':
					rotateL();
					break;
				default:
					throw ("Invalid command: " + c);
			}
		}
	}
};