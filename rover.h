#include <string>

enum Facing {North, East, South, West};

class ObstacleException {
private:
	int x, y;
public: 
	ObstacleException(int x, int y) {
		this->x = x;
		this->y = y;
	}
	int getX() { return x; }
	int getY() { return y; }
	std::string getMesage() {
		return "Obstacle encountered at (" + std::to_string(x) + "," + std::to_string(y) + ").";
	}
};

class Rover{
private:
	int x,y;
	Facing facing;
	int gridSize;
	std::vector<std::vector <bool> > grid;
public:
	//initialize rover's lovation and rotation on a 100x100 grid with no obstacles
	Rover(int x, int y, Facing facing) {
		this->x = x;
		this->y = y;
		this->facing = facing;
		std::vector<bool> temprow(100, false);
		this->grid = std::vector <std::vector<bool> > (100, temprow);
		this->gridSize = this->grid.size();
	}

	//initialize rover's location and rotation, and the grid it is on
	Rover(int x, int y, Facing facing, std::vector<std::vector<bool> > & grid) {
		this->x = x;
		this->y = y;
		this->facing = facing;
		this->grid = grid;
		this->gridSize = grid.size();
	}

	int getX() { return x; }
	int getY() { return y; }
	int getFacing() { return facing; }


	void getNextF(int &nextX, int &nextY) {
		//could be implemented without a switch statement if the rover's rotation
		//was stored as a pair of ints: (x,y) as (0,1), (1,0), (0, -1), (-1, 0) for N,E,S,W resp.
		//then just add those to the current location.
		//this would make the code shorter but possibly less readable
		switch (facing) {
			case Facing::North:
				nextY = (y+1) % gridSize;
				break;
			case Facing::East:
				nextX = (x+1) % gridSize;
				break;
			case Facing::South:
				nextY = (y + gridSize - 1) % gridSize;
				break;
			case Facing::West:
				nextX = (x + gridSize - 1) % gridSize;
				break;
			default:
				throw "Somehow the rover managed to face none of N,E,S,W.";
		}
	}	

	//would probably be better to return a pair of ints rather than changing by reference
	void getNextB(int &nextX, int &nextY) {
		switch (facing) {
			case Facing::North:
				nextY = (y + 100 - 1) % 100;
				break;
			case Facing::East:
				nextX = (x + 100 - 1) % 100;
				break;
			case Facing::South:
				nextY = (y+1) % 100;
				break;
			case Facing::West:
				nextX = (x+1) % 100;
				break;
			default:
				throw "Somehow the rover managed to face none of N,E,S,W.";
		}
	}

	//might have been better to use a function pointer rather than a flag variable
	void moveBF(bool forward) {

		int nextY = y, nextX = x;

		if (forward) {
			getNextF(nextX, nextY);
		} else {
			getNextB (nextX, nextY);
		}

		if (grid.at(nextX).at(nextY) == true) {
			//next step would contain an obstacle
			throw ObstacleException(nextX, nextY);

		} else {
			//otherwise, no obstacle found, move along
			this->y = nextY;
			this->x = nextX;	
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
					moveBF(true);
					break;
				case 'B':
				case 'b':
					moveBF(false);
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