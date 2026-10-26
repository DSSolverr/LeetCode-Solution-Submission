/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // keep track of how many cams we placed globally
    int camera ;
    
    // returns 3 possible states for a node:
    // 0 -> im completely uncovered (need my parent to save me)
    // 1 -> i have a camera placed on me
    // 2 -> im already covered (one of my kids is watching me)
    int dfs(TreeNode* node){
        
        // base case: if it's a null node, just pretend it's covered.
        // we don't wanna put cams on literally nothing, and leaf nodes need to think their "kids" are fine.
        if( !node ) return 2 ;

        // check on the kids first (bottom-up approach)
        int l = dfs(node->left) ;
        int r = dfs(node->right) ;

        // scenario A: oh no, at least one kid is completely uncovered (0).
        // i literally HAVE to buy a camera right here to save them. no other choice.
        if( l == 0 || r == 0 ){
            camera++ ;
            return 1 ; // tell my parent i got a cam now
        }
        // scenario B: kids are fine, and at least one actually bought a cam (1).
        // sweet, that means im covered by their camera! i don't need to spend money.
        else if( l == 1 || r == 1 ) return 2 ;
        
        // scenario C: both kids are covered (2), but NEITHER has a camera on them.
        // so im left totally naked/vulnerable. ill just return 0 and pray my parent buys a cam for me lol.
        return 0 ;
    }
    
    int minCameraCover(TreeNode* root) {
        camera = 0 ;
        
        // run the dfs to cover the tree.
        // but wait... what if the root itself returns 0 (uncovered) at the very end?
        // it doesn't have a parent to bail it out! so we gotta forcefully buy one last cam just for the root.
        if( dfs(root) == 0 ) camera++ ;
        
        return camera ;
    }
};