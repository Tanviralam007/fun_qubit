#include <stdio.h>

struct qubit{
    // Probability amplitude
    float x;  
    float y; 
};
typedef struct qubit qubit;

/**
 * Print qubit state with formatted output
 * q Qubit to be printed
 */
void print_qubit(qubit q){
    printf("[%.1f, %.1f]\n", q.x, q.y);
}

/**
 * Pauli-X Gate (Quantum NOT Gate) Operation
 * q Input qubit
 * Transformed qubit after X gate application
 * 
 * Pauli-X Gate Matrix:
 * X = [0 1]
 *     [1 0]
 * Effectively swaps |0⟩ and |1⟩ states
 */
qubit pauli_X(qubit q){
    qubit r;
    r.x = 0.0 * q.x + 1.0 * q.y;
    r.y = 1.0 * q.x + 0.0 * q.y;
    return r;
}

int main(){
    // Quantum State Demonstration
    // starting with |0> state expects result to be 0.0, 1.0   
    qubit q1 = {1.0, 0.0}; 
    qubit result = pauli_X(q1);
    print_qubit(result);

     // expecting 1.0, 0.0
    result = pauli_X(result);
    print_qubit(result);

    printf("\n");
    // starting with |1> state expects result to be 1.0, 0.0
    qubit q2 = {0.0, 1.0};
    result = pauli_X(q2);
    print_qubit(result);

    // expecting 0.0, 1.0
    result = pauli_X(result);
    print_qubit(result);
}