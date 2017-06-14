#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
		// ensure proper usage
		if (argc != 4)
		{
				printf("Usage:resize n infile outfile\n");
				return 1;
		}

		int n = atoi(argv[1]);
		char* infile = argv[2];
		char* outfile = argv[3];
		if(n < 0 || n > 100)
		{
				printf("The resize n should be a positive integer <= 100.\n");
				return 2;
		}


		// open input file 
		FILE* inptr = fopen(infile, "r");
		if (inptr == NULL)
		{
				printf("Could not open %s.\n", infile);
				return 3;
		}

		// open output file
		FILE* outptr = fopen(outfile, "w");
		if (outptr == NULL)
		{
				fclose(inptr);
				fprintf(stderr, "Could not create %s.\n", outfile);
				return 4;
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

		BITMAPFILEHEADER bfout;
		BITMAPINFOHEADER biout;	
		bfout=bf;
		biout=bi;
		biout.biWidth=bi.biWidth * n;
		biout.biHeight=bi.biHeight * n;

		int padin = (4-(bi.biWidth*sizeof(RGBTRIPLE))%4)%4;
		int padout = (4-(biout.biWidth*sizeof(RGBTRIPLE))%4)%4;

		 // update image size
         biout.biSizeImage = abs(biout.biHeight) * ((biout.biWidth * sizeof (RGBTRIPLE)) + padout);
    
         // update file size
           bfout.bfSize = biout.biSizeImage + sizeof (BITMAPFILEHEADER) + sizeof (BITMAPINFOHEADER); 
    

		// write outfile's BITMAPFILEHEADER
		fwrite(&bfout, sizeof(BITMAPFILEHEADER), 1, outptr);

		// write outfile's BITMAPINFOHEADER
		fwrite(&biout, sizeof(BITMAPINFOHEADER), 1, outptr);

		for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
		{
				for(int iter1 = 0; iter1 < n; iter1++)
				{
						// iterate over pixels in scanline
						for (int j = 0; j < bi.biWidth; j++)
						{
								// temporary storage
								RGBTRIPLE triple;

								// read RGB triple from infile
								fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

								// write RGB triple to outfile
								for(int iter2 = 0; iter2 < n; iter2++) 
								{
										fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
								}
						}

						// skip over padding in infile
						fseek(inptr, padin, SEEK_CUR);

						// then add it to outfile
						for (int k = 0; k <padout; k++)
								fputc(0x00, outptr);

						fseek(inptr, -(bi.biWidth * 3 + padin ), SEEK_CUR);

				}
				fseek(inptr, bi.biWidth*3+padin, SEEK_CUR);
		}

		// close infile
		fclose(inptr);

		// close outfile
		fclose(outptr);

		return 0;
}