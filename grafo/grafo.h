typedef struct grafo Grafo;

Grafo* init_grafo(int nro_vertices, int grau_max, int eh_ponderado);

void free_grafo(Grafo* gr);