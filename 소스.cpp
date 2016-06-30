#include <stdio.h>
#include <stdlib.h>

#define MAX_VALUE 500
#define ERROR 0.0 //loss/corruption율 조절 (0 - 0.5)
#define STIME 10 //simulation time 조절

struct pkt {
	char data[20];
};
struct frm {
	int seqnum;
	int acknum;
	char payload[20];
};

struct frm send_frame[5];
int frame_rear = 0;
int frame_front = 0;
struct frm send_ack[5];
int ack_rear = 0;
int ack_front = 0;
static int sel = 0;


int error_add(void); // loss/corruption에 따른 error를 제공한다.

void C1(int); //C1에 대한 main function
void Init_C1(struct frm *, int *, int *);// C1 초기화 함수
void C1_in(struct frm *, int *, int *, int);// C1 ack 수신 함수
void C1_out(struct pkt *, struct frm *, int *, int *, int);//frame send
void C1_Timer(int *);//Timer interrupt

void C2(int);//C2수행
void Init_C2(struct frm *, int *, int *);//C2 queue초기화
void C2_ack(struct frm *, int *, int *, int);//frame receive
void C2_out(struct frm *, int *, int *);//ack send
void print_C2(void);

int main()
{
	int timeset = 0;
	printf("Select the ARQ mode : \n 1. Go-Back-N \n 2. Stop-and-Wait \n '7' means error occured : ");
	scanf("%d", &sel);
	for (int time = 0; time < STIME; time++) //SimulationTime()에서 시간이 변함을
	{                                            //알려줄 때마다 time값 0에서부터 1씩 증가
		if (time == STIME)
			break;
		printf("\n\n================================ %3d second(s)  =================================\n\n", time);

		timeset = time % 2;

		C1(time); //C1 수행
		if (timeset == 1)//C1에서 frame을 전송 받았을 때
			C2(time); //C2 수행
		else//C1에서 frame을 전송받지 않았을 때
			print_C2();//C2의 비어있는 모습을 출력

	}
	printf("\n\tSimulation time is %d seconds.\n", STIME);
	int i; scanf("%d", &i);
	return 0;
}



int error_add(void) {

	int	error = ERROR * 10;

	switch (error) {
	case 0: return 0; break;
	case 1: if (0 <= (rand() % 1000) && (rand() % 1000) <= 100) return 1; else return 0; break;
	case 2: if (0 <= (rand() % 1000) && (rand() % 1000) <= 200) return 1; else return 0; break;
	case 3: if (0 <= (rand() % 1000) && (rand() % 1000) <= 300) return 1; else return 0; break;
	case 4: if (0 <= (rand() % 1000) && (rand() % 1000) <= 400) return 1; else return 0; break;
	case 5: if (0 <= (rand() % 1000) && (rand() % 1000) <= 500) return 1; else return 0; break;
	default: return 0; break;
	}
}

void C1(int time) //C1 수행
{
	/***************** circular queue를 사용 *****************/
	static struct frm C1_queue[MAX_VALUE]; //C1의 queue
	static int C1_rear=0; //C1 queue의 맨 앞 포인트
	static int C1_front=0; //C1 queue의 맨 뒤의 전을 포인트
	struct pkt packet; //packet

	if (time == 0) //처음 시작시
		Init_C1(C1_queue, &C1_rear, &C1_front); //initialize C1

	C1_in(C1_queue, &C1_rear, &C1_front, time); //ack값을 receive
	C1_out(&packet, C1_queue, &C1_rear, &C1_front, time);//packet을 frame화 하고 send
}

void Init_C1(struct frm *C1_queue, int *C1_rear, int *C1_front) //initialize C1
{
	*C1_rear;
	*C1_front;

	for (int i = 0; i < MAX_VALUE; i++) { //C1 queue의 모든값을 초기화
		C1_queue[i].seqnum = 0;
		C1_queue[i].acknum = 7; //ack는 7로 초기화
		for (int j = 0; j<20; j++)
			C1_queue[i].payload[j] = 0;
	}
}

void C1_in(struct frm *C1_queue, int *C1_rear, int *C1_front, int time)
{
	int error = 0;
	printf("1. C1 ( Sender )");
	printf("\n\n\tReceived Ack : ");
	if (ack_front == ack_rear);
	else
		for (int i = 1; i <= 4; i++) {
			if (ack_front != ack_rear && error_add() != 1 && send_ack[(ack_front + 1) % 6].acknum == (C1_queue[(*C1_front + i) % MAX_VALUE].seqnum + 1) % 6)
			{ // ACK number를 C1에 전해준다.
				ack_front = (ack_front + 1) % 6;
				C1_queue[(*C1_front + i) % MAX_VALUE].acknum = send_ack[ack_front].acknum;
				printf("%d", send_ack[ack_front].acknum);
			}
			else if (ack_front != ack_rear) {//각 ack가 C1 front의 seqnum+1과 같지 않으면 timer interrupt를 실행하고 error를 유도한다.
				C1_Timer(&(*C1_front));//Timer interrupt발생
				error = 1;// 이후 수행시 모두 error 처리.
			}


		}
	printf("\n\n");
}

void C1_Timer(int *C1_front) // Timer interrupt에 대한 전반적인 기능을 하는 함수.
{
	switch (sel) {
	case 1:
		if ((*C1_front) - 1 <0)
			*C1_front = *C1_front + MAX_VALUE - 1;
		else
			(*C1_front)--;
		ack_front = (ack_front + 1) % 6;
	case 2:
		(*C1_front)--;
		ack_front = (ack_front + 1) % 6;

	default: break;
	}


}

void C1_out(struct pkt *packet, struct frm *C1_queue, int *C1_rear, int *C1_front, int time)
{
	static int cnt = 0, cnt_packet = 0;
	int timeset = 1, i;


	timeset = time % 2;
	if (timeset == 0 || time < 2) // 2n sec에만 패킷이 할당되도록 설정.
		for (i = 0; i < 4; i++, cnt++, cnt_packet++) {// 4pkt/sec
			printf("\t%d번째 packet in -> ", cnt_packet);

			*C1_rear = (*C1_rear + 1) % MAX_VALUE; //C1의 rear값 증가
			if (*C1_front == *C1_rear) {//C1의 queue가 모두 찼을경우
				printf("\n\tError : C1의 Queue가 모두 찼습니다."); //Error메시지 출력
			}

			cnt %= 6; // 0 <= sequnce number <= 5
			C1_queue[*C1_rear].seqnum = cnt; //C1의 sequnce number값을 전달.
			printf(" Sequnce Number %d\n", C1_queue[*C1_rear].seqnum);

			for (int j = 0; j<20; j++)
				C1_queue[cnt].payload[j] = packet->data[j];//packet의 data를 frame의 data에 전해줌
		}
	else
		printf("\tPacket wait.\n\tPacket wait.\n\tPacket wait.\n\tPacket wait.\n\tPacket wait.\n");


	printf("\n\tSended frame   : ");
	for (i = 1; i < 5; i++) //전송 : send_frame에 C1_queue값 대입
	{
		if (time == 0)
		{//처음 시작할 때 C1값을 전송용 queue인 send_frame으로 전송
			frame_rear = (frame_rear + 1) % 6;
			send_frame[frame_rear] = C1_queue[(*C1_front + i) % MAX_VALUE];

			if (error_add())//error발생
				send_frame[frame_rear].seqnum = 7;//sequence number에 error값 입력

			printf("%d", send_frame[frame_rear].seqnum);
		}
		else if (C1_queue[(*C1_front + 1) % MAX_VALUE].acknum == (C1_queue[(*C1_front + 1) % MAX_VALUE].seqnum + 1) % 6)
		{//ack가 제대로 받아진 경우 다음 frame전송
			frame_rear = (frame_rear + 1) % 6;
			*C1_front = (*C1_front + 1) % MAX_VALUE;
			send_frame[frame_rear] = C1_queue[(*C1_front + 4) % MAX_VALUE];

			if (error_add())//error발생
				send_frame[frame_rear].seqnum = 7;//sequence number에 error값 입력

			printf("%d", send_frame[frame_rear].seqnum);
		}
		else {//ack를 기다리는 경우
			printf("wait ");
			break;
		}
	}
	printf("\n\tSliding Window : ");
	for (i = (*C1_front + 1) % MAX_VALUE; i != (*C1_front + 5) % MAX_VALUE; i = (i + 1) % MAX_VALUE)
		printf("%d", C1_queue[i].seqnum);

	printf("\n\tFrames In C1  : ");
	for (i = (*C1_front + 1) % MAX_VALUE; i != (*C1_rear + 1) % MAX_VALUE; i = (i + 1) % MAX_VALUE)
		printf("%d", C1_queue[i].seqnum);
	printf("\n");
}

void C2(int time)
{
	struct frm C2_queue[MAX_VALUE]; //C2의 queue
	static int C2_rear;
	static int C2_front;
	if (time == 0)//0초에 초기화
		Init_C2(C2_queue, &C2_rear, &C2_front);//initialize C2
	else
	{
		C2_ack(C2_queue, &C2_rear, &C2_front, time);//frame을 받음
		C2_out(C2_queue, &C2_rear, &C2_front);//ack를 전송
	}
}

void Init_C2(struct frm *C2_queue, int *C2_rear, int *C2_front) //initialize C2
{
	*C2_rear = 0;
	*C2_front = 0;

	for (int i = 0; i < 4; i++) {
		C2_queue[i].seqnum = 0;
		C2_queue[i].acknum = 0;
		for (int j = 0; j<20; j++)
			C2_queue[i].payload[j] = 0;
	}
}

void C2_ack(struct frm *C2_queue, int *C2_rear, int *C2_front, int time)
{
	static int correct_frame = 0;//제대로 받아진 frame의 갯수
	int error = 0;
	printf("\n\n2. C2 ( Receiver )");
	printf("\n\n\tReceived Frame : ");

	while (frame_front != frame_rear) { //수신 : C2_queue에 send_frame값 대입
		if ((error_add() != 1 && send_frame[(frame_front + 1) % 6].seqnum == ((C2_queue[*C2_rear].seqnum) + 1) % 6) || *C2_rear == 0) {
			//send seqnum이 C2 seqnum의 다음 값이면 수행 (error가 없는 경우)
			*C2_rear = (*C2_rear + 1) % MAX_VALUE;
			frame_front = (frame_front + 1) % 6;
			C2_queue[*C2_rear] = send_frame[frame_front];
			C2_queue[*C2_rear].acknum = (C2_queue[*C2_rear].seqnum + 1) % 6;
			printf("%d", C2_queue[*C2_rear].seqnum);
			correct_frame++;
		}
		else if (error_add() != 1 && send_frame[(frame_front + 1) % 6].seqnum == 7) {//error가 발생한경우 error값을 1로 변경해서 알려줌. 이후부터는 send_frame의 값을 비워주기만 함
			frame_front = (frame_front + 1) % 6;
			error = 1;
		}
		//frame을 이미 받은경우(C1에서 ack가 제대로 받아지지 않았을 경우)
		else if (error_add() != 1 && (send_frame[(frame_front + 1) % 6].seqnum - 5) <= ((C2_queue[*C2_rear].seqnum) + 1) % 6) {

			(*C2_front)--;
			frame_front = (frame_front + 1) % 6;
		}
		else {
			frame_front = (frame_front + 1) % 6;
			error = 1;

		}
	}

	printf("\n\tReceived byte B: %d byte", correct_frame * 25);
}

void C2_out(struct frm *C2_queue, int *C2_rear, int *C2_front)//ack 전송
{
	printf("\n\tAck Frame      : ");
	for (int i = 1; i<5; i++) {
		if (*C2_front != *C2_rear) {
			ack_rear = (ack_rear + 1) % 6;
			*C2_front = (*C2_front + 1) % MAX_VALUE;
			send_ack[ack_rear] = C2_queue[*C2_front]; //ack전송 : C2_queue의 값을 send_ack에 대입

			if (error_add())//ack error발생
				send_ack[ack_rear].acknum = 7; //ack number에 error값 입력

			printf("%d", send_ack[ack_rear].acknum);
		}
		else
			ack_rear = (ack_rear + 1) % 6;
	}

}

void print_C2()//C1의 frame을 기다리는 동안 출력하기 위한 함수
{
	printf("\n\n2. C2 ( Receiver )");
	printf("\n\n\tReceived Frame : ");
	printf("\n\tReceived byte B: ");
	printf("\n\tAck Frame      : ");
}