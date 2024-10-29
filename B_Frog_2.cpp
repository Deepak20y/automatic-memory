
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> 
#include <iostream>
using namespace __gnu_pbds;
using namespace std;


typedef tree<int, null_type, less<int>, rb_tree_tag,
            tree_order_statistics_node_update>
    ordered_set;


int main()
{

  ordered_set p;
  p.insert(3);

    cout << "The value at 3rd index ::"
        << *p.find_by_order(3) << endl;

    cout << "The index of number 6::" << p.order_of_key(6)
        << endl;

    
    cout << "The index of number seven ::"
        << p.order_of_key(7) << endl;

    return 0;
}
