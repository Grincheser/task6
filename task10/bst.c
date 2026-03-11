#include <stdlib.h>
#include "bst.h"

t_btree *bstree_create_node(int item)
{
    t_btree *new_node;
    
    new_node = (t_btree*)malloc(sizeof(t_btree));
    if (new_node)
    {
        new_node->item = item;
        new_node->left = NULL;
        new_node->right = NULL;
    }
    
    return new_node;
}

void bstree_insert(t_btree *root, int item, int (*cmpf)(int, int))
{
    int cmp_result;
    
    if (!root) return;
    
    cmp_result = cmpf(item, root->item);
    if (cmp_result < 0)
    {
        if (root->left)
        {
            bstree_insert(root->left, item, cmpf);
        }
        else
        {
            root->left = bstree_create_node(item);
        }
    }
    else if (cmp_result > 0)
    {
        if (root->right)
        {
            bstree_insert(root->right, item, cmpf);
        }
        else
        {
            root->right = bstree_create_node(item);
        }
    }
}

void bstree_apply_infix(t_btree *root, void (*applyf)(int))
{
    if (!root) return;
    
    bstree_apply_infix(root->left, applyf);
    applyf(root->item);
    bstree_apply_infix(root->right, applyf);
}

void bstree_apply_prefix(t_btree *root, void (*applyf)(int))
{
    if (!root) return;
    
    applyf(root->item);
    bstree_apply_prefix(root->left, applyf);
    bstree_apply_prefix(root->right, applyf);
}

void bstree_apply_postfix(t_btree *root, void (*applyf)(int))
{
    if (!root) return;
    
    bstree_apply_postfix(root->left, applyf);
    bstree_apply_postfix(root->right, applyf);
    applyf(root->item);
}