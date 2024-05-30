class Solution {
public:
    string getRoman(int number){
        if(number == 4){
            return "IV";
        }
        if(number == 9){
            return "IX";
        }
        if(number == 40){
            return "XL";
        }
        if(number == 90){
            return "XC";
        }
        if(number == 400){
            return "CD";
        }
        if(number == 900){
            return "CM";
        }
        string ans = "";
        while(number >= 1000){
            ans+= 'M';
            number-=1000;
        }

        while(number >= 500){
            ans+= 'D';
            number-=500;
        }

        while(number >= 100){
            ans+= 'C';
            number-=100;
        }
        while(number >= 50){
            ans+= 'L';
            number-=50;
        }

        while(number >= 10){
            ans+= 'X';
            number-=10;
        }

        while(number >= 5){
            ans+= 'V';
            number-=5;
        }

        while(number > 0){
            ans+= 'I';
            number--;
        }
        return ans;
    }
    string intToRoman(int num) {
        string ans = "";
        int curr = 1;
        while(num){
            int last = num%10;
            ans = getRoman(curr*last) + ans;
            curr*=10;
            num/= 10;
        }
        return ans;
    }
};