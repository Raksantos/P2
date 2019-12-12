typedef struct binary_tree BT;

BT* create_empty_binary_tree();

BT* inite_bt(int item, BT* left, BT* right);

BT* search(BT *bt, int item);

int is_empty(BT* bt);

void inOrder(BT* bt);

void preOrder(BT* bt);

void posOrder(BT* bt);

BT* add(BT *bt, int item);

BT* remove_node(BT *bt, int item);

BT* remove_current(BT* current);