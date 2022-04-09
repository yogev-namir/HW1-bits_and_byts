#include <stdio.h>


int bitAND(int x, int y) {
/* returns: ~(~x|~y) based on De Morgan's laws the func calculating the outcome
 * of bitwise AND operand using only ~ | operators, the returned value is equal to x&y*/
    return ~(~x|~y);
}

int getByte(int x, int n){
    /*returns: (x & (mask<<(n<<3)))>>(n>>3) & mask,
     * reading the n byte(0->3) frm 32 bits word.
     * 3 is the number of shift to get from the LSB to the MSB
     * in the returned number the MSB gets a weight of 2^7 instead of a sign bit*/
    int mask = 0xFF;
    return ((x & (mask<<(n<<3)))>>(n<<3)) & mask;
}

int logicalShift(int x, int n){
    /* returns: ~(~ x | mask), shifting int num n bits right and replacing the left bits with zeros */
    int mask = ((1<<31)>>n)<<1;//the shifting n to the left and then 1 right is replacing n-1 right shifts

    return x & ~mask;
}

int main(){
    printf("%x\n", bitAND(5,6));
    printf("%x\n",getByte(0x12345678,1));
    printf("%x",logicalShift(0x87654321,4));
}
