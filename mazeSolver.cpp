/*
* Programmers : Danial Saeedi and Abbas Mohamadian
* Date : 1/19/2020
* Github : https://github.com/danial-saeedi/mazeSolver
*/
#include <iostream>
#include <queue>
#include <vector>
#include <fstream>
using namespace std;

#define ROW 20
#define COL 40

//We mark the shortest path with 9 in map matrix
#define MARK 9

struct Point 
{
    int x;
    int y;
};

//Header Files
#include "mapLoader.h"
#include "solver.h"

int main()
{
	//Loading the map
	int map[ROW][COL];
    int distance[ROW][COL] = {0};
	Point mouse;
	Point cheese;
	loadMap("map.txt", map);
	
	//This function finds the position of mouse and cheese
	findMouseAndCheese(map, mouse, cheese);
	
	//this function  finds the distances from start to end
   	int length = findShortestPath(map, distance, mouse, cheese);
   	
   	//And then from the destination, we backtrack to start
    markShortestPath(map, distance, cheese);
    
    //And finally, printring the map
    showMap(map);
    return 0;
}
