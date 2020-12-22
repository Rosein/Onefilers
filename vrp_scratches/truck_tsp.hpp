#ifndef TRUCK_TSP
#define TRUCK_TSP

#include <iostream>
#include <vector>
#include <random>
#include <utility>
#include <iomanip>

#define NUMBER_OF_NEIGHBORS 5

using Route = std::vector<int>;
using Matrix = std::vector<std::vector<double>>;

const double geo_degree_in_km = 111.1; 

//typ dla miasta szerokosc/długosc geo
struct Coordinate{
    double width;
    double length;
};

std::vector<std::string> name_of_cities { "Krakow", "Bialystok", "Bie-Biala", "Chrzanow", "Gdansk", "Gdynia", "Gliwice", "Gromnik", "Katowice", "Kielce", "Krosno", "Krynica", "Lublin", "Lodz", "Malbork", "Nowy Targ", "Olsztyn", "Poznan", "Pulawy", "Radom", "Rzeszow", "Sandomierz", "Szczecin", "Szczucin", "Szk Poreba", "Tarnow", "Warszawa", "Wieliczka", "Wroclaw", "Zakopane", "Zamosc" };
std::vector<Coordinate> cities = {
        {50.0619474, 19.9368564},
        {53.132398, 23.1591679},
        {49.822118, 19.0448936},
        {50.1411926, 19.4028502},
        {54.347629, 18.6452324},
        {54.5164982, 18.5402738},
        {50.294113, 18.6657306},
        {53.7361111, 15.9897222},
        {50.2598987, 19.0215852},
        {50.8716657, 20.6314728},
        {49.6938045, 21.7651458},
        {53.0336093, 23.5880673},
        {51.250559, 22.5701022},
        {51.7687323, 19.4569911},
        {54.0359361, 19.0348817},
        {49.4818229, 20.030541},
        {53.7766839, 20.476507},
        {52.4082663, 16.9335199},
        {51.4171713, 21.9720582},
        {51.4022557, 21.1541546},
        {50.0374531, 22.0047174},
        {50.6793066, 21.7495055},
        {53.4301818, 14.5509623},
        {50.3090256, 21.075161},
        {50.8275855, 15.5211659},
        {50.0123784, 20.9880739},
        {52.2319581, 21.0067249},
        {49.9823773, 20.0602114},
        {51.1089776, 17.0326689},
        {49.2969446, 19.950659},
        {50.7170854, 23.2525711}
    }; 

std::vector<int> route {0, 1, 3};

double distance_between_cities(Coordinate first_city, Coordinate second_city);
bool is_near_enough_to(double supect, double center, double measurement_error = 0.000001);
Matrix make_real_distance_matrix();

void display(Route vector);
std::pair<int,int> generate_cities_to_swap(Route route);
void swap(int& first, int& second);
Route createNeighbor(Route route);
bool are_route_equal(Route first_route, Route second_route);
bool is_already_in_neighbor(std::vector<Route> neighbors, Route candi );
std::vector<Route> getNeighbors(Route route);
double fitness(std::vector<int> route);

#endif //TRUCK_TSP