#ifndef USED_FUNCTION_H
#define USED_FUNCTION_H

void reset (int arr[],int num, int limit ){
    for(int i=0; i<limit;i++){
        arr[i]=num;

    }
}
void reset_hexa (char arr[],int num, int limit ){
    for(int i=0; i<limit;i++){
        arr[i]=num;

    }
}

void from_decimal(int temp, int arr[], int num, int count){
    while( temp!= 0){
          arr[count] = temp % num;
          temp /= num;
          count++;
    }
}
void from_decimal_hexa(char hexadecimal[], int temp, int ascii, int count){
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


#endif // USED_FUNCTION_H
