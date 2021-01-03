#include <stdio.h>


int RemoveElement(int nums[], int oldnums[], int val)
{
    int i = 0;
    int check = 0;
    int newVal = 0;
    int newLength = 0;
    int currentIndex = 0;
    int nextIndex = 0;
    int end = 0;

     //get initial length of array
    while(oldnums[i]!='\0')
    {
        i++;
    }
    end = i;
   
    nextIndex = currentIndex + 1;

    //rearrange so that target values are at the end of the array
    while(currentIndex<=end)
    {

        if(oldnums[currentIndex]!=val)// not the target value
        {
            currentIndex++;
            nextIndex++;
        }
        else// is the target value
        {
            
            //if last item in the array
            if(currentIndex == end|nextIndex > end)
            {
                if(nextIndex > end)
                {
                    nextIndex = currentIndex;
                    while(nextIndex<=end)
                    {
                        nums[nextIndex]= 0;
                        nextIndex++;
                    }

                }
                
                nums[currentIndex]=0;
            }
            //if not the last item in the array
            else
            {
                
                //if nextIndex is not the target value use it
                if(oldnums[nextIndex]!=val)
                {
                    newVal = oldnums[nextIndex];
                    oldnums[nextIndex] = val;
                    nums[currentIndex] = newVal;
                    currentIndex++;
                    nextIndex++;
                }
                else //nextIndex is also the target value
                {
                    nextIndex++;
                }
                

            }
            
            
        }
    }

    //get newLength
    i = 0;
    while(oldnums[i]!='\0')
    {
        i++;
    }
    newLength = i;
    


    return newLength;
}

int main(void)
{
  int nums[5] = {1,6,9,4};
  int val = 9;
  int i = 0;
  int newLength = 0;

  size_t n = sizeof(nums)/sizeof(nums[0]);
  

  printf("Starting length: %d \n", (int)n);
  newLength = RemoveElement(&nums[0],nums,val);
  while(i<=4)
  {
      printf(" %d,",nums[i]);
      i++;
  }
  printf("\n");
  printf("New Length: %d\n", newLength);


    return 0;
}