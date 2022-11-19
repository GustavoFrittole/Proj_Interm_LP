#include "Month.h"

int daysInM(Month m, int y){
    
    switch(m){
        case jan: case mar: case may: case jul: case aug: case oct: case dec: return 31;
            break;
        case apr: case  jun: case sep: case  nov: return 30; 
            break;
        case feb: 
            if(y%100==0){ if(y%400==0) return 29; }
            else if(y%4==0) return 29;
            return 28;
            break;
    }
    return -1; //non accade mai, risolve il warning
}
