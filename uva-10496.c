#include <stdio.h>

struct Beeper{
  int x;
  int y;
};

typedef struct Beeper Beeper;
int n, m;
int nb;

int min(int a, int b){
  return (a < b) ? a : b;
}

int abs(int n){
  return (n < 0) ? -n : n;
}

int solve(Beeper bs[], int check[], int index[], int cnt, int p, int i, int sum){
  sum += abs(bs[p].x - bs[i].x) + abs(bs[p].y - bs[i].y);
  if(cnt == nb){
    sum += abs(bs[0].x - bs[i].x) + abs(bs[0].y - bs[i].y);
    return sum;
  }
  int minSum = 1000001;
  for(int j = 1; j <= nb; j++){
    if(i != j && !check[j]){
      check[j] = 1;
      minSum = min(minSum, solve(bs, check, index, cnt + 1, i, j, sum));
      check[j] = 0;
    }
  }
  
  return minSum;
}

int main(void) {
  int t;
  scanf("%d", &t);
  while(t--){
    int sx, sy;
    scanf("%d %d", &n, &m);
    scanf("%d %d", &sx, &sy);
    scanf("%d", &nb);
    Beeper bs[nb + 1];
    int check[nb + 1], index[nb + 1];
    bs[0].x = sx;
    bs[0].y = sy;
    check[0] = 1;
    index[0] = 0;
    for(int i = 1; i <= nb; i++){
      scanf("%d %d", &bs[i].x, &bs[i].y);
      check[i] = 0;
      index[i] = 0;
    }
    printf("The shortest path has length %d\n", solve(bs, check, index, 0, 0, 0, 0));
  }
  return 0;
}