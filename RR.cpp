#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<queue>
#include<string>
using namespace std;
const int MAX_TIME = 11;
int Run_time,Q_time; 
typedef struct{
	string NAME;
	int TIME;
	int RESTTIME;
	int status;//0:结束 
}PCB;
queue<PCB> q;

void run(){
	Q_time = ceil(Run_time / q.size());
	while(!q.empty()){
		if(q.front().RESTTIME <= Q_time){
			printf("%s\n",q.front().NAME.c_str());
			q.pop();
		}
		else{
			q.front().RESTTIME -= Q_time;
			q.front().NAME += " !"; 
			q.push(q.front());
			q.pop();
		}
	} 
	
}
void initQueue(){
	char count = '0';
	printf("请输入系统响应时间：");
	scanf("%d",&Run_time);
	srand(time(NULL));
	for(int i = 0;i < 9;i++){
		PCB tem;
		tem.NAME = "process #";
		tem.NAME += ++count; 
		tem.TIME = rand() % MAX_TIME;
		tem.RESTTIME = tem.TIME;
		q.push(tem);
	}
}
int main(){
	initQueue();
	run();
	return 0;
}
