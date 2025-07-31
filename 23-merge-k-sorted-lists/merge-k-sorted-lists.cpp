/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        pair<int,ListNode*>;
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> minH;
        ListNode* dummynode = new ListNode(0);;
        ListNode* temp = dummynode;
        for(int i=0;i<lists.size();i++){
            if(lists[i]){
                minH.push({lists[i]->val,lists[i]});
            }
            
        }
        while(!minH.empty()){
            ListNode* smallest = minH.top().second;
            minH.pop();
            temp->next = smallest;
            temp = temp->next;
            if(smallest->next){
                minH.push({smallest->next->val,smallest->next});
            }
        }
        return dummynode->next;
    }
};