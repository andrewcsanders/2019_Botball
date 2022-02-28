#include </home/root/Documents/KISS/BabyReese/Create21-22/include/variables.h>
#include <kipr/wombat.h>
#include </home/root/Documents/KISS/BabyReese/Create21-22/include/camera.h>
#include </home/root/Documents/KISS/BabyReese/Create21-22/include/mobility.h>
int frturn = 2300, flturn = 2450, brturn = 2301, blturn = 2302, seright = 2047, seleft = 0, semiddle = 890, right_motor=0, left_motor=3, servo_L=200, servo_R=1800, left=0, right=1, whiteL=183, blackL=3665, whiteR=165, blackR=3243;
int car=0.65;
int PercentReturns, car, counter, channel_0_L_repeats, channel_1_L_repeats, channel_0_R_repeats, channel_1_R_repeats;
int left_return;
int right_return;
int return1_color(){
    //returns 0 for channel 0, 1 for channel 1, 2 if both, 3 if neither
    PercentReturns = (20);
    car=0.65;
    counter=1;
    channel_0_L_repeats=0;
	channel_1_L_repeats=0;
    channel_0_R_repeats=0;
	channel_1_R_repeats=0;
    left_return=3;
    right_return=3;
    camera_open_black();
    while (1){
        camera_update();
        if(get_object_count(0)>1&&get_object_confidence(0,0)>=car&&get_object_center_x(0,0)<80){
            channel_0_L_repeats=channel_0_L_repeats+1;
        }
        if(get_object_count(1)>1&&get_object_confidence(1,0)>=car&&get_object_center_x(1,0)<80){
            channel_1_L_repeats=channel_1_L_repeats+1;
        }
//////////////////////////////////////////////////////////////////////////////////////////////////////
        if(get_object_count(0)>1&&get_object_confidence(0,0)>=car&&get_object_center_x(0,0)>80){
            channel_0_R_repeats=channel_0_R_repeats+1;
        } 
        if(get_object_count(1)>1&&get_object_confidence(1,0)>=car&&get_object_center_x(1,0)>80){
            channel_1_R_repeats=channel_1_R_repeats+1;
        }
        if(counter==50){break;}counter=counter+1;
    }
    printf("%d\n", channel_0_L_repeats);
    printf("%d\n", channel_1_L_repeats);
    printf("%d\n", channel_0_R_repeats);
    printf("%d\n", channel_1_R_repeats);
    if(channel_0_L_repeats>1&&channel_1_L_repeats<5){
    	left_return=0;
    }if(channel_1_L_repeats>1&&channel_0_L_repeats<5){
    	left_return=1;
    }if(channel_1_L_repeats>1&&channel_0_L_repeats>5){
    	left_return=2;
    }
    /////////////////////////////////////////////////////////////////
    if(channel_0_R_repeats>1&&channel_1_R_repeats<1){
    	right_return=0;
    }if(channel_1_R_repeats>1&&channel_0_R_repeats<1){
    	right_return=1;
    }if(channel_1_R_repeats>1&&channel_0_R_repeats>1){
    	right_return=2;
    }
    
    //int temp[2]={left_return,right_return};
	//return(*temp);
    return(0);
}
void grab_poms(){
    printf("%d\n",left_return);
    printf("%d\n",right_return);
    //int a[3]={1,left_return,right_return};
    int returns=100+10*left_return+right_return;
    printf("%d\n",returns);
    if(returns==131||returns==102||returns==101){
	   	swap_poms();
    }
}

void swap_poms(){
    //wrist_lock();
    smart_servo(1,100,2,0);
    smart_servo(0,100,2,0);
    msleep(2000);
    big_arm(30);
    rotate(-32.5);
    big_arm(0);
    smart_servo(0,0,2,0);
    msleep(2000);
    big_arm(30);
	rotate(32.5);
    rotate(32.5);
    big_arm(0);
    gyro_drive(100,0.5,1);
    smart_servo(1,0,2,0);
    msleep(2800);
    big_arm(30);
    gyro_drive(-100,0.5,1);
    rotate(-32.5);
    big_arm(0);
    smart_servo(1,60,2,0);
    smart_servo(0,60,2,0);
    msleep(2000);
    
}

void left_pick(){
	
	//wrist_lock();
	smart_servo(1,80,2,0);
    msleep(2000);
    big_arm(30);
    rotate(-30);
    big_arm(0);
    smart_servo(1,0,2,0);

}

void right_pick(){

	//wrist_lock();
	smart_servo(0,80,2,0);
    msleep(2000);
    big_arm(30);
    rotate(-30);
    big_arm(0);
    smart_servo(0,0,2,0);

}