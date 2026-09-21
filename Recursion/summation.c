#include <stdio.h>
int addition(int a)
{
    if(a == 0) return 0;
    else 
    return a + addition(a-1); // gotten 3 first it waits 
    // gotten 2 then it also waits 
    // gotten 1 then it also waits 
// they all waits until and unless the base condtion is not satisfied . and when the base condition 
// is hitted then it reverse back with the values like this 3 <-- 2 <-- 1 so it is like 
// 3 <-- 2+1 = 3 + 3 = 6 ANSWER 
}
int main()
{
    int a = 3;
    int c = addition(a);
    printf("%d", c);

    return 0;
}