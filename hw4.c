/* 
 * File:   hw4.c
 * Author: umut öztürk 
 *THIS PROGRAMME IS DEVELOPED WITH NETBEANS IDE 8.2;
 * Created on 30 Kasım 2014 Pazar, 14:07
 */
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int control(char[], char[], char[], char[], int, int[]);
int recursive(int, int [], char[], char[], char[], char[], int, int[]);
int cut(char[], int, int);

int main(int argc, char *argv[]) {
    int a, b = 0, c, d, k, value1, value2, value3, value4;
    char characterSum[100];
    char character1[10];
    char character2[10];
    char character3[10];
    int uss = 0;
    while (1) {
        uss = 0;
        b = 0;
        int values[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        int digits[11] = {0};
        printf("\n\aEnter 1st input value:\t");
        scanf("%s", character1);
        printf("\aEnter 2nd input value:\t");
        scanf("%s", character2);
        printf("\aEnter Output value:\t");
        scanf("%s", character3);
        putchar(10);
        for (a = 0; a < strlen(character1); a++) {
            characterSum[b] = character1[a];
            b++;

        }
        for (a = 0; a < strlen(character2); a++) {
            characterSum[b] = character2[a];
            b++;

        }
        for (a = 0; a < strlen(character3); a++) {
            characterSum[b] = character3[a];
            b++;

        }

        for (a = 0; a < (b - 1); a++) {

            for (k = a + 1; k < (b); k++) {

                if (characterSum[k] == characterSum[a]) {
                    b = cut(characterSum, k, b);
                    k--;
                }
            }
        }
        uss = b;


        value1 = strlen(character1);
        value2 = strlen(character2);
        value3 = strlen(character3);
        value4 = uss;
        /*The length of all words must be greater than or equal to 2 
        The length of all words must be less than or equal to 6.
       Total number of different letters in all words must be less than or equal to 10.
         */
        if (value1 >= 2 && value2 >= 2 && value1 <= 6 && value2 <= 6 && value4 <= 10 && value3 >= value1 && value3 >= value2) {
            if (recursive(0, values, characterSum, character1, character2, character3, uss, digits) == 1) {
                break;

            }
        }
    }
    putchar(10);
    system("PAUSE");
    return 0;
}

/* This is the "not-very-smart" version of cryptarithmetic solver. It takes
 the puzzle itself (with the 3 strings for the two addends and sum) and a
 string of letters as yet unassigned. If no more letters to assign
 then we've hit a base-case, if the current letter-to-digit mapping solves
 the puzzle, we're done, otherwise we return false.
I used  brute forces */

int recursive(int index, int value1[10], char characterSumd[], char character1d[], char character2d[], char character3d[], int ussd, int digitsd[]) {
    int a, b, d;
    int found = 0;
    int out = 0;
    int value2[10];
    int i;
    int j;

    for (i = 0; i < 10; i++) {
        if (value1[i] == 0) {//check values before;it will be character={1,1,1,1,1,1,1,1,1);
            for (j = 0; j < 10; j++) {
                value2[j] = value1[j];
            }
            value2[i] = 1;

            digitsd[index] = i;

            if (index == (ussd - 1)) {
                if (control(characterSumd, character1d, character2d, character3d, ussd, digitsd) == 1) {
                    a = 0;
                    b = 0;
                    d = 0;
                    found = 0;


                    a = 0;
                    //The leftmost letter can not be zero in any word
                    while (character1d[a] != '\0') {
                        for (b = 0; b < ussd; b++) {
                            if (character1d[a] == characterSumd[b]) {
                                if (digitsd[b] == 0 && a == 0) {
                                    found = 1;
                                    break;
                                }

                            }
                        }
                        if (found > 0) {
                            break;
                        }
                        a++;
                    }

                    a = 0;
                    while (character2d[a] != '\0') {
                        for (b = 0; b < ussd; b++) {

                            if (character2d[a] == characterSumd[b]) {
                                if (digitsd[b] == 0 && a == 0) {
                                    found = 1;
                                    break;
                                }

                            }
                        }
                        if (found > 0) {
                            break;
                        }
                        a++;
                    }

                    a = 0;
                    while (character3d[a] != '\0') {
                        for (b = 0; b < ussd; b++) {

                            if (character3d[a] == characterSumd[b]) {
                                if (digitsd[b] == 0 && a == 0) {
                                    found = 1;
                                    break;
                                }
                            }
                        }
                        if (found > 0) {
                            break;
                        }
                        a++;
                    }
                    if (found == 0) {
                        printf("\n\nsearching...found!\n\n");
                        for (a = 0; a < strlen(character1d); a++) {
                            printf("%c", character1d[a]);
                        }
                        printf(":");
                        a = 0;
                        while (character1d[a] != '\0') {
                            for (b = 0; b < ussd; b++) {
                                if (character1d[a] == characterSumd[b]) {
                                    printf("%d", digitsd[b]);
                                    break;
                                }
                            }


                            a++;
                        }
                        putchar(10);

                        for (a = 0; a < strlen(character2d); a++) {
                            printf("%c", character2d[a]);
                        }
                        printf(":");
                        a = 0;
                        while (character2d[a] != '\0') {
                            for (b = 0; b < ussd; b++) {

                                if (character2d[a] == characterSumd[b]) {
                                    printf("%d", digitsd[b]);
                                    break;

                                }
                            }

                            a++;
                        }
                        putchar(10);

                        for (a = 0; a < strlen(character3d); a++) {
                            printf("%c", character3d[a]);
                        }
                        printf(":");
                        a = 0;
                        while (character3d[a] != '\0') {
                            for (b = 0; b < ussd; b++) {

                                if (character3d[a] == characterSumd[b]) {
                                    printf("%d", digitsd[b]);
                                    break;
                                }
                            }

                            a++;
                        }

                    
                     out = 1;
                    }
                  

                }

            } else {
                if (recursive(index + 1, value2, characterSumd, character1d, character2d, character3d, ussd, digitsd) == 1) {
                    out = 1;

                }
            }
        }
    }

    if (out == 1) {
        return 1;
    } else {
        return 0;
    }

}
//control functions controls that every character corresponds with some digits

int control(char characterSumd[], char character1d[], char character2d[], char character3d[], int ussd, int digitsd[]) {
    int a, f, c, d, k, e;
    int sum1 = 0, sum2 = 0, sum3 = 0;
    int top = 1;
    //a=strlen(character1) 
    //Because the rest of characters is units digit...
    /*For example;
     * SEND
     + MORE
    --------
      MONEY 
     * digits[10]={0,1,8,5,3,4,2,9,7}
     * characterSum[10]={S,E,N,D,M,O,R,Y)
     * Digit[4]=3 and characterSum[4]='S'
     * the character 'S' refers to the digit 3 with the same index!!!
     */

    for (a = strlen(character1d) - 1; a >= 0; a--) {
        for (f = 0; f < ussd; f++) {

            if (characterSumd[f] == character1d[a]) {
                break;
            }
        }
        sum1 += top * digitsd[f];
        top *= 10;
    }
    top = 1;
    for (a = strlen(character2d) - 1; a >= 0; a--) {
        for (f = 0; f < ussd; f++) {
            if (characterSumd[f] == character2d[a]) {
                break;
            }
        }
        sum2 += top * digitsd[f];
        top *= 10;
    }
    top = 1;
    for (a = strlen(character3d) - 1; a >= 0; a--) {
        for (f = 0; f < ussd; f++) {
            if (characterSumd[f] == character3d[a]) {
                break;
            }
        }
        sum3 += top * digitsd[f];
        top *= 10;
    }


    if (sum1 + sum2 == sum3) {

        return 1;
    } else {
        return 0;
    }

}
//it is used shifting method in Cut Function
//So characterSum strings have different characters

int cut(char character[100], int kd, int bd) {

    int a;
    for (a = kd + 1; a < bd; a++) {
        character[a - 1] = character[a];
    }

    return bd - 1;
}