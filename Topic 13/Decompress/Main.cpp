/* William Bowen - ITSE 34699 - Topic 13
   Decompress implementation.
 */

#include <iostream>
using namespace std;

int main()
{
    // declare variables
    unsigned short buffer = 0, bufferCopy = 0;  // these hold the bits
    int bits = 0; // used for both unprocessed bits and shifting
    unsigned char secretMessage[25] = {9,0,207,176,159,163,255,33,58,115,
                                       199,255,255,181,223,67,102,69,173,
                                       6,35,103,245,160,164}; //the message

    // for loop through array, adding and processing bits
    for (int i = 0; i <= 24; i++)
     {
         // add the current array index value to the bit buffer
         buffer <<= 8;               // shift buffer 8 bits
         buffer |= secretMessage[i]; // OR the next 8 bits
         bits += 8;                  // increase bit count by eight

         while (bits >= 5)           // process all available 5 bit blocks
         {
            bufferCopy = buffer;    // copy buffer so we can process it
            bits -= 5;              // subtract 5 from bits (now a shift value)
            bufferCopy >>= bits;    // shift bufferCopy right by bits value
                                    // leaving exactly 5 bits to "decode"
            (bufferCopy == 31) ?           // simple if : else processes bits
            cout << (char)(bufferCopy+1) : // ascii 32 is a space
            cout << (char)(bufferCopy+65); // 65-90 are caps
                                    // cleanup the buffer
            buffer <<= (16 - bits); // bounce the buffer left to clear the
            buffer >>= (16 - bits); // processed bits, then same amount right
            // to reset the buffer (far easier IMHO than working out a mask)
         } // end while
     } // end for

    return 0;
}  // end main
