#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("=== 3.1(2) READING RN-file.txt ===\n");
    
   
    FILE *fp = fopen("RN-file.txt", "r");
    if(!fp) {
        printf("ERROR: RN-file.txt missing! Run rand_no.c first.\n");
        return 1;
    }
    
    int bins1[10] = {0};
    double rn;
    char line[100];
    fgets(line, 100, fp); 
    fgets(line, 100, fp); 
    
    int count = 0;
    while(fscanf(fp, "%lf", &rn) == 1) {
        int bin = (int)(rn * 10);
        if(bin > 9) bin = 9;
        bins1[bin]++;
        count++;
    }
    fclose(fp);
    
    printf("Read %d numbers from RN-file.txt\n", count);
    printf("1K BINS (Expected=100):\n");
    printf("Bin# Range    Count\n");
    for(int i = 0; i < 10; i++) {
        printf(" %d  %.1f-%.1f  %4d\n", i+1, i*0.1, (i+1)*0.1, bins1[i]);
    }
    
   
    printf("\n=== 3.2 10K RNs ===\n");
    srand(time(NULL));
    FILE *fp10k = fopen("RN-file-10000.txt", "w");
    fprintf(fp10k, "CMPE485 - 10000 U(0,1) RNs\nGenerated: %s\n\n", __DATE__);
    
    int bins2[10] = {0};
    for(int i = 0; i < 10000; i++) {
        double rn = (double)rand() / RAND_MAX;
        fprintf(fp10k, "%.6f\n", rn);
        int bin = (int)(rn * 10);
        if(bin > 9) bin = 9;
        bins2[bin]++;
    }
    fclose(fp10k);
    
    printf("10K BINS (Expected=1000):\n");
    printf("Bin# Range    Count\n");
    for(int i = 0; i < 10; i++) {
        printf(" %d  %.1f-%.1f  %4d\n", i+1, i*0.1, (i+1)*0.1, bins2[i]);
    }
    
    
    double chi2 = 0;
    for(int i = 0; i < 10; i++) {
        double diff = bins2[i] - 1000.0;
        chi2 += (diff * diff) / 1000.0;
    }
    printf("\n=== 3.3 CHI-SQUARE TEST ===\n");
    printf("χ² = %.3f\n", chi2);
    printf("Critical value (9df, α=0.05) = 16.919\n");
    if(chi2 < 16.919) printf("✓ UNIFORM DISTRIBUTION ACCEPTED\n");
    
    printf("\nPress ENTER...");
    getchar();
    return 0;
}
