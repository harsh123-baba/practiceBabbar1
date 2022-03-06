#include<bits/stdc++.h> 
#include<iostream>
using namespace std;

vector<int> sol;

void solution(vector<int> person, int nSkills, int cp, vector<int> onesol, int smask){
    if(cp==person.size()){
        if(smask == ((1<<nSkills)-1)){
            if(sol.size()==0 || sol.size() > onesol.size()){
                sol = onesol;
            }
        }
        return;
    }
    solution(person, nSkills, cp+1, onesol, smask);
    onesol.push_back(cp);
    solution(person, nSkills, cp+1, onesol, (smask | person[cp]));
    onesol.pop_back();

}

int main(){
    unordered_map<string, int> map;
    int nSkills = 3;
    for(int i = 0; i<nSkills; i++){
        string s;
        cin>>s;
        map[s]=i;
    }
    int nProgramers=4;
    vector<int> person(nProgramers);
    for(int  i = 0; i<nProgramers; i++){
        int pSkills;
        cin>>pSkills;
        for(int j = 0; j<pSkills; j++){
            string s;
            cin>>s;
            int SkillNum = map[s];
            person[i] = person[i] | (1<<SkillNum);

        }
    }
    vector<int> onesol;
    solution(person, nSkills, 0, onesol, 0);
    for(int i=0; i<sol.size(); i++){
        cout<<sol[i]<<" ";
    }
}
