#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

bool isPrime(int n)
{
    for (int i = 2; i <=sqrt(n); i++)
    {
        if (n%i == 0)
        {
            return false;
        }
    }
    return true;
}


int Reverse(int n)
{
    std::string temp;
    std::stringstream ss;
    ss << n;
    ss >> temp;
    reverse(temp.begin(), temp.end());
    int t = atoi(temp.c_str());
    return t;
}

int main()
{
    int M, N;
    cin >> M >> N;
    std::string c;
    std::vector<int> num;
    int i_rev = 0;

    for (int i = M; i <= N; i++)
    {
        i_rev = Reverse(i);
        if(num.end() != find(num.begin(),num.end(),i)){//这个数字已经找过了，不要再计算了
            continue;
        }   

        if(num.end() != find(num.begin(),num.end(),i_rev)){
            continue;
        }

        if (isPrime(i) && isPrime(i_rev))
        {
            num.push_back(i);
            if(i != i_rev && i_rev <= N){//避免重复
                num.push_back(i_rev); 
            }
        }
    }


    sort(num.begin(),num.end());
    for(int i=0;i<num.size();i++){
        cout << num[i] << " ";
    }

    return 0;
}
