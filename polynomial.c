//read 2 polynomial using array and add them

#include <stdio.h>

struct poly {
    int coeff;
    int expo;
} p[10], q[10], result[10];

int readPoly(struct poly po[10]) {
    int t1, i;
    printf("Enter the number of terms : ");
    scanf("%d", &t1);

    printf("Enter the coefficient and exponent in descending order:");

    for (i = 0; i < t1; i++) {
        printf("enter coeff(%d):", i + 1);
        scanf("%d", &po[i].coeff); // Use the parameter po instead of p
        printf("enter expo(%d):", i + 1);
        scanf("%d", &po[i].expo); // Use the parameter po instead of p
    }
    return (t1);
}

void display(struct poly po[], int term) {
    int k;
    for (k = 0; k < term - 1; k++) {
        if (po[k].coeff != 0) {
            if (po[k].expo == 0) {
                printf("%d", po[k].coeff);
            } else {
                printf("%d(x^%d) + ", po[k].coeff, po[k].expo);
            }
        }
    }

    if (po[term - 1].coeff != 0) {
        if (po[term - 1].expo == 0) {
            printf("%d", po[term - 1].coeff);
        } else {
            printf("%d(x^%d)", po[term - 1].coeff, po[term - 1].expo);
        }
    }

    printf("\n");
}

int addPoly(struct poly p[10], struct poly q[10], int t1, int t2, struct poly result[10]) {
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < t1 && j < t2) {
        if (p[i].expo == q[j].expo) {
            result[k].coeff = p[i].coeff + q[j].coeff;
            result[k].expo = p[i].expo;
            i++;
            j++;
        } else if (p[i].expo > q[j].expo) {
            result[k].coeff = p[i].coeff;
            result[k].expo = p[i].expo;
            i++;
        } else {
            result[k].coeff = q[j].coeff;
            result[k].expo = q[j].expo;
            j++;
        }
        k++;
    }

    while (i < t1) {
        result[k].coeff = p[i].coeff;
        result[k].expo = p[i].expo;
        i++;
        k++;
    }

    while (j < t2) {
        result[k].coeff = q[j].coeff;
        result[k].expo = q[j].expo;
        j++;
        k++;
    }

    return k; // Return the number of terms in the result polynomial after processing all terms.
}

int main() {
    int t1, t2, t3;
    t1 = readPoly(p);
    printf("First poly is:");
    display(p, t1);

    t2 = readPoly(q);
    printf("second poly:");
    display(q, t2);

    t3 = addPoly(p, q, t1, t2, result);

    printf("Result poly:");
    display(result, t3);
}
