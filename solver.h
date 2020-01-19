//returns true if row number and column number are valid
bool isValid(int row, int col) 
{
   
    return (row >= 0) && (row < ROW) && 
           (col >= 0) && (col < COL); 
}

void printArray(char arrayName[], int array[ROW][COL])
{
    cout << endl << arrayName << endl;
	for(int i =0; i < ROW;i++)
	{
		for(int j = 0; j < COL; j++)
		{
			cout << array[i][j] << " ";
		}
		cout << endl;
	}
    cout << endl ;
}


void markShortestPath(int map[ROW][COL], int distance[ROW][COL],Point curr)
{
    
    int rowDirections[] = {-1, 0, 0, 1}; 
    int colDirections[] = {0, -1, 1, 0};
    for (int i = 0; i < 4; i++)
    {
        int row = curr.x + rowDirections[i]; 
        int col = curr.y + colDirections[i];

        if (isValid(row, col) && (distance[row][col] == distance[curr.x][curr.y] - 1))
        {
            map[row][col] = MARK;
            // if we reached a cell besides the source
            if (distance[row][col] == 1)
            {
                cout << endl << endl;
                return;
            }
            curr.x = row;
            curr.y = col;
            markShortestPath(map, distance, curr);
           // cout << "(" << curr.x << "," << curr.y << ")" << " ";
            return;
        }
    }
}

//I use Lee's algorithm (https://en.wikipedia.org/wiki/Lee_algorithm) for finding the shortest path 
int findShortestPath(int mat[ROW][COL], int distance[ROW][COL], Point src, Point dest)
{
    int rowDirections[] = {-1, 0, 0, 1}; 
    int colDirections[] = {0, -1, 1, 0};
    bool visited[ROW][COL] = {false};
    
    visited[src.x][src.y] = true;
    queue<Point> q; 
    q.push(src);

    while(!q.empty())
    {
        Point curr = q.front(); 
        if (curr.x == dest.x && curr.y == dest.y)
        {
        	return distance[curr.x][curr.y];
            break;
        }
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int row = curr.x + rowDirections[i]; 
            int col = curr.y + colDirections[i];

            if (isValid(row, col) && (mat[row][col] == 0 || mat[row][col] == 3) && !visited[row][col])
            {
                visited[row][col] = true;
                distance[row][col] = distance[curr.x][curr.y] + 1;
                Point Adjcell = {row, col};
                q.push(Adjcell);
            }
        }
    }

    return -1;
}

//This function will return ASCII codes
int symbol(int map[ROW][COL],Point p)
{
    int wall[4] = {0};

    if(isValid(p.x+1,p.y) && map[p.x+1][p.y] == 1)
    {
        wall[0] = 1;
    }

    if(isValid(p.x-1,p.y) && map[p.x-1][p.y] == 1)
    {
        wall[1] = 1;
    }

    if(isValid(p.x,p.y+1) && map[p.x][p.y+1] == 1)
    {
        wall[2] = 1;
    }

    if(isValid(p.x,p.y-1) && map[p.x][p.y-1] == 1)
    {
        wall[3] = 1;
    }


    if(wall[0] == 0 && wall[1] == 0 && wall[2] == 0 && wall[3] == 0 ) return 32;
    if(wall[0] == 1 && wall[1] == 1 && wall[2] == 1 && wall[3] == 1 ) return 197;
    if(wall[0] == 0 && wall[1] == 1 && wall[2] == 1 && wall[3] == 1 ) return 194;

    if(wall[0] == 0 && wall[1] == 1 && wall[2] == 0 && wall[3] == 1 ) return 191;

    if(wall[0] == 0 && wall[1] == 1 && wall[2] == 1 && wall[3] == 0 ) return 218;

    if(wall[0] == 0 && wall[1] == 0 && wall[2] == 1 && wall[3] == 1 ) return 196;

    if(wall[0] == 1 && wall[1] == 0 && wall[2] == 1 && wall[3] == 1 ) return 193;

    if(wall[0] == 1 && wall[1] == 1 && wall[2] == 0 && wall[3] == 1 ) return 180;

    if(wall[0] == 1 && wall[1] == 1 && wall[2] == 0 && wall[3] == 0 ) return 179;

    if(wall[0] == 1 && wall[1] == 0 && wall[2] == 1 && wall[3] == 0 ) return 192;

    if(wall[0] == 1 && wall[1] == 1 && wall[2] == 1 && wall[3] == 0 ) return 195;

    if(wall[0] == 1 && wall[1] == 0 && wall[2] == 0 && wall[3] == 1 ) return 217;

    return 32;
}

//This function, prints the map with showing the shortest path
void showMap(int map[ROW][COL])
{
    for (int i = 0; i < ROW; ++i)
    {
        for (int j = 0; j < COL; ++j)
        {
            if(map[i][j] == MARK)
            {
                cout << "O";
                
            }
            else if(map[i][j] == 0)
            {
                //32 : space
                cout << char(32);
            }
            else{
                char sym = symbol(map,{i,j});
                cout << sym;
            }
        }
        cout << endl;
    }
}