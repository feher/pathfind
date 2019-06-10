#ifndef PATHFIND_MAZE_H
#define PATHFIND_MAZE_H

enum {
    CLOSED = -1,
    EXIT = -2
};

typedef struct {
    /* Each of the int values for the directions is either the index
     * of the next chamber in the maze or CLOSED or EXIT. */
    int up;
    int down;
    int north;
    int north_east;
    int east;
    int south_east;
    int south;
    int south_west;
    int west;
    int north_west;
} chamber_t;

enum {
    NODE_COUNT = 100,
    START_NODE = 16
};

extern chamber_t maze_g[];

#endif //PATHFIND_MAZE_H
