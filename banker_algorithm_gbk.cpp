#include <cstdio>
int request[3];
int max[5][3] = {{7,5,3},{3,2,2},{9,0,2},{2,2,2},{4,3,3}};
int used[5][3] = {{0,1,0},{2,0,0},{3,0,2},{2,1,1},{0,0,2}};
int need[5][3];
int available[3] = {3,3,2};
int processNumber;
bool finish[5] = {false,false,false,false,false};
int work[3];
int safeNum[5];

void inputRequest(){
	printf("请输入请求的进程号：\n");
	scanf("%d",&processNumber);
	printf("请依次输入请求的资源数：\n");
	scanf("%d %d %d",&request[0],&request[1],&request[2]);
}
bool safeCheck(){
	int finishCount = 0;
	int count = 0;
	int index = 0;
	while(finishCount < 5){
		for(int i = 0;i < 5;i++){
			if (need[i][0] <= work[0]
				&&need[i][1] <= work[1]
				&&need[i][2] <= work[2]
				&& finish[i] == false ){

				work[0] += used[i][0];
				work[1] += used[i][1];
				work[2] += used[i][2];
				finish[i] = true;
				finishCount++;
				safeNum[index++] = i;
				break;
			}
		}
		count++;
		if (count > 5) return false;
	}
	return true;
}
void showRes(){
	printf("\n存在如下安全序列:\n");
	printf("\t");
	for (int i = 0; i < 5; ++i)
	{
		printf("process[%d],",safeNum[i] );
	}
	printf("\n");
}
bool isInputError(int index){
	if (request[0] > need[index][0] 
		|| request[1] > need[index][1] 
		|| request[2] > need[index][2]){
		return true;
	}
	if (request[0] > available[0] 
		|| request[1] > available[1] 
		|| request[2] > available[2]){
		return true;
	}
	return false;
}
void run(int num){
	// for (int i = 0; i < 5; ++i)
	// {
		if (!isInputError(num))
		{
			available[0] -= request[0];
			available[1] -= request[1];
			available[2] -= request[2];
			used[num][0] += request[0];
			used[num][1] += request[1];
			used[num][2] += request[2];
			need[num][0] -= request[0];
			need[num][1] -= request[1];
			need[num][2] -= request[2];
			if(safeCheck()){
				showRes();
				available[0] -= request[0];
				available[1] -= request[1];
				available[2] -= request[2];
			}
			else{
				printf("不安全，拒绝！\n");
			}
		}
		else{
			printf("inputError\n");
		}
	// }
	// if (finish[0] && finish[1] && finish[2] && finish[3] && finish[4])
	// 	{
	// 		printf("safe\n");
	// 	}
	// 	else{
	// 		printf("unsafe\n");
	// 	}	
}

void initProcess(){
	for (int i = 0; i < 5; ++i){
		for (int j = 0; j < 3; ++j){
			need[i][j] = max[i][j] - used[i][j];
		}
	}
	for (int i = 0; i < 3; ++i){
		work[i] = available[i];
	}
}

int main(){
	initProcess();
//	safeCheck();
//	showRes(); 
	inputRequest();
	run(processNumber-1);
	return 0;
}
