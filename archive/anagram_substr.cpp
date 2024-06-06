#include <bits/stdc++.h>

using namespace std;

// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s) {
    map<string, int> count;
    for(int i = 1; i<=s.size(); i++){
        for(int j = 0; j<=s.size()-i;j++){
            string temp = s.substr(j, i);
             cout<<temp<<endl;
            sort(temp.begin(), temp.end());

            count[temp]++;
        }
    }
    int total=0;
    for(auto itr = count.begin();itr!= count.end();itr++){
        if(itr->second > 1){
            total += itr->second * (itr->second -1)/2;
        }
    }

    return total;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
