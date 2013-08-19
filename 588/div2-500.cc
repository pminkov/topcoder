
#include <iostream>
#include <vector>
using namespace std;

class GUMIAndSongsDiv2 {

public:
int maxSongs(vector<int> duration, vector<int> tone, int T) {
  int N = tone.size();
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < i; j++) {
      if (tone[j] > tone[i]) {
        swap(tone[i], tone[j]);
        swap(duration[i], duration[j]);
      }
    }
  }
  int r = 0;
  for (int mask = 0; mask < (1 << N); mask++) {
    int last = -1;
    int tot = 0;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
      if ((mask & (1 << i)) > 0) {
        cnt++;
        tot += duration[i];
        if (last >= 0) tot += tone[i] - tone[last];
        last = i;
      }
    }
    if (tot <= T) r = max(r, cnt);
  }
  return r;
}

};

int main() {

}
