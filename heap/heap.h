typedef struct Heap heap;

void max_heapify(heap *hp, int i);

int dequeue(heap *hp);

int is_empty(heap *hp);

void enqueue(heap *hp, int item);

void swap(int *position1, int *position2);

int item_of(heap *hp, int i);

int get_right_index(heap *hp, int i);

int get_left_index(heap *hp, int i);

int get_parent_index(heap *hp, int i);

heap* create_heap();

void heapSort(heap *hp);