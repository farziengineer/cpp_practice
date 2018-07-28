#include <iostream>
#include <string>
#include <vector>
#include<map>
#include<bits/stdc++.h>
using namespace std;

struct word_detail{
  string word;
  int freq;
  int indx;
  
  
};

bool cmp(word_detail a, word_detail b)
{
  if(a.freq < b.freq)
    return true;
  if(a.freq == b.freq)
  {
    return a.indx < b.indx;
  }
}

vector<vector<string> > wordCountEngine(const  string& documen ) 
{
  // your code goes here
  string document  = documen;
  string words;
  vector<string> word_list;
  for(int i = 0; document[i]; i+=1)
  {
    if(document[i] == ' ')
    {
      word_list.push_back(words);
      words = "";
    }
    else
    {
      if(document[i] >= 'A' and document[i] <= 'Z')
        document[i] = document[i] -'A' +'a';
      else if(document[i] == '.' or document[i] == ',' or document[i] == '!' or document[i] == '\'')
        continue;
      
      words = words + document[i];
    }
  }
  
  if(words != "")
    word_list.push_back(words);
  
  map<string, int> mp;
  
  map<string, int> first_occur;
  
  for(int i = 0; i <word_list.size(); i +=1)
  {
    mp[word_list[i]] +=1;
  }
  
  for(int i = 0 ;i < word_list.size(); i +=1)
  {
    if(first_occur.count(word_list[i]) == 0)
      first_occur[word_list[i]] = i;
  }
  
  vector<word_detail> vec;
  
  for(int i = 0; i < word_list.size(); i +=1)
  {
    word_detail x;
    x.word = word_list[i];
    x.freq = mp[word_list[i]];
    x.indx = first_occur[word_list[i]];
    vec.push_back(x);
  }
  
  
  sort(vec.begin(), vec.end(), cmp);
  
  vector<vector<string> > ans;
  
  for(int i = 0; i < vec.size(); i +=1)
  {
    vector<string> temp = {vec[i].word, to_string(vec[i].freq)};
    ans.push_back(temp);
  }
  
  
  return ans;
  
}

int main() {
	vector<vector<string > > vec = wordCountEngine("Practice makes perfect. you'll only get Perfect by practice. just practice!");

	for(int i = 0; i < vec.size(); i +=1)
	{
		cout<<vec[i][0]<<" "<<vec[i][1]<<endl;
	}

  return 0;
}