/*
  按键：1开机（响应）    2投影开（响应）    3投影关（响应）    4 播放space（响应）   5 停止ctrl s（响应）   6 暂停ctrl p（响应）   7、F9音量加  8、F10音量减   9、F1关机
  接线：RX-无线模块、10-继电器-主机开机线、11-继电器-牛逼遥控器-投影
*/

/*
  需要修改的地方：解除按键没法在第一页里修改和定义
  ——20190807
  增加发送红外码的功能，并把红外码在第一页里填写
  写一个读取红外码的arduino程序与之配合。
  
*/

/*
  当前解除码是
  7
  5
  10
  12
*/

#include <EEPROM.h>
#include <Keyboard.h>
#define computer 10          //开机
#define projector 11         //投影


//=============================================CONFIG===========================
//关投影后的冷却时间内，不响应投影机的开机信号
unsigned long T = 60000;

//计次数
int N = 500;

//遥控器控制码
#define CTRLCODE_1   6
#define CTRLCODE_2   170
#define CTRLCODE_3   186
