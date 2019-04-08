#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

struct Point{
    int x;
    int y;
};

class Network{
    int check[10], selected[10], solution[10], n;
    double minSum;
    Point points[10];
public:
    Network(int n){
        this->n = n;
        minSum = 999999.0;
    }

    void getInput(){
        for(int i = 0; i < n; i++){
            scanf("%d %d", &points[i].x, &points[i].y);
        }
    }

    void findNetwork(int i, double sum, int cnt)
    {
        if(cnt >= n){
            if(sum < minSum){
                minSum = sum;
                for(int j = 0; j < n; j++){
                    solution[j] = selected[j];
                }
            }
            return;
        }

        for(int j = 0; j < n; j++){
            if(!check[j]){
                check[j] = 1;
                selected[cnt] = j;
                double tmp = sqrt(pow(points[i].x - points[j].x, 2) + pow(points[i].y - points[j].y, 2));
                findNetwork(j, sum + tmp + 16, cnt + 1);
                check[j] = 0;
                selected[cnt] = 0;
            }
        }
    }

    void solve(){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                check[j] = 0;
                selected[j] = 0;
            }
            check[i] = 1;
            selected[0] = i;
            findNetwork(i, 0.0, 1);
        }
    }

    void printResult(){
        for(int i = 1; i < n; i++){
            int j = solution[i - 1], k = solution[i];
            double tmp = sqrt(pow(points[j].x - points[k].x, 2) + pow(points[j].y - points[k].y, 2)) + 16;
            printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n", points[j].x, points[j].y, points[k].x, points[k].y, tmp);
        }
        printf("Number of feet of cable required is %.2lf.\n", minSum);
    }
};

int main() {
    int n;
    int cs = 0;
    while(scanf("%d", &n) && n){
        Network network(n);
        network.getInput();
        network.solve();
        printf("**********************************************************\nNetwork #%d\n",++cs );
        network.printResult();
    }
    return 0;
}
