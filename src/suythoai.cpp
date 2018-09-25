#include <iostream>
using namespace std;
int main()
{
    int t,l1[21],l2[21],l3[21],mid[21];
    cin>>t;
    for (int i=0;i<t;i++)
    {
        cin>>l1[i]>>l2[i]>>l3[i];
        if ((l1[i]<l2[i] && l1[i]>l3[i]) || (l1[i]>l2[i] && l1[i]<l3[i]))
            mid[i] = l1[i];
        else if ((l2[i]<l1[i] && l2[i]>l3[i]) || (l2[i]>l1[i] && l2[i]<l3[i]))
            mid[i] = l2[i];
        else if ((l3[i]<l2[i] && l3[i]>l1[i]) || (l3[i]>l2[i] && l3[i]<l1[i]))
            mid[i] = l3[i];
        else if (l1[i]==l2[i] && l2[i]==l3[i])
        	mid[i] = l1[i];
    }
    for (int i=0; i<t;i++)
    {
    	cout<<l1[i]<<" "<<l2[i]<<" "<<l3[i]<<" ";
        cout<<"Case "<<i+1<<": "<<mid[i]<<endl;
	}
	return 0;
}
