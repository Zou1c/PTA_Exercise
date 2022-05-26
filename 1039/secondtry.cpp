#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<int> Info[26*26*26*10+1];
//下标为id号，值为课程号;后面扩充为二维数组

int getId(char str[]){//自定义进制数？(这段我还需要理解一下)
    int num1 = (str[0] - 'A');
    int num2 = (str[1] - 'A') + num1*26;
    int num3 = (str[2] - 'A') + num2*26;
    int num4 = (str[3] - '0') + num3*10;
    return num4;
}

int main(){
    int Ncourse;
    int Nstudent;
    cin>>Nstudent>>Ncourse;
    
    int course;
    int num;
    for(int i=0;i<Ncourse;i++){
        cin>>course>>num;
        for(int j=0;j<num;j++){
            char tmp[5];
            cin>>tmp;
            Info[getId(tmp)].push_back(course);
            //输入的时候就完成了分类统计
        }
    }
    
    for(int i=0;i<Nstudent;i++){
        char name[5];
        cin>>name;
        
        int id=getId(name);
        int len=Info[id].size();
        cout<<name<<" "<<len;
        
        sort(Info[id].begin(),Info[id].end());
        for(int j=0;j<len;j++){
            cout<<" "<<Info[id][j];
        }
        
        cout<<endl;
    }
    
    return 0;
}
