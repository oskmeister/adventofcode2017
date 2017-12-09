#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NEIGHBOURS 50
#define MAX_NODES 2000

struct Node {
    char *name;
    char *neigh[50];
    int n_neigh;
    int weight;
    int num_in;
};

int contains(char **list, char *str) {
    int found = 0;
    while (*list) {
        if (strcmp(*list, str) == 0) found = 1;
        list++;
    }
    return found;
}

struct Node *parse_node(char *line) {
    size_t buffer_size = 500;
    char *node_name = (char *) malloc(sizeof(char) * buffer_size);
    char *node_neighbours = (char *) malloc(sizeof(char) * buffer_size);
    int node_weight;
    sscanf(line, "%s (%d) -> %[^\n]", node_name, &node_weight, node_neighbours);
    struct Node *tree = (struct Node *) malloc(sizeof(struct Node));
    tree->name = node_name;
    tree->weight = node_weight;
    tree->n_neigh = 0;
    tree->num_in = 0;
    memset(tree->neigh, 0, sizeof(tree->neigh));
    char *at = strtok(node_neighbours, " ,");
    while (at != NULL) {
        char *neigh = malloc(sizeof(char) * sizeof(at));
        strcpy(neigh, at);
        tree->neigh[tree->n_neigh++] = neigh;
        at = strtok(NULL, " ,");
    }
    free(node_neighbours);
    return tree;
}

void read_tree() {
    size_t size = 500;
    char *buffer = (char *) malloc(sizeof(char) * size);

    struct Node *nodes[MAX_NODES];
    int n_nodes = 0;
    while (getline(&buffer, &size, stdin) != -1) {
        nodes[n_nodes++] = parse_node(buffer);
    }

    int i, j;
    for (i = 0; i < n_nodes; ++i) {
        for (j = 0; j < n_nodes; ++j) {
            if (i == j) continue;
            if (contains(nodes[j]->neigh, nodes[i]->name)) {
                nodes[i]->num_in++;
            }
        }
    }

    for (i = 0; i < n_nodes; ++i) {
        if (nodes[i]->num_in == 0) {
            printf("%s has no in-edges\n", nodes[i]->name);
        }
    }

    free(buffer);
}

int main(int argc, char *argv[]) {
    read_tree();
}
