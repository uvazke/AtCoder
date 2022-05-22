#include <algorithm>
#include <iostream>
#include <list>
#include <set>
#include <string>
#include <vector>
using namespace std;
vector<string> Rotate(vector<string> vec) {
  vector<string> newVec;
  copy(vec.begin(), vec.end(), back_inserter(newVec));
  int rowSize = vec[0].size();
  for (int i = 0; i < vec.size(); i++) {
    for (int j = 0; j < rowSize; j++) {
      newVec[i][j] = vec[rowSize - 1 - j][i];
    }
  }
  return newVec;
}

int main() {
  int N;
  string S[200], T[200];
  vector<string> PartS, PartT;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> S[i];
  }
  for (int i = 0; i < N; i++) {
    cin >> T[i];
  }
  int minSharpColumnIndex = N - 1;
  int maxSharpColumnIndex = 0;
  int minSharpRowIndex = N - 1;
  int maxSharpRowIndex = 0;
  for (int i = 0; i < N; i++) {
    string::size_type firstIndex = S[i].find("#");
    if (firstIndex == string::npos) {
      continue;
    }
    if (minSharpRowIndex == N - 1) {
      minSharpRowIndex = i;
    }
    minSharpColumnIndex = min((int)firstIndex, minSharpColumnIndex);
    maxSharpRowIndex = i;
    string::size_type lastIndex = S[i].find_last_of("#");

    maxSharpColumnIndex = max((int)lastIndex, maxSharpColumnIndex);
  }
  int minSharpColumnIndexT = N - 1;
  int maxSharpColumnIndexT = 0;
  int minSharpRowIndexT = N - 1;
  int maxSharpRowIndexT = 0;
  for (int i = 0; i < N; i++) {
    string::size_type firstIndex = T[i].find("#");
    if (firstIndex == string::npos) {
      continue;
    }
    if (minSharpRowIndexT == N - 1) {
      minSharpRowIndexT = i;
    }
    minSharpColumnIndexT = min((int)firstIndex, minSharpColumnIndexT);
    maxSharpRowIndexT = i;
    string::size_type lastIndex = T[i].find_last_of("#");
    maxSharpColumnIndexT = max((int)lastIndex, maxSharpColumnIndexT);
  }

  int rowCount = maxSharpRowIndex - minSharpRowIndex + 1;
  int columnCount = maxSharpColumnIndex - minSharpColumnIndex + 1;
  int maxSize = max(rowCount, columnCount);
  int rowAppendSize = maxSize - (maxSharpRowIndex - minSharpRowIndex);
  for (int i = minSharpRowIndex; i <= maxSharpRowIndex; i++) {
    string s = S[i].substr(minSharpColumnIndex, columnCount);
    int appendSize = maxSize - columnCount;
    if (appendSize > 0) {
      s.append(string(appendSize, '.'));
    }
    PartS.push_back(s);
  }

  for (int i = 0; i <= rowAppendSize; i++) {
    PartS.push_back(string(maxSize, '.'));
  }

  int rowCountT = maxSharpRowIndexT - minSharpRowIndexT + 1;
  int columnCountT = maxSharpColumnIndexT - minSharpColumnIndexT + 1;
  int maxSizeT = max(rowCountT, columnCountT);
  int rowAppendSizeT = maxSizeT - (maxSharpRowIndexT - minSharpRowIndexT);
  for (int i = minSharpRowIndexT; i <= maxSharpRowIndexT; i++) {
    string s = T[i].substr(minSharpColumnIndexT, columnCountT);
    int appendSize = maxSizeT - (columnCountT);
    if (appendSize > 0) {
      s.append(string(appendSize, '.'));
    }
    PartT.push_back(s);
  }

  for (int i = 0; i <= rowAppendSizeT; i++) {
    PartT.push_back(string(maxSizeT, '.'));
  }

  for (int i = 0; i < 4; i++) {

    for (int j = 0; j < rowCount; j++) {
      if (PartS[j].compare(PartT[j]) != 0) {
        j = rowCount;
      }
      if (j == rowCount - 1) {
        cout << "Yes" << endl;
        return 0;
      }
    }

    PartS = Rotate(PartS);
  }
  cout << "No" << endl;
  return 0;
}
