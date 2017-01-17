/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
 
#define SIZE 512
int main(int argc, char* argv[])
{
   //file names
    FILE* file;
    FILE* img = NULL;
    //jpeg pattern of bytes
    int pattern[3] = {0xff,0xd8,0xff};
    //
    uint8_t buffer[512];
    int count = 0;
    char  title[12];
    
    //open memory card file..
    if ((file = fopen("card.raw", "r")) == NULL)
    {
        printf("\n File unable to open ");
    }
    
    
    while((!feof(file)) && (fread(buffer, SIZE, 1,file)))
    {
        //find begining of jpg using "pattern"
        if(buffer[0] == pattern[0] && buffer[1] == pattern[1] && buffer[2] == pattern[2])
        {
            //close if img is not empty
            if(img != NULL)  
                fclose(img);
            //print to current directory
            sprintf(title, "%03d.jpg",count);
            
        //open and write into img
        img = fopen(title,"w");
        
        count++;
        }
         if(img != NULL)
            fwrite(buffer, SIZE, 1,img);
    }
    if(img != NULL)  
        fclose(img);
    
    fclose(file);
    return 0;
            
}
