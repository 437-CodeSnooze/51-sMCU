#include <REGX52.H>
unsigned int FrquSelect   = 0;
unsigned int MusicSelect  = 0;
//要调用函数Delay
//unsigned int code FrquTable[]  = {0, 63778, // 晶振11.0592

//	//各音阶装入定时器的值
//	//上面define是为了给各音阶排序 使其可以在数组中对应计时器重装值
//	//这个是必备的初始化数组
//	
//                             63873,
//                             63968,
//                             64054,
//                             64140,
//                             64215,
//                             64291,
//                             64360,
//                             64425,
//                             64489,
//                             64547,
//                             64607,
//                             64655,
//                             64704,
//                             64751,
//                             64795,
//                             64837,
//                             64876,
//                             64913,
//                             64948,
//                             64981,
//                             65013,
//                             65042,
//                             65070,
//                             65095,
//                             65120,
//                             65143,
//                             65166,
//                             65187,
//                             65206,
//                             65224,
//                             65242,
//                             65259,
//                             65274,
//                             65289,
//                             65303};
void Timer0_Init()
{
    TMOD &= 0xf0;
    TMOD |= 0x01;
    EA  = 1;
    TR0 = 1;
    TH0 = (unsigned int)(65536 - 1000 / 12 * 11.0592) / 256;
    TL0 = (unsigned int)(65536 - 1000 / 12 * 11.0592) % 256;
    ET0 = 1;
    PT0 = 0;
}

// void Timer0_Routint() interrupt 1
// {
//     static unsigned int T0count;
//     TH0 = (unsigned int)(65536 - 1000 / 12 * 11.0592) / 256;
//     TL0 = (unsigned int)(65536 - 1000 / 12 * 11.0592) % 256;
//     T0count++;
//     if (T0count == 1000) 
//		{
//         P2_5    = ~P2_5;
//         T0count = 0;
//     }
// }模板

void Timer0_Routint() interrupt 1
{
    static unsigned int T0count;
    if (FrquTable[FrquSelect])
  	{
        TL0 = FrquTable[FrquSelect] % 256;
        TH0 = FrquTable[FrquSelect] / 256; 
			  T0count++;
		}
    if (T0count == 1000) 
		{
        Buzzer = !Buzzer;
			  T0count=0;
    }
}//控制中断
		
//int main()
//{
//    Timer0_Init();
//    while (1)			{
//        if (music[MusicSelect] != 0xff)
//				{
//            FrquSelect = music[MusicSelect];
//            MusicSelect++;
//            TR0=1;
//					  //正式开始发音
//            Delay1ms(Speed / 4 * music[MusicSelect]);
//            TR0=0;
//            MusicSelect++;
//            Delay(5);
//        } 
//				else
//				{
//            Delay(5000); // 5秒后重新播放
//            MusicSelect = 0;
//        }
//    }
//    return 0;
//}参考模板

//unsigned int code music[]  此数组与音乐的旋律有关 数组形式 第一个为音阶第二个为节拍时间

//需要定义的全局变量