#include <iostream>
#include <vector>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> positions(N);
    for (int i = 0; i < N; ++i) {
        cin >> positions[i];
    }
    int left_drone = 1;  
    int right_drone = N; 
    for (int i = 0; i < N; ++i) {
        if (left_drone == right_drone) {
            cout << left_drone << " " << right_drone << "\n";
            cout << "Collision" << "\n";
            return 0;
        } else if (left_drone > right_drone) {
            cout << left_drone << " " << right_drone << "\n";
            cout << "Miss" << "\n";
            return 0;
        } else if (left_drone + positions[left_drone - 1] == right_drone) {
            cout << left_drone << " " << right_drone << "\n";
            cout << "Stopped" << "\n";
            return 0;
        } else if (right_drone - positions[right_drone - 1] == left_drone) {
            cout << left_drone << " " << right_drone << "\n";
            cout << "Stopped" << "\n";
            return 0;
        }
        left_drone += positions[left_drone - 1];
        right_drone -= positions[right_drone - 1];
    }
    cout << left_drone << " " << right_drone << "\n";
    return 0;
}
