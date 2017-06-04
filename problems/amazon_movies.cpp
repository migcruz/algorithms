#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <list>
#include <cmath>
#include <ctime>
#include <climits>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>


using namespace std;
 
class Movie {
private:
    int movieId;
    float rating;
    vector<Movie*> similarMovies; // Similarity is bidirectional
 
public:
    Movie(int movieId, float rating) {
        this->movieId = movieId;
        this->rating = rating;
    }
 
    int getId() {
        return movieId;
    }
 
    float getRating() {
        return rating;
    }
 
    void addSimilarMovie(Movie* movie) {
        similarMovies.push_back(movie);
        movie->similarMovies.push_back(this);
    }
 
    vector<Movie *>& getSimilarMovies() {
        return similarMovies;
    }
};




/* 
 * @param movie Current movie.
 * @param numTopRatedSimilarMovies the maximum number of recommended movies to return.
 * @return List of top rated similar movies.
 * 
 * Assumptions I made: TODO
 * 
 * Description of my approach: TODO
 *
 * Runtime complexity of my approach: TODO
 *
 * Justification of runtime complexity: TODO
 *
 */

static void getMovieRecommendations(Movie& movie, int numTopRatedSimilarMovies, vector<Movie *>& recommendedMovies) {
	vector<Movie*> similarMovies;
	vector<Movie*> moreSimilarMovies;
	vector<Movie*> evenMoreSimilarMovies;
	similarMovies = movie.getSimilarMovies();
	Movie* temp;
	int numberOfLoops;

	// Store the movies by their ratings using reverse bubble sort
	bool sorting = true;
	while(sorting)
	{
		sorting = false;
		for (int i = 0; i < similarMovies.size() - 1; i++)
		{
			if (similarMovies[i]->getRating() < similarMovies[i+1]->getRating())
			{
				temp = similarMovies[i];
				similarMovies[i] = similarMovies[i+1];
				similarMovies[i+1] = temp;
				sorting = true;

			}
		}
	}

	// Only sort the closest and highest rated movies
	if (numTopRatedSimilarMovies > similarMovies.size())
	{
		numberOfLoops = similarMovies.size();
	}
	else
	{
		numberOfLoops = numTopRatedSimilarMovies;
	}

	// Sort each of the similar movies' similar movies
	for (int j = 0; j < numberOfLoops; j++)
	{
		sorting = true
		moreSimilarMovies = similarMovies[j].getSimilarMovies();
		while(sorting)
		{
			sorting = false;
			for (int i = 0; i < moreSimilarMovies.size() - 1; i++)
			{
				if (moreSimilarMovies[i]->getRating() < moreSimilarMovies[i+1]->getRating())
				{
					temp = moreSimilarMovies[i];
					moreSimilarMovies[i] = moreSimilarMovies[i+1];
					moreSimilarMovies[i+1] = temp;
					sorting = true;

				}
			}
		}

		// Add at least the similar movie and the similar movies' similar movies
		evenMoreSimilarMovies.push_back(similarMovies[j]);
		for (int k = 0; k < numTopRatedSimilarMovies - 1; k++)
		{
			evenMoreSimilarMovies.push_back(moreSimilarMovies[i]);
		}
	}

	// Final sort and pick
	sorting = true
	while(sorting)
	{
		sorting = false;
		for (int i = 0; i < evenMoreSimilarMovies.size() - 1; i++)
		{
			if (evenMoreSimilarMovies[i]->getRating() < evenMoreSimilarMovies[i+1]->getRating())
			{
				temp = evenMoreSimilarMovies[i];
				evenMoreSimilarMovies[i] = evenMoreSimilarMovies[i+1];
				evenMoreSimilarMovies[i+1] = temp;
				sorting = true;

			}
		}
	}
	for (int k = 0; k < numTopRatedSimilarMovies; k++)
	{
		recommendedMovies.push_back(evenMoreSimilarMovies[k]);
	}

    return;
}



bool movieIdCompare (Movie* a, Movie* b) { return (a->getId() < b->getId()); }

int main() {
	std::map<int, Movie*> movieMap;
	Movie* rootMovie = NULL;
    int numTopRatedSimilarMovies = 0;

	string type;
	while (cin >> type) {
        if (type.compare("movie") == 0) {
        	cout << "CASE1" << endl;
            int id;
            float rating;
            cin >> id >> rating;
            movieMap[id] = new Movie(id, rating);
        }
        else if (type.compare("similar") == 0) {
        	cout << "CASE2" << endl;
        	int movieId1, movieId2;
        	cin >> movieId1 >> movieId2;
            movieMap[movieId1]->addSimilarMovie(movieMap[movieId2]);
        }
        else if (type.compare("params") == 0) {
        	cout << "CASE3" << endl;
        	int rootId;
        	cin >> rootId >> numTopRatedSimilarMovies;
            rootMovie = movieMap[rootId];
        }
        else {
        	cout << "OTHER" << endl;
            // ignore comments and whitespace
        }
	}

    vector<Movie*> result;
    getMovieRecommendations(*rootMovie, numTopRatedSimilarMovies, result);
    std::sort(result.begin(), result.end(), movieIdCompare);
    
    ofstream fout(getenv("OUTPUT_PATH"));
    fout << "result";
    
    for (int i = 0; i < result.size(); ++i) {
        fout << " ";
        fout << result[i]->getId();
    }
    
    fout << endl;
    fout.close();
    
    return 0;
}
lol.cpp
Open with
Displaying exam.py.