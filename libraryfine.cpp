#include <iostream>
using namespace std;

int libraryFine(int d1, int m1, int y1, int d2, int m2, int y2) {
    // If the book is returned on time or early
    if (y1 < y2 || (y1 == y2 && m1 < m2) || (y1 == y2 && m1 == m2 && d1 <= d2)) {
        return 0;
    }
    
    // If the book is returned after the due date, but within the same year and month
    if (y1 == y2 && m1 == m2 && d1 > d2) {
        return 15 * (d1 - d2);
    }
    
    // If the book is returned after the due month but within the same year
    if (y1 == y2 && m1 > m2) {
        return 500 * (m1 - m2);
    }
    
    // If the book is returned in a later year
    if (y1 > y2) {
        return 10000;
    }

    return 0; // Just in case, though it should never reach here due to the logic above
}

int main() {
    int d1, m1, y1, d2, m2, y2;
    // Read the returned date (d1, m1, y1)
    cin >> d1 >> m1 >> y1;
    // Read the due date (d2, m2, y2)
    cin >> d2 >> m2 >> y2;
    
    // Call the function to calculate the fine and output the result
    cout << libraryFine(d1, m1, y1, d2, m2, y2) << endl;
    
    return 0;
}
