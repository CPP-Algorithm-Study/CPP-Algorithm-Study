class Solution {
public:
    unordered_map<Node*,Node*>mp;
    Node* cloneGraph(Node* node) {
        if (!node) return NULL;
        Node* head=new Node(node->val); //현재 노드를 복제
        mp[node]=head; //매핑에 추가
        for (auto i:node->neighbors){
            if (mp.count(i)) head->neighbors.push_back(mp[i]); // 이미 복제된 경우 매핑된 노드를 이웃에 넣음
            else
                head->neighbors.push_back(cloneGraph(i)); // 아직 복제되지 않은 경우 복제하고 이웃에 넣음
        }
        return head;
    }
};
