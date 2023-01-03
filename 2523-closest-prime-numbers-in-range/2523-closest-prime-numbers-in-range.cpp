class Solution {
public:
    void fillPrimes(vector<int>& prime, int high)
    {
        bool ck[high + 1];
        memset(ck, true, sizeof(ck));
        ck[1] = false;
        ck[0] = false;
        for (int i = 2; (i * i) <= high; i++) {
            if (ck[i] == true) {
                for (int j = i * i; j <= sqrt(high); j = j + i) {
                    ck[j] = false;
                }
            }
        }
        for (int i = 2; i * i <= high; i++) {
            if (ck[i] == true) {
                prime.push_back(i);
            }
        }
    }
    // in segmented sieve we check for prime from range [low, high]
    
    vector<int> v;
    
    void segmentedSieve(int low, int high)
    {
        if (low<2 and high>=2){
            low = 2;
        }//for handling corner case when low = 1 and we all know 1 is not prime no.
        bool prime[high - low + 1];
      //here prime[0] indicates whether low is prime or not similarly prime[1] indicates whether low+1 is prime or not
        memset(prime, true, sizeof(prime));

        vector<int> chprime;
        fillPrimes(chprime, high);
        //chprimes has primes in range [2,sqrt(n)]
         // we take primes from 2 to sqrt[n] because the multiples of all primes below high are marked by these
       // primes in range 2 to sqrt[n] for eg: for number 7 its multiples i.e 14 is marked by 2, 21 is marked by 3,
       // 28 is marked by 4, 35 is marked by 5, 42 is marked 6, so 49 will be first marked by 7 so all number before 49
      // are marked by primes in range [2,sqrt(49)]
        for (int i : chprime) {
            int lower = (low / i);
            //here lower means the first multiple of prime which is in range [low,high]
            //for eg: 3's first multiple in range [28,40] is 30         
            if (lower <= 1) {
                lower = i + i;
            }
            else if (low % i) {
                lower = (lower * i) + i;
            }
            else {
                lower = (lower * i);
            }
            for (int j = lower; j <= high; j = j + i) {
                prime[j - low] = false;
            }
        }

        for (int i = low; i <= high; i++) {
            if (prime[i - low] == true) {
                // cout << (i) << " ";
                v.push_back(i);
            }
        }
    }
    vector<int> closestPrimes(int left, int right) {
        segmentedSieve(left, right);
        if(v.size() < 2) return {-1, -1};
        int mn = INT_MAX;
        int l = -1, r = -1;
        for(int i = 1; i < v.size(); i++){
            if(v[i] - v[i - 1] < mn){
                mn = (v[i] - v[i - 1]);
                l = v[i - 1], r = v[i];
            }
        }
        
        return {l, r};
    }
};