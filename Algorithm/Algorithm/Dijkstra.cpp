void Dijkstra(int start_node)
{
  dist[start_node] = 0;
  priority_queue<pair<int, int> > pq;
  pq.push(make_pair(0, start_node)); 
 
  while (false == pq.empty()) {
      int cost = -pq.top().first;    
      int curr = pq.top().second;    
      pq.pop();

      for (int i = 0; i < adj[curr].size(); i++) 
      {     
          int next = adj[cur][i].first;     
          int nCost = cost + adj[curr][i].second;     
        
          if (nCost < dist[next]) 
          { 
              dist[next] = nCost;   
              pq.push(make_pair(-nCost, next)); 
          }
      }
  }  
}
