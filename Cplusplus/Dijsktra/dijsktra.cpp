/**
 * Implementation of Dijsktra
 */
#include <iostream>
#include <vector>
#include <limits>

#define FORI(s, n) for (int i = s; i < n; i++)
#define FORJ(s, n) for (int j = s; j < n; j++)

using VB = std::vector<bool>;
using VI = std::vector<int>;
using VVI = std::vector<VI>;

int INF = std::numeric_limits<int>::max();

int minDist(const VI &dist, const VB &visited);
void dijsktra(VVI &graph, int src);

void printAns(const VI &ans, int src, const VI &parents);

int main()
{

    VVI graph =
        {{0, 4, 0, 0, 0, 0, 0, 8, 0},
         {4, 0, 8, 0, 0, 0, 0, 11, 0},
         {0, 8, 0, 7, 0, 4, 0, 0, 2},
         {0, 0, 7, 0, 9, 14, 0, 0, 0},
         {0, 0, 0, 9, 0, 10, 0, 0, 0},
         {0, 0, 4, 14, 10, 0, 2, 0, 0},
         {0, 0, 0, 0, 0, 2, 0, 1, 6},
         {8, 11, 0, 0, 0, 0, 1, 0, 7},
         {0, 0, 2, 0, 0, 0, 6, 7, 0}};
    int src = 0;

    std::cout << "Source: " << src << '\n';
    dijsktra(graph, src);

    return 0;
}

void printPath(int src, int dest, const VI &parents)
{
    if (parents[dest] == -1)
    {
        return;
    }

    printPath(src, parents[dest], parents);
    std::cout << dest << " ";
}

void printAns(const VI &dist, int src, const VI &parents)
{
    FORI(0, dist.size())
    {
        if (i == src)
        {
            continue;
        }

        std::cout << src << " to " << i << '\t' << dist[i] << '\t';
        printPath(src, i, parents);
        std::cout << '\n';
    }
}

int minDist(const VI &dist, const VB &visited)
{
    int min = INF;
    int idx;
    FORI(0, dist.size())
    {
        if (!visited[i] && dist[i] <= min)
        {
            min = dist[i];
            idx = i;
        }
    }
    return idx;
}

void dijsktra(VVI &graph, int src)
{
    int vertexCount = graph.size();

    // To store distances from source
    VI dist(vertexCount, INF);
    // To keep track of visited nodes
    VB visited(vertexCount, false);
    // Parents for each vertex to find a shortest path
    VI parents(vertexCount, -1);

    // Distance of source from itself is 0
    dist[src] = 0;

    // Since we are considering a edge, we go one loop less
    FORI(0, vertexCount - 1)
    {
        // Find index of minimum element
        int minIdx = minDist(dist, visited);

        // Visit that element
        visited[minIdx] = true;

        // Find all paths from above minimum element
        FORJ(0, vertexCount)
        {
            // If it's not visited and a path exist
            // And our minIdx is valid, we check if we have smaller distance
            if (!visited[j] && graph[minIdx][j] && dist[minIdx] != INF && (dist[minIdx] + graph[minIdx][j] < dist[j]))
            {
                parents[j] = minIdx;
                dist[j] = dist[minIdx] + graph[minIdx][j];
            }
        }
    }
    printAns(dist, src, parents);
}