#include <vector>
using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        
        // Directions representing the 8 neighbors around each cell.
        vector<pair<int, int>> directions = {{-1, -1}, {-1, 0}, {-1, 1}, 
                                             {0, -1},          {0, 1}, 
                                             {1, -1}, {1, 0}, {1, 1}};
        
        // Traverse the board and apply rules, but temporarily store the new state.
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int liveNeighbors = 0;
                
                // Count the number of live neighbors.
                for (auto dir : directions) {
                    int ni = i + dir.first;
                    int nj = j + dir.second;
                    if (ni >= 0 && ni < rows && nj >= 0 && nj < cols && abs(board[ni][nj]) == 1) {
                        liveNeighbors++;
                    }
                }
                
                // Rule 1 or Rule 3: A live cell dies if it has <2 or >3 live neighbors.
                if (board[i][j] == 1 && (liveNeighbors < 2 || liveNeighbors > 3)) {
                    board[i][j] = -1; // -1 means the cell is currently live but will die.
                }
                
                // Rule 4: A dead cell becomes live if it has exactly 3 live neighbors.
                if (board[i][j] == 0 && liveNeighbors == 3) {
                    board[i][j] = 2; // 2 means the cell is currently dead but will become live.
                }
            }
        }
        
        // Update the board to its final state.
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == -1) {
                    board[i][j] = 0; // Dead cell
                } else if (board[i][j] == 2) {
                    board[i][j] = 1; // Live cell
                }
            }
        }
    }
};

// this should not be medium TT