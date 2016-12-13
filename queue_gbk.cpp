#include<cstdio>
#include<cstdlib>
#include<queue>
#include<string>
using namespace std;
typedef struct index{
	int NEEDTIME;	
	int RESTTIME;
	char TIMES;
	string NAME; 
}PCB;
queue<PCB> q1,q2,q3;
int q_time[3]; 
char p_count1 = '1';
char p_count2 = '1';
char p_count3 = '1';

void printHint(){
	printf("\n********************************************�밴��ʾ����*********************************************\n");
	printf("\n 1 : ����߼��ȴ������м������; 2 : ���м��ȴ������м������; 3 : ����ͼ��ȴ������м������; 4 : ִ��\n"); 
}
void run(){
	while(!q1.empty()){
		if(q1.front().RESTTIME > q_time[0]){
			q1.front().RESTTIME = q1.front().RESTTIME - q_time[0];
			q1.front().TIMES++;
			q1.front().NAME += " #";
			q1.front().NAME += (char)q1.front().TIMES;
			printf("%s\n",q1.front().NAME.c_str());
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
			q2.front().TIMES++;
			q2.front().NAME += " #";
			q2.front().NAME += (char)q2.front().TIMES;
			printf("%s\n",q2.front().NAME.c_str());			
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
		if(q3.front().TIMES != '0'){
			q3.front().TIMES++;
			q3.front().NAME += " #";
			q3.front().NAME += (char)q3.front().TIMES;
			printf("%s\n",q3.front().NAME.c_str());
			q3.pop();
		}
		else{
			printf("%s\n",q3.front().NAME.c_str());
			q3.pop();
		}
	}
}

void initPCB(int qNumber){
	PCB tem;
	tem.TIMES = '0';
	int flag = qNumber;
	//printf("\n������������֣��س�����\n");
	//scanf("%s",&tem.NAME);
	printf("\n������ý���ִ������Ҫʱ�䣬�س�����\n");
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
	printf("\n******************************************�����η���ʱ��Ƭ*******************************************\n");
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
	printf("****************************************�༶�������е����㷨*****************************************\n");
	printHint();
	initReadyQueue();
	run();
	return 0;
} 
