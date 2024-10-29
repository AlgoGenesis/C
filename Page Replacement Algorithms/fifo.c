#include <stdio.h>
int main()
    {
    int inp_size=0;
    int fsize=0;
    int found=0;
    int oldest_ind=0;

    printf("Enter input size.\n");
    scanf("%d",&inp_size);
    int inp[inp_size];

    printf("Enter the input.\n");
    for(int i=0;i<inp_size;i++){
        scanf("%d",&inp[i]);
    }
    printf("Enter frame size.\n");
    scanf("%d",&fsize);    

    int frames[fsize];

    //initialise the frames array with -1
    for(int i=0;i<fsize;i++){
        frames[i]=-1;
    }

    int page, miss=0;
    for(int i=0;i<inp_size;i++){
        //for each input initialise found to 0
        found=0;

        //iterate through the frames, searching if the current input is already present.
        for(int j=0;j<fsize;j++){
            if(frames[j]==inp[i]){
                found =1;
                break;
            }
        }

        if(found)
        printf("%d already in frames\n",inp[i]);

        else{
            //if the frame was not found, increment miss count.
            miss++;

            //remove the frame that has been in memory for the longest amount of time
            if(frames[oldest_ind]!=-1)
            printf("The frame that will be removed is %d\n",frames[oldest_ind]);
            frames[oldest_ind]=inp[i];

            //increment the next index which will be removed and ensure to take modulus with frame size
            //so the index remains within bounds.
            oldest_ind=(oldest_ind+1)%fsize;

            printf("%d->",inp[i]);

            //print the current frame picture
            for(int j=0;j<fsize;j++){
                if(frames[j]!=-1)
                printf("%d ",frames[j]);
            }

            printf("\n");
        }
    }

    printf("\nThe total number of page faults is %d\n",miss);
    printf("The total number of hits is %d",inp_size-miss);
}