#include "my_movie_list.hpp"

#include <iostream>
#include <string>
#include <vector>

// Movie Methods

Movie::Movie(const std::string& title) : mTitle(title) {}

Movie::Movie(const std::string& title, const std::string& director, int year, float rating,
             const std::string& mainActor, const std::vector<std::string>& actors,
             const std::vector<std::string>& genres)
    : mTitle(title),
      mDirector(director),
      mYear(year),
      mRating(rating),
      mMainActor(mainActor),
      mActors(actors),
      mGenres(genres) {}

void Movie::changeStatus(Movie::Status status) { mStatus = status; }

std::string Movie::getTitle() { return mTitle; }

// MovieList Methods

MovieList::MovieList() {
    mName = "Untitled List";
    mNumberOfMovies = 0;
}

MovieList::MovieList(std::string name) {
    mName = name;
    mNumberOfMovies = 0;
}

MovieList::MovieList(std::initializer_list<Movie> movies) {
    mMovieList = movies;
    mNumberOfMovies = movies.size();
}

void MovieList::pushMovie(Movie movie) {
    mMovieList.push_back(movie);
    mNumberOfMovies++;
}

void MovieList::popMovie() {
    mMovieList.pop_back();
    mNumberOfMovies--;
}

std::string MovieList::getListName() { return mName; }

unsigned int MovieList::getNumberOfMovies() { return mNumberOfMovies; }

void MovieList::setListName(std::string name) { mName = name; }

void MovieList::printAllTitles(bool withHeader, bool withStatistics) {
    if (withStatistics) {
        std::cout << mName << " contains " << mNumberOfMovies << " movies." << std::endl;
    }

    if (mNumberOfMovies != 0) {
        if (withHeader) {
            std::cout << "Titles in " << mName << ":" << std::endl;
        }

        for (Movie movie : mMovieList) {
            std::cout << movie.getTitle() << std::endl;
        }
    }
}
