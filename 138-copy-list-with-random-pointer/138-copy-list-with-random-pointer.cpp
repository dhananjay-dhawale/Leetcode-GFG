/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) {
            return NULL;
        }
        map <Node*, int> mp, mp1;
        int i = 0, n = 0;
        Node *t = head;
        while(t) {
            mp[t] = i++;
            t = t->next;
            n += 1;
        }
        t = head;
        i = 0;
        vector <int> v(n, -1);
        while(t) {
            if(t->random) {
                v[i] = mp[t->random];
            }
            t = t->next;
            i += 1;
        }
        Node *p = new Node(head->val);
        Node *ans = p;
        t = head->next;
        i = 0;
        map <int, Node*> vec;
        vec[i++] = ans;
        while(t) {  
            p->next = new Node(t->val);
            t = t->next;
            p = p->next;
            vec[i++] = p;
        }
        p = ans;
        t = head;
        while(t) {
            if(t->random) {
                int idx = mp[t->random];
                p->random = vec[idx];
            }
            t = t->next;
            p = p->next;
        }
        return ans;
    }
};