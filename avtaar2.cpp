/*
findmaxpath()
Node{
      int max_sum;
}
at root => max( findmaxpath(root->left) ,findmaxpath(root->right),
 root->data + max_path_in_left_tree_connectedToRoot/right )
            1(7+2+1)
     3(7)                    -5(2)
-1(-1)  4(4)            -3(-3)    7(7)    max_sum=10


post order
*/
/*
garbage collector
new -> delete 

java
var user =new User<Node>

User{
      allCreatedObjects.add(this);
}

// do some ops on list
list=null

List<Object> allCreatedObjects;
allCreatedObjects.add(user);

list=null   
*/