#include <bits/stdc++.h>

using namespace std;

struct node {
    int index, lowlink, component;
    bool in_stack;

    vector<node*> neighbors;

    node ( ) : index(-1), in_stack(false) {}
};

vector<vector<node*> > components;
vector<node> nodes;

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

    vector<node*> component;
    if ( v->lowlink == v->index ) {
        while ( !st.empty() ) {
            node *w = st.top();
            st.pop();
            w->component = components.size();
            w->in_stack = false;

            component.push_back(w);
            if ( v->index == w->index )
                break;
        }
        components.push_back(component);
    }
}

void SCC ( ) {
    components.clear();
    stack<node*> st;
    int index = 0;

    for ( int i = 0; i < nodes.size(); i++ )
        if ( nodes[i].index == -1 )
            strong_connect(index, &nodes[i], st);
}

vector<int> visited;
int longest_from ( int n ) {
    if ( !visited[n] ) {
        visited[n] = components[n].size();

        int best = 0;
        for ( int i = 0; i < components[n].size(); i++ ) {
            node *current = components[n][i];

            for ( int j = 0; j < current->neighbors.size(); j++ ) {
                node *to = current->neighbors[j];
                if ( to->component != n )
                    best = max( best, longest_from( to->component ) );
            }
        }

        visited[n] += best;
    }

    return visited[n];
}

int main ( ) {
    int cases;

    cin >> cases;
    int n, m;

    while ( cases-- ) {
        cin >> n >> m;

        nodes = vector<node>(n);
        int x, y;
        for ( int i = 0; i < m; i++ ) {
            cin >> x >> y;
            --x; --y;
            nodes[x].neighbors.push_back(&nodes[y]);
        }

        SCC();
        visited = vector<int>( components.size() );

        int ans = 0;
        for ( int i = 0; i < components.size(); i++ )
            ans = max( ans, longest_from(i) );

        cout << ans << '\n';
    }
}
