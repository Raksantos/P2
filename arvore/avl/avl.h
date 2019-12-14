typedef struct binary_tree BT;

BT* create_empty_binary_tree();

BT* init_bt(int item, BT* left, BT* right);

BT* search(BT *bt, int item);

int is_empty(BT* bt);

void inOrder(BT* bt);

void preOrder(BT* bt);

void posOrder(BT* bt);

BT* add(BT *bt, int item);

BT* remove_node(BT *root, int item);

BT* remove_current(BT* current);

int h(BT *bt);

int max(int a, int b);

int is_balanced(BT *bt);

int balance_factor(BT *bt);

BT *rotate_right(BT *bt);

BT *rotate_left(BT *bt);