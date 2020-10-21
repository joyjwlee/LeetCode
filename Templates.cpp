// BINARY SEARCH
int left = min(search_space), right = max(search_space);
while (left < right) {
    mid = left + (right - left) / 2;
    if (condition(mid))
        right = mid;
    else
        left = mid + 1;
}
return left;

// VECTOR OF DEFINED SIZE
vector<vector<int>> vec(n, vector<int>(m));

// CUSTOM SORT WITH CMP METHOD AS ADDITIONAL PARAMETER
static bool cmp(pair<int, int> &a, pair<int, int> &b) {
    return a.second < b.second;
}
vector<pair<int, int>> vec;
sort(vec.begin(), vec.end(), cmp);

// SORT VECTOR (for ascending, remove last parameter)
sort(v.begin(), v.end(), greater<int>());

// CUSTOM SORT VECTOR (sort by second element, ascending order)
sort(points.begin(), points.end(), [](vector<int> &a, vector<int> &b) {
    return a[1] < b[1];
});

// UNORDERED MAP
unordered_map<char, int> mp;

// ITERATE THROUGH MAP
for (auto i : mp)
    cout << i.first << " " << i.second << endl;

// DFS
// dr dc arrays
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

// check for boundary
bool shouldVisit(vector<vector<char>> &grid, int i, int j) {
    if (0 <= i && i < grid.size())
        if (0 <= j && j < grid[0].size())
            return true;
    return false;
}

void DFS(vector<vector<char>> &grid, int i, int j) {
    grid[i][j] = 0;
    for (int k = 0; k < 4; k++) {
        if (shouldVisit(grid, i + dr[k], j + dc[k]))
            DFS(grid, i + dr[k], j + dc[k]);
    }
}

// INSERT FOR SINGLY-LINKED LIST
// helper to insert
void insert_node(ListNode *&curr, int val) {
    // if null
    if (curr == NULL) {
        curr = new ListNode(val);
        return;
    }

    // otherwise iterate thru and add
    ListNode *temp = curr;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new ListNode(val);
    return;
}

// ITERATE BINARY TREE VIA STACK
stack<TreeNode *> s;
s.push(node);

// iterate
while (!s.empty()) {
    // get current, remove
    TreeNode *curr = s.top();
    s.pop();
    // if null
    if (curr == NULL)
        continue;
    // otherwise, get val and add to stack
    v.push_back(curr->val);
    s.push(curr->left);
    s.push(curr->right);
}

// STRING STREAM TO PARSE INPUT
stringstream s(str); // used to break word
string word;         // store individual word
while (s >> word)    // iterate through each word
    cout << word << endl;

// EUCLID'S FOR GCF
int getGCF(int a, int b) {
    if (a == 0)
        return b;
    return getGCF(b % a, a);
}

// TREE TRAVERSALS
// Inorder Traversal (Left-Root-Right)
void printInorder(struct Node *node) {
    // end case
    if (node == NULL)
        return;

    // recur right
    printInorder(node->left);

    // print curr
    cout << node->data << " ";

    // recur right
    printInorder(node->right);
}
// Preorder Traversal (Root-Left-Right)
void printPreorder(struct Node *node) {
    // end case
    if (node == NULL)
        return;

    // print curr
    cout << node->data << " ";

    // recur left
    printPreorder(node->left);

    // recur right
    printPreorder(node->right);
}
// Postorder Traversal (Left-Right-Root)
void printPostorder(struct Node *node) {
    // end case
    if (node == NULL)
        return;

    // recur left
    printPostorder(node->left);

    // recur right
    printPostorder(node->right);

    // print curr
    cout << node->data << " ";
}

// STRUCT FOR CUSTOM SORT (lexicographic:)
struct {
    bool operator()(string a, string b) const {
        int len = (a.size() < b.size()) ? a.size() : b.size();
        for (int i = 0; i < len; i++)
            if (a[i] > b[i])
                return true;
        return false;
    }
} lexico;

// BOOL METHOD FOR CUSTOM SORT
static bool custom(string &a, string &b) {
    return a >= b;
}
sort(s.begin(), s.end(), custom);

// SET
set<int> s;
return vector<int>(s.begin(), s.end()); // s as vector