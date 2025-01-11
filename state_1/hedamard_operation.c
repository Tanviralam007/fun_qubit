#include <stdio.h>
#include <math.h>

struct qubit{
    // Probability amplitude
    float x; 
    float y; 
};
typedef struct qubit qubit;

void printQubit(qubit q){
    printf("[%.1f, %.1f]\n", q.x, q.y);
}

// Hedamard gate operation on qubit q
// H(|0>) = 1/sqrt(2), 1/sqrt(2)
// Nither |0> nor |1>, middle of the |0> and |1>

qubit hadamard(qubit q){
    qubit r;
    r.x = 1/sqrt(2) * q.x + 1/sqrt(2) * q.y;
    r.y = 1/sqrt(2) * q.x - 1/sqrt(2) * q.y;
    return r;
}

int main(){
    // starting with |0> state expect result to be 0.707, 0.707
    qubit q1 = {1.0, 0.0};
    qubit result = hadamard(q1);
    printQubit(result); // expected result: [0.707, 0.707] which is |+>

    qubit q2 = result;
    result = hadamard(q2);
    printQubit(result); // expected result: [0.0, 1.0] which is |0>

    return 0;
}