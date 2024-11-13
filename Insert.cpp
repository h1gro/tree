#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "Tree.h"

node_t* CreateSubtree(struct node_t* parent, int elem)
{
    node_t* subtree = (node_t*) calloc(1, sizeof(node_t));

    assert(subtree);

    subtree->elem  = elem;
    subtree->left  = NULL;
    subtree->right = NULL;

    if (parent != NULL)
    {
        Insert(parent, subtree);
    }

    return subtree;
}

int Insert(struct node_t* parent, struct node_t* subtree)
{
    assert(parent);
    assert(subtree);

    if (subtree->elem > parent->elem)
    {
        if (parent->right == NULL)
        {
            parent->right = subtree;
            return 0;
        }
        else
        {
            parent = parent->right;
            Insert(parent, subtree);
        }
    }

    else if (subtree->elem < parent->elem)
    {
        if (parent->left == NULL)
        {
            parent->left = subtree;
            return 0;
        }
        else
        {
            parent = parent->left;
            Insert(parent, subtree);
        }
    }

    else if (subtree->elem == parent->elem)
    {
        printf("This element was in the tree yet\n");
    }

    return 0;
}
