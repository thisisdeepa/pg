#include<stdio.h>
#include<math.h>
int step=0;
int num;
void MoveTower(int n,char source,char dest, char temp)
{
    if(n==1)
    {
        step++;
        printf("\n Step #%d disc %d from source:%c to destination:%c\n:",step,n,source,dest);
        return;
    }
    MoveTower(n-1,source,temp,dest);
    step++;
    if(step==(pow(2,num)/2))
    {
        printf("\nStep # %d is a special move",step);
        printf("\n moves the last disc 'n'=%d from source:%c to destination:%c, where it stays!\n:",n,source,dest);
        printf("\n It takes %d steps to move 'n-1',here %d discs from source:%c to temp:%c\n:",step-1,n-1,source,temp);
    }
    else 
    {
        printf("\n Step #%d disc %d from source:%c to destination:%c\n:",step,n,source,dest);
    }
     MoveTower(n-1,temp,dest,source);
}
int main()
{
     int n=0;
     printf("\nEnter the number of disks");
     scanf("%d",&num);
     n=num;
     MoveTower(n,'A','B','C');
     
}