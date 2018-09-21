#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <conio.h>
#include <time.h>

#define NOOP -1

int pointIsInSnake( int x, int y, int snake[][2], int snakelength);

int main(void) {
	
	const int dimension = 20;
	
	srand(time(NULL));
	
	int x = rand()%dimension, y = rand()%dimension, px = rand()%dimension, py = rand()%dimension, i, j, eaten = 0, steps = 0, part = 0;
	int snake[dimension*dimension][2];	
	char currentdirection = 'w', lastdirection = ' ';
	
	for(i=0;i<(dimension*dimension);++i){
		snake[i][0] = NOOP;
		snake[i][1] = NOOP;
		
	}
	
	time_t start, current;
	
	printf("Press button to start");
	getch();
    system("@cls||clear");
	time(&start);
	
	while(1){
		time(&current);
		printf("Snake A:%d S:%d T:%.0f\n", eaten , steps++, difftime(current, start));				
		for(i=0; i<dimension+2; ++i){
			if(i == 0){
				printf("%c", -55);
			}else if(i == dimension+1){
				printf("%c", -56);
			}else{
				printf("%c", -70);
			}
			for(j=0; j<dimension+1; ++j){
				if(i == 0 || i == dimension+1){
					printf("%c", -51);
				}else{
					if(x == j && y == i-1){
						printf("%c", 153);
					} else if(px == j && py == i-1){
						printf("X");
					} else {
						if(part = pointIsInSnake(j,i-1,snake,dimension*dimension)){
							if(snake[part][0] == NOOP && snake[part][1] == NOOP){
								printf("o");
							} else {
								printf("O");	
							}
						} else {
							printf(" ");
						}
					}
				}
			}
			if(i == 0){
				printf("%c", -69);
			}else if(i == dimension+1){
				printf("%c", -68);
			}else{
				printf("%c", -70);
			}
			printf("\n");
		}
		
		currentdirection = getch();
				
		if(	(currentdirection == 'w' || currentdirection == 's' || currentdirection == 'a' || currentdirection == 'd') && 
			(lastdirection == ' ' ||
			((lastdirection == 'w' && currentdirection != 's') ||
			(lastdirection == 's' && currentdirection != 'w') ||
			(lastdirection == 'a' && currentdirection != 'd') ||
			(lastdirection == 'd' && currentdirection != 'a'))) ){
			lastdirection = currentdirection;
		}
		
		int a = 1;
		for(i = dimension*dimension-1; i>0; --i){
			snake[i][0] = snake[i-1][0];
			snake[i][1] = snake[i-1][1];
			if(a && !(px == x && py == y) && (snake[i][0] != NOOP || snake[i][1] != NOOP)){
				snake[i][0] = NOOP;
				snake[i][1] = NOOP;
				a = 0;
			}
		}
		
		if(x==px && y==py){
            do{
                px = rand()%dimension;
                py = rand()%dimension;
            }while(pointIsInSnake(px,py,snake,dimension*dimension));
			eaten++;
		}
		
		switch(lastdirection){
			case 'w':
				snake[0][0] = x;		
				snake[0][1] = y--;
				break;
			case 's':
				snake[0][0] = x;		
				snake[0][1] = y++;
				break;
			case 'a':
				snake[0][0] = x--;		
				snake[0][1] = y;
				break;
			case 'd':
				snake[0][0] = x++;		
				snake[0][1] = y;
				break;
		}
		
		if( pointIsInSnake(x,y,snake,dimension*dimension) || 
			x < 0 || x >= dimension || 
			y < 0 || y >= dimension ){
			printf("defeat");
			break;
		}
		
    	system("@cls||clear");
	}

    return 0;
}

int pointIsInSnake( int x, int y, int snake[][2], int snakelength){
    int zaehler;
    for(zaehler=0;zaehler<snakelength;++zaehler){
        if(snake[zaehler][0] == x && snake[zaehler][1] == y) {
            return zaehler+1;
        } else if(snake[zaehler][0] == NOOP && snake[zaehler][1] == NOOP){
            break;
        }
    }
    return 0;
}
