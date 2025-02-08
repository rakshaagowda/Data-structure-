#include <stdio.h>
#include <stdlib.h>
struct time{
    int hour;
    int min;
    int sec;
};
typedef struct time *T;
void read(T t){
    printf("\nenter time (H:M:S): ");
    scanf("%d %d %d",&t->hour,&t->min,&t->sec);
}
void display(T t){
    printf("\n%02d: %02d: %02d",t->hour,t->min,t->sec);
}
void updatetime(T t){
    t->sec++;
    if(t->sec>=60){
        t->sec-=60;
        t->min++;
        if(t->min>=60){
            t->min-=60;
            t->hour++;
            if(t->hour>=24){
                t->hour-=24;
            }
        }
        
    }
}
T addtwotime(T t1,T t2){
    T result;
    result=(struct time*)malloc(sizeof(struct time));
    result->hour=t1->hour+t2->hour;
    result->min=t1->min+t2->min;
    result->sec=t1->sec+t2->sec;
    if(result->sec>=60){
        result->sec-=60;
        result->min++;
        if(result->min>=60){
            result->min-=60;
            result->hour++;
            if(result->hour>=24){
                result->hour-=24;
            }
        }
        
    }
    return result;
}
int main()
{
    T t1,res;
    
    t1=(struct time*)malloc(sizeof(struct time));
    T t2;
    t2=(struct time*)malloc(sizeof(struct time));
    read(t1);
    
    display(t1);
    read(t2);
    display(t2);
    updatetime(t1);
    res=addtwotime(t1,t2);
    display(res);
	return 0;
}
