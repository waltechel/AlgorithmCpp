#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> getPartialTable(string str);
vector<int> getPossibleNameLength(const vector<int>& pi);
void printAnswer(const vector<int>& ans);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string name1, name2;
    cin >> name1;
    cin >> name2;
    
    string fullname = name1 + name2;
    vector<int> pi = getPartialTable(fullname);
    vector<int> answer = getPossibleNameLength(pi);
    
    if (fullname[0] == fullname[fullname.size() - 1]) {
        answer.push_back(1);
    }
    sort(answer.begin(), answer.end());
    printAnswer(answer);

    return 0;
}

vector<int> getPossibleNameLength(const vector<int>& pi) {
    vector<int> res;
    
    int nameLength = (int) pi.size();
    while(nameLength > 0) {
        res.push_back(nameLength);
        nameLength = pi[nameLength - 1];
        
        if (nameLength == 1) {
            break;
        }
    }
    
    return res;
}

vector<int> getPartialTable(string str) {
    vector<int> pi(str.size(), 0);
    
    int begin = 1;
    int matched = 0;
    
    while(begin + matched < str.size()) {
        if (str[begin + matched] == str[matched]) {
            pi[begin + matched] = matched + 1;
            matched++;
        } else {
            if (matched == 0) {
                begin++;
            } else {
                begin = begin + matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }
    
    return pi;
}

void printAnswer(const vector<int>& ans) {
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}
