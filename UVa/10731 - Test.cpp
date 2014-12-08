#include <bits/stdc++.h>

using namespace std;

struct node {
	int index, lowlink;
	bool in_stack;
	char id;

	vector<node*> neighbors;

	node ( ) : index(-1), in_stack(false), id('@') { }
};

vector<node> nodes;
vector<vector<char> > components;

void strong_connect ( int &index, node *v, stack<node*> &st ) {
	v->index = index;
	v->lowlink = index;
	v->in_stack = true;

	index++;
	st.push(v);

	for ( int i = 0; i < v->neighbors.size(); i++ ) {
		node *w = v->neighbors[i];

		if ( w->index == -1 ) {
			strong_connect( index, w, st );
			v->lowlink = min( v->lowlink, w->lowlink );
		} else if ( w->in_stack ) {
			v->lowlink = min( v->lowlink, w->index );
		}
	}

	vector<char> component;
	if ( v->lowlink == v->index ) {
		while ( !st.empty() ) {
			node *w = st.top();
			st.pop();

			w->in_stack = false;
			component.push_back( w->id );

			if ( v->index == w->index )
				break;
		}
		sort( component.begin(), component.end() );
		components.push_back( component );
	}
}

void SCC ( ) {
	int index;
	stack<node*> st;

	components.clear();
	for ( int i = 0; i < 26; i++ )
		if ( nodes[i].id != '@' && nodes[i].index == -1 )
			strong_connect( index, &nodes[i], st );
}

int main ( ) {
	int n;
	bool flag = false;

	while ( cin >> n && n ) {
		if ( flag ) cout << '\n';
		else		flag = true;

		nodes = vector<node>(26);

		char letters[5], ans;
		for ( int c = 0; c < n; c++ ) {
			for ( int i = 0; i < 5; i++ )
				cin >> letters[i];
			cin >> ans;

			for ( int i = 0; i < 5; i++ ) {
				nodes[ans - 65].id = ans;
				if ( letters[i] != ans ) {
					nodes[ans - 65].neighbors.push_back( &nodes[letters[i] - 65] );
					nodes[letters[i] - 65].id = letters[i];
				}
			}
		}

		SCC();

		sort( components.begin(), components.end() );
		for ( int i = 0; i < components.size(); i++ ) {
			for ( int j = 0; j < components[i].size(); j++ ) {
				if ( j > 0 ) cout << ' ';
				cout << components[i][j];
			}
			cout << '\n';
		}
	}
}
