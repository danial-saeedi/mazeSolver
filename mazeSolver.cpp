#include <iostream>
#include <fstream>
using namespace std;

//Map Dimension
#define M 11
#define N 20

void readMap(char address[],int map[M][N])
{
	ifstream fin;
	
	fin.open(address);
	
	string lines[M];
	string temp;
	int index = 0;
	while(fin >> temp)
	{
		lines[index] = temp;
		index++;
	}
	
	for(int i =0; i < M;i++)
	{
		for(int j = 0; j < N; j++)
		{
			map[i][j] = lines[i][j] - '0';
		}
	}
	
	fin.close();
}

void findTheMouse(int map[M][N],int &x,int &y)
{
	bool endOfLoop = false;
	for (int i=0; i<M; i++) 
    { 
    	if(endOfLoop == false)
    	{
    		for (int j=0; j<N; j++) 
	        {
	        	if(map[i][j] == 2)
				{
					x = i;
					y = j;
					endOfLoop = true;
	        		break;
				}
			}
	    }
		else
		{
			break;
		}
	}
}

int main()
{
	int map[M][N];
	int mouseX;
	int mouseY;
	readMap("map.txt",map);
	
	//Find position of the mouse
	findTheMouse(map,mouseX,mouseY);
	

	cout << mouseX << " " << mouseY;

	return 0;
}
