#ifndef USED_FUNCTION8_H
#define USED_FUNCTION8_H
#include <math.h>
#include <QDebug>

int to_decimal8 (int temp, int modulus, int count, int power){
    int decimal;
    while (temp != 0){
        modulus = temp%10;
        temp /=10;
        decimal +=modulus*pow(power,count);
        count++;
    }
    return decimal;
}

void from_decimal8(int temp, int arr[], int num, int count){
    while( temp!= 0){
          arr[count] = temp % num;
          temp /= num;
          count++;
    }
}

void from_decimal8_hexa(char hexadecimal[], int temp, int ascii, int count){
    while (temp != 0){
       ascii = temp % 16;
       if (ascii < 10){
           hexadecimal[count]= ascii + 48;
        }
       else{
           hexadecimal[count]= ascii + 55;
        }
       count++;
       temp = temp / 16;

     }
}
void reset8_hexa (char arr[],int num, int limit ){
    for(int i=0; i<limit;i++){
        arr[i]=num;

    }
}



#endif // USED_FUNCTION8_H
