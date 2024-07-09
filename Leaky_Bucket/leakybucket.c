 
#include<stdio.h> 
int main() 
{ 
    int bucket_size,n,outgoing,incoming,store=0; 
    printf("Enter Bucket Zize : "); 
    scanf("%d",&bucket_size); 
    printf("Enter Outgoing Rate : "); 
    scanf("%d",&outgoing); 
    printf("Enter No: of Inputs : "); 
    scanf("%d",&n); 
    while(n!=0) 
    { 
        printf("\nEnter Incoming Packet Size : "); 
        scanf("%d",&incoming); 
        printf("\nIncoming Packet Size : %d\n",incoming); 
        if(incoming<=(bucket_size-store)) 
        { 
            store+=incoming; 
            printf("Bucket Buffer Size %d out of %d\n",store,bucket_size); 
        } 
        else 
        { 
            printf("Dropped %d no: of packets.\n",incoming-(bucket_size-store)); 
            printf("Bucket Buffer Size %d out of %d\n",store,bucket_size); 
            store=bucket_size; 
        } 
        store=store-outgoing; 
        printf("After Outgoing %d Packets Left out of %d in Buffer..\n\n",store,bucket_size); 
    } 
} 
/*output
Enter Bucket Zize : 3
Enter Outgoing Rate : 2
Enter No: of Inputs : 5

Enter Incoming Packet Size : 5

Incoming Packet Size : 5
Dropped 2 no: of packets.
Bucket Buffer Size 0 out of 3
After Outgoing 1 Packets Left out of 3 in Buffer..


Enter Incoming Packet Size : 4

Incoming Packet Size : 4
Dropped 2 no: of packets.
Bucket Buffer Size 1 out of 3
After Outgoing 1 Packets Left out of 3 in Buffer..


Enter Incoming Packet Size : 3

Incoming Packet Size : 3
Dropped 1 no: of packets.
Bucket Buffer Size 1 out of 3
After Outgoing 1 Packets Left out of 3 in Buffer..


Enter Incoming Packet Size : 2

Incoming Packet Size : 2
Bucket Buffer Size 3 out of 3
After Outgoing 1 Packets Left out of 3 in Buffer..


Enter Incoming Packet Size : 1

Incoming Packet Size : 1
Bucket Buffer Size 2 out of 3
After Outgoing 0 Packets Left out of 3 in Buffer..
*/