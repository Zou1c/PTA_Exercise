#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int getID(char name[]){
    int id = 0;
    for(int i=0;i<3;++i) id = id*26+(name[i]-'A');
    id = id*10+(name[3]-'0');
    return id;
}
vector<int> vi[26*26*26*10+1];
int main()
{
    int N, K;
    char name[5];
    int course, Ni;
    cin >> N >> K;
    for(int i=0;i<K;++i){
        cin >> course >> Ni;
        for(int j=0;j<Ni;++j){
            cin >> name;
            vi[getID(name)].push_back(course);
        }
    }
    for(int i=0;i<N;++i){
        cin >> name;
        cout << name << " " << vi[getID(name)].size();
        sort(vi[getID(name)].begin(), vi[getID(name)].end());
        for(int j=0;j<vi[getID(name)].size();++j)
            cout << " " << vi[getID(name)][j];
        cout << endl;
    }
}
