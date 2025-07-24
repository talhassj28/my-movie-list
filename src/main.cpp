#include <iostream>

#include "cli.cpp"
#include "my_movie_list.hpp"

int main() {
    printLandingPage();

    MovieList movieList;

    std::string userInput;
    while (userInput != "Q" && userInput != "q") {
        std::cout << "Movie name to add or type \"Q\"" << std::endl;
        std::cin >> userInput;
        std::cout << std::endl;

        if (userInput != "Q" && userInput != "q") {
            Movie movie(userInput);

            movieList.pushMovie(movie);
        }
    }

    movieList.printAllTitles(true, true);

    return 0;
}
