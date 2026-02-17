#include <REGX52.H>
#include "Delay.h"
#include "Matrix 有拖拖沓沓拖拖沓沓现场    LED.h"
#include "Key.h"
unsigned char i;
unsigned char a = 0;
unsigned char count=0;
unsigned char pause=0;
unsigned char K1;

sbit RCK=P3^5;     //RCLK
sbit SCK=P3^6;     //SRCLK
sbit SER=P3^4;     //SER

unsigned char animation_speed = 50; // 动画速度，值越大越慢 (单位: 10ms)

// 动画数据 (48字节, 6帧, 每帧8字节)
unsigned char Animation[48] = 
{
    0x00,0x00,0x19,0x3E,0x7C,0x54,0x03,0x00,
    0x00,0x00,0x01,0x02,0x1C,0x1C,0x7B,0x58,
    0x00,0x00,0x19,0x3E,0x7C,0x54,0x03,0x00,
    0x00,0x00,0x23,0x7C,0xF8,0xB6,0x01,0x00,
    0x00,0x00,0x01,0x02,0x24,0x78,0xFF,0xB0,
    0x00,0x00,0x23,0x7C,0xF8,0xB6,0x01,0x00
};

// --- 定时器0初始化 (10ms@11.0592MHz) ---
void Timer0Init(void)
{
    TMOD &= 0xF0;        // 设置定时器模式为16位定时器
    TMOD |= 0x01;
    TL0 = 0x00;          // 设置定时初值 (10ms)
    TH0 = 0xDC;
    TF0 = 0;             // 清除TF0标志
    TR0 = 1;             // 定时器0开始计时
    ET0 = 1;             // 允许定时器0中断
    EA = 1;              // 开启总中断
}

// --- 定时器0中断服务程序 (用于切换动画帧) ---
void Timer0_ISR() interrupt 1
{
    // 1. 重新装载初值，以实现连续的10ms定时
    TL0 = 0x00;
    TH0 = 0xDC;

    // 2. 静态变量，用于软件分频，控制动画切换速度
    if (++count >= animation_speed)
    {
        count = 0; // 计数器清零

        // 3. 如果没有暂停，则切换到下一帧
        if (pause == 0)
        {
            i += 8;
            // 4. 修正后的循环逻辑
            if (i >= 40) // 当播放到最后一帧(索引40)后
            {
                i = 0; // 循环回到第一帧
            }
        }
    }
}

// --- 主函数 ---
void main()
{
    Timer0Init();        // 初始化定时器
    MatrixLED_Init();    // 初始化点阵

    while(1)
    {
        // 1. 按键检测 (非阻塞方式)
        unsigned char key_val = Key();
        if(key_val == 1) // 如果按键1被按下
        {
            pause = !pause; // 切换暂停状态 (0变1, 1变0)
            Delay(200);    // 简单延时，防止一次按键触发多次
        }

        // 2. 高速扫描显示当前帧 (i的值由中断控制)
        // 这部分代码会被反复、快速地执行，形成稳定的图像
        MatrixLED_ShowColumn(0, Animation[i]);
        MatrixLED_ShowColumn(1, Animation[i+1]);
        MatrixLED_ShowColumn(2, Animation[i+2]);
        MatrixLED_ShowColumn(3, Animation[i+3]);
        MatrixLED_ShowColumn(4, Animation[i+4]);
        MatrixLED_ShowColumn(5, Animation[i+5]);
        MatrixLED_ShowColumn(6, Animation[i+6]);
        MatrixLED_ShowColumn(7, Animation[i+7]);
    }
}
