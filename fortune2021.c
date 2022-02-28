#include </home/root/Documents/KISS/BabyReese/Create21-22/include/variables.h>
#include </home/root/Documents/KISS/BabyReese/Create21-22/include/camera.h>
#include <mobility.h>
#include <mic.h>
#include <mission.h>
#include <camera.h>

void Arkansas_Alabama_Part_1(){
return1_color();
int contents;
int claw_1 = left_return;
int claw_2 = right_return;
int Green = 0;
int Red = 1;
int Mix=2;
int Nothing=3;

if(claw_1 = 3){claw_1 = Mix;}
if(claw_2 = 3){claw_2 = Mix;}
if(claw_1 == Mix && claw_2 ==Red){contents = 1;}
else if(claw_1 == Mix && claw_2 ==Green){contents = 2;}
else if(claw_1 == Mix && claw_2 ==Mix){contents = 3;}
else if(claw_1 == Red && claw_2 ==Mix){contents = 4;}
else if(claw_1 == Red && claw_2 ==Green){contents = 5;}
else if(claw_1 == Red && claw_2 ==Red){contents = 6;}
else if(claw_1 == Green && claw_2 ==Mix){contents = 7;}
else if(claw_1 == Green && claw_2 ==Red){contents = 8;}
else if(claw_1 == Green && claw_2 ==Green){contents = 9;}
else{contents = 10;}
if(contents == 1 || contents == 7 || contents == 8 )//this swaps poms
{
swap_poms();
int intermediate = claw_1;
claw_1 = claw_2;
claw_2 = intermediate;
}
////////end swap

if(contents == 1 || contents == 2 || contents == 3 || contents == 4 || contents == 7){
//dump_routine each claw only opens if it is above a dump station and the value of claw_x = Mix. e.g.
    smart_servo(0,0,2,0);
    smart_servo(0,1,2,0);
    big_arm(20);
    rotate(35);
    if (claw_1 == Mix){
        smart_servo(100,0,2,0);
        rotate(10);
        rotate(-10);
        smart_servo(0,0,2,0);
        claw_1 = 3;
    }
    /*if (claw_2 == Mix){
        rotate_slightly(-x);
        pull_slightly_forward(y);
        claw_2_open();
        shake();
        claw_2_close();
        pull_slightly_forward(-y);
        rotate_slightly(x);
        claw_2 = 3;
    }*/
//remember that after the dump routine, you go to the place that you started teh routine
}
//end dump routine

//at this point all possible runs should be at the exact same x,y,r,s(but with different contents in claw)

if(contents == 3 || contents == 10){

}
else{
    //rotate();
    if(claw_1 == Red){
        //red_claw_delivery(); reese's job
        claw_1 = Nothing;
    }
    if(claw_2 == Green){
        //green_claw_delivery(); reese's job
        claw_2 = Nothing;
    }
}
}