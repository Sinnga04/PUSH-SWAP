/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamsingh <kamsingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:35:58 by kamsingh          #+#    #+#             */
/*   Updated: 2024/03/13 17:32:44 by kamsingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Stack {
    Node *top;
} Stack;

Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printNodeInfo(Node *node) {
    if (node == NULL) {
        printf("NULL\n");
    } else {
        printf("%d\n", node->data);
    }
}

Node *findNearestNode(Stack *stackA, int numberB) {
    Node *nearestNode = NULL; // Pointer to the nearest node in stackA
    int minDifference = INT_MAX; // Initialize minDifference to the maximum possible value
    Node *currentA = stackA->top; // Pointer to traverse stackA

    // If stackA is empty, return NULL
    if (stackA->top == NULL) {
        return NULL; 
    }

    // Iterate over all nodes in stackA
    while (currentA != NULL) {
        // Calculate the absolute difference between the data of the current node in stackA and the given number from stackB
        int difference = abs(currentA->data - numberB);

        // Update nearestNode and minDifference if the current node in stackA is closer to the given number from stackB
        if (difference < minDifference) {
            minDifference = difference;
            nearestNode = currentA;
        }

        currentA = currentA->next; // Move to the next node in stackA
    }

    return nearestNode;
}

int main() {
    // Create Stack A
    Stack stackA;
    stackA.top = createNode(1);
    stackA.top->next = createNode(3);
    stackA.top->next->next = createNode(5);

    // Create Stack B
    Stack stackB;
    stackB.top = createNode(2);
    stackB.top->next = createNode(4);
    stackB.top->next->next = createNode(7);

    // Iterate over all nodes in Stack B
    Node *currentB = stackB.top;
    while (currentB != NULL) {
        // Find the nearest node in Stack A to the current number from Stack B
        Node *nearestNode = findNearestNode(&stackA, currentB->data);

        // Print information about the nearest node
        printf("Nearest Node in Stack A to %d from Stack B: ", currentB->data);
        printNodeInfo(nearestNode);

        currentB = currentB->next; // Move to the next node in Stack B
    }

    // Free memory (optional)
    Node *temp;
    while (stackA.top != NULL) {
        temp = stackA.top;
        stackA.top = stackA.top->next;
        free(temp);
    }
    while (stackB.top != NULL) {
        temp = stackB.top;
        stackB.top = stackB.top->next;
        free(temp);
    }

    return 0;
}
