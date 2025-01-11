#include <stdio.h>
#include <math.h>

struct qubit{
    float x;
    float y;
};
typedef struct qubit qubit;

void printQubit(qubit q){
    printf("[%.1f, %.1f]\n", q.x, q.y);
}

// pauli-X to a qubit thats in the superposition |+>
// which returns X . (|+>) = |+> (0.707, 0.707)
/*
where, 
X = [0 1
     1 0]
*/

qubit pauli_X_AND_Superposition(qubit q){
    qubit r;
    r.x = 0.0 * q.x + 1.0 * q.y;
    r.y = 1.0 * q.x + 0.0 * q.y;
    return r;
}

int main()
{   
    qubit q1 = {0.707, 0.707};
    qubit result = pauli_X_AND_Superposition(q1);
    printQubit(result); // expected result: [0.707, 0.707]

    return 0;
}