#include <iostream>
#include <vector>

using namespace std;


vector<int> compareTriplets(vector<int> a, vector<int> b) {

   vector<int> c(2);

   for(int i = 0; i < a.size();i++){

     for(int j = 0;j < b.size();j++){

         if(a[i]>b[j]){

            vector<int> c[0]++;

        } else if(a[i]<b[j]) {

            vector<int> c[1]++;

        }

     }

  }
    return vector<int> c;
    std::cout << c << '\n';
}


int main(){

  int A[3]={5,4,10};

  int B[3]={1,7,10};

  compareTriplets(A, B);

  return 0;
}
