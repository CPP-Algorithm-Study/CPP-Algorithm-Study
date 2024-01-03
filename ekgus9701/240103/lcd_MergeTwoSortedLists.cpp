class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL){
            return l2;
        }

        if(l2 == NULL) {
            return l1;
        }

        ListNode *head = NULL;

        //작은 값 노드로 헤드 포인터 설정
        if(l1->val < l2->val){ //l2 1번째가 l1 1번째보다 크면
            head = l1; 
            l1 = l1->next;
        } 
        
        else { 
            head = l2;
            l2 = l2->next;
        }

        ListNode *p;
        p = head; //p는 병합한 리스트의 끝을 가리킴

        while(l1 && l2){
            if(l1->val < l2->val){ //작은애를 연결
                p->next = l1;
                l1 = l1->next;
            } 
            
            else {
                p->next = l2;
                l2 = l2->next;
            }

            p = p->next; //p를 끝으로 옮김
        }

        if(l1 != NULL){
            p->next = l1;
        } 
        else {
            p->next = l2;
        }

        return head;
    }
};
