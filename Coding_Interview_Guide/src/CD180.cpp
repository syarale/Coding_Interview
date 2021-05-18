
// CD180：通过先序和中序数组生成后序数组

#include <iostream>
#include <vector>
using namespace std;



vector<int> get_posorder(vector<int> preorder, vector<int> midorder) {
    vector<int> posorder;
    
    int len = preorder.size();

    if (len == 0) {
        return posorder;
    }
    
    int root = preorder[0];
    int i;
    for (i = 0; i < len; i++) {
        if (midorder[i] == root) {
            break;
        }
    } 

    // it shouldn't be happend
//    if (i == len) {
//        return posorder;
//    }
    
    vector<int>::iterator mid_it = midorder.begin();
    vector<int>::iterator pre_it = preorder.begin();
    vector<int> pre_lch(pre_it + 1, pre_it + 1 + i);
    vector<int> pre_rch(pre_it + 1 + i, preorder.end());
    vector<int> mid_lch(mid_it, mid_it + i);
    vector<int> mid_rch(mid_it + i + 1, midorder.end());
      
    vector<int> pos_lch = get_posorder(pre_lch, mid_lch);
    vector<int> pos_rch = get_posorder(pre_rch, mid_rch);
    
    
    posorder.insert(posorder.end(), pos_lch.begin(), pos_lch.end());
    posorder.insert(posorder.end(), pos_rch.begin(), pos_rch.end());
    posorder.push_back(root);
    
    return posorder;
}





int main()
{
    int n = 0;
    vector<int> pre_order;
    vector<int> mid_order;
    vector<int> pos_order; 
    
    cin>>n;
    for (int i = 0; i < n; i++) {
        int tmp = 0;
        cin>>tmp;
        pre_order.push_back(tmp);
    }

    for (int i = 0; i < n; i++) {
        int tmp = 0;
        cin>>tmp;
        mid_order.push_back(tmp);
    }
    
    pos_order = get_posorder(pre_order, mid_order);
    int len = pos_order.size();
    for (int i = 0; i < len; i++) {
        cout<<pos_order[i]<<" ";
    }

    return 0;    
} 
