#include "truck_tsp.hpp"

double distance_between_cities(Coordinate first_city, Coordinate second_city){
    return sqrt(pow(first_city.length - second_city.length, 2) + pow(first_city.width- second_city.width, 2));
}

bool is_near_enough_to(double supect, double center, double measurement_error ){
    return supect >= center - measurement_error && supect <= center + measurement_error;
}

Matrix make_real_distance_matrix(){
    
    Matrix distance_matrix( cities.size(), std::vector<double>( cities.size(), 0 ) );

    for( int i = 0; i < cities.size(); i++ )
        for( int j = 0; j < cities.size(); j++ )
            distance_matrix[ i ][ j ] = geo_degree_in_km * distance_between_cities( cities[ i ], cities[ j ] );

    return distance_matrix;
}

void display(Route route){
    const int word_width = 15;
    for (int i = 0; i < route.size(); i++){
        std::cout << std::setw( word_width ) << name_of_cities[ route[ i ] ] << " ";
    }

    std::cout << ": Whole distance is " << fitness(route) << std::endl;

    for (int i = 0; i < route.size(); i++){
        std::cout << std::setw( word_width ) << route[i] << " ";
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

double fitness(std::vector<int> route){
    double route_length;
    static Matrix distance_matrix = make_real_distance_matrix();

    for (int i = 0; i < route.size() - 1; i++)
        route_length += distance_matrix[ route[i] ][ route[i + 1]];

    return route_length;
}

int main(){

    srand( time(NULL) );
    createNeighbor(route);
    std::vector<Route> neighbors = getNeighbors(route);

    std::cout << "First route\n";
    display(route);

    std::cout << "Neighbors \n";
    for(int i =0; i< neighbors.size(); i ++){
        display(neighbors[i]);
    }
}

