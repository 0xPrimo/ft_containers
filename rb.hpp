#ifndef RB
# define RB

# include <stdlib.h>

# define RED 0
# define BLACK 1

# define LEFT 0
# define RIGHT 1
# define ROOT 2
struct node
{
    int data;
    int color;
    int side;

    node(int data): 
                data(data),
                parent(NULL),
                left_child(NULL),
                right_child(NULL)
    {}

    node*   parent;
    node*   left_child;
    node*   right_child;
};


class rb
{
    private:
        node*   root;
        size_t  size;
    
    private:
        node& make_node()
        {

        }

    public:
        rb(): root(NULL), size(0)
        {
            root->side = ROOT;
            root->color = BLACK;
        }

        void    insert(int element)
        {
            node *tmp = root;
            /* insert node */
            if (element > root->data)
            {
                while (tmp->right_child)
                    tmp = tmp->right_child;
                tmp->right_child = new node(element);
                tmp->right_child->color = RED;
                tmp->right_child->side = RIGHT;
                tmp->right_child->parent = tmp;
            }
            else if (element < root->data)
            {
                while (tmp->left_child)
                    tmp = tmp->left_child;
                tmp->left_child = new node(element);
                tmp->left_child->color = RED;
                tmp->left_child->side = LEFT;
                tmp->left_child->parent = tmp;
            }

            /* check if the tree is balance */
            // check if the parent is black
            if (tmp->parent->color != BLACK)
            {
                while (tmp != root)
                {
                    if (tmp->side == RIGHT)
                    {
                        node *tmp1 = tmp;
                        for(int i = 0; i < 2 && tmp1 != root; i++)
                            tmp1 = tmp1->parent;
                        if (tmp1->left_child->color == RED)
                        {
                            tmp1->left_child->color = BLACK;
                            tmp1->right_child->color = BLACK;
                        }
                        else
                        {
                            // Right rotation
                        }

                    }
                    else
                    {

                    }
                }
                if (root->color == RED)
                    root->color = BLACK;
            }
            
        }

};
#endif