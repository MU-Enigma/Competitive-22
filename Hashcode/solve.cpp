#include <bits/stdc++.h>
using namespace std;

vector< pair< vector<string>, vector<string> > > customer_data;
//                 likes        dislikes

#define like_ingredients first
#define dislike_ingredients second

bool have_ingredient(set<string> ans, string ingredient){ // checks if we have the ingredient in the ans set
    return ans.find(ingredient)==ans.end();
}

int simulate(set<string> ans){
    int count = 0; // counts number of customer 
    for(auto customer: customer_data){
        bool check_all_likes = true; //  assuming if we have all liked ingredients on our pizza
        bool check_all_dislikes = true;// assuming if we do not have any disliked ingredients on our pizza

        for(auto ingredient: customer.like_ingredients){
            if(have_ingredient(ans, ingredient)){
                check_all_likes = false;
                break;
            }
        }
        for(auto ingredient: customer.dislike_ingredients){
            if(have_ingredient(ans, ingredient)==false){
                check_all_dislikes = false;
                break;
            }
        }
        /* required condition: 
            The customer need to have all liked ingredients on his pizza
            and none of the disliked ingredients.
        */
        if(check_all_likes && check_all_dislikes){ // checking for our required condition
            count++;
        }
    }
    return count;
}

int main(){
    int n;
    cin>>n;
    set<string> ans;

    for(int i=0; i<n; i++){
        int lno; cin>>lno; // no of likes by each customer
        vector<string> likes(lno);
        for(int j=0; j<lno; j++){
            cin>>likes[j];
            ans.insert(likes[j]);
        }
        int dno; cin>>dno; // no of dislikes by each customer
        vector<string> dislikes(dno);
        for( int j=0 ; j<dno ; j++){
            cin>>dislikes[j];
        }
        customer_data.push_back( {likes, dislikes} );
    }
    // cout<< simulate(ans)<<endl;
    cout<< ans.size()<<" ";
    for(auto i: ans){
        cout<< i<<" ";
    }
}