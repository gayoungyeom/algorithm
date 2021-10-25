#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    double x, y;
    int b = (4 - brown ) / 2;

    x = (-b + sqrt(pow(b ,2) - 4 * yellow)) / 2;
    y = (brown - 4) / 2 - x;

    answer.push_back(x+2);
    answer.push_back(y+2);
    sort(answer.rbegin(), answer.rend());

    return answer;
}
