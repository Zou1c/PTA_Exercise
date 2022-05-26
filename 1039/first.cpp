#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<string> Names;
int getName(string name){
    int len=Names.size();
    for(int i=0;i<len;i++){
        if(name == Names[i])
            return i;
    }
    return 0;
}

int main(){
    int Ncourse;
    int Nstudent;
    cin>>Nstudent>>Ncourse;
    
    vector<vector<string>> table;
    vector<int> tableindex;
    for(int i=0;i<Ncourse;i++){
        int Cnumber;
        int num;
        cin>>Cnumber>>num;
        vector<string> list;
        for(int j=0;j<num;j++){
            string tmp;
            cin>>tmp;
            list.push_back(tmp);
        }
        table.push_back(list);
        tableindex.push_back(Cnumber);
    }
    
    for(int i=0;i<Nstudent;i++){
        string tmp;
        cin>>tmp;
        Names.push_back(tmp);
    }
    //read completed--

    vector<vector<int>> SCourse;
    SCourse.resize(Nstudent);
    for(int i=0;i<Ncourse;i++){
        vector<string> snames = table[i];
        int cnumber = tableindex[i];
        
        for(int j=0,len=snames.size();j<len;j++){
            int nameindex = getName(snames[j]);//超时了！
            SCourse[nameindex].push_back(cnumber);
        }
    }
    for(int i=0;i<Nstudent;i++)
        sort(SCourse[i].begin(),SCourse[i].end());
    
    
    //print Names and SCourse:
    for(int i=0;i<Nstudent;i++){
        cout<<Names[i]<<" ";
        int len=SCourse[i].size();
        if(len == 0)
            cout<<len<<endl;
        else
            cout<<len<<" ";
        for(int j=0;j<len;j++){
            if(j == len-1)
                cout<<SCourse[i][j]<<endl;
            else
                cout<<SCourse[i][j]<<" ";
        }
    }
}
