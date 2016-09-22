#include<cstdio>
#include<string>
#include<cstdlib>
void printCheckerBoard(std::string board){
	int count = 0;
	for(unsigned int i = 0;i < board.size();i++){
		printf("%c",board[i]);
		count++;
		if(count == 13){
			printf("\n");
			count = 0;
		}
	}
}
int exchangePlayer(int playerctrl){
	int thisplayer;
	playerctrl % 2 == 0 ? thisplayer = 2 : thisplayer = 1; 
//	printCheckerBoard(board);
	return thisplayer;
}
void printHint(int player){	
	std::string p1 = "玩家1请输入棋子坐标：";
	std::string p2 = "玩家2请输入棋子坐标：";	
	std::string thisplayer;
	if(player == 1) thisplayer = p1;
	if(player == 2) thisplayer = p2;	
	printf("%s\n",thisplayer.c_str());
}
void reFreshBoard(std::string &board,int x,int y,int thisplayer,int p[2][4]){
	std::string ooxx;
	if(thisplayer == 1) ooxx = "x";
	else ooxx = "o";
	if(x == 1){
		switch(y){
			case 1 : board[15] = ooxx[0]; p[0][0]++;p[1][0]++;p[0][3]++;break;
			case 2 : board[19] = ooxx[0]; p[0][0]++;p[1][1]++;break;
			case 3 : board[23] = ooxx[0]; p[0][0]++;p[1][2]++;p[1][3]++;break;
		}
	}
	if(x == 2){
		switch(y){
			case 1 : board[41] = ooxx[0]; p[0][1]++;p[1][0]++;break;
			case 2 : board[45] = ooxx[0]; p[0][1]++;p[1][1]++;p[0][3]++;p[1][3]++;break;
			case 3 : board[49] = ooxx[0]; p[0][1]++;p[1][2]++;break;
		}
	}
	if(x == 3){
		switch(y){
			case 1 : board[67] = ooxx[0]; p[0][2]++;p[1][0]++;p[1][3]++;break;
			case 2 : board[71] = ooxx[0]; p[0][2]++;p[1][1]++;break;
			case 3 : board[75] = ooxx[0]; p[0][2]++;p[1][2]++;p[0][3]++;break;
		}
	}
	system("cls");
	printf("小帅哥快来玩呀:\n");
	printCheckerBoard(board);
}
int isDone(int p1[2][4],int p2[2][4]){
	for(int i = 0;i < 2;i++){
		for(int j = 0;j < 4;j++){
			if(p1[i][j] == 3) return 1;
			if(p2[i][j] == 3) return 2;
		}
	}
	return 3;
}
bool isExist(int exist[3][3],int x,int y){
	if(exist[x-1][y-1] != 1) exist[x-1][y-1] = 1;
	else return true;
	return false;
}
bool isPeace(int peace[3][3]){
	for(int i = 0;i < 3;i++){
		for(int j = 0;j < 3;j++){
			if(peace[i][j] != 1) return false;
		}
	}
	return true;
}
bool isOverSize(int x,int y){
	if(x > 3 || x < 1 || y > 3 || y < 1) return true;
	return false;
}
int main(){
	int x,y;	
	int playerctrl = 1;
	int thisplayer,winner;
	int p1[2][4],p2[2][4];
	int exist[3][3]; 
	for(int i = 0;i < 2;i++){
		for(int j = 0;j < 4;j++){
			p1[i][j] = 0;
			p2[i][j] = 0;
		}
	}
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			exist[i][j] = 0;
		}
	}
	std::string board = "+---+---+---+|   |   |   |+---+---+---+|   |   |   |+---+---+---+|   |   |   |+---+---+---+";	
	printf("小帅哥快来玩呀:\n");
	printCheckerBoard(board);
	while(isDone(p1,p2) == 3){
		thisplayer = exchangePlayer(playerctrl);
		printHint(thisplayer);
		scanf("%d %d",&x,&y);
		while(isOverSize(x,y)){
			printf("大哥，棋盘只有3x3,请重新输入坐标：\n");
			scanf("%d %d",&x,&y);
		}
		while(isExist(exist,x,y)){
			printf("此地有人，请重新输入坐标：");
			scanf("%d %d",&x,&y);
		}
		if(thisplayer == 1)	reFreshBoard(board,x,y,thisplayer,p1);		
		if(thisplayer == 2) reFreshBoard(board,x,y,thisplayer,p2);
		playerctrl++;
	}		
	winner = isDone(p1,p2);
	if(winner != 3){
		if(winner == 1) printf("GAME OVER! #1 win!");
		if(winner == 2) printf("GAME OVER! #2 win!");
		if(winner == 3) printf("#3");
	}
	else if (isPeace(exist)){
		printf("平局了！");
	}
	else printf("ERROR:end");
	
	return 0;
	
}
