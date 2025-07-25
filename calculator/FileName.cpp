#include <conio.h>
#include <graphics.h>
#include <stdio.h>
#include <easyx.h>
#include <mmsystem.h>
#include <print>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#pragma comment(lib,"winmm.lib")
//*******
//未操作：
//第一轮做完后用结果接着进行操作 已完成
//点击完符号后再点符号已消除上一步 完成
// 加个音乐可以拍视频了
// 
// 
//   0    1    2    3
//0  ce   c   删除  / 
//1  7    8    9    *   
//2  4    5    6    -    
//3  1    2    3    +  
//4 +/-   0    .    = 
//strcpy(a, b);  先将 b 号复制到a中,a中原有的值会被覆盖掉
//strcat(a, b);  将b串拼接到a后面
//*******

POINT log[5][4];
POINT mop[5][4];
int w = 75;
int h = 50;
int num = 0;
char arr[20][5] = { "C","c" ,"|","/","7","8","9","*","4","5","6","-","1","2","3","+" ,"^","0",".","=" };
char printnumber1[50];//点击后在输出栏显示的值
char printnumber2[50];//点击后在输出栏2显示的值

void other() {
	char number[8] = "CE";
	int temp_x = w / 2 - textwidth(number) / 2;//字体宽度
	int temp_y = h / 2 - textheight(number) / 2;//字体高度
	outtextxy(log[0][0].x + temp_x, log[0][0].y + temp_y, number);
	sprintf(number, "%s", "c");
	temp_x = w / 2 - textwidth(number) / 2;//字体宽度
	temp_y = h / 2 - textheight(number) / 2;//字体高度
	outtextxy(log[0][1].x + temp_x, log[0][1].y + temp_y, number);
	sprintf(number, "%s", "←");
	temp_x = w / 2 - textwidth(number) / 2;//字体宽度
	temp_y = h / 2 - textheight(number) / 2;//字体高度
	outtextxy(log[0][2].x + temp_x, log[0][2].y + temp_y, number);
	sprintf(number, "%s", "÷");
	temp_x = w / 2 - textwidth(number) / 2;//字体宽度
	temp_y = h / 2 - textheight(number) / 2;//字体高度
	outtextxy(log[0][3].x + temp_x, log[0][3].y + temp_y, number);
	sprintf(number, "%s", "×");
	temp_x = w / 2 - textwidth(number) / 2;//字体宽度
	temp_y = h / 2 - textheight(number) / 2;//字体高度
	outtextxy(log[1][3].x + temp_x, log[1][3].y + temp_y, number);
	sprintf(number, "%s", "-");
	temp_x = w / 2 - textwidth(number) / 2;//字体宽度
	temp_y = h / 2 - textheight(number) / 2;//字体高度
	outtextxy(log[3][3].x + temp_x, log[2][3].y + temp_y, number);
	sprintf(number, "%s", "+");
	temp_x = w / 2 - textwidth(number) / 2;//字体宽度
	temp_y = h / 2 - textheight(number) / 2;//字体高度
	outtextxy(log[4][3].x + temp_x, log[3][3].y + temp_y, number);
	sprintf(number, "%s", "=");
	temp_x = w / 2 - textwidth(number) / 2;//字体宽度
	temp_y = h / 2 - textheight(number) / 2;//字体高度
	outtextxy(log[4][3].x + temp_x, log[4][3].y + temp_y, number);
	sprintf(number, "%s", ".");
	temp_x = w / 2 - textwidth(number) / 2;//字体宽度
	temp_y = h / 2 - textheight(number) / 2;//字体高度
	outtextxy(log[4][2].x + temp_x, log[4][2].y + temp_y, number);
	sprintf(number, "%s", "0");
	temp_x = w / 2 - textwidth(number) / 2;//字体宽度
	temp_y = h / 2 - textheight(number) / 2;//字体高度
	outtextxy(log[4][1].x + temp_x, log[4][1].y + temp_y, number);
	sprintf(number, "%s", "+/-");
	temp_x = w / 2 - textwidth(number) / 2;//字体宽度
	temp_y = h / 2 - textheight(number) / 2;//字体高度
	outtextxy(log[4][0].x + temp_x, log[4][0].y + temp_y, number);
}
void innputnumber() {
	settextstyle(60, 0, "隶书"); //文字样式
	outtextxy(log[0][3].x + 40, 100, '0');
}

void RegularPainting() {
	cleardevice();//刷新
	//画框
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			log[i][j].x = 10 + j * 85;
			log[i][j].y = 200 + i * 60;
			solidrectangle(log[i][j].x, log[i][j].y, log[i][j].x + w, log[i][j].y + h);
			//printf("log[%d][%d]=%s,x1:%d, y1:%d, x2:%d, y2:%d",i,j,&arr[i+j], &log[i][j].x, &log[i][j].y, &log[i][j].x + w, &log[i][j].y + h);
		}
	}

	//    
	//数字区域初始化
	int n = 9;
	settextstyle(30, 0, "隶书"); //文字样式
	settextcolor(BLACK);
	setbkmode(TRANSPARENT); //文字背景透明
	char number[2] = " ";

	for (int i = 1; i < 4; i++) {
		for (int j = 2; j >= 0; j--) {
			sprintf(number, "%d", n);
			int temp_x = w / 2 - textwidth(number) / 2;//字体宽度
			int temp_y = h / 2 - textheight(number) / 2;//字体高度
			outtextxy(log[i][j].x + temp_x, log[i][j].y + temp_y, number);
			n -= 1;

		}
	}
	other();
}

//初始化绘制
void initialization() {
	
	RegularPainting();//常规区域绘制
	
	innputnumber();//输出栏位置绘制
	strcpy(printnumber2, "");
	strcpy(printnumber1, "");
}

void deleteLastCharacter(char* text) {
	int length = strlen(text);
	if (length > 0) {
		text[length - 1] = '\0';
	}
}
void printnumber_2(char* printnumber2) {
	
	settextstyle(60, 0, "隶书"); //文字样式
	outtextxy(log[0][3].x + 70 - textwidth(printnumber2), 100, printnumber2);
}

void printnumber_1(char* text,char symbol) {
	
	text[strlen(text)] = symbol;
	text[strlen(text)+1] = '\0';
	printf("printnumber_1——printnumber1=%s，symbol=%c,text=%s\n", printnumber1, symbol, text);
	settextstyle(40, 0, "隶书"); //文字样式
	outtextxy(log[0][3].x + 70 - textwidth(text), 50, text);
}

//点击切换正负按键时如果是负数则操作的事
void removeFirstChar(char* str) {
	if (str[0] != '\0') {
		char* temp = str;
		while (*temp != '\0') {
			*temp = *(temp + 1);
			temp++;
		}
	}
}
//加减乘除通用模块描述
void Asmd(char* text1, char* text2, char symbol) {
	strcat(text1, text2);//输出栏2的内容赋值给输出栏1
	printnumber_1(text1, symbol);//输出输出栏1
	printnumber_2(text2);//输出输出栏2
	strncpy(text2, "", 1);//将printnumber2内容清空
}

void calculator_Rounding(char* text2) {
	while (true)
	{
		if (text2[strlen(text2) - 1] == '0') {
			text2[strlen(text2) - 1] = '\0';
		}
		if (text2[strlen(text2) - 1] == '.') {
			text2[strlen(text2) - 1] = '\0';
			break;
		}
		break;
	}
}

char calculator(char* symbol, char* text1,char* text2) {
	RegularPainting();
	char n[50];
	char Csymol = symbol[0];
	strcpy(n, text1);
	n[strlen(n)] = '\0';
	double t1,t2;
	t1= strtod(n, NULL);
	t2 = strtod(text2, NULL);
	strcat(text1, text2);
	printnumber_1(text1, '=');
	printf("calculator——t1=%f，t2=%f\n", t1, t2);
	//开始操作 t1，t2是值，symbol是符号
	//结果放在text2，text1的值已经操作完毕
	//正常return返回0，异常1
	//char arr[20][5] = { "C","c" ,"|","/","7","8","9","*","4","5","6","-","1","2","3","+" ,"^","0",".","=" };
	switch (Csymol)
	{
	case '/':
		//t2不可为0
		if (t2 == 0) {
			printf("calculator_if——t2=%f\n", t2);
			return 1;
		}
		
		sprintf(text2, "%.2f", t1 / t2);
		
		
		printf("calculator_/——text2=%s\n", text2);
		break;
	case '*':
		sprintf(text2, "%.2f", t1 * t2);
		break;
	case '-':
		sprintf(text2, "%.2f", t1 - t2);
		break;
	case '+':
		sprintf(text2, "%.2f", t1 + t2);
		break;
	default:

		printf("calculator——好可惜报错啦~~~\n");

		exit(0);
		break;
	}

	calculator_Rounding(text2);
	printf("calculator——printnumber1=%s，printnumber2=%s,symbol[0]=%c\n", text1, text2, symbol[0]);
	return 0;
}

//避免点击多次符号
void Removesymbols(char* text1) {
	//printf("Removesymbols——text1=%s,text1[strlen(text1) - 1]=%c,text1[strlen(text1) - 2]=%c\n", text1, text1[strlen(text1) - 1], text1[strlen(text1) - 2]);
	if ((text1[strlen(text1) - 2] == '/') or (text1[strlen(text1) - 2] == '*') or (text1[strlen(text1) - 2] == '-') or (text1[strlen(text1) - 2] == '+')) {
		text1[strlen(text1) - 2] = text1[strlen(text1) - 1];
		text1[strlen(text1) - 1] = '\0';
		cleardevice();
		RegularPainting();
		printnumber_1(text1, '\0');//输出输出栏1
		
	}
}

void show(char* text) { //点击数字后显示在输出栏
	
	cleardevice();
	RegularPainting();
	if (strlen(printnumber1) != 0) {
		printnumber_1(printnumber1,'\0');
	}
	printf("测试前——printnumber1=%s，printnumber2=%s\n", printnumber1, printnumber2);
	if (int(*text) >= 48 and int(*text) <= 57) {
		strcat(printnumber2, text);
		printnumber_2(printnumber2);
	}
	else 
	{
		//printnumber1已有的情况再按符号，会重复 解决
		char symbol= *text;
		char pan[51];
		char equalto_symbol[2];
		printf("text=%c\n", symbol);
		switch (symbol)
		{
		case 'C':
			printf("这是CE");
			strncpy(printnumber2, "",1);
			break; 

		//c删除键 删除全部
		case 'c':
			printf("这是C");
			strcpy(printnumber2, "");
			strcpy(printnumber1, "");
			strcpy(equalto_symbol, "");
			symbol = NULL;
			printnumber_2(printnumber2);
			break; 

		//← 删除键 只能一个
		case '|':
			
			deleteLastCharacter(printnumber2);
			settextstyle(60, 0, "隶书"); //文字样式
			outtextxy(log[0][3].x + 70 - textwidth(printnumber2), 100, printnumber2);
			break; //可选的

		//除号÷
		case '/':
			//重新绘画
			cleardevice();
			RegularPainting();
			
			Asmd(printnumber1, printnumber2, '/');//通用模块调用
			Removesymbols(printnumber1);//避免点击多次符号
			break; //可选的

		//乘号 ×
		case '*':
			cleardevice();
			RegularPainting();
			Asmd(printnumber1, printnumber2, '*');
			Removesymbols(printnumber1);//避免点击多次符号

			break; //可选的

		//减号 -
		case '-':
			cleardevice();
			RegularPainting();
			Asmd(printnumber1, printnumber2, '-');
			Removesymbols(printnumber1);//避免点击多次符号
			break; //可选的

		//加号 +
		case '+':
			cleardevice();
			RegularPainting();
			Asmd(printnumber1, printnumber2, '+');
			Removesymbols(printnumber1);//避免点击多次符号
			break; //可选的

		//更换符号 正数变负数 负数变正数
		case '^':
			printf("printnumber2[0]=%c,printnumber2=%s\n", printnumber2[0], printnumber2);
			if (printnumber2[0] == '-') {
				removeFirstChar(printnumber2);
				printnumber_2(printnumber2);//输出输出栏2
			}
			else
			{
				strcpy(pan, "-"); // 先将 "-" 号复制到新的字符串中
				strcat(pan, printnumber2); // 然后将原始字符串拼接到后面
				strcpy(printnumber2,pan);//将改造好的字符串导入到printnumber2中
				printnumber_2(printnumber2);//输出输出栏2
			}
			
			break; //可选的

		//点号 添加小数部分
		case '.':
			printnumber2[strlen(printnumber2)] = '.';
			printnumber2[strlen(printnumber2) + 1] = '\0';
			printnumber_2(printnumber2);//输出输出栏2
			break; //可选的

		//等于号 获取运行结果
		case '=':
			 
			equalto_symbol[0] = printnumber1[strlen(printnumber1) - 1];
			equalto_symbol[1] = '\0';
			char result = calculator(equalto_symbol, printnumber1, printnumber2);//0正常 1不支持 后面要加一个弹窗警报
			if (result == 1) {
				strcpy(printnumber2, "除数不能为0");
			}
			printnumber_2(printnumber2);


			strcpy(printnumber1, printnumber2);
			strcpy(printnumber2, "");
			break; //可选的
		}
	}
	printf("测试后——printnumber1=%s，printnumber2=%s\n", printnumber1, printnumber2);
}

//点击后获取数值
void mous() {
	for (int i = 0; i < 19; i++) {
		printf("arr[%d]:%s\n", i, &arr[i][5]);
	}

	int mous_x, mous_y;
	ExMessage msg;//MOUSEMSG的替代
	while (true)
	{
		if (peekmessage(&msg, EM_MOUSE))//EM_MOUSE为获取鼠标消息,有鼠标消息返回真没有返回假
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				//获取鼠标地址
				mous_x = msg.x;
				mous_y = msg.y;
				printf("x:%d,y:%d\n", msg.x, msg.y); 
				//鼠标地址和框地址比较判断点击哪里
				for (int i = 0; i < 4; i++) {
					for (int j = 0; j < 5; j++) {
						//log[i][j].x = 10 + j * 85;
						//log[i][j].y = 200 + i * 60;
						//solidrectangle(log[i][j].x, log[i][j].y, log[i][j].x + w, log[i][j].y + h);
						//log[i][j].x<x<log[i][j].x + w and log[i][j].y<y<log[i][j].y
						if ((log[j][i].x < msg.x and msg.x < log[j][i].x+w) and (log[j][i].y < msg.y and msg.y < log[j][i].y+h)) {
							printf("结果：%s\n", &arr[i + j*4-1][5]);
							show(&arr[i + j * 4 - 1][5]);
						}
					}
				}

			}
		}
	}
}

void playmulic() {
	if (mciSendString("open 一期一会.mp3", 0, 0, 0) != 0) {
		printf("打开音乐文件失败。\n");
	}

	// 播放音乐
	if (mciSendString("play 一期一会.mp3", NULL, 0, NULL) != 0) {
		printf("播放音乐失败。\n");
	}
}

//以获取点击哪里获取什么文字
int main() { 
	//计算器             格子宽75 高50 间隙10
	//        顶到信息栏1 20
	//           信息栏1 信息栏1 40
	//        信息栏之间20              共信息栏190
	//           信息栏2  信息栏2 90
	//        间隔和信息栏之间 20
	//  ce   c   删除  /  高6*10+5*50 =250+60=310  
	//  7    8    9    *   
	//  4    5    6    -    
	//  1    2    3    +  
	// +/-   0    .    =    
	initgraph(350, 500,1); //创建窗口  宽 高
	
	setbkcolor(RGB(243, 243, 243));//背景颜色：白色
	
	initialization();
	playmulic();
	while (true)
	{
		mous();
	}

		
	getchar();//防止窗口关闭
	closegraph();
	return 0;
}