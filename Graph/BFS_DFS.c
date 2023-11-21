#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct AdjList {
    struct Node* head;
};

int q[20], top = -1, front = -1, rear = -1, vis[20], stack[20];
struct AdjList adjList[20];
int a[20][20]; // Adjacency matrix

int delete();
void add(int item);
void bfs_matrix(int s, int n);
void bfs_list(int s, int n);
void dfs_matrix(int s, int n);
void dfs_list(int s, int n);
void push(int item);
int pop();
void printAdjList(int n);

void main() {
    int n, i, s, ch, j;
    char c, dummy;
    printf("Enter the no. of vertices : ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        adjList[i].head = NULL;
        for (j = 1; j <= n; j++) {
            printf("ENTER 1 IF %d HAS A NODE WITH %d ELSE 0 : ", i, j);
            scanf("%d", &a[i][j]);
            if (a[i][j] == 1) {
                struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
                newNode->data = j;
                newNode->next = adjList[i].head;
                adjList[i].head = newNode;
            }
        }
    }

    printf("THE ADJACENCY MATRIX IS : \n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            printf(" %d", a[i][j]);
        }
        printf("\n");
    }
    
    printf("THE ADJACENCY LIST IS : \n");
    printAdjList(n);

    do {
        for (i = 1; i <= n; i++)
            vis[i] = 0;
        printf("\nMENU");
        printf("\n1.B.F.S (Adjacency Matrix)");
        printf("\n2.B.F.S (Adjacency List)");
        printf("\n3.D.F.S (Adjacency Matrix)");
        printf("\n4.D.F.S (Adjacency List)");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        printf("Enter the start vertex : ");
        scanf("%d", &s);

        switch (ch) {
            case 1:
                printf("\nBFS using Adjacency Matrix:\n");
                bfs_matrix(s, n);
                break;
            case 2:
                printf("\nBFS using Adjacency List:\n");
                bfs_list(s, n);
                break;
            case 3:
                printf("\nDFS using Adjacency Matrix:\n");
                dfs_matrix(s, n);
                break;
            case 4:
                printf("\nDFS using Adjacency List:\n");
                dfs_list(s, n);
                break;
        }
        printf("\nDO U WANT TO CONTINUE(Y/N) ?: ");
        scanf(" %c", &c); // Add a space before %c to skip the newline character
    } while (c == 'y' || c == 'Y');
}

void bfs_matrix(int s, int n) {
    // BFS using adjacency matrix 
    int p, i;
    add(s);
    vis[s] = 1;
    p = delete();
    if (p != 0)
        printf(" %d", p);
    while (p != 0) {
        for (i = 1; i <= n; i++) {
            if (a[p][i] != 0 && vis[i] == 0) {
                add(i);
                vis[i] = 1;
            }
        }
        p = delete();
        if (p != 0)
            printf(" %d ", p);
    }
    for (i = 1; i <= n; i++)
        if (vis[i] == 0)
            bfs_matrix(i, n);
}

void bfs_list(int s, int n) {
    // BFS using adjacency list
    int p, i;
    add(s);
    vis[s] = 1;
    p = delete();
    if (p != 0)
        printf(" %d", p);
    while (p != 0) {
        struct Node* current = adjList[p].head;
        while (current != NULL) {
            if (vis[current->data] == 0) {
                add(current->data);
                vis[current->data] = 1;
            }
            current = current->next;
        }
        p = delete();
        if (p != 0)
            printf(" %d ", p);
    }
    for (i = 1; i <= n; i++)
        if (vis[i] == 0)
            bfs_list(i, n);
}

void dfs_matrix(int s, int n) {
    // DFS using adjacency matrix 
    int i, k;
    push(s);
    vis[s] = 1;
    k = pop();
    if (k != 0)
        printf(" %d ", k);
    while (k != 0) {
        for (i = 1; i <= n; i++) {
            if (a[k][i] != 0 && vis[i] == 0) {
                push(i);
                vis[i] = 1;
            }
        }
        k = pop();
        if (k != 0)
            printf(" %d ", k);
    }
    for (i = 1; i <= n; i++)
        if (vis[i] == 0)
            dfs_matrix(i, n);
}

void dfs_list(int s, int n) {
    // DFS using adjacency list
    int i, k;
    push(s);
    vis[s] = 1;
    k = pop();
    if (k != 0)
        printf(" %d ", k);
    while (k != 0) {
        struct Node* current = adjList[k].head;
        while (current != NULL) {
            if (vis[current->data] == 0) {
                push(current->data);
                vis[current->data] = 1;
            }
            current = current->next;
        }
        k = pop();
        if (k != 0)
            printf(" %d ", k);
    }
    for (i = 1; i <= n; i++)
        if (vis[i] == 0)
            dfs_list(i, n);
}

void add(int item) {
    if (rear == 19)
        printf("QUEUE FULL");
    else {
        if (rear == -1) {
            q[++rear] = item;
            front++;
        } else
            q[++rear] = item;
    }
}

int delete() {
    int k;
    if (front > rear || front == -1)
        return (0);
    else {
        k = q[front++];
        return (k);
    }
}

void push(int item) {
    if (top == 19)
        printf("Stack overflow ");
    else
        stack[++top] = item;
}

int pop() {
    int k;
    if (top == -1)
        return (0);
    else {
        k = stack[top--];
        return (k);
    }
}

void printAdjList(int n) {
    for (int i = 1; i <= n; i++) {
        printf("Vertex %d: ", i);
        struct Node* current = adjList[i].head;
        while (current != NULL) {
            printf("%d -> ", current->data);
            current = current->next;
        }
        printf("NULL\n");
    }
}
