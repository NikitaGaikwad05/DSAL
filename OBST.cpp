
#include <iostream>
using namespace std;

#define SIZE 10

class OBST {
    int p[SIZE];  
    int a[SIZE];  
    int w[SIZE][SIZE];
    int c[SIZE][SIZE];  
    int r[SIZE][SIZE];  
    int n; 

public:
    
    void get_data() {
        int i;
        cout << "\nOptimal Binary Search Tree\n";
        cout << "\nEnter the number of nodes: ";
        cin >> n;

        cout << "\nEnter the data (keys):\n";
        for (i = 1; i <= n; i++) {
            cout << "a[" << i << "]: ";
            cin >> a[i];
        }

        cout << "\nEnter the success probabilities (p[i]):\n";
        for (i = 1; i <= n; i++) {
            cout << "p[" << i << "]: ";
            cin >> p[i];
        }
    }

    int Min_Value(int i, int j) {
        int m, k;
        int minimum = 32000; 
        for (m = r[i][j - 1]; m <= r[i + 1][j]; m++) {
            if ((c[i][m - 1] + c[m][j]) < minimum) {
                minimum = c[i][m - 1] + c[m][j];
                k = m;
            }
        }
        return k;
    }

    void build_OBST() {
        int i, j, k, m;
        for (i = 0; i <= n; i++) {
            w[i][i] = 0;  
            c[i][i] = 0;  
            r[i][i] = 0;  // No root for a tree with no nodes
        }

        for (i = 0; i < n; i++) {
            w[i][i + 1] = p[i + 1]; 
            c[i][i + 1] = p[i + 1]; 
            r[i][i + 1] = i + 1;  
        }
        for (m = 2; m <= n; m++) { 
            for (i = 0; i <= n - m; i++) {  
                j = i + m;  

                w[i][j] = w[i][j - 1] + p[j];

                k = Min_Value(i, j);
                c[i][j] = w[i][j] + c[i][k - 1] + c[k][j];  
                r[i][j] = k;  
            }
        }
    }

    void build_tree(int i, int j) {
        if (i > j) {
            return;  
        }

        int root = r[i][j];
        if (root == 0) return; 
        cout << "\n\t" << a[root];
        if (root - 1 >= i && r[i][root - 1] != 0) {
            cout << "\t\t" << a[r[i][root - 1]];
        } else {
            cout << "\t\t-"; // changed to '-' to represent null
        }
        if (root + 1 <= j && r[root][j] != 0) {
            cout << "\t" << a[r[root][j]];
        } else {
            cout << "\t-"; // changed to '-' to represent null
        }
        build_tree(i, root - 1);  // Left subtree
        build_tree(root, j);  // Right subtree
    }

    void display_tree() {
        cout << "\nThe Optimal Binary Search Tree for the Given Node is:\n";
        cout << "The Root of this OBST is: " << a[r[0][n]] << endl;
        cout << "The Cost of this OBST is: " << c[0][n] << endl;

        cout << "\n\n\t NODE \t LEFT CHILD \t RIGHT CHILD\n";
        build_tree(0, n);  // Start recursion from the root of the whole tree
    }
};

int main() {
    OBST obj;
    obj.get_data();  
    obj.build_OBST();  
    obj.display_tree();  
    return 0;
}



