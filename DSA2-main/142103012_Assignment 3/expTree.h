typedef struct node{

    char data;
    struct node *left, *right;

}node;

typedef node* eTree;

eTree init_tree(eTree, char*, int, int);
eTree Init(eTree, char*);
int Compute(eTree);
void inorder(eTree);
node* NewNode(char);
int LeafNode(node *);
int evaluate(char , int a, int b);
