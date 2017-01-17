/**
 * copy.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    int n = atoi(argv[1]);
    
    if (argc != 4)

    {
        printf("Usage: ./copy n infile outfile\n");
        return 1;
    }
    
    if(n < 0 || n > 100)
    {
        printf("n must be  positive and less than 100\n");
        return 1;
    }
        

    // remember filenames
    char* infile = argv[2];
    char* outfile = argv[3];

    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    //delcare new datatype
    BITMAPINFOHEADER newbi;
    //modifying the BITMAPINFOHEADER
    newbi = bi;
     //specify new width and height ( Note: "n" is argv[1] )
    newbi.biWidth =   bi.biWidth * n;
    newbi.biHeight =  abs(bi.biHeight) * n;
    
    // determine old and new padding for scanlines
    int mod = 4;
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % mod) % mod;
    
    int newPadding = (4 - (newbi.biWidth * sizeof(RGBTRIPLE)) % mod) % mod;
    
    //creating new size
    newbi.biSizeImage = (newbi.biWidth * sizeof(RGBTRIPLE) + newPadding) * abs(newbi.biHeight);
    
    //delcare new datatype
    BITMAPFILEHEADER newbf;
    
    newbf = bf;
    // since BITMAPFILEHEADER = 40 and BITMAPINFOHEADER = 14 (40 + 14 = 54)
    newbf.bfSize = newbi.biSizeImage + 54;
    
    // write outfile's BITMAPFILEHEADER
    fwrite(&newbf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&newbi, sizeof(BITMAPINFOHEADER), 1, outptr);
    // iterate over infile's scanlines
     for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        // Read each scanline factor times
        for (int j = 0; j < n; j++)
        {  
            // iterate over pixels in scanline
            for (int k = 0; k < bi.biWidth; k++)
            {
                // temporary storage
                RGBTRIPLE triple;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                // write RGB triple to outfile, multiplied by factor
                for (int l = 0; l < n; l++)
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);    
            }
            
            // fill in space by padding
            for (int pad = 0; pad < newPadding; pad++)
                fputc(0x00, outptr);
            
            // start over for every iteration (Note: n is argv[1])
            if (j + 1 < n)
                fseek(inptr, -bi.biWidth * sizeof(RGBTRIPLE), SEEK_CUR);
        }

        // Skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}