#pragma once

#include <string>
#include <vector>

class Movie {
   public:
    Movie() = default;
    Movie(const std::string& title);
    Movie(const std::string& title, const std::string& director, int year, float rating,
          const std::string& mainActor, const std::vector<std::string>& actors,
          const std::vector<std::string>& genres);

    ~Movie() = default;

    enum class Status {
        PlanToWatch,
        Watching,
        Completed,
        Dropped,
        OnHold,
    };

    enum class TitleType { Movie, Series };

    enum class VisualType { RealFilm, Animated, Anime, Cartoon };

    void changeStatus(Movie::Status status);

    // Getters
    std::string getTitle();
    std::string getDirector();
    int getYear();
    float getRating();
    std::string getMainActor();

    // Setters
    void setTitle();
    void setDirector();
    void setYear();
    void setRating();
    void setMainActor();

   private:
    std::string mTitle;
    std::string mDirector;
    int mYear;
    float mRating;
    std::string mMainActor;
    Movie::TitleType mType;
    Movie::VisualType mVisual;
    Movie::Status mStatus;
    std::vector<std::string> mActors;
    std::vector<std::string> mGenres;
};

class Series : Movie {
   private:
    unsigned int mNumberOfSeasons;
    unsigned int mNumberOfEpisodes;
};

class MovieList {
   public:
    MovieList();
    MovieList(std::string name);
    MovieList(std::initializer_list<Movie> movies);

    ~MovieList() = default;

    void pushMovie(Movie movie);
    void popMovie();

    void printAllTitles(bool withHeader = false, bool withStatistics = false);

    // Getter
    std::string getListName();
    unsigned int getNumberOfMovies();

    // Setter
    void setListName(std::string name);

   private:
    std::vector<Movie> mMovieList;
    std::string mName;
    unsigned int mNumberOfMovies;
};
