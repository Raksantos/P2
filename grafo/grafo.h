typedef struct grafo Graph;

Graph* init_graph();

void free_Graph(Graph* gr);

int add_edge(Graph* gr, int vertex1, int vertex2);

struct adj_list* create_adj_list(int item);

void dfs(Graph* gr, int source);

void bfs(Graph* gr, int source);