#include <iostream>
#include <vector>
#include <random>
#include <utility>

#define NUMBER_OF_NEIGHBORS 5

using Route = std::vector<int>;

void display(Route vector){
    for (int i = 0; i < vector.size(); i++){
        std::cout << vector[i] << " ";
    }
    std::cout << std::endl;
}


// generator dwoch miast do wymiany na ścieżce
std::pair<int,int> generate_cities_to_swap(Route route){

    int first_city = 0 + std::rand() % route.size();
    int second_city = 0 + std::rand() % route.size();

    while(first_city == second_city){
        second_city = 0 + std::rand() % route.size();
    }
    return {first_city, second_city};
    // std::cout << first_city << std::endl;
    // std::cout << second_city;
}

// zamiana wartości 2 elementów 
void swap(int& first, int& second){
    int temp = first;
    first = second;
    second = temp;
}
 // stworzenie sasiedztwa - nowej drogi poprzez wymiane 2 miast miejscami w wektorze
Route createNeighbor(Route route) {
    Route new_route(route);
    std::pair<int,int> cities_to_swap = generate_cities_to_swap(route);
    swap(new_route[ cities_to_swap.first ], new_route[ cities_to_swap.second ]);
    return new_route;

}

bool are_route_equal(Route first_route, Route second_route){
    for (int i=0; i<first_route.size(); i++){
        if(first_route[i] != second_route[i]){
            return false;
        }
    }
    return true;
}

bool is_already_in_neighbor(std::vector<Route> neighbors, Route candi )
{
    for(int i=0; i< neighbors.size(); i++){
        if( are_route_equal(neighbors[i], candi) )
            return true;
    }
    return false;
}

std::vector<Route> getNeighbors(Route route) {
    
    std::vector<Route> neighbors;

    for(int i=0; i <= NUMBER_OF_NEIGHBORS; i++){
        Route new_neighbor = createNeighbor(route);
        if(!is_already_in_neighbor( neighbors, new_neighbor ))
            neighbors.push_back( new_neighbor );
    }

    return neighbors;
}

std::vector<int> route {5,4,3,2,10};

// double fitness(std::vector<int> route){
//     double route_length;

//     for (int i=0; i < route.size() - 1; i++){
//         route_length += distance_matrix[ route[i] ][ route[i + 1]];
//     }
//     std::cout << route_length << std::endl;
// }

int main(){
    srand( time(NULL) );
    // fitness(route);
    createNeighbor(route);
   
    std::vector<Route> neighbors = getNeighbors(route);
 
    std::cout << "First route\n";
    display(route);

    //Route new_route = createNeighbor(route);
   // display(new_route);

    std::cout << "Neighbors \n";
    for(int i =0; i< NUMBER_OF_NEIGHBORS; i ++){
        display(neighbors[i]);
    }
}

