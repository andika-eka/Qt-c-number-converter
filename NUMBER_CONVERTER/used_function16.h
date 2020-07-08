#ifndef USED_FUNCTION16_H
#define USED_FUNCTION16_H
#include <math.h>
#include <QDebug>

void from_decimal16(int temp, int arr[], int num, int count){
    while( temp!= 0){
          arr[count] = temp % num;
          temp /= num;
          count++;
    }
}

int to_decimal16(char temp[], int len, int ascii){
    int decimal=0;
    for (int i = 0;len != 0; i++){
            len--;
            qDebug()<<"test";
            qDebug()<<len;
            if(temp[i] >= '0' && temp[i] <= '9'){
                     ascii = temp[i] - 48;
//                     qDebug()<< "A";
//                     qDebug()<< ascii;
                    }

            else if(temp[i] >= 'a' && temp[i] <= 'f'){
                    ascii = temp[i] - 87;
//                    qDebug()<< "B";
//                    qDebug()<< ascii;
                    }

            else if(temp[i] >= 'A' && temp[i] <= 'F'){
                      ascii = temp[i] - 55;
//                      qDebug()<< "C";
//                      qDebug()<< ascii;
                    }
      qDebug()<<ascii;
            decimal += ascii * pow(16,len);
     }
    return decimal;
}

#endif // USED_FUNCTION16_H
