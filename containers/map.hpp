#ifndef _MAP_
# define _MAP_
# include <memory>
# include <string>
# include <iostream>
# include <unistd.h>
# include "../utils/pair.hpp"
# include "map_iterator.hpp"
# include "../utils/reverse_iterator.hpp"
# include "../utils/lexicographical_compare.hpp"


namespace ft
{
template<   class Key,
            class T,
            class compare = std::less<Key>,
            class alloc = std::allocator<ft::pair<const Key, T> >
        >
class map
{
    public:
        typedef Key                                             key_type;
        typedef T                                               mapped_type;
        typedef ft::pair<const Key, T>		                    value_type;
        typedef std::size_t                                     size_type;
        typedef std::ptrdiff_t                                  difference_type;
        typedef compare                                         key_compare;
        typedef alloc                                           allocator_type;
        typedef typename allocator_type::reference              reference;
        typedef typename allocator_type::const_reference        const_reference;
        typedef typename allocator_type::pointer                pointer;
        typedef typename allocator_type::const_pointer          const_pointer;
        typedef ft::map_iterator<value_type*>                   iterator;
        typedef ft::map_iterator<const value_type*>             const_iterator;
        typedef ft::reverse_iterator<iterator>                  reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>            const_reverse_iterator;
        
        struct value_compare
        {
            key_compare key_comp;
            value_compare() {}
            bool operator()(const value_type &v1, const value_type &v2)
            {
                return (key_comp(v1.first, v2.first));
            }
        };
    private:
        typedef Node<value_type>                                node;
        typedef typename alloc::template rebind<node>::other    node_allocator;

    private:
        node*                   root;
        node*                   NIL;
        size_type               Size;
        allocator_type          allocator;
        node_allocator          nodeAlloc;
        key_compare             Key_compare;
    
    private:
        node *newNode(value_type const &value, node *parent)
        {
            node *newnode = nodeAlloc.allocate(1);
            
            allocator.construct(&newnode->value, value);
            newnode->color = RED;
            newnode->parent = parent;
            newnode->left = NIL;
            newnode->right = NIL;
            return (newnode);
        }

        node *newNIL()
        {
            node *newnode = nodeAlloc.allocate(1);

            newnode->color = BLACK;
            newnode->parent = NULL;
            newnode->left = NULL;
            newnode->right = NULL;
            return (newnode);      
        }

        void rightRotation(node *Node)
        {
            node *tmp = Node->left;

            // Inherite the Node
            Node->left = tmp->right;
            if (tmp->right != NIL)
                tmp->right->parent = Node; // Inherite the Node
            tmp->parent = Node->parent;
            if (Node->parent == NIL)
                root = tmp;
            else if (Node == Node->parent->right) // the Node at the right side
                Node->parent->right = tmp;
            else // the Node at the left side
                Node->parent->left = tmp;
            tmp->right = Node;
            Node->parent = tmp;
        }

        void leftRotation(node *Node)
        {
            node *tmp = Node->right;

            Node->right = tmp->left;
            if (tmp->left != NIL)
                tmp->left->parent = Node;
            tmp->parent = Node->parent;
            if (Node->parent == NIL)
                root = tmp;
            else if (Node == Node->parent->left)
                Node->parent->left = tmp;
            else
                Node->parent->right = tmp;
            tmp->left = Node;
            Node->parent = tmp;
        }

        void BalanceTreeInsert(node *curr)
        {
            while (curr != root && curr->parent->color == RED)
            {
                node *GrandNode = curr->parent->parent;
                if (GrandNode->right == curr->parent) // we are at the right side of the tree
                {
                    if (GrandNode->left && GrandNode->left->color == RED) // Swap colors
                    {
                        GrandNode->right->color = BLACK;
                        GrandNode->left->color = BLACK;
                        GrandNode->color = RED;

                        curr = GrandNode; // balance the grand node
                    }
                    else // do a left rotation
                    {
                        if (curr == curr->parent->left)
                        {
                            curr = curr->parent;
                            rightRotation(curr);
                        }
                        curr->parent->color = BLACK;
                        GrandNode->color = RED;
                        leftRotation(GrandNode);
                    }
                }
                else // we are at the left side of the tree
                {
                    if (GrandNode->right && GrandNode->right->color == RED) // Swap colors
                    {
                        GrandNode->left->color = BLACK;
                        GrandNode->right->color = BLACK;
                        GrandNode->color = RED;

                        curr = GrandNode; // balance the grand node
                    }
                    else // do a right rotation
                    {
                        if (curr == curr->parent->right)
                        {
                            curr = curr->parent;
                            leftRotation(curr);
                        }
                        curr->parent->color = BLACK;
                        GrandNode->color = RED;
                        rightRotation(GrandNode);
                    }
                }
            }
            root->color = BLACK;
        }

        void BalanceTreeErase(node *Node)
        {
            while(Node != root && Node->color == BLACK)
            {
                if (Node == Node->parent->left)
                {
                    node *sib = Node->parent->right;
                    if (sib->color == RED)
                    {
                        sib->color = BLACK;
                        Node->parent->color = RED;
                        leftRotation(Node->parent);
                        sib = Node->parent->right;
                    }

                    if (sib->left->color == BLACK && sib->right->color == BLACK)
                    {

                        sib->color = RED;
                        Node = Node->parent;
                    }
                    else
                    {
                        if (sib->right->color == BLACK)
                        {
                            sib->left->color = BLACK;
                            sib->color = RED;
                            rightRotation(sib);
                            sib = Node->parent->right;
                        }
                        sib->color = Node->parent->color;
                        Node->parent->color = BLACK;
                        sib->right->color = BLACK;
                        leftRotation(Node->parent);
                        Node = root;
                    }
                }
                else
                {
                    node *sib = Node->parent->left;
                    if (sib->color == RED)
                    {
                        sib->color = BLACK;
                        Node->parent->color = RED;
                        rightRotation(Node->parent);
                        sib = Node->parent->left;
                    }
                    if (sib->left->color == BLACK && sib->right->color == BLACK)
                    {
                        sib->color = RED;
                        Node = Node->parent;
                    }
                    else
                    {
                        if (sib->left->color == BLACK)
                        {
                            sib->right->color = BLACK;
                            sib->color = RED;
                            leftRotation(sib);
                            sib = Node->parent->left;
                        }
                        sib->color = Node->parent->color;
                        Node->parent->color = BLACK;
                        sib->left->color = BLACK;
                        rightRotation(Node->parent);
                        Node = root;
                    }                    
                }
            }
            Node->color = BLACK;
        }

        void rbTransplant(node *a, node *b)
        {
            if (a->parent == NIL)
                root = b;
            else if (a == a->parent->left)
                a->parent->left = b;
            else
                a->parent->right = b;
            b->parent = a->parent;
        }

        node *get_min(node *node) const
        {
            if (!node || node == NIL)
                return (NIL);
            while (node->left != NIL)
                node = node->left;
            return (node);
        }
        
        node *get_max(node *node) const
        {
            if (!node || node == NIL)
                return (NIL);
            while (node->right != NIL)
                node = node->right;
            return (node);
        }

        node *get_node(value_type &value)
        {
            node *tmp = root;
            while (tmp != NIL)
            {
                if (Key_compare(value.first, tmp->value.first))
                    tmp = tmp->left;
                else if (Key_compare(tmp->value.first, value.first))
                    tmp = tmp->right;
                else
                    return (tmp);
            }
            return (0);
        }

        void delete_tree(node *Node)
        {
            if (!Node || Node == NIL)
                return ;
            delete_tree(Node->left);
            delete_tree(Node->right);
            allocator.destroy(&Node->value);
            nodeAlloc.deallocate(Node, 1);
        }

        void delete_node(node *Node)
        {
            allocator.destroy(&Node->value);
            nodeAlloc.deallocate(Node, 1);
        }

        void erase_from_tree(node *Node)
        {

            node*   FixUp;
            int     color;

            color = Node->color;
            if (Node->left == NIL)
            {
                FixUp = Node->right;
                rbTransplant(Node, Node->right);
            }
            else if (Node->right == NIL)
            {
                FixUp = Node->left;
                rbTransplant(Node, Node->left);
            }
            else
            {
                node *suc = get_min(Node->right);
                color = suc->color;
                FixUp = suc->right;
                if (suc->parent == Node)
                    suc->right->parent = suc;
                else
                {
                    rbTransplant(suc, suc->right);
                    suc->right = Node->right;
                    suc->right->parent = suc;
                }
                rbTransplant(Node, suc);
                suc->left = Node->left;
                suc->left->parent = suc;
                suc->color = Node->color;
            }
            
            if (color == BLACK)
                BalanceTreeErase(FixUp);
            Size--;
            delete_node(Node);
            if (!Size)
                root = NULL;
        }

    public:
        ////////////////////////////////////////////////////////////////////
        //                        Member functions                        //
        ////////////////////////////////////////////////////////////////////

        map():root(NULL), NIL(newNIL()), Size(0)
        {
        }

        map(const compare &comp, const allocator_type &allocator = allocator_type()):       root(NULL),
                                                                                            NIL(newNIL()),
                                                                                            Size(0),
                                                                                            allocator(allocator),
                                                                                            Key_compare(comp)
        {
        }
        
        template<class InputIt>
        map( InputIt first, InputIt last,
            const compare &comp = compare(),
            const allocator_type &allocator = allocator_type()):    root(NULL),
                                                                    NIL(newNIL()),
                                                                    Size(0),
                                                                    allocator(allocator),
                                                                    Key_compare(comp)
        {
            insert(first, last);
        }

        map(const map &other):  root(NULL),
                                NIL(newNIL()),
                                Size(0),
                                allocator(other.allocator),
                                Key_compare(other.Key_compare)
        {
            const_iterator it = other.begin();
            for(; it != other.end();it++)
                insert(*it);
        }

        map& operator=(const map &other)
        {
            clear();
            if (!other.size())
                return (*this);
            const_iterator it = other.begin();
            for(; it != other.end(); it++)
                insert(*it);
            return (*this);
        }
        
        ~map()
        {
            delete_tree(root);
            nodeAlloc.deallocate(NIL, 1);
        }

        allocator_type get_allocator() const
        {
            return (allocator);
        }
        ////////////////////////////////////////////////////////////////////
        //                          Element access                        //
        ////////////////////////////////////////////////////////////////////
        /**/
        T& at(const Key& key)
        {
            iterator it = find(key);
            if (it == end())
                throw std::out_of_range("map");
            return (it->second);
        }

        const T& at(const Key& key) const
        {
            const_iterator it = find(key);
            if (it == end())
                throw std::out_of_range("map");
            return (it->second);
        }

        T& operator[](const Key &key)
        {
            iterator it = find(key);
            if (it == end())
                return (insert(ft::make_pair(key, T())).first->second);        
            return (it->second);
        }
        ////////////////////////////////////////////////////////////////////
        //                            Iterators                           //
        ////////////////////////////////////////////////////////////////////
        /**/
        iterator begin()
        {
            return (iterator(get_min(root), NIL, get_max(root)));
        }

        iterator end()
        {
            return (iterator(NIL, NIL, get_max(root)));
        }

        const_iterator begin() const
        {
            return (const_iterator(get_min(root), NIL, get_max(root)));
        }

        const_iterator end() const
        {
            return (const_iterator(NIL, NIL, get_max(root)));
        }


        reverse_iterator rbegin()
        {
            return (reverse_iterator(end()));
        }

        reverse_iterator rend()
        {
            return (reverse_iterator(begin()));
        }

        const_reverse_iterator rbegin() const
        {
            return (const_reverse_iterator(end()));
        }

        const_reverse_iterator rend() const
        {
            return (const_reverse_iterator(begin()));
        }
        ////////////////////////////////////////////////////////////////////
        //                            Capacity                            //
        ////////////////////////////////////////////////////////////////////
        size_type size() const
        {
            return (Size);
        }

        bool empty() const
        {
            if (!Size)
                return true;
            return false;
        }

        size_type max_size() const
        {
            return (allocator.max_size());
        }
        ////////////////////////////////////////////////////////////////////
        //                            Modifiers                           //
        ////////////////////////////////////////////////////////////////////
        void clear()
        {
            delete_tree(root);
            root = NULL;
            Size = 0;
        }
        
        ft::pair<iterator, bool> insert( const value_type &value)
        {
            node *tmp = root;
            
            if (!root && !Size++)
            {
                root = newNode(value, NIL);
                root->color = BLACK;
                return (ft::make_pair(iterator(root, NIL, root), true));
            }
            else
            {
                node *parent = NULL;
                while (tmp != NIL)
                {
                    parent = tmp;
                    if (Key_compare(value.first, tmp->value.first))
                        tmp = tmp->left;
                    else if (Key_compare(tmp->value.first, value.first))
                        tmp = tmp->right;
                    else
                        return (ft::make_pair(iterator(tmp, NIL, get_max(root)), false));
                }
                tmp = newNode(value, parent);
                if (Key_compare(value.first, parent->value.first))
                {   
                    parent->left = tmp;
                    if (parent->color == RED)
                        BalanceTreeInsert(parent->left);
                }
                else
                {
                    parent->right = tmp;
                    if (parent->color == RED)
                        BalanceTreeInsert(parent->right);
                }

            }
            Size++;
            return ft::pair<iterator, bool>(iterator(tmp, NIL, get_max(root)), true);
            /* balance the tree */

        }

        template <class it>
        void insert(it first, it last)
        {
            while (first != last)
                insert(*first++);
        }

        iterator insert( iterator pos, const value_type& value )
        {
            (void)pos;
            return (insert(value).first);
        }

        void erase(iterator position)
        {
            erase_from_tree(get_node(*position));
        }
        
        void erase( iterator first, iterator last )
        {
            for(;first != last;)
            {
                iterator it = first++;
                erase(it);
            }
        }


        size_type erase(const Key &key)
        {
            iterator it = find(key);

            if (it == end())
                return (0);
            erase(it);
            return (1);
        }

        void swap(map &m1)
        {
            map tmp(*this);
            *this = m1;
            m1 = tmp;
        }
        ////////////////////////////////////////////////////////////////////
        //                            Look Up                             //
        ////////////////////////////////////////////////////////////////////

        size_type count( const Key& key ) const
        {
            const_iterator it = begin();

            for (;it != end();it++)
                if (it->first == key)
                    return (1);
            return (0);
        }

        iterator find(const Key &key)
        {
            node *tmp = root;

            while (tmp && tmp != NIL)
            {
                if (Key_compare(key, tmp->value.first))
                    tmp = tmp->left;
                else if (Key_compare(tmp->value.first, key))
                    tmp = tmp->right;
                else
                    return (iterator(tmp, NIL, get_max(root)));
            }
            return (end());
        }

        const_iterator find(const Key &key) const
        {
            node *tmp = root;

            while (tmp && tmp != NIL)
            {
                if (Key_compare(key, tmp->value.first))
                    tmp = tmp->left;
                else if (Key_compare(tmp->value.first, key))
                    tmp = tmp->right;
                else
                    return (const_iterator(tmp, NIL, get_max(root)));
            }
            return (const_iterator(NIL, NIL, get_max(root)));
        }

        iterator upper_bound(const Key &key)
        {
            iterator it = begin();
            while (it != end())
            {
                if (it->first > key)
                    return (it);
                else
                    it++;
            }
            return (it);
        }

        const_iterator upper_bound(const Key &key) const
        {
            const_iterator it = begin();
            while (it != end())
            {
                if (it->first > key)
                    return (it);
                else
                    it++;
            }
            return (it);
        }

        iterator lower_bound(const Key &key)
        {
            iterator it = begin();
            while (it != end())
            {
                if (it->first >= key)
                    return (it);
                else
                    it++;
            }
            return (it);
        }

        const_iterator lower_bound(const Key &key) const
        {
            const_iterator it = begin();
            while (it != end())
            {
                if (it->first >= key)
                    return (it);
                else
                    it++;
            }
            return (it);
        }

        ft::pair<iterator, iterator> equal_range(const Key &key)
        {
            return (ft::make_pair(lower_bound(key), upper_bound(key)));
        }

        ft::pair<const_iterator, const_iterator> equal_range(const Key &key) const
        {
            return (ft::make_pair(lower_bound(key), upper_bound(key)));
        }

        ////////////////////////////////////////////////////////////////////
        //                            Observers                           //
        ////////////////////////////////////////////////////////////////////
        key_compare key_comp() const
        {
            return (Key_compare);
        }

        value_compare value_comp() const
        {
            return (value_compare());
        }

};
        ////////////////////////////////////////////////////////////////////
        //                        Non-member functions                    //
        ////////////////////////////////////////////////////////////////////
    template<   class Key,
            class T,
            class compare,
            class alloc
            >
    bool    operator==(const map<Key, T, compare, alloc> &m1, const map<Key, T, compare, alloc> &m2)
    {
        if (m1.size() != m2.size())
            return (false);
        typename map<Key, T, compare, alloc>::const_iterator it1 = m1.begin(), it2 = m2.begin();
    
        for(; it1 != m1.end() ; it1++, it2++)
            if (it1->first != it2->first)
                return (false);
        return (true);
    }

    template<   class Key,
            class T,
            class compare,
            class alloc
            >
    bool    operator!=(const map<Key, T, compare, alloc> &m1, const map<Key, T, compare, alloc> &m2)
    {
        return (!operator==(m1, m2));
    }

    template<   class Key,
            class T,
            class compare,
            class alloc
            >
    bool    operator<(const map<Key, T, compare, alloc> &m1, const map<Key, T, compare, alloc> &m2)
    {
        return (ft::lexicographical_compare(m1.begin(), m1.end(), m2.begin(), m2.end()));
    }

    template<   class Key,
            class T,
            class compare,
            class alloc
            >
    bool    operator>(const map<Key, T, compare, alloc> &m1, const map<Key, T, compare, alloc> &m2)
    {
        return (m2 < m1);
    }

    template<   class Key,
            class T,
            class compare,
            class alloc
            >
    bool    operator<=(const map<Key, T, compare, alloc> &m1, const map<Key, T, compare, alloc> &m2)
    {
        return (!(m1 > m2));
    }

    template<   class Key,
            class T,
            class compare,
            class alloc
            >
    bool    operator>=(const map<Key, T, compare, alloc> &m1, const map<Key, T, compare, alloc> &m2)
    {
        return (!(m1 < m2));
    }
    
    template<   class Key,
            class T,
            class compare,
            class alloc
            >
    void swap(map<Key, T, compare, alloc> &m1, map<Key, T, compare, alloc> &m2)
    {
        map<Key, T, compare, alloc> tmp(m1);

        m1 = m2;
        m2 = tmp;
    }     
}

#endif