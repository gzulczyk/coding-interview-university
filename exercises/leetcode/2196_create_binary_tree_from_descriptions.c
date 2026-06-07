/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* createBinaryTree(int** descriptions, int descriptionsSize, int* descriptionsColSize) {
    
    int childs[descriptionsSize]; 
    int isChild[100001] = {0};
    struct TreeNode* nodes[100001] = {NULL};

    for(int i = 0; i < descriptionsSize; i++) {
        childs[i] = descriptions[i][1];

        // Child node creation
        isChild[descriptions[i][1]] = 1;
        if (nodes[descriptions[i][1]] == NULL) {
            struct TreeNode* node = malloc(sizeof(struct TreeNode));
            node->val = descriptions[i][1];
            node->left = NULL;
            node->right = NULL;   
            nodes[descriptions[i][1]] = node;         
        }

        // Parent node creation
        if (nodes[descriptions[i][0]] == NULL) {
            struct TreeNode* node = malloc(sizeof(struct TreeNode));
            node->val = descriptions[i][0];
            node->left = NULL;
            node->right = NULL;   
            nodes[descriptions[i][0]] = node;         
        }
        if(descriptions[i][2] == 1){
            nodes[descriptions[i][0]]->left = nodes[descriptions[i][1]];
        } else {
            nodes[descriptions[i][0]]->right = nodes[descriptions[i][1]];
        }

    }
    for(int j=0; j < descriptionsSize; j++){
        if(isChild[descriptions[j][0]] == 0){
            return nodes[descriptions[j][0]];
        }
    }

    return NULL;
}