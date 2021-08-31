//
//  algospotCastle.cpp
//  boj1926bfs
//
//  Created by 강명진 on 2021/08/31.
//
// https://zoosso.tistory.com/590 까망 하르방님 블로그의 코드를 참고했습니다..
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int tc,n,longest;
int x[1001],y[1001],r[1001];

struct Tree{ //tree구현
    vector<Tree*> child;//서로의 관계만 필요하기 때문에 child만 필요..
};

bool enClosed(int a,int b){//두원이 속해있는지 확인하는 함수
    if (r[a]>r[b]){//왼쪽의 원의 반지름 ra가 오른쪽 원의 반지름 rb보다 커야한다
        int dSquare=(x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]); // 원과 원사이의 거리의 제곱
        int rSquare=(r[a]-r[b])*(r[a]-r[b]); //두반지름의 차이의 제곱..
        if (rSquare>dSquare)return true;//a원 내부에 b가 있으려면 r(a의 반지름)>D+R(b의 반지름) 이여야함.  -> r-R>D c++ 에서 소숫점 계산 하면 까다로워서 제곱한다..
    }
    return false;
}

bool isChild(int parent,int child){// 두 노드가 서로 자식 부모 관계인지 확인..
    if (!enClosed(parent,child)){//child 원이 parent 원 내부에 있는지 확인.. 만약 child가 parent 원 내부에 없으면 절대 부모자식 관계 아니다..
        return false;
    }
    for (int i =0;i<n;i++){//갯수가 1000개 밖에 안되서 전부 확인..
        if (i!=parent&&i!=child&&enClosed(parent,i)&&enClosed(i,child))return false;//중간에 누가 끼면 안된다.. 따라서 parent,i와 i,parent의 원 내부에 있는지 확인..
    }
    return true;
}

Tree* getTree(int root){
    Tree* tmp=new Tree();//현재 노드 생성
    for (int i = 0 ; i <n;i++){//부모 자식 관계인 노드 확인(모든 노드를 검색해본다) 갯수가 1000개라서..
        if (isChild(root, i)){
            tmp->child.push_back(getTree(i));//i가 자식 관계일 경우 child vector에 push_back한다.. 재귀적으로 모든 노드 생성..
        }
    }
    return tmp;
}


int height(Tree* root){//높이를 구한다.
    vector<int> heights;//높이 벡터를 생성 이유는 벡터를 소팅해서  subtree중 가장 긴 높이중 두개를 찾아야 해서..
    for (int i = 0 ; i <root->child.size();i++){//재귀적으로 구현한다.. 이유는 subtree중 한 subtree에서의 subtree끼리 방문했을때 가장 긴 길이가 나올수 있어서
        heights.push_back(height(root->child[i]));
    }
    if (heights.empty())return 0;
    sort(heights.begin(),heights.end());
    if (heights.size()>=2){
        longest = max(longest,2+heights[heights.size()-2]+heights[heights.size()-1]);//sort했을때 가장 긴두개의 합이 긴 경우가 있을수 잇어서
    }
    return heights.back()+1;//또는 현재의 가장긴 길이만 방문했을때 길수도 있기 때문에
}

int solve(Tree* root){
    longest=0;
    int h=height(root);
    return max(longest,h);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>tc;
    for (int i=0;i<tc;i++){
        cin>>n;
        for (int j=0;j<n;j++){
            cin>>x[j]>>y[j]>>r[j];
        }
        Tree* root=getTree(0);
        cout<<solve(root)<<'\n';
    }
}