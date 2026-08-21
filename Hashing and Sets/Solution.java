class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        if(magazine.length()<ransomNote.length())
            return false;
        int[] a= new int[26];
        int[] b = new int[26];
        for (char ch: ransomNote.toCharArray())
            a[ch-97]++;
        for (char ch: magazine.toCharArray())
            b[ch-97]++;
        for (int i=0;i<26;i++)
            if(b[i]<a[i])
                return false;
        return true;
    }
}