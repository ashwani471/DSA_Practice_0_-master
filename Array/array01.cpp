#include<iostream>
#include <climits>
#include<vector>
#include<cstring>
#include<cmath>
using namespace std;

int sumofArray(int arr[] , int n){
   
    int sum = 0;
    for(int i=0;i<n;i++){
        sum = sum+arr[i];
    }
    return sum;

}

int linearSearch(int arr[],int n , int x){
    // int j=0;
    for(int i=0 ; i<n ;i++){
        if(arr[i]==x){
            return i;
        }
    }
    return -1;
    
}

void arrange(int arr[] , int n){
    int val =1;
    int s = 0;
    int e = n-1;
    while(s<=e){
        if(val%2!=0){
            arr[s]=val;
            s++;
            val++;
        }else{
            arr[e]=val;
            e--;
            val++;
        }
    }
}

void arrange_02(int arr[],int n){
    int val = 1;

    for(int i = 0;i<((n-1)/2);i++){
        if(val%2!=0){
            arr[i]=val;
            val++;
        }
    }
    val=1;
    for(int i=(((n-1)/2)+1);i<n;i++){
        if(val%2==0){
            arr[i]=val;
            val++;
        }
    }
}

void reverseArray(int arr[] , int n){
   for(int i=0,j=n-1 ; i<=j ; i++,j--){
    int temp = arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
   }
}

void swapAlternate(int arr[] , int n ){
    for(int i=0 ; i<n-1 ; i=i+2){
        int temp = arr[i];
        arr[i]=arr[i+1];
        arr[i+1]=temp;
    }
}

void intersection(int arr1[] , int arr2[] , int n , int m){
    for(int i=0 ; i<n ; i++){
        for(int j = 0 ; j<m ; j++){
            if(arr1[i] == arr2[j]){
                cout<<arr1[i]<<" ";
                arr2[j]=INT_MIN;
                break;
            }
        }
    }
}

int findUnique(int arr[],int n){
    int temp=0;
    for(int i=0 ; i<n ; i++){
        if(n==1){
            return arr[i];
        }
        for(int j = 0 ; j<n ; j++){
            if(i!=j){
            if(arr[i]==arr[j]){
                break;
            }
            if(j==n-1){
                temp=arr[i];
            }
        }
        }
        if(temp!=0){
            return temp;
        }
    }
    // return -1;

}
//only one digit repeated
int findDuplicate(int arr[] , int n){
    int actualSum=0;
    for(int i=0 ; i<n ; i++){
        actualSum+=arr[i];
    }
    int expectedSum = ((n-2)*(n-1))/2;
    return actualSum - expectedSum;
}

//multiple digit repeated
int findDuplicate_multiple(int arr[],int n){
    for(int i = 0; i<n ; i++){
        for(int j = i+1 ;j<n;j++){
            if(arr[i]==arr[j]){
                return arr[i];
            }
        }
    }
    return -1;
}

int pairSum(int arr[], int n , int x){
    int count = 0;
    for(int i = 0 ; i<n ; i++){
        for(int j = i+1 ; j<n ; j++){
            if(arr[i]+arr[j]==x){
                count++;
            }
        }
    }
    return count;
}



void pairSum_2(int arr[], int n , int x){
    for(int i = 0 ; i<n ; i++){
        for(int j = i+1 ; j<n ; j++){
            if(arr[i]+arr[j]==x){
                cout<<"("<<arr[i]<<","<<arr[j]<<")"<<endl;
            }
        }
    }
}

int tripletSum(int arr[] , int n , int x){
    int count=0;
    for(int i = 0 ; i<n ; i++){
        for(int j = i+1 ; j<n ; j++){
            for(int k=j+1 ; k<n ; k++){
                if(arr[i]+arr[j]+arr[k] == x){
                  cout<<"("<<arr[i]<<","<<arr[j]<<","<<arr[k]<<")"<<endl;
                     count++;
                }
            }
        }
    }
    return count;
}

void sortZeroesAndOnes(int arr[],int n){
    for(int i= 0,j=n-1;i<j;){
      if(arr[i]==1 && arr[j]==0){
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
      }else{
        if(arr[i]==0){
        i++;
      }
      if(arr[j]==1){
        j--;
      }
      }
    }
}

void nextGreaterElement(int arr[] , int n){
    for(int i = 0 ;i<n;i++){
        if(i==n-1){
            arr[i]=-1;
        }
        for(int j = i+1 ; j<n ; j++){
            if(arr[i]<arr[j]){
                arr[i]=arr[j];
                break;
            }else{
                if(j==n-1){
                    arr[i]=-1;
                }
            }
        }
    }
}

int getFirstPosition(int arr[] , int n){
     sortZeroesAndOnes(arr,n);
     for(int i = 0 ; i<n ;i++){
        if(arr[i]==1){
            return i+1;
        }
     }
     return -1;
}

void missingNumbers(int arr[] , int n){
  int max = INT_MIN;
  int min = INT_MAX;
  bool check=false;
  for(int i = 0 ; i<n ; i++){
    if(min > arr[i]){
        min = arr[i];
    }
    if(arr[i] > max){
       max = arr[i];
    }
  }    
  for(int j = min+1; j<max; j++){
    for(int k = 0 ; k<n ; ){
        if(arr[k] != j){
          k++;
        }else{
            check=true;
           break;
        }
    }
    if(check==false){
       cout<<j<<" ";
    }
    check=false;
  }
}

void findLocalMinimaAndMaxima(int arr[], int n){
    vector<int>minima;
    vector<int>maxima;
    vector<vector<int>> matrix;
    if(arr[0]>arr[1]){
        cout<<"mixima:"<<arr[0]<<endl;
        maxima.push_back(arr[0]);

    }else{
        if(arr[0]==arr[1]){
            matrix.push_back({-1});
        }
        cout<<"minima:"<<arr[0]<<endl;
        minima.push_back(arr[0]);
    }
    for(int i = 1 ; i<n-1;i++){
        if(arr[i]<arr[i-1]&&arr[i]<arr[i+1]){
            cout<<"minima:"<<arr[i]<<endl;
            minima.push_back(arr[i]);
        }
        if(arr[i]>arr[i-1]&&arr[i]>arr[i+1]){
            cout<<"maxima:"<<arr[i]<<endl;
            maxima.push_back(arr[i]);
        }
    }
    if(arr[n-1]>arr[n-2]){
        cout<<"maxima:"<<arr[n-1]<<endl;
        maxima.push_back(arr[n-1]);
    }else{
        if(arr[n-1]==arr[n-2]){
            matrix.push_back({-1});
        }
        cout<<"minima:"<<arr[n-1]<<endl;
        minima.push_back(arr[n-1]);
    }
    matrix.push_back(minima);
    matrix.push_back(maxima);
    
}

int binarySearch(int arr[] , int n , int val){
    int start=0;
    int end = n;

    for(;start<=end;){
      int mid = (start+end)/2;
      if(arr[mid] == val){
        return mid;
      }else{
        if(val>arr[mid]){
            start=mid+1;
        }else{
             end = mid-1;
        }
      }
}
  return -1;
}

void printArray(int b[], int size){
   for(int i= 0 ; i<size ; i++){
    cout<<b[i]<<" ";
   }
}

void selectionSort(int arr[] , int n){
    for(int i = 0;i<n;i++){
        int min = INT_MAX;
        for(int j = i;j<n;){
              if(arr[j]<min){
                min=arr[j];
                j++;
              }else{
                j++;
              }
        }
        for(int k = 0 ;k<n ;k++){
            if(arr[k]==min){
                int temp = arr[i];
                arr[i]=arr[k];
                arr[k]=temp;
                break;
            }
        }
    }

    // printArray(arr , n);
    
}

void bubbleSort(int arr[] , int n){
    for(int i = 0 ;i<n ;i++){
        for(int j = 0 ; j<n-i;j++){
            if(arr[j+1]<arr[j]){
                int temp = arr[j+1];
                arr[j+1]= arr[j];
                arr[j]=temp;
            }
        }
    }
}

void insertionSort(int arr[] , int n){
    for(int i = 1; i<n ; i++){
        int cur = arr[i];
        int j;
        for(j = i-1 ; j>=0 ; j--){
            if(cur<arr[j]){
                arr[j+1]=arr[j];
            }else{
                break;
            }
        }
        arr[j+1]=cur;
    }
}

void mergeSort(int arr[], int brr[] , int n , int m){
    int ans[100];
    int size = n+m;
    int k =0;
    int i , j=0;
    for(i =0 , j=0;i<n&&j<m;){
        if(arr[i]<=brr[j]){
          ans[k]=arr[i];
          i++;
          k++;            
        }else{
            ans[k]=brr[j];
            j++;
            k++;
        }
    }
    if(i<n){
      for(;i<n;i++){
        ans[k]=arr[i];
      }
    }
    if(j<m){
        for(;j<m;j++){
            ans[k]=brr[j];
        }
    }

    printArray(ans,size);

}

void pushZeroesEnd(int arr[] , int n){
    for(int i = 0,j=n-1 ; i<j;){
        if(arr[i]!=0){
            i++;
        }
        if(arr[j]==0){
            j--;
        }
       if(arr[i]==0 && arr[j]!=0){
        int temp = arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        i++;
        j--;
       }
    }
}

void rotate(int arr[] , int n , int d){
    int i=0;
    while(i<d){
        int temp = arr[0];
        for(int j = 1 ; j<n ; j++){
            arr[j-1]=arr[j];
        }
        arr[n-1]=temp;
        i++;
    }
}

int findSortArrayRotation(int arr[], int n){
    for(int i =0 ; i< n ; i++){
        if(arr[i+1]<arr[i]){
            return i+1;
        }
    }
}

void sumOfTwoArray(int arr1[] , int arr2[] , int n , int m ){
    int k=0;
    if(n>m){
        k=n;
    }else{
        k=m;
    }
    int sum=0;
    int carry=0;
    int output[100];
    int put;
    while(k>=0){
    for(int i=n-1 , j=m-1 ; i>0||j>0 ; i--, j--){
       sum = arr1[i]+arr2[j]+carry;
       if(sum>9){
        put=sum%10;
        carry=sum/10;
        output[k]=put;
        k--;
       }else{
        output[k]=put;
        carry=0;
        k--;
       }
    }
    
}
}

// ------------------------- strings ------------------------------

int length(char s[]){
    int cnt=0;
    for(int i = 0; s[i]!='\0' ; i++){
       cnt++;
    }
    return cnt;
}

bool checkPalindrome( char s[]){
    int len=length(s);
    for(int i = 0, j = len-1 ; i<=j ; i++ , j--){
        if(s[i] != s[j]){
            return false;
            break;
        }
    }
    return true;
}

void reverseString(char s[]){
    int len  = length(s);
    for(int i = 0 , j=len-1 ; i<=j ; i++ , j--){
        char temp = s[i];
        s[i]=s[j];
        s[j]=temp;
    }
}

void trimSpaces(char s[]){
    for(int i = 0 ; s[i]!='\0' ; i++){
        if(s[i] == ' '){
            for(int j = i ; s[j]!='\0' ;j++){
                s[j] = s[j+1];
            }
        }
    }
}

void reverseStringWordWise(char s[]){
    int len = length(s);
    reverseString(s);
    cout<<s<<endl;
    int p1=0;
    int i,j;
    for(i = 0 ; s[i] != '\0' ; ){
        if(s[i]==' '||s[i]=='\0'){
            // int k = 0 ; 
             j=i-1;
           for(;p1<=j;){
            char temp = s[p1];
            s[p1]=s[j];
            s[j]=temp;
            p1++;
            j--;
           }
           p1=i+1;
           if(s[i+1]==' '){
            for(;s[i]==' ';){
                i++;
            }
            p1=i;
           }
        }
        i++;
    }
    j=i-1;
    for(;p1<=j;){
        char temp = s[p1];
        s[p1]=s[j];
        s[j]=temp;
        p1++;
        j--;
    }
}

void printAllPrefixes(char s[]){
    for(int i = 0 ; s[i]!='\0' ; i++){
       for(int j = 0 ; j<=i ; j++){
        cout<<s[j];
       }
       cout<<endl;
    }
}

void printAllSubstring(char s[]){
    int k = 0;
    while(s[k] != '\0'){
        for(int i = k ; s[i]!='\0' ; i++){
            for(int j = k ; j<=i ; j++){
                cout<<s[j];
            }
       cout<<endl;
    }
    k++;
}
}

void print2dArrayRowWise(int a[][100] , int n , int m){
 for(int i = 0 ; i < m ;i++){
        for(int j = 0 ; j< n ;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

void print2dArrayColWise(int arr[][100] , int n , int m){
for(int j = 0 ; j<n ; j++){
    int sum = 0;
    for(int i = 0 ; i<m ;i++){
        sum = sum + arr[i][j];
    }
    cout<<sum << " ";
}
}

void findLargest(int arr[][100] , int m , int n){
    vector<int> row;
    vector<int> col;

    int sum = 0;
    for(int i = 0 ; i<m ; i++){
        for(int j = 0 ; j<n ; j++){
            sum +=arr[i][j];
        }
        row.push_back(sum);
        sum =0 ;
    }

    for(int j = 0 ; j<n ; j++){
        for(int i = 0 ;i<m ; i++){
            sum+=arr[i][j];
        }
        col.push_back(sum);
            sum = 0;
    }
    vector<int> maxRowData;
    int maxrow = row[0];
    int k;
    int maxrowindx;
    for(k = 1 ; k<row.size() ; ){
        if(maxrow < row[k]){
            maxrow = row[k];
            maxrowindx=k;
        }
        k++;
    }
    maxRowData.push_back(maxrowindx);
    maxRowData.push_back(maxrow);

    k=0;
    vector<int> maxcolData;
    int maxcol = col[0];
    int maxcolindx;
    for(k = 1 ; k<col.size() ; ){
        if(maxcol < col[k]){
            maxcol = col[k];
            maxcolindx=k;
        }
        k++;
    }
    maxcolData.push_back(maxcolindx);
    maxcolData.push_back(maxcol);

    if(maxRowData[1]<maxcolData[1]){
        cout<<maxcolData[0]<<" "<<maxcolData[1];
    }else{
        cout<<maxRowData[0]<<" "<<maxRowData[1];
    }

}

 void waveWise(int arr[][100] , int m , int n){
    for(int j = 0 ;j<n; j++){
        if(j%2 == 0){
            for(int i = 0 ; i<m ;i++){
                 cout<<arr[i][j]<<" ";
              }
        }else{
            for(int i = m-1 ; i>=0 ;i--){
                cout<<arr[i][j]<<" ";
            }
        }
       
    }
 }

void spiralPrint(int arr[][100] , int m  , int n){
    int cs =0,ce=n-1,rs = 0,re=m-1;
    int elements = m*n;
    while(elements>0){
    //------------right to left print ---------
    for(int i = cs ; i<=ce ; i++ ){
      cout<<arr[rs][i]<<" ";
      elements--;
    }
     
    //---------------top to bottom print ----------
    rs=rs+1;
    for(int j = rs ; j<=re ; j++){
        cout<<arr[j][ce]<<" ";
        elements--;
    }
    ce-=1;

    //------------------right to left print -----------
    for(int k = ce ; k>=cs ; k--){
        cout<<arr[re][k]<<" ";
        elements--;
    }
    re-=1;

    //---------------bottom to top print -----------
    for(int l = re ; l>=rs ; l--){
        cout<<arr[l][cs]<<" ";
        elements--;
    }
    cs+=1;
}
}

bool checkPermutation( char s1[] , char s2[]){
    int count[26]={};
    for(int i =0 ; s1[i]!='\0' ;i++){
        count[s1[i]]++;
    }
    for(int j = 0 ; s2[j]!='\0';j++){
        count[s2[j]]--;
    }
    for(int k = 0 ; k<26; k++){
        if(count[k]!=0){
            return false;
        }else{
            return true;
        }
    }

}

void removeConsecutiveDuplicate(char s[]){
    char lastchar = s[0];
    int j = 1;
    for(int i = 1 ; s[i]!='\0' ;){
        if(s[i]==lastchar){
            i++;
        }
        lastchar = s[i];
        s[j]=s[i];
        i++;
        j++;
    }
    s[j]='\0';
}

void reverseEachWord(char s[]){
    int len = strlen(s);
    // cout<<len;
     int i=0,j=0,k = 0;
     while(len>j){
     for(; j<len && s[j]!=' ';){
        j++;
     }
      k = j-1;
     for(;i<k;){
            int temp = s[k];
            s[k]=s[i];
            s[i]=temp;
            i++;
            k--;
        }
        j++;
        i=j;
}
}

//---------------recursion -------------

int factorial(int n){
    if(n==0){
        return 1;
    }
    int smalloutput = factorial(n-1);
    return n*smalloutput;
}

int power(int x , int n){
    if(n=0){
        return 1;
    }
    int smalloutput = power(x,n-1);
    return x*smalloutput;
}

int fibonacci(int n){
    if(n==0){
        return 0;
    }

    if(n==1){
        return 1;
    }

    int smalloutput = fibonacci(n-1) + fibonacci(n-2);

    return smalloutput;
}

bool is_sorted(int a[] , int size){
    if(size == 0 || size == 1){
        return true;
    }

    if(a[0]>a[1]){
        return false;
    }
    bool isSmallerSorted = is_sorted(a+1 , size-1);
    return isSmallerSorted;
}

int allIndexes(int *arr , int n , int x ,  int output[]){
    if(n == 0){
        return 0;
    }

    int count = allIndexes(arr,n-1 , x ,output);
    if(arr[n-1] == x){
        output[count]=n-1;
        return count+1;
    }
    return count;
}

int allIndexes_2(int *arr , int n ,int x ,int* output){
    if(n == 0){
        return 0;
    }
    int smallAns = allIndexes_2(arr+1 , n-1 , x , output);
    
    if(arr[0] == x){
        for(int i = smallAns-1 ; i>=0 ; i--){
            output[i+1] = output[i]+1;
        }
        output[0]=0;
        return smallAns+1;
    }else{
        for(int i  = 0; i<smallAns ; i++){
            output[i] = output[i]+1;
        }
        return smallAns;
    }
}

int multiplyNumbers(int m , int n){
    if(n == 1 ){
        return m;
    }
    int smallAns = multiplyNumbers(m,n-1);
    return smallAns+m;
}

int countZeros(int n){
    if(n==0){
        return 0;
    }

    int smallans = countZeros(n/10);
    if(n%10 == 0){
        return smallans+=1;
    }
    return smallans;
}

double geometricSum(int k){
    if(k==0){
        return 1;
        }
    double smallans = geometricSum(k-1);
    return smallans+1.0/pow(2,k);
}

bool helper(string &str , int st , int e){
    if(st == e){
        return true;
    }
    
    bool smallans = helper(str , st+1 , e-1);

    if(str[st] == str[e]){
       return true;
    }
}

bool ispalindrome(string& str){
    
    int len = str.length();
    bool check = helper(str , 0 ,len-1 );
    return check;
}

int subSequence(string input , string output[]){
    if(input.empty()){
        output[0]="";
        return 1;
    }
    string smallString = input.substr(1);
    int smallsub = subSequence(smallString , output);
    char firstChar = smallString[0];
    int len = smallString.size();
    for(int i = len,j=0 ; i<len*2 && j<len ;i++,j++){
         output[i]=firstChar+output[j];
    }
    return 2*smallsub;
}

string getString(int d){
    if(d==2){
        return "abc";
    }
    if(d==3){
        return "def";
    }
    if(d==4){
        return "ghi";
    }
    if(d==5){
        return "jkl";
    }
    if(d==6){
        return "mno";
    }
    if(d==7){
        return "pqrs";
    }
    if(d==8){
        return "tuv";
    }
    if(d==9){
        return "wxyz";
    }
    return "";
}

void keypad(int input , string output){
    if(input == 0){
        cout<<output<<endl;
        return;
    }
  int lastdigit = input%10;
  int smallnum = input/10;
  string str = getString(lastdigit);
  for(int i = 0 ; i<str.size() ; i++){
    keypad(smallnum , str[i]+output);
  }
} 

int main(){
    int n,x;
    cout<<"Enter value of n:"<<endl;
    cin>>n;
    cout<<"Enter value of x:"<<endl;
    cin>>x;
    // int output = factorial(n);
    int output = power(x,n);
    cout<<output<<endl; 

    
    // int a = 100;
    // int* p = &a;
    // int** q = &p;
    // // int c = ++(**q);
    // int b = ++(**q);
    // int *r=*q;
    // (*r)++;
    // cout<<a<<" "<<b<<" "<<endl;
    // char a=65;
    // cout<<a<<endl;
    // int a[10]={1, 2, 3,4 ,5 ,6 ,7 ,8};
    // int i = 10;
    // int* p = &i;
    // cout<<i<<" "<<p<<" "<<*p<<" "<<i+1<<" "<<p+1<<" "<<*p+1<<" "<<&p;
    // char str[] = "abcde";
    // char* pstr = "abcde";
    // cout<<sizeof(str)<<" "<<sizeof(pstr);
    // int i = 10;
    // int const j = 20;

    // cout<<i<<" "<<j;

    // i=12;
    // j=22;
    // cout<<i<<" "<<j;
    // cout<<a<<endl;
    // cout<<a+1<<endl;
    // cout<<a+2<<endl;
    // cout<<a+6;
    // cout<<a[0]<<endl;
    // cout<<a[1]<<endl;
    // cout<<*a<<endl;
    // cout<<*(a+1)<<endl;
    // cout<<*(1+a);
    

    //-------------------------------2D Array -------------------------
    // int n,m;
    // cout<<"Enter row value:";
    // cin>>m;
    // cout<<"Enter col value:";
    // cin>>n;
    // int arr[100][100];

    // for(int i = 0 ; i < m ;i++){
    //     for(int j = 0 ; j< n ;j++){
    //         cin>>arr[i][j];
    //     }
    // }

//---------------- print row wise------------------

// print2dArrayRowWise(arr , m , n);

// ----------------------- print col wise ----------------------

// print2dArrayColWise(arr , m , n);

// findLargest(arr , m , n);
//    waveWise(arr , m , n);
// spiralPrint(arr , m , n);

    
    // int size;
    // cout<<"Please enter your array size:";
    // cin>>size;
    // int arr[100];

    // for(int i=0; i<size;i++){
    //     cin>>arr[i];
    // }

    // for(int i  = 0 ; i<size ; i++){
    //     cout<<arr[i]<<" ";
    // }

    /*---------------Largest Element find ---------------------*/
   
    // int n;
    // cout<<"Enter the size of your Array:";
    // cin>>n;

    // int arr[100];

    // for(int i=0 ; i<n ; i++){
    //     cin>>arr[i];
    // }

    // int LN = INT_MIN;
    // int j=0;

    // for(int i=0;i<n ;i++){
    //     if(arr[i]>LN){
    //         LN=arr[i];
    //         j=i;
    //     }
    // }
    // cout<<LN<<" "<<j;

// ......sum of array elements.....
// int n ;
// cin>>n;
// int arr[5]; 
//   for ( int i  = 0; i < n; i++)
//   { cin>>arr[i];
//     /* code */
//   }
//   int sum = 0 ;
//   for (int i = 0; i < n; i++)
//   { sum = sum+arr[i];


//     /* code */
//   }
//   cout<<sum;

// int n;
// cout<<"Enter the size of the Array:";
// cin>>n;

// int arr[100];

// for(int i = 0 ; i<n ; i++){
//     cin>>arr[i];
// }

// int sum = sumofArray(arr , n);

// cout<<"Sum of the Array is"<<sum;

/*-----------Linear search-------------*/

// int x;
// cout<<"please enter the number that you want to search in the Array:";
// cin>>x;

// int n;
// cout<<"Please Enter the size of the Array:";
// cin>>n;
// int input[100];
// for(int i=0;i<n;i++){
//     cin>>input[i];
// }
// int d;
// cout<<"Enter rotate indexes:";
// cin>>d;

// char str[100];
// cout<<"Give me the string:";
// cin.getline(str , 100);

// removeConsecutiveDuplicate(str);
// reverseEachWord(str);
// cout<<str;

// char str2[100];
// cout<<"give me string2:";
// cin.getline(str2,100);
// bool ans = checkPermutation(str1,str2);
// if(ans){
//     cout<<"yes both strings are permutation of each other";
// }else{
//     cout<<"No strings are not permutation of each other";
// }
// reverseString(string);
// trimSpaces(string);
// reverseStringWordWise(string);
// printAllPrefixes(string);
// cout<<string;
// printAllSubstring(string);
// length(string);
// checkPalindrome(string);

// pushZeroesEnd(input , n);
// rotate(input , n , d);

// int m;
// cout<<"please enter the size of Array2:";
// cin>>m;
// int input2[100];
// for(int j=0;j<m;j++){
//     cin>>input2[j];
// }
// mergeSort(input,input2,n,m);

// selectionSort(input , n);
// bubbleSort(input , n);
// insertionSort(input , n);
// printArray(input , n); 
// int a = binarySearch(input , n , x);
// cout<<a;
// missingNumbers(input , n);
// int duplicate = findDuplicate_multiple(input , n);
// cout<<duplicate;
// findLocalMinimaAndMaxima(input,n);
// int x;
// cout<<"Please provide the number for pair:";
// cin>>x;

// int totalPairs = pairSum(input , n , x);
// cout<<totalPairs<<endl;
// pairSum_2(input , n , x);

// int totalCount =tripletSum(input , n , x);
// cout<<totalCount;
// sortZeroesAndOnes(input ,n);
// printArray(input , n);
// nextGreaterElement(input , n);
// printArray(input , n);
// int DuplicateValue = findDuplicate(input , n);
// cout<<"The duplicate in the Array is:"<<DuplicateValue;

// int m;
// cout<<"Please enter the size of the Array2:";
// cin>>m;
// int input2[100];
// for(int j = 0 ; j<m ; j++){
//     cin>>input2[j];
// }
// intersection(input1 , input2 , n , m);
// int Unique=findUnique(input , n);
// if(Unique>0){
//     cout<<"I find the Unique one in the Array:"<<Unique;
// }else{
//     cout<<"Invalid Array No unique Value";
// }
// reverseArray(input , n);
// printArray(input , n);
// int index=linearSearch(input,n,x);
// cout<<index;


return 0;

}