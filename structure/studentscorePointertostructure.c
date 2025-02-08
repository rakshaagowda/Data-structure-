#include <stdio.h>
#include <stdlib.h>
struct student{
    char name[30];
    int regn;
    float average;
    int marks[3];
};
int n;
typedef struct student *s;

void read(s std){
    for(int i=0;i<n;i++){
        printf("enter student  %d name: ",(i+1));
        scanf("%s",(std+i)->name);
        printf("enter register number: ");
        scanf("%d",&(std+i)->regn);
        printf("enter marks of 3 tests: ");
        for(int j=0;j<3;j++){
            scanf("%d",&(std+i)->marks[j]);
        }
            
    }
}
void sort(s std){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if((std+j)->regn>(std+(j+1))->regn){
                int k=j+1;
                struct student temp=*(std+j);
                *(std+j)=*(std+k);
                *(std+k)=temp;
            }
        }
    }
}

void display(s std){
    sort(std);
    for(int i=0;i<n;i++){
         printf("\nenter student  %d name: ",(i+1));
        printf("%s",(std+i)->name);
        printf("\nenter register number: ");
        printf("%d",(std+i)->regn);
        printf("\nenter marks of 3 tests: ");
        for(int j=0;j<3;j++){
            printf("%d\t",(std+i)->marks[j]);
        }
        printf("\naverage marks (best two out of three) : %.2f ",(std+i)->average);
    }
}

void calculateaverage(s std){
    int min,sum,besttwo;
    float avg;
    
    for(int i=0;i<n;i++){
        min=(std+i)->marks[0];
       /* for(int x=1;x<3;x++){
            if((std+i)->marks[x]>min){
                min=(std+i)->marks[x];
            }*/
            if((std+i)->marks[1]<min){
                min=(std+i)->marks[1];
            }
            if((std+i)->marks[2]<min){
                min=(std+i)->marks[2];
            }
             sum=(std+i)->marks[0]+(std+i)->marks[1]+(std+i)->marks[2];
            besttwo=sum-min;
            avg = besttwo/(2.0);
            (std+i)->average=avg;
            /*for(int y=0;y<n;y++){
                sum+=(std+i)->marks[y];
            }
          (std+i)->average=(sum-min)/(2.00);
           */
        }
    }


int main()
{
    s std;
    int choice;
    do{
        printf("\nmenu\n1.readinfo2.calculate average \n3.display info\n0exit\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:printf("\nenter the number of students: ");
                scanf("%d",&n);
                std=(struct student *)malloc(n*sizeof(struct student));
                read(std);
                break;
        case 2: calculateaverage(std);
                break;
        case 3: display(std);
                break;
        case 0: break;
        default: printf("invalid choice");
        }
    }while(choice!=0);
	return 0;
}
