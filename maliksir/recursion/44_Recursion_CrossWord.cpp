#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void Display(vector<vector<char>>& v){
    for(int i = 0; i<v.size(); i++){
        for(int j  = 0; j<v[0].size(); j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}


bool canPlaceHorizontally(vector<vector<char>>& v, string word, int i , int j){
    // ya toh left side honi nhi chaiye yaa phir hai toh wha plus hona chaiye

    if(j-1 >= 0 && v[i][j-1] != '+'){
        return false;
    }   
    // ya toh right side honi nh chaiye yaa ohir hai toh wha + hona chaiye

    else if(j+word.size() < v[0].size() && v[i][j+word.size()]!='+'){
        return false;
    }
    for(int jj=0; jj<word.size(); jj++){
        if(j+jj >= v[0].size()){
            return false;
        }
        if(v[i][j+jj]=='-' || v[i][j+jj]==word[jj]){
            continue;
        }
        else{
            return false;
        }
    }
    // cout<<"hori"<<i<<j<<"\n";
    return true;
}

bool canPlaceVertically(vector<vector<char>>& v, string word, int i, int j){
    if(i-1>=0 && v[i-1][j] != '+'){
        return false;
    

    }
    else if(i+word.size() < v.size() && v[i+word.size()][j]!='+'){
        return false;
    }
    for(int ii = 0; ii<word.size(); ii++){
        if(i+ii >= v.size()){
            return false;
        }
        if(v[i+ii][j] == '-' || v[i+ii][j] == word[ii]){
            continue;
        }
        else{
            return false;
        }
    }
    // cout<<"Verical"<<i<<j<<"\n";
    return true;
}

vector<bool> placeWordVertically(vector<vector<char>>& v, string word, int i , int j){
    vector<bool> wePlaced(word.size(), false);
    for(int ii = 0; ii<word.size(); ii++){
        if(v[i+ii][j]=='-'){
            v[i+ii][j] = word[ii];
            wePlaced[ii] = true;
        }
    }
    return wePlaced;
}
vector<bool> placeWordHorizontally(vector<vector<char>>& v, string word, int i , int j){
    vector<bool> wePlaced(word.size(), false);
    for(int jj = 0; jj<word.size(); jj++){
        if(v[i][j+jj]=='-'){
            v[i][j+jj] = word[jj];
            wePlaced[jj] = true;

        }
    }
    return wePlaced;
}

void unplaceWordHorizontally(vector<vector<char>>& v, vector<bool> wePlaced,int i , int j){
    for(int jj=0 ; jj<wePlaced.size(); jj++){
        if(wePlaced[jj]==true){
            v[i][j+jj] = '-';
        }
    }

}
void unplaceWordVertically(vector<vector<char>>& v, vector<bool>wePlaced, int i , int j){
    for(int  ii= 0; ii<wePlaced.size(); ii++){
        if(wePlaced[ii] == true){
            v[i][i+ii] = '-';
        }
    }
}

void Crossword(vector<vector<char>>& v, vector<string>& words, int wordIdx){
    if(wordIdx==words.size()){
        // cout<<"v\n";
        Display(v);
        return;
    }
    string word = words[wordIdx];
    // cout<<wordIdx<<"\n";
    for(int i = 0; i<v.size(); i++){
        for(int  j = 0; j<v[0].size(); j++){
            // cout<<"cl\n";
            if(v[i][j]=='-' || v[i][j]==word[0]){
                if(canPlaceHorizontally(v, word, i, j)){
                    vector<bool> wePlaced = placeWordHorizontally(v, word, i, j);
                    Crossword(v, words, wordIdx+1);
                    unplaceWordHorizontally(v, wePlaced, i, j);
                }
                if(canPlaceVertically(v, word, i , j)){
                    vector<bool> wePlaced = placeWordVertically(v, word, i, j);
                    Crossword(v, words, wordIdx+1);
                    unplaceWordVertically(v, wePlaced,i, j);
                }
            }
        }
    }
}



int main(){
    vector<vector<char>> v = {
        {'+', '+', '+', '+', '+', '+', '+', '+', '+', '-'},
        {'-',  '+', '+', '+', '+', '+', '+', '+', '+', '-'},
        {'-',  '-',  '-',  '-',  '-',  '-',  '-',  '+', '+', '-'},
        {'-',  '+', '+', '+', '+', '+', '+', '+', '+', '-'},
        {'-',  '+', '+', '+', '+', '+', '+', '+', '+', '-'},
        {'-',  '+', '+', '+', '+', '-',  '-',  '-',  '-',  '-'},
        {'-',  '-',  '-',  '-',  '-',  '-',  '+', '+', '+', '-'},
        {'-',  '+', '+', '+', '+', '+', '+', '+', '+', '-'},
        {'+', '-',  '-',  '-',  '-',  '-',  '-',  '-',  '-',  '-'},
        {'+', '+', '+', '+', '+', '+', '+', '+', '+', '+'}
    };

    vector<string> words;
    words.push_back("PHYSICS");
    words.push_back("CHEMISTRY");
    words.push_back("HISTORY");
    words.push_back("CIVICS");

    words.push_back("GEOGRAPHY");
    // Display(v);
    // cout<<endl;
    Crossword(v,words,0);
}