#include "maze.h"

/* The Maze.
 *
 * The following matrix defines a maze consisting of NODE_COUNT chambers.
 * Each chamber has a number of tunnels in various directions.
 * The starting point is START_NODE. There is only one way to the EXIT.
 */
chamber_t maze_g[] = {
        /* 0 */
        {
                .up = 58,
                .down = CLOSED,
                .north = CLOSED,
                .north_east = 36,
                .east = 39,
                .south_east = 59,
                .south = CLOSED,
                .south_west = 45,
                .west = CLOSED,
                .north_west = 7,
        },
        /* 1 */
        {
                .up = 94,
                .down = 64,
                .north = CLOSED,
                .north_east = CLOSED,
                .east = 57,
                .south_east = 40,
                .south = 91,
                .south_west = 26,
                .west = CLOSED,
                .north_west = 55,
        },
        /* 2 */
        {
                .up = 88,
                .down = CLOSED,
                .north = CLOSED,
                .north_east = CLOSED,
                .east = 39,
                .south_east = CLOSED,
                .south = 5,
                .south_west = 32,
                .west = 59,
                .north_west = CLOSED,
        },
        /* 3 */
        {
                .up = CLOSED,
                .down = CLOSED,
                .north = 20,
                .north_east = CLOSED,
                .east = CLOSED,
                .south_east = 6,
                .south = CLOSED,
                .south_west = 70,
                .west = CLOSED,
                .north_west = 43,
        },
        /* 4 */
        {
                .up = 38,
                .down = CLOSED,
                .north = CLOSED,
                .north_east = 44,
                .east = CLOSED,
                .south_east = CLOSED,
                .south = CLOSED,
                .south_west = 82,
                .west = CLOSED,
                .north_west = CLOSED,
        },
        /* 5 */
        {
                .up = 23,
                .down = 26,
                .north = 41,
                .north_east = CLOSED,
                .east = CLOSED,
                .south_east = CLOSED,
                .south = CLOSED,
                .south_west = 2,
                .west = CLOSED,
                .north_west = CLOSED,
        },
        /* 6 */
        {
                .up = 76,
                .down = 95,
                .north = CLOSED,
                .north_east = CLOSED,
                .east = CLOSED,
                .south_east = 56,
                .south = 43,
                .south_west = CLOSED,
                .west = 3,
                .north_west = 8,
        },
        /* 7 */
        {
                .up = 37,
                .down = CLOSED,
                .north = CLOSED,
                .north_east = CLOSED,
                .east = CLOSED,
                .south_east = 0,
                .south = 18,
                .south_west = CLOSED,
                .west = 65,
                .north_west = 43,
        },
        /* 8 */
        {
                .up = CLOSED,
                .down = 6,
                .north = 82,
                .north_east = 28,
                .east = 52,
                .south_east = CLOSED,
                .south = CLOSED,
                .south_west = CLOSED,
                .west = CLOSED,
                .north_west = CLOSED,
        },
        /* 9 */
        {
                .up = 93,
                .down = CLOSED,
                .north = 11,
                .north_east = 46,
                .east = 68,
                .south_east = CLOSED,
                .south = CLOSED,
                .south_west = 48,
                .west = CLOSED,
                .north_west = CLOSED,
        },
        /* 10 */
        {
                .up = 60,
                .down = CLOSED,
                .north = 46,
                .north_east = CLOSED,
                .east = 20,
                .south_east = 21,
                .south = CLOSED,
                .south_west = 98,
                .west = 15,
                .north_west = 65,
        },
        /* 11 */
        {
                .up = 98,
                .down = CLOSED,
                .north = CLOSED,
                .north_east = 38,
                .east = CLOSED,
                .south_east = CLOSED,
                .south = 9,
                .south_west = CLOSED,
                .west = CLOSED,
                .north_west = CLOSED,
        },
        /* 12 */
        {
                .up = 25,
                .down = CLOSED,
                .north = CLOSED,
                .north_east = CLOSED,
                .east = CLOSED,
                .south_east = 40,
                .south = CLOSED,
                .south_west = 29,
                .west = CLOSED,
                .north_west = 29,
        },
        /* 13 */
        {
                .up = 14,
                .down = CLOSED,
                .north = 51,
                .north_east = 37,
                .east = CLOSED,
                .south_east = CLOSED,
                .south = 19,
                .south_west = 34,
                .west = 89,
                .north_west = CLOSED,
        },
        /* 14 */
        {
                .up = CLOSED,
                .down = 67,
                .north = 40,
                .north_east = 13,
                .east = 74,
                .south_east = 82,
                .south = 63,
                .south_west = 92,
                .west = 22,
                .north_west = 16,
        },
        /* 15 */
        {
                .up = 63,
                .down = CLOSED,
                .north = CLOSED,
                .north_east = 48,
                .east = 32,
                .south_east = 41,
                .south = CLOSED,
                .south_west = 81,
                .west = CLOSED,
                .north_west = 10,
        },
        /* 16 */
        {
                .up = 58,
                .down = 58,
                .north = 76,
                .north_east = 30,
                .east = 97,
                .south_east = CLOSED,
                .south = 92,
                .south_west = 96,
                .west = CLOSED,
                .north_west = 14,
        },
        /* 17 */
        {
                .up = CLOSED,
                .down = 56,
                .north = 22,
                .north_east = CLOSED,
                .east = 72,
                .south_east = 49,
                .south = CLOSED,
                .south_west = CLOSED,
                .west = CLOSED,
                .north_west = 75,
        },
        /* 18 */
        {
                .up = 18,
                .down = CLOSED,
                .north = CLOSED,
                .north_east = CLOSED,
                .east = 18,
                .south_east = 7,
                .south = 52,
                .south_west = CLOSED,
                .west = CLOSED,
                .north_west = 56,
        },
        /* 19 */
        {
                .up = 13,
                .down = CLOSED,
                .north = CLOSED,
                .north_east = CLOSED,
                .east = 87,
                .south_east = 36,
                .south = 33,
                .south_west = CLOSED,
                .west = 77,
                .north_west = CLOSED,
        },
        /* 20 */
        {
                .up = CLOSED,
                .down = CLOSED,
                .north = 10,
                .north_east = CLOSED,
                .east = CLOSED,
                .south_east = CLOSED,
                .south = CLOSED,
                .south_west = 37,
                .west = 45,
                .north_west = 3,
        },
        /* 21 */
        {
                .up = CLOSED,
                .down = 10,
                .north = 78,
                .north_east = CLOSED,
                .east = CLOSED,
                .south_east = 66,
                .south = 35,
                .south_west = 31,
                .west = CLOSED,
                .north_west = 58,
        },
        /* 22 */
        {
                .up = CLOSED,
                .down = 14,
                .north = 80,
                .north_east = CLOSED,
                .east = 17,
                .south_east = 82,
                .south = 35,
                .south_west = 77,
                .west = 84,
                .north_west = 66,
        },
        /* 23 */
        {
                .up = 35,
                .down = CLOSED,
                .north = 65,
                .north_east = CLOSED,
                .east = CLOSED,
                .south_east = 5,
                .south = CLOSED,
                .south_west = CLOSED,
                .west = CLOSED,
                .north_west = CLOSED,
        },
        /* 24 */
        {
                .up = CLOSED,
                .down = 69,
                .north = 70,
                .north_east = CLOSED,
                .east = 36,
                .south_east = 89,
                .south = CLOSED,
                .south_west = 58,
                .west = CLOSED,
                .north_west = CLOSED,
        },
        /* 25 */
        {
                .up = 12,
                .down = CLOSED,
                .north = 44,
                .north_east = 48,
                .east = 64,
                .south_east = CLOSED,
                .south = CLOSED,
                .south_west = CLOSED,
                .west = CLOSED,
                .north_west = 73,
        },
        /* 26 */
        {
                .up = CLOSED,
                .down = CLOSED,
                .north = CLOSED,
                .north_east = CLOSED,
                .east = 5,
                .south_east = CLOSED,
                .south = CLOSED,
                .south_west = 44,
                .west = CLOSED,
                .north_west = 1,
        },
        /* 27 */
        {
                .up = CLOSED,
                .down = 54,
                .north = CLOSED,
                .north_east = 76,
                .east = 45,
                .south_east = CLOSED,
                .south = 95,
                .south_west = CLOSED,
                .west = CLOSED,
                .north_west = 53,
        },
        /* 28 */
        {
                .up = CLOSED,
                .down = 39,
                .north = CLOSED,
                .north_east = 8,
                .east = 78,
                .south_east = CLOSED,
                .south = CLOSED,
                .south_west = 91,
                .west = 66,
                .north_west = CLOSED,
        },
        /* 29 */
        {
                .up = 12,
                .down = CLOSED,
                .north = CLOSED,
                .north_east = CLOSED,
                .east = CLOSED,
                .south_east = 12,
                .south = 75,
                .south_west = 78,
                .west = 89,
                .north_west = 34,
        },
        /* 30 */
        {
                .up = CLOSED,
                .down = 73,
                .north = CLOSED,
                .north_east = CLOSED,
                .east = 84,
                .south_east = 75,
                .south = 47,
                .south_west = CLOSED,
                .west = 93,
                .north_west = 16,
        },
        /* 31 */
        {
                .up = 34,
                .down = CLOSED,
                .north = 98,
                .north_east = CLOSED,
                .east = CLOSED,
                .south_east = 21,
                .south = CLOSED,
                .south_west = 90,
                .west = 46,
                .north_west = 89,
        },
        /* 32 */
        {
                .up = 2,
                .down = CLOSED,
                .north = CLOSED,
                .north_east = 15,
                .east = CLOSED,
                .south_east = CLOSED,
                .south = 65,
                .south_west = CLOSED,
                .west = CLOSED,
                .north_west = 38,
        },
        /* 33 */
        {
                .up = 85,
                .down = 19,
                .north = 62,
                .north_east = 40,
                .east = 88,
                .south_east = 53,
                .south = CLOSED,
                .south_west = 80,
                .west = 83,
                .north_west = CLOSED,
        },
        /* 34 */
        {
                .up = CLOSED,
                .down = 67,
                .north = CLOSED,
                .north_east = 76,
                .east = 77,
                .south_east = CLOSED,
                .south = 31,
                .south_west = 13,
                .west = 29,
                .north_west = 53,
        },
        /* 35 */
        {
                .up = CLOSED,
                .down = CLOSED,
                .north = 22,
                .north_east = 36,
                .east = 95,
                .south_east = 21,
                .south = CLOSED,
                .south_west = CLOSED,
                .west = 23,
                .north_west = CLOSED,
        },
        /* 36 */
        {
                .up = CLOSED,
                .down = CLOSED,
                .north = 86,
                .north_east = 0,
                .east = 97,
                .south_east = CLOSED,
                .south = 24,
                .south_west = 19,
                .west = 35,
                .north_west = 60,
        },
        /* 37 */
        {
                .up = 7,
                .down = 93,
                .north = 13,
                .north_east = CLOSED,
                .east = CLOSED,
                .south_east = CLOSED,
                .south = 58,
                .south_west = 20,
                .west = 87,
                .north_west = 76,
        },
        /* 38 */
        {
                .up = 74,
                .down = 11,
                .north = 62,
                .north_east = 51,
                .east = 32,
                .south_east = CLOSED,
                .south = CLOSED,
                .south_west = CLOSED,
                .west = CLOSED,
                .north_west = 4,
        },
        /* 39 */
        {
                .up = CLOSED,
                .down = 0,
                .north = CLOSED,
                .north_east = 2,
                .east = 93,
                .south_east = CLOSED,
                .south = 96,
                .south_west = CLOSED,
                .west = 28,
                .north_west = CLOSED,
        },
        /* 40 */
        {
                .up = 1,
                .down = CLOSED,
                .north = 87,
                .north_east = 33,
                .east = CLOSED,
                .south_east = 63,
                .south = 14,
                .south_west = 12,
                .west = CLOSED,
                .north_west = 79,
        },
        /* 41 */
        {
                .up = CLOSED,
                .down = CLOSED,
                .north = CLOSED,
                .north_east = 5,
                .east = 15,
                .south_east = CLOSED,
                .south = CLOSED,
                .south_west = 43,
                .west = 79,
                .north_west = 50,
        },
        /* 42 */
        {
                .up = CLOSED,
                .down = 82,
                .north = CLOSED,
                .north_east = CLOSED,
                .east = CLOSED,
                .south_east = 69,
                .south = CLOSED,
                .south_west = CLOSED,
                .west = CLOSED,
                .north_west = CLOSED,
        },
        /* 43 */
        {
                .up = 90,
                .down = CLOSED,
                .north = 7,
                .north_east = 41,
                .east = CLOSED,
                .south_east = CLOSED,
                .south = CLOSED,
                .south_west = 6,
                .west = CLOSED,
                .north_west = 3,
        },
        /* 44 */
        {
                .up = 69,
                .down = CLOSED,
                .north = 4,
                .north_east = 26,
                .east = 78,
                .south_east = CLOSED,
                .south = CLOSED,
                .south_west = 25,
                .west = CLOSED,
                .north_west = 45,
        },
        /* 45 */
        {
                .up = CLOSED,
                .down = 44,
                .north = CLOSED,
                .north_east = 47,
                .east = CLOSED,
                .south_east = 0,
                .south = 20,
                .south_west = 99,
                .west = CLOSED,
                .north_west = 27,
        },
        /* 46 */
        {
                .up = 9,
                .down = 31,
                .north = 51,
                .north_east = CLOSED,
                .east = 10,
                .south_east = CLOSED,
                .south = CLOSED,
                .south_west = CLOSED,
                .west = CLOSED,
                .north_west = 51,
        },
        /* 47 */
        {
                .up = 85,
                .down = 45,
                .north = CLOSED,
                .north_east = 99,
                .east = 88,
                .south_east = CLOSED,
                .south = CLOSED,
                .south_west = CLOSED,
                .west = 30,
                .north_west = 99,
        },
        /* 48 */
        {
                .up = CLOSED,
                .down = CLOSED,
                .north = CLOSED,
                .north_east = 9,
                .east = CLOSED,
                .south_east = 15,
                .south = 72,
                .south_west = CLOSED,
                .west = CLOSED,
                .north_west = 25,
        },
        /* 49 */
        {
                .up = 97,
                .down = CLOSED,
                .north = CLOSED,
                .north_east = CLOSED,
                .east = CLOSED,
                .south_east = 17,
                .south = CLOSED,
                .south_west = CLOSED,
                .west = CLOSED,
                .north_west = CLOSED,
        },
        /* 50 */
        {
                .up = CLOSED,
                .down = 54,
                .north = CLOSED,
                .north_east = 92,
                .east = CLOSED,
                .south_east = CLOSED,
                .south = 57,
                .south_west = CLOSED,
                .west = CLOSED,
                .north_west = 41,
        },
        /* 51 */
        {
                .up = CLOSED,
                .down = 62,
                .north = CLOSED,
                .north_east = CLOSED,
                .east = 13,
                .south_east = 46,
                .south = CLOSED,
                .south_west = 46,
                .west = 38,
                .north_west = 73,
        },
        /* 52 */
        {
                .up = 56,
                .down = CLOSED,
                .north = 8,
                .north_east = 95,
                .east = CLOSED,
                .south_east = CLOSED,
                .south = 64,
                .south_west = 18,
                .west = 89,
                .north_west = CLOSED,
        },
        /* 53 */
        {
                .up = CLOSED,
                .down = 34,
                .north = CLOSED,
                .north_east = CLOSED,
                .east = 33,
                .south_east = 27,
                .south = CLOSED,
                .south_west = CLOSED,
                .west = CLOSED,
                .north_west = 86,
        },
        /* 54 */
        {
                .up = 92,
                .down = 27,
                .north = CLOSED,
                .north_east = 69,
                .east = CLOSED,
                .south_east = CLOSED,
                .south = 77,
                .south_west = CLOSED,
                .west = 50,
                .north_west = CLOSED,
        },
        /* 55 */
        {
                .up = CLOSED,
                .down = 1,
                .north = 69,
                .north_east = CLOSED,
                .east = 76,
                .south_east = CLOSED,
                .south = CLOSED,
                .south_west = 88,
                .west = 70,
                .north_west = CLOSED,
        },
        /* 56 */
        {
                .up = CLOSED,
                .down = 18,
                .north = 6,
                .north_east = 17,
                .east = CLOSED,
                .south_east = 63,
                .south = 52,
                .south_west = CLOSED,
                .west = CLOSED,
                .north_west = CLOSED,
        },
        /* 57 */
        {
                .up = CLOSED,
                .down = 1,
                .north = CLOSED,
                .north_east = 71,
                .east = CLOSED,
                .south_east = CLOSED,
                .south = 80,
                .south_west = 50,
                .west = 71,
                .north_west = CLOSED,
        },
        /* 58 */
        {
                .up = 0,
                .down = 94,
                .north = CLOSED,
                .north_east = CLOSED,
                .east = 24,
                .south_east = 21,
                .south = 83,
                .south_west = 16,
                .west = 37,
                .north_west = 16,
        },
        /* 59 */
        {
                .up = CLOSED,
                .down = CLOSED,
                .north = 94,
                .north_east = 2,
                .east = 79,
                .south_east = CLOSED,
                .south = 75,
                .south_west = 0,
                .west = 95,
                .north_west = CLOSED,
        },
        /* 60 */
        {
                .up = 10,
                .down = CLOSED,
                .north = 92,
                .north_east = CLOSED,
                .east = CLOSED,
                .south_east = CLOSED,
                .south = 36,
                .south_west = 65,
                .west = CLOSED,
                .north_west = CLOSED,
        },
        /* 61 */
        {
                .up = CLOSED,
                .down = CLOSED,
                .north = 74,
                .north_east = CLOSED,
                .east = CLOSED,
                .south_east = 66,
                .south = 79,
                .south_west = CLOSED,
                .west = 96,
                .north_west = CLOSED,
        },
        /* 62 */
        {
                .up = CLOSED,
                .down = CLOSED,
                .north = 51,
                .north_east = CLOSED,
                .east = 33,
                .south_east = CLOSED,
                .south = CLOSED,
                .south_west = CLOSED,
                .west = 38,
                .north_west = 80,
        },
        /* 63 */
        {
                .up = CLOSED,
                .down = CLOSED,
                .north = CLOSED,
                .north_east = 15,
                .east = CLOSED,
                .south_east = 75,
                .south = 56,
                .south_west = 14,
                .west = 40,
                .north_west = CLOSED,
        },
        /* 64 */
        {
                .up = CLOSED,
                .down = 1,
                .north = CLOSED,
                .north_east = 89,
                .east = CLOSED,
                .south_east = CLOSED,
                .south = CLOSED,
                .south_west = 25,
                .west = CLOSED,
                .north_west = 52,
        },
        /* 65 */
        {
                .up = 60,
                .down = CLOSED,
                .north = 10,
                .north_east = 7,
                .east = 74,
                .south_east = 23,
                .south = 32,
                .south_west = CLOSED,
                .west = CLOSED,
                .north_west = 89,
        },
        /* 66 */
        {
                .up = CLOSED,
                .down = 21,
                .north = 28,
                .north_east = CLOSED,
                .east = 80,
                .south_east = 92,
                .south = CLOSED,
                .south_west = CLOSED,
                .west = 22,
                .north_west = 61,
        },
        /* 67 */
        {
                .up = 82,
                .down = 14,
                .north = CLOSED,
                .north_east = 34,
                .east = CLOSED,
                .south_east = CLOSED,
                .south = 91,
                .south_west = CLOSED,
                .west = 73,
                .north_west = CLOSED,
        },
        /* 68 */
        {
                .up = 85,
                .down = 9,
                .north = CLOSED,
                .north_east = CLOSED,
                .east = CLOSED,
                .south_east = CLOSED,
                .south = CLOSED,
                .south_west = CLOSED,
                .west = CLOSED,
                .north_west = CLOSED,
        },
        /* 69 */
        {
                .up = 54,
                .down = CLOSED,
                .north = CLOSED,
                .north_east = 55,
                .east = CLOSED,
                .south_east = CLOSED,
                .south = 42,
                .south_west = CLOSED,
                .west = 24,
                .north_west = 44,
        },
        /* 70 */
        {
                .up = 24,
                .down = CLOSED,
                .north = 3,
                .north_east = CLOSED,
                .east = 83,
                .south_east = CLOSED,
                .south = 71,
                .south_west = 55,
                .west = 73,
                .north_west = 87,
        },
        /* 71 */
        {
                .up = 57,
                .down = CLOSED,
                .north = CLOSED,
                .north_east = CLOSED,
                .east = CLOSED,
                .south_east = 70,
                .south = CLOSED,
                .south_west = CLOSED,
                .west = CLOSED,
                .north_west = 57,
        },
        /* 72 */
        {
                .up = CLOSED,
                .down = 48,
                .north = CLOSED,
                .north_east = CLOSED,
                .east = CLOSED,
                .south_east = CLOSED,
                .south = 73,
                .south_west = CLOSED,
                .west = 17,
                .north_west = CLOSED,
        },
        /* 73 */
        {
                .up = 67,
                .down = 51,
                .north = CLOSED,
                .north_east = 70,
                .east = 30,
                .south_east = 25,
                .south = 72,
                .south_west = CLOSED,
                .west = CLOSED,
                .north_west = CLOSED,
        },
        /* 74 */
        {
                .up = CLOSED,
                .down = CLOSED,
                .north = 14,
                .north_east = 61,
                .east = CLOSED,
                .south_east = CLOSED,
                .south = 93,
                .south_west = 38,
                .west = CLOSED,
                .north_west = 65,
        },
        /* 75 */
        {
                .up = CLOSED,
                .down = CLOSED,
                .north = 30,
                .north_east = 17,
                .east = CLOSED,
                .south_east = 63,
                .south = 29,
                .south_west = CLOSED,
                .west = CLOSED,
                .north_west = 59,
        },
        /* 76 */
        {
                .up = CLOSED,
                .down = CLOSED,
                .north = 6,
                .north_east = 27,
                .east = 55,
                .south_east = 37,
                .south = CLOSED,
                .south_west = 93,
                .west = 34,
                .north_west = 16,
        },
        /* 77 */
        {
                .up = 54,
                .down = 34,
                .north = CLOSED,
                .north_east = CLOSED,
                .east = CLOSED,
                .south_east = CLOSED,
                .south = CLOSED,
                .south_west = 22,
                .west = CLOSED,
                .north_west = 19,
        },
        /* 78 */
        {
                .up = CLOSED,
                .down = 96,
                .north = CLOSED,
                .north_east = 29,
                .east = 21,
                .south_east = 94,
                .south = 44,
                .south_west = CLOSED,
                .west = CLOSED,
                .north_west = 28,
        },
        /* 79 */
        {
                .up = CLOSED,
                .down = CLOSED,
                .north = CLOSED,
                .north_east = 81,
                .east = 40,
                .south_east = 59,
                .south = 41,
                .south_west = CLOSED,
                .west = 98,
                .north_west = 61,
        },
        /* 80 */
        {
                .up = 87,
                .down = CLOSED,
                .north = CLOSED,
                .north_east = 22,
                .east = 57,
                .south_east = CLOSED,
                .south = 33,
                .south_west = 62,
                .west = 66,
                .north_west = 92,
        },
        /* 81 */
        {
                .up = 79,
                .down = 88,
                .north = CLOSED,
                .north_east = CLOSED,
                .east = CLOSED,
                .south_east = 15,
                .south = CLOSED,
                .south_west = CLOSED,
                .west = CLOSED,
                .north_west = CLOSED,
        },
        /* 82 */
        {
                .up = 14,
                .down = 4,
                .north = CLOSED,
                .north_east = CLOSED,
                .east = 95,
                .south_east = 22,
                .south = 67,
                .south_west = 42,
                .west = EXIT,
                .north_west = 8,
        },
        /* 83 */
        {
                .up = CLOSED,
                .down = CLOSED,
                .north = 58,
                .north_east = CLOSED,
                .east = CLOSED,
                .south_east = 84,
                .south = 70,
                .south_west = CLOSED,
                .west = 33,
                .north_west = CLOSED,
        },
        /* 84 */
        {
                .up = CLOSED,
                .down = CLOSED,
                .north = CLOSED,
                .north_east = 83,
                .east = 30,
                .south_east = 87,
                .south = CLOSED,
                .south_west = CLOSED,
                .west = CLOSED,
                .north_west = 22,
        },
        /* 85 */
        {
                .up = 68,
                .down = 47,
                .north = CLOSED,
                .north_east = CLOSED,
                .east = CLOSED,
                .south_east = CLOSED,
                .south = CLOSED,
                .south_west = 33,
                .west = 85,
                .north_west = 85,
        },
        /* 86 */
        {
                .up = CLOSED,
                .down = CLOSED,
                .north = CLOSED,
                .north_east = 53,
                .east = CLOSED,
                .south_east = CLOSED,
                .south = 90,
                .south_west = 36,
                .west = CLOSED,
                .north_west = CLOSED,
        },
        /* 87 */
        {
                .up = 19,
                .down = 84,
                .north = 40,
                .north_east = CLOSED,
                .east = 80,
                .south_east = CLOSED,
                .south = 37,
                .south_west = 70,
                .west = CLOSED,
                .north_west = CLOSED,
        },
        /* 88 */
        {
                .up = CLOSED,
                .down = 33,
                .north = CLOSED,
                .north_east = 2,
                .east = 81,
                .south_east = CLOSED,
                .south = CLOSED,
                .south_west = CLOSED,
                .west = 47,
                .north_west = 55,
        },
        /* 89 */
        {
                .up = 64,
                .down = CLOSED,
                .north = 13,
                .north_east = 29,
                .east = 31,
                .south_east = CLOSED,
                .south = 52,
                .south_west = 24,
                .west = CLOSED,
                .north_west = 65,
        },
        /* 90 */
        {
                .up = 43,
                .down = CLOSED,
                .north = CLOSED,
                .north_east = CLOSED,
                .east = 95,
                .south_east = 86,
                .south = CLOSED,
                .south_west = 31,
                .west = CLOSED,
                .north_west = 97,
        },
        /* 91 */
        {
                .up = CLOSED,
                .down = CLOSED,
                .north = 67,
                .north_east = CLOSED,
                .east = CLOSED,
                .south_east = 28,
                .south = CLOSED,
                .south_west = CLOSED,
                .west = CLOSED,
                .north_west = 1,
        },
        /* 92 */
        {
                .up = 66,
                .down = CLOSED,
                .north = 14,
                .north_east = 60,
                .east = CLOSED,
                .south_east = 80,
                .south = 16,
                .south_west = 50,
                .west = 54,
                .north_west = CLOSED,
        },
        /* 93 */
        {
                .up = 39,
                .down = 76,
                .north = 37,
                .north_east = CLOSED,
                .east = CLOSED,
                .south_east = 74,
                .south = CLOSED,
                .south_west = 9,
                .west = CLOSED,
                .north_west = 30,
        },
        /* 94 */
        {
                .up = 58,
                .down = CLOSED,
                .north = 78,
                .north_east = CLOSED,
                .east = 59,
                .south_east = CLOSED,
                .south = CLOSED,
                .south_west = CLOSED,
                .west = CLOSED,
                .north_west = 1,
        },
        /* 95 */
        {
                .up = 52,
                .down = 35,
                .north = 59,
                .north_east = 27,
                .east = CLOSED,
                .south_east = CLOSED,
                .south = 6,
                .south_west = CLOSED,
                .west = 82,
                .north_west = 90,
        },
        /* 96 */
        {
                .up = 16,
                .down = CLOSED,
                .north = 78,
                .north_east = 39,
                .east = CLOSED,
                .south_east = CLOSED,
                .south = CLOSED,
                .south_west = CLOSED,
                .west = 99,
                .north_west = 61,
        },
        /* 97 */
        {
                .up = CLOSED,
                .down = 90,
                .north = 49,
                .north_east = 36,
                .east = 97,
                .south_east = CLOSED,
                .south = CLOSED,
                .south_west = 97,
                .west = CLOSED,
                .north_west = 16,
        },
        /* 98 */
        {
                .up = CLOSED,
                .down = CLOSED,
                .north = 31,
                .north_east = 79,
                .east = CLOSED,
                .south_east = CLOSED,
                .south = 10,
                .south_west = 11,
                .west = CLOSED,
                .north_west = CLOSED,
        },
        /* 99 */
        {
                .up = CLOSED,
                .down = CLOSED,
                .north = CLOSED,
                .north_east = 45,
                .east = CLOSED,
                .south_east = 47,
                .south = 96,
                .south_west = CLOSED,
                .west = 47,
                .north_west = CLOSED,
        },
};
