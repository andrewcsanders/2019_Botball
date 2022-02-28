#include <kipr/wombat.h>
#include <mobility.h>
#include <mic.h>
#include <mission.h>
#include <camera.h>
int double_cube()
{
    big_arm(1);
    gyro_drive(-50,1.7,1);
    gyro_drive(30,1,1);
    msleep(7000);
    gyro_drive(-70,1,1);
    smart_servo(claw_L,0,1,0.5);
    msleep(1100);
    big_arm(20);
    gyro_drive(80,1,0);
    motors(0,0);
    big_arm(16);
    smart_servo(claw_L,100,1.3,0);
    msleep(1100);
    big_arm(1);
    smart_servo(claw_L,0,1.2,0);
    msleep(1300);
    big_arm(30);  
    return stacked_start_to_lock();
}
void botguy_setup(){
    printf("starting botguy/n");
	smart_servo(0,100,2,0);
    big_arm(100);
    wrist_delta=300;
    msleep(6000);
    
}
int stacked_start_to_lock(){
    gyro_drive(100,0.2,0);
    gyro_drive(200,5,1);
    rotate(-90);
    //
    gyro_drive(-100,3,0);
    gyro_drive(-50,2,0);//physical square up
    //
    gyro_drive(100,1,1);
    
    return 1;
}

int lock_setup(){
    big_arm(60);
    gyro_drive(-150,2,1);
    gyro_drive(150,1.8,1);
    rotate(90);
    drive_till_bump(100,5,1);
    //gyro_drive(-100,1,1);
    rotate(45);
    gyro_drive( 30,1,1);
    gyro_drive(-30,1,1);
    
}