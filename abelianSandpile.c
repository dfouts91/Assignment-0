#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#define HEIGHT 23
#define WIDTH 23

void setup(int i, char *arr[]);
void addSand(int y, int x);
void print();
	

int grid[HEIGHT][WIDTH];
int delay;

int main(int argc, char *argv[])
{
	setup(argc, argv);
	print();
	
	while(1)
	{
		addSand(HEIGHT/2, WIDTH/2);
		print();
		usleep(delay);
	}
}
void setup(int arg, char *arr[])
{
	int i = 1;
	int preDelay;
	
	if(arg != 1 && !strcmp(arr[1], "--fps"))
	{
		printf("xxx %s", arr[1]);
		preDelay = atoi(arr[2]);
		delay = 1000000/preDelay;
		i = 3;
	}
	else
	{
		delay = 0;
		i = 1;
	}
	
	while(i + 2 < arg)
	{
		grid[atoi(arr[i])][atoi(arr[i+1])] = atoi(arr[i+2]);
		i += 3;
	}
}
void addSand(int y, int x)
{
	if(y >= 0 && y < HEIGHT && x >= 0 && x < WIDTH && grid[y][x] != -1)
	{
		grid[y][x] += 1;

		if(grid[y][x] > 8)
		{
			grid[y][x] -= 9;
			
			//Bottom Row
			addSand(y+1, x-1);
			addSand(y+1, x);
			addSand(y+1, x+1);
			
			//Middle Row
			addSand(y,x-1);
			addSand(y,x);
			addSand(y,x+1);
			
			//Top Row
			addSand(y-1,x-1);
			addSand(y-1,x);
			addSand(y-1,x+1);
		}
	}
}
void print()
{
	int i, j;
	
	for(i = 0; i < HEIGHT; i++)
	{
		for(j = 0; j < WIDTH; j++)
		{
			printf(" %c ", grid[i][j] == -1 ? '#' : '0' + grid[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
