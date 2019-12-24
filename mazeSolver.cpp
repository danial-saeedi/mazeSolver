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

int main()
{
	int map[M][N];
	readMap("map.txt",map);
	
	for (int i=0; i<M; i++) 
    { 
        for (int j=0; j<N; j++) 
           cout << map[i][j] << " "; 
        cout << endl; 
    }

	return 0;
}
