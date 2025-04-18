#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <limits>
#include <vector>
#include <algorithm>


#pragma region DO NOT MODIFY 
double adjMatrix[51][51];
std::string cities[51];

void file_to_adjacency_matrix(std::string filename);

int city_to_index(std::string city);

void dijkstra(int s, int t);

int main() {
	file_to_adjacency_matrix("distances.csv");

	dijkstra(city_to_index("Portland ME"), city_to_index("Seattle WA"));
	std::cout << std::endl;

	dijkstra(city_to_index("Jacksonville FL"), city_to_index("Seattle WA"));
	std::cout << std::endl;

	dijkstra(city_to_index("Boston MA"), city_to_index("Los Angeles CA"));
	std::cout << std::endl;

	dijkstra(city_to_index("New York City NY"), city_to_index("Los Angeles CA"));
	std::cout << std::endl;

	dijkstra(city_to_index("Chicago IL"), city_to_index("Honolulu HI"));
	std::cout << std::endl;

	dijkstra(city_to_index("Nashville TN"), city_to_index("Milwaukee WI"));
	std::cout << std::endl;

	dijkstra(city_to_index("Milwaukee WI"), city_to_index("Anchorage AK"));
	std::cout << std::endl;

	dijkstra(city_to_index("Charlotte NC"), city_to_index("Houston TX"));
	std::cout << std::endl;

	dijkstra(city_to_index("Albuquerque NM"), city_to_index("Portland OR"));
	std::cout << std::endl;

	dijkstra(city_to_index("Philadelphia PA"), city_to_index("Las Vegas NV"));
	std::cout << std::endl;

	return 0;
}
#pragma endregion

void file_to_adjacency_matrix(std::string filename) {
	std::ifstream file(filename);

	//check
	if(!file.is_open()){
		std::cout << "failed to open file." << std::endl;
		return;
	}

	std::string line;

	//skip
	std::getline(file,line);

	for(int i = 0; i < 51; i++){
		std::getline(file,line);
		std::stringstream ss(line);

		std::string city;
		std::getline(ss, city, ',');
		cities[i]=city;

		//loop over disatances between cities
		for(int j = 0; j < 51; j++){
			std::string str_distance;
			std::getline(ss, str_distance, ',');


			//parse and set city to distance
			adjMatrix[i][j] = std::stod(str_distance);
		}

	}
}

int city_to_index(std::string city) {
	for (int i = 0; i < 51; i++){
		if(cities[i] == city){
			return i;
		}
	}
	return -1;
}

void dijkstra(int s, int t) {
    double dist[51];
    bool closed[51];
    int parent[51];

    for (int i = 0; i < 51; i++) {
        dist[i] = std::numeric_limits<double>::max();
        closed[i] = false;
        parent[i] = -1; 
    }

    dist[s] = 0;
   
    std::vector<int> open;
    open.push_back(s);
 
    while (!open.empty() ) {
        int umin = open[0];
        for (int i = 1; i < open.size(); i++) {
            if (dist[open[i]] < dist[umin]) {
                umin = open[i];
            }
        }

        //vector sauce
        open.erase(std::remove(open.begin(), open.end(), umin), open.end()) ;
        closed[umin] = true;

        for (int v = 0; v  < 51; v++) {
            if (adjMatrix[umin][v] == -1) continue;
            if (closed[v]) continue;                 

            double len = dist[umin] + adjMatrix[umin][v];

            if (len  < dist[v]) {
                dist[v] = len;
                parent[v] = umin;

                if (std::find(open.begin(), open.end(), v) == open.end()) {
                    open.push_back(v);
                }
            }
        }
    }

    if (dist[t] ==  std::numeric_limits<double>::max() ) {
        std::cout << "No path from " << cities[s] << " to "  << cities[t] << std::endl;
        return;
    }

    std::vector<int> path;
    int curr = t;
    while (curr != -1) {
        path.push_back(curr);
        curr = parent[curr];
    }

    std::cout << "Path from " << cities[s] << " to " << cities[t] << ":" << std::endl;
    for (int i = path.size() - 1; i >= 0; i--) {
        std::cout << cities[path[i]] << std::endl;
    }

    std::cout << "Total Distance: " << dist[t] << " miles" << std::endl;
}
