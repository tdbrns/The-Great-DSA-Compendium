/*
Algorithm:          Flood Fill using Depth-First Search (LeetCode Problem #733)

Task:               You are given an image represented by an m x n grid of integers "image", where image[i][j] represents the pixel value
                    of the image. You are also given three integers "sr", "sc", and "color". Your task is to perform a flood fill on the
                    image starting from the pixel image[sr][sc]. To perform a flood fill:
                     1. Begin with the starting pixel and change its color to "color".
                     2. Perform the same process for each pixel that is directly adjacent (pixels that share a side with the original
                        pixel, either horizontally or vertically) and shares the same color as the starting pixel.
                     3. Keep repeating this process by checking neighboring pixels of the updated pixels and modifying their color if it 
                        matches the original color of the starting pixel.
                     4. The process stops when there are no more adjacent pixels of the original color to update.
                    Return the modified image after performing the flood fill.

Solution:           Use the depth-first search algorithm to perform the flood fill by recursively visiting all the adjacent pixels of the
                    current pixel and only changing the color of the pixels that are in the range of the grid and match the original 
                    color of the starting pixel; any pixels that do not meet this criteria should be left unchanged.

Time complexity:    O(M * N)
                        M * N = size of the grid of pixels

Space complexity:   O(P)
                        P = number of pixels in the grid / maximum depth of the recursive call stack

Auxiliary space:    O(P)
                        P = maximum depth of the recursive call stack

Resources:          https://leetcode.com/problems/flood-fill/solutions/
*/

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

void dfs(vector<vector<int>>& image, int i, int j, int color, int currColor)
{
    // NOTE:
    //  image[i][j] = current pixel
    //  image[i][j+1] = right 1 pixel
    //  image[i][j-1] = left 1 pixel
    //  image[i-1][j] = up 1 pixel
    //  image[i+1][j] = down 1 pixel

    int m = image.size();       // Number of rows.
    int n = image[0].size();    // Number of columns.

    // Base case; 
    // If the current pixel is out of range, already the correct color, or does not match the original color of the starting pixel, 
    // we do not want to change anything, so return to the previously visited pixel.
    if (i < 0 || j < 0 || i >= m || j >= n || image[i][j] == color || image[i][j] != currColor)
        return;
    
    // Change the color value of the current pixel.
    image[i][j] = color;

    // Visit the pixels that are adjacent to the current pixel.
    dfs(image, i, j + 1, color, currColor);       // Right 
    dfs(image, i, j - 1, color, currColor);       // Left
    dfs(image, i - 1, j, color, currColor);       // Up
    dfs(image, i + 1, j, color, currColor);       // Down
}

// wrapper function for dfs().
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
{
    int currColor = image[sr][sc];          // Current color value of the starting pixel.
    dfs(image, sr, sc, color, currColor);
    return image;
}

int main()
{
    vector<vector<int>> image1 = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    int sr = 1, sc = 1, color = 2;
    floodFill(image1, sc, sc, color);
    for (int i = 0; i < image1.size(); i++)
    {
        for (int j = 0; j < image1[0].size(); j++)
            cout << image1[i][j] << " ";
        cout << endl;
    }

    cout << endl;

    vector<vector<int>> image2 = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    sr = 0;
    sc = 0;
    color = 0;
    floodFill(image2, sc, sc, color);
    for (int i = 0; i < image2.size(); i++)
    {
        for (int j = 0; j < image2[0].size(); j++)
            cout << image2[i][j] << " ";
        cout << endl;
    }

    return 0;
}