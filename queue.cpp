#include<cstdio>
#include<cstdlib>
#include<queue>
#include<string>
using namespace std;
typedef struct index{
	int NEEDTIME;	
	int RESTTIME;
	int STATUS;//0:Íê³É,1:ÕýÔÚ,3:µÈ´ý
	string NAME; 
}PCB;
queue<PCB> q1,q2,q3;
int q_time[3]; 
char p_count1 = '1';
char p_count2 = '1';
char p_count3 = '1';

void printHint(){
	printf("\n********************************************请按提示输入*********************************************\n");
	printf("\n 1 : 在最高级等待队列中插入进程; 2 : 在中级等待队列中插入进程; 3 : 在最低级等待队列中插入进程; 4 : 执行\n"); 
}
void run(){
	while(!q1.empty()){
		if(q1.front().RESTTIME > q_time[0]){
			q1.front().RESTTIME = q1.front().RESTTIME - q_time[0];			
			q2.push(q1.front());
			q1.pop();			
		}
		else{
			printf("%s\n",q1.front().NAME.c_str());
			q1.pop();
		}
	}
	while(!q2.empty()){
		if(q2.front().RESTTIME > q_time[1]){
			q2.front().RESTTIME = q2.front().RESTTIME - q_time[1];			
			q3.push(q2.front());
			q2.pop();			
		}
		else{
			printf("%s\n",q2.front().NAME.c_str());
			q2.pop();
		}
	}
	while(!q3.empty()){
//		if(q1.front().RESTTIME > q_time[0]){
//			q1.front().RESTTIME = q1.front().RESTTIME - q_time[0];			
//			q2.push(q1.front());
//			q1.pop();			
//		}
//		else{
			printf("%s\n",q3.front().NAME.c_str());
			q3.pop();
//		}
	}
}

void initPCB(int qNumber){
	PCB tem;
	
	int flag = qNumber;
	//printf("\nÇëÊäÈë½ø³ÌÃû×Ö£¬»Ø³µ½áÊø\n");
	//scanf("%s",&tem.NAME);
	printf("\n请输入该进程执行所需要时间，回车结束\n");
	scanf("%d",&tem.NEEDTIME);
	tem.RESTTIME = tem.NEEDTIME;
	if(flag == 1){
		tem.NAME = "process ";
		tem.NAME += (char)p_count1;
		tem.NAME += " in queue";
		tem.NAME += "1";
		p_count1++;
	}
	if(flag == 2){
		tem.NAME = "process ";
		tem.NAME += (char)p_count2;
		tem.NAME += " in queue";
		tem.NAME += "2";
		p_count2++;
	}
	if(flag == 3){
		tem.NAME = "process ";
		tem.NAME += (char)p_count3;
		tem.NAME += " in queue";
		tem.NAME += "3";
		p_count3++;
	}
	switch(flag){
		case 1 : q1.push(tem);break;
		case 2 : q2.push(tem);break;
		case 3 : q3.push(tem);break;
		default : printf("default");break;
	}
}
void insertProcess(int flag){
	switch(flag){
		case 1 : initPCB(1);break;
		case 2 : initPCB(2);break;
		case 3 : initPCB(3);break;
	}
}
void initReadyQueue(){
	int operationCode;
	printf("\n******************************************请依次分配时间片*******************************************\n");
	scanf("%d %d %d",&q_time[0],&q_time[1],&q_time[2]); 
	printHint();
	scanf("%d",&operationCode);
	while(operationCode != 4){
		insertProcess(operationCode);
		printHint();
		scanf("%d",&operationCode);
	}
}
int main(){	
	printf("****************************************多级反馈队列调度算法*****************************************\n");
	printHint();
	initReadyQueue();
	run();
	return 0;
} 
