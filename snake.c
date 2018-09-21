#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <conio.h>
#include <time.h>

int main(void) {
	
	const int dimension = 20;
	const int noop = -1;
	
	srand(time(NULL));
	
	int x = rand()%dimension, y = rand()%dimension, px = rand()%dimension, py = rand()%dimension, i, j, k, eaten = 0, steps = 0;
	int snake[dimension*dimension][2];	
	char currentdirection = 'w', lastdirection = ' ';
	
	for(i=0;i<(dimension*dimension);++i){
		snake[i][0] = noop;
		snake[i][1] = noop;
		
	}
	
	
	while(1){
		printf("Snake A:%d S:%d\n", eaten , steps++);				
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
						int a = 0;
						for(k=0;k<dimension*dimension;++k){
							if(snake[k][0] == j && snake[k][1] == i-1) {
								a = 1;
								break;
							} else if(snake[k][0] == noop && snake[k][1] == noop){
								break;
							}
						}
						if(a){
							if(snake[k+1][0] == noop && snake[k+1][1] == noop){
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
			(lastdirection = ' ' ||
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
			if(a && !(px == x && py == y) && (snake[i][0] != noop || snake[i][1] != noop)){
				snake[i][0] = noop;
				snake[i][1] = noop;
				a = 0;
			}
		}
		
		if(x==px && y==py){
            do{
                a = 0;
                px = rand()%dimension;
                py = rand()%dimension;
                
                for(k=0;k<dimension*dimension;++k){
                    if(snake[k][0] == px && snake[k][1] == py) {
                        a = 1;
                        break;
                    } else if(snake[k][0] == noop && snake[k][1] == noop){
                        break;
                    }
                }
                
            }while(a)
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
		
		
		a = 0;
		for(k=0;k<dimension*dimension;++k){
			if(snake[k][0] == x && snake[k][1] == y) {
				a = 1;
				break;
			} else if(snake[k][0] == noop && snake[k][1] == noop){
				break;
			}
		}
		
		if( a || 
			x < 0 || x >= dimension || 
			y < 0 || y >= dimension ){
			printf("defeat %d %d", x, y);
			break;
		}
		
    	system("@cls||clear");
	}

    return 0;
}


