#include <stdio.h>
int trap(int height[], int n) 
{
    int left = 0, right = n - 1;
    int left_max = 0, right_max = 0;
    int water = 0;
    while (left < right) 
    {
        if (height[left] < height[right])
        {
            if (height[left] >= left_max)
                left_max = height[left];
            else
                water += left_max - height[left];
            left++;
        } else {
            if (height[right] >= right_max)
                right_max = height[right];
            else
                water += right_max - height[right];
            right--;
        }
    }
    return water;
}
int main() 
{
    int h1[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int n1 = sizeof(h1)/sizeof(h1[0]);
    printf("Test Case 1: Output = %d\n", trap(h1, n1));
  //spacing looks good
    int h2[] = {4,2,0,3,2,5};
    int n2 = sizeof(h2)/sizeof(h2[0]);
    printf("Test Case 2: Output = %d\n", trap(h2, n2));

    int h3[] = {1,1,1};
    int n3 = sizeof(h3)/sizeof(h3[0]);
    printf("Test Case 3: Output = %d\n", trap(h3, n3));

    int h4[] = {5};
    int n4 = sizeof(h4)/sizeof(h4[0]);
    printf("Test Case 4: Output = %d\n", trap(h4, n4));

    int h5[] = {2,0,2};
    int n5 = sizeof(h5)/sizeof(h5[0]);
    printf("Test Case 5: Output = %d\n", trap(h5, n5));

    int h6[] = {0,0,0,0};
    int n6 = sizeof(h6)/sizeof(h6[0]);
    printf("Edge Case 1: Output = %d\n", trap(h6, n6));

    int h7[] = {1,2,3,4,5};
    int n7 = sizeof(h7)/sizeof(h7[0]);
    printf("Edge Case 2: Output = %d\n", trap(h7, n7));

    int h8[] = {5,4,3,2,1};
    int n8 = sizeof(h8)/sizeof(h8[0]);
    printf("Edge Case 3: Output = %d\n", trap(h8, n8));

    return 0;
}
