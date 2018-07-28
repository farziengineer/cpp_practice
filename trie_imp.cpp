#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
	bool is_end_of_word;
	map<int, TrieNode* > children;
	// TrieNode* children[26];
};

TrieNode* getNode()
{
	TrieNode* new_node = new TrieNode;

	new_node->is_end_of_word = false;
	for(int i=0 ; i<26 ; i+=1)
	{
		new_node->children[i] = NULL;
	}

	return new_node;
}


void insert(TrieNode* root, string s)
{
	TrieNode* temp = root;

	for(int i = 0; s[i]!='\0'; i+=1)
	{
		if(temp->children[s[i]-'a']==NULL)
			temp->children[s[i]-'a']=getNode();
		temp = temp->children[s[i]-'a'];
	}

	temp->is_end_of_word = true;
}

bool search(TrieNode* root, string s)
{
	TrieNode* temp = root;

	for(int i=0 ; s[i]!='\0' ; i+=1)
	{
		if(temp->children[s[i]-'a']==NULL)
			return false;
		temp = temp->children[s[i]-'a'];
	}
	return temp->is_end_of_word;
}

TrieNode* getparent(TrieNode* root, string pref)
{

	for(int i=0 ; pref[i]!='\0' ; i+=1)
	{
		root=root->children[pref[i]-'a'];
	}
	return root;
}


vector < char > vec;

void prefix_match(TrieNode* parent)
{	
	if(parent == NULL)
		return;

	if(parent->is_end_of_word==true)
	{
		for(int i=0;i<vec.size();i+=1)
			cout<<vec[i];
		cout<<endl;
	}

	for(int i=0; i<26; i+=1)
	{
		if(parent->children[i])
		{
			vec.push_back(char(i+'a'));
			prefix_match(parent->children[i]);
			vec.pop_back();
		}
	}
}

void longest_prefix_match(TrieNode* root, string &prefix)
{
	if(root == NULL)
		return;

	string longest = "", sub_str = "";
	for(int i = 0; prefix[i] != '\0'; i +=1)
	{
		root = root->children[prefix[i] - 'a'];
		sub_str = sub_str + prefix[i];
		if(root == NULL)
			break;
		if(root and root->is_end_of_word == true)
		{
			longest = sub_str;
		}

	}
	cout<<longest<<endl;
	return;
}

int main()
{
	TrieNode* root = getNode();
		insert(root, "are");
        insert(root, "area");
        insert(root, "base");
        insert(root, "cat");
        insert(root, "cater");
        insert(root, "basement");	
        string s;
	// cin>>s;
	// cout<<search(root, s)<<endl;
	string pref;
	cin>>pref;
	// TrieNode* parent = getparent(root, pref);
	// prefix_match(parent);
	longest_prefix_match(root, pref);
	return 0;
}