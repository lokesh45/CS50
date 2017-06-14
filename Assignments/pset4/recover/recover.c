#include <stdio.h>
#include <stdint.h>
 
int main(int argc, char *argv[])
 {
    FILE *fr;
     // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }
    if ((fr = fopen(argv[1], "r")) == NULL)
    {
        fprintf(stderr,"Cannot open the file...\n");
        return 1;
    }
    
    uint8_t buf[512];
    
    int count = 0;
    FILE *fw = NULL;
    
    while (fread(buf, 512, 1, fr))
    {
        // Check first four bytes are a JPEG signature
        if (buf[0] == 0xff && buf[1] == 0xd8 && buf[2] == 0xff && (buf[3] & 0xe0) == 0xe0)
        {
            if (fw != NULL)
                fclose(fw);
            char samplefile[8];
            sprintf(samplefile, "%03d.jpg", count);
            // Open a new JPEG file
            fw = fopen(samplefile, "w");
            count++;
        }
        if (fw != NULL)
            fwrite(buf, 512, 1, fw);
    }
    
    if (fw != NULL)
        fclose(fw);
    
    fclose(fr);
    return 0;
 } 