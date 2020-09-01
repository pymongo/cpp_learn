#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

// [拓扑排序]从房间0，每个房间里有若干条其它房间的钥匙，问你是否存在一个顺序可以遍历每一个房间
// 这题不用拓扑排序，因为是固定起点的，直接BFS搜索+visited避免重复就行了
class Solution {
public:
    static bool canVisitAllRoomsBfs(vector<vector<int>> &rooms) {
        const int n = rooms.size();
        vector<bool> visited(n, false);
        int visited_nodes_count = 0;
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            const int room = q.front();
            q.pop();
            if (visited[room]) {
                continue;
            }
            visited[room] = true;
            visited_nodes_count++;
            for (const int next_room:rooms[room]) {
                if (!visited[next_room]) {
                    q.push(next_room);
                }
            }
        }
        return visited_nodes_count == n;
    }

    static bool canVisitAllRooms(vector<vector<int>> &rooms) {
        const int n = rooms.size();
        vector<int> indegree(n, 0);

        // Build Graph
        vector<unordered_set<int>> graph(n, unordered_set<int>());
        for (size_t i = 0; i < n; i++) {
            const int n_keys = rooms[i].size();
            for (int j = 0; j < n_keys; j++) {
                int next_room = rooms[i][j];
                if (next_room == i) {
                    // 避免当前节点连向自己的入度
                    continue;
                }
                indegree[next_room]++;
                graph[i].insert(next_room);
            }
        }

        queue<int> q;
        q.push(0);
        int visited_room_count = 0;
        vector<bool> visited(n, false);
        while (!q.empty()) {
            int room = q.front();
            q.pop();
            if (visited[room]) {
                continue;
            }
            visited[room] = true;
            visited_room_count++;
            for (int next_room:graph[room]) {
                if (indegree[next_room] == 0 || indegree[next_room] == 1) {
                    indegree[next_room] = 0;
                    q.push(next_room);
                } else {
                    indegree[next_room]--;
                }
            }
        }

        cout << visited_room_count << endl;
        return visited_room_count == n;
    }
};

int main() {
    vector<vector<int>> test_case_1{{1},
                                    {2},
                                    {3},
                                    {}};
    vector<vector<int>> test_case_2{{1, 3},
                                    {3, 0, 1},
                                    {2},
                                    {0}};
    vector<vector<int>> test_case_3{{1},
                                    {1, 1}};
    cout << (Solution::canVisitAllRooms(test_case_3) ? "true" : "false") << endl;
    return 0;
}