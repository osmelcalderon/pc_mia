#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<string, int> animal_index;
    vector<string> animal(n);
    vector<set<string>> features(n);
    for(int i=0; i<n; i++) {
        int m;
        cin >> animal[i] >> m;
        animal_index[animal[i]] = i;
        for(int j=0; j<m; j++) {
            string feature;
            cin >> feature;
            features[i].insert(feature);
        }
    }
    int max_yes = 0;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            set<string> common;
            set_intersection(features[i].begin(), features[i].end(), features[j].begin(), features[j].end(), inserter(common, common.begin()));
            max_yes = max(max_yes, (int)common.size());
        }
    }
    cout << max_yes+1 << endl;
    return 0;
}