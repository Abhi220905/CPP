#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Movie {
public:
    string title;
    string genre;
    int releasedYear;

    // Function to display movie details
    void display() {
        cout << "Title: " << title << " | Genre: " << genre << " | Year: " << releasedYear << endl;
    }
};

int main() {
    // Creating an array of Movie objects
    Movie movies[3];

    // Instantiating objects and setting attributes
    movies[0].title = "Inception";
    movies[0].genre = "Sci-Fi";
    movies[0].releasedYear = 2010;

    movies[1].title = "The Dark Knight";
    movies[1].genre = "Action";
    movies[1].releasedYear = 2008;

    movies[2].title = "Interstellar";
    movies[2].genre = "Sci-Fi";
    movies[2].releasedYear = 2014;

    cout << "--- Movie List ---" << endl;
    for (int i = 0; i < 3; i++) {
        movies[i].display();
    }

    return 0;
}
