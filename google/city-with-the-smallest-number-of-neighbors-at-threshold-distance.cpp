class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, 1e9));

        for(int i = 0; i < n; i++) dist[i][i] = 0;
        for(auto edge : edges)
            dist[edge[0]][edge[1]] = dist[edge[1]][edge[0]] = edge[2];

        for(int via = 0; via < n; via++)
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);

        int ans_conn_to = 1e9, ans_city = 0;

        for(int city = 0; city < n; city++){
            int cities_in_radar = 0;
            for(int d : dist[city])
                cities_in_radar += (d <= distanceThreshold);

            if(cities_in_radar > ans_conn_to) continue;
            ans_conn_to = cities_in_radar;
            ans_city = city;
        }

        return ans_city;
    }
};

// Approch : Applied floydd warshall to know the Smallest dist of every node to other possible and then 
//           iterating dist metric of each node and and if its min_nodes are lesser than yet recorded or equal, update the ans node and dist_metric
 