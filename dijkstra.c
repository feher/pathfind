#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <limits.h>
#include "maze.h"

#define UNEXPLORED 0
#define EXPLORED 1

#define NEIGHBOR_COUNT 10

#define DEBUG_PRINT(...) \
            do { fprintf(stderr, __VA_ARGS__); } while (0)

//#define DEBUG_PRINT(fmt, ...)

static int dij_get_unexplored_min_node(const int *explored_state, const int *dist_from_start, int node_count) {
    int mindist = INT_MAX;
    int minnode = -1;
    for (int i = 0; i < node_count; ++i) {
        if (explored_state[i] == UNEXPLORED) {
            if (dist_from_start[i] < mindist) {
                mindist = dist_from_start[i];
                minnode = i;
            }
        }
    }
    DEBUG_PRINT("Unexplored min node %d\n", minnode);
    return minnode;
}

static void dij_get_neighbours(const chamber_t *chamber, int neighbours[NEIGHBOR_COUNT]) {
    neighbours[0] = chamber->up;
    neighbours[1] = chamber->down;
    neighbours[2] = chamber->west;
    neighbours[3] = chamber->north;
    neighbours[4] = chamber->east;
    neighbours[5] = chamber->south;
    neighbours[6] = chamber->north_west;
    neighbours[7] = chamber->north_east;
    neighbours[8] = chamber->south_west;
    neighbours[9] = chamber->south_east;
}

static void dij_update_neighbor_info(
        int node,
        const chamber_t *maze,
        int *dist_from_start,
        int *prev_node) {
    const chamber_t *chamber = maze + node;

    int neighbours[NEIGHBOR_COUNT];
    dij_get_neighbours(chamber, neighbours);

    const int new_dist = dist_from_start[node] + 1;
    for (int i = 0; i < NEIGHBOR_COUNT; ++i) {
        int n = neighbours[i];
        if (n == CLOSED || n == EXIT) {
            continue;
        }
        if (new_dist < dist_from_start[n]) {
            dist_from_start[n] = new_dist;
            prev_node[n] = node;
        }
    }
}

static int dij_find_exit_node(const chamber_t *maze, int node_count) {
    for (int i = 0; i < node_count; ++i) {
        const chamber_t *chamber = maze + i;

        int neighbours[NEIGHBOR_COUNT];
        dij_get_neighbours(chamber, neighbours);

        for (int j = 0; j < NEIGHBOR_COUNT; ++j) {
            int n = neighbours[j];
            if (n == EXIT) {
                DEBUG_PRINT("exit node %d\n", i);
                return i;
            }
        }
    }
    return -1;
}

static int* djs_make_path(const int *prev_node, int node_count, int exit_node, int *path_len) {
    DEBUG_PRINT("Make path start\n");
    *path_len = 0;

    int *path_to_exit = (int *)malloc(node_count * sizeof(int));
    if (path_to_exit == NULL) {
        return NULL;
    }
    int len = 0;
    path_to_exit[len++] = exit_node;
    DEBUG_PRINT("%d, ", exit_node);

    int n = exit_node;
    int prev;
    while ((prev = prev_node[n]) != -1) {
        DEBUG_PRINT("%d, ", prev);
        path_to_exit[len++] = prev;
        n = prev;
    }
    DEBUG_PRINT("\n");
    *path_len = len;
    return path_to_exit;
}

int* dij_find_exit_path(const chamber_t *maze, int node_count, int start_node, int *path_len) {
    *path_len = 0;
    int *result = NULL;

    int exit_node = dij_find_exit_node(maze, node_count);
    if (exit_node == -1) {
        fprintf(stderr, "No exit node.\n");
        goto err1;
    }

    int *explored_state = (int *)malloc(node_count * sizeof(int));
    if (explored_state == NULL) {
        goto err1;
    }
    for (int i = 0; i < node_count; ++i) {
        explored_state[i] = UNEXPLORED;
    }

    int *dist_from_start = (int *)malloc(node_count * sizeof(int));
    if (dist_from_start == NULL) {
        goto err2;
    }
    for (int i = 0; i < node_count; ++i) {
        dist_from_start[i] = INT_MAX;
    }

    int *prev_node = (int *)malloc(node_count * sizeof(int));
    if (prev_node == NULL) {
        goto err3;
    }
    for (int i = 0; i < node_count; ++i) {
        prev_node[i] = -1;
    }

    explored_state[start_node] = UNEXPLORED;
    dist_from_start[start_node] = 0;
    prev_node[start_node] = -1;

    int unexplored_node = 0;
    while ( (unexplored_node = dij_get_unexplored_min_node(explored_state, dist_from_start, node_count)) != -1) {
        explored_state[unexplored_node] = EXPLORED;
        if (unexplored_node == exit_node) {
            DEBUG_PRINT("Exit found at %d\n", unexplored_node);
            break;
        }
        dij_update_neighbor_info(unexplored_node, maze, dist_from_start, prev_node);
    }

    result = djs_make_path(prev_node, node_count, exit_node, path_len);

    free(prev_node);
err3:
    free(dist_from_start);
err2:
    free(explored_state);
err1:
    return result;
}
