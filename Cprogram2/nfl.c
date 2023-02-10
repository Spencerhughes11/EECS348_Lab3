#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TD 6
#define FG 3
#define SAFETY 2
#define TDXP 7
#define TD2 8


int main(){
    int user_score = 2;

    while (user_score != 0 && user_score != 1){    
    printf("Enter 0 or 1 to STOP\n");
    printf("Enter the NFL Score: \n");
    scanf("%d", &user_score);

    printf("\nPossible combinations of scoring plays: \n");
    for (int a = 0; a < user_score; a++){
        for (int b = 0; b < user_score; b++){
            for (int c = 0; c < user_score; c++){
                for (int d = 0; d < user_score; d++){
                    for (int e = 0; e < user_score; e++){
                        if (user_score == (a*TD2 + b*TDXP + c*TD + d*FG + e*SAFETY)){
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", a, b, c, d ,e);
                        }

                        }
                }
            }
        }
    }
}

    return 0;
}