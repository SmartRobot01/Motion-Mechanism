#include "LobotServoController.h"

LobotServoController myse;

void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);

  /*myse.runActionGroup(100, 0); //不断运行100号动作组
  delay(5000);
  myse.stopActiongGroup(); //停止动作组运行
  delay(2000);
  myse.setActionGroupSpeed(100, 200); //设置100号动作组运行速度为200%
  delay(2000);
  myse.runActionGroup(100, 0); //循环运行100号动作组
  delay(5000);
  myse.stopActiongGroup(); //停止动作组运行
  delay(2000);
  myse.moveServo(0, 1500, 1000); //0号舵机1000ms移动至1500位置
  delay(2000);
  myse.moveServo(2, 800, 1000); //2号舵机800ms移动至800位置
  delay(2000);
  myse.moveServos(5, 1000, 0, 1300, 2, 700, 4, 600, 6, 900, 8, 790); //
  //控制5个舵机，移动时间1000ms，0号舵机至1300位置，2号舵机至700位置，4号舵机至600位置，
  //6号舵机至900位置，8号舵机至790位置
  delay(2000);
  */

  LobotServo servos[2];   //舵机ID位置结构数组
  servos[0].ID = 0;       //0号舵机
  servos[0].Position = 1550;  //1550位置
  servos[1].ID = 2;       //2号舵机
  servos[1].Position = 1500;  //1500位置
  myse.moveServos(servos, 2, 1000); //控制两个舵机，移动时间1000ms,ID和位置有servos指定

  delay(2000);

}

void loop() {
  static uint32_t Timer;

  if (millis() > Timer) {
    Timer = millis() + 1000;
    myse.getBatteryVoltage();
    Serial.print("Battery Volt:");
    Serial.println(myse.batteryVoltage);
  }

  myse.receiveHandle();

  //LobotServo servos[2];   //舵机ID位置结构数组
  //servos[0].ID = 0;       //0号舵机
  //servos[0].Position = 1550;  //1600位置
  //servos[1].ID = 2;       //2号舵机
  //servos[1].Position = 500;  //500位置
  //myse.moveServos(servos, 2, 10000); //控制两个舵机，移动时间10000ms,ID和位置有servos指定
  //delay(2000);
  

  myse.moveServo(2, 500, 5000); //2号舵机800ms移动至800位置
  delay(5000);
  myse.moveServo(2, 2500, 10000); //2号舵机800ms移动至800位置
  delay(10000);
}


