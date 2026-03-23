#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    
    FILE *fp = fopen("RN-file.txt", "w");
    fprintf(fp, "CMPE485 - 1000 RNs U(0,1)\nGenerated: %s %s\n\n", __DATE__, __TIME__);
    
    printf("1000 RNs U(0,1) - 10 ROWS x 100 COLS:\n\n");
    
    for(int row=0; row<10; row++) {
        for(int col=0; col<100; col++) {
            double rn = (double)rand() / RAND_MAX;
            fprintf(fp, "%.6f\n", rn);
            printf("%.4f ", rn);
        }
        printf("\n");
    }
    
    fclose(fp);
    printf("\n✓ RN-file.txt CREATED (1000 numbers)\n");  // Fixed typo
    printf("Press ENTER to continue...");
    getchar();
    return 0;
}
