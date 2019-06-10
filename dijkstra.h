#ifndef PATHFIND_DIJKSTRA_H
#define PATHFIND_DIJKSTRA_H

#include <stddef.h>

#include "maze.h"

/**
 * Finds a path from the exit node to the start node.
 *
 * NOTE: The returned path is reversed. That is, it starts
 * from the exit node, not from the start node.
 *
 * If there is no exit node in the maze then path_len is set to 0
 * and returns NULL.
 *
 * If there is no such path then path_len is set to 1 and
 * the returned path has only the exit node in it.
 *
 * Otherwise path_len is set to the length of the path and
 * the returned array is the path from start to exit.
 *
 * @param maze In.
 * @param node_count In.
 * @param start_node In.
 * @param path_len Out. The length of the path.
 * @return The path or NULL. Caller must free.
 */
int* dij_find_exit_path(const chamber_t *maze, int node_count, int start_node, int *path_len);

#endif