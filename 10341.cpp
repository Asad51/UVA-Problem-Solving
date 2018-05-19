#include <cstdio>
#include <cmath>
using namespace std;

#define err 0.0000001

int p, q, r, s, t, u;

double solve(double x){
	double a = p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
	return a;
}

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	while((scanf("%d%d%d%d%d%d", &p, &q, &r, &s, &t, &u)) != EOF){
		double l = 0.0;
		double h = 1.0;
		double res = -1, m;
		while(l<h){
			m = (h+l)/2.0;
			double s = solve(m);
			//printf("%lf\n", s);
			if(fabs(s)<=err){
				res = m;
				break;
			}
			else if(s>0)
				l = m;
			else
				h = m;
		}
		if(res==-1)
			printf("No solution\n");
		else{
			printf("%.4lf\n", res );
		}
	}
	return 0;
}
