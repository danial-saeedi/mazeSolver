//This function, loads the map from map.txt
void loadMap(char address[], int map[ROW][COL])
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

//This function, finds the position of mouse and cheese
void findMouseAndCheese(int map[ROW][COL], Point &mouse, Point &cheese)
{
	bool endOfLoop = true;
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
