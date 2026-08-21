class Solution {
    public int longestPalindrome(String s) {
        HashMap <Character,Integer> map = new HashMap<>();
        for(int i = 0 ; i < s.length(); i++) {
            char ch = s.charAt(i);
            map.put(ch,map.getOrDefault(ch,0)+1);
        }
        int so = 0 , se = 0, flag = 0;
        for ( int val: map.values()) {
            if (val%2!=0){
                so=so+val-1;
               flag = 1;
               }
            if (val%2==0) 
                se=se+val;
        }
        if(flag==0)
        return se;
        return so+se+1;
    }
}