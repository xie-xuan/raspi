#include<wiringPi.h>
#include<stdio.h>
#include<stdlib.h>
float Read_cputemp(void);


int main(void)
{
    float temp = 0;
   // wiringPiSetup();
    //pinMode(7,OUTPUT);
    //digitalWrite(7,HIGH);
    while(1)
    {
        temp = Read_cputemp();
        printf("%.2f\n",temp);
        delay(500);
       // digitalWrite(7,HIGH);//delay(500);
       // digitalWrite(7,LOW);//delay(50);

    }
    return 0;
}

float Read_cputemp(void)
{
    char buffer[10];
    float result;
    FILE *fp = fopen("/sys/class/thermal/thermal_zone0/temp","r");
    fscanf(fp,"%s",buffer);
    result = (float)(atoi(buffer));
    return result/1000;
}
