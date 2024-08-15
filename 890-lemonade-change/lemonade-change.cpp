class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives = 0;
        int tens = 0;
        int twenty = 0;
        for (int i = 0; i < bills.size(); i++) {
            int paid = bills[i];
            int change = bills[i] - 5;

            if (paid == 5) {
                fives++;
            } else if (paid == 10) {
                tens++;
            } else {
                twenty++;
            }

            if (change != 0) {
                // cout<<"Inside"<<endl;
                // cout<<"Change is: "<<change<<endl;
                while (change - 20 >= 0 && twenty > 0) {
                    cout << "reducing 20" << endl;
                    change -= 20;
                    twenty--;
                }

                while (change - 10 >= 0 && tens > 0) {
                    // cout<<"reducing 10"<<endl;
                    change -= 10;
                    tens--;
                }

                while (change - 5 >= 0 && fives > 0) {
                    // cout<<"reducing 5"<<endl;
                    change -= 5;
                    fives--;
                }
            }

            if (change > 0) {
                return false;
            }

            // cout<<"I is: "<<i<<endl;
            // cout<<"fives is: "<<fives<<endl;
            // cout<<"tens is: "<<tens<<endl;
            // cout<<"twenty is: "<<twenty<<endl;
            // cout<<endl;
        }
        return true;
    }
};