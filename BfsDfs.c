#include <stdio.h>
#include <stdlib.h>
struct vertex
{
    char c;
    struct vertex *relation[20];
    char col, predecessor;
    int distance, dTime, fTime;
};
int time = 0, dopi = 0;
char dop[20] = "";
void graphGen(struct vertex *vertexG[], int n)
{
    char relate[20];
    for (int i = 0; i < n; i++)
    {
        struct vertex *node = malloc(sizeof(struct vertex));
        printf("Enter the vertex data-");
        getchar();
        scanf("%c", &node->c);
        vertexG[i] = node;
    }
    getchar();
    for (int i = 0; i < n; i++)
    {
        struct vertex *temp = vertexG[i];
        int ind = 0;
        printf("Enter the relation of the vertex %c-", vertexG[i]->c);
        gets(relate);
        for (int j = 0; relate[j] != '\0'; j++)
        {
            if (relate[j] == '0')
            {
                temp->relation[0] = NULL;
                break;
            }
            else if (relate[j] == ',')
                continue;
            else
            {
                int k = 0;
                while (vertexG[k] != NULL)
                {
                    if (vertexG[k]->c == relate[j])
                        break;
                    k++;
                }
                if (vertexG[k] == NULL)
                {
                    printf("%c is not a vertex\n", relate[j]);
                    temp->relation[ind] = NULL;
                }
                else
                {
                    temp->relation[ind++] = vertexG[k];
                    temp->relation[ind] = NULL;
                }
            }
        }
    }
}
void searchInit(struct vertex *vertexG[], char type, int n)
{
    for (int i = 0; i < n; i++)
    {
        vertexG[i]->col = 'w';
        vertexG[i]->predecessor = '0';
        if (type == 'd')
        {
            time = 0;
            dopi = 0;
        }
    }
}
struct vertex *queue[30];
void bfs(struct vertex *vertexG[], char start)
{
    char op[20] = "";
    int i = 0, front = -1, rear = -1, k = 0;
    while (vertexG[i]->c != start)
        i++;
    vertexG[i]->col = 'g';
    vertexG[i]->predecessor = '0';
    vertexG[i]->distance = 0;
    front++;
    queue[++rear] = vertexG[i];
    while (front != -1)
    {
        struct vertex *temp = queue[front++];
        if (front > rear)
            front = rear = -1;
        for (int j = 0; temp->relation[j] != NULL; j++)
        {
            if (temp->relation[j]->col == 'w')
            {
                temp->relation[j]->col = 'g';
                temp->relation[j]->predecessor = temp->c;
                temp->relation[j]->distance = temp->distance + 1;
                if (front == -1)
                    front++;
                queue[++rear] = temp->relation[j];
            }
        }
        temp->col = 'b';
        op[k++] = temp->c;
    }
    printf("The Bfs sequence-%s", op);
}
void dfs(struct vertex *vertexG[], struct vertex *vertexs)
{
    vertexs->col = 'g';
    vertexs->dTime = ++time;
    dop[dopi++] = vertexs->c;
    for (int i = 0; vertexs->relation[i] != NULL; i++)
    {
        if (vertexs->relation[i]->col == 'w')
        {
            vertexs->relation[i]->predecessor = vertexs->c;
            dfs(vertexG, vertexs->relation[i]);
        }
    }
    vertexs->col = 'b';
    vertexs->fTime = ++time;
}
void main()
{
    int n, cont = 1, ch;
    char src;
    struct vertex *vertexGroup[30];
    for (int i = 0; i < 30; i++)
    {
        vertexGroup[i] = NULL;
    }
    printf("Enter the number of vertex in the graph-");
    scanf("%d", &n);
    graphGen(vertexGroup, n);
    for (int i = 0; i < n; i++)
    {
        printf("Vertex-%c", vertexGroup[i]->c);
        printf("\nRelations-");
        for (int j = 0; vertexGroup[i]->relation[j] != NULL; j++)
        {
            printf("%c ", vertexGroup[i]->relation[j]->c);
        }
        printf("\n");
    }
    do
    {
        printf("\nSearch Methods\n------------------------------\n1.Bfs\n2.Dfs\nEnter the search method-");
        scanf("%d", &ch);
        printf("Enter the start node-");
        getchar();
        scanf("%c", &src);
        switch (ch)
        {
                case 1:
                    searchInit(vertexGroup, 'b', n);
                    bfs(vertexGroup, src);
                    break;
                case 2:
                    printf("search starts from %c\n", src);
                    int i = 0;
                    while (vertexGroup[i]->c != src)
                        i++;
                    searchInit(vertexGroup, 'd', n);
                    dfs(vertexGroup, vertexGroup[i]);
                    for (int i = 0; i < n; i++)
                    {
                        if (vertexGroup[i]->col == 'w')
                        {
                            dfs(vertexGroup, vertexGroup[i]);
                        }
                    }
                    printf("The dfs sequence-%s", dop);
                    break;
                default:
                    printf("invalid choice");
                    break;
        }
        printf("\nDo you want to continue(0/1)-");
        scanf("%d", &cont);
    } while (cont != 0);
}
/*
Output
=================
Enter the number of vertex in the graph-5
Enter the vertex data-a
Enter the vertex data-b
Enter the vertex data-c
Enter the vertex data-d
Enter the vertex data-e
Enter the relation of the vertex a-b,e
Enter the relation of the vertex b-c,d
Enter the relation of the vertex c-0
Enter the relation of the vertex d-0
Enter the relation of the vertex e-0
Vertex-a
Relations-b e
Vertex-b
Relations-c d
Vertex-c
RelationsVertex-d
RelationsVertex-e
RelationsSearch Methods
------------------------------
1.Bfs
2.Dfs
Enter the search method-1
Enter the start node-a
The Bfs sequence-abecd
Do you want to continue(0/1)-1
Search Methods
------------------------------
1.Bfs
2.Dfs
Enter the search method
-
2
Enter the start node
-
d
search starts from d
The dfs sequence
-dabce
Do you want to continue(0/1)
-
0
*/