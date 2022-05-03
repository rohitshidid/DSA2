typedef struct node{
  int data;
  struct node *left, *right;
} node;

typedef node *bst;

void initbst(bst *tree);
void createNode(bst *tree, int d);
int *inputbst(int *arr, int size);
void inorder(bst tree);
void preorder(bst tree);