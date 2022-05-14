#include <bits/stdc++.h>

using namespace std;

int a[500001], n, mid, range;
int avg, sum=0;
vector<int> v;
int cnt[8001];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >>n;
    for(int i =0; i<n; i++){
        cin >>a[i];
        v.push_back(a[i]);
        sum+=a[i];
        cnt[a[i]+4000]++;
    }
    sort(v.begin(), v.end());
    avg = round(double(sum) / n);
    int max = 0;
    int flag;
	for (int i = 0; i < 8001; i++)
	{
		if (cnt[i] > max)
		{
			max = cnt[i];
			flag = i;
		}
	}

	for (int i = flag + 1; i < 8001; i++)
	{
		if (cnt[i] == max)
		{
			flag = i;
			break;
		}
	}
    mid = v[(n-1)/2];
    range=v[n-1]-v[0];
    cout << avg << "\n";
    cout << mid << "\n";
    cout << flag -4000 <<"\n";
    cout <<range;
    return 0;
}