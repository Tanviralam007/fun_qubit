#include <stdio.h>
#include <math.h>
/*
         |+>   |+>
|0> --> H --> X --> H --> |0> (head)
*/

struct qubit{
    float x;
    float y;
};

typedef struct qubit qubit;

void printQubit(qubit q){
    printf("[%.1f, %.1f]\n", q.x, q.y);
}

qubit hadamard(qubit q){
    qubit r;
    r.x = 1/sqrt(2) * q.x + 1/sqrt(2) * q.y;
    r.y = 1/sqrt(2) * q.x - 1/sqrt(2) * q.y;
    return r;
}

// pauli-X operation on qubit q
/*
where, 
X = [0 1
     1 0]
*/
qubit pauli_X(qubit q){
    qubit r;
    r.x = 0.0 * q.x + 1.0 * q.y;
    r.y = 1.0 * q.x + 0.0 * q.y;
    return r;
}

int main(){
    // starting with |0> state [1.0, 0.0]
    qubit q1 = {1.0, 0.0};
    qubit result_1 = hadamard(q1);
    qubit result_2 = pauli_X(result_1);
    result_2 = hadamard(result_2);
    printQubit(result_2); // expected result [1.000, 0.000]

}

