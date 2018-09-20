#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <conio.h> 

int main(void) {
	
	int dimension = 20, x = 4, y = 5, px = 7, py = 9, i, j, k;
	int snake[dimension*dimension][2];	
	char currentdirection = 'w', lastdirection = currentdirection;
	
	for(i=0;i<(dimension*dimension);++i){
		snake[i][0] = 0;
		snake[i][1] = 0;
		
	}
	
	snake[0][0] = 1;
	snake[0][1] = 0;
	
	snake[1][0] = 1;
	snake[1][1] = 0;
	
	
	while(1){
		printf("Snake\n");				
		for(i=0; i<dimension+2; ++i){
			if(i == 0){
				printf("%c", -55);
			}else if(i == dimension+1){
				printf("%c", -56);
			}else{
				printf("%c", -70);
			}
			for(j=0; j<dimension+2; ++j){
				if(i == 0 || i == dimension+1){
					printf("%c", -51);
				}else{
					if(x == i-1 && y == j-1){
						printf("%c", 153);
					} else if(px == i-1 && py == j-1){
						printf("X");
					} else {
						int a = 0, dx = 0, dy = 0;
						for(k=0;k<dimension*dimension;++k){
							dx += snake[k][0];
							dy += snake[k][1];
							if(dx + x == i-1 && dy + y == j-1) {
								a = 1;
								break;
							} else if(snake[k][0] == 0 && snake[k][1] == 0){
								break;
							}
						}
						if(a){
							printf("O");
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
				
		if((currentdirection == 'w' || currentdirection == 's' || currentdirection == 'a' || currentdirection == 'd') &&
			((lastdirection == 'w' && currentdirection != 's') ||
			(lastdirection == 's' && currentdirection != 'w') ||
			(lastdirection == 'a' && currentdirection != 'd') ||
			(lastdirection == 'd' && currentdirection != 'a')) ){
			lastdirection = currentdirection;
		}
		
		int a = 1;
		for(i = dimension*dimension-1; i>0; --i){
			snake[i][0] = snake[i-1][0];
			snake[i][1] = snake[i-1][1];
			if(a && !(px == x && py == y) && (snake[i][0] != 0 || snake[i][1] != 0)){
				snake[i][0] = 0;
				snake[i][1] = 0;
				a = 0;
			}
		}
		
		switch(lastdirection){
			case 'w':
				--x;
				snake[0][0] = 1;
				snake[0][1] = 0;
				break;
			case 's':
				++x;
				snake[0][0] = -1;
				snake[0][1] = 0;
				break;
			case 'a':
				--y;
				snake[0][0] = 0;
				snake[0][1] = 1;
				break;
			case 'd':
				++y;
				snake[0][0] = 0;
				snake[0][1] = -1;
				break;
		}
		
		if( x < 0 || x >= dimension || 
			y < 0 || y >= dimension ){
			printf("defeat");
			break;
		}
		
    	system("@cls||clear");
	}

    return 0;
}


