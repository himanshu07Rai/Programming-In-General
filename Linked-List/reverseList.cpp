 class LLNode {
     public:
         int val;
         LLNode *next;
 };


LLNode* solve(LLNode* node) {
    if(!node || !node->next)
        return node;
    LLNode* p = node, *c = node->next, *n = node->next->next;
    p->next=NULL;
    while(n)
    {
        c->next = p;
        p = c;
        c = n;
        n = n->next;
    }
    c->next = p;
    return c;
}
