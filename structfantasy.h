typedef struct
{
    int rank;
    char name[20];
}
playerrank;

typedef struct node
{
    int rank;
    char name[20];
    struct node *next;
}
node;