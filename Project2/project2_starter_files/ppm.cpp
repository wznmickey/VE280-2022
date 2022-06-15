#include <fstream>
 
using namespace std;

int main() {
    constexpr auto width = 400u, height = 800u;

    ofstream ofs("first.ppm", ios_base::out | ios_base::binary);

    ofs << "P6" << endl << width << ' ' << height << endl << "255" << endl;
 
    for (auto j = 0u; j < height; ++j)
        for (auto i = 0u; i < width; ++i)
            ofs << (char) (255)        // red
		<< (char) (255)        // green
		<< (char) (255); // red, green, blue

    ofs.close();
    return EXIT_SUCCESS;
}
