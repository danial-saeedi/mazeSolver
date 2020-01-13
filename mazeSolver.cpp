#include <iostream>
#include <queue>
#include <vector>
#include <fstream>
using namespace std;

#define ROW 4
#define COL 5

struct Point 
{
    int x;
    int y; 
}; 

struct queueNode 
{
    Point pt;
    int dist;
    Point prevPt; //Previous Point
};

bool isValid(int row, int col) 
{
    // return true if row number and column number 
    // is in range 
    return (row >= 0) && (row < ROW) && 
           (col >= 0) && (col < COL); 
}

void showTheShortestPath(int mat[ROW][COL],int distance[ROW][COL],Point src, Point dest)
{

	for(int i =0; i < ROW;i++)
	{
		for(int j = 0; j < COL; j++)
		{
			cout << distance[i][j] << " ";
		}

		cout << endl;
	}

}

//I use Lee's algorithm for finding the shortest path 
void mazeSolver(int mat[ROW][COL],Point src,Point dest)
{
    int rowDirections[] = {-1, 0, 0, 1}; 
    int colDirections[] = {0, -1, 1, 0};

    bool visited[ROW][COL] = {false};
    int distance[ROW][COL] = {0};

    visited[src.x][src.y] = true;
	distance[src.x][src.y] = 1; 
    queue<queueNode> q; 

    queueNode s = {src,0}; 

    q.push(s);

    int length;

    while(!q.empty())
    {
        queueNode curr = q.front(); 
        Point pt = curr.pt;

        if (pt.x == dest.x && pt.y == dest.y)
        {
        	length = curr.dist;
            break;
        }

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int row = pt.x + rowDirections[i]; 
            int col = pt.y + colDirections[i];

            if (isValid(row, col) && !mat[row][col] && !visited[row][col])
            {
                visited[row][col] = true;
                queueNode Adjcell = {
                    {row, col},
                    curr.dist + 1
                };

                distance[row][col] = curr.dist + 1;
                q.push(Adjcell);
            }
        }
    }

    distance[src.x][src.y] = 0;
    distance[dest.x][dest.y] = 1000;

   showTheShortestPath(mat,distance,src, dest);
}

void readMap(char address[],int map[ROW][COL])
{
	ifstream fin;

	fin.open(address);

	string lines[ROW];
	string temp;
	int index = 0;
	while(fin >> temp)
	{
		lines[index] = temp;
		index++;
	}
	
	for(int i =0; i < ROW;i++)
	{
		for(int j = 0; j < COL; j++)
		{
			map[i][j] = lines[i][j] - '0';
		}
	}
	
	fin.close();
}

void findStartAndDest(int map[ROW][COL],Point &mouse,Point &cheese)
{
	bool endOfLoop = false;
	for (int i=0; i<ROW; i++) 
    { 
		for (int j=0; j<COL; j++) 
		{
			if(map[i][j] == 2)
			{
				mouse.x = i;
				mouse.y = j;
				endOfLoop = true;
			}
			else if(map[i][j] == 3)
			{
				cheese.x = i;
				cheese.y = j;
				endOfLoop = true;
			}
		}
	}
}

int main()
{
	int map[ROW][COL];
	Point mouse;
	Point cheese;

	readMap("map.txt",map);

	findStartAndDest(map,mouse,cheese);

   	mazeSolver(map,mouse,cheese);

    // for (int i = 0; i < ROW; ++i)
    // {
    //     for (int j = 0; j < COL; ++j)
    //     {
    //         cout << map[i][j] << "";
    //     }
    //     cout << endl;
    // }
    return 0;
}