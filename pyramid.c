/*!
 ============================================================================
 @name        : pyramid.c
 @author      : Vinod Ghadge
 @copyright   : Created on: Jan. 17, 2020
 @brief       : Create Pyramid of star with entry Door
 ============================================================================
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int NoOfExtraRows(int row);
void Print_Var_Bar_And_star();
void Print_star();
void itertionLoop();
int i,j,n,k,p,c,s,count,flag,pyramid;

void NoOfPyramid(int size){
    
    pyramid = size;
    i=k=p=1;
    flag=count=0;
    c = 4;
    n = pyramid*3 + NoOfExtraRows(pyramid) + ((pyramid-1)*2);
     
        while(count < pyramid){
            if(count == pyramid-1){
                flag=1;
            }
            if(i == c){
                c += 1;
                p =  (j/2)+3;
                i =  1;
            }
            itertionLoop();
            count++;     
        }    
}

int NoOfExtraRows(int row){
    
    if(row==1){
        return 0;
    }
    int x;
    int y=1;
    x = row-1;
    while(x>row-(row-1)){
      y = y+x;
      x--;
    }
    return y;
}

void Print_Var_Bar_And_star(){
    int temp;
    while(j++ < ((p*2)-1))                   
       {
        if(flag==1){
            if(pyramid > 4){
                while(j>=s && j < (s+pyramid)){
                    if(i == (((pyramid+2)/2)+2) && j == temp){
                        write(1,"\b$",2);
                    }
                write(1, "|", 1 );
                    j++;
                }
            } else {
            while(j>=s && j < (s+pyramid)){
                write(1, "|", 1 );
                    j++;
                }
            }
        }
            write(1, "*", 1 );
    }   
        temp = ((j+2)/2)+(pyramid/2);
        s = (((j+2)/2)-(pyramid/2));
}

void Print_star(){
    
    while(j++ < ((p*2)-1))                   
        {
            write(1, "*", 1 );
        }
        s = (((j+2)/2)-(pyramid/2));
}

void itertionLoop(){
    
    while(i<c){
        j=0;
        while(j++<(n-p)){
            write(1, " ", 1 );
        }
            j=0;
            write(1, "/", 1 );
                if(i >= (c - pyramid)){
                    Print_Var_Bar_And_star();
                }else{
                          Print_star();
                      }
                    write(1, "\\\n", 2 );
            i++;
            p++;
        }  
}

int main(int argc, char const *argv[])
{
    int pyramid_size;
    pyramid_size = atoi(argv[1]);
    NoOfPyramid(pyramid_size);
    return 0;
}
