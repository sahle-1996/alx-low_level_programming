#!/usr/bin/python3
"""Module to calculate the perimeter of an island in a grid."""


def get_island_perimeter(grid):
    """Calculate the perimeter of an island.
    The grid represents water by 0 and land by 1.
    Args:
        grid (list): A list of list of integers representing an island.
    Returns:
        The perimeter of the island defined in grid.
    """
    num_cols = len(grid[0])
    num_rows = len(grid)
    shared_edges = 0
    land_cells = 0

    for row in range(num_rows):
        for col in range(num_cols):
            if grid[row][col] == 1:
                land_cells += 1
                if col > 0 and grid[row][col - 1] == 1:
                    shared_edges += 1
                if row > 0 and grid[row - 1][col] == 1:
                    shared_edges += 1
    return land_cells * 4 - shared_edges * 2
