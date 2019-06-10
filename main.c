#include <stdlib.h>
#include <stdio.h>

#include "dijkstra.h"

int main() {
    int path_len = 0;
    int *path = dij_find_exit_path(maze_g, NODE_COUNT, START_NODE, &path_len);
    if (path == NULL) {
        printf("Error occured\n");
        return EXIT_FAILURE;
    }

    printf("Path: ");
    for (int i = path_len - 1; i >= 0; --i) {
        printf("%d, ", path[i]);
    }
    printf("\n");
    free(path);

    return EXIT_SUCCESS;
}
