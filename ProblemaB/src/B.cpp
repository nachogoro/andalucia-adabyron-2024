#include <bits/stdc++.h>

using namespace std;

struct TrieNode {
	int baddieCounter=0;
	int heroCounter=0;

	bool endOfBaddie=false;
	bool endOfHero=false;

	map<char, TrieNode*> children;

	~TrieNode() {
		for (auto [letter, child] : children) {
			delete child;
		}
	}
};

struct Trie {
	TrieNode* root = new TrieNode();

	~Trie() { delete root; }

	void insert(string_view word, bool hero) {
		insert_internal(word, hero, root);
	}

	void insert_internal(string_view word, bool hero, TrieNode* ptr) {
		if (hero)
			ptr->heroCounter++;
		else
			ptr->baddieCounter++;

		if (word.empty()) {
			if (hero) {
				ptr->endOfHero = true;
			} else {
				ptr->endOfBaddie = true;
			}
			return;
		}

		if (!ptr->children.count(word[0])) {
			ptr->children[word[0]] = new TrieNode();
		}

		insert_internal(word.substr(1), hero, ptr->children[word[0]]);
	}
};

bool shortest_prefixes_no_hero(TrieNode* p, string prefix, vector<string>& blockers)
{
	if (p->heroCounter == 0) {
		blockers.push_back(prefix);
		return true;
	}

	if (p->endOfBaddie && p->heroCounter > 0) {
		// A baddie is prefix of one or more heroes, no solution
		return false;
	}

	for (auto [letter, node] : p->children) {
		if (node->baddieCounter > 0) {
			// There are baddies to block down this path
			auto result = shortest_prefixes_no_hero(node, prefix + letter, blockers);
			if (!result)
				return false;
		}
	}

	return true;
}

int main() {
	int N;
	cin >> N;

	Trie t;

	string line;
	// Skip trailing \n
	getline(cin, line);

	while(N--) {
		getline(cin, line);
		bool hero = line[0] == '+';
		string_view name = string_view{line}.substr(1);

		t.insert(name, hero);
	}

	vector<string> blockers;
	auto success = shortest_prefixes_no_hero(t.root, "", blockers);

	if (success) {
		cout << blockers.size() << "\n";
		sort(begin(blockers), end(blockers));
		for (auto& blocker : blockers) {
			cout << blocker << "\n";
		}
	} else {
		cout << "-1\n";
	}


}
