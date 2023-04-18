class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // pair {dist,node}
        set<pair<int, int>> st;
        vector<int> dist(V, 1e9);
        st.insert({0, S});
        dist[S] = 0;

        // Now, erase the minimum distance node first from the set
        // and traverse for all its adjacent nodes.
        while (!st.empty())
        {
            auto it = *(st.begin());
            int node = it.second;
            int dis = it.first;
            st.erase(it);

            // Check for all adjacent nodes of the erased
            // element whether the prev dist is larger than current or not.
            for (auto it : adj[node])
            {
                int adjNode = it[0];
                int edgW = it[1];

                if (dis + edgW < dist[adjNode])
                {
                    // erase if it was visited previously at
                    // a greater cost.
                    if (dist[adjNode] != 1e9)
                        st.erase({dist[adjNode], adjNode});

                    // If current distance is smaller,
                    // push it into the queue
                    dist[adjNode] = dis + edgW;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};