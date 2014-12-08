#include <bits/stdc++.h>

using namespace std;

struct node {
	int index, lowlink;
	bool in_stack;

	vector<node*> neighbors;

	node ( ) : index(-1), in_stack(false) { }
};

vector<node> nodes;
int answer;

void strong_connect ( int &index, node *v, stack<node*> &st ) {
	v->index = index;
	v->lowlink = index;
	v->in_stack = true;

	st.push(v);
	++index;

	for ( int i = 0; i < v->neighbors.size(); i++ ) {
		node *w = v->neighbors[i];

		if ( w->index == -1 ) {
			strong_connect( index, w, st );
			v->lowlink = min( v->lowlink, w->lowlink );
		} else if ( w->in_stack ) {
			v->lowlink = min( v->lowlink, w->index );
		}
	}

	if ( v->index == v->lowlink ) {
		answer++;
		while ( !st.empty() ) {
			node *w = st.top();
			st.pop();
			w->in_stack = false;

			if ( v->index == w->index )
				break;
		}
	}
}

void SCC ( ) {
	int index = 0;
	stack<node*> st;
	answer = 0;

	for ( int i = 0; i < nodes.size(); i++ )
		if ( nodes[i].index == -1 )
			strong_connect( index, &nodes[i], st );
}

int main() {
	int P, T;

	while ( cin >> P >> T ) {
		if ( !P && !T )
			break;

		map<string, int> mp;
		int id = 0;
		string name;

		getline( cin, name );
		for ( int i = 0; i < P; i++ ) {
			getline( cin, name );
			mp[name] = id++;
		}

		nodes = vector<node>(P);
		string a, b;
		for ( int i = 0; i < T; i++ ) {
			getline( cin, a );
			getline( cin, b );
			nodes[ mp[a] ].neighbors.push_back( &nodes[ mp[b] ] );
		}

		SCC();

		cout << answer << '\n';
	}
}
