class Solution {
public:
    map<Node*,Node*> mp;
    void  dfs(Node* node){
        Node* copy = new Node(node->val);
        mp[node] = copy;
        for(auto neigh: node->neighbors){
            if(mp.find(neigh) == mp.end()){
                dfs(neigh);
            }
            copy->neighbors.push_back(mp[neigh]);
        }
    }
    Node* cloneGraph(Node* node) {
        if(!node) {
            return node;
        }
        dfs(node);
        return mp[node];
    }
};